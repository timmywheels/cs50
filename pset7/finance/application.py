import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Create stocks table if none exists
db.execute("CREATE TABLE IF NOT EXISTS stocks (stock_id integer PRIMARY KEY AUTOINCREMENT NOT NULL, id integer NOT NULL, username text NOT NULL, name text NOT NULL, symbol text NOT NULL, price numeric NOT NULL, shares numeric NOT NULL, transaction_total numeric NOT NULL, buy_sell text NOT NULL, date datetime default current_timestamp NOT NULL )")

def get_user(user_id):
        username = db.execute("SELECT username FROM users WHERE id = :user_id", user_id=user_id)
        return username[0]['username'].capitalize()

app.jinja_env.globals.update(get_user=get_user)

# Store quotes
quotes = []


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_db = "user_" + str(session["user_id"])

    portfolio = db.execute("SELECT * FROM :user_db WHERE id = :id", id=session["user_id"], user_db=user_db)

    def portfolio_total():

        total = 0

        for item in portfolio:

            total += float(item['transaction_total'])

        return total

    account_total = usd(portfolio_total())



    def check_balance():
        balance = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
        return balance[0]['cash']


    cash_remaining = usd(check_balance())

    def update_stocks():

        total_price = 0

        for item in portfolio:

            stock = lookup(item['symbol'])

            stock_price = stock['price']

            total_price = float(stock['price']) * int(item['shares'])

            item['transaction_total'] = usd(total_price)

            item['price'] = usd(stock_price)

    update_stocks()

    if not portfolio:

        return render_template("index.html")

    return render_template("index.html", portfolio=portfolio, account_total=account_total, cash_remaining=cash_remaining)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    user_db = "user_" + str(session["user_id"])

    if request.method == 'POST':

        symbol = request.form.get("symbol").upper()

        if symbol == '':
            return apology("Enter a symbol")

        if lookup(symbol) is None:
            return apology("Symbol does not exist")

        try:
            shares = int(request.form.get("shares"))

        except ValueError:
            return apology("Please enter a floating point number")

        if shares <= 0:
            return apology("Please enter a number greater than 0", 400)

        # Get stock object
        stock = lookup(symbol)

        # Get price from stock
        price = float(stock['price'])

        # print("stock", stock)

        # Get stock name
        name = stock['name']

        # Calculate cost
        cost = round(price * shares, 2)

        # Get balance
        balance = db.execute("SELECT cash FROM users WHERE id = :id", id = session["user_id"])

        # Set user balance
        updated_balance = balance[0]['cash']


        # Check if user has sufficient funds
        if cost > updated_balance:
            return apology("Insufficient funds")

        else:

            # Subtract cost from users balance
            db.execute("UPDATE users SET cash = :updated_balance - :cost WHERE cash = :updated_balance AND id = :id", updated_balance=updated_balance, cost=cost, id=session["user_id"])

            # Get username from session
            username = db.execute("SELECT username FROM users WHERE id = :id", id=session["user_id"])

            update_existing_stock = db.execute("UPDATE :user_db SET shares = shares + :shares WHERE symbol = :symbol", user_db=user_db, shares=shares, symbol=symbol)

            # print(">>>>>>>", update_existing_stock)

            if not update_existing_stock:
                # Add data to :user_db table
                db.execute("INSERT INTO :user_db (id, username, name, symbol, price, shares, transaction_total) VALUES (:id, :username, :name, :symbol, :price, :shares, :transaction_total)",
                    id=session["user_id"], username=username[0]['username'], name=name, symbol=symbol, price=price, shares=shares, transaction_total=cost, user_db=user_db)

            # Add data to transactions table
            buy_sell="BUY"

            db.execute("INSERT INTO transactions (id, username, name, symbol, price, shares, transaction_total, buy_sell) VALUES (:id, :username, :name, :symbol, :price, :shares, :transaction_total, :buy_sell)",
                id=session["user_id"], username=username[0]['username'], name=name, symbol=symbol, price=price, shares=shares, transaction_total=cost, buy_sell=buy_sell)

            return redirect("/")
            # Log users balance after purchase
            # print('BALANCE: $', round(updated_balance, 2))

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of stocks"""

    transactions = db.execute("SELECT * FROM transactions WHERE id = :id", id=session["user_id"])

    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()


    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]


        user_db = "user_" + str(session["user_id"])

        db.execute("CREATE TABLE IF NOT EXISTS :user_db (stock_id integer PRIMARY KEY AUTOINCREMENT NOT NULL, id integer NOT NULL, username text NOT NULL, name text NOT NULL, symbol text NOT NULL, price numeric NOT NULL, shares numeric NOT NULL, transaction_total numeric NOT NULL, date datetime default current_timestamp NOT NULL)", user_db=user_db)

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == 'GET':
        return render_template("quote.html")

    if request.method == 'POST':
        quote = lookup(request.form.get("symbol"))


        if not quote:
            return apology("Invalid ticker", 400)


        quotes.append(quote)

        return render_template("quoted.html", quotes=quotes, usd=usd)



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

# UPDATE Customers
# SET ContactName = 'Alfred Schmidt', City= 'Frankfurt'
# WHERE CustomerID = 1;

    if request.method == 'POST':

        username = request.form.get("username")
        pwhash = generate_password_hash(request.form.get("password"))
        confirmation = request.form.get("confirmation")

        passwords_match = check_password_hash(pwhash, confirmation)

        if username == "":
            return apology("Missing username!", 400)

        if pwhash == "" or confirmation == "":
            return apology("Missing password!", 400)

        if not passwords_match:
            return apology("Passwords don't match!", 400)



        result = db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)", username=request.form.get("username"), hash=pwhash)

        # print('result:', result)

        if not result :
            return apology("NO", 400)

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    user_db = "user_" + str(session["user_id"])

    # Create unique set of stocks symbols
    symbols = set()

    # Get username from session
    # username = db.execute("SELECT username FROM users WHERE id = :id", id=session["user_id"])
    # portfolio = db.execute("SELECT symbol FROM stocks WHERE id = :id", id=session["user_id"])
    portfolio = db.execute("SELECT symbol FROM :user_db WHERE id = :id", id=session["user_id"], user_db=user_db)

    for symbol in portfolio:
        symbols.add(symbol["symbol"])


    # if request.method == 'GET':


        # Loop through symbols in portfolio
        # Add them to the 'symbols' set


    if request.method == 'POST':
        shares_input = request.form.get("shares")

        # print("Shares:", shares_input)

        symbol_input = request.form.get("symbol")

        # print("Symbol:", symbol_input)

        share_count = db.execute("SELECT shares FROM :user_db WHERE id = :id AND symbol = :symbol", user_db=user_db, id=session["user_id"], symbol=symbol_input)

        shares_owned = share_count[0]['shares']

        stock = lookup(symbol_input)

        sell_price = int(shares_input) * stock['price']

        # print("Total Shares:", shares_owned)

        if int(shares_input) > shares_owned:
            return apology("You don't have that many shares")

        else:

            buy_sell = "SELL"

            updated_shares = shares_owned - int(shares_input)

            update_portfolio_value = db.execute("UPDATE users SET cash = cash + :sell_price WHERE id = :id", sell_price=sell_price, id=session["user_id"])

            update_total_shares = db.execute("UPDATE :user_db SET shares = :updated_shares WHERE id = :id AND symbol = :symbol_input", updated_shares=updated_shares, id=session["user_id"], symbol_input=symbol_input, user_db=user_db)


            # Get stock object
            stock = lookup(symbol_input)

            # Get stock name
            name = stock['name']

            # Get stock price
            price = stock['price']

            # Get username from session
            username = db.execute("SELECT username FROM users WHERE id = :id", id=session["user_id"])

            # Add data to transactions table
            db.execute("INSERT INTO transactions (id, username, name, symbol, price, shares, transaction_total, buy_sell) VALUES (:id, :username, :name, :symbol, :price, :shares, :transaction_total, :buy_sell)", id=session["user_id"], username=username[0]['username'], name=name, symbol=symbol_input, price=price, shares=shares_input, transaction_total=sell_price, buy_sell=buy_sell)

            return redirect("/")

    return render_template("sell.html", symbols=symbols)


def errorhandler(e):
    """Handle error"""
    # print(e)
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)

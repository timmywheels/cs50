import cs50


def get_positive_int(prompt):
    while True:
        n = cs50.get_int(prompt)
        if n >= 1:
            break
    return n

i = get_positive_int('positive integer, please: ')
print(i)
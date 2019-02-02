import sys

# if len(sys.argv) == 2:
#     print(f'hello, {sys.argv[1]}')
# else:
#     print('Hello, World!')

for string in sys.argv:
    for char in string:
        print(char)
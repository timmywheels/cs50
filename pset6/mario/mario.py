from cs50 import get_int

height = get_int('Height: ')


while height < 0 or height > 23:
    print('Enter an integer between 0 and 23')
    height = get_int('Height: ')

for i in range(height):
    # print(f'i:{i}')
    # print(f'height: {height}')

    # Print spaces
    for j in range(1, (height - i)):
        print(' ', end='')
        # print(f'j:{j}')

    # Print blocks
    for k in range(i+1):
        print('#', end='')
        # print(f'k:{k}')

    print('  ', end='')

    # # Print blocks
    for k in range(i+1):
        print('#', end='')

    print()



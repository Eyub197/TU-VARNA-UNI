from random import randint

list = [randint(1, 100) for _ in range(10)]


def print_all_odd_index_elements(list):
    print(list)
    for i in range(1, len(list), 2):
        print(list[i])


print_all_odd_index_elements(list)

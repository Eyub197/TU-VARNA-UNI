# def print_number_sequance():
#     n = int(input("Enter number: "))
#     for i in range(1, n + 1):
#         print(str(i) * i)


# print_number_sequance()


def print_number_sequance_loops():
    n = int(input("Enter number: "))
    for i in range(1, n + 1):
        for number in range(i):
            print(i, end="")
        print()


print_number_sequance_loops()

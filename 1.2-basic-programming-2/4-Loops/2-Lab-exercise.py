numbers_first = []
numbers_first_count = int(
    input("Enter how many numbers do you want in the first list: ")
)

numbers_second = []
numbers_second_count = int(
    input("Enter how many numbers do you want in the second list: ")
)


def populate_array(array, count):
    for _ in range(0, count):
        array.append(int(input("Enter a number :-) :")))


def find_sum(numbers):
    return sum(numbers)


populate_array(numbers_first, numbers_first_count)
populate_array(numbers_second, numbers_second_count)


first_sum = find_sum(numbers_first)
second_sum = find_sum(numbers_second)

if not (first_sum == second_sum):
    print(f"Yes {first_sum}")
else:
    print(f"No {first_sum - second_sum}")

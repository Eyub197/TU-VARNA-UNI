my_set = {1, 23, 34, 45, 21, 123, 34, 43}
first_biggest_number = max(my_set)


def find_second_biggest_number(first_biggest_number, my_set):
    my_set.remove(first_biggest_number)
    return max(my_set)


second_biggest_number = find_second_biggest_number(first_biggest_number, my_set)

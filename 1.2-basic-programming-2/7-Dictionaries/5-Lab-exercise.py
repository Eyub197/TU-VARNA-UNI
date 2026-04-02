dict_numbers = {"one": 1, "two": 2, "three": 3}


def find_biggest_value_in_dict(dict):
    return max(dict.values())


def find_smallest_value_in_dict(dict):
    return min(dict.values())


print(find_biggest_value_in_dict(dict_numbers))
print(find_smallest_value_in_dict(dict_numbers))

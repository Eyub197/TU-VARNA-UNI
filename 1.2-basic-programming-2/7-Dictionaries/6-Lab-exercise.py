dict_example = {
    "one": 1,
    "two": 2,
    "three": 3,
}


def print_dict_in_rows(dict):
    for key, value in dict.items():
        print(f"{key}: {value}")


print_dict_in_rows(dict_example)

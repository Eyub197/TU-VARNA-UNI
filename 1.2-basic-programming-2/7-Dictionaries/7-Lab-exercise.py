list_of_dicts = [
    {
        "one": 1,
        "two": 2,
        "three": 3,
    },
    {
        "four": 4,
        "five": 5,
        "six": 6,
    },
    {
        "seven": 7,
        "eight": 8,
        "nine": 9,
    },
]


def convert_list_of_dicts_to_list_of_values(list_of_dicts):
    result = []
    for dict in list_of_dicts:
        for key, value in dict.items():
            result.append(value)
    return result


print(convert_list_of_dicts_to_list_of_values(list_of_dicts))

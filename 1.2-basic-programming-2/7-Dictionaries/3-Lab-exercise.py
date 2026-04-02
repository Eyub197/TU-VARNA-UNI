dict = {1: "foo", 3: "baz"}
dict_names = {1: "foo", 5: "faz"}


def is_uniqe_value(value):
    return value not in dict.values()


def is_uniqe_value_names(value):
    return value not in dict_names.values()


def merge_uniq_values(dict_one, dict_two):
    merged = {}
    for key, value in dict_two.items():
        if is_uniqe_value(value):
            merged[key] = value
    for key, value in dict_one.items():
        if is_uniqe_value_names(value):
            merged[key] = value
    return merged


print(merge_uniq_values(dict, dict_names))

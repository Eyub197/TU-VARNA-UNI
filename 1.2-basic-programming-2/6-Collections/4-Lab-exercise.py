list_with_fractions = [12.32, 44.43, 13.43, 23.12]


def power_up(list):
    for i in range(len(list)):
        list[i] = list[i] ** 2
    return list


list = power_up(list_with_fractions)
print(list)

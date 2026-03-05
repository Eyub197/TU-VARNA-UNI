def calc_points():
    point_count = 82
    bonus_points = 0
    if point_count <= 80:
        bonus_points = 3
    elif point_count > 80:
        bonus_points = point_count * 0.05
    elif point_count > 90:
        bonus_points = point_count * 0.10

    if point_count % 2 == 0:
        bonus_points += 1
    elif point_count % 3 == 0:
        bonus_points += 2

    return point_count, bonus_points


point_count, bonus_points = calc_points()

print(f"Bonus points {bonus_points:g}")
print(f"All points {bonus_points + point_count}")

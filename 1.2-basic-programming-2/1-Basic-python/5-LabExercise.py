count = int(input("Enter the squere dimentions: "))

for i in range(1, count + 1):
    if i == count or i == 1:
        print("*" * count)
else:
    print("*", " " * (count - 4), "*")

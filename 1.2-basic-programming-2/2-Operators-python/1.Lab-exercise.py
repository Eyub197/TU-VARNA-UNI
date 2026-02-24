firstNumber = int(input("Enter first number: "))
secondNumber = int(input("Enter second number: "))
operator = input("Enter a operator: ")


def getBsicManthResult(firstNumber, secondNumber, operator):
    if operator == "+":
        return firstNumber + secondNumber
    elif operator == "-":
        return firstNumber - secondNumber
    elif operator == "*":
        return firstNumber * secondNumber
    elif operator == "/":
        return firstNumber / secondNumber


result = getBsicManthResult(firstNumber, secondNumber, operator)
print(result)

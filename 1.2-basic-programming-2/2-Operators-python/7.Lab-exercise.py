def calculator():
    firstNumber = int(input("Enter first number: "))
    print("\nChoose an operation:")
    print("1: Addition (+)")
    print("2: Subtraction (-)")
    print("3: Multiplication (*)")
    print("4: Division (/)")
    print("5: Exponentiation (firstNumber ** secondNumber)")
    print("6: N-th Root (firstNumber ** (1 / secondNumber))")
    print("7: Bitwise Operations")
    operation = int(input("Enter a value from 1 to 7: "))
    secondNumber = int(input("Enter second Number: "))
    match operation:
        case 1:
            print(f"Result: {firstNumber + secondNumber}")
        case 2:
            print(f"Result: {firstNumber - secondNumber}")
        case 3:
            print(f"Result: {firstNumber * secondNumber}")
        case 4:
            print(f"Result: {firstNumber / secondNumber}")
        case 5:
            print(f"Result: {firstNumber**secondNumber}")
        case 6:
            print(f"Result: {firstNumber ** (1 / secondNumber)}")
        case 7:
            print("\nChoose a bitwise operation:")
            print("1: AND (&)")
            print("2: OR (|)")
            print("3: XOR (^)")
            print("4: NOT (~) (applies to the sum of the numbers)")
            print("5: Left Shift (<<)")
            print("6: Right Shift (>>)")
            bitwiseOperationChoice = int(
                input("Enter bitwise operation choice (1-6): ")
            )
            match bitwiseOperationChoice:
                case 1:
                    print(f"Result: {firstNumber & secondNumber}")

                case 2:
                    print(f"Result: {firstNumber | secondNumber}")

                case 3:
                    print(f"Result: {firstNumber ^ secondNumber}")

                case 4:
                    print(f"Result: {~(firstNumber + secondNumber)}")

                case 5:
                    print(f"Result: {firstNumber << secondNumber}")

                case 6:
                    print(f"Result: {firstNumber >> secondNumber}")
                case _:
                    print("Invalid bitwise operation choice.")
        case _:
            print("Invalid main operation choice.")


# Call the calculator function to run the program
calculator()

## to do

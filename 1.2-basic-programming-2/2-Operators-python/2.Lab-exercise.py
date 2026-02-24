sameStringOne = "Hello1."
sameStringTwo = "Hello"


def checkIfTwoStringsIdentical(firstString, secondString):
    return firstString is secondString


print(checkIfTwoStringsIdentical(sameStringOne, sameStringTwo))

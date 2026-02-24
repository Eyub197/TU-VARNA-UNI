def handleBGNTransfer(wantedCurrency, amount):
    if wantedCurrency == "USD":
        return amount * 1.79549
    elif wantedCurrency == "EUR":
        return amount * 1.95583
    elif wantedCurrency == "GBP":
        return amount * 2.53405


def handleUSDTransfer(wantedCurrency, amount):
    if wantedCurrency == "BGN":
        return amount * 1.66
    elif wantedCurrency == "EUR":
        return amount * 0.85
    elif wantedCurrency == "GBP":
        return amount * 0.74


def handleEURTransfer(wantedCurrency, amount):
    if wantedCurrency == "BGN":
        return amount * 1.95583
    elif wantedCurrency == "USD":
        return amount * 1.18
    elif wantedCurrency == "GBP":
        return amount * 0.87


def handleGBPTransfer(wantedCurrency, amount):
    if wantedCurrency == "BGN":
        return amount * 2.2200
    elif wantedCurrency == "EUR":
        return amount * 1.15
    elif wantedCurrency == "USD":
        return amount * 1.35


def handleCurrencyExchange():
    amount = int(input("Enter how much money you have: "))
    startingCurrency = input("Enter your starting currancy (BGN, USD, EUR, GBP)")
    wantedCurrency = input("Enter the currency you wnat it to change")
    newAmount = ""
    match startingCurrency:
        case "BGN":
            newAmount = handleBGNTransfer(wantedCurrency, amount)
            print(
                f"Your {amount}${startingCurrency} is equl to {wantedCurrency}{newAmount} "
            )

        case "USD":
            newAmount = handleUSDTransfer(wantedCurrency, amount)
            print(
                f"Your {amount}${startingCurrency} is equl to {wantedCurrency}{newAmount} "
            )

        case "EUR":
            newAmount = handleEURTransfer(wantedCurrency, amount)
            print(
                f"Your {amount}${startingCurrency} is equl to {wantedCurrency}{newAmount} "
            )

        case "GBP":
            newAmount = handleGBPTransfer(wantedCurrency, amount)
            print(
                f"Your {amount}${startingCurrency} is equl to {wantedCurrency}{newAmount} "
            )


handleCurrencyExchange()

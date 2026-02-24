FRUIT_FOR_KG_PRICE = 2.33
VEGETABLE_FOR_KG_PRICE = 1.55


def calcProducPrice(productType, kg):
    if productType == "fruit":
        return (kg * FRUIT_FOR_KG_PRICE) * 1.96
    elif productType == "vegetable":
        return (kg * VEGETABLE_FOR_KG_PRICE) * 1.96


profit = calcProducPrice("fruit", 3)

print(f"The profit is ${profit}Euro")

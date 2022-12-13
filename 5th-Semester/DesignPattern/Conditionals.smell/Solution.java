
public bool ProvideCoffee (CoffeeType coffeeType)
{
    if(!enoughChangeConsideringCupPrice() || !sufficientCupandWaterandCoffeePowder() ) {
	return false;
    }
    if(!canMakeCreamCoffee(coffeeType) ) {
	return false;
    }
    if(!canMakeSugarCoffee(coffeeType)){
	return false;
    }

    takeCoffeeAndWaterInCup();
   
    if(isCreamCoffee(coffeeType)){
	takeCreamPowder();
    }
    if (isSugarCoffee(coffeeType)){
	takeSugar();
    }

    ReturnChange();
    return true;
}


public int getChange(){
    return _change
}

public int getCupPrice(){
    return _CUP_PRICE
}

private bool enoughChangeConsideringCupPrice(){
    return getChange() > getCupPrice();
}

public bool sufficientCupandWaterandCoffeePowder(){
    return AreCupsSufficient || IsHotWaterSufficient || IsCoffeePowderSufficient;
}
public bool canMakeCreamCoffee(CoffeeType coffeeType){
    return isCreamCoffee(coffeeType) && IsCreamPowderSufficient;
}
public bool canMakeSugarCoffee(CoffeeType coffeeType){
    return isSugarCoffee(coffeeType) && !IsSugarSufficient;
}

public bool isCreamCoffee(CoffeeType coffeeType){
    return coffeeType == CoffeeType.Cream || coffeeType ==CoffeeType.CreamAndSugar;
}

public bool isSugarCoffee(CoffeeType coffeeType){
    return coffeeType == CoffeeType.Sugar || coffeeType == CoffeeType.CreamAndSugar;
}

private void takeHotWater(){
    _hotwater -= _CUP_HOT_WATER;
}

private void takeCoffeePowder(){
    _coffeePowder -= _CUP_COFFEE_POWDER;
}

private void takeCreamPowder(){
	_creamPowder -= _CUP_CREAM_POWDER;
}

private void takeSugar(){
	_sugar -= _CUP_SUGAR;
}

private void takeCoffeeAndWaterInCup(){
    _cups--;
    takeHotWater();
    takeCoffeePowder();
}

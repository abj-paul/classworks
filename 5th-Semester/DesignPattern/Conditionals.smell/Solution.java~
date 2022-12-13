//﻿ Example of Conditional Complexity

public bool ProvideCoffee (CoffeeType coffeeType)
{
    if( _change <_CUP_PRICE || AreCupsSufficient || !IsHotWaterSufficient || IsCoffeePowderSufficient) {
	return false;
    }
    if( (coffeeType == CoffeeType.Cream || coffeeType == CoffeeType.CreamAndSugar) && !IsCreamPowderSufficient) {
	return false;
    }
    if((coffeeType == CoffeeType.Sugar || coffeeType == CoffeeType.CreamAndSugar) && !IsSugarSufficient){
	return false;
    }
    
    cups--;
    _hotwater -= _CUP_HOT_WATER;
    _coffeePowder -= _CUP_COFFEE_POWDER;

    if(coffeeType == CoffeeType.Cream || coffeeType ==CoffeeType.CreamAndSugar) {
	_creamPowder -= _CUP_CREAM_POWDER;
    }
    if (coffeeType == CoffeeType.Sugar || coffeeType == CoffeeType.CreamAndSugar){
	_sugar -= _CUP_SUGAR;
    }
    ReturnChange();
    return true;
}

# Recipe Book
https://zelda.fandom.com/wiki/Food
https://minecraft.wiki
https://eldenring.wiki.fextralife.com/Elden+Ring+Wiki

CookBooks CSV:
UUID;Ingedient Name;Type
123-321-123;Chicken;Protein
321-123-321;Peanuts;Protein
132-321-132;Rice;Grain
101-101-101;Soy Sauce;Culinary
010-010-010;Butter;Culinary
101-010-101;Salt;Culinary

###  Recipes
#### UUID;Recipe Name;PrepTime(?1);CookTime(?1);CookType;CookTemp;IngredientUUID#Volume|...;Nested Recipe List;Instruction List
* 231-231-231;Soy Chicken;10 min;10 min;Saute;Low;123-321-123,2,Breast|101-101-101,1,Cup;;Preheat Fry pan|Place some butter salt and chicken in pan|Cook until chicken is more white than pink|Pour in soy sauce|stir until done
* 132-213-132;Steamed Rice;5 min;20 min;Appliance;Steamed;132-321-132,2,Cups;Wash Rice until water no longer cloudy|fill with water until about an inch above rice|Put in cooker
* 011-010-101;Jesse's Chicken;15 min;15 min;Saute;Medium-High;321-123-321,1,Handfull;231-231-231,1,Count|132-213-132,1,Count;Start Rice cooking first|Cook peanuts in with chicken|Poor chicken over bed of rice

Ingredients
 : id
 : Name
 : Type


Recipes
 : PrepTime
 : CookTime
 : CookType
 : Ingredient List
  + UUID
  + Count
  + Volume
 : Instruction List


## Note ##
? May want to set times to be time-deltas
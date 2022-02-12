# Desctiption

Implement a directory of country capitals.

The program receives the following requests for input:

 - **CHANGE_CAPITAL country new_capital** - changing the capital of the country country to new_capital, or adding such a country with such a capital, if it did not exist before.

 - **RENAME old_country_name new_country_name** - renaming the country from old_country_name to new_country_name.

 - **ABOUT country** - output of the capital of the country country.

 - **DUMP** - output of capitals of all countries.

## Input format

The first line contains the number of requests Q, the following Q lines contain descriptions of requests. All names of countries and capitals consist only of Latin letters, numbers and underscores.

## Output format

Output the result of processing each request:

In response to the *CHANGE_CAPITAL* country new_capital query, output 

 - *Introduce new country country with capital new_capital*, if the country country did not exist before;

 - *Country country hasn't changed its capital*, if country country had a capital new_capital up to the current moment;

 - *Country country has changed its capital from old_capital to new_capital*, if the country country up to the current moment had an old_capital capital whose name does not match the name of new_capital.

In response to the RENAME old_country_name new_country_name request, output

 - *Incorrect rename, skip*, if the new country name matches the old one, the country old_country_name does not exist or the country new_country_name already exists;

 - *Country old_country_name with capital capital has been renamed to new_country_name*, if the query is correct and the country has capital capital.

In response to the ABOUT country query, output

 - *Country country doesn't exist*, if a country named country doesn't exist;

 - *Country country has capital capital*, if the country country exists and has a capital capital.

In response to the DUMP request, output

 - *There are no countries in the world*, if no countries have been added yet;

 - a sequence of pairs of the form *country/capital*, describing the capitals of all countries, if there is already at least one country in the world. When displaying a sequence, the pairs of the specified type must be ordered by the name of the country and separated by a space.

# Example 1

## Input
```
6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP
```

## Output

```
Introduce new country RussianEmpire with capital Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic has capital Petrograd
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
USSR/Moscow
```

# Example 2

## Input
```
24
RENAME FakeCountry FarFarAway
ABOUT FarFarAway
DUMP
CHANGE_CAPITAL TsardomOfRussia Moscow
CHANGE_CAPITAL TsardomOfRussia Moscow
CHANGE_CAPITAL ColonialBrazil Salvador
CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
RENAME TsardomOfRussia RussianEmpire
CHANGE_CAPITAL RussianEmpire Moscow
CHANGE_CAPITAL RussianEmpire SaintPetersburg
CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
DUMP
RENAME ColonialBrazil EmpireOfBrazil
ABOUT RussianEmpire
RENAME EmpireOfBrazil UnitedStatesOfBrazil
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
ABOUT RussianEmpire
DUMP
RENAME USSR USSR
```

## Output

```
Incorrect rename, skip
Country FarFarAway doesn't exist
There are no countries in the world
Introduce new country TsardomOfRussia with capital Moscow
Country TsardomOfRussia hasn't changed its capital
Introduce new country ColonialBrazil with capital Salvador
Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg
Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
Country RussianEmpire has capital SaintPetersburg
Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
Country RussianEmpire doesn't exist
FederativeRepublicOfBrazil/Brasilia USSR/Moscow
Incorrect rename, skip
```
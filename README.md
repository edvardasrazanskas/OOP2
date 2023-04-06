# OOP
Šiame projekte bus padaryta programa, kuri galės:

1. 
a) nuskaityti vardą ir pavardę.
b) nuskaityti n atliktų namų darbų rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.

2. Apskaičiuoti galutinį balą (galutinis):
GALUTINIS = 0.4 * vidurkis + 0.6 * egzaminas.

- Kriterijai:
a) Turi būti 6 versijos: v0.1, v0.2, v0.3, v0.4, v0.5 ir v1.0. Kiekviena versija turės savo atskirus reikalavius, kurie bus surašyti žemiau.
b) Turi b8ti susitvarkomma su klaidingais vartotojo įvedimais (pvz.: įvedamas ne skaičius)



# V0.1
Pagal aprašytus užduoties reikalavimus realizuokite programą, kuri nuskaito vartotojų įvedamus reikiamus duomenis (struktūros elementai):
    studento vardą ir pavardę;
    namų darbų ir egzamino rezultatą;

Baigus duomenų įvedimą, suskaičiuoja galutinį balą ir juos pateikia į ekraną tokiu ar panašiu pavidalu (kur galutinis apskaičiuotas balas pateikiamas dviejų skaičių po kablelio tikslumu):
Pavardė     Vardas      Galutinis(vid./med.)

Čia galutinis rezultatas gali būti skaičiuojamas naudojant namų darbų vidutinį balą arba medianą.

Sukurti 2 atskirus failus(darbartiniu atveju - main-vectors.cpp ir main-arrays.cpp) kurie studento namų darbų rezultatų įvedimui naudotų masyvus ir vektorius.

# V0.2
Papildykite programos versiją (v0.1) taip, kad būtų galima duomenis ne tik įvesti bet ir nuskaityti iš failo.

Reikalavimai output’ui: studentai turi būti surūšiuoti pagal vardus (ar pavardes) ir visi stulpeliai būtų gražiai "išlygiuoti".

# V0.3 
Papildyta V0.2 versija - functions.h faile perkelta struktūra, algoritmai ir funkcijos.

# V0.4
Studentų rūšiavimo programa: studentu_skirstymas.cpp
Failų generatorius: file-generator.cpp

# V0.5

### Lentelė
        1 000	    10 000 	    100 000     1 000 000 	10 000 000 
vector	0.0063	    0.2813	    0.4832	    4.7886	    27.1517
list	0.0066	    0.0439	    0.4225	    4.0452	    24.3295
deque	0.0065	    0.0546	    0.5045	    5.4876	    32.4625

# V1.0
Optimizuotos programos
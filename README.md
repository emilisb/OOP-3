#  3 užduotis

![version][version-badge]

## [Užduoties sąlyga](https://github.com/objprog/paskaitos2019/wiki/3-oji-užduotis)

## Parsisiuntimas (Unix platformoje)

- `git clone https://github.com/emilisb/OOP-3.git`
- `cd OOP-3`

## Kompiliavimas

- `make`

**arba build + paleidimas**

- `make run`

## Paleidimas

- `make run`

**arba**

- `cd bin`
- `./uzduotis`

## Unit testų paleidimas (reikalingas Google Test)

- `make test`

## Dokumentacijos sugeneravimas (reikalingas Doxygen)

- `make docs`

## Konteinerio pakeitimas

- Atsidarykite StudentCollection.hpp failą
- Užkomentuokite esamą konteinerį ir atkomentuokite norimą

## Versijų istorija (changelog)

### [v2.0](https://github.com/emilisb/OOP-3/releases/tag/v2.0)

**Pridėta**

- Pridėta Doxygen dokumentacija
- Pridėti Google Test unit testai

### [v1.5](https://github.com/emilisb/OOP-3/releases/tag/v1.5)

**Pridėta**

- Pridėta abstrakti `Person` klasė
- Pridėtas custom vektorius iš 4-tos užduoties

**Benchmark su mano vektoriumi**
![](https://i.imgur.com/NnBiJeJ.png)

### [v1.2](https://github.com/emilisb/OOP-3/releases/tag/v1.2)

**Pridėta**

- Pridėta daugiau `Student` klasės operatorių

### [v1.1](https://github.com/emilisb/OOP-3/releases/tag/v1.1)

**Pridėta**

- Klasės interfeisas naudoja getter'ius
- Sukurta nauja repozicija

**Pakeista**

- Perdarytas `Student` klasės konstruktorius

**Programos sparta prieš pakeitimus**
![](https://i.imgur.com/pAMmctP.png)

**Programos sparta po pakeitimų**
![](https://i.imgur.com/PdaAVut.png)

**Optimizavimo flagų analizė**

***O1***
![](https://i.imgur.com/NQlAFUu.png)

***O2***
![](https://i.imgur.com/K8caUmT.png)

***O3***
![](https://i.imgur.com/PdaAVut.png)

### [v1.0](https://github.com/emilisb/OOP-2/releases/tag/v1.0) - (2019-03-25 😔😔😔)

**Pridėta**

- Pridėtos naujos "kietekų" ir "vargšiukų" dalybos strategijos

**Pakeista**

- Skirtingi konteineriai naudoja tą patį failą

**Programos spartos analizė**

![](https://i.imgur.com/ly3j3bP.png)

### [v0.5](https://github.com/emilisb/OOP-2/releases/tag/v0.5) - (2019-03-12)

**Pridėta**

- Pridėti `std::list` ir `std::deque` konteineriai

**Pakeista**

- Pereita prie C++17 standarto

**Programos spartos analizė**

![](https://i.imgur.com/ly3j3bP.png)


### [v0.4](https://github.com/emilisb/OOP-2/releases/tag/v0.4) - (2019-03-04)

**Pridėta**

- Pridėtas duomenų failų generavimas
- Pridėta galimybė analizuoti programos veikimo laiką

**Programos spartos analizė**

![](https://i.imgur.com/RoGyppG.png)

### [v0.3.1](https://github.com/emilisb/OOP-2/releases/tag/v0.3.1) - (2019-02-24)

**Pridėta**

- Pridėta trūkstama linija po lentelės viršutinės sekcijos

**Pakeista**

- Iškelta galutinio įvertinimo teksto generavimo funkcija

### [v0.3](https://github.com/emilisb/OOP-2/releases/tag/v0.3) - (2019-02-24)

**Pridėta**

- Dirbant su vektoriais naudojamas exception handling

**Pakeista**

- Ženkliai pertvarkytas kodas
- Iškeltos pasikartojančios funkcijos/komponentai
- Atnaujintas makefile

### [v0.2](https://github.com/emilisb/OOP-2/releases/tag/v0.2) - (2019-02-17)

**Pridėta**

- Pridėta galimybė skaityti duomenis iš failo
- Duomenys rikiuojami pagal vardą

### [v0.1](https://github.com/emilisb/OOP-2/releases/tag/v0.1) - (2019-02-17)

**Pridėta**

- Pirmoji programos versija

[version-badge]: https://img.shields.io/badge/version-2.0-green.svg

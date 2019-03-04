//
//  main.cpp
//  Objektinis2
//
//  Created by Emilis Baliukonis on 13/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include "StudentCollection.hpp"
#include "Console/Console.hpp"

int main(int argc, const char * argv[]) {
    StudentCollection collection;
    
    const bool useFile = Console::getBoolWithQuestion("Ar norite skaityti pažymius iš failo?");
    
    if (useFile) {
        collection.loadFromFile("data/kursiokai.txt");
    } else {
        const bool useRandom = Console::getBoolWithQuestion("Ar norite naudoti atsitiktinius duomenis?");
        collection.loadFromConsole(useRandom);
    }
    
    collection.finalResultMode = Console::getCharWithQuestion("Ar norite naudoti vidurkį ar medianą?", "vidurkį", "medianą", 'v', 'm');
    
    collection.calculateFinal();
    
    collection.sortByName();
    collection.printResults();
    
    return 0;
}

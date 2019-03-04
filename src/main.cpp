//
//  main.cpp
//  Objektinis2
//
//  Created by Emilis Baliukonis on 13/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <string>

#include "StudentCollection.hpp"
#include "Console/Console.hpp"
#include "Console/Table.hpp"
#include "Console/Row.hpp"
#include "Timer.hpp"

using std::string;

int main(int argc, const char * argv[]) {
    const bool useProfiler = Console::getBoolWithQuestion("Ar norite atlikti spartos testą?");
    
    if (useProfiler) {
        Table table(8);
        table.setSeparatorRow(1);
        table.addRow( { "N", "Generav.", "Skait.", "Skaiciav.", "Rikiav.", "Rūsiav.", "Rasymas", "Viso" } );
        
        for (int numOfStudents = 10; numOfStudents <= 100000; numOfStudents*= 10) {
            Timer totalTimer;
            totalTimer.start();
            Timer timer;
            StudentCollection collection;
            collection.finalResultMode = 'v';
            
            string units = "ms";
            
            timer.start();
            string filename = "data/" + std::to_string(numOfStudents) + ".txt";
            collection.generateRandomFile(filename, numOfStudents);
            string time1 = std::to_string(timer.duration()) + units;
            
            timer.start();
            collection.loadFromFile(filename);
            string time2 = std::to_string(timer.duration()) + units;
            
            timer.start();
            collection.calculateFinal();
            string time3 = std::to_string(timer.duration()) + units;
            
            timer.start();
            collection.sortByName();
            string time4 = std::to_string(timer.duration()) + units;
            
            timer.start();
            collection.setTypeByFinalResult();
            string time5 = std::to_string(timer.duration()) + units;
            
            timer.start();
            collection.writeStudentsByTypeToFile("data/bad_students.txt", "data/good_students.txt");
            string time6 = std::to_string(timer.duration()) + units;
            
            string time7 = std::to_string(totalTimer.duration()) + units;
            
            table.addRow( { std::to_string(numOfStudents), time1, time2, time3, time4, time5, time6, time7 } );
        }
        
        table.print();
    } else {
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
    }
    
    return 0;
}

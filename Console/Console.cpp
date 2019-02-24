//
//  Console.cpp
//  Uzduotis 2
//
//  Created by Emilis Baliukonis on 21/02/2019.
//  Copyright © 2019 Emilis Baliukonis. All rights reserved.
//

#include <iostream>
#include "Console.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool Console::getBoolWithQuestion(string question, char trueValue, char falseValue) {
    char input = '\0';
    
    while (input != trueValue && input != falseValue) {
        cout
        << question << endl
        << trueValue << " - taip" << endl
        << falseValue << " - ne" << endl;
        cin >> input;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return input == trueValue;
}

char Console::getCharWithQuestion(string question, string option1, string option2, char value1, char value2) {
    char input = '\0';
    
    while (input != value1 && input != value2) {
        cout
        << question << endl
        << value1 << " - " << option1 << endl
        << value2 << " - " << option2 << endl;
        cin >> input;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return input;
}

int Console::getIntegerWithQuestion(string question) {
    int input = 0;
    cout << question << " ";
    cin >> input;
    cout << endl;
    
    if (cin.fail()) {
        // discard 'bad' character(s)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Bad input!" << endl;
        
        return Console::getIntegerWithQuestion(question);
    }
    
    return input;
}

string Console::getStringWithQuestion(string question) {
    string input;
    
    cout << question << " ";
    cin >> input;
    cout << endl;
    
    if (cin.fail()) {
        // discard 'bad' character(s)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Bad input!" << endl;
        
        return Console::getStringWithQuestion(question);
    }
    
    return input;
}

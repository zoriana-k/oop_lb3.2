#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class manager {
public:
    char name[128];

    // Конструктори за допомогою списку ініціалізації
    manager() : name("") {
        cout << "Manager (default constructor) created\n";
    }//конструутор без параметрів

    manager(const char* managerName) {
        strcpy_s(name, managerName);
        cout << "Manager (parameterized constructor) created\n";
    }//з параметрами

    manager(const manager& other) {
        strcpy_s(name, other.name);
        cout << "Manager (copy constructor) created\n";
    }//копіювання

    ~manager() {
        cout << "Manager destroyed\n";
    }// Деструктор
};

#pragma once
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class employeer {
public:
    // Публічні поля
    char name[256];
    char position[128];
    int experience;

    employeer() : experience(0), budget(0) {
        strcpy_s(name, "");
        strcpy_s(position, "");
        strcpy_s(employeerID, "");
        strcpy_s(team, "");
        strcpy_s(tasks, "");
        strcpy_s(resources, "");
    }//конструктор без параметрів

    // Метод для виведення всієї інформації
    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Employeer ID: " << employeerID << endl;
        cout << "Team: " << team << endl;
        cout << "Tasks: " << tasks << endl;
        cout << "Resources: " << resources << endl;
        cout << "Budget: $" << budget << endl;
    }

    // Перевантажений оператор +
    employeer operator+(const employeer& other) {
        employeer result;
        result.experience = this->experience + other.experience;
        strcpy_s(result.name, sizeof(result.name), this->name);
        strcat_s(result.name, sizeof(result.name), other.name);
        strcpy_s(result.position, sizeof(result.position), this->position);
        strcat_s(result.position, sizeof(result.position), other.position);
        strcpy_s(result.employeerID, sizeof(result.employeerID), this->employeerID);
        strcat_s(result.employeerID, sizeof(result.employeerID), other.employeerID);
        strcpy_s(result.team, sizeof(result.team), this->team);
        strcat_s(result.team, sizeof(result.team), other.team);
        strcpy_s(result.tasks, sizeof(result.tasks), this->tasks);
        strcat_s(result.tasks, sizeof(result.tasks), other.tasks);
        strcpy_s(result.resources, sizeof(result.resources), this->resources);
        strcat_s(result.resources, sizeof(result.resources), other.resources);
        result.budget = this->budget + other.budget;
        return result;
    }

    // Перевантажений оператор <<
    friend ostream& operator<<(ostream& os, const employeer& e) {
        os << "Name: " << e.name << endl;
        os << "Position: " << e.position << endl;
        os << "Experience: " << e.experience << " years" << endl;
        return os;
    }

    void setEmployeerID(const char* newID) {
        strcpy_s(employeerID, sizeof(employeerID), newID);
    }
    void setTeam(const char* newTeam) {
        strcpy_s(team, sizeof(team), newTeam);
    }
    void setTasks(const char* newTasks) {
        strcpy_s(tasks, sizeof(tasks), newTasks);
    }
    void setResources(const char* newResources) {
        strcpy_s(resources, sizeof(resources), newResources);
    }
    void setBudget(int newBudget) {
        budget = newBudget;
    }//сетери
    // Метод для запису в файл
    void writeToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << name << endl;
            file << position << endl;
            file << experience << endl;
            file << employeerID << endl;
            file << team << endl;
            file << tasks << endl;
            file << resources << endl;
            file << budget << endl;
            file.close();
        }
        else {
            cerr << "Unable to open file for writing: " << filename << endl;
        }
    }

    // Метод для читання з файлу
    void readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            file.getline(name, 256);
            file.getline(position, 128);
            file >> experience;
            file.ignore();
            file.getline(employeerID, 64);
            file.getline(team, 128);
            file.getline(tasks, 2048);
            file.getline(resources, 2048);
            file >> budget;
            file.close();
        }
        else {
            cerr << "Unable to open file for reading: " << filename << endl;
        }
    }

    // Метод для додавання досвіду
    void addExperience(int years) {
        experience += years;
    }

    // Метод для генерації і сортування досвіду
    void generateAndSortExperience(int numValues) {
        int* experienceArray = new int[numValues];
        for (int i = 0; i < numValues; i++) {
            experienceArray[i] = rand() % 50;
        }
        cout << "\nGenerated experience values: ";
        for (int i = 0; i < numValues; i++) {
            cout << experienceArray[i] << " ";
        }
        cout << endl;
        sort(experienceArray, experienceArray + numValues);
        cout << "\nSorted experience values: ";
        for (int i = 0; i < numValues; i++) {
            cout << experienceArray[i] << " ";
        }
        cout << endl;
        delete[] experienceArray;
    }


private:
    // Приватні поля
    char employeerID[64];
    char team[128];
    char tasks[2048];
    char resources[2048];
    int budget;
};

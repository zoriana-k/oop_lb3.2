#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class manager {
public:
    char name[128];

    // ������������ �� ��������� ������ �����������
    manager() : name("") {
        cout << "Manager (default constructor) created\n";
    }//����������� ��� ���������

    manager(const char* managerName) {
        strcpy_s(name, managerName);
        cout << "Manager (parameterized constructor) created\n";
    }//� �����������

    manager(const manager& other) {
        strcpy_s(name, other.name);
        cout << "Manager (copy constructor) created\n";
    }//���������

    ~manager() {
        cout << "Manager destroyed\n";
    }// ����������
};

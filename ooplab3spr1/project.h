#pragma once
#include "employeer.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class project {
public:
	static int totalBudget; // �������� ����
	char name[256];
	char customer[256];
	int budget;//3 ������� ��������
	vector<employeer> team;
	project() : name(""), customer(""), budget(0) {}
	project(const char* name, const char* customer, int budget) : budget(budget) {
		strcpy_s(this->name, name);
		strcpy_s(this->customer, customer);
	}//����������� ��� ���������
	project(const project& other) {
		strcpy_s(this->name, other.name);
		strcpy_s(this->customer, other.customer);
		this->budget = other.budget;
	}// ����������� ���������
	~project() {
		cout << "Project destroyed\n";
	}// ����������
	static void increaseTotalBudget(int amount) {
		totalBudget += amount;
	}// ��������� �����
	static void printTotalBudget() {
		cout << "Total Project Budget: " << totalBudget << endl;
	}
	void printInfo() {
		cout << name << endl;
		cout << customer << endl;
		cout << budget << endl;
		cout << manager << endl;
		cout << teams << endl;
		cout << employeers << endl;
		cout << tasks << endl;
		cout << resourses << endl;
	};//����� � ������������� ��� ����
	void setManager(const char* newManager) {
		strcpy_s(manager, sizeof(manager), newManager);
	}
	void setTeams(const char* newTeams) {
		strcpy_s(teams, sizeof(teams), newTeams);
	}
	void setEmployeers(const char* newEmployeers) {
		strcpy_s(employeers, sizeof(employeers), newEmployeers);
	}
	void setTasks(const char* newTasks) {
		strcpy_s(tasks, sizeof(tasks), newTasks);
	}
	void setResources(const char* newResourses) {
		strcpy_s(resourses, sizeof(resourses), newResourses);
	}//������
	project operator+(const project& other) {
		project result;
		result.budget = this->budget + other.budget;
		strcpy_s(result.name, sizeof(result.name), this->name);
		strcat_s(result.name, sizeof(result.name), other.name);
		strcpy_s(result.customer, sizeof(result.customer), this->customer);
		strcat_s(result.customer, sizeof(result.customer), other.customer);
		strcpy_s(result.manager, sizeof(result.manager), this->manager);
		strcat_s(result.manager, sizeof(result.manager), other.manager);
		strcpy_s(result.teams, sizeof(result.teams), this->teams);
		strcat_s(result.teams, sizeof(result.teams), other.teams);
		strcpy_s(result.employeers, sizeof(result.employeers), this->employeers);
		strcat_s(result.employeers, sizeof(result.employeers), other.employeers);
		strcpy_s(result.tasks, sizeof(result.tasks), this->tasks);
		strcat_s(result.tasks, sizeof(result.tasks), other.tasks);
		strcpy_s(result.resourses, sizeof(result.resourses), this->resourses);
		strcat_s(result.resourses, sizeof(result.resourses), other.resourses);
		result.budget = this->budget + other.budget;
		return result;
	}//�������������� �����, ���� ������ � ����� ��������� ��'��� �����
	friend ostream& operator<<(ostream& os, const project& p) {
		os << "Project Name: " << p.name << endl;
		os << "Customer: " << p.customer << endl;
		os << "Budget: " << p.budget << endl;
		os << "Manager: " << p.manager << endl;
		os << "Teams: " << p.teams << endl;
		os << "Employeers: " << p.employeers << endl;
		os << "Tasks: " << p.tasks << endl;
		os << "Resources: " << p.resourses << endl;
		return os;
	}//�������������� �����, ���� ������� ��� �����
	void writeToFile(const std::string& filename) const {
		std::ofstream file(filename);
		if (file.is_open()) {
			file << name << endl;
			file << customer << endl;
			file << budget << endl;
			file << manager << endl;
			file << teams << endl;
			file << employeers << endl;
			file << tasks << endl;
			file << resourses << endl;
			file.close();
		}
	}//����� ��� ������ � ����
	void readFromFile(const std::string& filename) {
		std::ifstream file(filename);
		if (file.is_open()) {
			file.getline(name, 256);
			file.getline(customer, 256);
			file >> budget;
			file.ignore();
			file >> manager;
			file >> teams;
			file >> employeers;
			file >> tasks;
			file >> resourses;
			file.close();
		}
		else {
			cerr << "Unable to open file: " << filename << endl;
		}
	}//����� ��� ������� � �����
	void changeBudget(int newBudget) {
		budget = newBudget;
	}//����� ��� ���� �������
	void addEmployeer(const employeer& e) {
		team.push_back(e);
	}//����� ��� ��������� �������� �� �������
	void printProjectInfo() const {
		cout << "Project Name: " << name << endl;
		cout << "Customer: " << customer << endl;
		cout << "Budget: " << budget << endl;
		cout << "Team Members:" << endl;
		for (size_t i = 0; i < team.size(); i++) {
			cout << i + 1 << ". " << team[i] << endl;
		}
	}


private:
	char manager[256];
	char teams[128];
	char employeers[1028];
	employeer employeer;//��'���� ���� ��'����
	char tasks[5086];
	char resourses[5086];//5 ��������� ��������
};

static int totalBudget;// ����������� ���������� ����
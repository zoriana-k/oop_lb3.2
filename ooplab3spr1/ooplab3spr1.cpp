#include <iostream>
#include "manager.h"
#include "project.h"
#include "customer.h"
#include "employeer.h"
#include "team.h"

void processProject(const project& p) {
    cout << "Processing project: " << p.name << endl;
    cout << "Customer: " << p.customer << endl;
    cout << "Budget: " << p.budget << endl;
}// ������� ���� ������ �����

void processProject(const project* p) {
    if (p) {
        cout << "Processing project: " << p->name << endl;
        cout << "Customer: " << p->customer << endl;
        cout << "Budget: " << p->budget << endl;
    }
}//������������� �������

void processProjectPointer(const project* p) {
    cout << "Processing project by pointer: " << p->name << endl;
    cout << "Customer: " << p->customer << endl;
    cout << "Budget: " << p->budget << endl;
}//������� � ����������

project createNewProject(const char* name, const char* customer, int budget) {
    project p;
    strcpy_s(p.name, name);
    strcpy_s(p.customer, customer);
    p.budget = budget;
    return p;
}// ������� ��� ��������� ������ ��'���� ������� � ���������� ����

int main() {
    cout << "Demonstrating all constructors of manager class:\n";
    manager defaultManager;
    manager paramManager("Uzliuk Iryna");
    manager copiedManager = paramManager;//������������ 

    cout << "\nDemonstrating all constructors of project class:\n";
    project defaultProject;
    strcpy_s(defaultProject.name, "Advertisting campaign");
    strcpy_s(defaultProject.customer, "LadyBugAuto");
    defaultProject.budget = 45000;
    project parameterizedProject("Website development", "Sushi-Kushi", 50000);
    project copiedProject = parameterizedProject;//������������

    project projects[2] = { defaultProject, parameterizedProject }; // ��������� ���������� ������ ��'���� �������

    cout << "\nStatic array of projects:\n";
    for (const auto& p : projects) {
        processProject(p);  // ������� ������� ��� ������� ��'����
    }

    project* dynamicProjects = new project[2]{
        createNewProject("Website development", "Sushi-Kushi", 50000),
        createNewProject("Fixing bugs", "KvaCommision", 30000)
    };// ��������� ���������� ������ ��'���� �������

    cout << "\nDynamic array of projects:\n";
    for (int i = 0; i < 2; ++i) {
        processProject(dynamicProjects[i]);  //������� ������� ��� ������� ���������� ��'����
    }

    delete[] dynamicProjects;

    project::increaseTotalBudget(parameterizedProject.budget);// ������������ ��������� ������ ����� project ��� ��������� ������� �� ���� ���������
    project::printTotalBudget();

    processProject(parameterizedProject);//������ �������� �������
    processProject(&parameterizedProject);//������ ������������� �������
    processProjectPointer(&parameterizedProject);//������ ������� � ����������

    project newProject = createNewProject("Fixing bugs", "KvaCommision", 300000);
    manager projectManager("Uzliuk Iryna");

    cout << "\nDemonstrating assotiatio n between customer and project:\n";
    customer cust;
    strcpy_s(cust.name, "KvaCommision");
    cust.associateProject(&newProject);
    cust.assignManager(&projectManager);
    cust.printProjectInfo();//���������

    cout << "\nDemonstrating composition with team class:\n";
    team t("Solodyuk Andrii"); 
    t.printTeamLeader();// ����������

    cout << "\nDemonstrating dynamic memory allocation:\n";
    project* dynamicProject = new project();
    dynamicProject->budget = 45000;
    cout << "Dynamic project budget: " << dynamicProject->budget << endl;
    delete dynamicProject;  // ������������ �������� ���'�� ��� ��������� �������

    //���������
    cout << "\nDemonstrating aggregation between employeer and project:\n";
    employeer emp1;
    strcpy_s(emp1.name, "Lisovska Viktoria");
    strcpy_s(emp1.position, "Marketer");
    emp1.experience = 6;
    emp1.setEmployeerID("Fairy");
    emp1.setTeam("Tales");
    emp1.setTasks("Develop and implement marketing strategies to promote the project. Manage social media campaigns, email marketing, and ads. Analyze market trends and customer feedback to optimize campaigns.");
    emp1.setResources("Marketing Tools, Design Tools, SEO & SEM Tools, Collaboration Tools");
    emp1.setBudget(30000);
    newProject.addEmployeer(emp1);
    employeer emp2;
    strcpy_s(emp2.name, "Suska Nadia");
    strcpy_s(emp2.position, "Tester");
    emp2.experience = 5;
    emp2.setEmployeerID("Angel");
    emp2.setTeam("Tales");
    emp2.setTasks("Test software and applications to identify bugs and issues. Develop test cases and scenarios based on project requirements. Collaborate with developers to ensure product quality and functionality.");
    emp2.setResources("Testing Tools, Bug Tracking Tools, Automation Tools, Collaboration Tools.");
    emp2.setBudget(35000);
    newProject.addEmployeer(emp2);
    newProject.printProjectInfo();

    return 0;
}

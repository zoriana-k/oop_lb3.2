class customer {
public:
    char name[128];
    project* associatedProject;
    manager* projectManager;  // асоціація

    customer() : associatedProject(nullptr), projectManager(nullptr) {}

    void associateProject(project* p) {
        associatedProject = p;
    }

    void assignManager(manager* m) {
        projectManager = m;
    }

    void printProjectInfo() {
        if (associatedProject) {
            cout << "Customer: " << name << endl;
            cout << "Associated project: " << associatedProject->name << endl;
            if (projectManager) {
                cout << "Manager: " << projectManager->name << endl;
            }
        }
    }
};

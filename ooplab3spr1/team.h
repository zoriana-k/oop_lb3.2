#pragma once
#include "employeer.h"

class team {
private:
    employeer teamLeader; // ����������

public:
    team(const char* leaderName) {
        strcpy_s(teamLeader.name, leaderName);
    }

    void printTeamLeader() {
        cout << "Team leader: " << teamLeader.name << endl;
    }
};

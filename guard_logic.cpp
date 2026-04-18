#include <iostream>
#include <vector>
using namespace std;

enum DoorType {
    SAFE_EXIT,
    TRAP,
    BACK_TO_START
};

class Door {
public:
    DoorType type;
    bool isSafe;
    bool hasTrap;
    bool isVisited;

    Door(DoorType t, bool safe, bool trap, bool visited) {
        type = t;
        isSafe = safe;
        hasTrap = trap;
        isVisited = visited;
    }
};

class GuardSystem {
public:
    // Score-based decision (creative logic)
    int calculateScore(Door &d) {
        int score = 0;

        if (d.isSafe) score += 50;
        if (!d.hasTrap) score += 30;
        if (!d.isVisited) score += 20;

        return score;
    }

    Door chooseBestDoor(vector<Door>& doors) {
        int maxScore = -1;
        Door best = doors[0];

        for (auto &d : doors) {
            int score = calculateScore(d);

            cout << "Door Score: " << score << endl;

            if (score > maxScore) {
                maxScore = score;
                best = d;
            }
        }

        return best;
    }

    string getDoorName(DoorType t) {
        if (t == SAFE_EXIT) return "Safe Exit Door";
        if (t == TRAP) return "Trap Door";
        return "Back to Start Door";
    }

    void explainChoice(Door &d) {
        cout << "\nReason for selection:\n";
        if (d.isSafe) cout << "- It is safe\n";
        if (!d.hasTrap) cout << "- No trap detected\n";
        if (!d.isVisited) cout << "- Not visited before\n";
    }
};

int main() {
    GuardSystem system;

    // Multiple test cases (creative bonus)
    vector<Door> doors = {
        Door(SAFE_EXIT, true, false, false),
        Door(TRAP, false, true, false),
        Door(BACK_TO_START, false, false, true)
    };

    Door result = system.chooseBestDoor(doors);

    cout << "\nChosen Door: " << system.getDoorName(result.type) << endl;

    system.explainChoice(result);

    return 0;
}
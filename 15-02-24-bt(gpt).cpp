#include <iostream>
#include <vector>

using namespace std;

struct soluzione {
    vector<vector<unsigned>> corsi; // corsi per ogni studente
    vector<vector<unsigned>> sol; // assegnazione dei corsi agli slot
    unsigned k; // numero di slot disponibili



    bool isComplete() {
        vector<bool> courseAssigned(corsi.size(), false);
        for (int i = 0; i < sol.size(); i++) {
            for (int j = 0; j < sol[i].size(); j++) {
                courseAssigned[sol[i][j] - 1] = true;
            }
        }
        for (int i = 0; i < courseAssigned.size(); i++) {
            if (!courseAssigned[i]) {
                return false;
            }
        }
        return true;
    }

    bool canAdd(unsigned course, unsigned slot) {
        for (int i = 0; i < corsi.size(); i++) {
            for (int j = 0; j < corsi[i].size(); j++) {
                if (corsi[i][j] == course) {
                    for (int k = 0; k < corsi[i].size(); k++) {
                        if (sol[slot - 1].size() > 0 && find(sol[slot - 1].begin(), sol[slot - 1].end(), corsi[i][k]) != sol[slot - 1].end()) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    void add(unsigned course, unsigned slot) {
        sol[slot - 1].push_back(course);
    }

    void remove(unsigned course, unsigned slot) {
        if (sol[slot - 1].size() > 0) {
            sol[slot - 1].pop_back();
        }
    }

    bool solve() {
        for (int course = 1; course <= corsi.size(); course++) {
            for (int slot = 1; slot <= k; slot++) {
                if (canAdd(course, slot)) {
                    add(course, slot);
                    if (isComplete()) {
                        return true;
                    }
                    if (solve()) {
                        return true;
                    }
                    remove(course, slot);
                }
            }
        }
        return false;
    }

    void printsol() {
        for (int i = 0; i < sol.size(); i++) {
            for (int j = 0; j < sol[i].size(); j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
};


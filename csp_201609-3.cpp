#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct follower {
    int hp;
    int attack;
    follower(int h, int a) : hp(h), attack(a) {}
};

vector<follower> player[2];

int main() {
    int N;
    while (cin >> N) {
        int pid = 0;
        player[0].push_back(follower(30, 0));
        player[1].push_back(follower(30, 0));
        for (int n = 0; n < N; n++) {
            string type;
            cin >> type;
            if (type == "summon") {
                int pos, h, a;
                cin >> pos >> a >> h;
                player[pid].insert(player[pid].begin() + pos, follower(h, a));
            } else if (type == "attack") {
                int att, deff;
                cin >> att >> deff;
                player[pid][att].hp -= player[!pid][deff].attack;
                player[!pid][deff].hp -= player[pid][att].attack;
                if (player[pid][att].hp <= 0 && att != 0) {
                    player[pid].erase(player[pid].begin() + att);
                }
                if (player[!pid][deff].hp <= 0 && deff != 0) {
                    player[!pid].erase(player[!pid].begin() + deff);
                }
            } else if (type == "end") {
                pid = !pid;
            }
        }
        if (player[0][0].hp > 0 && player[1][0].hp > 0)
            cout << 0 << endl;
        else if (player[0][0].hp > 0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        for (int i = 0; i < 2; i++) {
            cout << player[i][0].hp << endl;
            cout << player[i].size() - 1 << " ";
            for (int j = 1; j < player[i].size(); j++) {
                cout << player[i][j].hp << " ";
            }
            cout << endl;
        }
    }
}

#include "cstring"
#include "iostream"
using namespace std;

int n;
char x, y;
int winner(char x, char y) {
    if (x == 'S' && y == 'S') {
        return 2;
    }
    if (x == 'B' && y == 'B') {
        return 2;
    }
    if (x == 'J' && y == 'J') {
        return 2;
    }

    if (x == 'S' && y == 'J') {
        return 0;
    }
    if (x == 'J' && y == 'B') {
        return 0;
    }
    if (x == 'B' && y == 'S') {
        return 0;
    }

    if (x == 'B' && y == 'J') {
        return 1;
    }
    if (x == 'J' && y == 'S') {
        return 1;
    }
    if (x == 'S' && y == 'B') {
        return 1;
    }
}
int main() {
    int cnt[3];
    while (cin >> n) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            cnt[winner(x, y)]++;
        }
        if (cnt[0] > cnt[1]) {
            cout << "suantou" << endl;
            continue;
        } else if (cnt[0] < cnt[1]) {
            cout << "huaye" << endl;
            continue;
        } else if (cnt[0] == cnt[1]) {
            cout << "QAQ" << endl;
            continue;
        }
    }
}
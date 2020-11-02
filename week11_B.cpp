#include "iostream"
using namespace std;
int n;
int a[21][21], b[21][21];

int judge() {
    int is[4];
    for (int i = 0; i < 4; i++) is[i] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) {
                is[0] = 0;
            }
            if (a[n - 1 - j][i] != b[i][j]) {
                is[1] = 0;
            }
            if (a[n - 1 - i][n - 1 - j] != b[i][j]) {
                is[2] = 0;
            }
            if (a[j][n - 1 - i] != b[i][j]) {
                is[3] = 0;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (is[i]) {
            return i;
        }
    }
    return -1;
}
int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b[i][j];
            }
        }
        cout << judge() << endl;
    }
}
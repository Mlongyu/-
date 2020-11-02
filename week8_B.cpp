#include <iostream>
using namespace std;

int a[501][501], inDegree[501];
int n, m, p1, p2;

void topsort() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (inDegree[j] == 0) {
                inDegree[j]--;
                cout << j;
                if (i != n)
                    cout << " ";
                else
                    cout << endl;

                for (int k = 1; k <= n; k++) {
                    if (a[j][k] == 1) inDegree[k]--;
                }
                break;
            }
        }
    }
}
int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n + 1; i++) {
            inDegree[i] = 0;
            for (int j = 0; j < n + 1; j++) {
                a[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> p1 >> p2;
            if (a[p1][p2] == 0) {
                a[p1][p2] = 1;
                inDegree[p2]++;
            }
        }
        topsort();
    }
    return 0;
}

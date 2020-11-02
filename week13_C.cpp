#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int f[100001][20], temp, m;

int main() {
    while (cin >> m) {
        if (m == 0) break;
        temp = 0;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            f[b][a]++;
            if (b > temp) temp = b;
        }

        for (int i = temp - 1; i >= 0; i--)
            for (int j = 0; j <= 10; j++)
                f[i][j] +=
                    max(f[i + 1][j - 1], max(f[i + 1][j], f[i + 1][j + 1]));
        cout << f[0][5] << endl;
    }
}

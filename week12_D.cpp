#include <cstring>
#include <iostream>
using namespace std;


int n, f[1001][1001];

string s;
bool judge(int i, int j) {
    if (s[i] == '[' && s[j] == ']') return 1;
    if (s[i] == '(' && s[j] == ')') return 1;
    return 0;
}

int main() {
    while (cin >> s) {
        if (s == "end") {
            break;
        }
        n = s.length();
        memset(f, 0, sizeof(f));
        for (int ii = 1; ii < n; ii++)
            for (int i = 0; i + ii < n; i++) {
                int j = i + ii;
                if (judge(i, j)) {
                    if (j == i + 1)
                        f[i][j] = 2;
                    else
                        f[i][j] = f[i + 1][j - 1] + 2;
                }
                for (int k = i; k < j; k++)
                    f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
            }
        cout << f[0][n - 1] << endl;
    }
    return 0;
}
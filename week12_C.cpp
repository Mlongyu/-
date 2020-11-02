#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int minN =-1100000000;
int n, m;
int f[1000001], a[1000001], ff[1000001];
int main() {
    while (scanf("%d", &m) != EOF) {
        memset(ff, 0, sizeof(ff));
        memset(f, 0, sizeof(f));
        int ans = minN;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= m; i++) {
            int mn = minN;
            for (int j = i; j <= n; j++) {
                f[i - 1] = minN;
                f[j] = max(f[j - 1] + a[j], ff[j - 1] + a[j]);
                ff[j - 1] = mn;
                mn = max(f[j], mn);
                if (i == m) {
                    ans = max(f[j], ans);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
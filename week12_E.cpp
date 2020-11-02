#include <cstring>
#include <iostream>
using namespace std;
const int maxX = 1e9;

struct node {
    string cla;
    int d;
    int c;
} a[16];

int n, f[1 << 16], pre[1 << 16], sum[1 << 16];

void output(int x) {
    if (x == 0) return;
    output(x - (1 << pre[x]));
    cout << a[pre[x]].cla << endl;
}
int main() {
    int T;
    while (cin >> T) {
        while (T--) {
            memset(f, 0, sizeof(f));
            memset(pre, 0, sizeof(pre));
            memset(sum, 0, sizeof(sum));
            cin >> n;
            for (int i = 0; i < n; i++) cin >> a[i].cla >> a[i].d >> a[i].c;
            int tot = (1 << n);
            for (int i = 1; i <= tot; i++) {
                f[i] = maxX;
                for (int j = n - 1; j >= 0; j--) {
                    int now = 1 << j;
                    if (!(i & now)) continue;
                    int tmp = sum[i - now] + a[j].c - a[j].d;
                    tmp = max(0, tmp);
                    if (f[i] > f[i - now] + tmp) {
                        f[i] = f[i - now] + tmp;
                        sum[i] = sum[i - now] + a[j].c;
                        pre[i] = j;
                    }
                }
            }
            cout << f[tot - 1] << endl;
            output(tot - 1);
        }
    }

    return 0;
}
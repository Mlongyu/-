#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

long long n;
struct _point {
    long long x;
    long long y;

    bool operator<(_point t) {
        if (x == t.x) return y < t.y;
        return x < t.x;
    }

} p[2000];
struct set {
    long long x;
    long long y;
    long long r;

    bool operator<(set t) {
        if (r != t.r) return r < t.r;
        if (x != t.x) return x < t.x;
        return y < t.y;
    }

} ans[2000];

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (long long i = 1; i <= n; i++) {
            cin >> p[i].x >> p[i].y;
        }
        sort(p + 1, p + n + 1);
        for (long long i = 1; i <= n; i++) {
            long long rr = 0;
            for (long long j = 1; j <= n; j++) {
                long long t = (long long)(p[i].x - p[j].x) * (p[i].x - p[j].x) +
                        (long long)(p[i].y - p[j].y) * (p[i].y - p[j].y);
                if (rr < t) {
                    rr = t;
                }
            }
            ans[i].r = rr;
            ans[i].x = p[i].x;
            ans[i].y = p[i].y;
        }
        sort(ans + 1, ans + 1 + n);
        cout << ans[1].x << ".00 " << ans[1].y << ".00\n";
        cout << ans[1].r << ".00" << endl;
    }

    return 0;
}

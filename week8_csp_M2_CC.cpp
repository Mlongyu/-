#include <iostream>
#include <string>
using namespace std;

int q;
long long k, pos;

long long getNum(long long x) {
    long long a = 1, d = 1, n = 0, judge = 10, sn = 0;
    for (; judge <= x; d++, judge *= 10) {
        n = judge - judge / 10;
        sn += a * n + n * (n - 1) * d / 2;
        a = a + (n - 1) * d + (d + 1);
    }
    long long nn = x - judge / 10 + 1;
    return sn + a * nn + nn * (nn - 1) * d / 2;
}

long long getNum1(long long x) {
    long long d = 1, n = 0, judge = 10, sn = 0;
    for (; judge <= x; d++, judge *= 10) {
        n = judge - judge / 10;
        sn += n * d;
    }
    return sn + (x - judge / 10 + 1) * d;
}
int main() {
    while (cin >> q) {
        for (int i = 0; i < q; ++i) {
            cin >> k;
            long long l = 0, r = 1e9;
            int ans = 0;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                if (getNum(mid) < k) {
                    l = mid + 1;
                    ans = mid;
                } else
                    r = mid - 1;
            }
            k = k - getNum(ans);
            l = 0, r = 1e9;
            pos = 0;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                if (getNum1(mid) < k) {
                    l = mid + 1;
                    pos = mid;
                } else
                    r = mid - 1;
            }
            string outs = to_string(pos + 1);
            cout << outs[k - getNum1(pos) - 1] << endl;
        }
    }

    return 0;
}

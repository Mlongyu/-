#include "algorithm"
#include "iostream"
using namespace std;
int a[101];
int x, y;
int main() {
    while (cin >> x) {
        cin >> y;
        int tot = 0;
        for (int i = 0; i < x; i++) {
            cin >> a[i];
            tot += a[i];
        }
        sort(a, a + x);
        tot -= a[x - 1];
        int mx = a[x - 1] + y, mn, leftCount, yuShu, tot1;
        tot1 = tot + y;
        if (tot1 <= a[x - 1] * (x - 1)) {
            mn = a[x - 1];
        } else {
            leftCount = (tot + a[x - 1] + y) - a[x - 1] * x;
            yuShu = leftCount % x;
            if (yuShu == 0) {
                mn = a[x - 1] + leftCount / x;
            } else {
                mn = a[x - 1] + leftCount / x + 1;
            }
        }
        cout << mn << " " << mx << endl;
    }
    return 0;
}
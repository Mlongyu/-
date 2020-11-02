#include "iostream"
using namespace std;
int main() {
    int n, x, l, r;

    while (scanf("%d %d", &n, &x) != EOF) {
        int cur = 1, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> l >> r;
            while (cur + x <= l) {
                cur += x;
            }
            ans += r - cur + 1;
            cur = r + 1;
        }
        cout << ans << endl;
    }
}
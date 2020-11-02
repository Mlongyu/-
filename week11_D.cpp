#include "algorithm"
#include "iostream"
using namespace std;
int n;
int main() {
    while (cin >> n) {
        int a[100001], cnt[100001] = {0};
        int ct = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0) {
                if (a[i] == a[i - 1]) {
                    cnt[ct]++;
                } else {
                    ct++;
                    cnt[ct]++;
                }

            } else {
                cnt[ct]++;
            }
        }
        int mx = 0;
        for (int i = 0; i <= ct; i++) {
            mx = max(min(cnt[i], cnt[i + 1]) * 2, mx);
        }
        cout << mx << endl;
    }
}
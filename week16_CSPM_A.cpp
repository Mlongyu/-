#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n, k, ans, t;

int main() {
    string str;
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        if (k > 10) {
            for (int i = 1; i <= n; i++) cin >> t;
            cout << n;
        } else {
            for (int i = 1; i <= n; i++) {
                cin >> str;
                sort(str.begin(), str.end());
                int cnt = 1;
                for (int j = 0; j < str.size() - 1; j++) {
                    if (str[j + 1] != str[j]) cnt++;
                }
                if (cnt < k) ans++;
            }
            cout << ans;
        }
        str.clear();
    }

    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct seg {
    int a, b;
    bool operator<(const seg &s) const {
        if (b != s.a) return a < s.a;
    }
};
seg set[30000];
int main() {
    int N, T;
    while (cin >> N >> T) {
        for (int i = 1; i <= N; i++) {
            cin >> set[i].a >> set[i].b;
        }
        sort(set + 1, set + N + 1);
        int position = 0, m = 0,ans = 0;
        for (int i = 1; i <= N; i++) {
            int count = 0;
            while (set[i].a <= position + 1 && i <= N) {
                if (set[i].b > m) {
                    count++;
                    m = set[i].b;
                }
                i++;
            }
            i--;
            position = m;
            if (count > 0)
                ans++;
            else
                break;
        }
        if (position < T)
            cout << "-1\n";
        else
            cout << ans << endl;
    }

    return 0;
}

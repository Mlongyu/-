#include <iostream>
using namespace std;
long long a[100001];
long long dp[100001];
int maxx = 0;
int n;
int main() {
    while (cin >> n) {
        int temp;
        for (int i = 1; i <= n; i++) {
            cin >> temp;
            a[temp]++;
            maxx = max(maxx, temp);
        }
        dp[1] = a[1];
        for (int i = 2; i <= maxx; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);
        }
        cout << dp[maxx] << endl;
    }
}

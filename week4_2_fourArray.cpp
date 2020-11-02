#include "algorithm"
#include "iostream"
using namespace std;
int n;
int ans = 0;
int a1[4001], a2[4001], a3[4001], a4[4001];
int sum1[4001 * 4001], sum2[4001 * 4001];
int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a1[i] >> a2[i] >> a3[i] >> a4[i];
        }
        /*for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            system("pause");
            cout << endl;
        }*/
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum1[count] = a1[i] + a2[j];
                sum2[count] = a3[i] + a4[j];
                // cout<<sum1[count]<<" "<<sum2[count]<<endl;
                count++;
            }
        }
        sort(sum1, sum1 + n * n);
        int l, r;
        for (int i = 0; i < count; i++) {
            l = 0;
            r = count - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sum1[mid] + sum2[i] >= 0)
                    r = mid - 1;
                else
                    l = mid + 1;
                while (sum1[l] + sum2[i] == 0 &&
                       l < count) {  //相同的数字出现多次，加起来
                    ans++;
                    l++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
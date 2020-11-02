#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct homeWork {
    int ddl;
    int score;
    bool operator<(homeWork z) {
        if (score > z.score)
            return true;
        else
            return false;
    }
} work[1001];
bool done[1001];
int n, num;
int DDL[1001], mark[1001];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        memset(done, false, sizeof(done));
        cin >> num;
        int ans = 0;
        for (int j = 0; j < num; j++) {
            cin >> work[j].ddl;
        }
        for (int k = 0; k < num; k++) {
            cin >> work[k].score;
            ans += work[k].score;
        }
        sort(work, work + num);
        for (int j = 0; j < num; j++) {
            for (int p = work[j].ddl; p >= 1; p--) {
                if (!done[p]) {
                    done[p] = true;
                    //可以做，要扣的分减掉
                    ans -= work[j].score;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
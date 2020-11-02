#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct reg {
    int startTime;  //开始时间，
    int endTime;    //结束时间
    bool operator<(const reg &t) const {
        if (startTime != t.startTime) return startTime < t.startTime;
    }
};

reg Time[100];
reg ans[100];
int tot;
int A, B, N;

void f(int t) {
    int t1 = t / 60;
    if (t1 < 10) cout << 0;
    cout << t1;
    cout << ":";

    int t2 = t % 60;
    if (t2 < 10) cout << 0;
    cout << t2;
}

int a, b;
char c;
int main() {
    while (cin >> A >> B >> N) {  // A至少休息的时间  B最多睁眼的时间
        A *= 60, B *= 60;
        tot = 0;
        int ret = 1;  //可以
        memset(Time, 0, sizeof(Time));
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < N; i++) {
            cin >> a >> c >> b;
            Time[i].startTime = a * 60 + b;
            cin >> c;
            cin >> a >> c >> b;
            Time[i].endTime = a * 60 + b;
            if (Time[i].startTime > Time[i].endTime) Time[i].endTime += 24 * 60;
            if (Time[i].endTime - Time[i].startTime > B) {
                ret = 0;
                break;
            }
        }
        sort(Time, Time + N);

        reg last;
        last.startTime = Time[0].startTime, last.endTime = Time[0].endTime;

        for (int i = 1; i < N; i++) {
            int tmp = Time[i].startTime - last.endTime - 1;
            if (tmp >= A) {  //可以睡觉
                ans[tot].startTime = last.endTime + 1;
                ans[tot].endTime = Time[i].startTime - 1;
                last = Time[i];
                tot++;
            } else {  //不可以睡觉
                last.endTime = Time[i].endTime;
                if (last.endTime - last.startTime + 1 > B) {  //超时
                    ret = 0;
                    break;
                }
            }
        }
        if (!ret) {
            cout << "No" << endl;
            continue;
        }
        //检查交界处
        if (Time[0].startTime + 24 * 60 - last.endTime - 1 >= A) {  //可以睡觉
            ans[tot].startTime = (last.endTime + 1) % (60 * 24);
            ans[tot].endTime =
                (Time[0].startTime + 60 * 24 - 1) % (60 * 24);  //防止是负数
            tot++;
        } else if (tot == 0 || (ans[0].startTime - 1 + 60 * 24) % (60 * 24) -
                                       last.startTime + 1 >
                                   B) {  //不可以休息
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
        cout << tot << endl;
        for (int i = 0; i < tot; i++) {
            f(ans[i].startTime);
            cout << "-";
            f(ans[i].endTime);
            cout << endl;
        }
    }
    return 0;
}

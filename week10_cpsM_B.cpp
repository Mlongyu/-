#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct time {
    int yae, mon, day, hou, min, sec;
    time() {}
    time(int y, int mo, int d, int h, int mi, int s) {
        yae = y, mon = mo, day = d, hou = h, min = mi, sec = s;
    }
    bool operator<(const time &b) const {
        if (yae != b.yae) return yae < b.yae;
        if (mon != b.mon) return mon < b.mon;
        if (day != b.day) return day < b.day;
        if (hou != b.hou) return hou < b.hou;
        if (min != b.min) return min < b.min;
        return sec < b.sec;
    }
    bool operator>(const time &b) const { return b < *this; }
    bool operator<=(const time &b) const { return !(b < *this); }
    bool operator==(const time &b) const { return !(b < *this || *this < b); }

} s[25][120], e[25][120], t[4020];

int T, num[25], cnt, n;
time tbegin(1800, 1, 1, 0, 0, 0), tend(2200, 1, 1, 0, 0, 0);
int flag = 0;

void output(int i) {
    if (t[i].mon < 10) cout << "0";
    cout << t[i].mon << "/";
    if (t[i].day < 10) cout << "0";
    cout << t[i].day << "/";
    cout << t[i].yae << " ";
    if (t[i].hou < 10) cout << "0";
    cout << t[i].hou << ":";
    if (t[i].min < 10) cout << "0";
    cout << t[i].min << ":";
    if (t[i].sec < 10) cout << "0";
    cout << t[i].sec << "";
}
//确定空闲段的右边界
bool isRight(int index) {
    if (index == 0) return 0;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            tot++;
            continue;
        }
        if (t[index] <= s[i][1] && t[index] > tbegin) {
            tot++;
            continue;
        }
        if (t[index] > e[i][num[i]]) {
            tot++;
            continue;
        }
        if (t[index] == e[i][num[i]]) continue;
        for (int j = 1; j <= num[i]; j++) {
            if (t[index] > s[i][j] && t[index] <= e[i][j]) break;

            if (j + 1 <= num[i] && t[index] > e[i][j] &&
                t[index] <= s[i][j + 1]) {
                tot++;
                break;
            }
        }
    }

    if (tot >= 2 && tot >= n - 1)
        return 1;
    else
        return 0;
}
//确定空闲段的左边界
bool isLeft(int index) {
    if (index == cnt) return 0;

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            tot++;
            continue;
        }
        if (t[index] < s[i][1]) {
            tot++;
            continue;
        }

        if (e[i][num[i]] <= t[index] && tend > t[index]) {
            tot++;
            continue;
        }
        for (int j = 1; j <= num[i]; j++) {
            if (s[i][j] <= t[index] && e[i][j] > t[index]) break;
            if (j + 1 <= num[i] && e[i][j] <= t[index] &&
                s[i][j + 1] > t[index]) {
                tot++;
                break;
            }
        }
    }
    if (tot >= 2 && tot >= n - 1)
        return 1;
    else
        return 0;
}

//满足1h长
bool anhour(int left, int right) {
    time l = t[left], r = t[right];

    if (r.yae - l.yae >= 2) return 1;
    r.mon += (r.yae - l.yae) * 12;

    if (r.mon - l.mon >= 2) return 1;
    r.day += (r.mon - l.mon) * 30;

    if (r.day - l.day >= 2) return 1;
    r.hou += (r.day - l.day) * 24;

    if (r.hou - l.hou >= 2) return 1;
    r.min += (r.hou - l.hou) * 60;

    r.sec += (r.min - l.min) * 60;
    if (r.sec - l.sec >= 3600) return 1;
    return 0;
}

void judge(int left, int right) {
    if (!anhour(left, right)) return;
    flag = 1;
    cout << "appointment possible from ";
    output(left);
    cout << " to ";
    output(right);
    cout << endl;
}

int main() {
    cin.sync_with_stdio(false);
    while (cin >> T) {
        for (int cc = 1; cc <= T; cc++) {
            memset(num, 0, sizeof(num));
            memset(s, 0, sizeof(s));
            memset(e, 0, sizeof(e));
            memset(t, 0, sizeof(t));
            cnt = 0;
            flag = 0;
            t[++cnt] = tbegin;
            t[++cnt] = tend;
            cin >> n;
            for (int i = 1; i <= n; i++) {
                cin >> num[i];
                for (int j = 1; j <= num[i]; j++) {
                    cin >> s[i][j].yae >> s[i][j].mon >> s[i][j].day >>
                        s[i][j].hou >> s[i][j].min >> s[i][j].sec;
                    cin >> e[i][j].yae >> e[i][j].mon >> e[i][j].day >>
                        e[i][j].hou >> e[i][j].min >> e[i][j].sec;
                    t[++cnt] = s[i][j];
                    t[++cnt] = e[i][j];
                    string ttemp;
                    getline(cin, ttemp);
                }
            }
            sort(t + 1, t + 1 + cnt);
            cout << "Scenario #" << cc << ":\n";
            int left = 1, right = 1;
            while (left <= cnt && right <= cnt) {
                right++;
                if (right > cnt) break;
                //找到使时间段最长的右边界
                while (right <= cnt && isRight(right)) right++;
                right--;
                judge(left, right);
                left = right + 1;
                //确定左边界
                while (left <= cnt && !isLeft(left)) left++;
                right = left;
            }
            if (flag == 0) cout << "no appointment possible\n";
            cout << endl;
        }
    }
}

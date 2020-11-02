#include <iostream>
#include <stack>
using namespace std;

struct rectangle {
    int index;
    long long int height;  //数很大，用long long
};

int n;
long long int ans;
int _left[100001], _right[100001];  //左端点与右端点

rectangle p[100001],cur;
stack<rectangle> s;

int main() {
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            p[i].index = i;
            cin >> p[i].height;
        }
        ans = 0;

        //左端点
        for (int i = n - 1; i >= 0; i--) {  //往左数第一个小于h[i]的点
            while (s.size() > 0 && s.top().height > p[i].height) {
                cur = s.top();
                s.pop();
                _left[cur.index] = i;
            }
            s.push(p[i]);
        }
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            _left[cur.index] = -1;
        }
        //右端点
        for (int i = 0; i < n; i++) {  //往右数第一个小于h[i]的点
            while (s.size() > 0 && s.top().height > p[i].height) {
                cur = s.top();
                s.pop();
                _right[cur.index] = i;
            }
            s.push(p[i]);
        }

        while (!s.empty()) {
            cur = s.top();
            s.pop();
            _right[cur.index] = n;
        }
        //长度为_right-_left-1
        for (int i = 0; i < n; i++) {
            long long int ss = (_right[i] - _left[i] - 1) * p[i].height;
            if (ss > ans) ans = ss;
        }
        cout << ans << endl;
    }
}

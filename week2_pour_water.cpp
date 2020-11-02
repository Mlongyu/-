#include "iostream"
#include "queue"
#include "vector"
using namespace std;
struct status  //记录状态的结构体
{
    int A, B;  // A，B杯子水含量
    status(int _A, int _B) {
        A = _A;
        B = _B;
    }
};
void Print(int& x, int& y, int& B);
int AB[1001][1001], opNum[1001][1001];
void bfs(int A, int B, int C)  //广度优先搜索
{
    queue<status> q;
    q.push(status(0, 0));
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            AB[i][j] = -1;
        }
    }

    AB[0][0] = 0;
    while (!q.empty()) {
        status cur = q.front();
        q.pop();
        int a = cur.A, b = cur.B;
        //switch
        for (int i = 0; i < 6; i++) {
            int x = -1, y = -1;
            if (i == 0 && a < A && -1 == AB[A][b]) {
                x = A;
                y = b;
            }
            if (i == 1 && b < B && -1 == AB[a][B]) {
                x = a;
                y = B;
            }
            if (i == 2 && b < B && a > 0) {
                if (a > B - b && -1 == AB[a - B + b][B]) {
                    x = a - B + b;
                    y = B;
                }
                if (a < B - b && -1 == AB[0][b + a]) {
                    x = 0;
                    y = b + a;
                }
            }
            if (i == 3 && a < A && b > 0) {
                if (b > A - a && -1 == AB[A][b - A + a]) {
                    y = b - A + a;
                    x = A;
                }
                if (b < A - a && -1 == AB[b + a][0]) {
                    y = 0;
                    x = b + a;
                }
            }
            if (i == 4 && -1 == AB[0][b]) {
                x = 0;
                y = b;
            }
            if (i == 5 && -1 == AB[a][0]) {
                x = a;
                y = 0;
            }

            if (x != -1 && y != -1) {
                opNum[x][y] = i;
                AB[x][y] = a * B + a + b;
                if (x == C || y == C)  //罐子中包含C单位的水，结束搜索
                {
                    Print(x, y, B);
                    return;
                }
                q.push(status(x, y));
            }
        }
    }
}
void Print(int& x, int& y, int& B)  //输出
{
    int a = x, b = y;
    vector<int> ans;
    while (AB[a][b] != a * B + a + b) {
        int ta = AB[a][b] / (B + 1), tb = AB[a][b] % (B + 1);
        ans.push_back(opNum[a][b]);
        a = ta;
        b = tb;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        switch (ans[i]) {
            case 0:
                cout << "fill A\n";
                break;
            case 1:
                cout << "fill B\n";
                break;
            case 2:
                cout << "pour A B\n";
                break;
            case 3:
                cout << "pour B A\n";
                break;
            case 4:
                cout << "empty A\n";
                break;
            default:
                cout << "empty B\n";
                break;
        }
    }
    cout << "success\n";
}
int main() {
    int A, B, C;
    while (cin >> A >> B >> C)
        if (0 == C)
            cout << "success\n";
        else
            bfs(A, B, C);
    // system("pause");/*吸取教训，这玩意不能一块带进vj*/
    return 0;
}
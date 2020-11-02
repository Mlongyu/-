#include <iostream>
using namespace std;
int father[30005], _rank[30005];

int find(int x) {
    if (father[x] == x) return x;
    return father[x] = find(father[x]);
}
void combine(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (_rank[x] > _rank[y]) swap(y, x);
    father[x] = y;
    _rank[x] = (_rank[y] += _rank[x]);
}
int n, m;
int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; i++) _rank[i] = 1;
        for (int i = 0; i < n; i++) father[i] = i;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            int stu1, stu2;
            cin >> stu1;
            for (int j = 0; j < num - 1; j++) {
                cin >> stu2;
                combine(stu1, stu2);
                stu1 = stu2;
            }
        }
        cout << _rank[find(0)] << endl;
    }
    return 0;
}

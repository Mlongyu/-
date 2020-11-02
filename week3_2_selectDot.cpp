#include <algorithm>
#include <iostream>
using namespace std;

struct seg {
    int a;
    int b;
    bool operator<(const seg& S) const {
        return b < S.b || b == S.b && a > S.a;
    }
};
seg set[101];

int main() {
    int i, n, count;
    while (cin >> n) {
        count = 1;
        for (i = 0; i < n; i++) {
            cin >> set[i].a;
            cin >> set[i].b;
        }

        sort(set, set + n);  //按b从小到大排序

        int newEnd = set[0].b;
        // cout << "(" << set[0].a << "," << set[0].b << ")"<< "  ";
        for (i = 1; i < n; i++) {
            if (newEnd < set[i].a) {
                count++;
                newEnd = set[i].b;
                // cout << "(" << set[i].a << "," << set[i].b << ")"<< "  ";
            }
        }
        cout << count << endl;
    }
    return 0;
}
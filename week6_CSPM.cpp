#include "algorithm"
#include "iostream"
using namespace std;
struct poke {
    int size;
    int color;
    bool operator<(const poke& S) const {
        return size < S.size || size == S.size && color < S.color;
    }
    bool operator==(const poke& S) const {
        return size == S.size && color == S.color;
    }
};
int A, B, x[2], y[2];
poke a[5];
int main() {
    while (cin >> A >> B) {
        int t2 = 0;
        int type[9] = {0};
        poke set[A * B];

        for (int i = 0; i < 2; i++) {
            cin >>x[i]>> y[i];
        }
        int cnt = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if (i == x[0] && j == y[0] || i == x[1] && j == y[1]) {
                    set[cnt].size = 999;
                    set[cnt].color = 999;
                    continue;
                }
                set[cnt].size = i;
                set[cnt].color = j;
                cnt++;
            }
        }
        sort(set, set + cnt);
        /*for (int i = 0; i < cnt; i++) {
            cout << set[i].size << " " << set[i].color << endl;
        }*/

        int c = 0;
        for (int i = 0; i < (A * B - 4); i++) {
            for (int j = i + 1; j < (A * B - 3); j++) {
                for (int k = j + 1; k < A * B - 2; k++) {
                    a[0].size = x[0];
                    a[0].color = y[0];
                    a[1].size = x[1];
                    a[1].color = y[1];
                    a[2].size = set[i].size;
                    a[2].color = set[i].color;
                    a[3].size = set[j].size;
                    a[3].color = set[j].color;
                    a[4].size = set[k].size;
                    a[4].color = set[k].color;
                    sort(a, a + 5);
                    /*for (int tt = 0; tt < 5; tt++) {
                        cout << a[tt].size << " " << a[tt].color << endl;
                    }
                    cout << "=====" << endl;*/
                    int c1 = 0;
                    int temp;
                    int t[4];
                    for (int o = 0; o < 4; o++) {
                        int temp = a[o + 1].size - a[o].size;
                        if (temp == 0) {
                            t[c1] = o;
                            c1++;
                        }
                    }

                    if ((a[0].size + 1 == a[1].size) &&
                        (a[1].size + 1 == a[2].size) &&
                        (a[2].size + 1 == a[3].size) &&
                        (a[3].size + 1 == a[4].size) &&
                        (a[0].color == a[1].color) &&
                        (a[1].color == a[2].color) &&
                        (a[2].color == a[3].color) &&
                        (a[3].color == a[4].color)) {
                        type[0]++;
                    } else if ((a[0].size + 1 == a[1].size) &&
                               (a[1].size + 1 == a[2].size) &&
                               (a[2].size + 1 == a[3].size) &&
                               (a[3].size + 1 == a[4].size)) {
                        type[1]++;
                    } else if ((a[0].color == a[1].color) &&
                               (a[1].color == a[2].color) &&
                               (a[2].color == a[3].color) &&
                               (a[3].color == a[4].color)) {
                        type[2]++;
                    } else if (((a[0].size == a[1].size) &&
                                (a[1].size == a[2].size) &&
                                (a[2].size == a[3].size)) ||
                               ((a[1].size == a[2].size) &&
                                (a[2].size == a[3].size) &&
                                (a[3].size == a[4].size))) {
                        type[3]++;
                    } else if (((a[0].size == a[1].size) &&
                                (a[1].size == a[2].size) &&
                                (a[3].size == a[4].size)) ||
                               ((a[0].size == a[1].size) &&
                                (a[2].size == a[3].size) &&
                                (a[3].size == a[4].size))) {
                        type[4]++;
                    } else if (c1 == 2 && a[t[0]].size == a[t[0] + 1].size &&
                               a[t[0] + 1].size == a[t[0] + 2].size) {
                        type[6]++;
                    } else if (c1 == 2) {
                        type[5]++;
                    } else if (c1 == 1) {
                        type[7]++;
                    } else {
                        type[8]++;
                    }
                    c++;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            cout << type[i] << " ";
        }
        //cout << c << endl;
    }
}

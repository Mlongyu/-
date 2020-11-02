#include "cstring"
#include "iostream"
using namespace std;
int main() {
    int n, a, b, c, t;
    string s, s1;
    cin >> t;
    while (cin >> n) {
        cin >> a >> b >> c;
        cin >> s;
        s1 = s;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                cnt1++;
            }
            if (s[i] == 'P') {
                cnt2++;
            }
            if (s[i] == 'S') {
                cnt3++;
            }
        }
        int ct = 0;
        ct += (min(b, cnt1) + min(c, cnt2) + min(a, cnt3));
        int yu1 = abs(a - cnt3), yu2 = abs(b - cnt1), yu3 = abs(c - cnt2);
        int sa = a, sb = b, sc = c;
        if (ct * 2 >= n) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'R') {
                    s1[i] = 'P';
                    b--;
                    if (b < 0 && (yu3 > 0 || yu1 > 0)) {
                        if (yu1 > 0 && sa > cnt3) {
                            s1[i] = 'R';
                            yu1--;
                        } else if (yu3 > 0 && sc > cnt2) {
                            s1[i] = 'S';
                            yu3--;
                        }
                    }
                }
                if (s[i] == 'P') {
                    s1[i] = 'S';
                    c--;
                    if (c < 0 && (yu2 > 0 || yu1 > 0)) {
                        if (yu1 > 0 && sa > cnt3) {
                            s1[i] = 'R';
                            yu1--;
                        } else if (yu2 > 0 && sb > cnt1) {
                            s1[i] = 'P';
                            yu2--;
                        }
                    }
                }
                if (s[i] == 'S') {
                    s1[i] = 'R';
                    a--;
                    if (a < 0 && (yu2 > 0 || yu3 > 0)) {
                        if (yu3 > 0 && sc > cnt2) {
                            s1[i] = 'S';
                            yu3--;
                        } else if (yu2 > 0 && sb > cnt1) {
                            s1[i] = 'P';
                            yu2--;
                        }
                    }
                }
            }
            cout << s1 << endl;

        } else {
            cout << "NO" << endl;
        }
    }
}
/*#include <cstring>
#include <iostream>
using namespace std;
char game[200];
int mark[200];
int main() {
    int t, n, a, b, c;
    double num;
    cin >> t;
    while (t--) {
        num = 0;
        memset(mark, 0, sizeof(mark));
        cin >> n;
        cin >> a >> b >> c;
        for (int i = 1; i <= n; i++) {
            cin >> game[i];
        }
        for (int i = 1; i <= n; i++) {
            if (game[i] == 'R' && b > 0) {
                num++;
                b--;
                mark[i] = 1;
            } else if (game[i] == 'P' && c > 0) {
                num++;
                c--;
                mark[i] = 1;
            } else if (game[i] == 'S' && a > 0) {
                num++;
                a--;
                mark[i] = 1;
            }
        }
        if (num * 2 >= n) {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                if (mark[i] == 1 && game[i] == 'R')
                    printf("P");
                else if (mark[i] == 1 && game[i] == 'P')
                    printf("S");
                else if (mark[i] == 1 && game[i] == 'S')
                    printf("R");
                else {
                    if (a > 0) {
                        printf("R");
                        a--;
                    } else if (b > 0) {
                        printf("P");
                        b--;
                    } else if (c > 0) {
                        printf("S");
                        c--;
                    }
                }
            }
            printf("\n");
        } else
            printf("NO\n");
    }
    return 0;
}
*/

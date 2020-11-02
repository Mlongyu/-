/*看错题，正确的应该是点在输入的点之中，这里当成另外求点了*/
#include "algorithm"
#include "cmath"
#include "iostream"
using namespace std;
#define mmm 1e-8
double R;
const int N = 1000010;
struct _point {
    double x, y;
    _point() {}
    _point(double xx, double yy) {
        x = xx;
        y = yy;
    }
} p[N];
_point O;

double len(_point a, _point b) {
    return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}
_point cnt(_point a, _point b) {  //中点
    return _point((a.x + b.x) / 2, (a.y + b.y) / 2.0);
}
_point cnt(_point a, _point b, _point c) {  //求外心
    double x1 = a.x, y1 = a.y;
    double x2 = b.x, y2 = b.y;
    double x3 = c.x, y3 = c.y;

    double a1 = 2 * (x2 - x1);
    double b1 = 2 * (y2 - y1);
    double c1 = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;

    double a2 = 2 * (x3 - x2);
    double b2 = 2 * (y3 - y2);
    double c2 = x3 * x3 + y3 * y3 - x2 * x2 - y2 * y2;

    double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    double y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

    return _point(x, y);
}
int n;
void func() {  //求最小圆
    random_shuffle(p + 1, p + n + 1);
    O = p[1];  //圆心
    R = 0;     //半径
    int i, j, k;
    for (i = 2; i <= n; i++) {
        if (len(O, p[i]) < R + mmm) continue;
        O = p[i];
        R = 0;
        for (j = 1; j < i; j++) {
            if (len(O, p[j]) < R + mmm) continue;
            O = cnt(p[i], p[j]);
            R = len(O, p[i]);
            for (k = 1; k < j; k++) {
                if (len(O, p[k]) < R + mmm) continue;
                O = cnt(p[i], p[j], p[k]);
                R = len(O, p[i]);
            }
        }
    }
    printf("%.2f %.2f\n%.2f\n", O.x, O.y, R*R);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        func();
    }

    return 0;
}
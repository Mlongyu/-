#include <string.h>

#include <iostream>
using namespace std;

int a[10], k, m;
const int N = 10;
const int f[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
struct Matrix {
    int x[N][N];
    Matrix operator*(const Matrix &t) const {
        Matrix M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                M.x[i][j] = 0;
                for (int k = 0; k < N; k++) {
                    M.x[i][j] += x[i][k] * t.x[k][j];
                    M.x[i][j] %= m;
                }
            }
        }
        return M;
    }
    Matrix() { memset(x, 0, sizeof(x)); }
    Matrix(const Matrix &t) { memcpy(x, t.x, sizeof(x)); }
};
Matrix quick_pow(Matrix a, int x) {
    Matrix M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            M.x[i][j] = 0;
        }
    for (int i = 0; i < N; i++) {
        M.x[i][i] = 1;
    }
    while (x) {
        if (x & 1) M = M * a;
        a = a * a;
        x >>= 1;
    }
    return M;
}
int main() {
    while (cin >> k >> m) {
        for (int i = 0; i < 10; i++) {
            cin >> a[i];
        }
        Matrix ma;
        for (int i = 0; i < 10; i++) {
            ma.x[0][i] = a[i];
        }
        for (int i = 1; i < 10; i++) {
            ma.x[i][i - 1] = 1;
        }
        if (k < 10)
            cout << f[k] % m << endl;
        else {
            Matrix ans = quick_pow(ma, k - 9);
            int fk = 0;
            for (int i = 0; i < 10; i++)
                fk += ans.x[0][i] * f[9 - i], fk = fk % m;
            cout << fk << endl;
        }
    }
}

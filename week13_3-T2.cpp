#include "iostream"
#include "cstring"
using namespace std;
int bi(int a, int b) {
    if (a == 0 && b == 2)
        return 1;
    else if (a == 0 && b == 5)
        return 2;
    else if (a == 0 && b == 0)
        return 3;
    else if (a == 2 && b == 5)
        return 1;
    else if (a == 2 && b == 0)
        return 2;
    else if (a == 2 && b == 2)
        return 3;
    else if (a == 5 && b == 0)
        return 1;
    else if (a == 5 && b == 2)
        return 2;
    else if (a == 5 && b == 5)
        return 3;
}
int main() {
    int N, NA, NB;
    int flag;
    while (scanf("%d%d%d", &N, &NA, &NB) != EOF) {
        flag = 0;
        int A[100];
        int B[100];
        int i, j, k;
        for (i = 0; i < NA; i++) scanf("%d", &A[i]);
        for (i = 0; i < NB; i++) scanf("%d", &B[i]);
        for (j = NA; j < 100; j++)  //注意j的取值范围
            A[j] = A[j - NA];
        for (j = NB; j < 100; j++) B[j] = B[j - NB];
        for (j = 0; j < N; j++) {
            if (bi(A[j], B[j]) == 1) flag++;
            if (bi(A[j], B[j]) == 2) flag--;
        }
        if (flag > 0) printf("A\n");
        if (flag < 0) printf("B\n");
        if (flag == 0) printf("draw\n");
    }

    return 0;
}
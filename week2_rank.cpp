#include <iostream>
using namespace std;

struct student {
    char name[15];
    int AC_Count;
    int score;
};

/*https://zh.cppreference.com/w/cpp/algorithm/qsort*/
/*必须是const型参数*/
int cmp(const void *a, const void *b) {
    struct student *aa = (student *)a;
    struct student *bb = (student *)b;
    if (aa->AC_Count != bb->AC_Count)
        return bb->AC_Count - aa->AC_Count;
    else if (aa->score != bb->score)
        return aa->score - bb->score;
    else
        return aa->name - bb->name;
}
int n, m;
student stu[10001];
int main() {
    int  j, t,h,  res, num = 0;
    char str[20];
    scanf("%d%d", &n, &m);
    while (scanf("%s", &stu[num].name) != EOF) {
        stu[num].AC_Count = 0;
        stu[num].score = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            res = sscanf(str, "%d(%d)", &h, &t);
            if (res == 2) {
                stu[num].AC_Count++;
                stu[num].score += h;
                stu[num].score += m * t;
            } else if (res == 1 && h > 0) {
                stu[num].AC_Count++;
                stu[num].score += h;
            }
        }
        num++;
        /*qsort(stu, num, sizeof(stu[0]), cmp);
        for (i = 0; i < num; i++) {
            printf("%-10s %2d %4d\n", stu[i].name, stu[i].AC_Count,
        stu[i].score);
        }*/
    }
    qsort(stu, num, sizeof(stu[0]), cmp);
    for (int i = 0; i < num; i++) {
        printf("%-10s %2d %4d\n", stu[i].name, stu[i].AC_Count, stu[i].score);
    }
    return 0;
}
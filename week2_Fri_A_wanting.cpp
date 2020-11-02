#include "iostream"
using namespace std;
int have3node;
int main() {
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        
        int num[6] = {0};  //存每个节点有几个连接的点
        int numOf1 = 0, numOf2 = 0, numOf3 = 0,
            numOf4 = 0;  //比如numOf3就是有三个相邻点的节点数
        bool g[6][6];    //邻接矩阵
        //初始化图
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 6; k++) g[j][k] = false;
        //连接节点
        for (int u = 0; u < 5; u++) {
            cin >> a >> b;
            g[a - 1][b - 1] = true;
            g[b - 1][a - 1] = true;
        }
        for (int x = 0; x < 6; x++) {
            for (int y = 0; y < 6; y++)
                if (g[x][y]) num[x]++;
            switch (num[x]) {
                case 1:
                    numOf1++;
                    break;
                case 2:
                    numOf2++;
                    break;
                case 3:
                    numOf3++;
                    have3node = x;
                    break;
                case 4:
                    numOf4++;
                    break;
                default:
                    break;
            }
        }
        int count = 0;
        if (numOf3 ==1) {
            for (int m = 0; m < 6; m++) {
                if (g[have3node][m]) {
                    if (num[m] == 2) count++;
                }
            }
        }

        if (numOf4 == 1)
            cout << "2,2-dimethylbutane\n";
        else if (numOf3 == 2)
            cout << "2,3-dimethylbutane\n";
        else if (numOf1 == 2)
            cout << "n-hexane\n";
        else if (count == 2)
            cout << "3-methylpentane\n";
        else
            cout << "2-methylpentane\n";
    }
    system("pause");
    return 0;
}
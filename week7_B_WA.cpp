#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int isBusiness[1001][1001];
int N, S, E, M, X, Y, Z, K;
int cost[1001][1001];
int dis[1001][1001];  //存储源点到各个顶点的最短路径

vector<int> path[1001][1001];
int main() {
    while (cin >> N >> S >> E) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                isBusiness[i][j] = 0;
                isBusiness[j][i] = 0;
                cost[i][j] = 99999;
                cost[j][i] = 99999;
                dis[i][j] = 99999;
                dis[j][i] = 99999;
                path[i][j].clear();
                path[j][i].clear();
            }
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> X >> Y >> Z;
            cost[X - 1][Y - 1] = Z;
            cost[Y - 1][X - 1] = Z;
        }
        for (int i = 0; i < N; i++) {
            cost[i][i]=0;
        }
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> X >> Y >> Z;
            cost[X - 1][Y - 1] = Z;
            cost[Y - 1][X - 1] = Z;
            isBusiness[X - 1][Y - 1] = 1;
            isBusiness[Y - 1][X - 1] = 1;
        }
        /*for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << cost[i][j] << "\t\t";
            }
            cout << endl;
        }*/

        for (int i = 0; i < N; i++)  //初始化
        {
            for (int j = 0; j < N; j++) {
                dis[i][j] = cost[i][j];
                path[i][j].push_back(i + 1);
                path[i][j].push_back(j + 1);
            }
        }
        int k = S - 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // dis[i] = min(dis[i],dis[j] + cost[j][i]);
                //求源点到节点的最短路径，利用现有的L矩阵
                if (dis[k][i] > dis[k][j] + cost[j][i]) {
                    dis[k][i] = dis[k][j] + cost[j][i];

                    path[k][i].clear();  //保存并更新路径
                    path[k][i].insert(path[k][i].end(), path[k][j].begin(),
                                      path[k][j].end());
                    path[k][i].push_back(i + 1);
                }
            }
            for (int m = 0; m < i; m++)  //更新节点最短路径
            {
                for (int j = 0; j < N; j++) {
                    if (dis[k][m] > dis[k][j] + cost[j][m]) {
                        dis[k][m] = dis[k][j] + cost[j][m];
                        path[k][m].clear();  //保存并更新路径
                        path[k][m].insert(path[k][m].end(), path[k][j].begin(),
                                          path[k][j].end());
                        path[k][m].push_back(m + 1);
                    }
                }
            }
        }

        vector<int>::iterator ite;
        int i = E - 1;

        int p[1001], o = 0;
        for (ite = path[S - 1][i].begin(); ite != path[S - 1][i].end(); ++ite) {
            p[o] = *ite;
            o++;
        }
        int bn[1001], ct = 0;
        for (i = 0; i < o - 1; i++) {
            if (isBusiness[p[i] - 1][p[i + 1] - 1]) {
                bn[ct] = p[i];
                ct++;
            }
            cout << p[i] << " ";
        }
        cout << p[i] << endl;
        if (ct == 0) {
            cout << "Ticket Not Used" << endl;
        } else {
            for (i = 0; i < ct - 1; i++) {
                cout << bn[i] << " ";
            }
            cout << bn[i] << endl;
        }

        cout << dis[S - 1][E - 1] << endl << endl;
    }
    // system("pause");
    return 0;
}
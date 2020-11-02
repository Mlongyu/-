#include <iostream>
using namespace std;

string cur, path;

int main() {
    int p;
    cin >> p;
    getchar();
    getline(cin, cur);
    for (int i = 0; i < p; i++) {
        getline(cin, path);
        if (path[0] != '/') path = cur + "/" + path;  //转绝对路径
        int pos;
        int len;
        while ((pos = path.find("//")) != -1)  //处理"//"的情况
        {
            int num = 0;
            while (path[pos + 1 + num] == '/') num++;
            path.erase(pos + 1, num);
        }
        while ((pos = path.find("/./")) != -1)  // deal with "./"
        {
            path.erase(pos + 1, 2);
        }
        while ((pos = path.find("/../")) != -1)  //处理 /../ 的情况
        {
            if (pos == 0)
                path.erase(pos + 1, 3);  //起始位置
            else {
                int p = path.rfind("/", pos - 1);
                path.erase(p + 1, pos + 3 - p);
            }
        }
        len = path.length();  //更新长度
        //最后一个
        if (len != 1 && path[len - 1] == '/') path.erase(len - 1);
        cout << path << endl;
    }
}

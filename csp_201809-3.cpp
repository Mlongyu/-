#include "iostream"
#include "vector"
using namespace std;
const int maxn = 105;

struct node {
    string ele, id;
    vector<int> child;
};

int num[maxn];
node html[maxn], qry[maxn];
int len;
vector<int> ans;

void dfs(int u, int d) {
    bool flag = 0;
    if (qry[d].ele != "") {
        flag = (qry[d].ele == html[u].ele);
    } else if (qry[d].id != "") {
        flag = (qry[d].id == html[u].id);
    }
    if (flag) {
        if (d + 1 < len) {
            d++;
        } else
            ans.push_back(u);
    }
    for (int i = 0; i < html[u].child.size(); i++) {
        int v = html[u].child[i];
        dfs(v, d);
    }
}

int main() {
    int n, m;
    ios::sync_with_stdio(0);
    while (cin >> n >> m) {
        cin.get();
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);
            int d = 0;
            node tmp;
            tmp.ele = "", tmp.id = "";
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '.') {
                    j++;
                    d++;
                } else if (s[j] == ' ')
                    continue;
                else if (s[j] != '#') {
                    num[d] = i;
                    while (j < s.length() && s[j] != ' ') {
                        tmp.ele += tolower(s[j]);
                        j++;
                    }
                } else {
                    while (j < s.length()) {
                        tmp.id += s[j];
                        j++;
                    }
                }
            }
            html[i] = tmp;
            if (d > 0) {
                html[num[d - 1]].child.push_back(i);
            }
        }
        while (m--) {
            string s;
            getline(cin, s);
            len = 0;
            for (int i = 0; i < maxn; i++) qry[i].id = qry[i].ele = "";
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '#') {
                    while (i < s.length() && s[i] != ' ') qry[len].id += s[i++];
                    len++;
                } else if (s[i] == ' ')
                    continue;
                else {
                    while (i < s.length() && s[i] != ' ') {
                        qry[len].ele += tolower(s[i]);
                        i++;
                    }
                    len++;
                }
            }
            ans.clear();
            dfs(0, 0);
            cout << ans.size();
            for (int i = 0; i < ans.size(); i++) {
                cout << " ";
                cout << ans[i] + 1;
            }
            cout << "\n";
        }
    }

    return 0;
}

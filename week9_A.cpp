#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int maxn = 100001;
int tot, n, t;
string _cmd[] = {"MKDIR", "RM", "CD", "SZ", "LS", "TREE", "UNDO"};

struct CMD {
    string name, sstr;
    int type;
    void init(string s) {
        name = s;
        for (int i = 0; i < 7; ++i) {
            if (s == _cmd[i]) {
                type = i;
                if (i < 3) cin >> sstr;
                break;
            }
        }
    }
} cmd;
struct Node {
    string name;
    map<string, int> nexts;
    vector<string> Front, End;
    bool updated;
    int root, sz;

    void init(string s, int rt) {
        updated = false;
        root = rt;
        name = s;
        sz = 1;
        Front.clear();
        End.clear();
        nexts.clear();
    }
} node[maxn];
class Tree {
   protected:
    int now;  //实时位置
    int tot;
    Node root;
    vector<pair<string, pair<int, int> > > undo;
    CMD cmd;

   public:
    void init() {
        node[0].init("root", -1);
        root = node[0];
        undo.clear();
        tot = 0;
        now = 0;
    }
    void add(string s, int rt) {
        node[++tot].init(s, rt);
        node[rt].nexts[s] = tot;
    }
    void update(int id, int num) {
        while (id != -1) {
            node[id].updated = 0;
            node[id].sz += num;
            id = node[id].root;
        }
    }
    void viewFront(int id) {
        node[id].Front.push_back(node[id].name);
        if (node[id].sz == 1) return;
        if (node[id].sz < 11) {
            for (auto i : node[id].nexts) {
                if (!node[i.second].updated) push(i.second);
                node[id].Front.insert(node[id].Front.end(),
                                      node[i.second].Front.begin(),
                                      node[i.second].Front.end());
            }
            return;
        }
        int ct = 1;
        for (auto i : node[id].nexts) {
            if (!node[i.second].updated) push(i.second);
            for (auto j : node[i.second].Front) {
                node[id].Front.push_back(j);
                ++ct;
                if (ct >= 5) break;
            }
            if (ct >= 5) break;
        }
    }
    void viewEnd(int id) {
        int ct = 0;
        auto it = node[id].nexts.end();
        --it;
        for (;; --it) {
            if (!node[it->second].updated) push(it->second);
            int u = it->second;
            for (int i = node[u].End.size() - 1; i >= 0; --i) {
                node[id].End.push_back(node[u].End[i]);
                ++ct;
                if (ct >= 5) {
                    reverse(node[id].End.begin(), node[id].End.end());
                    break;
                }
            }
            if (ct >= 5) break;
            if (it == node[id].nexts.begin()) break;
        }
    }
    void push(int id) {
        node[id].Front.clear();
        node[id].End.clear();
        viewFront(id);
        if (node[id].sz > 10)
            viewEnd(id);
        else
            node[id].End = node[id].Front;
        node[id].updated = true;
    }
    void MKDIR();
    void RM();
    void CD();
    void SZ();
    void LS();
    void TREE();
    void UNDO();
    void solve();
} tree;
void Tree::MKDIR() {
    if (node[now].nexts.count(cmd.sstr)) {
        cout << "ERR" << endl;
        return;
    }
    add(cmd.sstr, now);
    update(now, 1);
    undo.push_back(make_pair("MKDIR", make_pair(now, tot)));
    cout << "OK" << endl;
}
void Tree::RM() {
    if (!node[now].nexts.count(cmd.sstr)) {
        cout << "ERR" << endl;
        return;
    }
    int u = node[now].nexts[cmd.sstr];
    update(now, (-1) * node[u].sz);
    node[now].nexts.erase(node[u].name);
    undo.push_back(make_pair("RM", make_pair(now, u)));
    cout << "OK" << endl;
}
void Tree::CD() {
    if (cmd.sstr == "..") {
        if (node[now].root == -1) {
            cout << "ERR" << endl;
            return;
        }
        undo.push_back(make_pair("CD", make_pair(now, node[now].root)));
        now = node[now].root;
        cout << "OK" << endl;
        return;
    }
    if (!node[now].nexts.count(cmd.sstr)) {
        cout << "ERR" << endl;
        return;
    }
    int u = node[now].nexts[cmd.sstr];
    undo.push_back(make_pair("CD", make_pair(now, u)));
    now = u;
    cout << "OK" << endl;
}
void Tree::SZ() { cout << node[now].sz << endl; }
void Tree::LS() {
    int t = node[now].nexts.size();
    if (t == 0) {
        cout << "EMPTY" << endl;
        return;
    }
    auto pos = node[now].nexts.begin();
    if (t > 0 && t < 11) {
        while (pos != node[now].nexts.end()) {
            cout << pos->first << endl;
            pos++;
        }
        return;
    }
    for (int i = 0; i < 5; ++i) {
        cout << pos->first << endl;
        pos++;
    }
    cout << "..." << endl;
    pos = node[now].nexts.end();
    for (int i = 0; i < 5; ++i) pos--;
    for (int i = 0; i < 5; ++i) {
        cout << pos->first << endl;
        pos++;
    }
}
void Tree::TREE() {
    if (!node[now].updated) push(now);
    if (node[now].sz == 1)
        cout << "EMPTY" << endl;
    else if (node[now].sz > 1 && node[now].sz < 11) {
        for (int i = 0; i < node[now].Front.size(); ++i)
            cout << node[now].Front[i] << endl;
    } else {
        for (int i = 0; i < 5; ++i) cout << node[now].Front[i] << endl;
        cout << "..." << endl;
        for (int i = 5; i > 0; --i)
            cout << node[now].End[node[now].End.size() - i] << endl;
    }
}
void Tree::UNDO() {
    if (!undo.size()) {
        cout << "ERR" << endl;
        return;
    }
    auto e = undo[undo.size() - 1];
    undo.pop_back();
    cout << "OK" << endl;
    int tmp = now;
    if (e.first == "MKDIR") {
        cmd.name = "RM";
        now = e.second.first;
        cmd.sstr = node[e.second.second].name;
        int u = node[now].nexts[cmd.sstr];
        update(now, (-1) * node[u].sz);
        node[now].nexts.erase(node[u].name);
        now = tmp;
    } else if (e.first == "RM") {
        now = e.second.first;
        int u = e.second.second;
        update(now, node[u].sz);
        node[now].nexts[node[u].name] = u;
        now = tmp;
    } else {
        now = e.second.first;
    }
}
void Tree::solve() {
    init();
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cmd.init(s);
        switch (cmd.type) {
            case 0:
                MKDIR();
                break;
            case 1:
                RM();
                break;
            case 2:
                CD();
                break;
            case 3:
                SZ();
                break;
            case 4:
                LS();
                break;
            case 5:
                TREE();
                break;
            case 6:
                UNDO();
                break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> t) {
        for (int i = 0; i < t; ++i) {
            cin >> n;
            tree.solve();
        }
    }

    return 0;
}
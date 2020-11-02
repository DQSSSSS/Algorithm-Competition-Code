#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
const LD eps = 1e-8;
LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

bool isNumber(char s) {
    return s >= '0' && s <= '9';
}

bool isAlpha(char s) {
    return s >= 'a' && s <= 'z';
}

struct haha {

    struct node {
        int l,r;
        int mark;
        vector<int> a;
    }pool[SZ];
    // 0:concat  1:shuffle  2:sorted  3:list

    int tot = 1;

    string read_string() {
        char a = getchar();
        string ans;
        while(isAlpha(a)) ans += a,a = getchar();
      //  cout << a << " " << ans << endl;
        return ans;
    }

    vector<int> read_list() {
        char a = getchar();
        vector<int> ans;
        while(a != ']') {
            int x = 0;
            while(a != ']' && a != ',')
                x = x * 10 + a - '0',a = getchar();
            if(a == ',') a = getchar();
            ans.push_back(x);
        }
        return ans;
    }

    int get_id(string s) {
        if(s == "concat") return 0;
        if(s == "shuffle") return 1;
        if(s == "sorted") return 2;
    }

    void dfs(int u) {
        string s = read_string();
       // cout << " !!! " << s << endl;
        if(s.size() == 0) { // ...,...,...]
            pool[u].a = read_list();
            pool[u].mark = 3;
        }
        else { //
            pool[u].mark = get_id(s);
            if(pool[u].mark) { // ...)
                dfs(pool[u].l = ++ tot);
                getchar(); //)
            }
            else { // ...,...)
                dfs(pool[u].l = ++ tot);
                getchar(); //,
                dfs(pool[u].r = ++ tot);
                getchar(); //)
            }
        }
    }

    void dfs_list(int u, vector<int> &a) {
        if(!u) return;
        for(int x : pool[u].a) a.push_back(x);
        dfs_list(pool[u].l,a);
        dfs_list(pool[u].r,a);
    }

    vector<pii> num;

    void dfs_work(int u) {
        if(!u) return;
        if(pool[u].mark == 3) {
            for(int x : pool[u].a) num.push_back({x,0});
        }
        else if(pool[u].mark) {
            dfs_list(u,pool[u].a);
            if(pool[u].mark == 2) { // sorted
                sort(pool[u].a.begin(),pool[u].a.end());
            }
            bool isAllEqu = true,first = true;
            int val = -1;
            for(int x : pool[u].a) {
                if(first == true) {
                    val = x; first = false;
                }
                else {
                    if(val != x) isAllEqu = false;
                }
            }
            for(int x : pool[u].a) {
                if(pool[u].mark == 1 && !isAllEqu) {
                    num.push_back({x,u});
                }
                else {
                    num.push_back({x,0});
                }
            }
        }
        else {
            dfs_work(pool[u].l);
            dfs_work(pool[u].r);
        }
    }

    void work() {
        dfs_work(1);
       // for(int i = 0,j = 0;i < num.size();i ++) printf("%d ",num[i].first); puts("");
       // for(int i = 0,j = 0;i < num.size();i ++) printf("%d ",num[i].second); puts("");
        int cnt = 1;
        for(int i = 0,j = 0;i < num.size();i ++) {
            if(i + 1 == num.size() || num[i].second != num[i+1].second) {
                if(num[i].second == 0) {
                    j = i + 1;
                }
                else {
                    sort(num.begin()+j,num.begin()+i+1);
                    for(int k = j;k <= i;k ++) num[k].second = cnt;
                    cnt ++;
                    j = i + 1;
                }
            }
        }
    }

    void dfs_print(int u) {
        if(!u) return ;
        printf("%d %d %d  ",pool[u].l,pool[u].r,pool[u].mark);
        for(int x : pool[u].a) printf("%d ",x);
        puts("");
        dfs_print(pool[u].l);
        dfs_print(pool[u].r);
    }
}a,b;


int main() {
    a.dfs(1);
    getchar();
  //  a.dfs_print(1);
    b.dfs(1);
   // b.dfs_print(1);
    a.work(); b.work();
    if(a.num == b.num) puts("equal");
    else puts("not equal");
}

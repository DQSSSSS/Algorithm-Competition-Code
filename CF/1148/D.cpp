#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct haha {
    int x,y,id;
};

vector<haha> f,g;

bool cmp(haha a,haha b) { return a.y > b.y; }

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        int x = read(),y = read();
        if(x < y) f.push_back((haha){x,y,i});
        if(x > y) g.push_back((haha){-x,-y,i});
    }
    sort(f.begin(),f.end(),cmp);
    sort(g.begin(),g.end(),cmp);
    if(f.size() < g.size()) swap(f,g);
    printf("%d\n",f.size());
    for(int i = 0;i < f.size();i ++)
        printf("%d ",f[i].id);
}

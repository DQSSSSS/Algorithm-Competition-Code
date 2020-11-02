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
    int x,y,d;
};

vector<haha> g;

pii a[SZ];
int b[SZ];

int main() {
    int n = read();
    LL sum = 0;
    for(int i = 1;i <= n;i ++) a[i] = make_pair(read(),i),sum += a[i].first;
    for(int i = 1;i <= n;i ++) b[i] = read(),sum -= b[i];
    if(sum) puts("NO");
    else {
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        set<int> S;
        vector<int> G;
        for(int i = 1;i <= n;i ++) {
            if(a[i].first < b[i]) G.push_back(i);
            if(a[i].first > b[i]) S.insert(i);
        }
        for(int i = 0;i < G.size();i ++) {
            while(1) {
                int id1 = G[i];
                if(a[id1].first == b[id1]) break;
                auto it = S.lower_bound(id1);
                if(it == S.end()) return puts("NO"),0;
                int id2 = *it;
                int d = min(b[id1] - a[id1].first,a[id2].first - b[id2]);
                g.push_back((haha){a[id1].second,a[id2].second,d});
                a[id1].first += d;
                a[id2].first -= d;
                if(a[id2].first == b[id2]) S.erase(id2);
            }
        }

        puts("YES");
        printf("%d\n",g.size());
        for(haha a : g) {
            printf("%d %d %d\n",a.x,a.y,a.d);
        }
    }
}

/**
5
3 3 3 1 5
1 5 2 4 3
*/

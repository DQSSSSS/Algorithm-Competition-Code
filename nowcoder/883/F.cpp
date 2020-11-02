#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e6 + 3;
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

int a[510][510];
int mn[510],mx[510];

struct dq {
    int l,r;
    int num[510];
    dq() { l = 1, r = 0; }
    void push_back(int x) { num[++ r] = x; }
    void pop_back() { r --; }
    void pop_front() { l ++; }
    int size() { return r-l+1; }
    bool empty() { return r-l+1 == 0; }
    int front() { return num[l]; }
    int back() { return num[r]; }
}qx,qn;


int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                a[i][j] = read();
            }
        }
        int ans = 0;
        for(int R = 1;R <= n;R ++) {
            for(int i = 1;i <= n;i ++) mn[i] = INF,mx[i] = -INF;
            for(int L = R;L >= 1;L --) {
                for(int i = 1;i <= n;i ++) mn[i] = min(mn[i],a[L][i]),mx[i] = max(mx[i],a[L][i]);
              //  printf("%d %d : \n",L,R);
              //  for(int i = 1;i <= n;i ++) printf("%d ",mx[i]); puts("");
              //  for(int i = 1;i <= n;i ++) printf("%d ",mn[i]); puts("");
                qx = dq();
                qn = dq();
                int l = 1,r = 0;
                while(r <= n) {
                    while(r <= n &&
                          (qx.empty() || qn.empty()
                           || mx[qx.front()] - mn[qn.front()] <= m)) {
                        r++;
                        if(r>n) break;
                        while(qx.size() && mx[qx.back()] <= mx[r]) qx.pop_back();
                        while(qn.size() && mn[qn.back()] >= mn[r]) qn.pop_back();
                        qx.push_back(r);
                        qn.push_back(r);
                       // if(qx.size() && qn.size())
                        //    printf("%d %d %d %d\n",r,mx[qx.front()],mn[qn.front()],m);
                    }
                   // cout << qx.size() << " " << qn.size() << endl;
                   // printf("%d %d %d %d\n",L,R,l,r-1);
                    ans = max(ans,(r-l)*(R-L+1));
                    if(qx.front() == l) qx.pop_front();
                    if(qn.front() == l) qn.pop_front();
                    l ++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
/**
2
2 100
1 2
2 1
3 1
1 3 2
2 3 1
3 2 1
*/

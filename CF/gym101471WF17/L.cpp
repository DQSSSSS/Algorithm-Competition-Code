#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

struct haha {
    int x,y,type,id;
}a[SZ];

bool cmp(haha a,haha b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool cmp2(haha a,haha b) { return a.id < b.id; }
set<int> s;
map<int,int> mp,mmp;
int dy[SZ],Ans[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i].x = read(),a[i].y = read(),a[i].type = 0,a[i].id = i;
    for(int i = n+1;i <= 2*n;i ++) a[i].x = read(),a[i].y = read(),a[i].type = 1,a[i].id = i;
    sort(a+1,a+1+2*n,cmp);
    for(int i = 1;i <= 2 * n;i ++) {
        if(a[i].type == 0) {
            auto it = s.lower_bound(a[i].y);
            if(it != s.end() && *it == a[i].y) return puts("syntax error"),0;
            mp[a[i].y] = i;
            mmp[a[i].y] = a[i].id;
            s.insert(a[i].y);
        }
        else {
            if(!s.size() || *s.begin() > a[i].y) return puts("syntax error"),0;
            auto it = s.lower_bound(a[i].y);
            if(it == s.end() || *it > a[i].y) it --;
            dy[mp[*it]] = i;
            Ans[mmp[*it]] = a[i].id-n;
            s.erase(it);
        }
    }
    mp.clear();
    for(int i = 1;i <= 2 * n;i ++) {
        if(a[i].type == 0) {
            mp[a[i].y] = i;
            s.insert(a[i].y);
        }
        else {
            auto it = s.lower_bound(a[i].y);
            if(it == s.end() || *it > a[i].y) it --;
            if(it != s.begin()) {
                int x = a[mp[*it]].x,y = *it;
                auto itt = it;
                it --;
                int xx = a[mp[*it]].x,yy = *it;
                if(xx < x) {
                    if(a[dy[mp[*it]]].x == a[i].x) return puts("syntax error"),0;
                    if(y <= a[dy[mp[*it]]].y && a[dy[mp[*it]]].y <= a[i].y) return puts("syntax error"),0;
                }
                else {
                    if(y <= a[dy[mp[*it]]].y) return puts("syntax error"),0;
                }
                s.erase(itt);
            }
            else s.erase(it);
        }
    }
//    for(int i = 1;i <= 2*n;i ++) if(a[i].type == 0) dy[a[i].id] = a[dy[a[i].id]].id-n;
    sort(a + 1, a + 1 + 2*n, cmp2);
    for(int i = 1;i <= n;i ++) printf("%d\n",Ans[i]);
    return 0;
}
/**
2
1 3
4 1
6 3
10 13
*/

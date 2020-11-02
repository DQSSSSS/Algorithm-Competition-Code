#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e6 + 10;
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
    int p,h,id;
}a[SZ],b[SZ];

bool operator <(haha a,haha b) {
    return a.p == b.p ? a.h < b.h : a.p < b.p;
}

int n,eda[SZ],edb[SZ],pa[SZ],pb[SZ];
set<pii> sa,sb;

bool check() {

    for(int i = 1,j = 1;i <= n;i ++) {
        if(i == n || a[i+1].p != a[i].p) {
            for(int k = j;k <= i;k ++) eda[k] = i;
            j = i + 1;
        }
    }
    for(int i = 1,j = 1;i <= n;i ++) {
        if(i == n || b[i+1].p != b[i].p) {
            for(int k = j;k <= i;k ++) edb[k] = i;
            j = i + 1;
        }
    }
/*
    for(int i = 1;i <= n;i ++) cout << a[i].id << " " << a[i].h << endl;
    puts("");
    puts("");
    for(int i = 1;i <= n;i ++) cout << b[i].id << " " << b[i].h << endl; puts("");
    for(int i = 1;i <= n;i ++) cout << eda[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) cout << edb[i] << " "; puts("");
*/
    for(int i = 1,j = 1,ii = i,jj = j;i <= n && j <= n;i ++,j ++) {
        while(ii <= eda[i]) sa.insert(make_pair(a[ii].h,ii)),ii ++;
        while(jj <= edb[j]) sb.insert(make_pair(-b[jj].h,jj)),jj ++;
        if(eda[i] <= edb[i]) {
            int id = sa.begin() -> second;
            auto it = sb.lower_bound(make_pair(-a[id].h+1,0));
            if(it == sb.end()) return false;
            //cout << id << " " << a[id].id << " " << b[it->second].id << endl;
            pa[i] = a[id].id;
            pb[i] = b[it->second].id;
            sb.erase(it);
            sa.erase(sa.begin());
        }
        else {
            int id = sb.begin() -> second;
            auto it = sa.lower_bound(make_pair(b[id].h+1,0));
            if(it == sa.end()) return false;
            //cout << i << " " << a[it->second].id << " " << b[i].id << endl;
            pa[i] = a[it->second].id;
            pb[i] = b[id].id;
            sa.erase(it);
            sb.erase(sb.begin());
        }
    }
    return true;
}

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) a[i].p = read();
    for(int i = 1;i <= n;i ++) a[i].h = read();
    for(int i = 1;i <= n;i ++) b[i].p = read();
    for(int i = 1;i <= n;i ++) b[i].h = read();
    for(int i = 1;i <= n;i ++) a[i].id = i;
    for(int i = 1;i <= n;i ++) b[i].id = i;
    sort(b + 1,b + 1 + n);
    sort(a + 1,a + 1 + n);
    if(!check()) return puts("impossible"),0;
    for(int i = 1;i <= n;i ++) printf("%d ",pa[i]); puts("");
    for(int i = 1;i <= n;i ++) printf("%d ",pb[i]); puts("");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

pii small[SZ],large[SZ];

int lb(pii a[],int l,int r,int val,bool f) {
    r ++;
    while(r-l>1) {
        int mid = l + r >> 1;
        if(f) {
            if(a[mid].first < val) l = mid;
            else r = mid;
        }
        else {
            if(a[mid].first < val) r = mid;
            else l = mid;
        }
    }
    return a[l].second + 1;
}

int L[SZ],R[SZ],del[SZ],a[SZ],n;
vector<int> lst[SZ];
vector<int> ans;

bool work() {
    ans.clear();
    set<pii> sr;
    set<int> sv;
    for(int i = 1;i <= 2*n;i ++) {
        for(int v : lst[i]) sv.insert(v),sr.insert(make_pair(R[v],v));
        if(sv.empty()) return false;
        while(del[sr.begin() -> second]) sr.erase(sr.begin());
        int x;
        if(sr.begin() -> first == i) {
            x = sr.begin() -> second;
            sr.erase(sr.begin());
            sv.erase(x);
        }
        else {
            int x = *sv.begin();
            sv.erase(x);
        }
        del[x] = 1;
        ans.push_back(x);
    }

    bool flag = 0;
    set<int> s;
    for(int i = 1;i <= n;i ++) s.insert(ans[i-1]);
    for(int i = 1;i <= n;i ++) {
        if(a[i]<0) {
            int x = *s.begin(); s.erase(s.begin());
            if(x != -a[i]) return false;
        }
        else {
            int x = *prev(s.end()); s.erase(x);
            if(x != a[i]) return false;
        }
        s.insert(ans[i+n-1]);
    }
    return true;
}

int main() {
     //freopen("1.in","r",stdin); freopen("my.out","w",stdout);
     int T = read();
     while(T --) {
        n = read();

        int l1 = 0,l2 = 0;

        small[++ l1] = make_pair(INF,0);
        large[++ l2] = make_pair(0,0);
        for(int i = 1;i <= 2*n;i ++) R[i] = 2*n,lst[i].clear(),del[i] = 0;
        for(int i = 1;i <= n;i ++) {
            int x = read(),v = abs(x);
            a[i] = x;
            R[v] = i+n-1;
            if(x<0) {
                while(l1 && small[l1].first < v) l1 --;
                L[v] = small[l1].second + 1;
                small[++ l1] = make_pair(v,i+n-1);
            }
            else {
                while(l2 && large[l2].first > v) l2 --;
                L[v] = large[l2].second + 1;
                large[++ l2] = make_pair(v,i+n-1);
            }
        }

        for(int i = 1;i <= 2*n;i ++) {
            if(R[i] == 2*n) {
                int r1 = lb(small,1,l1,i,0);
                int r2 = lb(large,1,l2,i,1);
                L[i] = max(r1,r2);
            }
        }

        //for(int i = 1;i <= 2*n;i ++) printf("%d: %d %d\n",i,L[i],R[i]);
        //cout << T << endl;
        for(int i = 1;i <= 2*n;i ++) lst[L[i]].push_back(i);

        if(!work()) { puts("-1"); continue; }
        for(int i = 0;i < ans.size();i ++) {
            printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
        }
     }
}

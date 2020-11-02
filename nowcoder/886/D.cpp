#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

int n,k,a[SZ],mind,val[SZ];

map<int,vector<vector<int>>> mp;

int check(int mid) {
    mind = INF;
    multiset<int> s;
    for(int i = 1;i <= n;i ++) s.insert(a[i]);
    int t = 1,now = 0;
    //puts("");
    vector<vector<int>> ans;
    vector<int> tmp;
    while(s.size()) {
        auto it = s.upper_bound(mid-now);
        if(it == s.begin()) {
            t ++,now = 0;
            ans.push_back(tmp);
            tmp.clear();
      //      puts("");
        }
        else {
            it --;
            now += *it;
            tmp.push_back(*it);
        //    printf("%d ",*it);
            s.erase(it);
        }
        if(t>n) return INF;
    }
    if(tmp.size()) ans.push_back(tmp);
    if(!mp.count(ans.size())) mp[ans.size()] = ans,val[ans.size()]=mid;
    return t;
}

int erfen() {
    int l = -1,r = 1e6+1;
    while(r-l>1) {
        int mid = l + r >>1;
        if(check(mid) <= k) r = mid;
        else l = mid;
    }
    return r;
}

mt19937 rd(time(0));

int randlr(int l,int r) {
    return rd()%(r-l+1)+l;
}

int main() {
    int T = read(),cc = 0;
    while(T ++) {
        n = read(),k = read();  for(int i = 1;i <= n;i ++) a[i] = read();
        //n = randlr(1,20),k = randlr(1,20); for(int i = 1;i <= n;i ++) a[i] = randlr(1,50);
      //  n = 100,k = 100; for(int i = 1;i <= n;i ++) a[i] = randlr(1,1000);
        sort(a+1,a+1+n);
        int l = a[n],r = 0;
        for(int i = n;i >= 1;i --) {
            r += a[i];
        }
        int ans;
        //check(85);
       // check(86);
        //for(int i = l;i <= r;i ++) printf("%d %d\n",i,check(i));
        mp.clear();
        for(int i = l;i <= r;i ++) {
           /* if(check(i)) {
                printf("%d %d\n",n,k);
                for(int j = 1;j <= n;j ++) printf("%d ",a[j]); puts("");
                return 0;
            }*/
            check(i);
        }
        for(auto x : mp) {
            printf("%d %d\n",x.second.size(),val[x.second.size()]);
            for(auto u : x.second) {
                int sum = 0;
                for(int i : u) {
                    printf("%d ",i);
                    sum += i;
                }
                printf("\tsum: %d\n",sum);
            }
        puts("");
        }
        /*int ef = erfen();
//        printf("Case #%d: %d\n",++ cc,ans);
        if(ans != ef) {
            printf("%d %d\n",n,k);
            for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
            return 0;
        }*/
    }
}
/**
49 72
5 7 15 16 19 24 25 27 30 31 42 47 49 50 50 52 55 58 58 59 60 61 64 65 66 66 66 66 67 71 82 82 82 83 84 84 85 88 88 88 89 92 95 95 97 97 98 98 100

1
20 10
7 7 14 17 18 19 21 21 24 28 30 34 35 41 43 43 43 44 44 49

7 14 17 18 19 21 21 24 28
49 35
44 44
43 43
43 41
34 30 7
28 24


 7  7 14 17 18 19 21 21 24 28 30 34 35 41 43 43 43 44 44 49
 4  3  5  7  6  7  7  7  6  5  4  3  1  2  6  5  4  3  2  1

49 35
44 41
44 34 7
43 30 7
43 28 14
43 24 18
21 21 19 17

49 35
44 41
44 34 7
43 43
43 30 7
28 24 21
21 19 18 17
14
*/

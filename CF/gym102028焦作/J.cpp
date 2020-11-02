#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL s1[1510][1510],s2[1510][1510];
pii thispair[1510][1510];
int n,m,s[SZ],sum[1510][1510];

struct hhh {
    int x1,y1,x2,y2;
}a[SZ];

map<pii,int> mp,place;

struct haha {
    pii p; int d;
};

bool cmp(haha a,haha b) {
    return a.p < b.p;
}

vector<haha> two;
set<pii> Set;

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        two.clear();
        mp.clear();
        Set.clear();
        place.clear();
        for(int i = 0;i <= m+1;i ++)
            for(int j = 0;j <= m+1;j ++) {
                sum[i][j] = 0;
                s1[i][j] = 0;
                s2[i][j] = 0;
                thispair[i][j] = make_pair(0,0);
            }

        for(int i = 1;i <= n;i ++) s[i] = 0;

        for(int i = 1;i <= n;i ++) {
            a[i].x1 = read(); a[i].x2 = read();
            a[i].y1 = read(); a[i].y2 = read();
            sum[a[i].x1][a[i].y1] ++;
            sum[a[i].x1][a[i].y2+1] --;
            sum[a[i].x2+1][a[i].y1] --;
            sum[a[i].x2+1][a[i].y2+1] ++;

            LL x = i;
            s1[a[i].x1][a[i].y1] += x;
            s1[a[i].x1][a[i].y2+1] -= x;
            s1[a[i].x2+1][a[i].y1] -= x;
            s1[a[i].x2+1][a[i].y2+1] += x;
            s2[a[i].x1][a[i].y1] += x*x;
            s2[a[i].x1][a[i].y2+1] -= x*x;
            s2[a[i].x2+1][a[i].y1] -= x*x;
            s2[a[i].x2+1][a[i].y2+1] += x*x;
        }
        int sum0 = 0;
        for(int i = 1;i <= m;i ++)
            for(int j = 1;j <= m;j ++)
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1],
                s1[i][j] += s1[i-1][j] + s1[i][j-1] - s1[i-1][j-1],
                s2[i][j] += s2[i-1][j] + s2[i][j-1] - s2[i-1][j-1];
        for(int i = 1;i <= m;i ++)
            for(int j = 1;j <= m;j ++) {
                if(sum[i][j] == 2) {
                    LL a = s1[i][j],b = s2[i][j];
                    int x = (a + sqrt(2*b-a*a)) / 2;
                    int y = a - x;
                    if(x<y) swap(x,y);
                    //cout << i << " " << j << " " << x << " " << y << endl;
                    pii p = make_pair(x,y);
                    thispair[i][j] = p;
                    mp[p] ++;
                }
                if(sum[i][j] == 1) {
                    int x = s1[i][j];
                    s[x] ++;
                }
                if(sum[i][j]) sum0 ++;
            }
        for(int i = 1;i <= m;i ++)
            for(int j = 1;j <= m;j ++) {
                if(sum[i][j] == 2) {
                    if(place[thispair[i][j]]) continue;
                    place[thispair[i][j]] = 1;
                    two.push_back((haha){thispair[i][j],mp[thispair[i][j]]});
                }
            }
        sort(two.begin(),two.end(),cmp);
        int ans = 0;
        for(int i = 1,j = 0;i <= n;i ++) {
         //   cout << i << endl;
            int k = j;
            while(k < two.size() && two[k].p.first == i) {
                int x = two[k].p.second;
                auto it = Set.find(make_pair(-s[x],x));
                Set.erase(it);
              //  printf("%d %d->%d\n",x,s[x],s[x]+two[k].d);
                Set.insert(make_pair(-(s[x]+two[k].d),x));
                k ++;
            }
            if(Set.size()) {
                auto it = Set.begin();
                ans = max(ans,s[i] - it -> first);
            }
            k = j;
            while(k < two.size() && two[k].p.first == i) {
                int x = two[k].p.second;
                auto it = Set.find(make_pair(-(s[x]+two[k].d),x));
                Set.erase(it);
                Set.insert(make_pair(-s[x],x));
                k ++;
            }
            Set.insert(make_pair(-s[i],i));
            j = k;
        }
        printf("%d\n",sum0 - ans);
    }
    return 0;
}
/**
233
4 4
1 2 1 2
2 3 2 3
2 3 3 4
1 2 4 4
*/

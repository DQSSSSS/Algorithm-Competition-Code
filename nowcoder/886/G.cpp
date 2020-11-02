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

char a[SZ][13],ok[222][13];
vector<int> dy[222];
int tong[SZ],b[222];

int mp[SZ];

const int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool pd(int y) {
    return (0 == y % 4 &&  y % 100!=0) || (0==y % 400);
}
struct haha {
    int y,m,d;
    void add() {
        d ++;
        if(m == 2) {
            if(pd(y)) {
                if(d == 30) d = 1,m ++;
            }
            else {
                if(d == 29) d = 1,m ++;
            }
        }
        else {
            if(d == month[m] + 1) d = 1,m ++;
        }
        if(m == 13) m = 1,y ++;
    }
    void print() { printf("%04d/%02d/%02d\n",y,m,d); }
    int msk() {
        return y*10000+m*100+d;
    }
};

void pre() {
    haha s = (haha){1600,1,7};
    while(s.y < 10000) {
        mp[++ mp[0]] = s.msk();
       // if(s.y == 2019) s.print();
        for(int i = 0;i < 7;i ++) s.add();
    }
    sort(mp+1,mp+1+mp[0]);
}

haha get(char a[]) {
    int yy = 0,mm = 0,dd = 0;
    for(int i = 0;i < 4;i ++) yy = yy * 10 + b[a[i]];
    for(int i = 5;i < 7;i ++) mm = mm * 10 + b[a[i]];
    for(int i = 8;i < 10;i ++) dd = dd * 10 + b[a[i]];
    return (haha){yy,mm,dd};
}

bool check(char a[]) {
    int k = get(a).msk();
//    for(int i = 'A';i <= 'J';i ++) printf("%d",b[i]);printf(" "); get(a).print();
    if(*lower_bound(mp+1,mp+1+mp[0],k) == k) return true;
    return false;
}

bool use[111];

bool dfs(int d) {
    if(d == 'J' + 1) return true;
    vector<int> lst;
    for(int id : dy[d]) if(-- tong[id] == 0) lst.push_back(id);
    for(int i = 0;i < 10;i ++) {
        if(ok[d][i] && !use[i]) {
            b[d] = i;
            bool flag = 0;
            for(int id : lst) {
                if(!check(a[id])) {
                    flag = 1; break;
                }
            }
            if(flag) continue;
            use[i] = 1;
            if(dfs(d+1)) return true;
            use[i] = 0;
        }
    }
    for(int id : dy[d]) tong[id] ++;
    return false;
}

string ss[SZ];

int main() {
    pre();
    int T = read(),cc = 0;
    while(T --) {
        int n = read();
        for(int i = 0;i <= 9;i ++) use[i] = 0;
        for(int i = 'A';i <= 'J';i ++) {
            for(int j = 0;j < 10;j ++)
                ok[i][j] = 1;
            dy[i].clear();
        }
        for(int i = 1;i <= n;i ++) {
            char s[13];
            scanf("%s",s);
            ss[i] = s;
        }
        sort(ss+1,ss+1+n); n = unique(ss+1,ss+1+n) - ss - 1;
        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j < 10;j ++) a[i][j] = ss[i][j];
        }
        for(int i = 1;i <= n;i ++) {
            ok[a[i][0]][0] = 0;
            for(int j = 2;j < 10;j ++) ok[a[i][5]][j] = 0;
            for(int j = 4;j < 10;j ++) ok[a[i][8]][j] = 0;
            for(int j = 0;j < 10;j ++) {
                dy[a[i][j]].push_back(i);
            }
            tong[i] = 8;
        }
        printf("Case #%d: ",++ cc);
        if(dfs('A')) {
            for(int i = 'A';i <= 'J';i ++) printf("%d",b[i]); puts("");
          /*  for(int i = 1;i <= n;i ++) {
                get(a[i]).print();
            }*/
        }
        else {
            puts("Impossible");
        }
    }
}
/***
1
CABJ/AI/AC
5
CABJ/AI/AC
CABJ/AI/AD
CABJ/AI/AE
CABJ/AI/AF
CABJ/AI/AG
*/

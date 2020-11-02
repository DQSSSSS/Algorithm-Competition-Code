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

bool zhuang(pii x,pii y) {
    return x.first == y.first ||x.second == y.second || x.first - x.second == y.first - y.second || x.first + x.second == y.first + y.second;
}

int n,m;
vector<pii> ans;

void get2n(int cur,int d) {
    if(ans.size() == 0) {
        int y1 = 3,y2 = 1;
        for(int i = 1;i <= 2*m;i ++) {
            if(i&1) ans.push_back(make_pair(1+d,y1)),y1++;
            else ans.push_back(make_pair(2+d,y2)),y2++;
            if(y1>m) y1=1;
        }
        return ;
    }
    int y1 = -1,y2 = -1;
    pii p = ans[ans.size()-1];
    for(int i = 3;i <= m;i ++) {
        if(!zhuang(p,make_pair(1+d,i))) {
            y1 = i; y2 = 1; break;
        }
    }
    if(y1 == -1) {
        for(int i = 3;i <= m;i ++) {
            if(!zhuang(p,make_pair(2+d,i))) {
                y1 = i; y2 = 1; break;
            }
        }
        for(int i = 1;i <= 2*m;i ++) {
            if(i&1) ans.push_back(make_pair(2+d,y1)),y1++;
            else ans.push_back(make_pair(1+d,y2)),y2++;
            if(y1>m) y1=1;
        }
    }
    else {
        for(int i = 1;i <= 2*m;i ++) {
            if(i&1) ans.push_back(make_pair(1+d,y1)),y1++;
            else ans.push_back(make_pair(2+d,y2)),y2++;
            if(y1>m) y1=1;
        }
    }
}

void get34(int dx,int dy) {
    ans.push_back(make_pair(1+dx,1+dy));
    ans.push_back(make_pair(2+dx,3+dy));
    ans.push_back(make_pair(3+dx,1+dy));
    ans.push_back(make_pair(1+dx,2+dy));
    ans.push_back(make_pair(2+dx,4+dy));
    ans.push_back(make_pair(3+dx,2+dy));
    ans.push_back(make_pair(1+dx,3+dy));
    ans.push_back(make_pair(2+dx,1+dy));
    ans.push_back(make_pair(3+dx,3+dy));
    ans.push_back(make_pair(1+dx,4+dy));
    ans.push_back(make_pair(2+dx,2+dy));
    ans.push_back(make_pair(3+dx,4+dy));
}

void get35(int dx,int dy) {
    ans.push_back(make_pair(1+dx,1+dy));
    ans.push_back(make_pair(2+dx,3+dy));
    ans.push_back(make_pair(1+dx,5+dy));
    ans.push_back(make_pair(2+dx,1+dy));
    ans.push_back(make_pair(1+dx,3+dy));
    ans.push_back(make_pair(2+dx,5+dy));
    ans.push_back(make_pair(3+dx,2+dy));
    ans.push_back(make_pair(2+dx,4+dy));
    ans.push_back(make_pair(3+dx,1+dy));
    ans.push_back(make_pair(1+dx,2+dy));
    ans.push_back(make_pair(3+dx,3+dy));
    ans.push_back(make_pair(1+dx,4+dy));
    ans.push_back(make_pair(3+dx,5+dy));
    ans.push_back(make_pair(2+dx,2+dy));
    ans.push_back(make_pair(3+dx,4+dy));
}

void get36(int dx,int dy) {
ans.push_back(make_pair(1+dx,1+dy));
ans.push_back(make_pair(2+dx,3+dy));
ans.push_back(make_pair(1+dx,5+dy));
ans.push_back(make_pair(2+dx,1+dy));
ans.push_back(make_pair(1+dx,3+dy));
ans.push_back(make_pair(2+dx,5+dy));
ans.push_back(make_pair(1+dx,2+dy));
ans.push_back(make_pair(3+dx,1+dy));
ans.push_back(make_pair(1+dx,4+dy));
ans.push_back(make_pair(3+dx,3+dy));
ans.push_back(make_pair(1+dx,6+dy));
ans.push_back(make_pair(3+dx,5+dy));
ans.push_back(make_pair(2+dx,2+dy));
ans.push_back(make_pair(3+dx,4+dy));
ans.push_back(make_pair(2+dx,6+dy));
ans.push_back(make_pair(3+dx,2+dy));
ans.push_back(make_pair(2+dx,4+dy));
ans.push_back(make_pair(3+dx,6+dy));
}

void get37(int dx,int dy) {
ans.push_back(make_pair(1+dx,1+dy));
ans.push_back(make_pair(2+dx,3+dy));
ans.push_back(make_pair(1+dx,5+dy));
ans.push_back(make_pair(2+dx,1+dy));
ans.push_back(make_pair(1+dx,3+dy));
ans.push_back(make_pair(2+dx,5+dy));
ans.push_back(make_pair(1+dx,2+dy));
ans.push_back(make_pair(2+dx,4+dy));
ans.push_back(make_pair(3+dx,1+dy));
ans.push_back(make_pair(1+dx,4+dy));
ans.push_back(make_pair(3+dx,3+dy));
ans.push_back(make_pair(1+dx,6+dy));
ans.push_back(make_pair(3+dx,5+dy));
ans.push_back(make_pair(2+dx,7+dy));
ans.push_back(make_pair(3+dx,2+dy));
ans.push_back(make_pair(2+dx,6+dy));
ans.push_back(make_pair(3+dx,4+dy));
ans.push_back(make_pair(1+dx,7+dy));
ans.push_back(make_pair(3+dx,6+dy));
ans.push_back(make_pair(2+dx,2+dy));
ans.push_back(make_pair(3+dx,7+dy));
}

void get44(int dx,int dy) {
ans.push_back(make_pair(1+dx,1+dy));
ans.push_back(make_pair(2+dx,3+dy));
ans.push_back(make_pair(3+dx,1+dy));
ans.push_back(make_pair(1+dx,2+dy));
ans.push_back(make_pair(2+dx,4+dy));
ans.push_back(make_pair(3+dx,2+dy));
ans.push_back(make_pair(1+dx,3+dy));
ans.push_back(make_pair(3+dx,4+dy));
ans.push_back(make_pair(4+dx,2+dy));
ans.push_back(make_pair(1+dx,4+dy));
ans.push_back(make_pair(4+dx,3+dy));
ans.push_back(make_pair(2+dx,2+dy));
ans.push_back(make_pair(4+dx,1+dy));
ans.push_back(make_pair(3+dx,3+dy));
ans.push_back(make_pair(2+dx,1+dy));
ans.push_back(make_pair(4+dx,4+dy));
}

void check() {
    bool use[33][33];
    memset(use,0,sizeof use);
    if(ans.size() != n*m) {
        while(1);
    }
    for(pii p : ans) {
        use[p.first][p.second] = 1;
    }
    for(int i = 0;i + 1 < ans.size();i ++) {
        pii x = ans[i],y = ans[i+1];
        if(zhuang(x,y)) {
            cout << i << endl;
            while(1);
        }
    }
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++) {
            if(!use[i][j]) {
                while(1);
            }
        }
    puts("YES");
}

int main() {
    int T = read(),cc = 0;
    int nn = 1,mm = 1;
    while(T --) {
        n = read(),m = read();
       // n = nn,m = mm;
        //mm ++;
        //if(mm == 21) nn ++,mm = 1;
        //cout << n << " " << m << endl;
        printf("Case #%d: ",++ cc);
        if(n == 1 && m == 1) {
            puts("POSSIBLE\n1 1");
            continue;
        }
        bool flag = 0;
        if(n > m) swap(n,m),flag = 1;
        if(n == 1) { puts("IMPOSSIBLE"); continue; }
        if(n == 2 && m <= 4) { puts("IMPOSSIBLE"); continue; }
        if(n == 3 && m == 3) { puts("IMPOSSIBLE"); continue; }
        puts("POSSIBLE");
        ans.clear();
        if(n == 2) {
            get2n(0,0);
        }
        else if(n == 4 && m == 4) {
            get44(0,0);
        }
        else {
            int dx = 0,dy = 0;
            for(int i = 0,nowx,cur = 0;i < n;i += nowx) {
                if(i + 2 == n) nowx = 2;
                else if(i + 4 == n) nowx = 2;
                else nowx = 3;
                if(nowx == 2) {
                    get2n(cur,i);
                    cur ^= 1;
                    continue;
                }
                for(int j = 0,nowy;j < m;j += nowy) {
                    if(j + 7 == m) nowy = 7,get37(i,j);
                    else if(j + 6 == m) nowy = 6,get36(i,j);
                    else if(j + 5 == m) nowy = 5,get35(i,j);
                    else nowy = 4,get34(i,j);
                }
            }
        }
        for(pii p : ans) {
            if(flag) swap(p.first,p.second);
            printf("%d %d\n",p.first,p.second);
        }
  //      check();
    }
}

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

vector<pii> ans;

void get25(int dx,int dy) {
    int sz1 = ans.size();
    ans.push_back(make_pair(2+dx,5+dy));
    ans.push_back(make_pair(2+dx,3+dy));
    ans.push_back(make_pair(2+dx,1+dy));
    ans.push_back(make_pair(1+dx,2+dy));
    ans.push_back(make_pair(1+dx,4+dy));
    ans.push_back(make_pair(2+dx,2+dy));
    ans.push_back(make_pair(2+dx,4+dy));
    ans.push_back(make_pair(1+dx,5+dy));
    ans.push_back(make_pair(1+dx,3+dy));
    ans.push_back(make_pair(1+dx,1+dy));
    reverse(ans.begin()+sz1,ans.end());
}

void get24(int dx,int dy) {
    int sz1 = ans.size();
ans.push_back(make_pair(2+dx,4+dy));
ans.push_back(make_pair(1+dx,2+dy));
ans.push_back(make_pair(2+dx,1+dy));
ans.push_back(make_pair(2+dx,3+dy));
ans.push_back(make_pair(1+dx,4+dy));
ans.push_back(make_pair(2+dx,2+dy));
ans.push_back(make_pair(1+dx,3+dy));
ans.push_back(make_pair(1+dx,1+dy));
    reverse(ans.begin()+sz1,ans.end());
}

void get23(int dx,int dy) {
    int sz1 = ans.size();
ans.push_back(make_pair(2+dx,3+dy));
ans.push_back(make_pair(1+dx,2+dy));
ans.push_back(make_pair(2+dx,1+dy));
ans.push_back(make_pair(1+dx,3+dy));
ans.push_back(make_pair(2+dx,2+dy));
ans.push_back(make_pair(1+dx,1+dy));
    reverse(ans.begin()+sz1,ans.end());
}

void get33(int dx,int dy) {
    int sz1 = ans.size();
ans.push_back(make_pair(3+dx,3+dy));
ans.push_back(make_pair(1+dx,2+dy));
ans.push_back(make_pair(3+dx,2+dy));
ans.push_back(make_pair(2+dx,1+dy));
ans.push_back(make_pair(2+dx,3+dy));
ans.push_back(make_pair(3+dx,1+dy));
ans.push_back(make_pair(2+dx,2+dy));
ans.push_back(make_pair(1+dx,3+dy));
ans.push_back(make_pair(1+dx,1+dy));
    reverse(ans.begin()+sz1,ans.end());
}

void get32(int dx,int dy) {
    int sz1 = ans.size();
ans.push_back(make_pair(3+dx,2+dy));
ans.push_back(make_pair(2+dx,1+dy));
ans.push_back(make_pair(1+dx,2+dy));
ans.push_back(make_pair(3+dx,1+dy));
ans.push_back(make_pair(2+dx,2+dy));
ans.push_back(make_pair(1+dx,1+dy));
    reverse(ans.begin()+sz1,ans.end());
}

void get2n(int dx,int m,int &sx,int &sy) {
    //printf("%d-%d\n",sx,sy);
    int sz = ans.size();
    for(int i = 0;i < m;i += 3) {
        if(i+5 == m) {
            get25(dx,i);
            break;
        }
        else if(i+4 == m) {
            get24(dx,i);
            break;
        }
        else {
            get23(dx,i);
        }
    }
    if(sx == dx+2) {
        for(int i = sz;i < ans.size();i ++)
            if(ans[i].first == dx+1) ans[i].first ++;
            else ans[i].first --;
        sx ++;
    }
    else sx += 3;
    if(sy == m) {
        for(int i = sz;i < ans.size();i ++) ans[i].second = m+1 - ans[i].second;
        sy = 1;
    }
    else sy = m;
}

void get3n(int dx,int m,int &sx,int &sy) {
    bool flag = 0;
    if(sx == dx+2) {
        sx = dx + 1;
        flag = 1;
    }
    //cout << sx << " " << dx <<endl;
    int sz = ans.size();
    for(int i = 0;i < m;i += 2) {
        int sz = ans.size();
        if(i+3 == m) {
            get33(dx,i);
            break;
        }
        else {
            get32(dx,i);
        }
        if(flag) {
            for(int j = sz;j < ans.size();j ++) {
                if(ans[j].second == i+1) ans[j].second ++;
                else ans[j].second --;
            }
        }
        flag ^= 1;
    }
  //  cout << sx << " " << sy << endl;
 //   for(int i = sz;i < ans.size();i ++) printf("%d,%d\n",ans[i].first,ans[i].second);

    if(sy == m) {
        for(int i = sz;i < ans.size();i ++) ans[i].second = m+1 - ans[i].second;
        sy = 1;
    }
}

int n,m,flag;

bool check() {
    if(flag) swap(n,m);
    assert(ans.size() == n*m);
    map<pii,int> mp;
    for(int i = 0;i < ans.size();i ++){
        assert(!mp.count(ans[i]));
        assert(ans[i].first >= 1);
        assert(ans[i].first <= n);
        assert(ans[i].second <= m);
        assert(ans[i].second >= 1);
        mp[ans[i]] = 1;
        if(i+1 < ans.size()) {
            int dx = ans[i+1].first - ans[i].first;
            int dy = ans[i+1].second - ans[i].second;
            int d = dx*dx+dy*dy;
            if(d <= 1 || d >= 9) {
                cout << i << endl;
                assert(0);
            }
        }
    }
    return true;
}

void work() {
    ans.clear(); flag = 0;
    if(n>m) swap(n,m),flag = 1;
    if(n == 1 && m == 1) {
        printf("YES\n1 1\n");
    }
    else if(n == 1 || (n == 2 && m == 2)) puts("NO");
    else {
        int sx = 1,sy = 1;
        for(int i = 0;i < n;i += 2) {
            if(i+3 == n) {
                get3n(i,m,sx,sy);
                break;
            }
            else {
                get2n(i,m,sx,sy);
            }
        }
        if(flag) {
            for(int i = 0;i < ans.size();i ++) swap(ans[i].first,ans[i].second);
        }
        puts("YES");
        for(int i = 0;i < ans.size();i ++) printf("%d %d\n",ans[i].first,ans[i].second);
        check();

    }
}

int main() {
   /* for(int N = 1;N <= 100;N ++) {
        for(int M = 1;M <= 100;M ++) {
            n = N; m = M;
            work();
        }
    }*/
    int T = read();
    while(T --) {
        n = read(),m = read();
        work();
    }
}

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

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
    int x,y;
}a[SZ];
int n;

int get0(vector<int> vec) {
    int tmp = 0;
    vector<int> ji;
    for(int t : vec) {
        if(t&1) ji.push_back(1);
        tmp += t / 2 * 2;
    }
    sort(ji.begin(),ji.end()); reverse(ji.begin(),ji.end());
    if(ji.size() == 0) {
        tmp = min(tmp+2,n);
    }
    else if(ji.size() == 1) {
        tmp += ji[0];
        if(tmp < n) tmp ++;
    }
    else if(ji.size() >= 2) tmp += ji[0] + ji[1];
    return tmp;
}

int get1(vector<int> vec) {
    int ans = vec[0];
    int t = vec[0];
    for(int i = 1;i < vec.size();i ++) {
        int x = vec[i];
        while(x >= 3 && t) {
            t --;
            ans += 3;
            x -= 3;
        }
    }
    return ans;
}

int get2(vector<int> vec) {
    int ans = vec[0];
    int t = vec[0] - 1;
    for(int i = 1;i < vec.size();i ++) {
        int &x = vec[i];
        if(x >= 3 && x % 2 == 1 && t) {
            t --;
            x -= 3;
            ans += 3;
        }
    }
    for(int i = 1;i < vec.size();i ++) {
        int &x = vec[i];
        while(x >= 6 && t >= 2) {
            t -= 2;
            ans += 6;
            x -= 6;
        }
    }
    for(int i = 1;i < vec.size();i ++) {
        int x = vec[i];
        ans += x / 2 * 2;
    }
    if(ans < n) ans ++;
    return ans;
}

int get3(vector<int> vec) {
    int ans = vec[0];
    int t = vec[0] - 2;
    for(int i = 1;i < vec.size();i ++) {
        int &x = vec[i];
        if(x >= 3 && x % 2 == 1 && t) {
            t --;
            x -= 3;
            ans += 3;
        }
    }
    for(int i = 1;i < vec.size();i ++) {
        int &x = vec[i];
        while(x >= 6 && t >= 2) {
            t -= 2;
            ans += 6;
            x -= 6;
        }
    }
    for(int i = 1;i < vec.size();i ++) {
        int x = vec[i];
        ans += x / 2 * 2;
    }
    if(ans < n) ans ++;
    if(ans < n) ans ++;
    return ans;
}

void work() {
    n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].x = read();
        a[i].y = read();
    }
    map<pll,map<LL,set<int> > > mp;
    for(int i = 1;i <= n;i ++) {
        for(int j = i + 1;j <= n;j ++) {
            if(i == j) continue;
            int dx = a[i].x - a[j].x;
            int dy = a[i].y - a[j].y;
            int gcd = __gcd(dx,dy); gcd = abs(gcd);
            dx /= gcd,dy /= gcd;
            if(dx < 0) dx *= -1,dy *= -1;
            LL A = dy,B = -dx,C = -(A*a[i].x + B * a[i].y);
            mp[{A,B}][C].insert(i);
            mp[{A,B}][C].insert(j);
         //   printf("%d %d %lld %lld %lld\n",i,j,A,B,C);
        }
    }
    int ans = min(2,n);
    for(auto &p1 : mp) {
        int tmp = 0;
        vector<int> vec;
        for(auto &p2 : p1.second) {
            int t = p2.second.size();
            vec.push_back(t);
        }
        sort(vec.begin(),vec.end()); reverse(vec.begin(),vec.end());
        ans = max(ans,get0(vec));
        ans = max(ans,get1(vec));
        ans = max(ans,get2(vec));
        ans = max(ans,get3(vec));
    }
    printf("%d\n",ans);
}

int main(){
    int T = read();
    int cc = 0;
    while(T --) {
        printf("Case #%d: ",++ cc);
        work();
    }
    return 0;
}





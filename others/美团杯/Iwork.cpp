#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

bool isNum(char c) {
    return '0' <= c && c <= '9';
}

struct sta {
    LL A,B;
}a[SZ];

sta merge(sta a,sta b) {
    LL A = a.A,B = a.B;
    LL C = b.A,D = b.B;
    sta ans;
    ans.A = A * C % mod;
    ans.B = ((C * B) % mod + D) % mod;
    return ans;
}

char s[SZ];
int main() {
    freopen("I/small.cpp","r",stdin);
    string s;
    int line = 0;
    a[0] = (sta){10007,0};
    a[1] = (sta){1,18980504};
    while(getline(cin,s)) {
        line ++;
        if(s[0] == 'v' && line >= 8) {
            int i = 6;
            vector<int> vec;
            while(i < s.size()) {
                int num = 0;
                while(i < s.size() && isNum(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                while(i < s.size() && !isNum(s[i])) i ++;
                vec.push_back(num);
            }
            int now = vec[0],u = vec[1],v = vec[2];
            //printf("%d %d %d\n",now,u,v);
            a[now] = merge(a[u],a[v]);
         //   printf("%d %lld %lld\n",now,a[now].A,a[now].B);
        }
    }
    cout << a[3000].B << endl;
}



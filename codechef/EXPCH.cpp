#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e7 + 10;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int a[SZ];

LL baoli(int n,char s[]) {
    LL ans = 0;
    for(int l = 1;l <= n;l ++) a[l] = 0;
    for(int l = 1;l <= n;l ++) {
        int d = 0;
        for(int i = l;i <= n;i ++) {
            if(s[i] == '(') {
                d ++;
            }
            else if(s[i] == ')') {
                if(d == 0) a[i] ++,d ++;
                else d --;
            }
            else {

            }
        }
    }
    for(int i = 1;i <= n;i ++) ans += a[i] * (n-i+1);
    for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
    return ans;
}

char s[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        scanf("%s",s + 1);
        n = strlen(s+1);

       // LL w = baoli(n,s);
       // cout <<w << endl;

        stack<pii> S;
        //for(int i = 1;i <= n;i ++) S.push(make_pair(0,0));
        S.push(make_pair(1,0));

        LL ans = 0;
        for(int i = 1;i <= n;i ++) {
            if(s[i] == '(') {
                S.push(make_pair(1,0));
            }
            else if(s[i] == ')') {
                //cout << S.top().first << " ";
                (ans += 1ll * S.top().first * (n-i+1) % mod) %= mod;
                if(S.size() > 1) {
                    pii u = S.top(); S.pop();
                    pii v = S.top(); S.pop();
                    v.first += u.second + 1;
                    v.second += u.first;
                    S.push(v);
                }
                else {
                    pii u = S.top(); S.pop();
                    swap(u.first,u.second);
                    u.first ++;
                    S.push(u);
                }
            }
            else {
                pii u = S.top(); S.pop();
                u.first ++;
                S.push(u);
            }
        }
      //  puts("");
      //  cout << ans <<endl;
        (ans *= ksm(1ll*n*(n+1)%mod*ksm(2,mod-2)%mod,mod-2))%=mod;
        printf("%lld\n",ans);
    }
}
/*
233
1
))((())(

233
1
())))(
1
)))))
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 1e7 + 19;
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
    int type,pos,val;
}a[SZ];

int n;
int A[SZ],B[SZ];
pii c[SZ];
int inv[10000100],b[10000100];
int mu[10000100],add[10000100],tot;

int ask(int x,int a,int b,int c,int d) {
    c %= mod; c += mod; c %= mod;
    return (1ll*a * x%mod + b - d) % mod * inv[c] % mod;
}

map<int,int> mp;

LL baoli() {
   // puts("---");
    LL ans = 0;
    vector<int> num; num.resize(n+1);
    for(int i = 1;i <= tot;i ++) {
        int type = a[b[i]].type,x = a[b[i]].pos,val = a[b[i]].val,y,tmp;
       // cout << b[i] << endl;
        switch(type) {
        case 1:
            num[x] = val;
            break;
        case 2:
            for(int j = 1;j <= n;j ++) (num[j] += val) %= mod;
            break;
        case 3:
            for(int j = 1;j <= n;j ++) (num[j] = 1ll * num[j] * val % mod) %= mod;
            break;
        case 4:
            for(int j = 1;j <= n;j ++) num[j] = val % mod;
            break;
        case 5:
            (ans += num[x]) %= mod;
            num[x] += mod; num[x] %= mod;
       //     cout << num[x] << endl;
            break;
        case 6:
            LL tmp = 0;
            for(int j = 1;j <= n;j ++) (tmp += num[j]) %= mod;
            tmp += mod; tmp %= mod;
      //      cout << tmp << endl;
            (ans += tmp) %= mod;
            break;
        }
    }
    return ans;
}

int main() {
    inv[1] = 1;
    for(int i = 2;i < mod;i ++)
        inv[i] = (mod - 1ll * mod / i * inv[mod % i] % mod) % mod;
    n = read();
    int q = read();
    for(int i = 1;i <= q;i ++) {
        a[i].type = read();
        if(a[i].type == 1) a[i].pos = read(),a[i].val = read();
        else if(a[i].type == 2) a[i].val = read();
        else if(a[i].type == 3) a[i].val = read();
        else if(a[i].type == 4) a[i].val = read();
        else if(a[i].type == 5) a[i].pos = read();
        if(a[i].type == 3 && a[i].val == 0) a[i].type = 4;
        if(a[i].pos) {
            if(!mp[a[i].pos]) mp[a[i].pos] = ++ tot;
            a[i].pos = mp[a[i].pos];
        }
        a[i].val %= mod;
    }
    int t = read();
    for(int i = 1;i <= t;i ++) A[i] = read(),B[i] = read();
    tot = 0;
    for(int i = 1;i <= t;i ++) {
        for(int j = 1;j <= q;j ++) {
            int id = (A[i] + 1ll*j * B[i]%q) % q + 1;
            b[++ tot] = id;
        }
    }

    for(int i = tot,MU = 1,ADD = 0;i >= 0;i --) {
        mu[i] = MU; add[i] = ADD;
        if(i == 0) break;
        int x = b[i];
        if(a[x].type == 2) (ADD += 1ll*MU * a[x].val % mod) %= mod;
        else if(a[x].type == 3) MU = 1ll * MU * a[x].val % mod;
    }

    pll lst = make_pair(0,0);
    LL ans = 0,sum = 0;
   // for(int i = 1;i <= tot;i ++) printf("%d ",mu[i]); puts("");
    //for(int i = 1;i <= tot;i ++) printf("%d ",add[i]); puts("");
    for(int i = 1;i <= tot;i ++) {
        int type = a[b[i]].type,x = a[b[i]].pos,val = a[b[i]].val;
        int y,z,tmp;
        switch(type) {
        case 1:
            if(lst.first > c[x].first) y = lst.first,z = lst.second;
            else y = c[x].first,z = c[x].second;
         //   printf("%d %d\n",y,z);
         //   printf("%d %d %d %d %d %d\n",
         //          z,mu[y],add[y],mu[i],add[i],ask(z,mu[y],add[y],mu[i],add[i]));
            (ans -= ask(z,mu[y],add[y],mu[i],add[i])) %= mod;
            (ans += val) %= mod;
            c[x] = make_pair(i,val);
            break;
        case 2:
            (ans += 1ll * val * n % mod) %= mod;
            break;
        case 3:
            ans = 1ll * ans * val % mod;
            break;
        case 4:
            lst = make_pair(i,val);
            ans = 1ll * n * val % mod;
            break;
        case 5:
            if(lst.first > c[x].first) y = lst.first,z = lst.second;
            else y = c[x].first,z = c[x].second;
            tmp = ask(z,mu[y],add[y],mu[i],add[i]);
            tmp += mod; tmp %= mod;
            (sum += tmp) %= mod;
       //     cout << tmp << endl;
            break;
        case 6:
            ans += mod; ans %= mod;
            (sum += ans) %= mod;
       //     cout << ans << endl;
            break;
        }
    }
    sum += mod; sum %= mod;
    printf("%lld\n",sum);
    return 0;
}

/**

5
10
2 2
3 2
2 4
5 2
6
1 1 3
6
2 2
4 3
6
1
0 1

*/

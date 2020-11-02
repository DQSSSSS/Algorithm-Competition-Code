#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,int> pli;
typedef pair<int,int> pii;
const int SZ = 2e5 + 10;
const LL mod[] = {1000056479,1000189471};

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 +a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

const int B = 131;

string s[SZ];
int id[SZ],n,m;
int h[2][SZ],mi[2][SZ];
LL a[SZ];
int val[SZ],ans[SZ];

pii get(int l,int r) {
    int a1 = (h[0][r] - 1ll * h[0][l-1] * mi[0][r-l+1] % mod[0] + mod[0]) % mod[0];
    int a2 = (h[1][r] - 1ll * h[1][l-1] * mi[1][r-l+1] % mod[1] + mod[1]) % mod[1];
    return make_pair(a1,a2);
}

void work(int l,int r) {
    int len = s[id[l]].length();
    map<LL,int> mp;
    for(int i = len;i <= n;i ++) {
        if(i-len >= len) {
            LL x = a[i-len];
            mp[x] = max(mp[x],val[i-len]);
        }
        pii t = get(i-len+1,i);
        LL x = a[i] = 1ll * t.first * t.second;
        val[i] = mp[x] + 1;
    }
    for(int i = max(n-len+1,len);i <= n;i ++) mp[a[i]] = max(mp[a[i]],val[i]);
    for(int i = l;i <= r;i ++) {
        int iid = id[i];
        int a1 = 0,a2 = 0;
        for(int j = 0;j < s[iid].length();j ++) a1 = (1ll*a1*B%mod[0] + s[iid][j]) % mod[0];
        for(int j = 0;j < s[iid].length();j ++) a2 = (1ll*a2*B%mod[1] + s[iid][j]) % mod[1];
        ans[iid] = mp[1ll * a1 * a2];
    }
}

bool cmp(int x,int y) {
    return s[x].length() < s[y].length();
}

char input[SZ],S[SZ];

int main() {
    n = read(),m = read();
    scanf("%s",S+1);
    for(int k = 0;k < 2;k ++) {
        mi[k][0] = 1;
        for(int i = 1;i <= n;i ++) mi[k][i] = (1ll*mi[k][i-1]*B%mod[k]);
        for(int i = 1;i <= n;i ++) h[k][i] = ((1ll*h[k][i-1]*B%mod[k]) + S[i]) % mod[k];
    }
    for(int i = 1;i <= m;i ++) {
        scanf("%s",input);
        s[i] = input;
        id[i] = i;
    }
    sort(id+1,id+1+m,cmp);
    for(int i = 1,j = 1;i <= m;i ++) {
        if(i == m || s[id[i+1]].length() != s[id[i]].length()) {
            work(j,i);
            j = i + 1;
        }
    }
    for(int i = 1;i <= m;i ++) printf("%d\n",ans[i]);
}

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 1e17;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

bool vis[SZ];
int pri[SZ],minP[SZ],mu[SZ];

void shai(int n) {
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ pri[0]] = i,minP[i] = i,mu[i] = -1;
        for(int j = 1,m;j <= pri[0] && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            minP[m] = pri[j];
            if(i % pri[j] == 0) {
                mu[m] = 0;
                break;
            }
            else {
                mu[m] = -mu[i];
            }
        }
    }
}

vector<int> a[SZ];
int num[SZ],use[SZ],n,q;


int A[SZ];
LL baoli(int x) {
    static LL ans = 0;
    int sign;
    if(use[x]) {
        sign = -1;
    }
    else {
        sign = 1;
    }
    for(int i = 1;i <= n;i ++)
        if(use[i]) {
            if(i == x) continue;
            if(__gcd(A[i],A[x]) == 1)
                ans += sign;
        }
    return ans;
}

mt19937 rd(time(0));

int getData() {
    return rd() % n + 1;
}

int main() {
    shai(500000);
    n = read(),q = read();
    for(int i = 1;i <= n;i ++) {
        int x = read();
        //int x = getData();
        A[i] = x;
        //a[i].push_back(1);
        while(x != 1) {
            int t = minP[x];
            a[i].push_back(t);
            while(x%t==0) x/=t;
        }
        //for(int t : a[i]) printf("%d ",t); puts("");
        vector<int> tmp = a[i]; a[i].clear();
        for(int S = 0;S < (1<<tmp.size());S ++) {
            LL t = 1;
            for(int j = 0;j < tmp.size();j ++) {
                if(S >> j & 1) {
                    t *= tmp[j];
                }
            }
            a[i].push_back(t);
        }
    }

    vector<int> query;

    LL ans = 0;
    while(q --) {
        int x = read();
        //int x = getData();
        query.push_back(x);
        int sign;
        if(use[x]) {
            sign = -1;
            for(int d : a[x]) {
                num[d] += sign;
            }
            for(int d : a[x]) {
                ans += sign * mu[d] * num[d];
            }
        }
        else {
            sign = 1;
            for(int d : a[x]) {
                ans += sign * mu[d] * num[d];
            }
            for(int d : a[x]) {
                num[d] += sign;
            }
        }

        //LL blans = baoli(x);
        /*if(blans != ans){
            for(int i = 1;i <= n;i ++) printf("%d ",A[i]); puts("");
            for(int x : query) printf("%d ",x); puts("");
            for(int x : query) printf("%d ",A[x]); puts("");
            return 0;
        }*/

        use[x] ^= 1;
       //printf("my: %lld\n",ans);
       // printf("baoli: %lld\n",blans);
        printf("%lld\n",ans);
    }

    return 0;
}

/*
100 100
64 36 53 88 77 89 72 5 50 58 5 50 25 15 47 26 17 71 16 48 31 10 5 51 56 57 77 3 43 94 54 87 4 60 51 79 4 73 70 78 6 3 84 53 23 75 77 91 18 89 3 58 69 2 54 33 24 38 80 94 31 49 44 4 89 2 89 82 65 17 74 87 72 64 12 60 49 42 61 23 43 6 38 11 78 36 35 54 58 35 6 50 45 86 66 25 15 45 73 59
3 6 64 82 72 23 7


6 6
98 40 11 33 77 33
1
2
3
4
5
6

4 4
98 40 33 33
1
2
3
4

*/


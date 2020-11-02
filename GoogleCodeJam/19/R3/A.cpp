#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int N = 1e6,M = N / 100;

mt19937 rd(time(0));

int main() {

    int T = 1000,t = 0;
    while(T --) {
        N -= M;
        int yuan = N - M + 1;
        int x = rd() % (N-M+1)+1;
        int hou = 0;
        for(int i = 1;i + M - 1 <= x;i ++) hou ++;
        for(int i = x+M;i + M - 1 <= N;i ++) hou ++;
        if(yuan - hou == 1998) t ++;
        printf("%6d%6d\n",N,yuan-hou);
    }
    cout << t << endl;
    /*int T = read(),cc = 0;
    while(T --) {
        int n = read();

        printf("Case #%d: %d\n",++ cc,ans);
    }*/
    return 0;
}

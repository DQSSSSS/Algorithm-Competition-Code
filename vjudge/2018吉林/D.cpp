#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 2e5 + 10;

double f[333];


int main() {
    int T,cc = 0;
    scanf("%d",&T);
    while(T --) {
        int pp;
        scanf("%d",&pp);
        double p = 1.0*pp/100;
        f[200] = 1/p;
        for(int i = 199;i >= 4;i --) {
            int nx1 = min(200,i+4);
            int nx2 = min(200,i+3);
            f[i] = p * (i/200.0+(1-i/200.0)*(f[nx1]+1))
                  + (1-p) * (f[nx2] + 1);
        }
        printf("Case %d: %.10f\n",++ cc,f[4]);
    }
}


#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

LL ans[5][2];
int len;

void work(int x,int y) {
    if(__gcd(x,y) == 1) { ans[++ len][0] = x; ans[len][1] = y; return ;}
    int flag = 0;
    for(int i = 2;i <= x - 2;i ++)
        for(int j = 2;j <= y - 2;j ++) {
            if(flag) break;
            if(__gcd(i,j) == 1 && __gcd(x-i,y-j) == 1){
                flag = 1;
                ans[++ len][0] = i; ans[len][1] = j;
                ans[++ len][0] = x-i; ans[len][1] = y-j;
            }
    }
    if(!flag) exit(1);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        LL A,B;
        len = 0;
        scanf("%lld%lld",&A,&B);
        if(A > B) swap(A,B);
        if(A < )
    }
}

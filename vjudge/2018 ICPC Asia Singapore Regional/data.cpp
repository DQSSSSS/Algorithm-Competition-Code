#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int read() {
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a == '-') flag = 1; a = getchar();}
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a = getchar();}
    if(flag) n = -n;
    return n;
}

mt19937 rd(time(0));

int randlr(int l,int r) {
    return rd()%(r-l+1) + l;
}

int main() {
    freopen("D.in","w",stdout);
    int n = 5e5;
    int k = 1e5;
    printf("%d %d\n",n,k);
    for(int i = 1;i <= n;i ++) {
        int x = randlr(0,1e9);
        printf("%d ",x);
    }
}

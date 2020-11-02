#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int work(int n) {
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(n == 4) return 1;
    if(n == 5) return 1;
    for(int i = 9;i <= n;i = i * 2 + 2) {
        if(i == n) return 1;
        if(i + 1 == n) return 1;
        printf("%d %d\n",i,i+1);
    }
    return 0;
}

int main() {
    int n = read();
	int p=2;
	while (p<=n) {
        printf("%d %d %d %d\n",p*2,p*2+1,p*4+1,p*4+2);
		p=p*4+2;
	}
    cout << work(n) <<endl;
}





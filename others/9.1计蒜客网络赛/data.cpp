#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 1000000010;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};


LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
           		break;
            }
            else {
            }
		}
    }
}

int randint()
{
    return rand() << 16 | rand();
}

int randlr(int l,int r) {
	return randint() % (r - l + 1) + l;
}

int main()
{
    freopen("in.txt","w",stdout);
    srand(time(0));
    int T = 1000;
    cout << T << endl;
    while(T --) {
        int n = randlr(2,3);
        int m = randlr(n*5,n*5+10);
        printf("%d %d\n",n,m);
        for(int i = 1;i <= m;i ++){
            int x = randlr(1,13);
        	printf("%d ",x);
        }
        puts("");
    }

    return 0;
}

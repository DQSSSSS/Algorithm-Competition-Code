#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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
    int l,r,id,b;
}a[SZ];

bool cmpr(haha a,haha b) {  return a.r < b.r;}
bool cmpid(haha a,haha b) {  return a.id < b.id;}

int Add[SZ];
int Del[SZ];
int lsh[SZ];

int main() {
    int T = read();
    int max1 = 0,max2 = 0;
    while(T --) {
        char s[3];
        scanf("%s",s);
        int x = read(),y = read();
        if(x>y) swap(x,y);
        if(s[0] == '+') max1 = max(max1,x),max2 = max(max2,y);
        else {
            if(x >= max1 && y >= max2) puts("YES");
            else puts("NO");
        }
    }
}



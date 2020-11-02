#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const LL INF = 1e18;
const LD eps = 1e-7;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

bool check(int n) {
	for(int i = 2;i * i < n;i ++)
		if(n % i == 0)return false;
	return true;
}
/*
vector<int> getGtmp;
int getG(int p) {
    int x = p - 1;
    getGtmp.clear();
    for(int i = 2;i <= x;i ++) if(x % i == 0) getGtmp.push_back(i);
    for(int k = 2;;k ++)
        for(int i = 0;i < getGtmp.size();i ++) {
            if(ksm(k,getGtmp[i],p) == 1) {
                if(getGtmp[i] == x)
                    return k;
                else break;
            }
        }
}*/

int randlr(int l,int r) {
	int x = rand() << 16 | rand();
	return x % (r - l + 1) + l;
}

int main() {
	//for(int i = 99991-1;;i --) if(check(i)) { cout << i << endl; return 0; }
	srand(time(0));
	freopen("B.in","w",stdout);
	int n = 20,m = 20,c = randlr(1,1000);
	cout << n << " " << m << " " << c << endl;
	for(int i = 0;i <= n;i ++,puts("")) 
		for(int i = 0;i <= m;i ++) 
			cout << randlr(0,1000000) << " "; 
		//*/
}

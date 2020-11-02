#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2100;
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

int jia[SZ][SZ],cheng[SZ][SZ],p;

int getp(int x) {
	int ans = 1;
	for(int i = 1;i <= p;i ++) {
        ans = cheng[ans][x];
        //cout << ans << " " << i << endl;
    }
    return ans;
}

bool check() {
	bool b = 0;
    for(int x = 0;x < p;x ++){
		bool use[2333] = {0};
		int lst = 1;
        for(int i = 1;i <= p - 1;i ++) {
            lst = cheng[lst][x];
            use[lst] = 1;
        }
        bool flag = 0;
        for(int i = 1;i <= p - 1;i ++) {
            if(!use[i]) { flag = 1; break; }
        }
        if(!flag) { b = 1; break; }
    }
    if(!b) return false;
    //puts("fuck");
    for(int i = 0;i < p;i ++)
    	for(int j = 0;j < p;j ++) {
            int x = getp(i),y = getp(j);
            if(getp(jia[i][j]) != jia[x][y]) {
            	//cout << i << " " << j << " " << x << " " << y << " " << endl;
            	//cout << jia[i][j] << " " << getp(jia[i][j]) << " " << jia[x][y] << endl;
            	return false;
            }
    	}
    return true;
}

int main() {
    int T = read();
    while(T --) {
		p = read();
		if(p == 2) {
            printf("0 1\n1 0\n0 0\n0 1\n");
            continue;
		}
        for(int i = 0;i < p;i ++) {
        	for(int j = 0;j < p;j ++)
        		jia[i][j] = 0;
        	jia[i][i] = i;
            for(int j = 0;j < p;j ++) {
            	if(i == 1) cheng[i][j] = j;
            	else cheng[i][j] = 0;
            }
            cheng[i][i] = 1;
        }
        cheng[0][p - 1] = 0;
        for(int i = 1;i <= p - 2;i ++) cheng[i][p - 1] = i + 1;
        for(int i = 0;i < p;i ++)
       		for(int j = 0;j < p;j ++)
       			printf("%d%c",jia[i][j] = 2,j == p - 1 ? '\n' : ' ');
       	for(int i = 0;i < p;i ++)
       		for(int j = 0;j < p;j ++)
       			printf("%d%c",cheng[min(i,j)][max(i,j)],j == p - 1 ? '\n' : ' ');
       //	assert(check());
    }
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int main(){
	/*for(int i = 1;i <= 100;i ++) {
		int t = 0;
		for(int j = 1;j <= i;j ++)
			if(__gcd(i,j) == 1)
				t ++;
		cout << i << " "<< t << endl;
	}*/
	int T = read();
	while(T --) {
		int n = read();
        if(n == 1) puts("5");
        else {
			printf("%d\n",n + 5);
        }
	}
	return 0;
}

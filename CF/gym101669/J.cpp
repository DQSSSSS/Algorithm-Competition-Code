#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int A = 0,B = 0,C = 0;

bool check() {
    if(A+B+C == 1) return true;
    if(A+B+C >= 5) return false;
    if(A == 1 && B + C == 1) return true;
    if(A == 2 && B + C == 0) return true;
    if(A+B+C == 4) {
        if(A == 2 && B == 1 && C == 1) return true;
        if(A == 2 && B == 2 && C == 0) return true;
        if(A == 3 && B == 1 && C == 0) return true;
    }
    if(A == 1 && B == 0 && C == 1) return true;
    if(A == 2 && B == 0 && C == 1) return true;
    if(A == 1 && B == 1 && C == 0) return true;
    if(A == 2 && B == 1 && C == 0) return true;
    if(A == 1 && B == 2 && C == 0) return true;
    if(A == 2 && B == 2 && C == 0) return true;
    if(A == 1 && B == 1 && C) return true;
    if(A == 1 && B == 2 && C) return true;
    return false;
}

int main(){
    int n;
    while(~scanf("%d",&n)) {
        A = 0,B = 0,C = 0;
        for(int i = 1;i <= n;i ++) {
            int x = read();
            if(x == 1) A ++;
            else if(x == 2) B ++;
            else C ++;
        }
        A %= 3;
        if(check()) puts("Win");
        else puts("Lose");
    }
}

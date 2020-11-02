#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

int A[55][55];
int B[55][55];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            A[i][j] = read();
        }
    }
    vector<pii> ans;
    for(int i = 1;i < n;i ++) {
        for(int j = 1;j < m;j ++) {
            int t = 0;
            for(int a = 0;a < 2;a ++) {
                for(int b = 0;b < 2;b ++) {
                    t += A[i+a][j+b];
                }
            }
            if(t == 4) {
                ans.push_back(make_pair(i,j));
                for(int a = 0;a < 2;a ++) {
                    for(int b = 0;b < 2;b ++) {
                        B[i+a][j+b] = 1;
                    }
                }
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(A[i][j] != B[i][j]) {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n",ans.size());
    for(pii p : ans) {
        printf("%d %d\n",p.first,p.second);
    }

}

#include <bits/stdc++.h>
using namespace std;

int a[110],use[110];

void dfs(int t,int n,int d) {
    if(t == n + 1) {
        for(int i = 1;i <= n;i ++) {
            printf("%d ",a[i]);
        }
        puts("");
        return ;
    }
    for(int i = 1;i <= n;i ++) {
        if(use[i] == 0 && (t == 1 || abs(i - a[t-1]) <= d)) {
            use[i] = 1;
            a[t] = i;
            dfs(t+1,n,d);
            use[i] = 0;
            a[t] = 0;
        }
    }
}

int main() {
    int n,d;
    cin >> n >> d;
    dfs(1,n,d);
}

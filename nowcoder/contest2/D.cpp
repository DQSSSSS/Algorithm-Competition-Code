#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

int a[SZ];

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
        LL ans = 0,lst = 0;
        int ans2 = 0;
        bool flag = 0;
        for(int i = 1;i <= n;i ++) {
			if(flag && (i == n || a[i + 1] < a[i]))
                ans += a[i] - lst,flag = 0,ans2 ++;
            if(!flag && i != n && a[i + 1] > a[i])
				lst = a[i],flag = 1,ans2 ++;
        }
        cout << ans << " " << ans2 <<endl;
    }
	return 0;
}


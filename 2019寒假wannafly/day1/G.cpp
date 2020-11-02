#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int gcd(int a,int b) { return b == 0 ? a : gcd(b,a%b); }

int st[210][10],sum[210],a[210][210],lg[210];

void get_st(int a[],int n) {
    for(int i = 1;i <= n;i ++) st[i][0] = a[i];
    for(int j = 1;j <= lg[n];j ++) {
        for(int i = 1;i <= n;i ++) {
            if(i + (1 << j) - 1 <= n)
                st[i][j] = gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}

int get_gcd(int l,int r) {
    int k = lg[r-l+1];
    return gcd(st[l][k],st[r-(1<<k)+1][k]);
}

LL get_ans(int n,int m,int x,int y,int flag) {
    if(flag == 1) {
        LL tmp = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) sum[j] = 0;
            for(int up = i;up >= 1;up --) {
                for(int j = 1;j <= m;j ++) sum[j] = gcd(sum[j],a[up][j]);
                get_st(sum,m);
                for(int j = 1;j <= m;j ++) {
                    if(sum[j] == 1) continue;
                    int l = j,r = m+1;
                    while(r - l > 1) {
                        int mid = l + r >> 1;
                        if(get_gcd(j,mid) > 1) l = mid;
                        else r = mid;
                    }
                    LL u = (l-j+1)*(i-up+1);
                    if(up == 1 && i == n) tmp = max(tmp,u * x);
                    if(j == 1 && l == m) tmp = max(tmp,u * y);
                    tmp = max(tmp,u);
                    //cout << up << " " << j << " " << i << " " << l << " " << u << endl;
                    //if(tmp == 6) system("pause");
                }
            }
        }
        return tmp;
    }
    LL tmp = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) sum[j] = 0;
        for(int up = i;up >= 1;up --) {
            for(int j = 1;j <= m;j ++) sum[j] = gcd(sum[j],a[up][j]);
            get_st(sum,m);
            for(int j = 1;j <= m;j ++) {
                if(sum[j] == 1) continue;
                int l = j,r = m+1;
                while(r - l > 1) {
                    int mid = l + r >> 1;
                    if(get_gcd(j,mid) > 1) l = mid;
                    else r = mid;
                }
                LL u = (l-j+1)*(i-up+1);
              //  cout << up << " " << j << " " << i << " " << l << " " << u << endl;
              //  if(j == 1 && l >= m/2) tmp = max(tmp,1ll*(i-up+1)*m/2*y);
                //if(up == 1 && i >= n/2) tmp = max(tmp,1ll*(l-j+1)*n/2*x);
                if(up <= n/2 && j <= m/2) {
                    if(l > m/2 && i <= n/2 && y > 1) tmp = max(tmp,u);
                    if(l <= m/2 && i > n/2 && x > 1) tmp = max(tmp,u);
                    if(l > m/2 && i > n/2 && x > 1 && y > 1) {
                        tmp = max(tmp,u);
                        if(up == 1 && i == n) tmp = max(tmp,u/2 * x);
                        if(j == 1 && l == m) tmp = max(tmp,u/2 * y);
                    }
                }
               // if(tmp == 18) system("pause");
            }
        }
    }
    return tmp;
}

int main() {
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    int dw = 0;
    for(int i = 1;i <= 200;i ++) lg[i] = log2(i);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            scanf("%d",&a[i][j]);
            dw = gcd(dw,a[i][j]);
            a[i+n][j] = a[i][j];
            a[i][j+m] = a[i][j];
            a[i+n][j+m] = a[i][j];
        }
    }
    if(dw != 1) printf("%lld\n",1ll*n*m*x*y);
    else {
        LL ans2 = get_ans(2*n,2*m,x,y,2);
        LL ans1 = get_ans(n,m,x,y,1);
        //cout << ans2 << " " <<ans1 <<endl;
        printf("%lld\n",max(ans2,ans1));
    }
    return 0;
}
/**
3 5 2 2
2 2 1 1 1
2 2 1 2 2
1 1 1 2 2

2 2 1 1 1 2 2 1 1 1
2 2 1 2 2 2 2 1 2 2
1 1 1 2 2 1 1 1 2 2
2 2 1 1 1 2 2 1 1 1
2 2 1 2 2 2 2 1 2 2
1 1 1 2 2 1 1 1 2 2


*/

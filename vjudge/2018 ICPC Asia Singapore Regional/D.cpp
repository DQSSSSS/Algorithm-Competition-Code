#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int read() {
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a == '-') flag = 1; a = getchar();}
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a = getchar();}
    if(flag) n = -n;
    return n;
}

int a[SZ],st[22][SZ];
int lg[SZ];

void get_st(int a[],int n) {
    for(int i = 1;i <= n;i ++) st[0][i] = a[i];
    for(int j = 1;j <= lg[n];j ++) {
        for(int i = 1;i + (1 << j) - 1 <= n;i ++) {
            st[j][i] = st[j-1][i] | st[j-1][i+(1<<(j-1))];
        }
    }
}

int ask_or(int l,int r) {
    int k = lg[r - l + 1];
    return st[k][l] | st[k][r-(1<<k)+1];
}

int n,k,nx[22][SZ];

bool check(int ans) {
    for(int i = 1;i <= 2*n;i ++) {
        int l = i - 1,r = 2 * n + 1;
        while(r-l>1) {
            int mid = l + r >> 1;
            int S = ask_or(i,mid);
            if((S & ans) == ans) r = mid;
            else l = mid;
        }
        if(r == 2 * n + 1) nx[0][i] = 0;
        else nx[0][i] = r + 1;
    }
 //   cout << ans << endl;
 //   for(int i = 1;i <= 2*n;i ++) printf("%d ",nx[i][0]); puts("");


    for(int j = 1;j <= lg[k];j ++) {
        for(int i = 1;i + (1 << j) - 1 <= 2*n+1;i ++) {
            if(!nx[j-1][i]) nx[j][i] = 0;
            else nx[j][i] = nx[j-1][nx[j-1][i]];
        }
    }

    for(int s = 1;s <= n;s ++) {
        int x = s;
        for(int j = 0;j <= lg[k];j ++) {
            if(k >> j & 1) {
                x = nx[j][x];
                if(x == 0) break;
            }
        }
     //   cout << s << " " << x << endl;
        if(x && x <= s + n) return true;
    }
 //   puts("false");
    return false;
}

int main() {
    //freopen("D.in","r",stdin);
    n = read();
    k = read();
    for(int i = 1;i <= 2*n+1;i ++) lg[i] = log2(i);
    for(int i = 1;i <= n;i ++) {
        a[i+n] = a[i] = read();
    }

    get_st(a,2*n);

    int ans = 0;
    for(int i = 29;i >= 0;i --) {
        if(check(ans|(1<<i))) ans |= 1 << i;
    }
    cout << ans << endl;
}

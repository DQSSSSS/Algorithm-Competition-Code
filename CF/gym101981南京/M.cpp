#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

int r[SZ],len;
LL sum[SZ];
char S[SZ];

void manacher(char s[]) {
    int n = strlen(s);
    len = 0;
    S[len ++] = '@';
    for(int i = 0;i < n;i ++)
        S[len ++] = s[i],S[len ++] = '$';
    S[len ++] = '#';

    int rr = 0,mid = 0;
    for(int i = 1;i < len;i ++) {
        int x = 1;
        if(rr < i) x = 1;
        else x = min(r[mid*2-i],rr - i);
        while(S[i + x] == S[i - x]) x ++;

        if(i + x > rr) rr = i + x,mid = i;
        r[i] = x;
    }
}

int z[SZ];

void get_z(char s[]) { //z[i]:后缀i与原串的lcp长度
	int n = strlen(s + 1);
	int l = 1,r = 0;
	for(int i = 2;i <= n;i ++) {
		if(i >= l + r) {
			int h = 0;
			while(i + h <= n && s[i + h] == s[1 + h]) h ++;
			z[i] = h;
		}
		else {
			int k = i - l + 1;
			if(i + z[k] < l + r) z[i] = z[k];
			else {
				int h = l + r - i;
				while(i + h <= n && s[i + h] == s[1 + h]) h ++;
				z[i] = h;
			}
		}
		if(i + z[i] > l + r) l = i,r = z[i];
	}
}

char a[SZ],b[SZ],c[SZ];

int n,m;

LL get_sum(int l,int r) {
    if(l > r) return 0;
    l = max(l,0); r = min(r,n-1);
    if(l == 0) return sum[r];
    return sum[r] - sum[l-1];
}

/**
     0     1     2     3     4
  0  1  2  3  4  5  6  7  8  9 10 11
  @  a  $  b  $  a  $  b  $  a  $  #
  0  1  1  3  1  5  1  4  1  2  1  1

  @  a  $  a  $  a  $  a  $  a  $  #
  0  1  2  3  4  5  5  4  3  2  1  0
*/

int main() {
    //freopen("M.in","r",stdin);
    scanf("%s%s",a,b);
    n = strlen(a),m = strlen(b);
    for(int i = 0;i < n / 2;i ++) swap(a[i],a[n-i-1]);
    manacher(a);
    for(int i = 1;i <= m;i ++) c[i] = b[i-1];
    for(int i = m+1;i <= n + m;i ++) c[i] = a[i-m-1]; c[n+m+1] = '\0';
    get_z(c);

    for(int i = m+1;i <= n + m;i ++) {
        LL x = min(z[i],m);
        sum[i-m-1] += x;
    }
    for(int i = 1;i < n;i ++) sum[i] += sum[i-1];
    LL ans = 0;
    for(int i = 1;i < len - 1;i ++) {
        int L = i / 2 + 1,R = (i + r[i]) / 2;
        ans += get_sum(L,R);
    }

    cout << ans << endl;
    return 0;
}
/**

*/

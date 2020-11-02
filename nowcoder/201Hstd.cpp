#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 500 + 10;
const int MOD = 1e9 + 7;
 
namespace {
  inline int add(int x) { return x >= MOD ? x - MOD : x; }
  inline int sub(int x) { return x < 0 ? x + MOD : x; }
  inline int mul(int x, int y) {
    return 1ll * x * y % MOD;
  }
  inline int pwr(int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = mul(x, x)) {
      if (y & 1) ans = mul(ans, x);
    }
    return ans;
  }
}
int n;
int p[MAXN];
int f[MAXN][MAXN];
int solve(int t) {
 
 
  //right part
 
  memset(f, 0, sizeof f);
 
  f[1][0] = p[t + 1];
 
  int tot = n - t;
  // f[cnt1][cnt0]
  for (int i = 2; i <= tot; i++) {
    for (int j = 0; j < i && t + i + j <= n; j++) {
      int pos = t + i + j;
      f[i][j] = add(mul(f[i - 1][j], p[pos]) +
                    mul(j ? f[i][j - 1] : 0, 1000 - p[pos]));
    }
  }
 
  int cnt0 = 0, cnt1 = 0;
  if (tot) {
    for (int i = 0; i <= tot; i++) {
      int j = tot - i;
      cnt0 = add(cnt0 + f[i][j]);
      cnt1 = add(cnt1 + mul(f[i][j], i));
    }
  } else {
    cnt0 = 1; cnt1 = 0;
  }
 
  //left part
 
  memset(f, 0, sizeof f);
 
  //f[cnt0][cnt1]
  //fprintf(stderr, "%d\n", t);
  f[0][0] = 1;
   
  for (int i = 1; i <= n - tot; i++) {
    for (int j = 0; j <= i && t - (i + j) >= 0; j++) {
      int pos = t - (i + j) + 1;
      f[i][j] = add(mul(f[i - 1][j], 1000 - p[pos]) +
                    mul(j ? f[i][j - 1] : 0, p[pos]));
    }
  }
 
  int cnt2 = 0, cnt3 = 0;
  for (int i = 1; i <= n - tot; i++) {
     
    int j = n - tot - i;
    cnt2 = add(cnt2 + mul(f[i][j], i));
    cnt3 = add(cnt3 + mul(f[i][j], mul(i, i)));
  }
  return add(mul(cnt0, cnt3) + mul(cnt1, cnt2));
 
   
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", p + i);
  }
 
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = add(ans + solve(i));
  }
 
  printf("%d\n", ans);
}

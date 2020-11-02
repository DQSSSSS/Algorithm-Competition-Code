#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  scanf("%d", &tt);
  for (int ttt = 1; ttt <= tt; ++ttt) {
    long long n, m, k, answer;
    scanf("%lld %lld %lld", &n, &m, &k);
    if (k == 1) {
      answer = m - 1;
    } else {
      answer = (k - 1) % (n - m + 1);
      for (long long i = n - m + 2; i <= n; ) {
        if (answer + k >= i) {
          answer = (answer + k) % i;
          ++i;
        } else {
          long long t = min(n - i + 1, (i - answer - 2) / (k - 1));
          answer += t * k;
          i += t;
        }
        cout << answer + 1 << endl;
      }
    }
    printf("Case #%d: %lld\n", ttt, answer + 1);
  }
  return 0;
}

/**
223092870
*/

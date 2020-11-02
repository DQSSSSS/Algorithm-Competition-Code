#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 2000;
const int L = 800;
const int M = 11 + 2 * (L + 1) * 10;

int n, len, m, low[L + 1], high[L + 1], fail[M], go[M][10], count[M][N + 1],
    dp[N + 1][M];
bool mark[N + 1][M];

int read_bigint(int *out) {
  static char buf[L + 2];
  scanf("%s", buf);
  int len = strlen(buf);
  for (int i = 0; i < len; ++i) {
    out[i] = buf[i] - '0';
  }
  return len;
}

void update(int &x, int a) { x = std::max(x, a); }

void gen(int i, bool has_started, bool is_greater, bool is_less, int u) {
  if (i == len || (is_greater && is_less)) {
    count[u][len - i]++;
  } else {
    for (int d = is_greater ? 0 : low[i]; d <= (is_less ? 9 : high[i]); ++d) {
      int uu = u;
      bool hs = has_started || d != 0;
      if (hs) {
        if (go[u][d] == -1) {
          go[u][d] = m++;
        }
        uu = go[u][d];
      }
      gen(i + 1, hs, is_greater || low[i] < d, is_less || d < high[i], uu);
    }
  }
}

int main() {
  freopen("H.in", "r", stdin);
  freopen("std.out", "w", stdout);
  int lenl = read_bigint(low);
  len = read_bigint(high);
  scanf("%d", &n);
  std::move_backward(low, low + lenl, low + len);
  std::fill(low, low + (len - lenl), 0);
  memset(go, -1, sizeof(go));
  m++;
  gen(0, false, false, false, 0);
  {
    std::queue<int> queue;
    for (int d = 0; d < 10; ++d) {
      int &v = go[0][d];
      if (~v) {
        fail[v] = 0;
        queue.push(v);
      } else {
        v = 0;
      }
    }
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      for (int j = 1; j <= n; ++j) {
        count[u][j] += count[u][j - 1];
      }
      for (int j = 0; j <= n; ++j) {
        count[u][j] += count[fail[u]][j];
      }
      for (int d = 0; d < 10; ++d) {
        int &v = go[u][d];
        if (~v) {
          fail[v] = go[fail[u]][d];
          queue.push(v);
        } else {
          v = go[fail[u]][d];
        }
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int u = 0; u < m; ++u) {
      if (dp[i][u] == -1) {
        continue;
      }
      for (int d = 0; d < 10; ++d) {
        int v = go[u][d];
        update(dp[i + 1][v], dp[i][u] + count[v][n - i - 1]);
      }
    }
  }
  int result = *std::max_element(dp[n], dp[n] + m);
  printf("%d\n", result);
  for (int j = 0; j < m; ++j) {
    mark[n][j] = dp[n][j] == result;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int u = 0; u < m; ++u) {
      for (int d = 0; d < 10; ++d) {
        int v = go[u][d];
        mark[i][u] |= ~dp[i][u] &&
                      dp[i][u] + count[v][n - i - 1] == dp[i + 1][v] &&
                      mark[i + 1][v];
      }
    }
  }
  for (int i = 0, u = 0; i < n; ++i) {
    for (int d = 0; d < 10; ++d) {
      int v = go[u][d];
      if (dp[i][u] + count[v][n - i - 1] == dp[i + 1][v] && mark[i + 1][v]) {
        printf("%d", d);
        u = v;
        break;
      }
    }
  }
  puts("");
}

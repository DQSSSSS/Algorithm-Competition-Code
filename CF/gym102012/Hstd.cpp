#include <bits/stdc++.h>

using namespace std;

const int N = 234567;

pair<pair<int, int>, int> a[N], events[N << 1];
int n, m, has[N], color[N], answer[N];

int main() {
  freopen("H.in", "r", stdin);
  freopen("std.out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &a[i].first.first, &a[i].first.second);
      a[i].second = i;
    }
    if (n < m) {
      puts("0");
    //  for (int i = 0; i < n; ++i) printf("1%c", i == n - 1 ? '\n' : ' ');
      continue;
    }
    sort(a, a + n);
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      q.push(make_pair(0, i));
    }
    for (int i = 0; i < n; ++i) {
      int x = q.top().second;
      q.pop();
      answer[a[i].second] = color[i] = x;
      q.emplace(-a[i].first.second, x);
    }
    int total = 0;
    for (int i = 0; i < n; ++i) {
      events[total++] = make_pair(make_pair(a[i].first.first, color[i]), 1);
      events[total++] = make_pair(make_pair(a[i].first.second, color[i]), -1);
    }
    sort(events, events + total);
    int result = 0, current = 0;
    for (int i = 0; i < total; ++i) {
      if (has[events[i].first.second]) {
        --current;
      }
      has[events[i].first.second] += events[i].second;
      if (has[events[i].first.second]) {
        ++current;
      }
      if (current == m) {
        result += events[i + 1].first.first - events[i].first.first;
      }
    }
    printf("%d\n", result);
    //for (int i = 0; i < n; ++i) printf("%d%c", answer[i] + 1, i == n - 1 ? '\n' : ' ');
  }
  return 0;
}

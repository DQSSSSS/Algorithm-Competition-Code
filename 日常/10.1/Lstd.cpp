#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n,...) for (int i = 1 , ##__VA_ARGS__ ; i <= n ; i++)
#define REP(i,n,...) for (int i = 0 , ##__VA_ARGS__ ; i < n ; i++)
#define LL long long
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair

const int MAXN = 100005;
int h[MAXN] , n , maxv;
set<pii> s1, s2;
LL ans , sum;
char op[3];

void init () {
  h[0] = h[n+1] = ans = sum = maxv = 0;
  FOR(i,n) sum += h[i];
  FOR(i,n) maxv = max(maxv,h[i]);
  FOR(i,n,cur=0) if (h[i] >= h[cur]) {
    ans += h[cur] * 1ll * (i-cur);
    cur = i;
    s1.insert(mp(i,h[i]));
  }
  for (int i = n , cur = n + 1 ; i ; i--)
    if (h[i] > h[cur]) {
      ans += h[cur] * 1ll* (cur-i);
      cur = i;
      s2.insert(mp(n-i+1,h[i]));
    }
  s1.insert(mp(0,0)); s2.insert(mp(0,0));
}

void era (set<pii>& s , int x) {
  auto it = s.lower_bound(mp(x,0));
  if (it == s.end() || it->x != x) return;
  int x1 = it->x , y1 = it->y , y0 = y1 ,flag = 0;
  it++; if (it != s.end()) x1 = it->x;
  else {flag = 1;}
  it--;
  if (it != s.begin()) {
    it--; y1 = it->y;
    if (flag) {
      y0 = y1+y1; x1 = x; x = it->x;
    }
    it++;
  }
  ans -= (y0-y1) * 1ll * (x1-x);
  s.erase(it);
}

void ins (set<pii>& s , int x , int y) {
  int xx = x , yy = y;
  auto it = s.lower_bound(mp(x,y));
  int x1 = x , y1 = y , flag = 0;
  if (it != s.end()) x1 = it->x;
  else {
    it--; x = it->x ;it++; flag = 1;
  }
  if (it != s.begin()) {
    it--; y1 = it->y; it++;
    if (flag) y = y1 + y1;
  }
  ans += (y-y1) * 1ll * (x1-x);
  s.insert(mp(xx,yy));
}

void chg (int x , int y) {
  sum += y; h[x] = y += h[x]; maxv = max(maxv,y);
  era(s1,x);
  auto it = s1.lower_bound(mp(x,y));
  it--;
  if (it->y <= y) { it++;
    while (it != s1.end() && it->y < y) {
      era(s1,it->x);
      it = s1.lower_bound(mp(x,y));
    }
    ins(s1,x,y);
  }

  x = n + 1 - x;
  era(s2,x);
  it = s2.lower_bound(mp(x,y));
  it--;
  if (it->y < y) { it++;
    while (it != s2.end() && it -> y <= y) {
      era(s2,it->x);
      it = s2.lower_bound(mp(x,y));
    }
    ins(s2,x,y);
  }
}

int main (void) {
  int t , q ; cin >> t; FOR(Cas,t) {
    s1.clear() , s2.clear();
    cin >> n >> q;
    FOR(i,n) scanf("%d",h+i);
    init();
    FOR(i,q,x,y) {
      scanf("%s",op);
      if (op[0] == 'P') printf("%lld\n",ans-sum+maxv);
      else {
        scanf("%d%d",&x,&y);
        chg(x,y);
      }
    }
  }
  return 0;
}

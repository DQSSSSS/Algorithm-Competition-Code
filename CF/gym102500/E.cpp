#include <bits/stdc++.h>
using namespace std;
int t[4], tt;
int read() {
    int x, y; scanf("%d.%d", &x, &y);
    return x * 100 + y;
}
int avg(int l, int r) {
    int ans = 0;
    for(int i = l; i <= r; i++) ans += t[i];
    return ans;
}
int main() {
    for(int i = 0; i < 4; i++) t[i] = read();
    tt = read() * 3;
    sort(t, t + 4);
    if(avg(1, 3) <= tt) cout << "infinite" << endl;
    else if(avg(0, 2) <= tt && tt <= avg(1, 3)) cout << fixed << setprecision(2) << (tt / 3. - t[1] - t[2]) / 100. << endl;
    else cout << "impossible" << endl;
    return 0;
}

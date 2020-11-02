#include <bits/stdc++.h>
using namespace std;
using Point = pair<int, int>;
#define x first
#define y second
using ll = long long;
const int N = 1000 + 5;
Point p[N];
int sgn(double x) {
    if(fabs(x) < 1e-6) return 0;
    else return x > 0 ? 1 : -1;
}
struct LINE {
    double k, b;
    bool operator == (const LINE &t) const {
        return sgn(k - t.k) == 0 && sgn(b - t.b) == 0;
    }
    bool operator < (const LINE &t) const {
        return sgn(k - t.k) == 0 ? sgn(b - t.b) < 0 : sgn(k - t.k) < 0;
    }
};
vector<LINE> Line;
vector<int> tline;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) {
            if(p[i].x == p[j].x) tline.push_back(p[i].x);
            else {
                double k = 1.0 * (p[j].y - p[i].y) / (p[j].x - p[i].x);
                double b = p[i].y - k * p[i].x;
                Line.push_back({k, b});
            }
        }
    sort(Line.begin(), Line.end());
    Line.resize(unique(Line.begin(), Line.end()) - Line.begin());
    sort(tline.begin(), tline.end());
    tline.resize(unique(tline.begin(), tline.end()) - tline.begin());
    ll ans = 0, m = Line.size() + tline.size();
    int pre = 0;
    for(int i = 0; i < Line.size(); i++)
        if(i+1==Line.size() || Line[i].k == Line[pre].k) continue;
        else {
            int c = i - pre;
            if(i+1==Line.size()) c++;
            ans += c * (m - c);
            pre = i;
        }
    //cout << Line.size() << " " << tline.size() << endl;
    int c = Line.size() - pre;
    ans += c * (m - c);
    c = tline.size();
    ans += c * (m - c);

    cout << ans / 2 << endl;
    return 0;
}

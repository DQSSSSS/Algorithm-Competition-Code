#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;
const double eps = 1e-6;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

vector<pair<double,int> > f,z,l;
vector<int> ans;
double a[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        double x; scanf("%lf",&x);
        a[i] = x;
        if(fabs(x) < eps) l.push_back(make_pair(0,i));
        else if(x < 0) f.push_back(make_pair(x,i));
        else z.push_back(make_pair(x,i));
    }

    sort(l.begin(),l.end());

    if(n == 1) return printf("%d\n%d",1,1),0;
    if(f.size() == 0 && z.size() == 0) return printf("%d\n%d",1,1),0;
    if(z.size() == 0) {
        if(f.size() == 1) {
            if(l.size() == 0) return printf("%d\n%d",1,1),0;
            else return printf("%d\n%d",1,l[0].second),0;
        }
    }

    sort(f.begin(),f.end());
    sort(z.begin(),z.end());

    for(int i = z.size() - 1;i >= 0;i --) {
        if(z[i].first > 1 + eps) ans.push_back(z[i].second);
    }

    for(int i = 0;i + 1 < f.size();i += 2) {
        if(f[i].first < -1 - eps) {
            if(f[i+1].first < -1-eps || f[i].first * f[i+1].first > 1 + eps)
                ans.push_back(f[i].second),ans.push_back(f[i+1].second);
        }
    }

    if(ans.size() == 0) {
        if(z.size() == 0)
            ans.push_back(f[0].second),ans.push_back(f[1].second);
        else if(f.size() < 2) ans.push_back(z[z.size()-1].second);
        else {
            if(f[0].first * f[1].first > z[z.size()-1].first + eps)
                ans.push_back(f[0].second),ans.push_back(f[1].second);
            else
                ans.push_back(z[z.size()-1].second);
        }
    }

    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i = 0;i < ans.size();i ++) printf("%d ",ans[i]);
}


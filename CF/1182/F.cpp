#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1073741823 + 10;
const int mod = 998244353;
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

int a,b,p,q;

int f(int x) {
    return 2ll * p * x % (2 * q);
}

int baoli() {
    int mind = 2e9 + 10,ans;
    for(int i = a;i <= b;i ++) {
        if(abs(f(i) - q) < mind)
            mind = abs(f(i) - q),ans = i;
    }
    cout << mind << endl;
    return ans;
}

mt19937 rd(time(0));

int main() {
    int T = read();
    while(T --) {
        a = read(),b = read(),p = read(),q = read();
       // a = rd() % 100000,b = rd() % 100000,p = rd() % 100000,q = rd() % 100000; if(a>b) swap(a,b);
        vector<pii> num2,num;
        int t = sqrt(b-a+1);
        for(int i = 0;i < t;i ++) {
            num2.push_back(make_pair(f(a+i),a+i));
        }
        sort(num2.begin(),num2.end());
        for(int i = 0,j = 0;i < num2.size();i ++) {
            if(i+1 == num2.size() || num2[i+1].first != num2[i].first) {
                num.push_back(num2[j]);
                j = i + 1;
            }
        }

        int mind = 2e9 + 10,ans = 1e9 + 1;
        for(int i = 0;i < t;i ++) {
            int goal = (q - 2ll * p * t * i % (2*q) + 2*q) % (2*q);
            int id = lower_bound(num.begin(),num.end(),make_pair(goal,0)) - num.begin();
            //cout << i << " " << a+t*i << endl;
            if(id == num.size()) id = 0;
            if(id < num.size()) {
                int x = t*i + num[id].second,d = abs(f(x) - q);
                if(d < mind || (d == mind && x < ans))
                    mind = d,ans = x;
            }
            if(id > 0) id --;
            else id = num.size()-1;
            int x = t*i + num[id].second,d = abs(f(x) - q);
            if(d < mind || (d == mind && x < ans))
                mind = d,ans = x;
        }

        for(int i = a + t * t;i <= b;i ++) {
            int x = i,d = abs(f(x) - q);
            if(d < mind || (d == mind && x < ans))
                mind = d,ans = x;
        }

      //  cout << mind << endl;
        printf("%d\n",ans);

      //  int bl = baoli();
      //  printf("%d\n",bl);
       // if(ans != bl) { printf("%d %d %d %d\n",a,b,p,q); assert(0); }
    }
}
/**
233
87454 87806 61431 57096
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 2e5 + 10;
const int mod = 1e9+7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a=='-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n=n*10+a-'0'; a = getchar(); }
    if(flag) n=-n;
    return n;
}

mt19937 rd(2333);

LL randlr(LL l,LL r)  {
    return rd()%(r-l+1)+l;
}

vector<int> a;

int work(double r) {
    a.clear();
    double now = 0;
    int sum = 0;
    while(fabs(now-r) > 1e-9) {
        int k = 1/(r-now); if((r-now)*k<1) k++;
        k += randlr(0,5);
        now += 1.0/k;
        sum += k;
        a.push_back(k);
      //  printf("%.10f %d\n",now,k);
    }
   // puts("finish");
    return sum;
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
//        double r = randlr(1e7,9e7)/1e7;
        double r;
        scanf("%lf",&r);
        printf("Case %d:\n",++ cc);
        for(int i = 1;;i ++){
            int sum = work(r);
            if(sum <= 1e4) {
                int m = sum - 1;
                printf("%d %d\n",sum,m);
                int t = sum-1,lst = 0;
             //   for(int x : a) cout << x << " "; puts("");
                vector<int> b;
                for(int x : a) {
                    printf("1 %d %d\n",lst,lst+1);
                    lst+=2; t ++; x --;
                    while(x -- > 1) printf("1 %d %d\n",lst,t),lst++,t++;
                    b.push_back(t);
                }
                int x = a.size();
                if(x>1) {
                    printf("0 %d %d\n",b[0],b[1]); t++;
                    for(int j = 2;j < b.size();j ++)
                        printf("0 %d %d\n",b[j],t),t++;
                }
                break;
            }
        }
    }
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,w[104],nn;
int b[104];
int c100;

bool cpo(int x,int c10,int c20,int c50){
    for(int ca=0;ca<=c10;ca++){
        for(int cb=0;cb<=c20;cb++){
            for(int cc=0;cc<=c50;cc++){
                if(ca*10+cb*20+cc*50==x){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int check(int c10,int c20,int c50){
    bool use[210] = {};
    for(int ca=0;ca<=c10;ca++){
        for(int cb=0;cb<=c20;cb++){
            for(int cc=0;cc<=c50;cc++){
                int t = ca*10+cb*20+cc*50;
                use[t] = 1;
            }
        }
    }
    int ans = -1;
    for(int i = 1;i <= n;i ++) {
        int x = w[i] % 100;
        int t = 1e9;
        for(int j = x;j <= 200;j += 100) {
            if(use[j]) {
                t = min(t,(w[i]-j)/100);
            }
        }
        ans = max(ans,t);
    }
    return ans;
}

int w33ha(){
    scanf("%d",&n);
    bool flag=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(w[i]%10)flag=1;
    }
    if(flag)return puts("-1"),0;
    int ans = 1e9;
    for(int sum = 0;sum <= 4;sum ++) {
        for(int c10 = 0;c10 <= sum;c10 ++) {
            for(int c20 = 0;c20 <= sum - c10;c20 ++) {
                for(int c50 = 0;c50 <= sum - c10 - c20;c50 ++) {
                    int t = check(c10,c20,c50);
                    if(t < 1e9) {
                        ans = min(ans,t+sum);
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
int main(){
    int T;scanf("%d",&T);
    while(T--)w33ha();
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
using namespace std;
ll m;
ll f[304];
vector<pa>ans;
int w33ha(){
    ans.clear();
    memset(f,0,sizeof(f));
    f[0]=1;
    f[1]=1;
    //int a=0;
    int B = 0;
    for(ll i=0;i<=32;i++){
        if((m&(1LL<<i))){
            ans.push_back({B+1,199});
            ans.push_back({B+5,B+5});
            B += 6;
        }
        else{
            ans.push_back({B+3,B+3});
            B += 4;
        }
    }
    ans.push_back({197,197});
    ans.push_back({198,198});
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}

int main(){
    while(scanf("%lld",&m)!=EOF)w33ha();
    return 0;
}

#include<bits/stdc++.h>
#define LiangJiaJun main
#define ULL unsigned long long
#define ll long long
#define MOD 19991227LL
using namespace std;
int m;
char s[300004];
set<int>ex;
set<ll>tr[300004];
set<int>::iterator it;
ll bin[300004];
ll hs[300004];
int LiangJiaJun(){
    ex.clear();
    bin[0]=1;
    for(int i=1;i<=300000;i++)bin[i]=(bin[i-1]*26)%MOD;
    scanf("%d",&m);
    hs[0]=0;
    while(m--){
        int t;scanf("%d",&t);
        scanf("%s",s+1);
        int l=strlen(s+1);
        for(int i=1;i<=l;i++){
            hs[i]=(((hs[i-1]*26)%MOD)+(s[i]-'a'))%MOD;
        }
        if(t==1){
            tr[l].insert(hs[l]);
            if(tr[l].size()==1)ex.insert(l);
        }
        else if(t==2){
            tr[l].erase(hs[l]);
            if(tr[l].size()==0)ex.erase(l);
        }
        else{
            int ans=0;
            for(it=ex.begin();it!=ex.end();it++){
                int len=(*it);
                if(len>l)break;
                for(int i=1;i+len-1<=l;i++){
                    int L=i,R=i+len-1;
                    ll now=(hs[R]-((bin[len]*hs[L-1])%MOD)+MOD)%MOD;
                    if(tr[len].count(now)){
                        ++ans;
                    }
                }
            }
            printf("%d\n",ans);
            fflush(stdout);
        }
    }
    return 0;
}

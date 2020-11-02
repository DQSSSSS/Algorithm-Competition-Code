#include<bits/stdc++.h>
#define ll long long
#define pa pair<ll,int>
using namespace std;
struct Ds{
    bitset<110> b;
    bitset<110> f;
    ll sum;
    int maxid;
    Ds(){
        b.reset();
        f.reset();
        sum=maxid=0;
    }
};
bool operator <(const Ds &a,const Ds &b) {
    return a.sum > b.sum;
}
priority_queue<Ds>q;
bitset<110> mp[104];
int n,k;
char s[104];
ll w[104];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=n;j++){
            if(s[j] == '1')
                mp[i].set(j);
        }
    }
    for(int i=1;i<=n;i++){
        Ds o=Ds();
        o.sum=w[i];
        o.b.set(i);
        o.f = mp[i];
        o.maxid = i;
        q.push(o);
    }
    k--;
    if(k==0)return puts("0"),0;
    while((k--)&&(!q.empty())){
        Ds now=q.top();q.pop();
     //   cout << now.sum << " " << now.maxid << endl;
        if(!k)return printf("%lld\n",now.sum),0;
        for(int i=now.maxid+1;i<=n;i++){
            if(now.f.test(i)){
                Ds nt=now;
                nt.maxid = i;
                nt.b.set(i);
                nt.f &= mp[i];
                nt.sum += w[i];
                q.push(nt);
            }
        }
    }
    puts("-1");
    return 0;
}

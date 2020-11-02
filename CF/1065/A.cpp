#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>s;
void init()
{
    ll cnt=1;
    ll ans=2;
    s[0]=0;
    s[0]=0;
    while(cnt<=10000000000)
    {
        s[cnt]=ans;
        cnt=ans+cnt;
        ans++;
        //cout << cnt << endl;
    }
}
int main()
{
    init();
    ll n, m;
    cin >> n >> m;
    if(m==0)
    {
        cout << n << " " << n << endl;
        return 0;
    }
    if(n<=m*2)
    {
        cout << 0 << " ";
    }
    else cout <<  n-m*2 <<" ";
    map<ll,ll>::iterator it;
    it=s.begin();
    for(;it!=s.end();)
    {
        ll but=it->first;
        it++;
        if(m>but&&m<=it->first)
        {
            cout << n-(it->second) << endl;
            break;
        }
    }
    return 0;
}

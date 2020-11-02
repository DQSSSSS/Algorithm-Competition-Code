#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
using namespace std;
const ll INF=1e14;
int n;
map<string,int>mert;
string x,a[504];
ll roc[504][504];
int fr[504][504],fa[504][504];
ll mp[504][504];
int nt[504];
bool flag;
char ss[10004];
void lag(int f,char* mt){
    int l=strlen(mt);
    string s="";
    for(int i=7;i<l-1;i++){
        if(mt[i]==' ')continue;
        if(mt[i]==','){
            //cout<<f<<" "<<mert[s]<<endl;
            if(mert[s]==f){
                if(!flag){
                    cout<<s<<endl;
                    flag=1;
                }
            }
            //cout<<f<<" "<<mert[s]<<endl;
            mp[f][mert[s]]=roc[f][mert[s]]=1;
            s="";
        }
        else s+=mt[i];
    }
    //cout<<f<<" "<<mert[s]<<endl;
    if(mert[s]==f){
        if(!flag){
            cout<<s<<endl;
            flag=1;
        }
    }
    mp[f][mert[s]]=roc[f][mert[s]]=1;
}
void dfs(int f,int t){
    if(mp[f][t]==1){
            //cout<<a[f]<<" "<<a[t]<<" ";
        nt[f]=t;
        return ;
    }
    int mid=fr[f][t];
    dfs(f,mid);
    dfs(mid,t);

}
ll floyd(){
    ll ans=INF;
    int f=-1,t=-1;

    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){
            for(int j=1;j<k;j++){
                if(i==j)continue;
                if(roc[i][k]+roc[k][j]+mp[j][i]<ans){
                    fa[i][j]=k;
                    f=i;t=j;
                    ans=roc[i][k]+roc[k][j]+mp[j][i];
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][j]>mp[i][k]+mp[k][j]){
                    fr[i][j]=k;
                    //cout<<"fffrr"<<endl;
                    mp[i][j]=mp[i][k]+mp[k][j];
                }
            }
        }
    }
    if(ans==INF)return ans;
    dfs(t,fa[f][t]);
    int st=t;
    do{
        cout<<a[st]<<" ";
        st=nt[st];
    }while(st!=fa[f][t]);
    cout<<a[st]<<endl;
    return 0;
}
int main(){
    //freopen("I.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[i][j]=INF;
            roc[i][j]=INF;
            fr[i][j]=0;
            fa[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=a[i];
        mert[x]=i;
    }
    flag=0;
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++){
        int c;
        cin>>x>>c;
        int f=mert[x];
        for(int j=1;j<=c;j++){
            fgets(ss,10000,stdin);
            lag(f,ss);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(roc[i][j]==1&&roc[j][i]==1){
                if(!flag){
                    cout<<a[i]<<" "<<a[j]<<endl;
                    flag=1;
                }
            }
        }
    }
    if(flag){
        return 0;
    }
    ll ans=floyd();
    if(ans==INF)puts("SHIP IT");
    //fclose(stdout);
    return 0;
}
/**
5
a c d b e
a 1
import c
c 1
import a
d 1
import d
*/

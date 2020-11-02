#include<bits/stdc++.h>
using namespace std;

int n,x[100],num;

void check(){
    int tag=1;
    for(int i=1;i<n;i++){
        int tag1=1;
        for(int j=1;j<=i;j++){
            if (x[j]!=x[n-i+j]) tag1=0;
        }
        if (tag1==1) tag=0;
        if (tag==0) break;
    }
    if (tag==0) return;
    for(int i=1;i<=n;i++)
        cout<<x[i];
    cout<<endl;
    num++;
}

void dfs(int u){
    if (u==n+1){
        //for(int i=1;i<=n;i++)
        //cout<<x[i];
    //cout<<endl;
        check();
        return;
    }
    x[u]=1;
    dfs(u+1);
    x[u]=2;
    dfs(u+1);
}

int main(){
    while(cin>>n){
        num++;
        dfs(1);
        cout<<num<<endl;
    }
    return 0;
}

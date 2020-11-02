#include<bits/stdc++.h>
using namespace std;

int n;

long long x[100][100][2],y[10000],prim[100000];
int tot=0;

int check(int a){
    for(int i=1;i<=tot;i++)
        if (a%prim[i]==0) return 0;
    return 1;
}

int main(){
    scanf("%d",&n);
    for(int i=2;i<=10000;i++)
        if (check(i)) prim[++tot]=i;
    for(int i=1;i<=n;i++){
        x[i][1][0]=i*2-1;
        x[i][1][1]=i*2;
    }
    int num=0;
    for(int i=1;i<=n;i++)
        for(int j=2;j<=n;j++){
            num++;
            for(int k=1;k<i;k++){
                y[x[k][j][0]]=num;
                y[x[k][j][1]]=num;
            }
            for(int k=1;k<j;k++){
                y[x[i][k][0]]=num;
                y[x[i][k][1]]=num;
            }
            int cnt=0;
            for(int k=1;k<=2*n;k++){
                if (y[k]!=num) x[i][j][cnt++]=k;
                if (cnt==2) break;
            }
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%lld ",prim[x[i][j][0]]*prim[x[i][j][1]]);
        puts("");
    }
    return 0;
}

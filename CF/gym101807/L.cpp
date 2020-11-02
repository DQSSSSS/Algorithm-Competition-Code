#include<bits/stdc++.h>
#define LiangJiaJun main
using namespace std;
char mp[4][104];
int a,b,w;
void output(bool t){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=w;j++){
            if(mp[i][j]=='*'&&t)mp[i][j]='.';
            printf("%c",mp[i][j]);
        }
        puts("");
    }
}
int LiangJiaJun(){
    scanf("%d%d%d",&w,&a,&b);
    for(int i=1;i<=3;i++){
        for(int j=1;j<=w;j++){
            if(i==2&&j==1)mp[i][j]='X';
            else if(i==1&&j==a)mp[i][j]='A';
            else if(i==3&&j==b)mp[i][j]='B';
            else mp[i][j]='*';
        }
    }
    if(a==b){
        puts("Possible");
        output(1);
        return 0;
    }
    if(a>b){
        if(b == 1) return puts("Impossible"),0;
        int ans=-1;
        for(int i=max(b,3);i<=a;i++){
            if(2+b+2*(i-b)==a){
                ans=i;break;
            }
        }
        if(ans==-1)return puts("Impossible"),0;
        for(int i=1;i<a;i++)mp[1][i]='.';
        mp[2][ans]='.';
        for(int i=b+1;i<=ans;i++)mp[3][i]='.';
        puts("Possible");
        output(0);
    }
    else{
        if(a == 1) return puts("Impossible"),0;
        int ans=-1;
        for(int i=max(a,3);i<=b;i++){
            if(2+a+2*(i-a)==b){
                ans=i;break;
            }
        }
        if(ans==-1)return puts("Impossible"),0;
        for(int i=1;i<b;i++)mp[3][i]='.';
        mp[2][ans]='.';
        for(int i=a+1;i<=ans;i++)mp[1][i]='.';
        puts("Possible");
        output(0);
    }
    return 0;
}

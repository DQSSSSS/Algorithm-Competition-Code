#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,c;
double dis[25][25][2000];
double p[25][25];
struct poi{
    int a,b,c;
    double t;
    poi(){}
    poi(int aa,int bb,int cc,double tt){
        a=aa;
        b=bb;
        c=cc;
        t=tt;
    }
    friend bool operator<(poi a,poi b){
        return a.t>b.t;
    }
};
vector<poi> v[25][25][2000];
priority_queue<poi> q;
bool flag[25][25][2000];
double dy[2000];
int nx1[2000];
int nx2[2000];
int dcnt;
int main(){
	freopen("B.in","r",stdin);	freopen("Bstd.out","w",stdout);
    cin>>n>>m>>c;
    for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) cin>>p[i][j];
    for (int i=-40;i<=40;i++) for (int j=-20;j<=20;j++) if (i+j*sqrt(2)>-1e-8 && i+j*sqrt(2)<c+1e-8){
        dy[++dcnt]=i+j*sqrt(2);
    }
    //cout<<dcnt<<endl;
    sort(dy+1,dy+dcnt+1);
    for (int i=1;i<=dcnt;i++){
        for (int j=1;j<i;j++){
            if (fabs(dy[i]-dy[j]-1)<1e-7) nx1[i]=j;
            if (fabs(dy[i]-dy[j]-sqrt(2))<1e-7) nx2[i]=j;
        }
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) for (int a=1;a<=dcnt;a++){
        dis[i][j][a]=1e14;
         
         
    }
    dis[0][0][1]=0;
    q.push(poi(0,0,1,0));
    double ans=1e14;
    unsigned mxsz = 0;
    int rnd = 0;
    while (!q.empty()){
    	mxsz = max(mxsz,q.size());
        poi now=q.top();
        q.pop();
        if (flag[now.a][now.b][now.c]) continue;
        if (now.a==n&&now.b==m)
        {
            ans=min(ans,dis[now.a][now.b][now.c]);
            break;
        }
        flag[now.a][now.b][now.c]=1;
        int i=now.a,j=now.b,a=now.c;
        vector<poi> vt;
        //if (dy[a]>c) continue;
        //if (dy[a]<-1e7) continue;
        if (dy[a]>sqrt(2)-1e-7){
            if (i<n && j<m) vt.push_back(poi(i+1,j+1,nx2[a],0));
            if (i<n && j>0) vt.push_back(poi(i+1,j-1,nx2[a],0));
            if (i>0 && j<m) vt.push_back(poi(i-1,j+1,nx2[a],0));
            if (i>0 && j>0) vt.push_back(poi(i-1,j-1,nx2[a],0));
        }
        if (dy[a]>1-1e-7){
            if (i<n) vt.push_back(poi(i+1,j,nx1[a],0));
            if (j<m) vt.push_back(poi(i,j+1,nx1[a],0));
            if (i>0) vt.push_back(poi(i-1,j,nx1[a],0));
            if (j>0) vt.push_back(poi(i,j-1,nx1[a],0));
        }
        rnd ++;
        int t = 0;
        for (int na=a+1;na<=min(dcnt,a+1);na++) vt.push_back(poi(i,j,na,(dy[na]-dy[a])*p[i][j]));
        for (int i=0;i<vt.size();i++){
            poi edg=vt[i];
            if (edg.t+dis[now.a][now.b][now.c]<dis[edg.a][edg.b][edg.c]){
                dis[edg.a][edg.b][edg.c]=edg.t+dis[now.a][now.b][now.c];
                q.push(poi(edg.a,edg.b,edg.c,edg.t+now.t));
            	t ++;
            }
        }
        cout << rnd << " " << t << endl;
    }
    cout << mxsz << endl;
    printf("%.6f\n",ans);
    return 0;
}

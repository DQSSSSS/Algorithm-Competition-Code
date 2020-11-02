#include<cstdio>
#include<iostream>
#include<cstring>
#define Maxn 5010
using namespace std;
 
struct per{
    long long w;
    int p;
    per(long long ww=0,int pp=0):w(ww),p(pp){}
}q[Maxn];
int qs,qe,top;
char str[][20]={"Prior","Untop","Add","Close","Chat","Rotate","Choose","Top"};
char s[20];
void shift(int x){
    if(x==top) top=qs;
    else if(top<x&&top>=qs) top++;
    per tmp=q[x];
    for(int i=x;i>qs;i--)
        q[i]=q[i-1];
    q[qs]=tmp;
}
void remov(int x){
    if(top==x) top=-1;
    else if(top<x&&top>=qs) top++;
    for(int i=x;i>qs;i--)
        q[i]=q[i-1];
    qs++;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("Bstd.out","w",stdout);
    int t,n,x;
    scanf("%d",&t);
    while(t--){
        qs=0,qe=top=-1;
        scanf("%d",&n);
        for(int k=1;k<=n;k++){
            scanf("%s",s);
            printf("Operation #%d: ",k);
            if(strcmp(s,str[0])&&strcmp(s,str[1])){
                scanf("%d",&x);
                if(!strcmp(s,str[2])){ //add
                    bool flag=false;
                    for(int i=qs;i<=qe;i++)
                    if(q[i].p==x){flag=true;break;}
                    if(flag) puts("same priority.");
                    else{
                        q[++qe]=per(0,x);
                        puts("success.");
                    }
                }
                else if(!strcmp(s,str[3])){ //close
                    int cnt=-1;
                    for(int i=qs;i<=qe;i++)
                    if(q[i].p==x){cnt=i;break;}
                    if(cnt==-1) puts("invalid priority.");
                    else{
                        printf("close %d with %I64d.\n",x,q[cnt].w);
                        remov(cnt);
                    }
                }
                else if(!strcmp(s,str[4])){ //chat
                    if(qs>qe){
                        puts("empty.");
                    }
                    else{
                        if(top==-1) {puts("success.");q[qs].w+=x;}
                        else {puts("success.");q[top].w+=x;}
                    }
                }
                else if(!strcmp(s,str[5])){ //rotate
                    if(x>qe-qs+1||x<1) puts("out of range.");
                    else{
                        shift(qs+x-1);
                        puts("success.");
                    }
                }
                else if(!strcmp(s,str[6])){ //choose
                    int cnt=-1;
                    for(int i=qs;i<=qe;i++)
                    if(q[i].p==x){cnt=i;break;}
                    if(cnt==-1) puts("invalid priority.");
                    else{
                        shift(cnt);
                        puts("success.");
                    }
                }
                else{ //top
                    int cnt=-1;
                    for(int i=qs;i<=qe;i++)
                    if(q[i].p==x){cnt=i;break;}
                    if(cnt==-1) puts("invalid priority.");
                    else {top=cnt;puts("success.");}
                }
            }
            else{
                if(!strcmp(s,str[0])){ //prior
                    if(qs>qe) puts("empty.");
                    else{
                        puts("success.");
                        int maxx=-1,cnt=0;
                        for(int i=qs;i<=qe;i++){
                            if(q[i].p>maxx){maxx=q[i].p;cnt=i;}
                        }
                        shift(cnt);
                    }
                }
                else{ //untop
                    if(top==-1) puts("no such person.");
                    else{
                        top=-1;
                        puts("success.");
                    }
                }
            }
        }
        if(top!=-1&&q[top].w) printf("Bye %d: %I64d\n",q[top].p,q[top].w);
        for(int i=qs;i<=qe;i++)
            if(i!=top&&q[i].w) printf("Bye %d: %I64d\n",q[i].p,q[i].w);
    }
	return 0;
}


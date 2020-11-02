#include<cstdio>
#include<bitset>
#include<cstring>
#define nn 200003
using namespace std;
typedef long long ll;
ll ans;
int n,a[nn],b[nn],c[nn],A[nn],B[nn],C[nn],f[nn],tree[nn];
ll ask(int w){ll tem=0;
    for (int i=w;i;i-=i&(-i))tem+=1ll*tree[i];
    return tem;
    }
void add(int w){
    for (int i=w;i<=n;i+=i&(-i))tree[i]++;
    }
ll work(int c[],int d[]){ll tem=0;
    memset(tree,0,sizeof(tree));
    for (int i=1;i<=n;i++)f[c[i]]=i;
    for (int i=1;i<=n;i++)d[i]=f[d[i]];
    for (int i=n;i>=1;i--){
            tem+=ask(d[i]-1);
            add(d[i]);
            }
        return tem;
    }
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    scanf("%d",&a[i]),A[i]=a[i];
    for (int i=1;i<=n;i++)
    scanf("%d",&b[i]),B[i]=b[i];
    for (int i=1;i<=n;i++)
    scanf("%d",&c[i]),C[i]=c[i];
    ans+=work(a,b);
    for (int i=1;i<=n;i++)b[i]=B[i],c[i]=C[i];
    ans+=work(b,c);
    for (int i=1;i<=n;i++)a[i]=A[i],c[i]=C[i];
    ans+=work(a,c);
    printf("%I64d\n",((ll)n*(n-1)-ans)/2);
    return 0;
}

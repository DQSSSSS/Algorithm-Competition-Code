#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){int t,n;
    freopen("a.in","w",stdout);
    srand(time(0));
    t=1;printf("%d\n",t);
    n=20;
    while (t--){
    printf("%d\n",n);
    for (int i=1;i<=n;i++){
        printf("%d ",rand()%10+1);
        }printf("\n");
    }
  /*  int T = 1;
    cout << T << endl;*/ 
    
    return 0;
}

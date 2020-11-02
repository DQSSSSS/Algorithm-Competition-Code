#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 +10;

const int B = 2000;
const int N = 4000;
struct haha {
    struct grid {
        int add[3];
    }a[4040][4040];

    void add(int x,int y,int id,int d) {
        x += B; y += B;
     //   printf("add %d %d %d %d\n",x,y,id,d);
        a[x][y].add[id] += d;
    }

    LL work(){
        LL ans = 0;
        for(int i = 1;i <= N;i ++) {
            for(int j = 1;j <= N;j ++) {
                a[i+1][j].add[0] += a[i][j].add[0];
                a[i][j+1].add[0] += a[i][j].add[0];
                a[i+1][j+1].add[0] -= a[i][j].add[0];

                a[i+1][j].add[2] += a[i][j].add[2];
                a[i+1][j+1].add[2] += a[i][j].add[2];
                a[i+2][j+1].add[2] -= a[i][j].add[2];

                a[i+1][j].add[1] += a[i][j].add[1];
                a[i+1][j-1].add[1] += a[i][j].add[1];
                a[i+2][j-1].add[1] -= a[i][j].add[1];

                if(a[i][j].add[0] || a[i-1][j].add[2] + a[i-1][j].add[1] > 0) {
                    ans ++;
                   // printf("%d %d %d\n",i,j,k);
                }

                if(a[i][j].add[0] || a[i][j].add[2] + a[i-1][j].add[1] > 0) {
                    ans ++;
                   // printf("%d %d %d\n",i,j,k);
                }

                if(a[i][j].add[0] || a[i-1][j].add[2] + a[i][j].add[1] > 0) {
                    ans ++;
                   // printf("%d %d %d\n",i,j,k);
                }

                if(a[i][j].add[0] || a[i][j].add[2] + a[i][j].add[1] > 0) {
                    ans ++;
                   // printf("%d %d %d\n",i,j,k);
                }
            }
        }
        return ans;
    }

    void print() {
        for(int i = 1;i <= N;i ++) {
            for(int j = 1;j <= N;j ++) {
                printf("(%d,%d): ",i,j);
                for(int k = 0;k <= 2;k ++) {
                    printf("%d ",a[i][j].add[k]);
                }
                puts("");
            }
        }
    }

}data;

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        char s[2];
        int x,y,z;
        scanf("%s%d%d%d",s,&x,&y,&z);
        z /= 2;
        if(s[0] == 'A') {
            data.add(x-z,y-z+1,0,1);
            data.add(x-z,y+z+1,0,-1);
            data.add(x+z,y-z+1,0,-1);
            data.add(x+z,y+z+1,0,1);
        }
        else {
            data.add(x-z,y,1,1);  data.add(x-z,y+1,2,1);
            data.add(x,y-z,1,-1); data.add(x,y-z+1,2,-1);
            data.add(x,y+z,1,-1); data.add(x,y+z+1,2,-1);
            data.add(x+z,y,1,1);  data.add(x+z,y+1,2,1);
        }
    }
    double ans = data.work() / 4.0;
  //  data.print();
    printf("%.2f\n",ans);
}
/*
1
B 1 0 2
*/

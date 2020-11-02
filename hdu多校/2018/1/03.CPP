#include<bits/stdc++.h>
using namespace std;

const int SZ = 100010;
const int INF = 1000000010;
const int MOD = 1000000007;

#define first x
#define second y

struct haha {
	int x,y,id;
}a[SZ];

bool cmp(haha a,haha b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int n;

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
		scanf("%d",&n);
        for(int i = 1;i <= 3 * n;i ++)
			scanf("%d%d",&a[i].x,&a[i].y),a[i].id = i;
        sort(a + 1,a + 1 + 3 * n,cmp);
        for(int i = 0;i < n;i ++)
			printf("%d %d %d\n",a[3 * i + 1].id,a[3 * i + 2].id,a[3 * i + 3].id);
    }
	return 0;
}


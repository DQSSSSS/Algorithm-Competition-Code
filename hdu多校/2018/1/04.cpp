#include<bits/stdc++.h>
using namespace std;

const int SZ = 100010;
const int INF = 1000000010;
const int MOD = 1000000007;

struct haha {
	int x,y;
}a[SZ];

bool cmp(haha a,haha b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int n,m,ans[SZ];
set<int> s;

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
		s.clear();
		scanf("%d%d",&n,&m);
        int mm = 0;
        for(int i = 1;i <= m;i ++)
			scanf("%d%d",&a[i].x,&a[i].y),mm = max(mm,a[i].y - a[i].x + 1);
        sort(a + 1,a + 1 + m,cmp);
		for(int i = 1;i <= mm;i ++) s.insert(i);
        int j = 1;
        for(int i = 1,p = 1;i <= m;i ++) {
        	while(j < a[i].x) ans[j ++] = 1;
        	while(p < a[i].x)
                s.insert(ans[p ++]);

            while(j <= a[i].y) {
                ans[j] = *s.begin();
				s.erase(s.begin());
				j ++;
			}
			//cout << i <<endl;
		}
		while(j <= n) ans[j ++] = 1;
		for(int i = 1;i <= n;i ++) printf("%d%c",ans[i],i == n ? '\n' : ' ');
    }
	return 0;
}
//1 2 3 4 1
//1 2 3 1 4

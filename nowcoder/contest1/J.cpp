#include<bits/stdc++.h>
using namespace std;

const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

int tree[SZ],n,m;
int ans[SZ];

void add(int x,int d) {
	if(x == 0) return ;
    for(int i = x;i <= n;i += i & -i)
		tree[i] += d;
}

int askSum(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
		ans += tree[i];
	return ans;
}

struct haha {
	int l,r,id,b;
}ask[SZ];

bool cmp(haha a,haha b) {
	return a.l < b.l;
}

struct hhh {
    int x,y,id;
}l[SZ],ask2[SZ];

bool cmp2(hhh a,hhh b) {
    return a.x == b.x ? a.y > b.y : a.x < b.x;
}

int nx[SZ],a[SZ];
map<int,int> mp;

int main() {
	while(~scanf("%d%d",&n,&m)) {
        mp.clear();
        for(int i = 1;i <= n;i ++) scanf("%d",&a[i]),tree[i] = ans[i] = 0;
        for(int i = n;i >= 1;i --)
            nx[i] = mp[a[i]],mp[a[i]] = i;
		for(int i = 1;i <= n;i ++)
			if(mp[a[i]] == i)
				add(i,1);
		int totm = 0;
        for(int i = 1;i <= m;i ++) {
			int L,R;
			scanf("%d%d",&L,&R);
			ask[++ totm] = (haha){1,L,i,1};
			ask[++ totm] = (haha){R,n,i,1};
			ask2[i] = (hhh){L,R,i};
        }
        sort(ask + 1,ask + 1 + totm,cmp);
        for(int i = 1,j = 1;i <= totm;i ++) {
			while(j <= n && j < ask[i].l)
                add(j,-1),add(nx[j],1),j ++;
            if(ask[i].r < ask[i].l) continue;
            ans[ask[i].id] += (askSum(ask[i].r) - askSum(ask[i].l - 1)) * ask[i].b;
        }

		for(int i = 1;i <= n;i ++) tree[i] = 0;

		int tot2 = 0;
        for(int i = 1;i <= n;i ++)
		{
            if(i != mp[a[i]]) continue;
            int L = i,p = i;
            while(nx[p] != 0) p = nx[p];
			l[++ tot2] = (hhh){L,p};
		}
		sort(l + 1,l + 1 + tot2,cmp2);
		sort(ask2 + 1,ask2 + 1 + m,cmp2);
        for(int i = 1,j = 1;i <= m;i ++) {
			while(j <= tot2 && (l[j].x < ask2[i].x || (l[j].x == ask2[i].x && l[j].y >= ask2[i].y)))
                add(l[j].y,1),j ++;
		//	cout << ask2[i].id << " " << askSum(n) - askSum(ask2[i].y - 1) << endl;
            ans[ask2[i].id] -= askSum(n) - askSum(ask2[i].y - 1);
        }

        for(int i = 1;i <= m;i ++)
			printf("%d\n",ans[i]);
	}
	return 0;
}

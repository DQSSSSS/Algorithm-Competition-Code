#include<bits/stdc++.h>
using namespace std;

const int SZ = 5e5 + 10;

int ch[SZ][2],intree[SZ],sz[SZ],tot = 0,fa[SZ],n,a[SZ];

void insert(int x,int id) {
	int p = 0; sz[0] ++;
	for(int i = 30;i >= 0;i --) {
		int c = x >> i & 1;
		if(!ch[p][c]) {
			ch[p][c] = ++ tot,fa[tot] = p;
		}
		p = ch[p][c];
		sz[p] ++;
	}
	intree[id] = p;
}

void del(int id) {
	int p = intree[id];
	while(p) sz[p] --,p = fa[p];
	sz[0] --;
}

int ask(int x) {
	int now = 0,p = 0;
	for(int i = 30;i >= 0;i --) {
		int c = x >> i & 1;
	//	cout << p << " " << sz[p] << " " << now << endl;
		//if((i != 30 && !p) || !sz[p]) break;
		if(ch[p][c ^ 1] && sz[ch[p][c ^ 1]]) {
			now |= (c ^ 1) << i;	p = ch[p][c ^ 1];	
		}
		else if(ch[p][c] && sz[ch[p][c]]){
			now |= c << i;	p = ch[p][c];
		}
		else break;
	}
	//cout << now << " "<< x << endl;
	return now ^ x;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		for(int i = 0;i <= tot;i ++) fa[i] = ch[i][0] = ch[i][1] = sz[i] = 0;
		tot = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++) {
			scanf("%d",&a[i]); 
			insert(a[i],i);
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++) {
			del(i);
			for(int j = i + 1;j <= n;j ++) {
				del(j);
				int x = ask(a[i]+a[j]);
				ans = max(ans,x);
			//	cout << i << " " << j << " " << x << endl;
			//	puts("---");
				insert(a[j],j);
			}
			insert(a[i],i);
		}
		/*int ans2 = 0;
		for(int i = 1;i <= n;i ++)
			for(int j = i + 1;j <= n;j ++)
				for(int k = 1;k <= n;k ++)
					if(k != i && k != j)
						ans2 = max(ans,(a[i]+a[j])^a[k]);
				
		printf("%d\n",ans2);*/
		printf("%d\n",ans);
	}
	return 0;
}


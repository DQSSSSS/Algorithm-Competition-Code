#include <bits/stdc++.h>
#define maxn 100010
#define inf 0x3f3f3f3f
#define REP(i,x,y) for(int i=x;i<(y);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,A,B;
pii pp[maxn],bpp[maxn];
priority_queue<pii>ause;
struct P{
	int A,B,det;
	P(){}
	P(int A,int B,int det):A(A),B(B),det(det){}
	
	bool operator < (const P& a) const {
		return det<a.det;
	}
};


priority_queue<P>det;
multiset<pii>buse;
int main()
{
	scanf("%d %d %d",&n,&A,&B);
	for(int i=1;i<=n;i++) scanf("%d",&pp[i].first);
	for(int i=1;i<=n;i++) scanf("%d",&pp[i].second);
	REP(i,1,n+1) ause.push(pp[i]);
	REP(i,1,n+1) {
		bpp[i]=pp[i];
		swap(bpp[i].first,bpp[i].second);
		buse.insert(bpp[i]);
	}
	ll ans=0;
	for(int i=n;i>n-A;i--) {
		pii now=ause.top();
		//cout<<now.first<<" "<<now.second<<endl;
		if(now.first<0) break;
		ause.pop();
		pii tmp=make_pair(now.second,now.first);
		buse.erase(buse.find(tmp));
		//cout << buse.size() << endl;
		ans+=now.first;
		det.push(P(now.first,now.second,now.second-now.first));
	}	
	multiset<pii>::iterator it=buse.end();
	it--;
	int cnt=0;
	while(cnt<B&&det.top().det>0) {
		ans+=det.top().det;
		det.pop();
		cnt++;
	}
	for(;cnt<=B;it--) {
		pii now=*it;
		ll tmp1=0;
		if(now.first<0) break;
		cnt++;
		if(!det.empty()) {
			P tmp=det.top();
			//cout<<tmp.A<<" "<<tmp.B<<" "<<tmp.det<<endl;
			tmp1=tmp.det+now.second;
			//cout<<tmp1<<endl;
			if(tmp1>now.first) {
				ans+=tmp1;
				det.pop();
				det.push(P(now.second,now.first,now.first-now.second));
			}
			else {
				ans+=now.first;
				
			}
		}
		else ans+=now.first;
		if(it==buse.begin()) break;
	}
	while(cnt<B&&det.top().det>0) {
		ans+=det.top().det;
		det.pop();
		cnt++;
	}
	cout<<ans<<endl;
}

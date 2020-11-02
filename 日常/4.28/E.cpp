#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int a[SZ];

int work(int l,int r)
{
	if(l == r) return 0;
	if(r == l + 1) return 0;
	if(a[l + 1] > a[l + 2]) return 0;
	int p = l + 1;
	while(p < r && a[p + 1] > a[p]) p ++;
	int pp = p;
	while(pp < r && a[pp + 1] < a[pp]) pp ++;
	int num = p - l + 1;
	return (num & 1);
}

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		cin >> n;
		for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
		int pos = 0;
		for(int i = 1;i <= n;i ++)  if(a[i] == 1) pos = i;
		int a = work(pos,n);
		for(int i = 1;i <= pos;i ++) swap(::a[i],::a[pos - i + 1]);
		int b = work(1,pos);
		cout << a << " " << b << " " << endl;
		if(a ^ b) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
/*
5
1 2 3 5 4
*/

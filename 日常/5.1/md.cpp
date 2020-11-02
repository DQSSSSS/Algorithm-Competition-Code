#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

int main()
{
	freopen("haha.txt","w",stdout);
	srand(time(0));
	int n = rand() % 10000 +1,T = rand() % 10000 + 1;
	cout << n << " " << T << endl;
	for(int i = 1;i <= n;i ++)
	{
		int x = rand() % 10000,y = rand() % 10000;
		int opt = rand() % 4;
		char c;
		if(opt == 0) c = 'U';
		if(opt == 1) c = 'D';
		if(opt == 2) c = 'L';
		if(opt == 3) c = 'R';
		cout << x << " " << y << " " << c << endl;
	}
	return 0;
}

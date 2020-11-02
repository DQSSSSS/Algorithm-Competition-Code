#include<bits/stdc++.h>
using namespace std;

const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

struct haha{
	int x,y;
	haha(int a,int b) :x(a),y(b){}
	void print() { printf("(%d,%d)",x,y); }
};

bool operator <=(haha a,haha b) {
	return a.x <= b.x && a.y <= b.y;
}

int C[1010][1010];

int get(haha a,haha b) {
	int n = a.x - b.x;
	int m = b.y - a.y;
	if(n < 0 || m < 0) return 0;
	return C[n + m][n];
}

int get(haha is,haha ie,haha js,haha je) {
	return get(is,ie) * get(js,je) - get(is,je) * get(js,ie) / 2;
}

int ask(int n,int m) {
	//return get((haha){n-1,0},(haha){0,m-1},(haha){n,1},(haha){1,m}) + get((haha){n-1,0},(haha){1,m},(haha){n,1},(haha){0,m-1});
	return get((haha){n,0},(haha){0,m},(haha){n,0},(haha){0,m});

	int ans = 0;
    for(haha is = (haha){n-1,0};is <= (haha){n-1,0};is.x ++)
		for(haha ie = (haha){0,m-1};ie <= (haha){0,m-1};ie.y ++)
			for(haha js = (haha){n,1};js <= (haha){n,1};js.y ++)
				for(haha je = (haha){1,m};je <= (haha){1,m};je.x ++) {
					int tmp = get(is,ie) + get(js,je) - get(is,je) - get(js,ie);
                    ans += tmp;
                    /*
                    is.print();printf("->");ie.print();printf("=%d\n",get(is,ie));
                    js.print();printf("->");je.print();printf("=%d\n",get(js,je));
                    is.print();printf("->");je.print();printf("=%d\n",get(is,je));
                    js.print();printf("->");ie.print();printf("=%d\n",get(js,ie));
                    cout << tmp <<endl;
                    puts("");
					*/
				}
	return ans;
}

int main() {
	C[0][0] = 1;
	for(int i = 1;i <= 1000;i ++)
		for(int j = 0;j <= i;j ++)
			if(j == 0) C[i][j] = 1;
			else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    for(int i = 1;i <= 10;i ++,puts(""))
		for(int j = 1;j <= 10;j ++)
			printf("%8d",ask(i,j));
	return 0;
}


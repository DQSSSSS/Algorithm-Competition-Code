#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

char mp[22][22],tmp[22][22],tp[22][22];
void print() {
	for(int i = 0;i < 16;i ++,puts(""))
		for(int j = 0;j < 16;j ++)
			cout << mp[i][j] << " ";
	puts("");
}

void print(int x) {
	for(int i = 15;i >= 0;i --)
		cout << (x >> i & 1); puts("");
}

int get(char c) {
	if('0' <= c && c <= '9') return c - '0';
	else return c - 'A' + 10;
}

void rot(int x,int y) {
    for(int i = x;i < x + 4;i ++)
    	for(int j = y;j < y + 4;j ++) {
            int dx = i - x,dy = j - y;
            tmp[dy][4 - dx - 1] = mp[i][j];
    	}
    for(int i = x;i < x + 4;i ++)
    	for(int j = y;j < y + 4;j ++)
    		mp[i][j] = tmp[i - x][j - y];
}

int getit(char a,char b,char c,char d) {
	return (1 << get(a)) | (1 << get(b)) | (1 << get(c)) | (1 << get(d));
}

int check() {
	int ans = 0;
	for(int i = 0,f = 0;i < 12;i ++) {
        int d = 0;
        for(int j = 0;j < 12;j ++) {
        	char c = mp[i][j];
        	if(d & (1 << get(c))) return -1;
            d |= 1 << get(c);
        }
        if(i % 4 == 0) f = 1;
        int p = 0;
       // cout << i << endl;
       // print(getit(mp[i][12],mp[i][13],mp[i][14],mp[i][15]));
       // printf(" ");
       // print(d);
       // cout << (getit(mp[i][12],mp[i][13],mp[i][14],mp[i][15]) & d) << endl;
        //puts("");

        while(getit(mp[i][12],mp[i][13],mp[i][14],mp[i][15]) & d) {
        	ans ++;
        	p ++;
        	if(f && i % 4) return -1;
            rot(i / 4 * 4,12);
            if(p == 4) return -1;
        }
	}
	//print();
	for(int j = 0,f = 0;j < 12;j ++) {
        int d = 0;
        for(int i = 0;i < 12;i ++) {
        	char c = mp[i][j];
        	if(d & (1 << get(c))) return -1;
            d |= 1 << get(c);
        }
        if(j % 4 == 0) f = 1;
        int p = 0;
        while(getit(mp[12][j],mp[13][j],mp[14][j],mp[15][j]) & d) {
        	ans ++;
        	p ++;
            if(f && j % 4) return -1;
            rot(12,j / 4 * 4);
            if(p == 4) break;
        }
        if(p == 4) return -1;
	}
	int d = 0;
	for(int j = 0;j < 12;j ++) {
		char c = mp[12][j];
		if(d & (1 << get(c))) return -1;
		d |= 1 << get(c);
	}
	int p = 0;
	while(getit(mp[12][12],mp[12][13],mp[12][14],mp[12][15]) & d) {
		ans ++;
		p ++;
		rot(12,12);
		if(p == 4) break;
	}
	if(p == 4) return -1;

	for(int i = 12;i < 16;i ++) {
        int d = 0;
        for(int j = 0;j < 16;j ++) {
        	char c = mp[i][j];
        	if(d & (1 << get(c))) return -1;
            d |= 1 << get(c);
        }
    }

    for(int j = 12;j < 16;j ++) {
        int d = 0;
        for(int i = 0;i < 16;i ++) {
        	char c = mp[i][j];
        	if(d & (1 << get(c))) return -1;
            d |= 1 << get(c);
        }
    }

	return ans;
}

int ans;

void dfs(int d,int num) {
	if(d == 3) {
		for(int i = 0;i < 4;i ++) {
			int d = 0;
			for(int j = 0;j < 12;j ++) {
				char c = mp[i][j];
				if(d & (1 << get(c))) return ;
				d |= 1 << get(c);
			}
		}
	}
	else if(d == 6) {
		for(int i = 4;i < 8;i ++) {
			int d = 0;
			for(int j = 0;j < 12;j ++) {
				char c = mp[i][j];
				if(d & (1 << get(c))) return ;
				d |= 1 << get(c);
			}
		}
	}
	else if(d == 7) {
		for(int j = 0;j < 4;j ++) {
			int d = 0;
			for(int i = 0;i < 12;i ++) {
				char c = mp[i][j];
				if(d & (1 << get(c))) return ;
				d |= 1 << get(c);
			}
		}
	}
	else if(d == 8) {
		for(int j = 4;j < 8;j ++) {
			int d = 0;
			for(int i = 0;i < 12;i ++) {
				char c = mp[i][j];
				if(d & (1 << get(c))) return ;
				d |= 1 << get(c);
			}
		}
	}
	else if(d == 9) {
		for(int i = 8;i < 12;i ++) {
			int d = 0;
			for(int j = 0;j < 12;j ++) {
				char c = mp[i][j];
				if(d & (1 << get(c))) return ;
				d |= 1 << get(c);
			}
		}
		for(int j = 8;j < 12;j ++) {
			int d = 0;
			for(int i = 0;i < 12;i ++) {
				char c = mp[i][j];
				if(d & (1 << get(c))) return ;
				d |= 1 << get(c);
			}
		}
		//print();
		for(int i = 0;i < 16;i ++)
			for(int j = 0;j < 16;j ++)
				tp[i][j] = mp[i][j];
		int a = check();
		for(int i = 0;i < 16;i ++)
			for(int j = 0;j < 16;j ++)
				mp[i][j] = tp[i][j];
		if(a != -1)
			ans = min(ans,a + num);
		return ;
	}
	if(num >= ans) return ;
	//print();
	for(int i = 0;i <= 3;i ++) {
        dfs(d + 1,num + i);
        rot(d / 3 * 4,d % 3 * 4);
	}
}

int main() {
	int T = read();
    while(T --) {
		for(int i = 0;i < 16;i ++)
			scanf(" %s",mp[i]);
		//print();
		//rot(0,0);
		//print();
        ans = 23333;
        dfs(0,0);
        printf("%d\n",ans);
    }
	return 0;
}

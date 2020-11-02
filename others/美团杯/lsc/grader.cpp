/* This is sample grader for the contestant */
#include "lcs.h"
#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define N 110

static int p[N];
static int tot_query;
static int max_lcs[N][N];
static int n;

int get_lcs(int len, int A[]) {

	assert(len <= 100);
	for (int i = 0; i < len; ++i) {
		assert(A[i] >= 1 && A[i] <= n);
	}
	++tot_query;
	memset(max_lcs, 0x00, sizeof max_lcs);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= len; ++j)
			if (p[i] == A[j - 1]) {
				max_lcs[i][j] = max_lcs[i-1][j-1] + 1;
			} else {
				max_lcs[i][j] = std::max(max_lcs[i-1][j], max_lcs[i][j-1]);
			}
	return max_lcs[n][len];
}
int b[101], c[101];
void QuickSort(int *a, int l, int r) {
    if(l >= r) return;
    int k = 1ll * rand() * rand() % (r - l + 1) + l;
    int x = a[k];
    int nb = 0, nc = 0;
    for(int i = l; i <= r; i++) if(i != k) {
        int tt[2] = {x, a[i]};
        if(get_lcs(2, tt) == 1) b[nb++] = a[i];
        else c[nc++] = a[i];
    }
    int p = l;
    for(int i = 0; i < nb; i++) a[p++] = b[i];
	int pp = p;
    a[p++] = x;
    for(int i = 0; i < nc; i++) a[p++] = c[i];
	QuickSort(a, l, pp - 1);
	QuickSort(a, pp + 1, r);
}
void find_permutation(int n, int res[]) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) res[i] = i + 1;
    for(int i = 1;i < n;i ++) {
        int l = 0,r = i+1;
        while(r-l>1) {
            int mid = l + r >>1;
            swap(res[mid],res[i]);
            int len = get_lcs(mid+1,res);
            if(len == mid+1) l = mid;
            else r = mid;
            swap(res[mid],res[i]);
        }
     //   cout << l << endl;
        for(int j = i;j > l;j --) res[j] = res[j-1];
        res[l] = i+1;
    }
}
int main()
{
	int used[N];
	// freopen("ex_lcs1.in", "r", stdin);
	assert(scanf("%d", &n) == 1);
	memset(used, 0x00, sizeof used);
	for (int i = 1; i <= n; ++i) {
		assert(scanf("%d", &p[i]));
		assert(1 <= p[i] && p[i] <= n && used[p[i]] == 0);
		used[p[i]] = 1;
	}
	fclose(stdin);

	tot_query = 0;
	int result[N];
	find_permutation(n, result);
	for (int i = 0; i < n; ++i) printf("%d ", result[i]); puts("");
	printf("%d\n", tot_query);
	return 0;
}

#include "lcs.h"
#include <bits/stdc++.h>
using namespace std;
int b[101], c[101];

void QuickSort(int *a, int l, int r) {
    if(l >= r) return;
    int k =  rand() % (r - l + 1) + l;
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
void find_permutation(int n, int res[])
{
    srand(time(NULL));
    for(int i = 0; i < n; i++) res[i] = i + 1;
    QuickSort(res, 0, n - 1);
}

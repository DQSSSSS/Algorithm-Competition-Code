#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define ll long long
#define MOD 998244353

using namespace std;

ll mul(ll a, ll b)
{
	if (!b) return 1;
	ll k = mul(a, b / 2);
	if (b & 1) return k * k % MOD * a % MOD;
	return k * k % MOD;
}

int n, k, N;
ll A[200010], B[200010], C[200010], a, b, c, sum;
ll f[200010], g[200010], h[200010];

void FWT(ll *v, int dir)//xor of course
{
	ll inv2 = mul(2, MOD - 2);
	for (int i = 1; i < N; i <<= 1)
		for (int j = 0; j < N; j += 2 * i)
			for (int k = 0; k < i; k++)
			{
				ll x = v[j + k], y = v[j + k + i];
				v[j + k] = (x + y) * (dir == -1 ? inv2 : 1) % MOD;
				v[j + k + i] = (x - y) * (dir == -1 ? inv2 : 1) % MOD;
			}
}

int main()
{
	//ios::sync_with_stdio(false);
	cin >> n >> k >> a >> b >> c;
	N = (1 << k);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
		f[B[i] ^ A[i]]++, g[C[i] ^ A[i]]++, h[B[i] ^ C[i]]++;
		sum ^= A[i];
	}

		for (int i = 0; i < N; i++) printf("%10lld",f[i]); cout << endl;
	for (int i = 0; i < N; i++) printf("%10lld",g[i]); cout << endl;
	for (int i = 0; i < N; i++) printf("%10lld",h[i]); cout << endl; puts("");
	FWT(f, 1), FWT(g, 1), FWT(h, 1);

		for (int i = 0; i < N; i++) printf("%10lld",f[i]); cout << endl;
	for (int i = 0; i < N; i++) printf("%10lld",g[i]); cout << endl;
	for (int i = 0; i < N; i++) printf("%10lld",h[i]); cout << endl;
	ll ans = 1;
	ll X = (a + b + c) % MOD, Y = (a + b - c + MOD) % MOD, Z = (a - b + c + MOD) % MOD, W = (a - b - c + 2 * MOD) % MOD;
	ll inv2 = mul(2, MOD - 2);
	for (int i = 0; i < N; i++)
	{
		ll x = (n + f[i] + g[i] + h[i]) % MOD * inv2 % MOD * inv2 % MOD,
		   y = ((n + f[i]) % MOD * inv2 % MOD - x + MOD) % MOD,
		   z = ((n + g[i]) % MOD * inv2 % MOD - x + MOD) % MOD,
		   w = ((n + h[i]) % MOD * inv2 % MOD - x + MOD) % MOD;
		f[i] = mul(X, x) * mul(Y, y) % MOD * mul(Z, z) % MOD * mul(W, w) % MOD;
	}
	FWT(f, -1);
	for (int i = 0; i < N; i++)
		cout << f[sum ^ i] << ' ';
	cout << endl;
	return 0;
}

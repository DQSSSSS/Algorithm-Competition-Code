#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define eps 1e-8
 
const double PI = acos(-1.0);
 
struct Complex
{
    double real, image;
    Complex(double _real, double _image)
    {
        real = _real;
        image = _image;
    }
    Complex() {}
};
 
Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.image + c2.image);
}
 
Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.image - c2.image);
}
 
Complex operator*(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real * c2.real - c1.image * c2.image, c1.real * c2.image + c2.real * c1.image);
}
 
int rev(int id, int len)
{
    int ret = 0;
    for (int i = 0; (1 << i) < len; i++)
    {
        ret <<= 1;
        if (id & (1 << i))
            ret |= 1;
    }
    return ret;
}
Complex *A = new Complex[1 << 19];
Complex *B = new Complex[1 << 19];
Complex *C = new Complex[1 << 19];
 
Complex *IterativeFFT(Complex a[], int len, int DFT)
{
    Complex *A = new Complex[len];
    for (int i = 0; i < len; i++)
        A[rev(i, len)] = a[i];
    for (int s = 1; (1 << s) <= len; s++)
    {
        int m = (1 << s);
        Complex wm = Complex(cos(DFT * 2 * PI / m), sin(DFT * 2 * PI / m));
        for (int k = 0; k < len; k += m)
        {
            Complex w = Complex(1, 0);
            for (int j = 0; j < (m >> 1); j++)
            {
                Complex t = w * A[k + j + (m >> 1)];
                Complex u = A[k + j];
                A[k + j] = u + t;
                A[k + j + (m >> 1)] = u - t;
                w = w * wm;
            }
        }
    }
    if (DFT == -1)
        for (int i = 0; i < len; i++)
            A[i].real /= len, A[i].image /= len;
    return A;
}
 
int powd(int a, int b, int p)
{
    int tmp = 1;
    while (b)
    {
        if (b & 1)
        {
            tmp = 1LL * tmp * a % p;
        }
        a = 1LL * a * a % p;
        b >>= 1;
    }
    return tmp;
}
 
bool ok(int x, int p)
{
    for (int i = 2; i * i <= p; i++)
        if ((p - 1) % i == 0 && powd(x, (p - 1) / i, p) == 1)
            return 0;
    return 1;
}
 
int find(int p)
{
    if (p == 2)
        return 1;
    int res = 2;
    for (; !ok(res, p);)
        res++;
    return res;
}
 
long long a[200005];
int id[200005];
int cnt[200005];
long long ans[200005];
 
int main()
{
    freopen("I.in","r",stdin);freopen("Istd.out","w",stdout);
    int n, p;
    scanf("%d%d", &n, &p);
    int g = find(p);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 0; i <= p; i++)
        ans[i] = 0;
    for (int i = 0; i < p - 1; i++)
    {
        int x = powd(g, i, p);
        id[x] = i;
    }
    for (int i = 0; i < p; i++)
        cnt[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        long long x = a[i] % p;
        if (x != 0)
        {
            cnt[id[x]]++;
        }
    }
    for (int i = 0; i < p - 1; i++)
    {
        A[i] = Complex((double)cnt[i] * 1.0, 0);
    }
    int len = 0;
    while ((1 << len) < p)
        len++;
    len = 1 << (len + 1);
    for (int i = p - 1; i < len; i++)
        A[i] = Complex(0, 0);
    for (int i = 0; i < len; i++)
        B[i] = A[i];
    A = IterativeFFT(A, len, 1);
    B = IterativeFFT(B, len, 1);
    for (int i = 0; i < len; i++)
    {
        C[i] = A[i] * B[i];
    }
    C = IterativeFFT(C, len, -1);
    for (int i = 0; i < len; i++)
    {
        ans[i % (p - 1)] += (long long)(C[i].real + 0.5);
    }
    long long tmp = 0;
    long long dqs = 1LL * n * n;
    for (int i = 0; i < p - 1; i++)
    {
        dqs -= ans[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % p == 0)
        {
            if (a[i] == 0)
                printf("%lld\n", dqs);
            else
                puts("0");
        }
        else
        {
            if (a[i] < p)
                printf("%lld\n", ans[id[a[i] % p]]);
            else
                puts("0");
        }
    }
    return 0;
}

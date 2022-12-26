#include <bits/stdc++.h>
using namespace std;
using foo = complex<double>;
constexpr int maxn = 1 << 21 | 5, maxlog = 22;
int n, m, t, rev[maxn], f[maxn], g[maxn];
foo omega[maxlog], h[maxn];
void init() noexcept
{
    omega[0] = 1;
    omega[1] = -1;
    omega[2] = foo(0, 1);
    for (int i = 3; i < maxlog; ++i)
        omega[i] = sqrt(omega[i - 1]);
}
void change(foo *a, const int &n) noexcept
{
    rev[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1)
            rev[i] |= n >> 1;
    }
    for (int i = 1; i < n; ++i)
    {
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    }
}
void fft(foo *a, const int &n, const bool &u) noexcept
{
    change(a, n);
    int qaq;
    foo *qwq = omega + 1, tat, bar, baz;
    for (int i = 1; i < n; i <<= 1, ++qwq)
    {
        qaq = i << 1;
        for (int j = 0; j < n; j += qaq)
        {
            tat = 1;
            for (int k = 0; k < i; ++k)
            {
                bar = a[j | k];
                baz = tat * a[j | k | i];
                tat *= *qwq;
                a[j | k] = bar + baz;
                a[j | k | i] = bar - baz;
            }
        }
    }
    if (u)
    {
        reverse(a + 1, a + n);
        for (int i = 0; i < n; ++i)
            a[i] /= n;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("3803.in","r",stdin);
    freopen("3803.out","w",stdout);
    #endif
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    t = n + m;
    for (int i = 0; i <= n; ++i) cin >> f[i];
    for (int i = 0; i <= m; ++i) cin >> g[i];
    n = max(n, m);
    for (int i = 0; i <= n; ++i) h[i] = foo(f[i], g[i]);
    m = 1;
    while (m <= t) m <<= 1;
    fft(h, m, false);
    for (int i = 0; i < m; ++i) h[i] *= h[i];
    fft(h, m, true);
    for (int i = 0; i <= t; ++i) cout << int(h[i].imag() / 2 + .5) << ' ';
    cout.put('\n');
    return 0;
}

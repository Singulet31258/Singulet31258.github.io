#include <iostream>
#include <map>
using namespace std;
constexpr int maxn = 2e5 + 5;
int l[maxn], link[maxn], last, tot, n, x;
long long ans;
map<int, int> go[maxn];
void init() noexcept
{
#ifndef ONLINE_JUDGE
    freopen("P2033.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    l[0] = 0;
    link[0] = -1;
    last = 0;
    tot = 0;
}
void extend(const int &x) noexcept
{
    int now = ++tot;
    l[now] = l[last] + 1;
    int p = last;
    while (p != -1 && go[p][x] == 0)
    {
        go[p][x] = now;
        p = link[p];
    }
    if (p == -1)
    {
        link[now] = 0;
    }
    else
    {
        int q = go[p][x];
        if (l[q] == l[p] + 1)
        {
            link[now] = q;
        }
        else
        {
            int clone = ++tot;
            l[clone] = l[p] + 1;
            link[clone] = link[q];
            go[clone] = go[q];
            while (p != -1 && go[p][x] == q)
            {
                go[p][x] = clone;
                p = link[p];
            }
            link[q] = link[now] = clone;
        }
    }
    last = now;
    ans += l[now] - l[link[now]];
}
int main()
{
    init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        extend(x);
        cout << ans << '\n';
    }
    return 0;
}

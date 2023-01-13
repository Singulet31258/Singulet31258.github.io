#include<bits/stdc++.h>
using namespace std;
using _=unsigned long long;
using u128=__uint128_t;
constexpr unsigned A=8e6;
unsigned p,i,*j,a[A],b[A],*c=b,phi[A];
_ n,d[A],t,u,l,r,ans;
const struct fastmod
{
    unsigned p,a;
    _ b;
    fastmod(const unsigned &p)noexcept:p(p),a(93-__builtin_clz(p)),b((u128(1)<<a)/p+1){}
    friend _ operator%(const _&n, const fastmod&m) noexcept{return n-_(u128(n)*m.b>>m.a)*m.p;}
    friend void operator%=(_&n,const fastmod&m)noexcept{n-=_(u128(n)*m.b>>m.a)*m.p;}
}m=(
#ifndef ONLINE_JUDGE
    freopen("P3768.in","r",stdin),
#endif
    cin>>p>>n,p);
_ qp(_ a,_ b)noexcept{
    _ r=1;
    while(b){
        if(b&1)(r*=a)%=m;
        b>>=1;
        (a*=a)%=m;
    }
    return r;
}
map<_,_>mp;
const _ quarter=qp(4,p-2),sixth=qp(6,p-2);
inline _ foo(const _&n)noexcept{
    return n*(n+1)%m*(n<<1|1)%m*sixth%m;
}
inline _ bar(const _&n)noexcept{
    return n*n%m*(n+1)%m*(n+1)%m*quarter%m;
}
inline _ baz(const _&n)noexcept{
    return n<A?d[n]:mp[n];
}
int main()
{
    clock_t st=clock();
    d[1]=1;
    for(i=2;i<A;++i){
        if(!a[i])a[i]=*c++=i,phi[i]=i-1;
        for(j=b,u=i**j;j!=c&&u<A;u=i**++j){
            a[u]=*j;
            if(*j==a[i]){
                phi[u]=phi[i]**j;
                break;
            }else{
                phi[u]=phi[i]*(*j-1);
            }
        }
        d[i]=(d[i-1]+_(i)*i%m*phi[i])%m;
    }
    for(i=1;n/i>=A;++i);
    while(--i){
        u=n/i;t=0;
        for(l=2;l<=u;l=r+1){
            r=u/(u/l);
            (t+=(foo(r%m)+p-foo((l-1)%m))*baz(u/r))%=m;
        }
        mp[u]=(bar(u%m)-t+p)%m;
    }
    for(l=1;l<=n;l=r+1){
        r=n/(n/l);
        (ans+=(bar(r%m)+p-bar((l-1)%m))*baz(n/r))%=m;
    }cout<<ans<<'\n';
    cerr<<clock()-st;
    return 0;
}

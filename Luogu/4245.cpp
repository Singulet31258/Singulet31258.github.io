#include<bits/stdc++.h>
struct qio{
    constexpr static int ibs=1<<21,obs=1<<21;
    FILE*ifp,*ofp;
    char ib[ibs],ob[obs],*ibp,*obp;
    qio()noexcept{
        ifp=stdin;
        ofp=stdout;
        fread(ib,sizeof(ib),1,ifp);
        ibp=ib-1;
        obp=ob;
    }
    qio(const char*ifn,const char*ofn)noexcept{
        ifp=fopen(ifn,"rb");
        ofp=fopen(ofn,"wb");
        fread(ib,sizeof(ib),1,ifp);
        ibp=ib-1;
        obp=ob;
    }
    template<typename T>
    qio&operator>>(T&x)noexcept{
        while(!isdigit(*++ibp));x=*ibp&0xf;
        while(isdigit(*++ibp))x=(x+(x<<2)<<1)+(*ibp&0xf);
        return*this;
    }
    template<typename T>
    void in(T&x)noexcept{
        while(!isdigit(*++ibp));x=*ibp&0xf;
        while(isdigit(*++ibp))x=(x+(x<<2)<<1)+(*ibp&0xf);
    }
    template<typename T>
    void in(T*x,const int&n)noexcept{
        T*y=x+n;
        while(x!=y)in(*x++);
    }
    template<typename T>
    qio&operator<<(T x)noexcept{
        char*t=obp;
        while(*obp++=x%10|0x30,x/=10);
        std::reverse(t,obp);
        return*this;
    }
    template<typename T>
    void out(T x)noexcept{
        char*t=obp;
        while(*obp++=x%10|0x30,x/=10);
        std::reverse(t,obp);
    }
    template<typename T>
    void out(T*x,const int&n)noexcept{
        T*y=x+n;
        while(x!=y)out(*x++),*obp++=' ';
    }
    void operator<<(const char&c)noexcept{
        *obp++=c;
    }
    ~qio()noexcept{
        fwrite(ob,sizeof(char),obp-ob,ofp);
        fclose(ifp);
        fclose(ofp);
    }
};
#ifndef ONLINE_JUDGE
qio io("P4245.in","P4245.out");
#else
qio io;
#endif
using _=std::complex<long double>;
constexpr int T=15,U=(1<<T)-1,maxlog=18,maxn=1<<maxlog|5;
constexpr _ V=_(.5,0),W=_(0,-.5),I=_(0,1);
int a[maxn],b[maxn];
_ baz[maxlog],foo,c[maxn],d[maxn],e[maxn],f[maxn],g[maxn],h[maxn];
int rev[maxn];
inline void init(const int&n)noexcept{
    rev[0]=0;
    for(int i=1;i<n;++i){
        rev[i]=rev[i>>1]>>1;
        if(i&1)rev[i]|=n>>1;
    }
}
template<typename T>
inline void brp(T*a,const int&n)noexcept{
    for(int i=1;i<n;++i)if(i<rev[i])std::swap(a[i],a[rev[i]]);
}
inline void init()noexcept{
    baz[0]=-1;baz[1]=I;
    for(int i=2;i<maxlog;++i)baz[i]=std::sqrt(baz[i-1]);
}
void fft(_*a,const int&n,const bool&u)noexcept{
    clock_t st=clock();
    brp(a,n);
    _ bar,*p=baz;
    for(int i=1;i<n;++p,i<<=1){
        for(int j=0;j<n;j+=i<<1){
            foo=1;
            for(int k=0;k<i;++k,foo*=*p){
                bar=foo*a[j|k|i];
                a[j|k|i]=a[j|k]-bar;
                a[j|k]+=bar;
            }
        }
    }
    if(u){
        for(int i=0;i<n;++i)a[i]/=n;
        std::reverse(a+1,a+n);
    }
    std::cerr<<clock()-st<<'\n';
}
int main(){
    using namespace std;
    int n,m,p,t;
    io>>n>>m>>p;t=n+m;
    io.in(a,n+1);
    io.in(b,m+1);
    n=max(n,m);
    for(int i=0;i<=n;++i)g[i]=_(a[i]>>T,a[i]&U),h[i]=_(b[i]>>T,b[i]&U);
    n=1;while(n<=t)n<<=1;
    init();
    init(n);
    fft(g,n,false);
    fft(h,n,false);
    for(int i=0,j;i<n;++i){
        j=(n-i)&(n-1);
        c[i]=(g[i]+conj(g[j]))*V;
        d[i]=(g[i]-conj(g[j]))*W;
        e[i]=(h[i]+conj(h[j]))*V;
        f[i]=(h[i]-conj(h[j]))*W;
    }
    _ u;
    for(int i=0;i<n;++i){
        u=e[i]+I*f[i];
        g[i]=c[i]*u;
        h[i]=d[i]*u;
    }
    fft(g,n,true);
    fft(h,n,true);
    long long qaq,qwq,tat,orz;
    for(int i=0;i<=t;++i){
        qaq=(long long)(g[i].real()+.5);
        qwq=(long long)(g[i].imag()+.5);
        tat=(long long)(h[i].real()+.5);
        orz=(long long)(h[i].imag()+.5);
        io<<(int)((orz+(qwq+tat+((__int128)qaq<<T)<<T))%p)<<' ';
    }
    return 0;
}
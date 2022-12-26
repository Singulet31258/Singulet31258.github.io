#include<bits/stdc++.h>
using namespace std;
using foo=complex<double>;
constexpr int maxn=1<<21|5,maxlog=22;
int n,m,t,rev[maxn],f[maxn],g[maxn];
foo omega[maxlog],a[maxn];
void init()noexcept{/*预处理2^m次单位根omega_{2^m},omega_n^n=1,omega_n^{n/2}=-1*/
    omega[0]=1;omega[1]=-1;omega[2]=foo(0,1);
    for(int i=3;i<maxlog;++i)omega[i]=sqrt(omega[i-1]);
}
void brp(foo*a,const int&n)noexcept{/*位逆序置换BRP，n必须为2的幂*/
    /**
     * FFT给系数分组的时候，实际上是这样操作的：（以下每个数都以二进制形式出现）
     * 下标个位为0的分左边，为1的分右边
     * 左边的下标最高位为0，而右边的为1
     * 这样就将个位和最高位对应了起来
     * 然后继续细分，可将十位和次高位对应起来
     * 以此类推，最后会发现，新下标刚好是旧下标的位逆序（即把旧下标的每一位倒着读过来）！
     * 如：001011的位逆序就是110100，0110001的位逆序就是1000110
     * 发现这个规律后，我们可以直接O(n)求解每个数的位逆序，然后直接把系数移到它最终的位置上！
     * 设rev[i]表示i的位逆序
     * 先把i右移1位，然后求其位逆序，然后再右移一位
     * 这个时候只需要判断rev[i]的最高位是否应为1即可
     * rev[i]的最高位是否应为1，即i的个位是否为1
     * 状态转移方程：rev[i]=rev[i>>1]>>1，当i&1为1时，rev[i]|=n>>1（即令最高位为1）
     */
    for(int i=1;i<n;++i){
        rev[i]=rev[i>>1]>>1;
        if(i&1)rev[i]|=n>>1;
        /**
         * 由于后续rev[i]都不会被更改，因此可以边求rev[i]边移动系数
         * 显然，rev[rev[i]]=i（毕竟翻转2次相当于没翻转）
         * 因此，i移动到rev[i]，那么rev[i]也会移动到i
         * 直接交换i和rev[i]即可，为避免重复交换，可限定只在i<rev[i]时交换
         */
        if(i<rev[i])swap(a[i],a[rev[i]]);
    }
}
void fft(foo*a,const int&n,const bool&u)noexcept{/*FFT模板，n必须为2的幂*/
    brp(a,n);/*先提前将系数移到最终的位置上*/
    foo bar,baz,qux,*p=omega+1;
    /**
     * 此时次数为i-1的多项式已经分治求解完毕，接下来需要求解2i-1次多项式
     * p是一个指针，指向求解当前多项式所需要的单位根
     * 显然，求解2^m-1次多项式需要2^m次单位根，即omega[m]
     */
    for(int i=1;i<n;i<<=1,++p){
        /**
         * 合并求解次数为2i-1的多项式，每求解完一个就走2i步合并下一个
         * j记录当前合并的多项式的起始位置
         */
        for(int j=0;j<n;j+=i<<1){
            bar=1;/*bar记录当前要代入的x的值*/
            /*枚举0<=k<i，利用之前求出的多项式来求解当前的多项式*/
            for(int k=0;k<i;++k){
                baz=a[j|k];        /*baz记录P(omega_{n/2}^k)*/
                qux=bar*a[j|k|i];  /*qux记录Q(omega_{n/2}^k)omega_n^k*/
                a[j|k]=baz+qux;    /*计算F(omega_n^k)*/
                a[j|k|i]=baz-qux;  /*计算F(omega_n^{k+n/2})*/
                bar*=*p;           /*将指数+1*/
            }
        }
    }
    /**
     * 如果打了u标记说明此FFT是点值转系数的FFT，否则是普通FFT
     * 设系数转点值所用到的矩阵为M，系数向量为A，点值向量为Y
     * 则Y=MA，显然，M有n行n列，第i行第j列（0<=i,j<n）就是omega_n^i的j次方
     * 点值转系数时，直接按普通FFT得到的是(M^2)A
     * 而M^2只有当n整除i+j时，第i行第j列为n，否则为0
     * 所以(M^2)A得到的实际上是[na_0,na_{n-1},na_{n-2},...,na_2,na_1]
     * 于是按普通FFT跑完后，各项除以n，然后把后n-1个数颠倒一下位置，即可还原出A！
     */
    if(u){
        for(int i=0;i<n;++i)a[i]/=n;
        reverse(a+1,a+n);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("3803.in","r",stdin);
    freopen("3803.out","w",stdout);
    #endif
    init();ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<=n;++i)cin>>f[i];/*n次多项式F(x)*/
    for(int i=0;i<=m;++i)cin>>g[i];/*m次多项式G(x)*/
    t=n+m;n=max(n,m);/*t为F(x)G(x)的次数*/
    for(int i=0;i<=n;++i)a[i]=foo(f[i],g[i]);/*构造F(x)+G(x)i*/
    m=1;while(m<=t)m<<=1;/*让多项式次数为2的幂-1*/
    fft(a,m,false);/*普通FFT*/
    for(int i=0;i<m;++i)a[i]*=a[i];/*平方*/
    fft(a,m,true);/*转回系数表示*/
    /*虚部除以2即可得F(x)G(x)，+.5保证四舍五入取整，避免精度误差*/
    for(int i=0;i<=t;++i)cout<<int(a[i].imag()/2+.5)<<' ';
    return 0;
}

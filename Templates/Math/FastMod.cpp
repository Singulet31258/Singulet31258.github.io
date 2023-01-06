#include<bits/stdc++.h>
using i8=char;
using i16=short;
using i32=long;
using i64=long long;
using i128=__int128_t;
using u8=unsigned char;
using u16=unsigned short;
using u32=unsigned long;
using u64=unsigned long long;
using u128=__uint128_t;
/**
 * 内部实现为Barrett Reduction的快速取模结构体
 * 在对固定模数p取模1e9次的情况下：（ISO C++14 O2 GCC 9.3.0）
 * 对变量p取模：4800~5000ms；
 * 对常量p取模：640~680ms；
 * 对只读变量p取模：4750~5000ms；
 * 把p封装到该结构体后取模：720~750ms；
 * 该结构体目前已经非常接近编译器对取模优化的效果，但仍有进一步的优化空间
 * 用法：(const)fastmod m(p);（const可加可不加）然后n对p取模就可以写成n%m
 * m在定义以后就无法修改，可以将m定义成constexpr
 * m在定义时会做一次低效的整数除法运算，因此在模数频繁变更的情况下不要使用该结构体！
*/
struct fastmod{
    const int a;
    const u64 b,p;
    constexpr fastmod(const u64&p)noexcept:a(127-__builtin_clzll(p)),b((u128(1)<<a)/p),p(p){}
    constexpr friend u64 operator/(const u64&n,const fastmod&m)noexcept{
        return u128(n)*b>>a;
    }
    constexpr friend u64 operator%(const u64&n,const fastmod&m)noexcept{
        return n-u128(n)*b>>a*m.p;
    }
};
constexpr fastmod M(1e9+7);
u64 n,p;
int main(){
    using namespace std;
    cin>>n>>p;
    const fastmod m(p);
    cout<<n%p<<' '<<n%m<<endl;
    return 0;
}

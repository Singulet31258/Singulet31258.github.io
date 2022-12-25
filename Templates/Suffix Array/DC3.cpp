//注：非重点代码压行，重点代码不压行
#include<bits/stdc++.h>
//常量与变量声明（非重点）
constexpr int maxn=1e6+5;int n,qaq[maxn],qwq[maxn],tat[maxn],orz[maxn],rk[maxn*3],sa[maxn*3];char s[maxn];
//基数排序（非重点）
void sort(const int*a,const int*b,int*c,const int&n,const int&m)noexcept{int i;memset(qaq,0,sizeof(int)*m);for(i=0;i<n;++i)++qaq[a[b[i]]];for(i=1;i<m;++i)qaq[i]+=qaq[i-1];for(i=n-1;~i;--i)c[--qaq[a[b[i]]]]=b[i];}
//DC3算法需要比较连续3个字符是否完全一致，r为字符的rank数组，a和b为要比较的字符起始位置
inline bool c0(const int*r,const int&a,const int&b)noexcept
{
  return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
//DC3算法最后一步所需的比较函数
inline bool c12(const bool&u,const int*r,const int&a,const int&b)noexcept
{
  return r[a]<r[b]||(r[a]==r[b]&&(u?qwq[a+1]<qwq[b+1]:r[a+1]<r[b+1]||(r[a+1]==r[b+1]&&qwq[a+2]<qwq[b+2])));
}
//DC3算法核心函数，请配合DC3算法的有关资料进行阅读
void dc3(int*rk,int*sa,const int&n,const int&m)noexcept
{
  int i,j=0,k,*rkn=rk+n,*san=sa+n,t0,t1,t12;rk[n]=rk[n+1]=0;
  //第一步
  for(i=1;i<n;i+=3)tat[j++]=i;t1=j;for(i=2;i<n;i+=3)tat[j++]=i;t12=j;
  sort(rk+2,tat,orz,t12,m);sort(rk+1,orz,tat,t12,m);sort(rk,tat,orz,t12,m);
  #define newpos(x) x/3+(x%3==1?0:t1)
  for(i=1,j=rkn[newpos(orz[0])]=0;i<t12;++i)rkn[newpos(orz[i])]=c0(rk,orz[i],orz[i-1])?j:++j;
  if(++j<t12)dc3(rkn,san,t12,j);else for(i=0;i<t12;++i)san[rkn[i]]=i;
  //第二步
  for(i=t0=0;i<t12;++i)if(san[i]<t1)tat[t0++]=3*san[i];if(n%3==1)tat[t0++]=n-1;
  sort(rk,tat,orz,t0,m);for(i=0;i<t12;++i)qwq[tat[i]=san[i]<t1?3*san[i]+1:3*(san[i]-t1)+2]=i;
  //第三步
  for(i=j=k=0;i<t12&&j<t0;++k)sa[k]=c12(san[i]<t1,rk,tat[i],orz[j])?tat[i++]:orz[j++];
  while(i<t12)sa[k++]=tat[i++];while(j<t0)sa[k++]=orz[j++];
}
int main()
{
  using namespace std;ios::sync_with_stdio(false);cin.tie(nullptr);//无关紧要
  cin>>s;for(n=0;s[n];++n)rk[n]=s[n];rk[n++]=0;dc3(rk,sa,n,128);//读入字符串并求它的后缀数组
  for(int i=1;i<n;++i)cout<<sa[i]+1<<' ';return cout.put('\n'),0;//输出一行后缀数组然后退出程序
}

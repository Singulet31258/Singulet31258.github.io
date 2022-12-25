#include<bits/stdc++.h>
constexpr int maxn = 1e6 + 5;
int n,qaq[maxn],qwq[maxn],tat[maxn],orz[maxn],rk[maxn*3],sa[maxn*3];
char s[maxn];
void sort(int*a,int*b,int*c,int n,int m)noexcept
{
  int i;memset(qaq,0,sizeof(int)*m);
  for(i=0;i<n;++i)++qaq[a[b[i]]];
  for(i=1;i<m;++i)qaq[i]+=qaq[i-1];
  for(i=n-1;~i;--i)c[--qaq[a[b[i]]]]=b[i];
}
inline bool c0(int*r,int a,int b)noexcept
{
  return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
inline bool c12(bool u,int*r,int a,int b)noexcept
{
  return r[a]<r[b]||(r[a]==r[b]&&(u?qwq[a+1]<qwq[b+1]:r[a+1]<r[b+1]||(r[a+1]==r[b+1]&&qwq[a+2]<qwq[b+2])));
}
void dc3(int*rk,int*sa,int n,int m)noexcept
{
  int i,j=0,k,*rkn=rk+n,*san=sa+n,t0,t1,t12;
  for(i=1;i<n;i+=3)tat[j++]=i;t1=j;
  for(i=2;i<n;i+=3)tat[j++]=i;t12=j;
  rk[n]=rk[n+1]=0;
  sort(rk+2,tat,orz,t12,m);
  sort(rk+1,orz,tat,t12,m);
  sort(rk,tat,orz,t12,m);
  #define foo(x) x/3+(x%3==1?0:t1)
  #define bar(x) x<t1?3*x+1:3*(x-t1)+2
  for(i=1,j=rkn[foo(orz[0])]=0;i<t12;++i)rkn[foo(orz[i])]=c0(rk,orz[i],orz[i-1])?j:++j;
  if(++j<t12)dc3(rkn,san,t12,j);
  else for(i=0;i<t12;++i)san[rkn[i]]=i;
  for(i=t0=0;i<t12;++i)if(san[i]<t1)tat[t0++]=3*san[i];
  if(n%3==1)tat[t0++]=n-1;
  sort(rk,tat,orz,t0,m);
  for(i=0;i<t12;++i)qwq[tat[i]=bar(san[i])]=i;
  for(i=j=k=0;i<t12&&j<t0;++k)sa[k]=c12(san[i]<t1,rk,tat[i],orz[j])?tat[i++]:orz[j++];
  while(i<t12)sa[k++]=tat[i++];
  while(j<t0)sa[k++]=orz[j++];
}
int main()
{
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>s;
  for(n=0;s[n];++n)rk[n]=s[n];
  rk[n++]=0;
  dc3(rk,sa,n,128);
  for(int i=1;i<n;++i)cout<<sa[i]+1<<' ';
  cout.put('\n');
  return 0;
}

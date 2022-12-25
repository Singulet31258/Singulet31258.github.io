#include<bits/stdc++.h>
constexpr int maxn = 1e6 + 5;
int n,qaq[maxn],qwq[maxn],tat[maxn],orz[maxn];
char s[maxn];
void sort(int*a,int*b,int*c,int n,int m)noexcept
{
  int i;
  memset(qaq,0,sizeof(int)*m);
  for(i=0;i<n;++i)++qaq[a[b[i]]];
  for(i=1;i<m;++i)qaq[i]+=qaq[i-1];
  for(i=0;i<n;++i)c[--qaq[a[b[i]]]]=b[i];
}
void dc3(int*rk,int*sa,int n,int m)noexcept
{
  int i,j=0,k,*rkn=rk+n,*san=sa+n,t0,t1,t12;
  for(i=1;i<n;i+=3)tat[j++]=i;
  t1=j;
  for(i=2;i<n;i+=3)tat[j++]=i;
  t12=j;
  rk[n]=rk[n+1]=0;
  sort(rk+2,tat,orz,t12,m);
  sort(rk+1,orz,tat,t12,m);
  sort(rk,tat,orz,t12,m);
  #define foo(x) x/3+(x%3==1?0:t1)
  #define bar(x) x<t1?3*x+1:3*(x-t1)+2
  
}

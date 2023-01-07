#include<bits/stdc++.h>
using namespace std;using _=long long;
const int A=2005,B=1e6+5,C=1e3+5;
_ n,m,k,a[A],c[4][B],d[3],e[C][2],i,j,l,t,u,ans;map<_,_>f;
_ b(_ n){return n/k*a[k]+a[n%k];}
_ g(_ n){return n<B?c[0][n]:f[n];}
int main(){
    cin>>n>>m>>k;
    for(i=1;i<=k;++i)a[i]=a[i-1]+(__gcd(i,k)==1);
    c[0][1]=c[3][1]=1;
    for(i=2;i<B;++i){
        if(!c[1][i])c[2][d[0]++]=i,c[3][i]=-1;
        for(j=0;j<d[0]&&i*c[2][j]<B;++j){
            c[1][i*c[2][j]]=1;
            if(i%c[2][j])c[3][i*c[2][j]]=-c[3][i];
            else{
                c[3][i*c[2][j]]=0;
                break;
            }
        }
        c[0][i]=c[0][i-1]+c[3][i]*(b(i)-b(i-1));
    }
    e[0][0]=n;e[0][1]=m;
    for(i=1;n/(i+1)>=B;++i)e[i][0]=n/(i+1);d[1]=i;
    for(i=1;m/(i+1)>=B;++i)e[i][1]=m/(i+1);d[2]=i;
    for(i=d[1]-1;~i;--i){
        t=0;u=n/(i+1);
        for(j=2;j<=u;j=l+1){
            l=u/(u/j);
            t+=(b(l)-b(j-1))*g(u/j);
        }
        f[u]=1-t;
    }
    for(i=d[2]-1;~i;--i){
        t=0;u=m/(i+1);
        for(j=2;j<=u;j=l+1){
            l=u/(u/j);
            t+=(b(l)-b(j-1))*g(u/j);
        }
        f[u]=1-t;
    }
    t=min(n,m);
    for(i=1;i<=t;i=j+1){
        j=min(n/(n/i),m/(m/i));
        ans+=(n/i)*b(m/i)*(g(j)-g(i-1));
    }cout<<ans;
    return 0;
}

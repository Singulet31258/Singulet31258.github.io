#include<bits/stdc++.h>
using namespace std;
using _=long long;
constexpr int A=1.8e6,B=1.5e3;
_ n,a[A][4],b,c[A][2],d[B],e;map<_,_>f[2];
_ baz(_ n){return n<A?c[n][0]:f[0][n];}
_ qux(_ n){return n<A?c[n][1]:f[1][n];}
void foo(){
    for(_ i=e-1,j=0;~i;--i,j=0){
        if(f[0].count(d[i]))continue;
        for(_ k=2,l;k<=d[i];k=l+1){
            l=d[i]/(d[i]/k);
            j+=(l-k+1)*baz(d[i]/k);
        }
        f[0][d[i]]=(d[i]*(d[i]+1)>>1)-j;
    }
    cout<<f[0][n]<<' ';
}
void bar(){
    for(_ i=e-1,j=0;~i;--i,j=0){
        if(f[1].count(d[i]))continue;
        for(_ k=2,l;k<=d[i];k=l+1){
            l=d[i]/(d[i]/k);
            j+=(l-k+1)*qux(d[i]/k);
        }
        f[1][d[i]]=1-j;
    }
    cout<<f[1][n]<<'\n';
}
int main(){
    clock_t st=clock();
    c[1][0]=c[1][1]=1;
    for(int i=2,k;i<A;++i){
        if(!a[i][0])a[i][0]=a[b++][1]=i,a[i][2]=i-1,a[i][3]=-1;
        for(int j=0;j<b&&i*a[j][1]<A;++j){
            k=i*a[j][1];
            a[k][0]=a[j][1];
            if(a[j][1]==a[i][0]){
                a[k][2]=a[i][2]*a[j][1];
                a[k][3]=0;
                break;
            }else{
                a[k][2]=a[i][2]*(a[j][1]-1);
                a[k][3]=-a[i][3];
            }
        }
        c[i][0]=c[i-1][0]+a[i][2];
        c[i][1]=c[i-1][1]+a[i][3];
    }
    int t;cin>>t;while(t--){
        cin>>n;
        d[0]=n;
        for(e=1;n/(e+1)>=A;++e)d[e]=n/(e+1);
        foo();
        bar();
    }
    cerr<<clock()-st;
    return 0;
}

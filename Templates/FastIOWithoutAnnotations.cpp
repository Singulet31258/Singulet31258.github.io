#include<bits/stdc++.h>
using namespace std;
struct FastIO{
  constexpr static int IBS=1<<25,OBS=1<<26;
  char ib[IBS],ob[OBS],*ibp,*obp;
  #ifndef ONLINE_JUDGE
  ifstream fin;
  ofstream fout;
  FastIO(const char*ifn,const char*ofn)noexcept:ibp(ib-1),obp(ob){fin.open(ifn);fout.open(ofn);fin.read(ib,IBS);}
  #else
  #define fin cin
  #define fout cout
  FastIO()noexcept:ibp(ib-1),obp(ob){fin.read(ib,IBS);}
  #endif
  ~FastIO()noexcept{fout.write(ob,obp-ob);fin.close();fout.close();}
  template<typename T>FastIO&operator>>(T&x)noexcept{while(!isdigit(*++ibp));x=*ibp&0xf;while(isdigit(*++ibp))x=(x+(x<<2)<<1)+(*ibp&0xf);return*this;}
  template<typename T>FastIO&operator<<(T x)noexcept{char*t=obp;while(*obp++=x%10|0x30,x/=10);std::reverse(t,obp);return*this;}
  FastIO&operator>>(char*s)noexcept{while(*++ibp!=' ')*s++=*ibp;return*this;}
};

#include<bits/stdc++.h>
struct FastIO{
  //IBS表示in文件的大小，OBS表示out文件的大小
  constexpr static int IBS=1<<25,OBS=1<<26;
  char ib[IBS],ob[OBS],*ibp,*obp;
  FILE*ifp,*ofp;
  FastIO()noexcept:ibp(ib-1),obp(ob),ifp(stdin),ofp(stdout){fread(ib,sizeof(ib),1,ifp);}
  FastIO(const char*ifn,const char*ofn)noexcept:ibp(ib-1),obp(ob),ifp(fopen(ifn,"r")),ofp(fopen(ofn,"w")){fread(ib,sizeof(ib),1,ifp);}
  ~FastIO()noexcept{fwrite(ob,sizeof(char),obp-ob,ofp);fclose(ifp);fclose(ofp);}
};
#ifndef ONLINE_JUDGE
FastIO io("P1001.in","P1001.out");
#else
FastIO io;
#endif

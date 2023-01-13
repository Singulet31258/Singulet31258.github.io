#include<bits/stdc++.h>
//fread/fwrite包装的超级快读快写结构体，但读写方式模仿iostream库的cin/cout，兼具简洁与高效2个方面
//该结构体的变量兼具读写2个功能。例如：FastIO io;那么int x;io>>x;表示从io指向的输入文件/stdin读取一个int数据到x，而io<<x;表示将数据x写入io指向的输出文件/stdout
struct FastIO{
  //IBS表示输入文件/stdin的大小，OBS表示输出文件/stdout的大小
  constexpr static int IBS=1<<25,OBS=1<<26;
  //ib输入缓冲区，ob输出缓冲区，ibp指向当前输入缓冲区的末尾，obp指向当前输出缓冲区的末尾
  char ib[IBS],ob[OBS],*ibp,*obp;
  //ifp指向输入文件/stdin，ofp指向输出文件/stdout
  FILE*ifp,*ofp;
  //无参构造函数指向标准IO，有参构造函数指向文件IO（ifn表示输入文件名称，ofn表示输出文件名称）
  FastIO()noexcept:ibp(ib-1),obp(ob),ifp(stdin),ofp(stdout){fread(ib,sizeof(ib),1,ifp);}
  FastIO(const char*ifn,const char*ofn)noexcept:ibp(ib-1),obp(ob),ifp(fopen(ifn,"r")),ofp(fopen(ofn,"w")){fread(ib,sizeof(ib),1,ifp);}
  ~FastIO()noexcept{fwrite(ob,sizeof(char),obp-ob,ofp);fclose(ifp);fclose(ofp);}//析构函数，在程序结束后会自动调用该函数，将清空缓冲区与关闭文件的代码放到这里
  //读取一个非负整数
  template<typename T>FastIO&operator>>(T&x)noexcept{while(!isdigit(*++ibp));x=*ibp&0xf;while(isdigit(*++ibp))x=(x+(x<<2)<<1)+(*ibp&0xf);return*this;}
  template<typename T>FastIO&operator<<(T x)noexcept{char*t=obp;while(*obp++=x%10|0x30,x/=10);std::reverse(t,obp);return*this;}//写入一个非负整数
  FastIO&operator>>(char*s)noexcept{while(*++ibp!=' ')*s++=*ibp;return*this;}//读取一个字符串，以空格为分隔符，但不读取空格
  int get()noexcept{return*++ibp;}//读取一个字符
  void put(const int&x)noexcept{*obp++=x;}//写入一个字符
  void flush()noexcept{fwrite(ob,sizeof(char),obp-ob,ofp);obp=ob;}//清空缓冲区，一般仅用于内存限制比较紧（即OBS不能开太大）的题，功能与std::flush完全一致
  void endl()noexcept{*obp++='\n';fwrite(ob,sizeof(char),obp-ob,ofp);obp=ob;}//先写入一个换行符，然后再清空缓冲区，功能与std::endl完全一致
  //该结构体的更多功能由你来实现…………
};//你也可以换一种定义flush与endl函数的方式，然后就可以写成io<<flush;或io<<endl;的形式
#ifndef ONLINE_JUDGE
FastIO io("?.in","?.out");//?处填题目指定的名称
#else
FastIO io;
#endif
int main(){
  int a,b;
  io>>a>>b<<a+b;
  return 0;
}

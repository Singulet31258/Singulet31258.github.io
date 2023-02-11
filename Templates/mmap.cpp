#include<sys/mman.h>
#define gc() q[i++]
char*q;
int read(){
    char c=gc();
    int x=0;
    while(c<48||c>57)c=gc();
    while(c>47&&c<58)x=x*10+c-48,c=gc();
    return x;
}
//...
int main(){
    q=(char*)mmap(0,N,PROT_READ,MAP_PRIVATE,fileno(stdin),0);
    //...
}

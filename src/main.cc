#include "../include/strCls.hh"

using std::cout;
using std::cin;
using std::endl;
using namespace str;

int main()
{
    const char *p = "Hello";
    String s1 = p, s2 = "World";
    s1 += p;
    s1 += s2;
    cout<<s1<<endl;
    s2 = s1;
    cout<<s2<<endl;
    s2 = p;
    cout<<s2<<endl;

    const String s3 = s1 + s2 + p;
    cout << s1 + p << s3<<endl;
    cout << p + s2 + s3<<endl;
    s2 += s3 + s1;
    cout << (p + s2 + s3).size()<<endl;

    cout << String(p) + p <<endl;
    cout << s3[11]<<endl;
    return 0;
}
#include "../include/strCls.hh"
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

namespace str{

    /* 默认构造函数开辟 BLOCK_SIZE = 24 字节的空间 */
    String::String()
    {
        _pstr = new char[BLOCK_SIZE];
        bzero(_pstr, BLOCK_SIZE);
    }

    /* 类型转换构造函数方便传入C风格字符串 */
    String::String(const char * str)
    : _pstr(new char[strlen(str) + 1])
    {
        strcpy(_pstr, str);
    }

    /* 简单的复制构造函数 */
    String::String(const String& str)
    : _pstr(new char[strlen(str._pstr) + 1])
    {
        strcpy(_pstr, str._pstr);
    }

    /* 析构函数释放空间 */
    String::~String()
    {
        delete []_pstr;
        _pstr = nullptr;
    }

    /* 赋值重载函数，深拷贝 */
    String& String::operator=(const String &str)
    {
        if(str._pstr == _pstr)
            return *this;
        delete []_pstr;
        _pstr = new char[strlen(str._pstr) + 1];
        strcpy(_pstr, str._pstr);
        return *this;
    }

    /* 重用以上赋值=、类型转换构造函数函数 */
    String& String::operator=(const char *str)
    {
        *this = String(str);
        return *this;
    }

    /* 拼接字符串 */
    String& String::operator+=(const String &str)
    {
        
        if(_pstr==nullptr || sizeof(_pstr) < strlen(_pstr) + strlen(str._pstr) + 1)
        {
            char * tmp = _pstr;
            tmp = new char[strlen(_pstr) + strlen(str._pstr) + BLOCK_SIZE + 1];
            sprintf(tmp, "%s%s", _pstr, str._pstr);
            if(_pstr)
                delete []_pstr;
            _pstr = tmp;
        } else {
            sprintf(_pstr, "%s%s", _pstr, str._pstr);
        }

        return *this;
    }


    /* 拼接C风格字符串 */
    String& String::operator+=(const char *str)
    {
        return *this += String(str);
    }

    /* 重载[]方便调用容器中的成员 */
    char &String::operator[](std::size_t index)
    {
        return _pstr[index];
    }

    /* const风格[]重载 */
    const char &String::operator[](std::size_t index) const
    {
        return _pstr[index];
    }

    /* 查看长度 */
    std::size_t String::size() const
    {
        return strlen(_pstr);
    }

    /* 传出只读的 C风格字符串 */
    const char* String::c_str() const
    {
        return _pstr;
    }

    /* 封装 strcmp 函数进行判断 */
    bool operator==(const String &s1, const String &s2)
    {
        return !strcmp(s1._pstr, s2._pstr);
    }

    /* 封装 strcmp 函数进行判断 */
    bool operator!=(const String &s1, const String &s2)
    {
        return !operator==(s1, s2);
    }

    /* 封装 strcmp 函数进行判断 */
    bool operator<(const String &s1, const String &s2)
    {
        return strcmp(s1._pstr, s2._pstr) < 0;
    }

    /* 封装 strcmp 函数进行判断 */
    bool operator>(const String &s1, const String &s2)
    {
        return strcmp(s1._pstr, s2._pstr) > 0;
    }

    /* 封装 strcmp 函数进行判断 */
    bool operator<=(const String &s1, const String &s2)
    {
        return strcmp(s1._pstr, s2._pstr) <= 0;
    }

    /* 封装 strcmp 函数进行判断 */
    bool operator>=(const String &s1, const String &s2)
    {
         return strcmp(s1._pstr, s2._pstr) >= 0;
    }

    /* 输出友元函数 */
    std::ostream& operator<<(std::ostream &os, const String &s)
    {
        return os<<s._pstr;
    }

    /* 输入友元函数 */
    std::istream& operator>>(std::istream &is, String &s)
    {
        vector<char> buff;
        char ch;
        while((ch = is.get()) != '\n' && ch != EOF)
            buff.push_back(ch);
        buff.push_back(0);
        s = &buff[0];
        return is;
    }

    /* 重载加法函数 */
    String operator+(const String &s1, const String &s2)
    {
        String tmp = s1;
        tmp += s2;
        return tmp;
    }

    /* 重载加法函数 */
    String operator+(const String &s1, const char *s2)
    {
        return s1 + String(s2);
    }

    /* 重载加法函数 */
    String operator+(const char *s1, const String &s2)
    {
        return String(s1) + s2;
    }
}
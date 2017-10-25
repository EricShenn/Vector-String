//
//  Mystring.cpp
//  向量类的重新设计
//
//  Created by 沈博南 on 2017/10/24.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include "Mystring.hpp"
#include <cstring>

mystring::mystring(const char *str)
{
    if (!str) {
        dimension = 0;
        space = NULL;
    }
    space = new char[dimension =(int)strlen(str)];
    strcpy(space, str);
}
mystring::mystring(const mystring &str)
{
    if(space) delete [] space;
    space = new char[dimension = (int)strlen(str.space)];
    strcpy(space, str.space);
}

mystring &mystring::operator=(const mystring &str)
{
    if(space) delete [] space;
    space = new char[dimension = (int)strlen(str.space)];
    strcpy(space, str.space);
    return *this;
}

istream & operator >>(istream &in,mystring &str)
{

    char s[999];
    gets(s);
    mystring tmp(s);
    str = s;
    return in;
}


ostream & operator <<(ostream &out,const mystring &str)
{
    puts(str.space);
    return out;
}

mystring &mystring::operator+(const mystring &str)
{
    mystring *tmp = new mystring(*this);
    strcpy(tmp->space+strlen(this->space), str.space);
    return *tmp;
    
}

int mystring::compare(const mystring &str)
{
    return strcmp(this->space, str.space);
}

int mystring::len()
{
    return this->dimension;
}

void mystring::show()
{
    cout<<*this;
}


bool mystring::operator>(const mystring &str)
{
    if(this->compare(str)>0)
        return 1 ;
    return 0;
}

void mystring::test_for_len()
{
    cout<<this->length;
}






str_vir::str_vir(const char *str,int num)
:mystring(str),special_num(num)
{
    ;
}
void str_vir::show()
{
    cout<<*this;
    cout<<this->special_num<<endl;
}




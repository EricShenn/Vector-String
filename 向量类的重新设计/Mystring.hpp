//
//  Mystring.hpp
//  向量类的重新设计
//
//  Created by 沈博南 on 2017/10/24.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#ifndef Mystring_hpp
#define Mystring_hpp

#include <stdio.h>
#include "Vector.hpp"
#endif /* Mystring_hpp */

class mystring:public Vector<char>
{
public:
    mystring(const char* str);
    mystring(const mystring &str);
    mystring &operator= (const mystring &str);
    friend ostream & operator <<(ostream &out,const mystring &str);
    friend istream & operator >>(istream &in,mystring &str);
    mystring & operator +(const mystring &str);
    int compare(const mystring &str);
    int len();
    void show();
    bool operator==(const mystring &str);
    bool operator!=(const mystring &str);
    bool operator> (const mystring &str);
    bool operator< (const mystring &str);
    
    
    void test_for_len();
    
protected:
    int &length = dimension;
};






class str_vir:public mystring
{
public:
    str_vir(const char *str,int num);
    void show();
protected:
    int special_num;
};










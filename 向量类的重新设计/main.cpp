//
//  main.cpp
//  向量类的重新设计
//
//  Created by 沈博南 on 2017/10/11.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include <iostream>

#include "Mystring.hpp"


int main(int argc, const char * argv[]) {
    
//  while(1)
  {
      cout<<"创建string s1,s2:\n"<<endl;
      mystring s1 = "test of s1",s2("testfors2");
      cout<<s1<<"长度:"<<s1.len()<<"\n\n"<<s2<<"长度:"<<s2.len()<<endl;
      
      cout<<"\n重载+运算符"<<" s1+s2 = "<<s1+s2<<endl;
      
      cout<<"字符串比较，比较s1和s2      "<<s1.compare(s2)<<"    "<<(s1>s2)<<endl;
      
      
      
      cout<<"\n\n动态多态性测试"<<endl;
      
      
      mystring s3("test for polymorphism");
      str_vir s4("test for polymorphism",65535);
      Vector<char> &tmp = s3, &tmp2 = s4, base(21,"test for polymorphism");
      
      base.show();
      tmp.show();
      tmp2.show();
      
  
      
  }
    
    
    return 0;
}

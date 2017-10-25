//
//  Vector.hpp
//  向量类的重新设计
//
//  Created by 沈博南 on 2017/10/11.
//  Copyright © 2017年 沈博南. All rights reserved.
//


#ifndef Vector_hpp
#define Vector_hpp

#include <iostream>

#endif /* Vector_hpp */


using namespace std;

template <typename T>
class Vector
{
public:
    Vector(int size=0,const T *other=NULL);
    Vector(const Vector &vec);
  //  Vector(int size,const int *other);
    
    virtual void show();
    int getdim();
    Vector<T> redim(int redimension);
    template <typename TYPE>friend ostream & operator<<(ostream &out, const Vector<TYPE> &v);
    
    //template <typename TYPE>friend istream & operate>>
    
    Vector<T> operator+(const Vector<T> &vec);
    Vector<T> & operator=(const Vector<T> &vec);
    Vector<T> & operator+=(const Vector<T> &vec) throw(char*);
    T & operator [] (const int num);
    
    
 
protected:
    int dimension;
    T *space;
    
};

template <typename T>
T & Vector<T>::operator [] (const int num)
{
    return space[num];
}


template <typename T>
Vector<T>::Vector(int size,const T *other)
{
    dimension = size;
    if(dimension<=0){
        dimension = 0;
        space = NULL;
        return;
    }
    else{
    space = new T[dimension];
    for (int i=0;i<dimension;i++)
        space[i] = (other!=NULL? other[i]:0);
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &vec)
{
    //if(space!=NULL)
    //    delete [] space;
    space = new T[vec.dimension];
    dimension = vec.dimension;
    for(int i=0;i<=dimension;i++)
        space[i] = vec.space[i];
        
    
}


template <typename T>
void Vector<T>::show()
{
    if (dimension == 0)
        cout<<"()"<<endl;
    else{
        cout<<"(";
        for(int i=0;i<dimension;i++)
            cout<<space[i]<<" ";
        cout<<")"<<endl;
}
}


template<typename T>
int Vector<T>::getdim()
{
    return this->dimension;
}

template<typename T>
Vector<T> Vector<T>::redim(int redimension)
{
    delete [] space;
    space = new T [redimension];
    return *this;
    

}



template <typename TYPE> ostream & operator<<(ostream &out, const Vector<TYPE> &v)
{
    if(v.dimension==0)
        out << "()";
    else
    {
        out << '(' << v.space[0];
        for(int i=1; i<v.dimension; i++)
            out << ", " << v.space[i];
        out << ')';
    }
    return out;                  
}


template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &vec)
{
    
    int dim = min(dimension,vec.dimension);
    Vector<T> tmp(dim);
    delete [] tmp.space;
    tmp.space = new T [dim];
    
    for(int i=0;i<dim;i++)
        tmp.space[i] = space[i]+vec.space[i];

    return tmp;
}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> &vec)
{
    if (space)
        delete [] space;
    space = new T[dimension = vec.dimension];
    for(int i=0;i<vec.dimension;i++)
        space[i] = vec.space[i];
    return *this;
}


template <typename T>
Vector<T> & Vector<T>::operator+=(const Vector<T> &vec) throw(char*)
{
    if (dimension!=vec.dimension)
        throw "dimension not match";
    for (int i=0;i<dimension;i++)
        space[i] = space[i] + vec.space[i];
        return *this;
}



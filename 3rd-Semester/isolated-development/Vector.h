#include<iostream>
#ifndef _VECTOR_H_
#define _VECTOR_H_

namespace abj{

template<typename T>
class Vector{
    private:
        T* storage;
        int curr_size;
        int capacity;
    public:
        Vector();
        void push(T& data);
        ~Vector();
        int size();

        T operator [](int index);

};
}

template<typename T>
abj::Vector<T>::Vector(){
    this->storage = (T*)calloc(this->capacity, sizeof(T));
    this->capacity=2;
    this->curr_size=0;
}

template<typename T>
abj::Vector<T>::~Vector(){
    //free(this->storage);
    this->curr_size=0;

    this->storage = (T*)calloc(this->capacity, sizeof(T));
    this->capacity=2;
}

template<typename T>
int abj::Vector<T>::size(){
    return this->curr_size;
}

template<typename T>
void abj::Vector<T>::push(T& data){
    if(this->curr_size+1>=this->capacity){
        T* temp = (T*)calloc(this->capacity*2, sizeof(T));
        this->capacity*=2;

        for(int i=0; i<this->curr_size; i++) temp[i]=this->storage[i];
        free(this->storage);
        this->storage=temp;
    }
    this->storage[this->curr_size++] = data;
}

template<typename T>
T abj::Vector<T>::operator [](int index){
    return this->storage[index];
}


#endif

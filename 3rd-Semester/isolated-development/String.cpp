#include "String.h"

abj::String::String(const char* data){
    int size=0;
    while(data[size]!='\0') size++;

    this->storage = (char*)calloc(size, sizeof(char));
    for(int i=0; i<size; i++) this->storage[i] = data[i];
    this->storage[size] = '\0';
    this->curr_size=size;
}

void abj::String::print(){
    std::cout<<this->storage<<std::endl;
}

int abj::String::size(){
    return this->curr_size;
}

abj::String::~String(){
    //free(this->storage);
}

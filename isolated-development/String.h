#include<iostream>
#ifndef _STRING_H_
#define _STRING_H_

namespace abj{
class String{
    private:
        char* storage;
        int curr_size;
    public:
        String(const char* data);
        ~String();

        int size();
        void print();
};
}

#endif

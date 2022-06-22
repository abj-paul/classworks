#include<iostream>
#include "String.h"
#include "Vector.h"

void usual();
void smol_problem();
void kill_me_problem();
void sedate_me_problem();

int main(){
    //usual();
    //smol_problem();
    //kill_me_problem();
    sedate_me_problem();
return 0;
}

void usual(){
    int a=1,b=3,c=5,d=-10;
    abj::Vector<int> v;
    v.push(a);
    v.push(b);
    v.push(c);
    v.push(d);

    for(int i=0; i<v.size(); i++) std::cout<<v[i]<<",";
    std::cout<<std::endl;

}

void smol_problem(){
    abj::String a("Abhi");
    abj::String b("jit");
    abj::String c("paul");

    abj::Vector<abj::String> v;
    v.push(a);
    v.push(b);
    v.push(c);

    for(int i=0; i<v.size(); i++) v[i].print();
}

void kill_me_problem(){
    int a=1,b=3,c=5,d=-10;
    abj::Vector<int> v1,v2;
    v1.push(a);
    v1.push(b);

    v2.push(c);
    v2.push(d);

    abj::Vector<abj::Vector<int>> store_vector;
    store_vector.push(v1);
    store_vector.push(v2);

    for(int i=0; i<store_vector.size(); i++){
        for(int j=0; j<store_vector[i].size(); j++)
            std::cout<<store_vector[i][j]<<",";
        std::cout<<std::endl;
    }

}

void sedate_me_problem(){
    abj::String a("Abhi");
    abj::String b("jit");
    abj::String c("paul");
    abj::String d("Abhi");

    abj::Vector<abj::String> v1,v2;
    v1.push(a);
    v1.push(b);

    v2.push(c);
    v2.push(d);

    abj::Vector<abj::Vector<abj::String>> store_vector;
    store_vector.push(v1);
    store_vector.push(v2);

    for(int i=0; i<store_vector.size(); i++){
        for(int j=0; j<store_vector[i].size(); j++)
            store_vector[i][j].print();
    }

}

void is_the_problem_really_resolved(){

}

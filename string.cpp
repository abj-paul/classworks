#include "string.h"

abj::String::String(){
	this->storage=NULL;
	this->curr_size=0;
}

abj::String::String(char* data){
	int size=0;
	while(data[size]!='\0') size++;

	this->storage = (char*)malloc
}

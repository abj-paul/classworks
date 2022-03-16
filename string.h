#include<iostream>

namespace abj{
class String{
	private:
		char* storage;
		int curr_size;
	public:
		String();
		String(char* data);
		void initialize(char* data);

		void print();
		std::vector<abj::String> split(char separator);

};
}

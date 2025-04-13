#include "Serializer.hpp"

int main()
{
    Data tmp;
    tmp.c = 'a';
    tmp.i = 1;
	Data *ptr = &tmp;
	try
	{
		uintptr_t num = Serializer::serialize(ptr);

		Data *new_ptr = Serializer::deserialize(num);
        std::cout << "Num == " << num << std::endl;
		std::cout << "Ptr == " << ptr << std::endl;
		std::cout << "New Ptr == " << new_ptr << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
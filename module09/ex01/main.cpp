#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr<<"Invalid number of arguments!" << std::endl;
		return 1;
	}
	RPN c;
	try 
	{
		int res = c.calculateResult(argv[1]);
		std::cout << res << std::endl;
	} catch(std::runtime_error &e)
	{
		std::cerr<<e.what()<<std::endl;
	}
}
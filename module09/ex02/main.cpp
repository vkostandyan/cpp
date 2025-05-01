#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	
	if (argc < 2)
	{
		std::cerr<<"Invalid number of arguments!" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe a;
		a.fill(argc, argv);
		a.manage();	
	}catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
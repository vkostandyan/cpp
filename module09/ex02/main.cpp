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
	// a.fill(argc, argv);
	// std::cout << "Vector: ";
	// for(std::vector<int>::const_iterator it = a.vec.begin(); it != a.vec.end(); ++it)
	// 	std::cout << *it << " ";
    // std::cout << std::endl;

	// std::cout << "Deque: ";
	// for(std::deque<int>::const_iterator it2 = a.deq.begin(); it2 != a.deq.end(); ++it2)
	// 	std::cout << *it2 << " ";
    // std::cout << std::endl;
	(void)argv;
}
#include "Span.hpp"

int main()
{
    try 
	{
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
		// sp.addNumber(42);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

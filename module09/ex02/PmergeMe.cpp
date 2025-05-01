#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this -> deq = other.deq;
	this -> vec = other.vec;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
    {
        this -> deq = other.deq;
        this -> vec = other.vec;
    }
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::fill(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);

		if (arg.size() > 10 || 
			arg.find_first_not_of("+0123456789") != std::string::npos ||
			(arg.find('+') != std::string::npos && arg[0] != '+'))
			throw std::runtime_error("Invalid input");

		std::stringstream ss(arg);
		long value;
		ss >> value;

		if (ss.fail() || !ss.eof())
			throw std::runtime_error("Conversion failed");

		if (value > 2147483647L)
			throw std::runtime_error("Number is bigger than INT_MAX");

		vec.push_back(static_cast<int>(value));
		deq.push_back(static_cast<int>(value));
	}
}

template <typename T>
void PmergeMe::sort(T &c)
{
	if (c.size() <= 1)
		return;
	T a, b;

	for (size_t i = 0; i + 1 < c.size(); i += 2)
	{
		if (c[i] < c[i + 1])
		{
			a.push_back(c[i + 1]);
			b.push_back(c[i]);
		}
		else
		{
			a.push_back(c[i]);
			b.push_back(c[i + 1]);
		}
	}
	bool hasOdd = c.size() % 2 != 0;
	int odd;
	if (hasOdd)
		odd = c.back();

	sort(a);
	for (size_t i = 0; i < b.size(); i++)
	{
	typename T::iterator pos = std::lower_bound(a.begin(), a.end(), b[i]);
	a.insert(pos, b[i]);  // ✅ Correct: insert from b
	}
	if (hasOdd)
	{
		typename T::iterator pos = std::lower_bound(a.begin(), a.end(), odd);
		a.insert(pos, odd);
	}
	c = a;
}

void PmergeMe::print()
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout<<" "<<vec[i];
	std::cout<<std::endl;
}

void PmergeMe::manage()
{
    int size = vec.size();
    std::cout<<"Before: ";
	this->print();
    std::clock_t start = std::clock();
	this->sort(this->vec);
	std::clock_t end = std::clock();
	double vec_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	start = std::clock();
	this->sort(this->deq);
	end = std::clock();
	double deq_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::vector<int> : " << vec_time * 1000000 << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque<int> : " << deq_time * 1000000 << " us" << std::endl;
}
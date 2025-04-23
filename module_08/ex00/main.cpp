#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm> // for std::find

// easyfind template
template <typename T>
typename T::iterator easyfind(T &container, int value) {
	return std::find(container.begin(), container.end(), value);
}

// run function from you
template <typename T>
void run(T &container, int value)
{
	typename T::iterator it = easyfind(container, value);
	if (it != container.end())
		std::cout << "Found: " << *it << " in container" << std::endl;
	else
		std::cout << "Value " << value << " not found in container" << std::endl;
}

int main() 
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	run(v, 30);
	run(v, 100);

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	run(l, 3);
	run(l, 5);

	std::deque<int> d;
	d.push_back(100);
	d.push_back(200);
	d.push_back(300);
	run(d, 200);
	run(d, 400);

	std::vector<int> vd;
	vd.push_back(11);
	vd.push_back(22);
	vd.push_back(33);
	run(vd, 33);
	run(vd, 55);

	return 0;
}

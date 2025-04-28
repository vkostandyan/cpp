#ifndef Serializer_HPP
# define Serializer_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
	int i;
	char c;
};

class Serializer
{
public:
    static uintptr_t serialize(Data*);
    static Data* deserialize(uintptr_t);
private:
    Serializer();
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
	virtual ~Serializer();
};

#endif
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		this->slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		delete this->slots[i];
		this->slots[i] = rhs.slots[i]->clone();
	}
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << "MateriaSource copy assignment called." << std::endl;
	if (&rhs != this)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete this->slots[i];
			this->slots[i] = rhs.slots[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		delete this->slots[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!this->slots[i])
		{
			this->slots[i] = m;
            std::cout<<"MateriaSource learnMateria called successfully!\n";
			return;
		}
	}
    std::cout<<"The slot is full!\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->slots[i] && this->slots[i]->getType() == type)
			return this->slots[i]->clone();
	}
	return (0);
}
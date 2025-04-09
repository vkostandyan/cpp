#include "Character.hpp"

Character::Character() : name("Unknown character")
{
    std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		this->slots[i] = NULL;
}

Character::Character(const std::string& name) : name(name)
{
    std::cout << "Character parameter constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		this->slots[i] = NULL;
}

Character::Character(const Character &rhs) : name(rhs.name)
{
	std::cout << "Character copy constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (rhs.slots[i])
		{
			delete this->slots[i];
			this->slots[i] = rhs.slots[i]->clone();
		}
		else
			this->slots[i] = NULL;
	}
}

const Character &Character::operator=(const Character &rhs)
{
	std::cout << "Character copy assignment called." << std::endl;
	if (&rhs != this)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			delete this->slots[i];
			this->slots[i] = rhs.slots[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
    std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
        delete this->slots[i];
}

const std::string &Character::getName() const { return (this->name); }

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!this->slots[i])
		{
			this->slots[i] = m;
            std::cout<<"Character equip called successfully!\n";
			return;
		}
	}
    std::cout<<"The inventory is full!\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->slots[idx] = NULL;
        // inchu voch nayev delete
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->slots[idx])
		this->slots[idx]->use(target);
}
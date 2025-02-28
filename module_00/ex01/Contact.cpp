#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

const std::string Contact::get_first_name()
{
    return (this->first_name);
}

const std::string Contact::get_last_name()
{
    return (this->last_name);
}

const std::string Contact::get_nick_name()
{
    return (this->nick_name);
}

const std::string Contact::get_phone_number()
{
    return (this->phone_number);
}

const std::string Contact::get_darkest_secret()
{
    return (this->darkest_secret);
}

void Contact::set_first_name(const std::string &f_name)
{
	this->first_name = f_name;
}
void Contact::set_last_name(const std::string &l_name)
{
	this->last_name = l_name;
}
void Contact::set_nick_name(const std::string &n_name)
{
	this->nick_name = n_name;
}
void Contact::set_phone_number(const std::string &p_number)
{
	this->phone_number = p_number;
}

void Contact::set_darkest_secret(const std::string &d_secret)
{
	this->darkest_secret = d_secret;
}

int isalpha_str(const std::string &name)
{
	for (int i = 0; name[i]; i++)
	{
		if(!isalpha(name[i]))
			return(0);
	}
	return(1);
}
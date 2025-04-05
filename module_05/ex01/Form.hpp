#ifndef Form_HPP
# define Form_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form();
    Form(const std::string, const bool, const int, const int);
    Form(const Form&);
    const Form& operator=(const Form&);
    ~Form();
public:
    const std::string &getName(void) const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &);
public:
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
private:
    const std::string   name;
    bool                isSigned;
    const int           signGrade;
    const int           executeGrade;
};

std::ostream&	operator<<(std::ostream& os, const Form& ob);

#endif
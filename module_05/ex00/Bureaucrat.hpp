#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string&, int);
    Bureaucrat(const Bureaucrat&);
    const Bureaucrat& operator=(const Bureaucrat&);
    ~Bureaucrat();
public:
    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
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
    const std::string name;
    int grade;
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);

#endif
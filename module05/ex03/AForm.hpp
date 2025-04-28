#ifndef AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const std::string, const bool, const int, const int);
    AForm(const AForm&);
    const AForm& operator=(const AForm&);
    virtual ~AForm();
public:
    const std::string &getName(void) const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &);
    void checkExecute(const Bureaucrat &) const;
    void validateGrade(int grade);
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
    class IsSignedException : public std::exception 
    {
        public:
            const char* what() const throw();
    };
protected:
    virtual void execute(Bureaucrat const &executor) const = 0;
private:
    const std::string   name;
    bool                isSigned;
    const int           signGrade;
    const int           executeGrade;
};

std::ostream&	operator<<(std::ostream& os, const AForm& ob);

#endif
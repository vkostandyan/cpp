#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

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
    void decrenentGrade();
private:
    const string name;
    int grade;
};

#endif
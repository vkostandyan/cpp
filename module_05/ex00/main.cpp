#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat ob("Bob", 6);
        Bureaucrat ob2;
        std::cout<<ob2;
        ob2 = ob;
        std::cout<<ob2;
        ob2.incrementGrade();
        ob2.incrementGrade();
        ob2.incrementGrade();
        ob2.incrementGrade();
        // ob2.incrementGrade();
        // ob2.incrementGrade();
        // ob2.incrementGrade();
        // ob2.incrementGrade();
        // ob2.incrementGrade();
        // ob2.incrementGrade();
        // ob2.incrementGrade();
        // ob2.incrementGrade();
        ob2.decrementGrade();
        ob2.decrementGrade();
        ob2.decrementGrade();
        std::cout<<ob2;
        std::cout<<ob;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
}
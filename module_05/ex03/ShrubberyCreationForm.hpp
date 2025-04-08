#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#define tree                            \
	"          	  &&&& \n"              \
	"          &&& &&  & &&\n"          \
	"      && &\\/&\\|& ()|/ @, &&\n"   \
	"      &\\/(/&/&||/& /_/)_&/_&\n"   \
	"   &() &\\/&|()|/&\\/ '%\" & ()\n" \
	"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n" \
	"&&   && & &| &| /& & % ()& /&&\n"  \
	" ()&_---()&\\&\\|&&-&&--%---()~\n" \
	"     &&     \\|||\n"               \
	"             |||\n"                \
	"             |||\n"                \
	"             |||\n"                \

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
    void execute(Bureaucrat const &) const;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string&);
    ShrubberyCreationForm(const ShrubberyCreationForm&);
    const ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm();
private:
    std::string target;
};

#endif
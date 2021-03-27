/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 19:45:07 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 10:48:58 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", "", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
}


ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	AForm::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	performChecks(executor, *this);
	std::string	fileName = getTarget() + "_shrubbery";
	std::ofstream	out(fileName.c_str());
	out.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	out << "          .     .  .      +     .      .          . \n\
     .       .      .     #       .           . \n\
        .      .         ###            .      .      . \n\
      .      .   .#:. .:##o##:. .:#o  .      . n=\n\
          .      . o####o###o####o  .\n\
       .     .#:.    .:#o###o#:.    .:#o  .        .       . \n\
  .             .#########o#########o        .        . \n\
        .    .#:.  o####o###o####o  .:#o   .       .\n\
     .     .  .#######oo##o##oo#######o                  .\n\
                .o##o#####o#####o##o           .      . \n\
    .   .#:. ...  .:##o###o###o##:.  ... .:#o     . \n\
      .     o#######o##o#####o##o#######o      .     .j\n\
    .    .     o#####oo#######oo#####o    .      .j\n\
            .     o      III      o    .     .\n\
       .         .   .   III     .        .       .\n\
.. .. ..................O000O........................ ...... ..o " << std::endl;
	out << " '.,\n\
                              'b      *\n\
                               '$    #.\n\
                                $:   #:\n\
                                *#  @):\n\
                                :@,@):   ,.**:'\n\
                      ,         :@@*: ..**'\n\
                       '#o.    .:(@'.@*i\n\
                          bq,..:,@@*'   ,*\n\
                          ,p$q8,:@)'  .p*'\n\
                         '    '@@Pp@@*'\n\
                               Y7'.'\n\
                              :@):.\n\
                             .:@:u.\n\
                           .::(@:. " << std::endl;
	out.close();
}

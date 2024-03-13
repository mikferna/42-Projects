/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:09:02 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/11 13:52:20 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
    Bureaucrat bureaucrat("ash", 1);

    std::cout << bureaucrat << std::endl;

    bureaucrat.decrementGrade();
	std::cout << bureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "================================\n";
    try{
    Bureaucrat bureaucrat1("ley", 150);

    std::cout << bureaucrat1 << std::endl;

    bureaucrat1.incrementGrade();
	std::cout << bureaucrat1 << std::endl;
    } catch (Bureaucrat::GradeTooLowException &a){
        std::cout << a.what() << std::endl;
    }
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:41:23 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/28 13:10:22 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& obj );
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=( const RobotomyRequestForm& obj );

		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif
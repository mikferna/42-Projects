/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:41:44 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/28 13:10:36 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& obj );
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=( const PresidentialPardonForm& obj );

		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif
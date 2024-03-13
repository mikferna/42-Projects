/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:12:15 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:42 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"

Base *generate()
{
	std::srand(std::time(0));
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "Created A" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "Created B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Created C" << std::endl;
		return new C();
	}
}

void identify_from_pointer(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer C" << std::endl;
}

void identify_from_reference(Base& p)
{
	try{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Reference A\n";
		(void)a;
	} catch (std::bad_cast){
		try{
			B& b = dynamic_cast<B&>(p);
			std::cout << "Reference B\n";
			(void)b;
		} catch (std::bad_cast){
			try{
				C& c = dynamic_cast<C&>(p);
				std::cout << "Reference C\n";
				(void)c;
			} catch (std::bad_cast){
				
			}
		}
	}
}

int main()
{
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}

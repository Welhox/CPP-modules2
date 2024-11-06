/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:46:25 by clundber          #+#    #+#             */
/*   Updated: 2024/11/04 16:27:21 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base * generate(void)
{
	static int rand = 0;
	std::srand(std::time(0));
	int random = std::rand() + rand;
	rand++;
	random %= 3;
	switch (random)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		throw std::invalid_argument("a error happend with rng");
		break;
	}
}

void identify(Base* p)
{
	std::string _class = "invalid";
	if (dynamic_cast<A*>(p) != nullptr)
		_class = "A";
	else if (dynamic_cast<B*>(p) != nullptr)
		_class = "B";
	else if (dynamic_cast<C*>(p) != nullptr)
		_class = "C";
	std::cout << "class = " << _class << std::endl;	
}

void identify(Base& p)
{
	std::string _class = "invalid";
	try{
		A temp = dynamic_cast<A&>(p); 
		_class = "A";}
	catch(const std::exception& e){}
	try{
		B temp = dynamic_cast<B&>(p); 
		_class = "B";}
	catch(const std::exception& e){}
	try{
		C temp = dynamic_cast<C&>(p); 
		_class = "C";}
	catch(const std::exception& e){}

	std::cout << "class = " << _class << std::endl;
	
}

int	main()
{
	try
	{
		Base *rand = nullptr;
		Base *rand2 = nullptr;
		
		rand = generate();
		rand2 = generate();
		try
		{
			identify(rand);
			identify(*rand);
			identify(rand2);
			identify(*rand2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete rand;
		delete rand2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
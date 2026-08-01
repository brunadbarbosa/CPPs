/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:58:27 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/30 11:31:45 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	// --- original tests ---
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	delete meta;
	delete j;
	delete i;

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongI = new WrongCat();
	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongI->getType() << " " << std::endl;
	wrongMeta->makeSound();
	wrongI->makeSound();
	delete wrongMeta;
	delete wrongI;

	// --- Brain deep copy test ---
	Dog *dog1 = new Dog();
	dog1->getBrain()->setIdea(0, "I want to chase the cat");
	dog1->getBrain()->setIdea(1, "I want treats");

	Dog *dog2 = new Dog(*dog1);
	std::cout << "dog1 idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;

	dog2->getBrain()->setIdea(0, "I want to sleep");
	std::cout << "After changing dog2's idea:" << std::endl;
	std::cout << "dog1 idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;

	delete dog1;
	delete dog2;
} 

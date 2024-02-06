/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:52:06 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/06 19:57:23 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <limits>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	book;
	std::string	input;

	while (true)
	{
		std::cout << "1. ADD\n2. SEARCH\n0. EXIT\nEnter a command : ";
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << "\nInput ended. Exiting.\n\n";
				return 0;
			} else {
				std::cerr << "\nError reading input. Exiting.\n\n";
				return 1;
			}
		}
		if (input == "EXIT" || input == "0")
			break;
		else if (input == "ADD" || input == "1")
			book.addContact();
		else if (input == "SEARCH" || input == "2")
			book.searchContact();
	}
	return 0;
}

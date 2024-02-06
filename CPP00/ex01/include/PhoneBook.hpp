/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:41:48 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/06 19:41:33 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <stdio.h>


class	PhoneBook {
	public:
		PhoneBook();

		void addContact(void);
		void searchContact(void);

	private:
		static const int MAX_CONTACTS = 8;

		Contact	contacts[MAX_CONTACTS];
		int	saved_contacts_size;
		int	oldest_contact_index;

		std::string	getInput(std::string prompt);
		std::string	inputPhoneNumber(void);
		std::string	truncateString(const std::string& str, size_t width);
		void		showContacts(void);
		void		showContactData(int index);
		void		resetInputStream(void);
		bool		isAllDigits(const std::string& str);
		int			inputSearchIndex(void);
};

#endif
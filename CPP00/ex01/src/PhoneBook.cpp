/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:41:51 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/08 14:10:32 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/********************************************************************/
/*                          DEFAULT CONSTRUCTOR                     */
/********************************************************************/

PhoneBook::PhoneBook() :
		saved_contacts_size(0), oldest_contact_index(0) {}

/********************************************************************/
/*                          PUBLIC                                  */
/********************************************************************/

void PhoneBook::addContact(void) {
	Contact new_contact;
	std::string input;

	new_contact.setFirstName(getInput("First name"));
	if (new_contact.getFirstName().empty())
		return;
	new_contact.setLastName(getInput("Last name"));
	if (new_contact.getLastName().empty())
		return;
	new_contact.setNickname(getInput("Nickname"));
	if (new_contact.getNickname().empty())
		return;
	new_contact.setPhoneNumber(inputPhoneNumber());
	if (new_contact.getPhoneNumber().empty())
		return;
	std::cout << "What is your darkest secret? i'll never tell anyone, i promise. 😈" << std::endl;
	new_contact.setSecret(getInput("Dark secret"));
	if (new_contact.getSecret().empty())
		return;

	std::cout << "Contact added successfully. 👌" << std::endl
			  << std::endl;
	std::cout << std::endl;
	std::cout << "CONTACT DATA:" << std::endl;
	std::cout << "First name:  " << new_contact.getFirstName() << std::endl;
	std::cout << "Last name:   " << new_contact.getLastName() << std::endl;
	std::cout << "Nickname:    " << new_contact.getNickname() << std::endl;
	std::cout << "Phonenumber: " << new_contact.getPhoneNumber() << std::endl;
	std::cout << "Secret:      " << new_contact.getSecret() << std::endl
			  << std::endl;

	if (oldest_contact_index < MAX_CONTACTS) {
		contacts[oldest_contact_index] = new_contact;
	} else {
		oldest_contact_index = 0;
		contacts[oldest_contact_index] = new_contact;
	}
	oldest_contact_index++;
	if (saved_contacts_size < MAX_CONTACTS)
		saved_contacts_size++;
}

void PhoneBook::searchContact(void) {
	int index = 0;

	if (saved_contacts_size == 0) {
		std::cout << "Contact list is empty." << std::endl;
		return;
	}
	showContacts();
	index = inputSearchIndex();
	if (index == -1)
		return;
	showContactData(index);
}

/********************************************************************/
/*                          PRIVATE                                 */
/********************************************************************/

bool PhoneBook::isAllDigits(const std::string &str) {
	for (std::string::size_type i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

void PhoneBook::resetInputStream(void) {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	clearerr(stdin);
}

std::string PhoneBook::getInput(std::string prompt) {
	std::string input = "";

	std::cout << "Enter " << prompt << ": ";
	while (true) {
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << "\nInput ended. ";
			} else {
				std::cerr << "\nError reading input. ";
			}
			std::cout << "Contact wasn't added.\n\n";
			resetInputStream();
			return "";
		}
		if (input.empty()) {
			std::cout << "Please insert something!!\n";
			std::cout << "Enter " << prompt << ": ";
			continue;
		}
		return input;
	}
}

std::string PhoneBook::inputPhoneNumber(void) {
	std::string input = "";

	std::cout << "Enter phonenumber: ";
	while (true) {
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << "\nInput ended. ";
			} else {
				std::cerr << "\nError reading input. ";
			}
			std::cout << "Contact wasn't added.\n\n";
			resetInputStream();
			return "";
		}
		if (input.empty() || !isAllDigits(input)) {
			std::cout << "Cannot be empty and could only consist out of numbers" << std::endl;
			std::cout << "Enter phonenumber: ";
			continue;
		}
		return input;
	}
}

int PhoneBook::inputSearchIndex(void) {
	std::string input = "";
	int index = 0;

	while (true) {
		std::cout << "Enter the index you want to see [1-" << saved_contacts_size << "]: ";
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << "\nInput ended. ";
			} else {
				std::cerr << "\nError reading input. ";
			}
			std::cout << "Returning to main menu.\n\n";
			resetInputStream();
			return -1;
		}
		if (input.empty()) {
			std::cout << "Index cannot be empty." << std::endl;
		} else if (!isAllDigits(input)) {
			std::cout << "Invalid input. Only numeric values without whitespaces" << std::endl;
		} else {
			index = std::atoi(input.c_str());
			if (index <= 0 || index > saved_contacts_size) {
				std::cout << "Invalid index. Please enter a valid index." << std::endl;
			} else {
				return index - 1;
			}
		}
	}
}

std::string PhoneBook::truncateString(const std::string &str, size_t width = 10) {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	}
	return str;
}

void PhoneBook::showContacts(void) {
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index"
			  << "|";
	std::cout << std::setw(10) << "First name"
			  << "|";
	std::cout << std::setw(10) << "Last name"
			  << "|";
	std::cout << std::setw(10) << "Nickname"
			  << "|" << std::endl;
	for (int i = 0; i < saved_contacts_size; i++) {
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::showContactData(int index) {
	std::cout << std::endl;
	std::cout << "First name:     " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name:      " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:       " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number:   " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getSecret() << std::endl;
	std::cout << std::endl;
}

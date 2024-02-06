/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:52:10 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/01 16:56:55 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string str) {
	this->first_name = str;
}

void Contact::setLastName(std::string str) {
	this->last_name = str;
}

void Contact::setNickname(std::string str) {
	this->nickname = str;
}

void Contact::setPhoneNumber(std::string str) {
	this->phone_number = str;
}

void Contact::setSecret(std::string str) {
	this->secret = str;
}

const std::string&	Contact::getFirstName(void) {
	return this->first_name;
}

const std::string&	Contact::getLastName(void) {
	return this->last_name;
}

const std::string&	Contact::getNickname(void) {
	return this->nickname;
}

const std::string&	Contact::getPhoneNumber(void) {
	return this->phone_number;
}

const std::string&	Contact::getSecret(void) {
	return this->secret;
}

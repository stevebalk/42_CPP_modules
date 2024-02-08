/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:10:27 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/08 14:10:03 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
	void setFirstName(std::string);
	const std::string &getFirstName(void);

	void setLastName(std::string);
	const std::string &getLastName(void);

	void setNickname(std::string);
	const std::string &getNickname(void);

	void setPhoneNumber(std::string);
	const std::string &getPhoneNumber(void);

	void setSecret(std::string);
	const std::string &getSecret(void);

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
};

#endif
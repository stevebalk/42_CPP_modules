/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:51:49 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/31 14:27:24 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

std::string string_to_upper(std::string str)
{
	int	length;

	length = str.length();
	for (int i = 0; i < length; i++)
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << string_to_upper(argv[i]);
		std::cout << std::endl;
	}
}

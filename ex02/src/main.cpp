/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:41 by edetoh            #+#    #+#             */
/*   Updated: 2025/02/14 12:09:26 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../includes/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "Initial value of a: " << a << std::endl;
	std::cout << "Increment a (prefix): " << ++a << std::endl;
	std::cout << "Value of a after prefix increment: " << a << std::endl;
	std::cout << "Increment a (postfix): " << a++ << std::endl;
	std::cout << "Value of a after postfix increment: " << a << std::endl;
	std::cout << "Value of b: " << b << std::endl;
	std::cout << "Maximum value between a and b: " << Fixed::max( a, b ) << std::endl;
	return 0;
}
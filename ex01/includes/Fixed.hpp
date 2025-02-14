/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:03:22 by edetoh            #+#    #+#             */
/*   Updated: 2025/02/14 12:20:40 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <string>

class Fixed
{
private:
	int fixedPoint;
	static const int fractionalBits = 8;

public:
	/* ------------------------------- Constructor ------------------------------ */
	Fixed();
	Fixed(const int integer);
	Fixed(const float float_nbr);
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed &copy);
	~Fixed();
	/* -------------------------------- Functions ------------------------------- */
    float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
		os << fixed.toFloat();
		return os;
	}
};

#endif
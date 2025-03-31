/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:03:22 by edetoh            #+#    #+#             */
/*   Updated: 2025/03/31 17:02:57 by edetoh           ###   ########.fr       */
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

    /* -------------------------------- Operators ------------------------------- */
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;

	static Fixed min(Fixed &op1, Fixed &op2);
	static Fixed min(const Fixed &op1, const Fixed &op2);

	static Fixed max( Fixed &op1, Fixed &op2);
	static Fixed max(const Fixed &op1, const Fixed &op2);

};
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif

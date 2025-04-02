/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:48:55 by edetoh            #+#    #+#             */
/*   Updated: 2025/04/02 11:46:48 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>
#include <string>
#include <math.h>


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Fixed::Fixed()
{
	this->fixedPoint = 0;
	std::cout << ">> Default constructor called" << std::endl;
}
Fixed::Fixed(const int integer)
{
	this->fixedPoint = integer << this->fractionalBits;
	std::cout << "Constructor called with int" << std::endl;
}
Fixed::Fixed(const float floating)
{
	this->fixedPoint = roundf(floating * (1 << this->fractionalBits));
	std::cout << "Constructor called with float" << std::endl;
}
// ───────────────────────────────── Copy Constructor ──────────────────────────────────
Fixed::Fixed(const Fixed &copy) : fixedPoint(copy.fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
}
// ───────────────────────────── Copy Assignment Operator ──────────────────────────────
Fixed &Fixed::operator=(const Fixed &copy)
{
	this->fixedPoint = copy.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

float Fixed::toFloat( void ) const
{
	return (float) this->fixedPoint / (1 << this->fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->fixedPoint >> this->fractionalBits;
}

// ────────────────────────────────────── Getters ──────────────────────────────────────
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

// ────────────────────────────────────── Setters ──────────────────────────────────────
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

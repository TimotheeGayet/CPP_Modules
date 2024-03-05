#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors and destructor

Fixed::Fixed( void ) : _fixedPointValue(0) {
}

Fixed::Fixed( int const value ) {
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed( float const value ) {
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed( Fixed const & src ) {
	*this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {
}

// Methodes

int Fixed::getRawBits( void ) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const {
	return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->_fixedPointValue >> this->_fractionalBits;
}

// Display

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {
	o << rhs.toFloat();
	return o;
}

// Comparisons

bool operator>( Fixed const & lhs, Fixed const & rhs ) {
	return lhs.getRawBits() > rhs.getRawBits();
}

bool operator<( Fixed const & lhs, Fixed const & rhs ) {
	return lhs.getRawBits() < rhs.getRawBits();
}

bool operator>=( Fixed const & lhs, Fixed const & rhs ) {
	return lhs.getRawBits() >= rhs.getRawBits();
}

bool operator<=( Fixed const & lhs, Fixed const & rhs ) {
	return lhs.getRawBits() <= rhs.getRawBits();
}

bool operator==( Fixed const & lhs, Fixed const & rhs ) {
	return lhs.getRawBits() == rhs.getRawBits();
}

bool operator!=( Fixed const & lhs, Fixed const & rhs ) {
	return lhs.getRawBits() != rhs.getRawBits();
}

// Operations

Fixed Fixed::operator+( Fixed const & rhs ) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-( Fixed const & rhs ) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*( Fixed const & rhs ) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/( Fixed const & rhs ) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment and decrement

Fixed & Fixed::operator++( void ) {
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed & Fixed::operator--( void ) {
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// Static methods

Fixed & Fixed::min( Fixed & lhs, Fixed & rhs ) {
	return (lhs < rhs) ? lhs : rhs;
}

Fixed const & Fixed::min( Fixed const & lhs, Fixed const & rhs ) {
	return (lhs < rhs) ? lhs : rhs;
}

Fixed & Fixed::max( Fixed & lhs, Fixed & rhs ) {
	return (lhs > rhs) ? lhs : rhs;
}

Fixed const & Fixed::max( Fixed const & lhs, Fixed const & rhs ) {
	return (lhs > rhs) ? lhs : rhs;
}
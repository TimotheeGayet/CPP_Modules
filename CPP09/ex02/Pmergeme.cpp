#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &src)
{
	if (this != &src)
		*this = src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}
PmergeMe::~PmergeMe(void) {}

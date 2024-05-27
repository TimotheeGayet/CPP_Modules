#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date
{
private:
	int _day;
	int _month;
	int _year;

	Date();
	Date(const Date &other);
	Date &operator=(const Date &other);

public:
	Date(int _year, int _month, int _day);
	~Date();

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	Date &operator>(Date &other);
	Date &operator<(Date &other);
	Date &operator>=(Date &other);
	Date &operator<=(Date &other);
	Date &operator==(Date &other);
	Date &operator!=(Date &other);
	Date operator--(int);

	class BadDateException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif

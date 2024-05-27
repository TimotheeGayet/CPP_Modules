#include "Date.hpp"

bool isBisextile(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

Date::Date()
{
	_day = 1;
	_month = 1;
	_year = 1970;
}

Date::Date(int year, int month, int day)
{
	if ((isBisextile(year) && month == 2 && day > 29) ||
		year < 0 || month < 1 || month > 12 || day < 1 || day > 31 ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
	{
		throw BadDateException();
	}
	_day = day;
	_month = month;
	_year = year;
}

Date::Date(const Date &other)
{
	_day = other.getDay();
	_month = other.getMonth();
	_year = other.getYear();
}

Date &Date::operator=(const Date &other)
{
	_day = other.getDay();
	_month = other.getMonth();
	_year = other.getYear();
	return *this;
}

Date::~Date() {}

int Date::getDay() const
{
	return _day;
}

int Date::getMonth() const
{
	return _month;
}

int Date::getYear() const
{
	return _year;
}

Date &Date::operator>(Date &other)
{
	if (_year > other.getYear())
		return *this;
	if (_year < other.getYear())
		return other;
	if (_month > other.getMonth())
		return *this;
	if (_month < other.getMonth())
		return other;
	if (_day > other.getDay())
		return *this;
	return other;
}

Date &Date::operator<(Date &other)
{
	if (_year < other.getYear())
		return *this;
	if (_year > other.getYear())
		return other;
	if (_month < other.getMonth())
		return *this;
	if (_month > other.getMonth())
		return other;
	if (_day < other.getDay())
		return *this;
	return other;
}

Date &Date::operator>=(Date &other)
{
	if (_year > other.getYear())
		return *this;
	if (_year < other.getYear())
		return other;
	if (_month > other.getMonth())
		return *this;
	if (_month < other.getMonth())
		return other;
	if (_day >= other.getDay())
		return *this;
	return other;
}

Date &Date::operator<=(Date &other)
{
	if (_year < other.getYear())
		return *this;
	if (_year > other.getYear())
		return other;
	if (_month < other.getMonth())
		return *this;
	if (_month > other.getMonth())
		return other;
	if (_day <= other.getDay())
		return *this;
	return other;
}

Date &Date::operator==(Date &other)
{
	if (_year == other.getYear() && _month == other.getMonth() && _day == other.getDay())
		return *this;
	return other;
}

Date &Date::operator!=(Date &other)
{
	if (_year != other.getYear() || _month != other.getMonth() || _day != other.getDay())
		return *this;
	return other;
}

Date Date::operator--(int)
{
	bool bisextile = (_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0;
	int max_days[12] = {31, bisextile ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	_day--;
	if (_day < 1)
	{
		_month--;
		if (_month < 1)
		{
			_month = 12;
			_year--;
		}
		_day = max_days[_month - 1];
	}
	return *this;
}

const char *Date::BadDateException::what() const throw()
{
	return "Error: bad date";
}

//Workshop 8
//Hero.cpp
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca

#include "Hero.h"

#include <cstring>



using namespace std;
using namespace ict;

Hero::Hero()
{
	_name[0] = '/0';
	_strength = 0;
}

Hero::Hero(const char* name, double strength)
{
	strncpy(_name, name, 21);
	_strength = strength;
}

bool Hero::isEmpty() const
{
	if (_name[0] == 0 && _strength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double Hero::getStrength() const
{
	if (_name[0] == 0 && _strength == 0)
	{
		return 0.0;
	}
	else
	{
		return _strength;
	}
}

void Hero::display(std::ostream& out) const
{

		out << _name << " - ";
		out << _strength << endl;
	
}


void Hero::operator-=(double strength)
{
	if (strength > _strength)
	{
		_strength = 0.0;
	}
	else
	{
		_strength = _strength - strength;
	}
}

void Hero::operator+=(double strength)
{
	_strength = _strength + strength;
}

bool ict::operator<(const Hero & first, const Hero & second)
{
	if (first._strength < second._strength)
	{
		return true;
	}
	else
	{
		return false;
	}
}
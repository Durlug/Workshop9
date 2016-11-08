//Workshop 8
//Hero.h
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca

#ifndef HERO_H
#define HERO_H

#include <iostream>

using namespace std;

namespace ict
{
	class Hero
	{
	private:
		char _name[21];
		double _strength;
	public:
		Hero();
		Hero(const char*, double);
		bool isEmpty() const;
		double getStrength() const;
		void display(std::ostream&) const;
		void operator-=(double strength);
		void operator+=(double strength);
		friend bool operator<(const Hero&, const Hero&);
	};

}

#endif
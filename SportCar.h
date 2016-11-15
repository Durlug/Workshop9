//Workshop 9
//SportCar.h
//Shaun Richardson
//110392156
//November 15th 2016

#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_

#include <iostream>
#include "Car.h"


namespace sict
{
	// complete the declaration of the class
	class SportCar : public Car
	{
	private:
		// private members go here
		int noOfPassengers_;


	public:
		// public members go here
		SportCar();
		SportCar(int maxSpeed, int passengers);
	
		// pure virtual members from base class go here
		void accelerate();
		void brake();
		std::ostream& display(std::ostream& ostr) const;

	};
}
#endif
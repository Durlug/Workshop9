//Workshop 9
//SportCar.cpp
//Shaun Richardson
//110392156
//November 15th 2016

#include "SportCar.h"


namespace sict
{

	SportCar::SportCar()
	{
		noOfPassengers_ = 1;
	}

	SportCar::SportCar(int maxspeed, int passengers) : Car(maxspeed)
	{
		noOfPassengers_ = passengers;
	}

	void SportCar::accelerate()
	{
		speed(speed() + 40);
	}

	void SportCar::brake()
	{
		speed(speed() - 10);
	}

	std::ostream& SportCar::display(std::ostream& ostr) const
	{
		if (speed() > 0)
		{
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is traveling at a speed of " << speed() << " km/h." << std::endl;
		}
		else
		{
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is parked.";
		}
		return ostr;
	}

}
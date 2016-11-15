//Workshop 9
//Car.cpp
//Shaun Richardson
//110392156
//November 15th 2016

#include "Car.h"

namespace sict
{

	void Car::speed(int value)
	{
		if (value > maxSpeed_)
		{
			maxSpeed_ = value;
		}
		else if(value < 0)
		{
			speed_ = 0;
		}
		else
		{
			speed_ = value;
		}
	
	}

	int Car::maxSpeed() const
	{
		return maxSpeed_;
	}

	int Car::speed() const
	{
		return speed_;
	}

	Car::Car(int maxSpeed)
	{
		maxSpeed_ = maxSpeed;
		speed_ = 0;
	}

}
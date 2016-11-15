//Workshop 9
//PickupTruck.cpp
//Shaun Richardson
//110392156
//November 15th 2016


#include <cstring>
#include "PickupTruck.h"


namespace sict
{

	PickupTruck::PickupTruck()
	{
		loadAmount_ = 0;
		loadedMaterial_[0] = '\0';
	}

	void PickupTruck::load(const char* loadedMaterial, int loadAmount)
	{
		loadAmount_ = loadAmount;
		strncpy(loadedMaterial_, loadedMaterial, 31);
	}

	void PickupTruck::unload()
	{
		loadAmount_ = 0;
	}

	bool PickupTruck::isEmpty() const
	{
		if (loadAmount_ == 0)
		{
			return true;
		}
		else
			return false;
	}

	void PickupTruck::accelerate()
	{
		speed(speed() + 20);
	}

	void PickupTruck::brake()
	{
		speed(speed() - 5);
	}

	std::ostream& PickupTruck::display(std::ostream& ostr) const
	{
		if (isEmpty() == true)
		{
			ostr << "This pickup truck is not carrying any load";
		}
		else
		{
			ostr << "This pickup truck is carrying " << loadAmount_ << " kgs of " << loadedMaterial_;
		}
		if (speed() == 0)
		{
			ostr << " and is parked.";
		}
		else
		{
			ostr << " traveling at the speed of " << speed() << " km/h." << std::endl;
		}
		return ostr;
	}


}
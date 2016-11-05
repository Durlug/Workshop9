//OOP244 Assignment
//Milestone 01
//Date.cpp
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca
//November 5th, 2016

// header files go here

#include "Date.h"
#include "wpgeneral.h"
namespace ict 
{
   // returns a unique value representing the date
   // this value is used to compare two dates
   int Date::value()const 
   {
      return year_ * 372 + mon_ * 31 + day_;
   }

   // bool validate(), this is an optional private function
   // for validation logic and setting the _readErrorCode.
   // see the read() function description for more details





   // mdays():
   // returns the day of the month.
   // _mon value must be set for this function to work
   // if _mon is invalid, this function returns -1
   // leap years are considered in this logic
   int Date::mdays()const 
   {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
   }

   // constructors
   Date::Date()                    //Setting the class to an empty safe state 
   {
	   year_ = 0;
	   mon_ = 0;
	   day_ = 0;
	   readErrorCode_ = NO_ERROR;
   }

   Date::Date(int year, int month, int day)       //Constructor used as a set function
   {
	   year_ = year;
	   mon_ = month;
	   day_ = day;
	   readErrorCode_ = NO_ERROR;
   }



   // member functions

   void Date::errCode(int errorCode)            //Error code validation
   {
	   if (errorCode == 0)
	   {
		   readErrorCode_ = NO_ERROR;
	   }
	   else if (errorCode == 1)
	   {
		   readErrorCode_ = CIN_FAILED;         //Istream failure
	   }
	   else if (errorCode == 2)
	   {
		   readErrorCode_ = YEAR_ERROR;         //Year entry failure
	   }
	   else if (errorCode == 3)
	   {
		   readErrorCode_ = MON_ERROR;          //Month entry failure
	   }
	   else if (errorCode == 4)
	   {
		   readErrorCode_ = DAY_ERROR;          //Day entry failure
	   }
   }

   int Date::errCode() const 
   {
	   return readErrorCode_;
   }

   bool Date::bad() const
   {
	   if (readErrorCode_ != 0)
	   {
		   return true;
	   }
	   else 
	   {
		   return false;
	   }
   }




   // operators
   bool Date::operator==(const Date& D) const 
   {
	   if (this->value() == D.value()) 
	   {
		   return true;
	   }
	   else
			return false;
	}

   bool Date::operator!=(const Date& D) const
   {
	   if (this->value() != D.value())
	   {
		   return true;
	   }
	   else
		   return false;
   }

   bool Date::operator<(const Date& D) const
   {
	   if (this->value() < D.value())
	   {
		    return true;
	   }
	   else
			return false;
   }

   bool Date::operator>(const Date& D) const
   {
	   if (this->value() > D.value())
	   {
		    return true;
	   }
	   else
			return false;
	}

   bool Date::operator<=(const Date& D) const
   {
	   if (this->value() <= D.value())
	   {
		    return true;
	   }
	   else
			return false;
	}

   bool Date::operator>=(const Date& D) const
   {
	   if (this->value() >= D.value())
	   {
		    return true;
	   }
	   else
			return false;
   }



   // IO functions

   std::istream& Date::read(std::istream& istr)
   {
	   char forward_slash;
	   readErrorCode_ = NO_ERROR;

	   istr >> year_ >> forward_slash >> mon_ >> forward_slash >> day_;        //Inputting info into the istream buffer with forward slash acting as /
	   if (istr.fail())                                                        //If istream fails
	   {
		   readErrorCode_ = CIN_FAILED;
	   }
	   else if (year_ < MIN_YEAR || year_ > MAX_YEAR)                         //Year must be between MIN and MAX or else error
	   {
		   readErrorCode_ = YEAR_ERROR;
	   }
	   else if (mon_ < 1 || mon_ > 12)                                        //Month must be in the range between 1 and 12
	   {
		   readErrorCode_ = MON_ERROR;
	   }
	   else if (day_ < 1 || day_ > mdays())                                  //Day cannot be less than 1, or greater than the mdays function
	   {
		   readErrorCode_ = DAY_ERROR;
	   }

	   return istr;
   }

   std::ostream& Date::write(std::ostream& ostr)
   {
	   ostr << year_ << "/";
	   ostr << mon_ << "/";
	   ostr << day_;

	   return ostr;
   }


   // non-memeber operator overloads
   std::ostream& operator << (std::ostream& os, Date& other)
   {
	   other.write(os);

	   return os;
	}

   std::istream& operator >> (std::istream& is, Date& other) 
   {
	   other.read(is);

	   return is;
   }

}
//Workshop 6
//Account.h
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca
//October 18th 2016


#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

namespace ict{
   class Account{
      char name_[41];
      double balance_;
   public:

      void display(bool gotoNewline = true)const;

      Account();
      Account(double balance);
      Account(const char name[], double balance = 0.0);
	 
	  Account& Account::operator+=(const Account& other);
	  Account& operator=(const char*);

	  friend std::ostream& operator<<(std::ostream& os, const Account& other);
	  friend Account& operator+(const Account&, const Account&);
   };

};

#endif

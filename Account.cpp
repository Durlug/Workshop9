//Workshop 6
//Account.cpp
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca
//October 18th 2016


#include <iomanip>
#include <cstring>
#include "Account.h"

using namespace std;

namespace ict{

    void Account::display(bool gotoNewline)const{
        cout << (name_[0] ? name_: "No Name") << ": $" << setprecision(2) << fixed << balance_;
        if (gotoNewline) cout << endl;
    }


    Account::Account(){
        name_[0] = 0;
        balance_ = 0;
    }
    Account::Account(double balance){
        name_[0] = 0;
        balance_ = balance;
    }
    Account::Account(const char name[], double balance){
        strcpy(name_, name);
        balance_ = balance;
    }

	Account& Account::operator+=(const Account& other) {
		balance_ += other.balance_;
		return *this;
	}

	Account& Account::operator=(const char* name){
		strcpy(name_, name);
		return *this;
	};

	ostream& operator<<(ostream& os, const Account& other){
		other.display(false);
		
		return os;

	}

	Account& operator+(const Account& first, const Account& second) {
		Account copy = first;
		copy += second;
		return copy;
	}

}
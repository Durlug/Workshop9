//Workshop 4
//Enrollment.cpp
//October 4th 2016
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Enrollment.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace ict;
  
  //done
  bool Enrollment::isValid()const{
    return name_ && name_[0];
  }
  //done
  void Enrollment::setEmpty(){
    name_[0] = 0;
    code_[0] = 0;
    year_ = 0;
    semester_ = 0;
    slot_ = 0;
    enrolled_ = false;
  }
  // done
  bool Enrollment::isEnrolled() const{
    return enrolled_;
  }

  // done
  void Enrollment::display(bool nameOnly)const{
    if (isValid()){
      cout << name_;
      if (!nameOnly){
        cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
        cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
      }
    }
    else{
      cout << "Invalid enrollment!" << endl;
    }
  }

  void Enrollment::set(char* name, char* code, int year, int semester, int slot, bool enrolled) {
	  if (name && name[0] && code && code[0] && year >= 2015 && semester > 0 && semester < 4 && slot > 0 && slot < 6) {
		  strncpy(name_, name, 31);
		  strncpy(code_, code, 11);

		  year_ = year;
		  semester_ = semester;
		  slot_ = slot;
		  enrolled_ = enrolled;
	  }
	  else {
		  setEmpty();
	  }
  }

  bool Enrollment::hasConflict(const Enrollment &other) const {
	  if (year_ == other.year_ && semester_ == other.semester_ && slot_ == other.slot_) {
		  return true;
	  }
	  else{
		  return false;
	  }
}

  Enrollment::Enrollment() {
	  setEmpty();
	}

  Enrollment::Enrollment(char* name, char* code, int year, int semester, int time) {
	  
	  this->set(name, code, year, semester, time);

  }





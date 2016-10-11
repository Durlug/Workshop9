
#include "Contact.h"
#include "PhoneNumber.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
using namespace ict;


namespace ict{

  void Contact::read(){
    cout << "Contact Name: ";
    cin.getline(name_, 41, '\n');
    cout << "Please enter " << noPN_ << " phone numbers: " << endl;
    for (int i = 0; i < noPN_; i++){
      cout << i + 1 << ": ";
      phoneNumber_[i].read();
    }
  }

  bool Contact::isEmpty()const{
    return phoneNumber_ == nullptr;
  }

  void Contact::setEmpty(){
    name_[0] = 0;
    noPN_ = 0;
    phoneNumber_ = nullptr;
						  }

  Contact::Contact() {                     //Sets contact to an empty safe state
	  setEmpty();
					 }

  Contact::Contact(const char* name, int phoneNums) {
	  phoneNumber_ = new PhoneNumber[phoneNums];

	  strncpy(name_, name, 40);
	  name_[40] = '\0';
	  noPN_ = phoneNums;
  }
  Contact::~Contact() {
	  delete[] phoneNumber_;
	}

  void Contact::display() const {
	  cout << name_ << endl;
	  cout << "----------------------------------------" << endl;
	  for (int i = 0; i < noPN_; i++) {
		  phoneNumber_[i].display();
	  }
  }

}
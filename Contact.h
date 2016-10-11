#ifndef ICT_CONTACT_H
#define ICT_CONTACT_H

#include "PhoneNumber.h"

namespace ict {
	class Contact: public PhoneNumber {
		char name_[41];
		PhoneNumber *phoneNumber_;
		int noPN_;
		void setEmpty();

	public:
		Contact();
		Contact(const char*, int);
		~Contact();
		void read();		
		bool isEmpty()const;
		void display() const;
	};

}

#endif
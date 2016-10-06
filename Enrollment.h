//Workshop 4
//Enrollment.h
//October 4th 2016
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca

#ifndef _ENROLLMENT_H_
#define _ENROLLMENT_H_

namespace ict {
	class Enrollment {
		char name_[31];
		char code_[11];
		int year_;
		int semester_;
		int slot_;
		bool enrolled_;
	public:
		Enrollment();
		Enrollment(char*, char*, int, int, int);
		bool isValid() const;
		void setEmpty();
		bool isEnrolled() const;
		void display(bool = false) const;
		void set(char*, char*, int, int, int, bool = false);
		bool hasConflict(const Enrollment &other) const;

	};

}

#endif

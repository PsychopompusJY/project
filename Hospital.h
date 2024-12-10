/*
 * Hospital.h
 *
 *  Created on: Dec 10, 2024
 *      Author: benjamin
 */

#include <iostream>
#include <string>
#include <array>
#include "Doctor.h"
#include "Patient.h"



#ifndef HOSPITAL_H_
#define HOSPITAL_H_

class Hospital{
private:
	Patient* p;
	Doctor* D;
	int NumP;
	int NumD;
public:
	void Find_Oldest_Patient();
	int Count_Critical_Patients();
	void Doctors_By_Specialty(string);
	void Show_Patient_By_ID(string);
	void Show_Doctor_By_ID(string);
	void Show_Assigned_Doctor(string);
	void Show_Assigned_Patients(string);

};



#endif /* HOSPITAL_H_ */

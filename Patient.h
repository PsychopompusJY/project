/*
 * Patient.h
 *
 *  Created on: Dec 9, 2024
 *      Author: benjamin
 */


#include <iostream>
#include <array>
#include <string>
#include "Doctor.h"

#ifndef PATIENT_H_
#define PATIENT_H_


class Patient{
private:
	string FirstName;
	string LastName;
	long int PatientID;
	long int AssignedDoctor;
	string DateOfBirth;
	string BloodType;
	string Diagnosis;
	string DateOfAdmission;
	string DischargeDate;
public:
	void SetFirstName(string);
	void SetLastName(string);
	void SetPatientID(long int);
	void SetAssignedDoctor(long int);
	void SetDateOfBirth(string);
	void SetBloodType(string);
	void SetDiagnosis(string);
	void SetDateOfAdmission(string);
	void SetDischargeDate(string);
	string GetFirstName();
	string GetLastName();
	long int GetPatientID();
	long int GetAssignedDoctor();
	string GetDateOfBirth();
	string GetDiagnosis();
	string GetDateOfAdmission();
	string GetDischargeDate();
	bool isDischarged();
	string Patient_Status();
	void Print_Patient_Info();



};


#endif /* PATIENT_H_ */

/*
 * Patient.cpp
 *
 *  Created on: Dec 10, 2024
 *      Author: benjamin
 */

#include <iostream>
#include <array>
#include <string>
#include "Patient.h"
using namespace std;


void Patient::SetFirstName(string name){
	FirstName = name;
}

void Patient::SetLastName(string name){
	LastName = name;
}

void Patient::SetPatientID(long int id){
	PatientID = id;
}

void Patient::SetAssignedDoctor(long int id){
	AssignedDoctor = id;
}

void Patient::SetDateOfBirth(string date){
	DateOfBirth = date;
}

void Patient::SetBloodType(string type){
	BloodType = type;
}

void Patient::SetDiagnosis(string diagnosis){
	Diagnosis = diagnosis;
}

void Patient::SetDateOfAdmission(string date){
	DateOfAdmission = date;
}

void Patient::SetDischargeDate(string date){
	DischargeDate = date;
}

string Patient::GetFirstName(){
	return FirstName;
}

string Patient::GetLastName(){
	return LastName;
}

long int Patient::GetPatientID(){
	return PatientID;
}

long int Patient::GetAssignedDoctor(){
	return AssignedDoctor;
}

string Patient::GetDateOfBirth(){
	return DateOfBirth;
}

string Patient::GetDiagnosis(){
	return Diagnosis;
}

string Patient::GetDateOfAdmission(){
	return DateOfAdmission;
}

string Patient::GetDischargeDate(){
	return DischargeDate;
}

bool Patient::isDischarged(){
	if (DischargeDate == "-1"){
		return false;
	}
	else{
		return true;
	}
}
string Patient::Patient_Status(){
	if (Diagnosis.find("Critical") != string::npos){
		return "Critical";
	}
	else if (Diagnosis.find("Moderate") != string::npos){
		return "Moderate";
	}
	else{
		return "Stable";
	}
}
void Patient::Print_Patient_Info(){
	cout << FirstName << " " << LastName << "\n" << PatientID << "\n" << AssignedDoctor << "\n" << DateOfBirth;
	cout << "\n" << BloodType << "\n" << Diagnosis << "\n" << DateOfAdmission << "\n" << DischargeDate << endl;
}


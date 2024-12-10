#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#ifndef DOCTOR_H
#define DOCTOR_H


class Doctor{
private:
	string FirstName;
	string LastName;
	int id;
	string Specialty;
	int YearsOfExperience;
	double BaseSalary;
	double PerformanceBonus;
public:
	string SetFirstName(string);
	string SetLastName(string);
	int Setid(int);
	string SetSpecialty(string);
	int SetYearsOfExperience(int);
	double SetBaseSalary(double);
	double SetPerformanceBonus(double);
	void GetFirstName();
	void GetLastName();
	void Getid();
	void GetSpecialty();
	void GetYearsOfExperience();
	void GetBaseSalary();
	void GetPerformanceBonus();
	double Calculate_Salary();
	void Print_Doctor_Info();
};


#endif

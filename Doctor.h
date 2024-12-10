#include <iostream>
#include <fstream>
#include <array>
#include <string>
using namespace std;

#ifndef DOCTOR_H_
#define DOCTOR_H_


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
	void SetFirstName(string);
	void SetLastName(string);
	void Setid(int);
	void SetSpecialty(string);
	void SetYearsOfExperience(int);
	void SetBaseSalary(double);
	void SetPerformanceBonus(double);
	string GetFirstName();
	string GetLastName();
	int Getid();
	string GetSpecialty();
	int GetYearsOfExperience();
	double GetBaseSalary();
	double GetPerformanceBonus();
	double Calculate_Salary();
	void Print_Doctor_Info();
};


#endif

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include "Doctor.h"

using namespace std;

// Setters
void Doctor::SetFirstName(string firstName) {
    FirstName = firstName;
}

void Doctor::SetLastName(string lastName) {
    LastName = lastName;
}

void Doctor::Setid(int id) {
    this->id = id;
}

void Doctor::SetSpecialty(string specialty) {
    Specialty = specialty;
}

void Doctor::SetYearsOfExperience(int yearsOfExperience) {
    YearsOfExperience = yearsOfExperience;
}

void Doctor::SetBaseSalary(double baseSalary) {
    BaseSalary = baseSalary;
}

void Doctor::SetPerformanceBonus(double performanceBonus) {
    PerformanceBonus = performanceBonus;
}

// Getters
string Doctor::GetFirstName() {
    return FirstName;
}

string Doctor::GetLastName() {
    return LastName;
}

int Doctor::Getid() {
    return id;
}

string Doctor::GetSpecialty() {
    return Specialty;
}

int Doctor::GetYearsOfExperience() {
    return YearsOfExperience;
}

double Doctor::GetBaseSalary() {
    return BaseSalary;
}

double Doctor::GetPerformanceBonus() {
    return PerformanceBonus;
}

// Member Functions
double Doctor::Calculate_Salary() {
    return BaseSalary + (BaseSalary * PerformanceBonus);
}

void Doctor::Print_Doctor_Info() {
    cout << "Doctor Information:" << endl;
    cout << "First Name: " << FirstName << endl;
    cout << "Last Name: " << LastName << endl;
    cout << "ID: " << id << endl;
    cout << "Specialty: " << Specialty << endl;
    cout << "Years of Experience: " << YearsOfExperience << endl;
    cout << "Base Salary: $" << fixed << setprecision(2) << BaseSalary << endl;
    cout << "Performance Bonus: " << PerformanceBonus * 100 << "%" << endl;
    cout << "Calculated Salary: $" << fixed << setprecision(2) << Calculate_Salary() << endl;
}

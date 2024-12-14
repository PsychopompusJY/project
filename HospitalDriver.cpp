/*
 * HospitalDriver.cpp
 *
 *  Created on: Dec 9, 2024
 *      Author: benjamin
 */


#include <iostream>
#include <string>
#include <vector>
#include "Hospital.h"
using namespace std;


int main(){

	Hospital Jewish_General;
try{
	cout << "Welcome to the Jewish General Hospital system\nWhat would you like to do? (Please enter the number of your choice)";
	cout << "1.Find oldest patient (by age)\n2.Find how many patients are in critical condition\n3.Find all doctors of a specialty\n4.Display patient information given an ID";
	cout << "\n5.Display doctor information given an ID\n6.Find doctor assigned to a patient (given patient ID)\n7.Find all patients assigned to a doctor (given doctor ID)\nEnter -1 to end\n";
	int choice;
	cin >> choice;
	if (choice ==0 || choice >7 || choice <-1){
		throw "Error: Selection out of Range";
	}
	while (choice != -1){
		string Specialty;
		string ID;
		switch (choice){
		case 1:
			Jewish_General.Find_Oldest_Patient();
			 cout << endl;
			break;
		case 2:
			cout << "There are currently " << Jewish_General.Count_Critical_Patients() << " critical patients in the hospital" << endl;
			cout << endl;
			break;
		case 3:
			cout << "What specialty are you looking for?: ";
			cin >> Specialty;
			Jewish_General.Doctors_By_Specialty(Specialty);
			cout << endl;
			break;
		case 4:
			cout << "What is the ID of the patient you would like to see?: ";
			cin >> ID;
			Jewish_General.Show_Patient_By_ID(ID);
			cout << endl;
			break;
		case 5:
			cout << "What is the ID of the doctor you would like to see?: ";
			cin >> ID;
			Jewish_General.Show_Doctor_By_ID(ID);
			 cout << endl;
			break;
		case 6:
			cout << "Which patients doctor would you like to see?: ";
			cin >> ID;
			Jewish_General.Show_Assigned_Doctor(ID);
			cout << endl;
			break;
		case 7:
			cout << "Which doctors patients would you like to see?: ";
			cin >> ID;
			Jewish_General.Show_Assigned_Patients(ID);
			cout << endl;
			break;

		}
		cout << "Welcome to the Jewish General Hospital system\n What would you like to do? (Please enter the number of your choice)";
		cout << "1.Find oldest patient (by age)\n2.Find how many patients are in critical condition\n3.Find all doctors of a specialty\n4.Display patient information given an ID";
		cout << "\n5.Display doctor information given an ID\n6.Find doctor assigned to a patient (given patient ID)\n7.Find all patients assigned to a doctor (given doctor ID)\n Enter -1 to end";
		int choice;
		cin >> choice;
	}
} catch (const char* err){
		cout << err;
	}
	return 0;
}

/*
 * Hospital.cpp
 *
 *  Created on: Dec 12, 2024
 *      Author: benjamin
 */


#include <iostream>
#include <fstream>
#include <string>
#include "Hospital.h"

using namespace std;

// Constructor
Hospital::Hospital() : patients(nullptr), doctors(nullptr), numPatients(0), numDoctors(0) {
    ifstream doctorFile("doctor_sample.txt");
    ifstream patientFile("patients_sample.txt");
 try{
    if (!doctorFile.is_open() || !patientFile.is_open()) {
        throw string("Error: Unable to open input files!") ;
    }

    // Read doctor information
    doctorFile >> numDoctors;
    doctors = new Doctor[numDoctors];
    for (int i = 0; i < numDoctors; ++i) {
        string firstName, lastName, specialty;
        int id, yearsOfExperience;
        double baseSalary, performanceBonus;

        doctorFile >> firstName >> lastName >> id;
        doctorFile.ignore(); // Ignore the space before the opening quote
        getline(doctorFile, specialty, '"'); // Read the opening quote
        getline(doctorFile, specialty, '"'); // Read the actual specialty inside quotes
        doctorFile >> yearsOfExperience >> baseSalary >> performanceBonus;

        if (id > 99999999 || id < 10000000){
        	throw string("Id number too large for doctor #" + to_string(i+1));
        }



        doctors[i].SetFirstName(firstName);
        doctors[i].SetLastName(lastName);
        doctors[i].Setid(id);
        doctors[i].SetSpecialty(specialty);
        doctors[i].SetYearsOfExperience(yearsOfExperience);
        doctors[i].SetBaseSalary(baseSalary);
        doctors[i].SetPerformanceBonus(performanceBonus);
    }

    // Read patient information
    patientFile >> numPatients;
    patients = new Patient[numPatients];
    for (int i = 0; i < numPatients; ++i) {
        string firstName, lastName, diagnosis, dateOfBirth, bloodType, admissionDate, dischargeDate;
        long int patientID, assignedDoctor;
        patientFile >> firstName >> lastName >> patientID >> assignedDoctor >> dateOfBirth >> bloodType;
        patientFile.ignore(); // Ignore space before the quoted diagnosis
        getline(patientFile, diagnosis, '"'); // Read opening quote
        getline(patientFile, diagnosis, '"'); // Read diagnosis inside quotes
        patientFile >> admissionDate >> dischargeDate;

        if (stoi(dateOfBirth.substr(4, 2)) > 12 || stoi(dateOfBirth.substr(4, 6)) <1){
        	throw ("Invalid date of birth of patient #" +to_string(i+1));
        }
        if (stoi(dateOfBirth.substr(6)) > 31 || stoi(dateOfBirth.substr(6)) <1){
        	throw ("Invalid date of birth of patient #" +to_string(i+1));
        }

        if (patientID > 99999999 || patientID < 10000000){
                	throw string("Id number too large for doctor #" + to_string(i+1));
                }

        bool isDoctor = false;
        for (int j =0; j < numDoctors; j++){
        	if (assignedDoctor == doctors[j].Getid() || assignedDoctor == -1){
        		isDoctor =true;
        	}
        }
        if (isDoctor == false){
        	throw string("Invalid assigned doctor of patient #" + to_string(i+1));
        }

        array<string, 8> BloodTypes = {"A+", "A-","AB+","AB-","B+","B-","O+","O-"};
        bool isRealBloodType = false;
        for(int k = 0; k< 8; k++){
        	if (bloodType == BloodTypes[k]){
        		isRealBloodType = true;
        	}
        }
        if (isRealBloodType== false){
        	throw string("Invalid blood type for patient #" + to_string(i+1));
        }

        patients[i].SetFirstName(firstName);
        patients[i].SetLastName(lastName);
        patients[i].SetPatientID(patientID);
        patients[i].SetAssignedDoctor(assignedDoctor);
        patients[i].SetDateOfBirth(dateOfBirth);
        patients[i].SetBloodType(bloodType);
        patients[i].SetDiagnosis(diagnosis);
        patients[i].SetDateOfAdmission(admissionDate);
        patients[i].SetDischargeDate(dischargeDate);
    }} catch(const string& err){
    	cout << "Error: " << err;
    	delete[] doctors;
    	delete[] patients;
    	doctorFile.close();
    	patientFile.close();
    	exit(1);
    }
    doctorFile.close();
    patientFile.close();
}

// Destructor
Hospital::~Hospital() {
    delete[] doctors;
    delete[] patients;
    doctors = nullptr;
    patients = nullptr;
}

// Find and display the oldest patient
void Hospital::Find_Oldest_Patient() {
    if (numPatients == 0) {
        cout << "No patients available." << endl;
        return;
    }

    int oldestIndex = 0;
    for (int i = 1; i < numPatients; ++i) {
        if (patients[i].GetDateOfBirth() < patients[oldestIndex].GetDateOfBirth()) {
            oldestIndex = i;
        }
    }

    cout << "Oldest Patient:" << endl;
    patients[oldestIndex].Print_Patient_Info();
}

// Count the number of critical patients
int Hospital::Count_Critical_Patients() {
    int criticalCount = 0;
    for (int i = 0; i < numPatients; ++i) {
    	if (patients[i].Patient_Status() == "Critical") {
            criticalCount++;
        }
    }
    return criticalCount;
}

// Display doctors by specialty
void Hospital::Doctors_By_Specialty(const string& specialty) {
    bool found = false;
    for (int i = 0; i < numDoctors; ++i) {
        if (doctors[i].GetSpecialty() == specialty) {
            doctors[i].Print_Doctor_Info();
            found = true;
        }
    }
    if (!found) {
        cout << "No doctors found with the specialty: " << specialty << endl;
    }
}

// Show patient by ID
void Hospital::Show_Patient_By_ID(const string& id) {
    for (int i = 0; i < numPatients; ++i) {
        if (to_string(patients[i].GetPatientID()) == id) {
            patients[i].Print_Patient_Info();
            return;
        }
    }
    cout << "No patient has the provided ID." << endl;
}

// Show doctor by ID
void Hospital::Show_Doctor_By_ID(const string& id) {
    for (int i = 0; i < numDoctors; ++i) {
        if (to_string(doctors[i].Getid()) == id) {
            doctors[i].Print_Doctor_Info();
            return;
        }
    }
    cout << "No doctor has the provided ID." << endl;
}

// Show assigned doctor for a patient
void Hospital::Show_Assigned_Doctor(const string& patientID) {
    for (int i = 0; i < numPatients; ++i) {
        if (to_string(patients[i].GetPatientID()) == patientID) {
            long int doctorID = patients[i].GetAssignedDoctor();
            for (int j = 0; j < numDoctors; ++j) {
                if (doctors[j].Getid() == doctorID) {
                    doctors[j].Print_Doctor_Info();
                    return;
                }
            }
            cout << "No doctor assigned to this patient." << endl;
            return;
        }
    }
    cout << "No patient found with the provided ID." << endl;
}

// Show patients assigned to a specific doctor
void Hospital::Show_Assigned_Patients(const string& doctorID) {
    bool found = false;
    for (int i = 0; i < numPatients; ++i) {
        if (to_string(patients[i].GetAssignedDoctor()) == doctorID) {
            patients[i].Print_Patient_Info();
            found = true;
        }
    }
    if (!found) {
        cout << "No patients assigned to doctor with ID: " << doctorID << endl;
    }
}

// Assign a doctor to a patient
void Hospital::Assign_Doctor_To_Patient(long int patientID, long int doctorID) {
    for (int i = 0; i < numPatients; ++i) {
        if (patients[i].GetPatientID() == patientID) {
            patients[i].SetAssignedDoctor(doctorID);
            cout << "Doctor with ID " << doctorID << " assigned to patient with ID " << patientID << "." << endl;
            return;
        }
    }
    cout << "No patient found with the provided ID." << endl;
}


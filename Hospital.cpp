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

    if (!doctorFile.is_open() || !patientFile.is_open()) {
        cerr << "Error: Unable to open input files!" << endl;
        exit(1);
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

        doctors[i].SetFirstName(firstName);
        doctors[i].SetLastName(lastName);
        doctors[i].Setid(id);
        doctors[i].SetSpecialty(specialty);
        doctors[i].SetYearsOfExperience(yearsOfExperience);
        doctors[i].SetBaseSalary(baseSalary);
        doctors[i].SetPerformanceBonus(performanceBonus);
    }
    doctorFile.close();

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

        patients[i].SetFirstName(firstName);
        patients[i].SetLastName(lastName);
        patients[i].SetPatientID(patientID);
        patients[i].SetAssignedDoctor(assignedDoctor);
        patients[i].SetDateOfBirth(dateOfBirth);
        patients[i].SetBloodType(bloodType);
        patients[i].SetDiagnosis(diagnosis);
        patients[i].SetDateOfAdmission(admissionDate);
        patients[i].SetDischargeDate(dischargeDate);
    }
    patientFile.close();
}

// Destructor
Hospital::~Hospital() {
    delete[] doctors;
    delete[] patients;
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


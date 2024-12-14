/*
 * Hospital.h
 *
 *  Created on: Dec 10, 2024
 *      Author: benjamin
 */





#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>
#include "Doctor.h"
#include "Patient.h"

class Hospital {
private:
    Patient* patients;     // Dynamic array of Patient objects
    Doctor* doctors;       // Dynamic array of Doctor objects
    int numPatients;       // Number of patients
    int numDoctors;        // Number of doctors

public:
    // Constructor and Destructor
    Hospital();            // Reads data from files and initializes arrays
    ~Hospital();           // Cleans up dynamic memory

    // Member functions
    void Find_Oldest_Patient();                               // Finds and displays the oldest patient
    int Count_Critical_Patients();                            // Counts critical patients
    void Doctors_By_Specialty(const std::string& specialty);  // Displays doctors by specialty
    void Show_Patient_By_ID(const std::string& id);           // Displays patient by ID
    void Show_Doctor_By_ID(const std::string& id);            // Displays doctor by ID
    void Show_Assigned_Doctor(const std::string& patientID);  // Displays assigned doctor for a patient
    void Show_Assigned_Patients(const std::string& doctorID); // Displays patients assigned to a doctor
    void Assign_Doctor_To_Patient(long int patientID, long int doctorID); // Assigns a doctor to a patient
};

#endif

///////////////////////////////////////////////////////////
//  ClinicRegister.h
//  Implementation of the Class ClinicRegister
//  Created on:      29-Nov-2025 23:53:27
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#ifndef CLINICREGISTER_H
#define CLINICREGISTER_H

#include <vector>
#include <string>
#include "Patient.h"
#include "Doctor.h"
#include "Schedule.h"
#include "Transaction.h"

class ClinicRegister {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Schedule> schedules;
    std::vector<Transaction> transactions;

    // helpers
    int findPatientIndex(const std::string& id) const;
    int findDoctorIndex(const std::string& id) const;
    int findScheduleIndex(const std::string& id) const;
    int findTransactionIndex(const std::string& id) const;

public:
    ClinicRegister();
    // CRUD
    void addPatient(const Patient& p);
    void addDoctor(const Doctor& d);
    void addSchedule(const Schedule& s);
    void addTransaction(const Transaction& t);

    bool editPatient(const std::string& id, const Patient& updated);
    bool deletePatient(const std::string& id);

    // lists
    std::vector<Patient> getPatientList() const;
    std::vector<Doctor> getDoctorList() const;
    std::vector<Schedule> getScheduleList() const;
    std::vector<Transaction> getTransactionList() const;

    // file I/O
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;

    // simple auto-id generators
    std::string nextPatientId() const;
    std::string nextDoctorId() const;
    std::string nextScheduleId() const;
    std::string nextTransactionId() const;
};

#endif // CLINICREGISTER_H

///////////////////////////////////////////////////////////
//  ClinicRegister.cpp
//  Implementation of the Class ClinicRegister
//  Created on:      29-Nov-2025 23:53:27
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#include "ClinicRegister.h"
#include <fstream>
#include <sstream>
#include <algorithm>

// --- ctor
ClinicRegister::ClinicRegister() {}

// --- helpers
int ClinicRegister::findPatientIndex(const std::string& id) const {
    for (size_t i = 0; i < patients.size(); ++i) if (patients[i].getId() == id) return (int)i;
    return -1;
}
int ClinicRegister::findDoctorIndex(const std::string& id) const {
    for (size_t i = 0; i < doctors.size(); ++i) if (doctors[i].getId() == id) return (int)i;
    return -1;
}
int ClinicRegister::findScheduleIndex(const std::string& id) const {
    for (size_t i = 0; i < schedules.size(); ++i) if (schedules[i].getId() == id) return (int)i;
    return -1;
}
int ClinicRegister::findTransactionIndex(const std::string& id) const {
    for (size_t i = 0; i < transactions.size(); ++i) if (transactions[i].getId() == id) return (int)i;
    return -1;
}

// --- add
void ClinicRegister::addPatient(const Patient& p) { patients.push_back(p); }
void ClinicRegister::addDoctor(const Doctor& d) { doctors.push_back(d); }
void ClinicRegister::addSchedule(const Schedule& s) { schedules.push_back(s); }
void ClinicRegister::addTransaction(const Transaction& t) { transactions.push_back(t); }

// --- edit/delete
bool ClinicRegister::editPatient(const std::string& id, const Patient& updated) {
    int idx = findPatientIndex(id);
    if (idx == -1) return false;
    patients[idx] = updated;
    return true;
}
bool ClinicRegister::deletePatient(const std::string& id) {
    int idx = findPatientIndex(id);
    if (idx == -1) return false;
    patients.erase(patients.begin() + idx);
    return true;
}

// --- getters
std::vector<Patient> ClinicRegister::getPatientList() const { return patients; }
std::vector<Doctor> ClinicRegister::getDoctorList() const { return doctors; }
std::vector<Schedule> ClinicRegister::getScheduleList() const { return schedules; }
std::vector<Transaction> ClinicRegister::getTransactionList() const { return transactions; }

// --- file I/O (simple CSV-like with sections)
bool ClinicRegister::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) return false;

    patients.clear(); doctors.clear(); schedules.clear(); transactions.clear();

    std::string line;
    enum Section { NONE, PATIENTS, DOCTORS, SCHEDULES, TRANSACTIONS } sec = NONE;
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        if (line == "#PATIENTS") { sec = PATIENTS; continue; }
        if (line == "#DOCTORS") { sec = DOCTORS; continue; }
        if (line == "#SCHEDULES") { sec = SCHEDULES; continue; }
        if (line == "#TRANSACTIONS") { sec = TRANSACTIONS; continue; }

        std::istringstream iss(line);
        if (sec == PATIENTS) {
            // id,name,age,address
            std::string id,name,address,ageS;
            if (!std::getline(iss, id, ',')) continue;
            if (!std::getline(iss, name, ',')) continue;
            if (!std::getline(iss, ageS, ',')) continue;
            if (!std::getline(iss, address)) address = "";
            int age = std::stoi(ageS);
            patients.emplace_back(id, name, age, address);
        } else if (sec == DOCTORS) {
            // id,name,specialty
            std::string id,name,specialty;
            if (!std::getline(iss, id, ',')) continue;
            if (!std::getline(iss, name, ',')) continue;
            if (!std::getline(iss, specialty)) specialty = "";
            doctors.emplace_back(id, name, specialty);
        } else if (sec == SCHEDULES) {
            // id,doctorId,day,time
            std::string id, docId, day, time;
            if (!std::getline(iss, id, ',')) continue;
            if (!std::getline(iss, docId, ',')) continue;
            if (!std::getline(iss, day, ',')) continue;
            if (!std::getline(iss, time)) time = "";
            schedules.emplace_back(id, docId, day, time);
        } else if (sec == TRANSACTIONS) {
            // id,patientId,doctorId,fee
            std::string id, pid, did, feeS;
            if (!std::getline(iss, id, ',')) continue;
            if (!std::getline(iss, pid, ',')) continue;
            if (!std::getline(iss, did, ',')) continue;
            if (!std::getline(iss, feeS)) feeS = "0";
            double fee = std::stod(feeS);
            transactions.emplace_back(id, pid, did, fee);
        }
    }

    fin.close();
    return true;
}

bool ClinicRegister::saveToFile(const std::string& filename) const {
    std::ofstream fout(filename);
    if (!fout.is_open()) return false;

    fout << "#PATIENTS\n";
    for (const auto& p : patients) {
        fout << p.getId() << "," << p.getName() << "," << p.getAge() << "," << p.getAddress() << "\n";
    }

    fout << "#DOCTORS\n";
    for (const auto& d : doctors) {
        fout << d.getId() << "," << d.getName() << "," << d.getSpecialty() << "\n";
    }

    fout << "#SCHEDULES\n";
    for (const auto& s : schedules) {
        fout << s.getId() << "," << s.getDoctorId() << "," << s.getDay() << "," << s.getTime() << "\n";
    }

    fout << "#TRANSACTIONS\n";
    for (const auto& t : transactions) {
        fout << t.getId() << "," << t.getPatientId() << "," << t.getDoctorId() << "," << t.getFee() << "\n";
    }

    fout.close();
    return true;
}

// --- simple auto-id generators
static int padNumber(int n) {
    return n;
}
std::string ClinicRegister::nextPatientId() const {
    int n = (int)patients.size() + 1;
    return "P" + std::to_string(100 + n); // P101, P102...
}
std::string ClinicRegister::nextDoctorId() const {
    int n = (int)doctors.size() + 1;
    return "D" + std::to_string(100 + n);
}
std::string ClinicRegister::nextScheduleId() const {
    int n = (int)schedules.size() + 1;
    return "S" + std::to_string(100 + n);
}
std::string ClinicRegister::nextTransactionId() const {
    int n = (int)transactions.size() + 1;
    return "T" + std::to_string(100 + n);
}

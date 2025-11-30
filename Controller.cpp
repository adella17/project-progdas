///////////////////////////////////////////////////////////
//  Controller.cpp
//  Implementation of the Class Controller
//  Created on:      29-Nov-2025 23:53:30
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#include "Controller.h"
#include <iostream>
#include <limits>

Controller::Controller() {}

void Controller::showMainMenu() const {
    std::cout << "\n=== Clinic Management ===\n";
    std::cout << "1. Add Patient\n";
    std::cout << "2. Edit Patient\n";
    std::cout << "3. Delete Patient\n";
    std::cout << "4. List Patients\n";
    std::cout << "5. Add Doctor\n";
    std::cout << "6. List Doctors\n";
    std::cout << "7. Add Schedule\n";
    std::cout << "8. List Schedules\n";
    std::cout << "9. Add Transaction\n";
    std::cout << "10. List Transactions\n";
    std::cout << "11. Load data (input.txt)\n";
    std::cout << "12. Save data (output.txt)\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose: ";
}

void Controller::pauseAndWait() const {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ---------- Handlers ----------
void Controller::handleAddPatient() {
    std::string name, address;
    int age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Patient name: "; std::getline(std::cin, name);
    std::cout << "Age: "; std::cin >> age; std::cin.ignore();
    std::cout << "Address: "; std::getline(std::cin, address);
    std::string id = registry.nextPatientId();
    Patient p(id, name, age, address);
    registry.addPatient(p);
    std::cout << "Added patient with ID " << id << "\n";
}

void Controller::handleEditPatient() {
    std::string id;
    std::cout << "Enter patient ID to edit: ";
    std::cin >> id;
    int idx = -1;
    auto list = registry.getPatientList();
    for (size_t i = 0; i < list.size(); ++i) if (list[i].getId() == id) { idx = (int)i; break; }
    if (idx == -1) { std::cout << "Patient not found.\n"; return; }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string name, address; int age;
    std::cout << "New name (leave empty to keep): "; std::getline(std::cin, name);
    std::cout << "New age (0 to keep): "; std::cin >> age; std::cin.ignore();
    std::cout << "New address (leave empty to keep): "; std::getline(std::cin, address);

    Patient updated = list[idx];
    if (!name.empty()) updated.setName(name);
    if (age > 0) updated.setAge(age);
    if (!address.empty()) updated.setAddress(address);

    if (registry.editPatient(id, updated)) std::cout << "Patient updated.\n"; else std::cout << "Update failed.\n";
}

void Controller::handleDeletePatient() {
    std::string id;
    std::cout << "Enter patient ID to delete: ";
    std::cin >> id;
    if (registry.deletePatient(id)) std::cout << "Deleted.\n"; else std::cout << "Not found.\n";
}

void Controller::handleListPatients() {
    auto list = registry.getPatientList();
    if (list.empty()) { std::cout << "No patients.\n"; return; }
    for (const auto& p : list) p.print();
}

void Controller::handleAddDoctor() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string name, specialty;
    std::cout << "Doctor name: "; std::getline(std::cin, name);
    std::cout << "Specialty: "; std::getline(std::cin, specialty);
    std::string id = registry.nextDoctorId();
    Doctor d(id, name, specialty);
    registry.addDoctor(d);
    std::cout << "Added doctor with ID " << id << "\n";
}

void Controller::handleListDoctors() {
    auto list = registry.getDoctorList();
    if (list.empty()) { std::cout << "No doctors.\n"; return; }
    for (const auto& d : list) d.print();
}

void Controller::handleAddSchedule() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string doctorId, day, time;
    std::cout << "Doctor ID for schedule: "; std::getline(std::cin, doctorId);
    // Check doctor exists
    bool ok = false;
    for (const auto& d : registry.getDoctorList()) if (d.getId() == doctorId) { ok = true; break; }
    if (!ok) { std::cout << "Doctor not found.\n"; return; }
    std::cout << "Day (e.g. Monday): "; std::getline(std::cin, day);
    std::cout << "Time (e.g. 09:00): "; std::getline(std::cin, time);
    std::string id = registry.nextScheduleId();
    Schedule s(id, doctorId, day, time);
    registry.addSchedule(s);
    std::cout << "Added schedule with ID " << id << "\n";
}

void Controller::handleListSchedules() {
    auto list = registry.getScheduleList();
    if (list.empty()) { std::cout << "No schedules.\n"; return; }
    for (const auto& s : list) s.print();
}

void Controller::handleAddTransaction() {
    std::string patientId, doctorId;
    double fee;
    std::cout << "Patient ID: "; std::cin >> patientId;
    std::cout << "Doctor ID: "; std::cin >> doctorId;
    // validate
    bool pexist = false, dexist = false;
    for (const auto& p : registry.getPatientList()) if (p.getId() == patientId) { pexist = true; break; }
    for (const auto& d : registry.getDoctorList()) if (d.getId() == doctorId) { dexist = true; break; }
    if (!pexist || !dexist) { std::cout << "Patient or Doctor not found.\n"; return; }
    std::cout << "Fee (numeric): "; std::cin >> fee;
    std::string id = registry.nextTransactionId();
    Transaction t(id, patientId, doctorId, fee);
    registry.addTransaction(t);
    std::cout << "Transaction recorded with ID " << id << "\n";
}

void Controller::handleListTransactions() {
    auto list = registry.getTransactionList();
    if (list.empty()) { std::cout << "No transactions.\n"; return; }
    for (const auto& t : list) t.print();
}

void Controller::handleLoad() {
    if (registry.loadFromFile("input.txt")) std::cout << "Loaded input.txt\n";
    else std::cout << "Failed to load input.txt (file may not exist or is malformed)\n";
}

void Controller::handleSave() {
    if (registry.saveToFile("output.txt")) std::cout << "Saved to output.txt\n";
    else std::cout << "Failed to save to output.txt\n";
}

// main loop
void Controller::run() {
    while (true) {
        showMainMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 1: handleAddPatient(); break;
            case 2: handleEditPatient(); break;
            case 3: handleDeletePatient(); break;
            case 4: handleListPatients(); break;
            case 5: handleAddDoctor(); break;
            case 6: handleListDoctors(); break;
            case 7: handleAddSchedule(); break;
            case 8: handleListSchedules(); break;
            case 9: handleAddTransaction(); break;
            case 10: handleListTransactions(); break;
            case 11: handleLoad(); break;
            case 12: handleSave(); break;
            case 0: std::cout << "Exiting. Saving to output.txt...\n"; handleSave(); return;
            default: std::cout << "Invalid choice.\n"; break;
        }
        pauseAndWait();
    }
}

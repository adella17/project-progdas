///////////////////////////////////////////////////////////
//  Controller.h
//  Implementation of the Class Controller
//  Created on:      29-Nov-2025 23:53:30
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ClinicRegister.h"

class Controller {
private:
    ClinicRegister registry;
    void showMainMenu() const;
    void pauseAndWait() const;
public:
    Controller();
    void run();

    // handlers
    void handleAddPatient();
    void handleEditPatient();
    void handleDeletePatient();
    void handleListPatients();

    void handleAddDoctor();
    void handleListDoctors();

    void handleAddSchedule();
    void handleListSchedules();

    void handleAddTransaction();
    void handleListTransactions();

    void handleLoad();
    void handleSave();
};

#endif // CONTROLLER_H

///////////////////////////////////////////////////////////
//  Doctor.h
//  Implementation of the Class Doctor
//  Created on:      29-Nov-2025 23:53:16
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
private:
    std::string id;
    std::string name;
    std::string specialty;
public:
    Doctor();
    Doctor(const std::string& id, const std::string& name, const std::string& specialty);

    std::string getId() const;
    std::string getName() const;
    std::string getSpecialty() const;

    void setName(const std::string& name);
    void setSpecialty(const std::string& specialty);

    void print() const;
};

#endif // DOCTOR_H

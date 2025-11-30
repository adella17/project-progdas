///////////////////////////////////////////////////////////
//  Patient.h
//  Implementation of the Class Patient
//  Created on:      29-Nov-2025 23:52:39
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
private:
    std::string id;
    std::string name;
    int age;
    std::string address;
public:
    Patient();
    Patient(const std::string& id, const std::string& name, int age, const std::string& address);

    std::string getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getAddress() const;

    void setName(const std::string& name);
    void setAge(int age);
    void setAddress(const std::string& address);

    void print() const;
};

#endif // PATIENT_H

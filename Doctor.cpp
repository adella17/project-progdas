///////////////////////////////////////////////////////////
//  Doctor.cpp
//  Implementation of the Class Doctor
//  Created on:      29-Nov-2025 23:53:16
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#include "Doctor.h"
#include <iostream>

Doctor::Doctor() : id(""), name(""), specialty("") {}
Doctor::Doctor(const std::string& id, const std::string& name, const std::string& specialty)
    : id(id), name(name), specialty(specialty) {}

std::string Doctor::getId() const { return id; }
std::string Doctor::getName() const { return name; }
std::string Doctor::getSpecialty() const { return specialty; }

void Doctor::setName(const std::string& n) { name = n; }
void Doctor::setSpecialty(const std::string& s) { specialty = s; }

void Doctor::print() const {
    std::cout << "Doctor[" << id << "] Name: " << name << " | Specialty: " << specialty << "\n";
}

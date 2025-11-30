///////////////////////////////////////////////////////////
//  Patient.cpp
//  Implementation of the Class Patient
//  Created on:      29-Nov-2025 23:52:40
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#include "Patient.h"
#include <iostream>

Patient::Patient() : id(""), name(""), age(0), address("") {}
Patient::Patient(const std::string& id, const std::string& name, int age, const std::string& address)
    : id(id), name(name), age(age), address(address) {}

std::string Patient::getId() const { return id; }
std::string Patient::getName() const { return name; }
int Patient::getAge() const { return age; }
std::string Patient::getAddress() const { return address; }

void Patient::setName(const std::string& n) { name = n; }
void Patient::setAge(int a) { age = a; }
void Patient::setAddress(const std::string& addr) { address = addr; }

void Patient::print() const {
    std::cout << "Patient[" << id << "] Name: " << name << " | Age: " << age << " | Address: " << address << "\n";
}

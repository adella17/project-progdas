///////////////////////////////////////////////////////////
//  Transaction.cpp
//  Implementation of the Class Transaction
//  Created on:      29-Nov-2025 23:53:25
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#include "Transaction.h"
#include <iostream>

Transaction::Transaction() : id(""), patientId(""), doctorId(""), fee(0.0) {}
Transaction::Transaction(const std::string& id, const std::string& patientId, const std::string& doctorId, double fee)
    : id(id), patientId(patientId), doctorId(doctorId), fee(fee) {}

std::string Transaction::getId() const { return id; }
std::string Transaction::getPatientId() const { return patientId; }
std::string Transaction::getDoctorId() const { return doctorId; }
double Transaction::getFee() const { return fee; }

void Transaction::setFee(double f) { fee = f; }
double Transaction::calculateFee() const { return fee; }

void Transaction::print() const {
    std::cout << "Transaction[" << id << "] Patient: " << patientId << " | Doctor: " << doctorId << " | Fee: " << fee << "\n";
}

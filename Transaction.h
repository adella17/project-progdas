///////////////////////////////////////////////////////////
//  Transaction.h
//  Implementation of the Class Transaction
//  Created on:      29-Nov-2025 23:53:24
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string id;
    std::string patientId;
    std::string doctorId;
    double fee;
public:
    Transaction();
    Transaction(const std::string& id, const std::string& patientId, const std::string& doctorId, double fee);

    std::string getId() const;
    std::string getPatientId() const;
    std::string getDoctorId() const;
    double getFee() const;

    void setFee(double fee);
    double calculateFee() const; // for now returns fee (could be extended)
    void print() const;
};

#endif // TRANSACTION_H

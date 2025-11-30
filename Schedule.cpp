///////////////////////////////////////////////////////////
//  Schedule.cpp
//  Implementation of the Class Schedule
//  Created on:      29-Nov-2025 23:53:22
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#include "Schedule.h"
#include <iostream>

Schedule::Schedule() : id(""), doctorId(""), day(""), time("") {}
Schedule::Schedule(const std::string& id, const std::string& doctorId, const std::string& day, const std::string& time)
    : id(id), doctorId(doctorId), day(day), time(time) {}

std::string Schedule::getId() const { return id; }
std::string Schedule::getDoctorId() const { return doctorId; }
std::string Schedule::getDay() const { return day; }
std::string Schedule::getTime() const { return time; }

void Schedule::setDay(const std::string& d) { day = d; }
void Schedule::setTime(const std::string& t) { time = t; }

void Schedule::print() const {
    std::cout << "Schedule[" << id << "] DoctorID: " << doctorId << " | " << day << " " << time << "\n";
}

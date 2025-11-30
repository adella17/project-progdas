///////////////////////////////////////////////////////////
//  Schedule.h
//  Implementation of the Class Schedule
//  Created on:      29-Nov-2025 23:53:21
//  Original author: LENOVO
///////////////////////////////////////////////////////////

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>

class Schedule {
private:
    std::string id;
    std::string doctorId;
    std::string day;
    std::string time;
public:
    Schedule();
    Schedule(const std::string& id, const std::string& doctorId, const std::string& day, const std::string& time);

    std::string getId() const;
    std::string getDoctorId() const;
    std::string getDay() const;
    std::string getTime() const;

    void setDay(const std::string& day);
    void setTime(const std::string& time);

    void print() const;
};

#endif // SCHEDULE_H
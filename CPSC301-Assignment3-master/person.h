//
//  Person.hpp
//  cpsc301 assignment3
//
//  Created by Lee Yi Wei on 2019/2/26.
//  Copyright © 2019 Lee Yi Wei. All rights reserved.
//

#ifndef Person_h
#define Person_h

#include <stdio.h>
#include <string>
using namespace std;

class Person
{
private:
    string firstName;
    string lastName;
    int employeeID;
    string companyName;
    float hoursWorked;
    float payRate;
public:
    Person();
    void setFirstName(string fName);
    string getFirstName();
    void setLastName(string lName);
    string getLastName();
    void setEmployeeId(int id);
    int getEmployeeId();
    void setCompanyName(string CoName);
    string getCompanyName();
    void setPayRate(float rate);
    float getPayRate();
    void setHoursWorked(float hours);
    float getHoursWorked();
    float totalPay();
    string fullName();
};

#endif /* Person_h */

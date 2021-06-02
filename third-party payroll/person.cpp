//
//  Person.cpp
//  cpsc301 assignment3
//
//  Created by Lee Yi Wei on 2019/2/26.
//  Copyright © 2019 Lee Yi Wei. All rights reserved.
//
#include<iostream>
#include "Person.hpp"

Person::Person()
{
    
}

void Person::setLastName(string lName)
{
    lastName=lName;
}
string Person::getLastName()
{
    return lastName;
}

void Person::setFirstName(string fName)
{
    firstName=fName;
}
string Person::getFirstName()
{
    return firstName;
}

void Person::setEmployeeId(int id)
{
    employeeID=id;
}
int Person::getEmployeeId()
{
    return employeeID;
}

void Person::setCompanyName(string CoName)
{
    companyName=CoName;
}
string Person::getCompanyName()
{
    return companyName;
}

void Person::setPayRate(float rate)
{
    payRate=rate;
}
float Person::getPayRate()
{
    return payRate;
}

void Person::setHoursWorked(float hours)
{
    hoursWorked=hours;
}
float Person::getHoursWorked()
{
    return hoursWorked;
}
float Person::totalPay()
{
    return hoursWorked*payRate;
}

string Person::fullName()
{
    return firstName+" "+lastName;
}

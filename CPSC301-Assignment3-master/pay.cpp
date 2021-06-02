#include "Person.h"
#include "Person.cpp"
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<vector>

void readDate( vector<Person> &employeesvect);
void getCompanies(vector<Person> &employeesvect,vector<string> &companyName);
void printHighestPaid(vector<Person> &employeesvect);
void separateAndSave(vector<Person> &employeesvect,vector<string> &companyName);


void readDate(vector<Person> &employeesvect) //read the data use vector to replace array
{
    string lName;
    string fName;
    string companyName;
    float payRate,hoursWorked;
    int employeeID;
    
    ifstream file;
    file.open("input.txt");
    if(file.fail())
    {
        cout<<"Can't open the file."<<endl;
        exit(1);
    }
    
        while(file>>fName>>lName>>employeeID>>companyName>>payRate>>hoursWorked) //input the data into vector
        {
            Person p;
             p.setLastName(lName);
             p.setFirstName(fName);
             p.setEmployeeId(employeeID);
             p.setCompanyName(companyName);
             p.setPayRate(payRate);
             p.setHoursWorked(hoursWorked);
            employeesvect.push_back(p); //add the data to the back of vector
        }
    file.close();
}

void getCompanies(vector<Person> &employeesvect,vector<string> &companyvect) //input the companyname into companyvect vector
{
    for(int i=0;i<employeesvect.size();i++)
    {
        //push back the data in the employeevect when vector at i and the data is getcompanyname()
        companyvect.push_back(employeesvect.at(i).getCompanyName());
    }
    
}

//find the highestpaid
void printHighestPaid(vector<Person> &employeesvect)
{
    string name,companyName;
    int employeeID=0;
    
    float totalpay=0;

    for(int i=0;i<employeesvect.size();i++) //use loop to read each people data in the employeesvect
    {
        //find the highest when the totalpay > employeesvect then will not input data
         if(totalpay<employeesvect.at(i).totalPay())
        {
            totalpay=employeesvect.at(i).totalPay();
            name=employeesvect.at(i).fullName();
            employeeID=employeesvect.at(i).getEmployeeId();
            companyName=employeesvect.at(i).getCompanyName();
            totalpay=employeesvect.at(i).totalPay();
        }
        
    }
    cout<<"Highest paid: "<<name<<endl;
    cout<<"Employee ID: "<<employeeID<<endl;
    cout<<"Employee: "<<companyName<<endl;
    cout<<"Total Pay: $"<<fixed<<setprecision(2)<<totalpay<<endl;
    
 
}

// use vector companyName to get company name than use name== companyname to separte

void separateAndSave(vector<Person> &employeesvect,vector<string> &companyName)
{
    //use vector companyname.size() to catch how much company
    for(int i=0;i<companyName.size();i++)
    {
        float total=0;
        string companyname = companyName.at(i);
        ofstream outfile;
        outfile.open(companyname+".txt");
        outfile << "--------------------------------------" << endl;
        //second loop that use to read all the data
        for(int j=0;j<employeesvect.size();j++)
        {
            //when the data in the employees vector's getcompanyname equal the company name that when the companyName read then outfile
            if(employeesvect.at(j).getCompanyName() == companyName.at(i))
            {
                outfile<<employeesvect.at(j).fullName()<<" "<<endl;
                outfile<<employeesvect.at(j).getEmployeeId()<<" ";
                outfile<<employeesvect.at(j).getCompanyName()<<" ";
                outfile<<"$"<<fixed<<setprecision(2)<<employeesvect.at(j).totalPay()<<endl;
                total+=employeesvect.at(j).totalPay();
            }

        }
        //out for the second loop if it in second loop it will read many times
        outfile << fixed << setprecision(2) << "Total $" << total;
        }

}
 


int main()
{
    vector<Person> employees;
    vector<string> companyNames;
    readDate(employees);
    getCompanies(employees, companyNames);
    printHighestPaid(employees);
    separateAndSave(employees, companyNames);
    system("PAUSE");
    
}

/*
 Highest paid: Ryan Ward
 Employee ID: 150
 Employee: Douglas
 Total Pay: $3281.00
 sh: PAUSE: command not found
 Program ended with exit code: 0
 */

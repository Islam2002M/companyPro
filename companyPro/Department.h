#pragma once
#include <string>
#include <vector>
#include "Employee.h"
using namespace std;
class Employee;

class Department {
private:
    string name;
    vector<Employee*> emp;

public:
    Department(string name, vector<Employee*> emp);

    bool operator==(const Department& other) const;
    bool existEmp(const Employee* x) const;
    bool existID(string id) const;
    string getName()const;
    bool addEmp(Employee* emp);
    bool deleteEmp(string id);
    bool deleteEmp(Employee* empp);
    int NumOfEmps4Dep() const;
    bool updata(Employee* empp, double sal);
    void updatede(string newName);
  
};


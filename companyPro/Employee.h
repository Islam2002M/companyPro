#pragma once
#include <string>
#include <vector>
#include "Department.h"
using namespace std;
class Department;

class Employee {
private:
    string id;
    string name;
    double salary;
    Department* dep;
    vector<string> positions;

public:
    // Constructor
    Employee(string id, string name, double salary, Department* dep, vector<string> positions);

    // Getters
    string getID() const;
    string getName() const;
    double getSalary() const;
    Department* getDepartment() const;
    vector<string> getPositions() const;

    // Setters
    void setID(string id);
    void setName(string name);
    void setSalary(double salary);
    void setDepartment(Department* dep);
    void setPositions(vector<string> positions);

    bool operator==(const Employee& other) const;
    void updateEmployee(string newId, string newName, double newSalary, Department* newDep, vector<string> newPositions);

};


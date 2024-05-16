#pragma once
#include <string>
#include <vector>
#include "Department.h"
#include "Employee.h"
using namespace std;
class Employee;
class Department;

class Company {
private:
    string name;
    static vector<Department*> dep;
    static vector<Employee*> employees;
    static Company* instance;
    //constructor
    Company(string name);

public:
    static Company* getInstance(string name);
    static int numOfDeps();
    static bool existDep(const Department* x);
    static Department* existDep(string depName);
    static bool addDepartment(Department* d);
    static bool removeDepartment(string dname);
    static bool exist(Employee* e);
    static Employee* exist(string id);
    static void addE(Employee* e);
    void assignE(Employee* e, Department* d);
    static void deleteE(string emID);
    void update(Employee* e,double sal);
    void updatedep(Department* d);
    static int NumOfEmps4comp();
   static Employee* findEmployee(string empId);
   //void print();

};




#include<iostream>
#include<vector>
#include<algorithm>
#include "Company.h"
using namespace std;

Company* Company::instance = nullptr;
vector<Department*> Company::dep;
vector<Employee*> Company::employees;

Company::Company(string name) : name(name) {}

Company* Company::getInstance(string name) {
    if (!instance) {
        instance = new Company(name);
    }
    return instance;
}

int Company::numOfDeps() {
    return dep.size();
}

bool Company::existDep(const Department* x) {
    for (int i = 0; i < dep.size(); i++) {
        if (dep[i] == x) {
            return true;
        }
    }
    return false;
}

bool Company::addDepartment(Department* d) {
    if (existDep(d->getName()))
    {
        cout << "This department name exist!" << endl;
        return false;
    }
    if (!existDep(d)) {
        dep.push_back(d);
        cout << "You have added the department '" << d->getName() << "' to the company." << endl;
        return true;
    }
    cout << "This department already exists!" << endl;
    return false;
}

bool Company::removeDepartment(string dname)
{

    Department* departmentToRemove = existDep(dname);
    // all employee in this dep in the company i want to set their dep={};
   // for (int i = 0; i < employees.size(); i++)
       // if (employees[i]->getDepartment()->getName() == dname)
           // employees[i]->setDepartment(NULL);
    if (departmentToRemove) {
        auto it = find(dep.begin(), dep.end(), departmentToRemove);
        if (it != dep.end()) {
            dep.erase(it);
            cout << "You have deleted the " << departmentToRemove->getName() << " department from the company and all employees become without department" << endl;
            delete departmentToRemove; 
            return true;
        }
    }

    cout << "This department doesn't exist, so you can't delete it!" << endl;
    return false;
}

bool Company::exist(Employee* e) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == e) {
            return true;
        }
    }
    return false;
}
Employee* Company::exist(string id)
{
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i]->getID() == id) {
            return employees[i];
        }
    }
    return NULL;

}

void Company::addE(Employee* e) {
    if (exist(e->getID()))
    {
        cout << "This ID already exist!" << endl;
        return;
    }
    if (!exist(e)) {
        employees.push_back(e);
        cout << "You have added the employee with ID " << e->getID() << " to the company." << endl;
    }
    else {
        cout << "Employee already exists." << endl;
    }
}
Employee* Company::findEmployee(string empId) {
    for (Employee* emp : employees) {
        if (emp->getID() == empId) {
            return emp;
        }
    }
    return nullptr; // Employee not found
}
void Company::deleteE(string empId) {
    Employee* employeeToDelete = findEmployee(empId);

    if (employeeToDelete) {
        auto it = find(employees.begin(), employees.end(), employeeToDelete);
        if (it != employees.end()) {
            employees.erase(it);
            cout << "You have deleted the employee with ID " << empId << " from the company." << endl;
            // Assuming the employee is automatically removed from their department
            if (employeeToDelete->getDepartment())
            {
                employeeToDelete->getDepartment()->deleteEmp(empId);
                cout << " employee is automatically removed from its department" << endl;
            }
            delete employeeToDelete; 
            return;
        }
    }

    cout << "This employee doesn't exist, so you can't delete it!" << endl;
 
}
void Company::update(Employee* e, double sal)
{
   
    if (!exist(e))
    {
        std::cout << "You tried to update a non-existent employee!" << std::endl;
        return;
    }
    for (size_t i = 0; i < employees.size(); i++)
    {
        if (e == employees[i])
        {
            employees[i]->updateEmployee(e->getID(), e->getName(), sal, e->getDepartment(), e->getPositions());
            cout << "you have update the salary for the employee which have ID: " << e->getID() << " in the main company" << endl;

        }
    }
}
void Company::updatedep(Department* d)
{
    string oldName = d->getName();
  if (existDep(d)) {
        for (auto it = dep.begin(); it != dep.end(); ++it) {
            if ((*it) == d) {
                d->updatede("Soft engineering");
                cout << " you have update the " << oldName << " department into " << d->getName()<< endl;
                return;
            }
        }
    }
    cout << "This department doesn't exist, so you can't delete it!" << endl;
    
}

void Company::assignE(Employee* e, Department* d) {
    d->addEmp(e);
}
Department* Company::existDep(string depName)
{
    for (Department* dept : dep) {
        if (dept->getName() == depName) {
            return dept;
        }
    }
    return nullptr;
 }
int Company::NumOfEmps4comp()
{
    return employees.size();
 }
/*void Company::print()
{
    cout << employees[0]->getSalary() << endl;
}*/

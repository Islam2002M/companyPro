#include "Department.h"
#include "Employee.h"
#include "Company.h" 
#include<iostream>
using namespace std;
Department::Department(std::string name, std::vector<Employee*> emp)
    : name(name), emp(emp)
{}

bool Department::existEmp(const Employee* x) const {
    for (size_t i = 0; i < emp.size(); i++)
        if (emp[i] == x)
            return true;
    return false;
}

bool Department::existID(std::string id) const {
    for (size_t i = 0; i < emp.size(); i++)
        if (emp[i]->getID() == id)
            return true;
    return false;
}

std::string Department::getName() const {
    return name;
}

bool Department::addEmp(Employee* Eemp) {
    Eemp->setDepartment(this);
    // Check if employee exists
    if (existEmp(Eemp)) {
        std::cout << "You tried to add an existing employee." << std::endl;
        return false;
    }

    // Check if the ID exists
    if (existID(Eemp->getID())) {
        std::cout << "You tried to add an employee with an existing ID. Please change the ID and try again." << std::endl;
        return false;
    }

    // Add the employee to the department
    emp.push_back(Eemp);
    std::cout << "You have added an employee with ID " << Eemp->getID() << " to the " << this->getName() << " department." << std::endl;

    // Add the employee to the company
    Company* company = Company::getInstance("comp");
    if (company != nullptr) { 
        company->addE(Eemp);
    }
    else {
        std::cout << "Error: Company instance not found." << std::endl;
        return false;
    }
    return true;
}

bool Department::deleteEmp(std::string id) {
    if (!existID(id))
    {
        std::cout << "You tried to delete a non-existent employee!" << std::endl;
        return false;
    }
    for (auto it = emp.begin(); it != emp.end(); ++it)
    {
        if ((*it)->getID() == id)
        {
            emp.erase(it);
            return true;
        }
    }
    return false;
}

bool Department::deleteEmp(Employee* empp) {
    auto it = std::find(emp.begin(), emp.end(), empp);
    if (it == emp.end()) {
        cout << "You tried to delete a non-exist employee!" << std::endl;
        return false;
    }

    emp.erase(it);
    cout << "you have delete the employee which have ID " << empp->getID() << " from the " << empp->getDepartment()->getName() << " department, and it still in the main company if you dosen't delete it from the company" << endl;
    return true;
}

int Department::NumOfEmps4Dep() const {
    return emp.size();
}

bool Department::updata(Employee* empp,double sal) {
    if (!existEmp(empp))
    {
        std::cout << "You tried to update a non-existent employee!" << std::endl;
        return false;
    }
    for (size_t i = 0; i < emp.size(); i++)
    {
        if (empp == emp[i])
        {
            emp[i]->updateEmployee(empp->getID(), empp->getName(), sal, empp->getDepartment(), empp->getPositions());
            cout << "you have update the salary (it become : " << sal << ")" << "of employee which have ID " << empp->getID() << " on its department and automaticlly it will updated in the main company" << endl;            //update if in the company 
            
        }
    }
    return false;
}
void Department::updatede(string newname) {
    name = newname;
}

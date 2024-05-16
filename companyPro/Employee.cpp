#include "Employee.h"
#include"Department.h"
// Constructor
Employee::Employee(std::string id, std::string name, double salary, Department* dep, std::vector<std::string> positions)
    : id(id), name(name), salary(salary), dep(dep), positions(positions)
{}

// Getters
std::string Employee::getID() const {
    return id;
}

std::string Employee::getName() const {
    return name;
}

double Employee::getSalary() const {
    return salary;
}

Department* Employee::getDepartment() const {
    return dep;
}

std::vector<std::string> Employee::getPositions() const {
    return positions;
}

// Setters
void Employee::setID(std::string id) {
    this->id = id;
}

void Employee::setName(std::string name) {
    this->name = name;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

void Employee::setDepartment(Department* dep) {
    this->dep = dep;
}

void Employee::setPositions(std::vector<std::string> positions) {
    this->positions = positions;
}

bool Employee::operator==(const Employee& other) const {
    return id == other.id && name == other.name && salary == other.salary && dep == other.dep && positions == other.positions;
}
void Employee::updateEmployee(string newId, string newName, double newSalary, Department* newDep, vector<string> newPositions)
{
    id = newId;
    name = newName;
    salary = newSalary;
    dep = newDep;
    positions = newPositions;
}

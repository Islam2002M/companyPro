#include <iostream>
#include <vector>
#include <algorithm>
#include "Company.h"
#include "Department.h"
#include "Employee.h"
using namespace std;

int main() {
    cout << "***** Creating company & 2 departments & 6 employees initially *****" << endl;

    // Create company
    Company* company = Company::getInstance("comp");
    /*try {
       
        string n = emp->getDepartment()->getName();
        cout << n << endl;
        company->removeDepartment("SoftwareEngineering");
        n = emp->getDepartment()->getName();
        cout << n << endl;
    }
    catch (const std::bad_alloc& e) {
        cerr << "Memory allocation error: " << e.what() << endl;
    }
    catch (const std::exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    catch (...) {
        cerr << "An unknown error occurred." << endl;
    }*/

   int choice;
    do {
        cout << "***** Menu *****" << endl;
        cout << "1. Adding" << endl;
        cout << "2. Deleting" << endl;
        cout << "3. Updating" << endl;
        cout << "4. Exit" << endl;
        cout << "you can press 5 to print the # of employees in the company" << endl;
        cout << "6. Back to the main list" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Adding
            int addChoice;
            cout << "1. Add Department" << endl;
            cout << "2. Add Employee" << endl;
            cout << "Enter your choice: ";
            cin >> addChoice;
            if (addChoice == 1) {
                // Add department
                string deptName;
                cout << "Enter department name: ";
                cin >> deptName;
                Department* newDept = new Department(deptName, {});
                company->addDepartment(newDept);
            }
            else if (addChoice == 2) {
                int addEChoice;
                cout << "1. Add Employee to Company" << endl;
                cout << "2. Add Employee to Specific Department" << endl;
                cout << "Enter your choice: ";
                cin >> addEChoice;
                if (addEChoice == 1) {
                    // Add employee to company
                    string empId, empName;
                    int empSalary;
                    cout << "Enter employee ID: ";
                    cin >> empId;
                    cout << "Enter employee name: ";
                    cin >> empName;
                    cout << "Enter employee salary: ";
                    cin >> empSalary;
                    Employee* newEmp = new Employee(empId, empName, empSalary, {}, {});
                    company->addE(newEmp);
                }
                else if (addEChoice == 2) {
                    // Add employee to specific department
                    string empId, empName, deptName;
                    int empSalary;
                    cout << "Enter employee ID: ";
                    cin >> empId;
                    cout << "Enter employee name: ";
                    cin >> empName;
                    cout << "Enter employee salary: ";
                    cin >> empSalary;
                    cout << "Enter the name of department : ";
                    cin >> deptName;
                    Department* targetDepartment = company->existDep(deptName); 
                    if (targetDepartment) {
                        Employee* newEmp = new Employee(empId, empName, empSalary, {}, {});
                        targetDepartment->addEmp(newEmp); 
                    }
                    else {
                        cout << "Department '" << deptName << "' does not exist." << endl;
                    }
                }
                else {
                    cout << "Invalid choice" << endl;
                }
            }
            break;

        case 2: // Deleting
            int deleteChoice;
            cout << "1. Delete Department" << endl;
            cout << "2. Delete Employee" << endl;
            cout << "Enter your choice: ";
            cin >> deleteChoice;
            if (deleteChoice == 1) {
                // Delete department
                string deptName;
                cout << "Enter department name to delete: ";
                cin >> deptName;
                company->removeDepartment(deptName);
               
            }
            else if (deleteChoice == 2) {
                // Delete employee
                string empId;
                cout << "Enter employee ID to delete: ";
                cin >> empId;
                int deleteChoice;
                cout << "1. Delete Employee from Company" << endl;
                cout << "2. Delete Employee from Specific Department" << endl;
                cout << "Enter your choice: ";
                cin >> deleteChoice;

                if (deleteChoice == 1) {
                    // Delete employee from company
                    company->deleteE(empId);
                    
                }
                else if (deleteChoice == 2) {
                    // Delete employee from specific department
                    string deptName;
                    cout << "Enter the name of the department from which you want to delete the employee: ";
                    cin >> deptName;
                    Department* targetDepartment = company->existDep(deptName);
                    if (targetDepartment) {
                        if (targetDepartment->deleteEmp(empId)) {
                            cout << "Employee deleted from department '" << deptName << "' successfully." << endl;
                        }
                        else {
                            cout << "Employee with ID " << empId << " not found in department '" << deptName << "'." << endl;
                        }
                    }
                    else {
                        cout << "Department '" << deptName << "' not found." << endl;
                    }
                }
                else {
                    cout << "Invalid choice" << endl;
                }

            }
            else {
                cout << "Invalid choice" << endl;
            }
            break;

        case 3: // Updating
            int updateChoice;
            cout << "1. Update Department" << endl;
            cout << "2. Update Employee" << endl;
            cout << "Enter your choice: ";
            cin >> updateChoice;
            if (updateChoice == 1) {
                // Update department
                string deptName,newName;
                cout << "Enter department name to update: ";
                cin >> deptName;
                cout << "Enter a new department name" << endl;
                cin >> newName;
                Department* targetDepartment = company->existDep(deptName);
                if (targetDepartment)
                {
                    (targetDepartment->updatede(newName));
                    cout << "you have changed the name of department from " << deptName << " into " << newName << endl;
                }
                else
                    cout << "you try to update a non exist department" << endl;
            }
            else if (updateChoice == 2) {
                // Update employee
                string empId;
                cout << "Enter employee ID to update: ";
                cin >> empId;
                double sal;
                cout << "Enter a new salary" << endl;
                cin >> sal;
                Employee* targetEmp = company->findEmployee(empId);
                if (targetEmp)
                {
                   // company->update(targetEmp,sal);
                    targetEmp->getDepartment()->updata(targetEmp,sal);
                }
                //cout << targetEmp->getSalary() << endl;

            }
            else {
                cout << "Invalid choice" << endl;
            }
            break;

        case 4: // Exit
            cout << "Exiting program..." << endl;
            break;

        case 5: 
            cout << "The number of employee in the company : " <<company->NumOfEmps4comp()<< endl;
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);

    // Clean up memory
  
    delete company;
   
    return 0;
}

#include <iostream>
#include <string>
using namespace std;


void Employee_Details(string employeename, string designation, string department, int employeeNumber, double basicSalary) {
    cout << "Enter Employee Name: ";
    getline(cin, employeename);

    cout << "Enter Designation: ";
    getline(cin, designation);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Employee Number: ";
    cin >> employeeNumber;

    cout << "Enter Basic Salary: ";
    cin >> basicSalary;

    
    cin.ignore();
}


void Display_Menu() {
    
    cout << "1- Calculate the Total Allowance\n";
    cout << "2- Calculate the Gross Pay\n";
    cout << "3- Calculate the Total Deduction\n";
    cout << "4- Calculate the Net Pay\n";
    cout << "5- Display the Salary Sheet\n";
    cout << "6- Exit from the system\n";
}


double Total_Allowance() {
    const double cost_of_living_allowance = 7800.00;
    const double monthly_allowance = 5000.00;
    const double salary_arrears = 2640.00;

    return cost_of_living_allowance + monthly_allowance + salary_arrears;
}


double Gross_Pay(double basicSalary) {
    return basicSalary + Total_Allowance();
}


double Total_Deduction() {
    const double stam_duty = 25.00;
    const double upf_employee = 5708.32;

    return stam_duty + upf_employee;
}


double Net_Pay(double grossPay, double totalDeduction) {
    return grossPay - totalDeduction;
}


void Salary_Sheet(const string name, const string designation, const string department, int employeeNumber, double basicSalary) {
    double totalAllowance = Total_Allowance();
    double grossPay = Gross_Pay(basicSalary);
    double totalDeduction = Total_Deduction();
    double netPay = Net_Pay(grossPay, totalDeduction);

    
    cout << "Employee Name: " << name << endl;
    cout << "Designation: " << designation << endl;
    cout << "Department: " << department << endl;
    cout << "Employee Number: " << employeeNumber << endl;
    cout << "Basic Salary: " << basicSalary << endl;
    cout << "Total Allowance: " << totalAllowance << endl;
    cout << "Gross Pay: " << grossPay << endl;
    cout << "Total Deduction:" << totalDeduction << endl;
    cout << "Net Pay: " << netPay << endl;
}

int main() {
    
    string name, designation, department;
    int employeeNumber;
    double basicSalary;

    
    Employee_Details(name, designation, department, employeeNumber, basicSalary);

    int choice;

    do {
        
        Display_Menu();

        
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch (choice) {
            case 1:
                cout << "Total Allowance: $" << Total_Allowance() << endl;
                break;

            case 2:
                cout << "Gross Pay: $" << Gross_Pay(basicSalary) << endl;
                break;

            case 3:
                cout << "Total Deduction: $" << Total_Deduction() << endl;
                break;

            case 4:
                cout << "Net Pay: $" << Net_Pay(Gross_Pay(basicSalary), Total_Deduction()) << endl;
                break;

            case 5:
                Salary_Sheet(name, designation, department, employeeNumber, basicSalary);
                break;

            case 6:
                cout << "THANK YOU HAVE NICE DAY...\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6); 

    return 0;
}
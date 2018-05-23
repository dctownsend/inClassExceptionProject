//
//  main.cpp
//  ExceptionProject
//
//  Created by dakota townsend on 5/22/18.
//  Copyright © 2018 dakota townsend. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

class Employee {
private:
    string eName;
    string hDate;
    int eNum;
public:
    Employee() {
        eName = "";
        hDate = "";
        eNum = 0;
    }
    Employee(string name, int num, string date) {
        eName = name;
        eNum = num;
        hDate = date;
    }
    class InvalidEmployeeNumber {};
    void setName(string);
    void setDate(string);
    void setNum(int);
    
    string getName();
    string getDate();
    int getNum();
};

void Employee:: setName(string var) {
    eName = var;
}
void Employee:: setDate(string var1) {
    hDate = var1;
}
void Employee:: setNum(int var2) {
   if(var2 < 0 || var2 > 9999)
       throw InvalidEmployeeNumber();
    else
    eNum = var2;
}
string Employee:: getName() {
    return eName;
}
string Employee:: getDate() {
    return hDate;
}
int Employee:: getNum() {
    return eNum;
}

class ProductionWorker: public Employee {
private:
    int shift;
    double hourly;
public:
    ProductionWorker(){
        shift = 0;
        hourly = 0;
    }
    ProductionWorker(int shf, double hrly){
        shift = shf;
        hourly = hrly;
    }
    class InvalidShift{};
    class InvalidPayRate{};
    void setShift(int);
    void setPayRate(double);
    
    int getShift();
    double getHourly();
};

void ProductionWorker:: setShift(int var) {
    if(var < 0 || var > 2)
        throw InvalidShift();
    else
        shift = var;
}
void ProductionWorker:: setPayRate(double pay) {
    if(pay < 1)
        throw InvalidPayRate();
    else
        hourly = pay;
}
int ProductionWorker:: getShift() {
    return shift;
}
double ProductionWorker:: getHourly() {
    return hourly;
}

int main() {
    int s;
    double p;
    
    cout << "1. DayShift \n2. NightShift " << endl;
    cout << "enter choice: ";
    cin >> s;
    cout << "enter hourly payrate: ";
    cin >> p;
    
    ProductionWorker e1(0,0);
    
    e1.setName("Dakota");
    e1.setDate("October 30 ");
    
    try{
        e1.setNum(1000);
        e1.setShift(s);
        e1.setPayRate(p);
    } catch(Employee:: InvalidEmployeeNumber) {
        cout << "error: invalid employee number" << endl;
    } catch(ProductionWorker:: InvalidShift) {
        cout << "error: invalid shift" << endl;
    } catch (ProductionWorker:: InvalidPayRate) {
        cout << "error: invalid payrate" << endl;
    }
    
    cout << "\n";
    cout << "employee details: \n" << endl;
    cout << "name: " << e1.getName() << endl;
    cout << "number: " << e1.getNum() << endl;
    cout << "hire date: " << e1.getDate() << endl;
    cout << "shift: " << e1.getShift() << endl;
    cout << "hourly pay: " << e1.getHourly() << endl;
    
    return 0;
};

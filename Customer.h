#pragma once
#include<iostream>
#include"Admin .h"
#include"Product.h"
#include"Person.h"

using namespace std;
class Customer:public Person
{
public:
	string username, password, firstname, lastname, email, registration_date, gender, bloodgroup, contact, address, file;
	int id;
	Customer();
	 void Save();
	 void add();
	 void Readdata(Customer* Data, bool);
	 void Display();
	 void Addtocart(int, int, int, int&);
	 void Viewproduct();
	 void Checkout();
};

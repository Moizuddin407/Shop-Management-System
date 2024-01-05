#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Person.h"
using namespace std;

class Shopkeeper:public Person
{
public:
	string username, password, firstname, lastname, email, registration_date, gender, bloodgroup, contact, address, file;
	int Id;
	int noofproducts;
	Shopkeeper();
	~Shopkeeper();
	void Save();
	void add();
	void Display();
	void readData(Shopkeeper* Data, bool);
};

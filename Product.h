#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include"Person.h"
using namespace std;
enum class Catagories
{
	Sports,
	Garments,
	Eatables,
	Medicines,
	Fashion,
};

class Product:public Person
{
public:
	string  Description, Color, file, categori, Name;
	int sid, pid, priceofproduct;
	string Atricalsize;
	Catagories catagories;
	int stock = 0;
	Product();
	void readdata(Product*,bool);
	void add();
	void Display();
	void Save();
	~Product();
};



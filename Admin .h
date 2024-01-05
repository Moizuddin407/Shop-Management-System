#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Admin
{
private:
	string file, productfile, shopekeeperfile ,customerfile;
public:
	Admin();
	void AddShopkeeper();
	void EditShopkeeper();
	void DeleteShopkeeper();
	void AddCustomer();
	void EditCustomer();
	void DeleteCustomer();
	void AddProduct();
	void EditProduct();
	void DeleteProduct();
};
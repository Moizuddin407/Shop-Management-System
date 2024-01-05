#include"Admin .h"
#include"Shopkeeper.h"
#include"Product.h"
#include"Customer.h"
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	//colour added using windows.h library.
	system("color 1F");
start:
	Customer p;
	string username, passwordadmin;
	int a;
	bool BreakMenu = false;
	//clear screen function.
	system("cls");

	cout << "\n\t------------------ Welcome to INVENTORY MANAGEMENT SYSTEM ------------------\n\n";
	cout << " \n\t  *********************  Which Module Do You want access? ********************* \n";
	cout << "\n\t ==========>> Press 1 for Administrator\n";
	cout << "\n\t ==========>> Press 2 for Shopkeeper\n";
	cout << "\n\t ==========>> Press 3 for Customer\n";
	cout << "\n\t ==========>> Enter your Choice = ";
	//label to return back if wrong input given.
	input_main:
	//to handle all edge cases of input.
	//this funtion will check if string input is given instead of int.
	void Char_String_Check();
	{
		//take input until right input is not given.
		while (!(cin >> a))
		{
			cout << "Incorrect input.\n \n\t !!! Press from 1-3 !!!\n";
			cin.clear();
			cin.ignore();
		}
	}
	//this will take input. If input is wrong, it will move back to input label
	//and loop 
	if (a > 3 || a < 1)
	{

		cout << "\n\t !!! Press from 1-3 !!!\n";
		cin.clear();
		cin.ignore();
		goto input_main;
	}
	switch (a)
	{

	case 1:
	{
		system("cls");
	Admin_Pass_User:
		cout << "\n\t ==========>> Aministrator Kindly Sign-IN  !!!" << endl;
		cout << "\n\t ==========>> Enter USERNAME :";
		cin >> username;
		cout << endl;
		cout << "\n\t ==========>> Enter PASSWORD :";
		cin >> passwordadmin;
		cout << endl;
		if (username == "moiz" && passwordadmin == "moiz")
		{
			int b = 1;
			//check for wrong input of ID PASS.
			while (b != 0)
			{
				admin_again:
				Admin A;
				cout << "\n\t *** What do you Want to Perform ? ***\n";
				cout << "\n\t     --- ADD ---\n\t ---> 1.Add New ShopKeeper \n\t ---> 2.Add New Customer \n\t ---> 3.Add New Product \n\t     --- EDIT ---\n\t ---> 4.Edit Shopkeeper Details\n\t ---> 5.Edit Costomer Details\n\t ---> 6.Edit Product Details \n\t     --- DELETE ---\n\t ---> 7.Delete Shopkeeepr\n\t ---> 8.Delete Customer\n\t ---> 9.Delete Product\n\t(0 TO EXIT)\n";
			reinput_admin:
				//to check if after logging into admin, no char is given.
				void Char_String_Check();
				{

					while (!(cin >> b))
					{
						cout << "\n\t #### Input Between the Range ####\n\n\t !!! Press from 0-9 !!!\n";
						cin.clear();
						cin.ignore();
					}
				}
				//to choose correct option from 1-9 after admin login.
				if (b > 9 || b < 0)
				{

					cout << "\n\t !!! Press from 0-9 !!!\n";
					cin.clear();
					cin.ignore();
					goto reinput_admin;
				}
				switch (b)
				{
				case 1:
				{

					A.AddShopkeeper();
					break;
					goto admin_again;
				}
				case 2:
				{
					A.AddCustomer();
					break;
					goto admin_again;
				}
				case 3:
				{
					A.AddProduct();
					break;
					goto admin_again;
				}
				case 4:
				{
					A.EditShopkeeper();
					break;
					goto admin_again;
				}
				case 5:
				{
					A.EditCustomer();
					break;
					goto admin_again;

				}
				case 6:
				{
					A.EditProduct();
					break;
					goto admin_again;
				}
				case 7:
				{
					A.DeleteShopkeeper();
					break;
					goto admin_again;
				}
				case 8:
				{
					A.DeleteCustomer();
					break;
					goto admin_again;
				}
				case 9:
				{
					A.DeleteProduct();
					break;
					goto admin_again;
				}
				}

			}
		}
		else

		{
			cout << " \n\t Enter Correct Admin Username & Password \n\t :( " << endl;
			goto Admin_Pass_User;
	    }

		break;
	}
	//for shop keeper.
	case 2:
	{
		system("cls");
	shope:
		int n = 0;
		cout << " \n\t ~~~~~~ PRESS YOUR DESIRED OPTION ~~~~~~\n";
		cout << "\n\t ==========>>  1.Register To System\n\t ==========>> 2.SignIN To System\n\t ==========>> (0 To EXIT)" << endl;
	shopkeeper_input:
		void Char_String_Check();
		{

			while (!(cin >> n))
			{
				cout << "\n\t #### Input Between the Range ####\n\n\t !!! Press from 0-2 !!!\n";
				cin.clear();
				cin.ignore();
			}
		}
		if (n > 2 || n < 0)
		{

			cout << "\n\t !!! Press from 0-2 !!!\n";
			cin.clear();
			cin.ignore();
			
			goto shopkeeper_input;
		}
		system("cls");

		if (n == 1)
		{
			Admin A;
			A.AddShopkeeper();
			goto shope;
		}
		else if (n == 2)
		{
			bool c = false;
			int id = 0;
			while (c == false)
			{
				string email, password;
				cout << "\n\t ==========>> Email: ";
				cin >> email;
				cout << "\n\t===========>> Password: ";
				cin >> password;
				//sends data as input to check wether desired email pass exists or not.
				ifstream in("Shopkeeper.txt");
				in >> n;
				in.close();
				if (n > 0)
				{
					//checks id and pass.
					Shopkeeper* shopkeeper = new Shopkeeper[n];
					shopkeeper[0].readData(shopkeeper, 0);
					for (int i = 0; i < n; ++i)
					{
						if (shopkeeper[i].email == email)
							if (shopkeeper[i].password == password)
							{
								id = shopkeeper[i].Id;
								c = true;
							}
					}
				}
				else
				{
					cout << "NO DATA IS PRESENT!!!!" << endl;
					break;
				}
				if (!c)
					cout << "\n\t ______ NO DATA FOUND INPUT AGAIN !!! ______ " << endl;
			}
			if (c)
			{
			shope2:
				system("cls");
				cout << "\n\t ++++++ WELCOME TO SHOPKEEPER PORTAL ++++++ \n";
				cout << " \n\t ~~~~~~ PRESS YOUR DESIRED OPTION ~~~~~~\n";
				cout << "\n\t ==========>> 1.ADD New Product\n\t ==========>> 2.Edit Product Detail \n\t ==========>> 3.View Products\n\t(0 To Exit)\n:";
				int c;
				shopkeeper_input_check:
				void Char_String_Check();
				{

					while (!(cin >> c))
					{
						cout << "\n\t #### Input Between the Range ####\n\n\t !!! Press from 0-3 !!!\n";
						cin.clear();
						cin.ignore();
					}
				}
				if (c > 3 || c < 0)
				{

					cout << "\n\t !!! Press from 0-3 !!!\n";
					cin.clear();
					cin.ignore();
					goto shopkeeper_input_check;
				}
				switch (c)
				{
				case 0:
					goto shope;
				case 1:
				{
					ifstream in( "Product.txt");
					//for ID of product
					int n = 0;
					in >> n;
					in.close();
					//product array created to store data
					Product* products = new Product[n];
					//read data function provides space to add data in array and send it back to file.
					products[0].readdata(products,0);
					Product P;
					P.sid = id;
					//add function adds products according to details given.
					P.add();
					//data is being sent back into file.
					ofstream out("Product.txt");
					n++;
					out << n << endl;
					out.close();
					n--;
					for (int i = 0; i < n; ++i)
					{
						products[i].Save();
					}
					P.Save();
					goto shope2;
					break;
				}
				case 2:
				{
					ifstream in("Product.txt");
					in >> n;
					Product* product = new Product[n];
					product[0].readdata(product, 0);
					for (int i = 0; i < n; ++i)
					{
						if (product[i].sid == id)
						{
							product[i].Display();
						}
					}
					int pid = 0;
					cout << "Enter The Pid ";
					cin >> pid;
					for (int i = 0; i < n; ++i)
					{
						if (product[i].pid == pid)
						{
							product[i].add();
							product[i].pid = pid;
						}
					}
					ofstream out("Product.txt");
					out << n << endl;
					out.close();
					in.close();
					for (int i = 0; i < n; ++i)
					{
						product[i].Save();
					}
					goto shope2;
					break;

				}
				case 3:
				{
					ifstream in("Product.txt");
					in >> n;
					in.close();
					Product* product = new Product[n];
					product[0].readdata(product, 0);
					for (int i = 0; i < n; ++i)
					{
						if (product[i].sid == id)
						{
							product[i].Display();
						}
					}
					system("pause");
					goto shope2;
					break;
					
				}
				}
			}
			else
			{
				goto shope;
				system("cls");
				break;
			}
		}
		if (n == 0)
			goto start;
		break;
	}
	case 3:
	{
		system("cls");
	customer:
		system("cls");
		int n = 0;
		int CustomerAmount;
		cout << "\n\t---> 1.Register To System\n\t---> 2.SignIN To System\n\t (0 To EXIT)" << endl;
		customer_input:
		void Char_String_Check();
		{

			while (!(cin >> n))
			{
				cout << "\n\t #### Input Between the Range ####\n\n\t !!! Press from 0-3 !!!\n";
				cin.clear();
				cin.ignore();
			}
		}
		if (n > 2 || n < 0)
		{

			cout << "\n\t !!! Press from 0-2 !!!\n";
			cin.clear();
			cin.ignore();
			goto customer_input;
		}
		if (n == 1)
		{
			Admin A;
			A.AddCustomer();
			cout << "\n\t---> 1.Register To System\n\t---> 2.SignIN To System\n\t (0 To EXIT)" << endl;
			goto customer_input;
		}
		else if (n == 2)
		{

			bool c = false;
			int id = 0;
			while (c == false)
			{
				ifstream in("Customer.txt");
				in >> n;
				in.close();
				if (n > 0)
				{
					string mail, pass;
					cout << "\n\t EMAIL :  ";
					cin >> mail;
					cout << "\n\t PASSWORD : ";
					cin >> pass;
					Customer* customer = new Customer[n];
					customer[0].Readdata(customer, 0);
					for (int i = 0; i < n; ++i)
					{
						if (customer[i].email == mail && customer[i].password == pass)
							c = true;
					}
				}
				else
				{
					cout << "\n\t!!!!!! NO DATA IS PRESENT !!!!!!\n" << endl;
					break;
				}
				if (!c)
					cout << "\n\t!!!!!! NO DATA FOUND INPUT AGAIN \n!!!!!!" << endl;
			}
			if (c)
			{
				cout << "\n\t ++++++ WELCOME TO CUSTOMER PORTAL ++++++ \n";
				cout << "Enter Your Wallet Amount more then 1000(2000 etc): Rs  ";
			Price_check:
				while (!(cin >> CustomerAmount))
				{
					cout << "\n\t #### Input an INTEGER VALUE greater tha 1000####\n\n";
					cin.clear();
					cin.ignore();
					
				}
				if (CustomerAmount < 1000)
				{
					cout << "Enter Your Wallet Amount more then 1000(2000 etc): Rs  ";
					goto Price_check;
				}
				
			
			customer2:
				
				Customer C;
				cout << "\n\t ---> 1.View Product\n\t ---> 2.Add To Cart\n\t ---> 3.Check Out\n\t (0 To Exit)\n";
				int c;
				Customer_Portal_Check:
				void Char_String_Check();
				{

					while (!(cin >> c))
					{
						cout << "\n\t #### Input Between the Range ####\n\n\t !!! Press from 0-3 !!!\n";
						cin.clear();
						cin.ignore();
					}
				}
				if (c > 3 || c < 0)
				{

					cout << "\n\t !!! Press from 0-3 !!!\n";
					cin.clear();
					cin.ignore();
					goto Customer_Portal_Check;
				}
				switch (c)
				{
				case 0:
					goto customer;
				case 1:
				{
					C.Viewproduct();
					goto customer2;
					break;
				}
				case 2:
				{
					int pid = 0, Quantity = 0, sid = 0;
					C.Viewproduct();
					cout << "Enter The sid: ";
					cin >> sid;
					cout << "Enter The Pid to buy: ";
					cin >> pid;
					cout << "Enter The Quantity: ";
					cin >> Quantity;
					C.Addtocart(sid, pid, Quantity, CustomerAmount);
					goto customer2;

					break;

				}
				case 3:
				{
					ofstream of("CheckOut.txt");
					string address;
					cout << "Remaing Cash :" << CustomerAmount << endl;
					cout << "Enter The Shipment Address: ";
					cin >> address;
					cout << "The Products Will be Delivered to your Address : " << address<<endl;
					float totalamount, bill;
					totalamount = (2 / 100) * CustomerAmount;
					bill = totalamount + 200;
					cout << "Bill of Your Purchasing is = Rs " << bill << endl;
					cout << "\t\t\t\t\tThankYou For Purchasing :)" << endl;
					of << "\t" << CustomerAmount << "\t" << bill << endl;

					goto customer2;
					break;
				}
				}
			}
			else
				break;
		}
		else if (n == 0)
			goto start;
		break;
	}
	}
}
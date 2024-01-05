#include "Customer.h"

Customer::Customer()
{
	file = "Customer.txt";
	id = 0;
}

void Customer::Save()
{
	ofstream out(file,ios::app);
	out << id << ' ' << firstname << ' ' << lastname << ' ' << username
		<< ' ' << email << ' ' << password << ' ' << registration_date
		<< ' ' << gender << " " << bloodgroup << ' ' << contact
		<< ' ' << address << endl;
	out.close();
}

void Customer::add()
{
	cout << "\n\t ***** ENTER THE FOLLOWING CREDENTIALS TO MAKE AN ACCOUNT *****\n" << endl;
	cout << "\n\t ---> FirstName :\t ";
	cin >> firstname;
	cout << "\n\t ---> LastName : \t";
	cin >> lastname;
	cout << "\n\t ---> Gender : \t";
	cin >> gender;
	cout << "\n\t ---> Blood Group : \t";
	cin >> bloodgroup;
	cout << "\n\t ---> Contact : \t";
	cin >> contact;
	cout << "\n\t ---> UserName : \t";
	cin >> username;

	bool c = false;
	while (c == false)
	{
		cout << "\n\t ---> Email ID : ";
		cin >> email;
		for (int i = 0; email[i] != '\0'; ++i)
		{
			if (email[i] == '@')
				c = true;
		}

	}
	cout << "\n\t ---> Enter Password : ";
	cin >> password;
	cout << "\n\t ---> Registration Date : ";
	cin >> registration_date;
	cout << "\n\t ---> Enter The Address: ";
	cin >> address;

	ifstream in( "Customer.txt");
	int n = 0;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		id++;
	}
	in.close();
}

void Customer::Readdata(Customer* Data, bool check)
{
	ifstream in("Customer.txt");
	int n = 0;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		in >> Data[i].id;
		in >> Data[i].firstname;
		in >> Data[i].lastname;
		in >> Data[i].username;
		in >> Data[i].email;
		in >> Data[i].password;
		in >> Data[i].registration_date;
		in >> Data[i].gender;
		in >> Data[i].bloodgroup;
		in >> Data[i].contact;
		in >> Data[i].address;
	}
	if (check == true)
		Data[n].add();
}

void Customer::Display()
{
	cout << id << "\t " << firstname << "\t " << lastname << " \t    " << email << " \t   " << username << " \t   " << password << "\t    " << registration_date << "\t    " << gender << "\t    " << bloodgroup << "\t    " << contact << "\t    " << address << endl;

}


void Customer::Addtocart(int sid,int pid,int Quantity,int &amount)
{
	ifstream in("Product.txt");
	int n = 0;
	in >> n;
	in.close();
	Product* product = new Product[n];

	product[0].readdata(product, 0);

	for (int i = 0; i < n; ++i)
	{
		if (product[i].sid == sid && product[i].pid == pid)
		{
			while (Quantity > 0)
			{
				if (product[i].stock > 0)
					product[i].stock--;
				else
				{
					cout << "Out Of Stock" << endl;
					break;
				}
				if (amount >= product[i].priceofproduct)
					amount -= product[i].priceofproduct;
				else
				{
					cout << "Out Of Balance!!!" << endl;
					break;
				}
				Quantity--;
			}
			break;
		}
	}
	ofstream out("Product.txt");
	out << n << endl;

	for (int i = 0; i < n; ++i) product[i].Save();
}
void Customer::Viewproduct()
{
	ifstream in(file);
	int n;
	in >> n;
	Product* product = new Product[n];
	product->readdata(product, 0);
	for (int i = 0; i < n; ++i)
	{
		product[i].Display();
	}
}

void Customer::Checkout()
{
}

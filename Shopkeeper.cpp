#include"Shopkeeper.h"
#include<iostream>
using namespace std;
void Shopkeeper::add()
{
	cout << "\n\t ^^^^^^ ENTER THE FOLLOWING CREDENTIALS TO MAKE AN ACCOUNT ^^^^^^" << endl;
	cout << " \n\t ==========>>FirstName :\t ";
	cin >> firstname;
	cout << " \n\t ==========>>LastName : \t";
	cin >> lastname;
	cout << " \n\t ==========>>Gender : \t";
	cin >> gender;
	cout << " \n\t ==========>>BloodGroup : \t";
	cin >> bloodgroup;
	cout << " \n\t ==========>>Contact : \t";
	cin >> contact;
	cout << " \n\t ==========>>UserName : \t";
	cin >> username;

	bool c = false;
	while (c==false)
	{
		cout << "\n\t ==========>>Email ID : ";
		cin >> email;
		for (int i = 0; email[i] != '\0'; ++i)
		{
			if (email[i] == '@')
				c = true;
		}

	}
	cout << " \n\t ==========>>Enter Password : ";
	cin >> password;
	cout << " \n\t ==========>>Registration Date : ";
	cin >> registration_date;
	cout << "\n\t ==========>>Enter The Addtress: ";
	cin >> address;

	ifstream in(file);
	int n = 0;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		Id++;
	}
	in.close();
}


void Shopkeeper::Display()
{
	cout << Id << "\t " << firstname << "\t " << lastname << " \t    " << email << " \t   " << username << " \t   " << password << "\t    " << registration_date << "\t    " << gender << "\t    " << bloodgroup << "\t    " << contact << "\t    " << address << endl;
}

void Shopkeeper::readData(Shopkeeper* Data,bool check)
{
	//data for new shop keeper being added and saved into dynamic array then transfererd to file.
	ifstream in(file);
	int n = 0;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
			in >> Data[i].Id;
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


void Shopkeeper::Save()
{
	ofstream out;
	out.open(file, ios::app);
	out<< Id <<' ' << firstname << ' ' << lastname << ' ' << username
		<< ' ' << email << ' ' << password << ' ' << registration_date
		<< ' ' << gender << " " << bloodgroup << ' ' << contact
		<< ' ' << address << endl;
	out.close();
}

Shopkeeper::Shopkeeper()
{
	file = "Shopkeeper.txt";
	Id = 0000;
}



Shopkeeper::~Shopkeeper()
{

}
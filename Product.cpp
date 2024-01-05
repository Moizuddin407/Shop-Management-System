#include "Product.h"
#include"Shopkeeper.h"
Product::Product()
{
	file = "Product.txt";
	sid = -1;
}
void Product::readdata(Product* products,bool check)
{
	ifstream in("Product.txt",ios::in);

	int n = 0;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		in >> products[i].sid;
		in >> products[i].pid;
		in >> products[i].categori;
		in >> products[i].Name;
		in >> products[i].Description;
		if (products[i].categori == "Medicines")
			products[i].catagories = Catagories::Medicines;
		if (products[i].categori == "Eatables")
			products[i].catagories = Catagories::Eatables;

		if (products[i].categori == "Fashion")
		{
			products[i].catagories = Catagories::Fashion;
			in >> products[i].Color;

		}
		else if (products[i].categori == "Garments")
		{
			products[i].catagories = Catagories::Garments;
			in >> products[i].Color;
			in >> products[i].Atricalsize;
		}
		else if (products[i].categori == "Sports")
		{
			products[i].catagories = Catagories::Sports;
			in >> products[i].Color;
		}
		in >> products[i].stock;
		in >> products[i].priceofproduct;
	
	}
	if (check == true)
		products[n].add();
}

void Product::add()
{
	int n = 0;
	int c = 0;
	cout << "\n\t !!! WELCOME SHOPKEEPER TO SHOPEONLINE !!!" << endl;
	cout << "\n\t %%%% Press to add Specific Product %%%%" << endl;
	cout << "\n\t~ 1.Sports\n\t~ 2.Garments\n\t~ 3.Eatables\n\t~ 4.Medicines\n\t~ 5.Fashion\n";
	Product_input:
	void Char_String_Check();
	{

		while (!(cin >> c))
		{
			cout << "\n\t #### Input Between the Range ####\n\n\t !!! Press from 1-5 !!!\n";
			cin.clear();
			cin.ignore();
		}
	}
	if (c > 5 || c<1)
	{
		cout << "\n\t Input Number between Range !!!";
		goto Product_input;
	}
	catagories = Catagories::Sports;
	cout << "\n\t Name of Product: ";
	cin >> Name;
	cout << " \n\t Desccription of Product : ";
	cin >> Description;
	cout << "\n\t Price of Article :";
	cin >> priceofproduct;
	cout << "\n\t Quantity of Article : ";
	cin >> stock;
	switch (c)
	{
	case 1:
	{
		cout << "\n\t Color of Product : ";
		cin >> Color;
		catagories = Catagories::Sports;
		categori = "Sports";
		break;
	}
	case 2:
	{
		catagories = Catagories::Garments;
		cout << "\n\t Size of ArtiCLE : ";
		cin >> Atricalsize;
		cout << "\n\t Color of Product : ";
		cin >> Color;
		categori = "Garments";
		break;

	}
	case 3:
	{
		catagories = Catagories::Eatables;
		categori = "Eatables";

		break;
	}
	case 4:
	{
		catagories = Catagories::Medicines;
		categori = "Medicines";
		cout << "\n\t Color of Product : ";
		cin >> Color;
		break;

	}
	case 5:
	{
		catagories = Catagories::Fashion;
		categori = "Fashion";
		cout << "\n\t Color of Product : ";
		cin >> Color;
		break;

	}
	break;
	}
	if (sid == -1)
	{
		cout << "Enter The Sid of the Shopkeeper to add Product : ";
		cin >> sid;
	}
	ifstream in(file);
	 n = 0;
	in >> n;
	pid = 0;
	if (n > 0)
	{
	Product* p = new Product[n];
	p->readdata(p, 0);
	int noofproducts = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sid == p[i].sid)
			noofproducts++;
	}
	pid += noofproducts;
	}
	in.close();
}

void Product::Display()
{
	cout << "Catagories \t Sid \t Pid \t Name \t Description \t Stock \t PriceofProduct";
	if (catagories == Catagories::Eatables)
	{
		cout << endl;
		cout << categori << "\t" << sid << "\t" << pid << "\t" << Name << "\t" << Description << "\t" << stock << "\t" << "\t" << priceofproduct << "\t";
	}
	if (catagories == Catagories::Fashion)
	{
		cout << "\tColor" << endl;
		cout << categori << "\t" << sid << "\t" << pid << "\t" << Name << "\t" << Description << "\t" << stock << "\t" << Color << "\t" << priceofproduct << "\t";

	}
	else if (catagories == Catagories::Garments)
	{
		cout << "Size " << endl;
		cout << categori << "\t" << sid << "\t" << pid << "\t" << Name << "\t" << Description << "\t" << stock << "\t" << Atricalsize << "\t" << priceofproduct << "\t";

	}
	else if (catagories == Catagories::Medicines)
	{
		cout << endl;
		cout << categori << "\t" << sid << "\t" << pid << "\t" << Name << "\t" << Description << "\t\t" << stock << "\t" << priceofproduct << "\t";

	}
	else if (catagories == Catagories::Sports)
	{
		cout << "\tColor" << endl;
		cout << categori << "\t\t" << sid << "\t" << pid << "\t" << Name << "\t" << Description << "\t" << stock << "\t" << Color << "\t" << priceofproduct<<"\t";
	}
	cout << endl;
}

void Product::Save()
{
	ofstream out(file, ios::app);

	out << sid << " " <<pid<<" " << categori << " " << Name << " "<<Description<<" ";
	if (catagories == Catagories::Fashion)
	{
		out << Color << " ";

	}
	else if (catagories == Catagories::Garments)
	{
		out << Color << " ";
		out << Atricalsize << " ";
	}
	else if (catagories == Catagories::Sports)
	{
		out << Color << " ";
	}
	out << stock << " " << priceofproduct << endl;
}                                                                   
Product::~Product()
{
}

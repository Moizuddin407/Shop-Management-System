#include"Admin .h"
#include"Shopkeeper.h"
#include"Customer.h"
#include"Product.h"
Admin::Admin()
{
	file = "Admin.txt";
	shopekeeperfile = "Shopkeeper.txt";
	productfile = "Product.txt";
	customerfile = "Customer.txt";
}
void Admin::AddShopkeeper()
{
	
	ifstream in(shopekeeperfile);
	int n = 0;
	in >> n;
	n++;
	Shopkeeper* shopekeeper = new Shopkeeper[n];
	//shopekeeper object arr created to save data by calling function from shopkeeper.cpp 
	shopekeeper->readData(shopekeeper,1);

	ofstream out(shopekeeperfile,ios::trunc);
	out << n << endl;
	out.close();
	in.close();
	for (int i = 0; i < n; ++i)
	{
		shopekeeper[i].Save();
	}
}

void Admin::EditShopkeeper()
{
	ifstream in(shopekeeperfile);
	int n = 0;
	in >> n;
	in.close();

	Shopkeeper	*shopkiper = new Shopkeeper[n];
	Shopkeeper s;
	s.readData(shopkiper,0);
	cout << "Id\t" << "FirstName\t " << " LastName\t" << " Email\t   " << "Username\t " << "Password\t " << " Registration_date\t " << "Gender\t " << "Bloodgroup\t " << "Contact\t " << "Address\t" << endl;
	for (int i = 0; i < n; ++i)
	{
		shopkiper[i].Display();
	}
	int id;
	cout << "Enter The Id TO Edit : ";
	cin >> id;
	for (int i = 0; i < n; ++i)
	{
		if (id == shopkiper[i].Id)
		{
			shopkiper[i].add();
			shopkiper[i].Id = id;
			break;
		}
	}

	ofstream out(shopekeeperfile);
	out << n << endl;
	out.close();
	in.close();
	for (int i = 0; i < n; ++i)
	{
		shopkiper[i].Save();
	}
	
}

void Admin::DeleteShopkeeper()
{
	ifstream in(shopekeeperfile);
	int n = 0;
	in >> n;
	in.close();

	Shopkeeper *shopkiper = new Shopkeeper[n];

	shopkiper->readData(shopkiper,0);
	cout << "Id\t" << "FirstName\t " << " LastName\t" << " Email\t" << "Username\t\t\t " << "Password\t " << "Registration_date\t" << "Gender\t " << "Bloodgroup\t " << "Contact\t " << "Address\t" << endl;
	for (int i = 0; i < n; ++i)
	{
		shopkiper[i].Display();
	}
	int id;
	cout << "Enter The Id TO Delete : ";
	cin >> id;
	ofstream out(shopekeeperfile);
	out << n - 1 << endl;
	out.close();
	in.close();
	for (int i = 0; i < n; ++i)
	{
		if(shopkiper[i].Id!=id)
			shopkiper[i].Save();
	}

}

void Admin::AddCustomer()
{

	ifstream in(customerfile);
	int n = 0;
	in >> n;
	n++;
	Customer* customer = new Customer[n];
	//object and check sent i.e. customer & 1/true.
	customer->Readdata(customer, 1);

	ofstream out(customerfile, ios::app);
	out << n << endl;
	out.close();
	in.close();
	for (int i = 0; i < n; ++i)
	{
		customer[i].Save();
	}
}

void Admin::EditCustomer()
{

	ifstream in(customerfile);
	int n = 0;
	in >> n;
	in.close();

	Customer* customer = new Customer[n];
	customer->Readdata(customer, 0);
	cout << "Id\t" << "FirstName\t " << " LastName\t" << " Email\t   " << "Username\t " << "Password\t " << " Registration_date\t " << "Gender\t " << "Bloodgroup\t " << "Contact\t " << "Address\t" << endl;
	for (int i = 0; i < n; ++i)
	{
		customer[i].Display();
	}
	int id;
	cout << "Enter The Id TO Edit : ";
	cin >> id;
	for (int i = 0; i < n; ++i)
	{
		if (id == customer[i].id)
		{
			customer[i].add();
			customer[i].id = id;
			break;
		}
	}

	ofstream out(customerfile);
	out << n << endl;
	out.close();
	in.close();
	for (int i = 0; i < n; ++i)
	{
		customer[i].Save();
	}
}

void Admin::AddProduct()
{
	ifstream in2("Shopkeeper.txt");
	int n = 0;
	in2 >> n;
	in2.close();
	Shopkeeper* shopkeeper = new Shopkeeper[n];
	shopkeeper[0].readData(shopkeeper, 0);
	for (int i = 0; i < n; ++i)
	{
		shopkeeper[i].Display();
	}
	ifstream in(productfile);
	 n = 0;
	in >> n;
	if (n == '\0')
		n == 0;
	n++;
	Product *product = new Product[n];

	product->readdata(product,1);
	ofstream out(productfile);
	out << n << endl;
	out.close();
	in.close();
	for (int i = 0; i < n; ++i)
	{
		product[i].Save();
	}
}

void Admin::EditProduct()
{
	ifstream in(productfile);
	int n;
	in >> n;
	Product* product = new Product[n];
	product->readdata(product,0);
	for (int i = 0; i < n; ++i)
	{
		product[i].Display();
	}
	int sid;
	cout << "Enter The Sid: ";
	cin >> sid;
	
	int noofproduts = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sid == product[i].sid)
			noofproduts++;
	}
	if (noofproduts > 0)
	{
		cout << "Products Are: "<<endl;
		for (int i = 0; i < n; ++i)
		{
			if (sid == product[i].sid)
				product[i].Display();
		}
		int pid = 0;
		cout << "Enter The Pid To Edit: ";
		cin >> pid;
		for (int i = 0; i < n; ++i)
		{
			if (pid == product[i].pid)
			{
				product[i].add();
				break;
			}
		}

	}


	ofstream out(productfile);
	out << n << endl;
	out.close();
	in.close();
	for (int i = 0; i < n; ++i)
	{
		product[i].Save();
	}
}

void Admin::DeleteProduct()
{
	ifstream in(productfile);
	int n;
	in >> n;
	if (n > 0)
	{
		Product* product = new Product[n];
		product->readdata(product, 0);
		for (int i = 0; i < n; ++i)
		{
			product[i].Display();
		}
		int sid;
		cout << "Enter The Sid: ";
		cin >> sid;

		int noofproduts = 0;
		for (int i = 0; i < n; ++i)
		{
			if (sid == product[i].sid)
				noofproduts++;
		}
		int pid = 0;
		if (noofproduts > 0)
		{
			cout << "Products Are: " << endl;
			for (int i = 0; i < n; ++i)
			{
				if (sid == product[i].sid)
					product[i].Display();
			}
			cout << "Enter The Pid To Delete: ";
			cin >> pid;

		}
		ofstream out(productfile);
		out << n - 1 << endl;
		out.close();
		in.close();
		for (int i = 0; i < n; ++i)
		{
			if (product[i].pid != pid)
				product[i].Save();
		}
	}
	else
		cout << "No Data Found" << endl;
}

void Admin::DeleteCustomer()
{
	ifstream in(customerfile);
	int n;
	in >> n;
	if (n > 0)
	{
		Customer* customer = new Customer[n];
		customer->Readdata(customer, 0);
		for (int i = 0; i < n; ++i)
		{
			customer[i].Display();
		}
		int id;
		cout << "Enter The Id: ";
		cin >> id;
		ofstream out(customerfile);
		out << n - 1 << endl;
		out.close();
		in.close();
		for (int i = 0; i < n; ++i)
		{
			if (customer[i].id != id)
				customer[i].Save();
		}
	}
	else cout << "No Data Found" << endl;
}
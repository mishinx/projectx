#include <iostream>
#include <fstream>
#include"candy.h"

using namespace std;

int main()
{
	fstream iFile("Candys.txt");
	int n;
	iFile >> n;
	Candy* arr = new Candy[n];

	for (int i = 0; i < n; ++i)
	{
		iFile >> arr[i];
		arr[i].print();
	}
	
	
	cout << "----------------------------------------------\n";
	sortCandys(arr, n);

	for (int i = 0; i < n; ++i)
	{
		arr[i].print();
	}
	cout << "----------------------------------------------\n";
	double aWeight = 0;
	for (int i = 0; i < n; ++i)
	{
		aWeight += arr[i].getweight()/n;
	}
	double aPrice = 0;
	for (int i = 0; i < n; ++i)
	{
		aPrice += arr[i].getpriceperpackage() / n;
	}
	for (int i = 0; i < n; ++i)
	{
		try
		{
			if (aWeight < arr[i].getweight())
				arr[i].setprice(arr[i].getprice() - 0.15 * arr[i].getprice());
			else if (aPrice > arr[i].getpriceperpackage())
				arr[i].setweight(arr[i].getweight() + 0.2 * arr[i].getweight());
		}
		catch (const Exeptionprice& P)
		{
			cout << "Price ERROR: ";
			P.print();
		}
		catch (const Exeptionweight& W)
		{
			cout << "Weight ERROR: ";
			W.print();
		}
	}
	ofstream oFile("NewCandys.txt");
	oFile << n<<"\n";
	for (int i = 0; i < n; ++i)
	{
		oFile << arr[i] << "\n";
	}

	cout << "\n";
	iFile.close();
	system("pause");
	return 0;
}
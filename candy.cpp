#include "candy.h"
#include <iostream>
using std::cout;
using std::cin;

Candy::Candy()
	:name("no name"), priceForKg(0), weight(0.0)
{}

Candy::Candy(const std::string& candyname, double candyprice, double candyweight)
	: name(candyname), priceForKg(candyprice), weight(candyweight)
{}

Candy::Candy(const Candy& C)
	: name(C.name), priceForKg(C.priceForKg), weight(C.weight)
{}

Candy::~Candy()
{}
std::string Candy::getname()const
{
	return name;
}
double Candy::getprice()const

{
	return priceForKg;
}

double Candy::getweight()const
{
	return weight;
}

double Candy::getpriceperpackage()const
{
	return priceForKg * weight;
}

void Candy::print() const
{
	cout.setf(std::ios_base::left, std::ios_base::adjustfield);
	cout.width(10); cout << name; cout << ' ';
	cout.width(3); cout << priceForKg; cout << ' ';
	cout.width(3); cout << weight; cout << " kg. ";
	cout << "Cost of packaging: " << getpriceperpackage() << "\n";
}

void Candy::writeTo(std::ostream& out)const

{

	out << name << ' ' << priceForKg << ' ' <<weight ;

}

void Candy::readFrom(std::istream& in)

{
	in >> name >> priceForKg >> weight;
}

std::ostream& operator << (std::ostream& out, const Candy& C)
{
	C.writeTo(out);
	return out;
}

std::istream& operator >> (std::istream& in, Candy& C)
{
	C.readFrom(in);
	return in;
}

void Candy::setprice(int candyprice)
{
	if (candyprice < 30)
		throw Exeptionprice(candyprice);

	priceForKg = candyprice;
}

void Candy::setweight(double candyweight)
{
	if (candyweight > 2)
		throw Exeptionweight(candyweight);

	weight = candyweight;
}

bool Candy::operator < (const Candy& C)
{
	if (C.getprice() < C.getpriceperpackage())
	{
		return C.getpriceperpackage();
	}
}

void sortCandys(Candy* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (arr[j].getpriceperpackage() > arr[i].getpriceperpackage())
			{
				std::swap(arr[j], arr[i]);

			}
		}
	}
}


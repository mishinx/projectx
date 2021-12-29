#pragma once
#include<iostream>
#include <string>
class Candy
{
private:
	std::string name;
	double priceForKg;
	double weight;

public:
	Candy();
	Candy(const std::string& candyname, double candyprice, double candyweight);
	Candy(const Candy& C);
	~Candy();

	std::string getname()const;
	double getprice() const;
	double getweight() const;
	double getpriceperpackage()const;

	void print() const;
	void readFrom(std::istream& in);
	void writeTo(std::ostream& out)const;

	void setprice(int candyprice);
	void setweight(double candyweight);
	bool operator <(const Candy& C);
};

class Exeptionprice
{
private:
	double newPrice;

public:
	Exeptionprice(double nPrice): newPrice(nPrice){}
	void print() const { std::cout << "The price cannot be less than 30.\n"; }
};

class Exeptionweight
{
private:
	double newWeight;
public:
	Exeptionweight(double nWeight):newWeight(nWeight){}
	void print()const { std::cout << "The weight cannot be more than 2kg.\n"; }
};

std::ostream& operator << (std::ostream& out, const Candy& C);
std::istream& operator >> (std::istream& in, Candy& C);

void sortCandys(Candy* arr, int n);
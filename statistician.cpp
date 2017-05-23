#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class statistician
{
public:
	ofstream myfile;
	// CONSTRUCTOR
	statistician();
	// MODIFICATION MEMBER FUNCTIONS
	void add(double r);
	void initstat();
	// CONSTANT MEMBER FUNCTIONS
	int getlength() const;
	double getaverage() const;
	double getsmallest() const;
	double getlargest() const;
	double getsum() const;
	void Display(ofstream &myfile, statistician &j);
private:
	int count;  
	double total;   
	double tiny; 
	double large;  
	double last;
};

statistician::statistician() : count(0), total(0)
{
}

void statistician::add(double r)
{
	if (count <= 0)
	{
		count = 1;
		total = r;
		tiny = r;
		large = r;
		return;
	}
	last = r;
	count = count + 1;
	total += r;
	if (r < tiny)
	{
		tiny = r;
	}
	if (large < r)
	{
		large = r;
	}
}

void statistician::initstat()
{
	count = 0;
	total = 0;
	last = 0;
	tiny = 0;
	large = 0;
}

double statistician::getlargest() const
{
	if (getlength() > 0)
	{
		double a = large;
		double b = tiny;
		if (a>b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
	else
	{
		return 0;
	}
}

int statistician::getlength() const
{
	return count;
}

double statistician::getaverage() const
{
	if (getlength() > 0)
	{
		return total / count;
	}
	else
	{
		return 0;
	}
}

double statistician::getsmallest() const
{
	if (getlength() > 0)
	{
		return tiny;
	}
	else
	{
		return 0;
	}
}

double statistician::getsum() const
{
	return total;
}

void statistician::Display(ofstream &myfile, statistician &j)
{
	myfile << endl;
	myfile << "Length is: " << j.getlength() << endl;
	myfile << "Sum is: " << j.getsum() << endl;
	myfile << "Average is: " << j.getaverage() << endl;
	myfile << "Smallest Value is: " << j.getsmallest() << endl;
	myfile << "Largest Value is: " << j.getlargest() << endl;
	myfile << endl;
}

int main()
{
	statistician a,b;
	ofstream myfile;
	myfile.open("Ikerman-CS372-Statistician-Output.txt");
	myfile << "Statistician1:" << endl;
	a.add(5.5);
	a.add(6.6);
	a.add(8.8);
	a.add(-3.4);
	a.add(-0.5);
	a.add(4.7);
	a.add(9.1);
	a.Display(myfile, a);
	myfile << "Added 5.2, -3.3, -8.5, 3.2, and 5.5:" << endl;
	a.add(5.2);
	a.add(-3.3);
	a.add(-8.5);
	a.add(3.2);
	a.add(5.5);
	a.Display(myfile, a);
	myfile << "Statistician2:" << endl;
	b.Display(myfile, b);
	b.add(103);
	b.add(821);
	b.add(871);
	b.add(487);
	b.add(312);
	b.add(245);
	b.add(224);
	b.add(623);
	b.add(424);
	b.add(432);
	myfile << "Added Values to Statistician2: " << endl;
	b.Display(myfile, b);


	myfile.close();

	return 0;
}
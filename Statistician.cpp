#include "stdafx.h"
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
	void next(double r);
	void reset();
	// CONSTANT MEMBER FUNCTIONS
	int length() const;
	double sum() const;
	double mean() const;
	double minimum() const;
	double maximum() const;
	double lastentered() const;
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

void statistician::next(double r)
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

void statistician::reset()
{
	count = 0;
	total = 0;
	last = 0;
	tiny = 0;
	large = 0;
}

double statistician::maximum() const
{
	if (length() > 0)
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

int statistician::length() const
{
	return count;
}

double statistician::mean() const
{
	if (length() > 0)
	{
		return total / count;
	}
	else
	{
		return 0;
	}
}

double statistician::minimum() const
{
	if (length() > 0)
	{
		return tiny;
	}
	else
	{
		return 0;
	}
}

double statistician::sum() const
{
	return total;
}

double statistician::lastentered() const
{
	if (length() > 0)
	{
		return last;
	}
	else 
	{
		return 0;
	}
}

void statistician::Display(ofstream &myfile, statistician &j)
{
	myfile << endl;
	myfile << "Minimum is: " << j.minimum() << endl;
	myfile << "Maximum is: " << j.maximum() << endl;
	myfile << "Length is: " << j.length() << endl;
	myfile << "Sum is: " << j.sum() << endl;
	myfile << "Mean is: " << j.mean() << endl;
	myfile << "Last number entered: " << j.lastentered() << endl;
	myfile << "Resetting..." << endl;
	j.reset();
	myfile << "Minimum is: " << j.minimum() << endl;
	myfile << "Maximum is: " << j.maximum() << endl;
	myfile << "Length is: " << j.length() << endl;
	myfile << "Sum is: " << j.sum() << endl;
	myfile << "Mean is: " << j.mean() << endl;
	myfile << "Last number entered: " << j.lastentered() << endl;
	myfile << endl;
}

int main()
{
	statistician a,b;
	ofstream myfile;
	myfile.open("Ikerman-CS372-Statistician-Output.txt");
	myfile << "Book Examples" << endl;
	//Book Examples
	a.next(1.1);
	a.next(-2.4);
	a.next(0.8);
	a.Display(myfile, a);
	myfile << "Experimental Examples" << endl;
	//Testing Example
	b.next(12.21);
	b.next(13.52);
	b.next(-5.89);
	b.Display(myfile, b);

	myfile.close();

	return 0;
}

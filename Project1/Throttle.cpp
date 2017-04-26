#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class throttle
{
public:
	ofstream myfile;
	//CONSTRUCTORS
	throttle() : top_position(6), position(0) {}
	throttle(double a) : top_position(a), position(0) {}
	throttle(double a, double b) : top_position(a), position(b) {}
	// MODIFICATION MEMBER FUNCTIONS
	void shut_off() { position = 0; }
	void shift(int amount);
	void Display(ofstream &myfile);
	// CONSTANT MEMBER FUNCTIONS
	double flow() const { return position / double(top_position); }
	bool is_on() const { return (position > 0); }
private:
	double position;
	double top_position;
};

void throttle::Display(ofstream &myfile)
{
	myfile << "Top Position " << top_position << " and Current Position " << position << endl;
}
void throttle::shift(int amount)
{
	position += amount;

	if (position < 0)
		position = 0;
	else if (position > top_position)
		position = top_position;
}

int main()
{
	throttle a, b(30), c(20, 6);
	ofstream myfile;
	myfile.open("Ikerman-CS372-ThrottleClass-output.txt");

	//Input for the "Car" Vehicle Throttle
	myfile << "Car: ";
	a.Display(myfile);

	//Input for the "Truck" Vehicle Throttle
	myfile << "Truck: ";
	b.Display(myfile);

	//Input for the "Shuttle" Vehicle Throttle
	myfile << "Shuttle: ";
	c.Display(myfile);
	myfile << endl;

	//Begin Testing other methods
	myfile << "Testing Shut-Off on Shuttle: ";
	c.shut_off();
	c.Display(myfile);
	//Testing Shift
	myfile << "Testing Shift(3) on Car: ";
	a.shift(3);
	a.Display(myfile);
	myfile << "Testing Shift(2) on Car: ";
	a.shift(2);
	a.Display(myfile);
	myfile << endl;
	//Testing is_on
	myfile << "Is Shuttle Running? " << c.is_on() << endl;
	myfile << "Is Car Running? " << a.is_on() << endl;
	myfile << "Car is running!? Let's try to turn it off: ";
	a.shut_off();
	myfile << a.is_on() << endl;
	myfile << "Is Truck Running? " << b.is_on() << endl;
	myfile << endl;
	//Testing flow
	myfile << "Flow on Car: " << a.flow() << endl;
	a.shift(4);
	myfile << "Car shifted to 4th gear" << endl;
	myfile << "New Flow on Car: " << a.flow() << endl;
	b.shift(6);
	myfile << "Truck in 6th gear" << endl;
	myfile << "New Flow on Truck: " << b.flow() << endl;

	myfile.close();

	return 0;
}

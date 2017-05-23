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

	myfile << "Car Status: ";
	a.Display(myfile);
	myfile << "Truck Status: ";
	b.Display(myfile);
	myfile << "Shuttle Status: ";
	c.Display(myfile);
	myfile << endl;

	a.shut_off();
	myfile << "Testing 'Shut-Off' Method on Car: ";
	a.Display(myfile);

	b.shut_off();
	myfile << "Testing 'Shut-Off' Method on Truck: ";
	b.Display(myfile);

	c.shut_off();
	myfile << "Testing 'Shut-Off' Method on Shuttle: ";
	c.Display(myfile);
	myfile << endl;

	myfile << "Testing Shift(3) on Car: ";
	a.shift(3);
	a.Display(myfile);

	myfile << "Testing Shift(-2) on Car: ";
	a.shift(-2);
	a.Display(myfile);

	myfile << "Testing Shift(-40) on Car: ";
	a.shift(-40);
	a.Display(myfile);

	myfile << "Testing Shift(1000) on Truck: ";
	b.shift(1000);
	b.Display(myfile);

	myfile << "Testing Shift(-90) on Shuttle: ";
	c.shift(-90);
	c.Display(myfile);
	
	myfile << endl;

	myfile.close();

	return 0;
}
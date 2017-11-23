#include<iostream>
#include<iomanip>
#include"Rectangle2D.h"
using namespace std;

int main()
{
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);

	cout << boolalpha;

	// Test area and perimeter getters
	cout << "r1's area is " << r1.getArea() << ", and it's perimeter is " << r1.getPerimeter() << "." << endl;

	// Test point-contained function
	cout << "'r1 contains the point (3, 3).' This statement is " << r1.contains(3, 3) << "." << endl;

	// Test rectangle-contained function
	cout << "'r1 contains r2.' This statement is " << r1.contains(r2) << "." << endl;

	// Test overlap function
	cout << "'r1 and r3 overlap.' This statement is " << r1.overlaps(r3) << "." << endl;

	return 0;
}
// ClassProject 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

double a1, b1, a2, b2;

double distance1, radius, circumference, area;

double getDistance(double x2, double x1, double y2, double y1);
double findRadius(double x2, double x1, double y2, double y1);
double findCircumference(double r);
double findArea(double r);

int main()
{
	cout << "Please enter the co-ordinates of a center point and any given point on the circle"
		<< endl << "This program will analyze and output information about that circle" << endl << endl
		<< "What are the x & y coordinates (seperated by a single space) of the center point?" << endl;
	cin >> a1 >> b1;
	cout << "What are the x & y coordinates (seperated by a single space) of a point on the circle?" << endl;
	cin >> a2 >> b2;

	radius = findRadius(a1, a2, b1, b2);
	circumference = findCircumference(radius);
	area = findArea(radius);

	cout << endl << "The radius of the circle is " << radius << endl
		<< "The circumferernce of the circle is " << circumference << endl
		<< "and the area of the circle is " << area << endl << endl;

	system("pause");
	return 0;
}

double getDistance(double x1, double x2, double y1, double y2) {
	double d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return d;
}

double findRadius(double x1, double x2, double y1, double y2) {
	double r = getDistance(x1, x2, y1, y2);
	return r;
}

double findCircumference(double r) {
	double c = (2 * 3.1415927 * r);
	return c;
}

double findArea(double r) {
	double a = ((3.1415927 * r) * (3.1415927 * r));
	return a;
}
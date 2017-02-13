/** \file
Contains declaration of common utility fucntions.
*/

#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <fstream>
#include <vector>
#include <cmath>
#include "Point.h"

static const double PI = 3.1415926535;

namespace cg{
	
	/**
	* Function to read a set of points from file and store it in a vector.
	* <b> Input: </b> File name and set of points. <br>
	* <b> Output: </b> Parses the file "file_name" and writes the point to the vector vect
	*/
	void readPointSet(char *, std::vector<Point> & );
	
	/**
	* Function to write a set of points from a vector to an output file.
	* <b> Input: </b> File name and set of points.<br>
	* <b> Output: </b> Writes the vector "vect" to the file "file_name"	
	*/
	void writePointSet(char *, const std::vector<Point> & );
	
	/**
	* Function to find the turning direction of a	set of three points in the sequence p,q,r.
	* <b> Input: </b> Three points p,q,r. <br>
	* <b> Output: </b> 1 for Left Turn, 0 if the points are Collinear, -1 for Right Turn.
	*/
	int turn_direction(const Point&, const Point&, const Point&);
	
	/**
	* Function to find the euclidean distance between two points in Cartesian coordinate system.
	* <b> Input: </b> 2 points a and b.<br>
	* <b> Output: </b> Euclidean distance between a and b.
	*/
	double euclideanDistance(const Point&,const Point&);
	
	/**
	* Function to find the polar angle of two points in cartesian coordinate system.
	* <b> Input: </b> 2 points a and b. <br>
	* <b> Output: </b> polar angle between a and b in cartesian coordinate system.
	*/
	double polarAngle(const Point&,const Point&);
	
	/**
	* Function to check where a stands with respect to b.
	* <b> Input: </b> 2 points a and b.<br>
	* <b> Output: </b> <ol> <li>True when Point a lies below Point b or Both lie on same horizontal axis but a lies to the left.</li>
	* <li>False otherwise.</li></ol>
	*/
	bool bottomOrLeft(const Point &,const Point &);
	
	/**
	* Compare two polar points by their theta
	* <b> Input: </b> 2 Polar Points a and b. <br>
	* <b> Output: </b> <ol><li> True if a's angle is less than b's theta or both are equal but a's radius is less than b's radius</li>
	* <li> False otherwise</li></ol>
	*/
	bool compareTheta(const PolarPoint &, const PolarPoint &);
	
	/**
	* Lambda function used for the sort function in andrews algorithm.
	* <b> Input: </b> Two points a and b belonging to set of points S. <br>
	* <b> Output: </b><ol><li>True if a's x-coordinate is larger than b or if both are same and a's y-coordinate is larger.</li>
	* <li>False otherwise.</li>
	*/
	bool compareXY(const Point& a, const Point& b);

}

#endif

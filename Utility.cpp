/** \file
Contains the function definitions of common utility functions.
*/

#include "Utility.h"
#include<iomanip>
namespace cg{
	/**
	Function to read a set of points from file and
	store it in a vector.
	*/
	void readPointSet(char *file_name, std::vector<Point> & vect){
		std::ifstream file(file_name);
		if(!file.is_open()){
			std::cerr << "Input File \"" << file_name << "\" not found !!\n";
			exit(1);
		}
		cg::Point p;
		while((file >> p)){
			vect.push_back(p);
		}
	}
	
	/**
	Function to write a set of points
	from a vector to an output file.
	*/
	void writePointSet(char *file_name, const std::vector<Point> & vect){
		std::ofstream file(file_name);
		if(!file.is_open()){
			std::cerr << "Output File not found\n";
			exit(1);
		}
		file << std::setprecision(15);
		for(auto it=vect.begin();it!=vect.end();it++){
			file << it->x << " " << it->y << "\n";
		}
	}

	/**
	Function to find the turning direction of a	set of three points in the sequence p,q,r.
	It returns 1 for LEFT turn, 0 for COLLINEARITY and, -1 for RIGHT turn
	*/
	int turn_direction(const Point& p, const Point& q, const Point& r){
		// determinant value
		double det = (1*(q.x*r.y - q.y*r.x) - p.x*(1*r.y - q.y*1) + p.y*(1*r.x - q.x*1));
		if (det == 0.0){
			return 0;
		}
		else if (det > 0.0){
			return 1;
		}
		else return -1;
	}
	
	/**
	Function to find the euclidean distance between
	two points in Cartesian coordinate system.
	*/
	double euclideanDistance(const Point &a,const Point &b){
		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
	}
	
	/**
	Function to find the polar angle of two points
	in cartesian coordinate system.
	*/
	double polarAngle(const Point &a,const Point &b){
		return fmod((atan2(double(a.y-b.y),double(a.x-b.x)) + 2*PI),2*PI)* 180/PI;
	}
	
	/**
	Check if either
	1. Point a lies below Point b, or
	2. Both lie on same horizontal axis but a lies to the left.
	*/
	bool bottomOrLeft(const  cg::Point &a,const cg::Point &b){
		return ((a.y < b.y) or (a.y == b.y and a.x < b.x));
	}
	
	/**
	Compare two polar points by their theta
	*/
	
	bool compareTheta(const PolarPoint &a,const PolarPoint &b){
		bool condition1 = (a.theta < b.theta);
		bool condition2 = (a.theta == b.theta);
		bool condition3 = (a.r < b.r);
		return (condition1 or (condition2 and condition3));
	}
}
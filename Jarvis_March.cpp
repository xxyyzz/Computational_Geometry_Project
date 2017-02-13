/** \file
Contains the main function to run Jarvis March Algorithm. 
This program file reads a set of points in the cartesian space from the first command line arguement,
computes the Convex Hull using Jarvis March Algorithm and writes the output to file specified in the second command line arguement. <br>
To run, execute the following command in the directory containing the source code using the terminal:-
\code
$ make jarvis.o input_file.txt output_file.txt
\endcode

<b>Note:</b> It creates a new file if <b><em> output_file.txt </em></b> does not exist, or overwrites the existing file.

*/

#include <vector>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

#include "Point.h"
#include "Utility.h"
#include "ConvexHull.h"

int main(int argc,char *argv[]){

	std::cout << std::setprecision(15);
	
	// Read from file
	std::vector<cg::Point> p;
	cg::readPointSet(argv[1],p);
	std::cout << "Read file successfully.\n";
	
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	
	std::vector<cg::Point> ch = cg::convexHullJarvisMarch(p);
	
	std::cout<<"Completed convex hull using Jarvis March.\n";
	std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
	std::cout << "Time taken to compute Convex Hull is = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()<<"ms" <<std::endl;
	
	// write to file
	cg::writePointSet(argv[2],ch);
	std::cout << "File written successfully.\n";
}

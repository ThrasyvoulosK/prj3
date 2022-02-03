//preprocessing.h

//datatypes for curves and vectors
#ifndef PREPROC_H
#define PREPROC_H
#include "../include/libraries.h"
using namespace std;


typedef struct _vecter_{
	std::string id;//its name
	std::vector<double> coordinate; // its coordinates stored in an array
}vecter;


typedef struct _curve_
{
	string id;
	int number_of_points;
	//coordinates [number_of_points][x , y]
	vector<vector <double> > coordinates;
		
}curve;

//decide whether to deal with curves or vectors, or return an error otherwise
std::string curves_or_vectors(std::string input_file);

//some code for printing the contents of lists of vectors
void print_vector_list(std::list<vecter> vector_list);

//assign vectors to vector lists
list<vecter> assign_vectors(string input_file, list<vecter> vector_list);

#endif
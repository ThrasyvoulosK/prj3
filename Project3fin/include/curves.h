//curves.h
#ifndef CURVES_H
#define CURVES_H
#include "../include/libraries.h"
#include "../include/preprocessing.h"

using namespace std;

//a function to assign curves from an input file to a list
list<curve> assign_curves(string input_file, list<curve> curves_list);


//a function to print curves
void print_curves(list< curve > curves_list);
#endif
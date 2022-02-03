#ifndef METRICS_H
#define METRICS_H
#include "../include/libraries.h"
#include "../include/preprocessing.h"
using namespace std;
double euclidean(std::vector<double> x, std::vector<double> y) ; 

double dtw(vector<vector<double>> c,vector<vector<double>> p );
double manhattan_distance(vector < double > c,vector < double > p);

int nearest_neighbor_vec(list<vecter> input_vectors_list,list<vecter> query_vectors_list);
#endif

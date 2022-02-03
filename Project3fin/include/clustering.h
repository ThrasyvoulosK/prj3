//clustering.h
//struct clustering for vectors

#ifndef CLUST_H
#define CLUST_H
#include "../include/libraries.h"
using namespace std;

typedef struct _clustering_
{
	string id;
	vector<double> coordinate;
	string center_id;
	double distance_from_cent;
	
}clustering;
//struct clustering for curves
typedef struct _clustering_c_
{
	string id;
	vector<vector<double>> coordinates;
	string center_id;
	double distance_from_cent;
	
}clustering_c;
#endif
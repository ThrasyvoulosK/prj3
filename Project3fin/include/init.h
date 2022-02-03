#ifndef INIT_H
#define INIT_H
#include "../include/libraries.h"
#include <list>
#include "../include/preprocessing.h"

//init 1
//select k members from the dataset and set them up as clustering centers
list<vecter> init_first(int K,list< vecter > dat);
list< curve > init_firstc(int K,list< curve > dat);

//init 2 (k-means++)
//select k random centroids(not parts of the dataset) as centers
//// make a loop where we initialise each center randomly

//list< vecter >
void init_second(int K,list< vecter > dat);

list< vecter > init_second_neo(int K,list< vecter > dat);

list< curve > init_second_c(int K,list< curve > dat);
#endif
#ifndef UPDATE_H
#define UPDATE_H
#include "../include/libraries.h"
#include "../include/clustering.h"
#include "../include/preprocessing.h"

list<clustering> update_first_v(list<vecter> centers,list<clustering> assigned,list<vecter> dat);
list<clustering_c> update_first_c(list<curve> centers,list<clustering_c> assigned,list<curve> dat);
list<clustering> update_second_v(list<vecter> centers,list<clustering> assigned,list<vecter> dat);
#endif
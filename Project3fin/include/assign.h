#ifndef ASSIGN_H
#define ASSIGN_H
#include "../include/libraries.h"
#include "../include/clustering.h"
#include "../include/preprocessing.h"
list<clustering> assign_first_v(list<vecter> dat,list<vecter> centers);
list<clustering_c> assign_first_c(list<curve> dat,list<curve> centers);
void print_assign_v(list<clustering> clusters_list);
void print_assign_c(list<clustering_c> clusters_list);


#endif
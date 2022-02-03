#ifndef LSH_H
#define LSH_H
#include "../include/libraries.h"
//#include "../include/clustering.h"
#include "../include/preprocessing.h"
typedef struct _grid_{
    //cell_distance is the minimum DTW distance
    double initial_x,end_x,initial_y,end_y,cell_dist;
}grid;
list<grid> create_grid(int L,list<curve> centers);
list <curve> grid_as_curve(grid grids);
list<curve> grid_recurs(list<curve> gr,list<grid> grids);
//list<list <curve> > snapped_curves(list <curve> data_curves,list<grid> grids,int L);
list<list <curve> > snapped_curves(list <curve> data_curves,list<curve> curve_grids);
#endif
//assign.cpp

#include "../include/assign.h"
#include "../include/metrics.h"

//Lloyd's Assignment
using namespace std;

list<clustering> assign_first_v(list<vecter> dat,list<vecter> centers)
{
	vector<double> temp1,temp2;
	list<vecter>::iterator it,vl;
	list<clustering> cl_temp;
	list<clustering>::iterator ci;
	clustering clus;
	double distance,max_d=1000000000;

	for(vl=centers.begin();vl!=centers.end();vl++)
	{
		//assign everything to the first center initially
		if(vl==centers.begin())
		{
			for (it = dat.begin(); it!=dat.end();++it)
        	{
            	if(it==dat.begin())
               	 it++;

               	clus.id=it->id;
               	clus.coordinate=it->coordinate;
               	clus.center_id=vl->id;
               	clus.distance_from_cent=manhattan_distance(vl->coordinate,it->coordinate);

               	cl_temp.push_back(clus);

       	 	}

		}
		//check for a better center and replace if necessary
		ci=cl_temp.begin();
        for (it = dat.begin(); it!=dat.end();++it)
        {
            if(it==dat.begin())
                it++;
            temp1=vl->coordinate;
            temp2=it->coordinate;
            distance = manhattan_distance(temp1,temp2);


            if(distance<ci->distance_from_cent)
            {
            	ci->center_id=vl->id;
               	ci->distance_from_cent=distance;
            }

            ci++;
        }
    }

    return cl_temp;

}

list<clustering_c> assign_first_c(list<curve> dat,list<curve> centers)
{
	vector<vector<double>> temp1,temp2;
	list<curve>::iterator it,vl;
	list<clustering_c> cl_temp;
	list<clustering_c>::iterator ci;
	clustering_c clus;
	double distance,max_d=1000000000;

	for(vl=centers.begin();vl!=centers.end();vl++)
	{
		//assign everything to the first center initially
		if(vl==centers.begin())
		{
			for (it = dat.begin(); it!=dat.end();++it)
        	{
            	if(it==dat.begin())
               	 it++;

               	clus.id=it->id;
               	clus.coordinates=it->coordinates;
               	clus.center_id=vl->id;
               	clus.distance_from_cent=dtw(vl->coordinates,it->coordinates);

               	cl_temp.push_back(clus);

       	 	}

		}
		//check for a better center and replace if necessary
		ci=cl_temp.begin();
        for (it = dat.begin(); it!=dat.end();++it)
        {
            if(it==dat.begin())
                it++;
            temp1=vl->coordinates;
            temp2=it->coordinates;
            distance = dtw(temp1,temp2);

            
            if(ci->id==it->id)
            	cout<<"yes it is"<<endl;
            else
            	cout<<"no it is not"<<endl;
			

            if(distance<ci->distance_from_cent)
            {
            	ci->center_id=vl->id;
               	ci->distance_from_cent=distance;
            }

            ci++;
        }
    }

    return cl_temp;

}
//Assignment by Range Search (LSH)
/*
list<clustering_c> assign_second_v(list<curve> dat,list<curve> centers)
{
	
}
*/

//print contents of assignments for vectors
void print_assign_v(list<clustering> clusters_list)
{
	list<clustering>::iterator ci;
	for(ci=clusters_list.begin();ci!=clusters_list.end();ci++)
	{
		cout<<"id "<<ci->id<<" ci->coordinate (NULL)"<<"  center_id "<< ci->center_id<<" center_dist "<<ci->distance_from_cent<<endl;
	}
}

//print contents of assignments for curves
void print_assign_c(list<clustering_c> clusters_list)
{
	list<clustering_c>::iterator ci;
	for(ci=clusters_list.begin();ci!=clusters_list.end();ci++)
	{
		cout<<"id "<<ci->id<<" ci->coordinates (NULL)"<<"  center_id "<< ci->center_id<<" center_dist "<<ci->distance_from_cent<<endl;
	}
}
#include "../include/silhouette.h"
#include "../include/metrics.h"

using namespace std;
//kaloume tin proti assign gia to kalutero kentro
//kanoume paromoia pragmata gia to deftero kalutero 
//vriskoume to klasma

list<clustering> centers_for_silhoutte_v(list<vecter> dat,list<vecter> centers)
{
	vector<double> temp1,temp2;
	list<vecter>::iterator it,vl;
	list<clustering> cl_temp;
	list<clustering>::iterator ci;
	clustering clus;
	double distance,max_d=1000000000;
    string our_center;

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
                our_center=ci->center_id;
            }
           // cout<<"SECOND"<<endl;
            //find the second best center
                if(ci->center_id!=our_center){
                    cout<<"true??"<<endl;
                    if(it->id!=vl->id){
                        cout<<"heyy"<<endl;
                         distance = manhattan_distance(vl->coordinate,it->coordinate);
                         cout<<"distance: "<< ci->distance_from_cent<<"and"<<distance<<endl;

                        if(distance>ci->distance_from_cent && distance!=0){
                            //if(//mikrotero apo ta xeirotera){
                              cout<<"changed??"<<endl;
                             ci->center_id=vl->id;
               	             ci->distance_from_cent=distance;
                            //}
                        }
                    }
                }

            ci++;
        }
    }
    cout<<centers.size()<<endl;
    return cl_temp;

}
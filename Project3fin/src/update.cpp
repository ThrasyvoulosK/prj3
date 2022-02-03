
#include "../include/update.h"
#include "../include/metrics.h"

#include "../include/assign.h"

using namespace std;

list<clustering> update_first_v(list<vecter> centers,list<clustering> assigned,list<vecter> dat)
{
//in each step, compute the distances of the points within the cluster, and choose a new center based on them (the sum)
    list<clustering> update;
    list<clustering>::iterator as,as2;
    list<vecter>::iterator itc,itc2;
    double distance_sum,dist_temp;
    list<vecter> new_centers,old_centers,tmp_centers;
    vecter newc;
    int centr_num=0;
    cout<<"upd begins"<<endl;
    old_centers=centers;
    new_centers=centers;
    list<clustering> new_assign;
    cout<<"our centers are: "<< centers.size()<<endl;
    int whiles=0;
    ////////////do, while our centers change, repeat
    do{

    for(itc=new_centers.begin();itc!=new_centers.end();itc++)
    {   
        centr_num++;
        cout<<"number of centre"<<centr_num<<endl;
        distance_sum=0;
     //       cout<<"upd begins loop"<<endl;
        newc.id=itc->id;
        newc.coordinate=itc->coordinate;

        for(as=assigned.begin();as!=assigned.end();as++)
        {
            if(itc->id==as->center_id)
            {
                distance_sum+=manhattan_distance(itc->coordinate,as->coordinate);
                cout<<"manh dist in if: "<<distance_sum<<endl;
            }
        } 

   //         cout<<"upd first loop ends"<<endl;
    //    cout <<"size of assign"<<assigned.size()<<endl;

        int count=0;
        for(as=assigned.begin();as!=assigned.end();as++)
        {
            
            count++;
            if(itc->id==as->center_id)
            {
                dist_temp=0;
                for(as2=assigned.begin();as2!=assigned.end();as2++)
                {
                    
                    if(as2->center_id==itc->id){
                       dist_temp+=manhattan_distance(as->coordinate,as2->coordinate);
                    }
                }
                 cout<<"temp dist in if: "<<dist_temp<<" distance sum: "<<distance_sum<<endl;

               // cout<<"upd the nested loop just terminated"<<endl;

                if(dist_temp<distance_sum){
                    distance_sum=dist_temp;
                    //cout<<"ifs distance sum: "<<distance_sum<<endl;
                    newc.id=as->id;
                    newc.coordinate=as->coordinate;
                    //new_centers.erase(itc);
                    //new_centers.push_back(newc);
                //    tmp_centers.push_back(newc);
                //    cout<<"FIRST IF"<<endl;

                }
                /*
                else //if our center is already the best
                {
                    newc.id=itc->id;
                    newc.coordinate=itc->coordinate;
                    //new_centers.push_back(newc);
                //    tmp_centers.push_back(newc);
                //     cout<<"SECOND IF"<<endl;
                   
                }
                */
                
            }
      //  cout<<"our count: "<<count<<endl;
        }
   //    cout<<"TERMINATED"<<endl;
    tmp_centers.push_back(newc);
    
    }
    cout<<"size of temp centers list: "<<tmp_centers.size()<<endl;
    old_centers=new_centers;
    new_centers=tmp_centers;
    tmp_centers.clear();
   
  
   //check both lists to see if the centers have exactly the same id, equaltimes to the size of the lists, with a counter
   unsigned int sim=0;
   itc2=old_centers.begin();
   for(itc=new_centers.begin();itc!=new_centers.end();itc++)
   {
       if(itc->id==itc2->id)
       {
           sim++;
       }
       cout<<"compare centers: "<<itc->id<<" "<<itc2->id<<endl;
       itc2++;
   }
   cout<<"size of old list: "<<old_centers.size()<<" size of new list: "<<new_centers.size()<<endl;
    whiles++;
    cout<<"while ends and restarts here "<<whiles<<endl;

   if(sim==new_centers.size()){
       break;
   }
   cout<<"sim is: "<<sim<<endl;
    //if old centers are the same as the new, break
    //else, reinitialise new_centers
    //old_centers=new_centers;
    //new_centers=NULL

    //reassign our dataset points based on our new centers
    new_assign=assign_first_v( dat,new_centers);
   assigned=new_assign;
    }while(1);
    


    return new_assign;


}

list<clustering_c> update_first_c(list<curve> centers,list<clustering_c> assigned,list<curve> dat)//a is the chosen assign method
{
//in each step, compute the distances of the points within the cluster, and choose a new center based on them (the sum)
    list<clustering_c> update;
    list<clustering_c>::iterator as,as2;
    list<curve>::iterator itc,itc2;
    double distance_sum,dist_temp;
    list<curve> new_centers,old_centers,tmp_centers;
    curve newc;
    int centr_num=0;
    cout<<"upd begins"<<endl;
    old_centers=centers;
    new_centers=centers;
    list<clustering_c> new_assign;
    cout<<"our centers are: "<< centers.size()<<endl;
    int whiles=0;
    ////////////do, while our centers change, repeat
    do{

    for(itc=new_centers.begin();itc!=new_centers.end();itc++)
    {   
        centr_num++;
        cout<<"number of centre"<<centr_num<<endl;
        distance_sum=0;
     //       cout<<"upd begins loop"<<endl;
        newc.id=itc->id;
        newc.coordinates=itc->coordinates;

        for(as=assigned.begin();as!=assigned.end();as++)
        {
            if(itc->id==as->center_id)
            {
                distance_sum+=dtw(itc->coordinates,as->coordinates);
                cout<<"dtw dist in if: "<<distance_sum<<endl;
            }
        } 

   //         cout<<"upd first loop ends"<<endl;
    //    cout <<"size of assign"<<assigned.size()<<endl;

        int count=0;
        for(as=assigned.begin();as!=assigned.end();as++)
        {
            
            count++;
            if(itc->id==as->center_id)
            {
                dist_temp=0;
                for(as2=assigned.begin();as2!=assigned.end();as2++)
                {
                    
                    if(as2->center_id==itc->id){
                       dist_temp+=dtw(as->coordinates,as2->coordinates);
                    }
                }
                 cout<<"temp dist in if: "<<dist_temp<<" distance sum: "<<distance_sum<<endl;

               // cout<<"upd the nested loop just terminated"<<endl;

                if(dist_temp<distance_sum){
                    distance_sum=dist_temp;
                    //cout<<"ifs distance sum: "<<distance_sum<<endl;
                    newc.id=as->id;
                    newc.coordinates=as->coordinates;
                    //new_centers.erase(itc);
                    //new_centers.push_back(newc);
                //    tmp_centers.push_back(newc);
                //    cout<<"FIRST IF"<<endl;

                }
                /*
                else //if our center is already the best
                {
                    newc.id=itc->id;
                    newc.coordinates=itc->coordinates;
                    //new_centers.push_back(newc);
                //    tmp_centers.push_back(newc);
                //     cout<<"SECOND IF"<<endl;
                   
                }
                */
                
            }
      //  cout<<"our count: "<<count<<endl;
        }
   //    cout<<"TERMINATED"<<endl;
    tmp_centers.push_back(newc);
    
    }
    cout<<"size of temp centers list: "<<tmp_centers.size()<<endl;
    old_centers=new_centers;
    new_centers=tmp_centers;
    tmp_centers.clear();
   
  
   //check both lists to see if the centers have exactly the same id, equaltimes to the size of the lists, with a counter
   unsigned int sim=0;
   itc2=old_centers.begin();
   for(itc=new_centers.begin();itc!=new_centers.end();itc++)
   {
       if(itc->id==itc2->id)
       {
           sim++;
       }
       cout<<"compare centers: "<<itc->id<<" "<<itc2->id<<endl;
       itc2++;
   }
   cout<<"size of old list: "<<old_centers.size()<<" size of new list: "<<new_centers.size()<<endl;
    whiles++;
    cout<<"while ends and restarts here "<<whiles<<endl;

   if(sim==new_centers.size()){
       break;
   }
   cout<<"sim is: "<<sim<<endl;
    //if old centers are the same as the new, break
    //else, reinitialise new_centers
    //old_centers=new_centers;
    //new_centers=NULL

    //reassign our dataset points based on our new centers
    new_assign=assign_first_c(dat,new_centers);
   assigned=new_assign;
    }while(1);
    return new_assign;
}


list<clustering> update_second_v(list<vecter> centers,list<clustering> assigned,list<vecter> dat){
    //list<vecter>::iterator itc;
    list<clustering>::iterator ita;

    //search our assigned vectors for vectors in the same cluster
    //for each of their coordinates, compute their mean
    //when we have traversed all of their coordinates, we should have a "mean" vector
    //set this vector as the center of its cluster
    //do the above for the rest of the clusters
    //compute the assigned
    //repeat


//in each step, compute the distances of the points within the cluster, and choose a new center based on them (the sum)
    list<clustering> update;
    list<clustering>::iterator as,as2;
    list<vecter>::iterator itc,itc2;
    double distance_sum,dist_temp,coord_sum;
    list<vecter> new_centers,old_centers,tmp_centers;
    vecter newc;
    int centr_num=0;
    cout<<"upd begins"<<endl;
    old_centers=centers;
    new_centers=centers;
    list<clustering> new_assign;
    int num_of_vectors=dat.size();
    int coord_counter;
    double coord_mean;
    cout<<"our centers are: "<< centers.size()<<endl;
    int whiles=0;
    vector<double> mean_vec;
    ////////////do, while our centers change, repeat

    do{
    for(itc=new_centers.begin();itc!=new_centers.end();itc++)
    {
      centr_num++;
      cout<<"number of centre"<<centr_num<<endl;
      //distance_sum=0;
      coord_sum=0;

     //       cout<<"upd begins loop"<<endl;
      
      coord_counter=0;

      //initialise mean vec to zero
      for(unsigned int i=0;i<(itc->coordinate).size();i++)
        mean_vec.push_back(0);
      //cout<< mean_vec.size()==(itc->coordinate).size() << mean_vec.size() <<endl;

      int vec_in_clus=0;
      //for for new dimension goes here
      for(as=assigned.begin();as!=assigned.end();as++)
      {
        if(itc->id==as->center_id)
        {
          vec_in_clus++;
          //we assign it a sum
          for(unsigned int i=0;i<(as->coordinate).size();i++)
            mean_vec[i]+=(as->coordinate)[i];

        }
      }
      for(unsigned int i=0;i<(itc->coordinate).size();i++){
        mean_vec[i]=mean_vec[i]/vec_in_clus;
        cout<<"mean vec in upd2: "<<mean_vec[i]<<endl;
        cout<<"I: "<<i<<" coordinatesize: "<< (itc->coordinate).size() <<" meanvecsize: "<< mean_vec.size() <<endl;
      }

      //assign new center
      //repeat for the next
      /*tmp_centers.push_back(newc);
    old_centers=new_centers;
    new_centers=tmp_centers;
    tmp_centers.clear();*/
      newc.id="new_vec"+to_string(centr_num);
      newc.coordinate=mean_vec;
      mean_vec.clear();
      tmp_centers.push_back(newc);
      cout<<"size of temp centers list: "<<tmp_centers.size()<<endl;
      //mean_vec.clear();
      //break;

    }

    cout<<"size of temp centers list: "<<tmp_centers.size()<<endl;
    old_centers=new_centers;
    new_centers=tmp_centers;
    tmp_centers.clear();


       //check both lists to see if the centers have exactly the same id, equaltimes to the size of the lists, with a counter
   unsigned int sim=0;
   itc2=old_centers.begin();
   for(itc=new_centers.begin();itc!=new_centers.end();itc++)
   {
   		/*
       if(itc->id==itc2->id)
       {
           sim++;
       }
       */
   		if(itc->coordinate==itc2->coordinate)
       {
           sim++;
       }
       cout<<"compare centers: "<<itc->id<<" "<<itc2->id<<endl;
       itc2++;
   }
   cout<<"size of old list: "<<old_centers.size()<<" size of new list: "<<new_centers.size()<<endl;
    whiles++;
    cout<<"while ends and restarts here "<<whiles<<endl;

   //if(sim>=new_centers.size()/2){
    if(sim==new_centers.size()){
    //if(sim>=1){
      //printf("\n\n\n\n\n\nmore than half centroids\n\n\n\n\n\n\n");
      //new_assign=assign_first_v( dat,new_centers);
      //assigned=new_assign;
      //return new_assign;
      break;
   }
   cout<<"sim is: "<<sim<<endl;

cout<<"??"<<endl;

    new_assign=assign_first_v( dat,new_centers);
    assigned=new_assign;
}while(1);
    return new_assign;

}



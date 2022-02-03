//init.cpp

#include "../include/init.h"
#include "../include/metrics.h"

using namespace std;

//uniform_real_distribution<double> si(0.0,(double)w);
list< vecter > init_first(int K,list< vecter > dat){
    list< vecter > centers;
    int c;
    list< vecter >::iterator vl;

    for(int i=0; i<K; i++)
    {
        c=rand()%(dat.size());
        //vl=centers.begin();centers
		vl=dat.begin();
        advance(vl,c);
        centers.push_back(*vl);
        cout<<"our c: "<<c<<endl;
    }
    //cout<<" our vector: " << print_vector_list(centers) << endl;
	//print_vector_list(centers);
    return centers;
}

//uniform_real_distribution<double> si(0.0,(double)w);
list< curve > init_firstc(int K,list< curve > dat){
    list< curve > centers;
    int c;
    list< curve >::iterator vl;

    for(int i=0; i<K; i++)
    {
        c=rand()%(dat.size());
        //vl=centers.begin();
		vl=dat.begin();
        advance(vl,c);
        centers.push_back(*vl);
        cout<<"our c: "<<c<<endl;
    }
    //cout<<" our vector: " << print_vector_list(centers) << endl;
   // print_curves(centers);
    return centers ;
}

//init 2
//for vectors
list< vecter > init_second_neo(int K,list< vecter > dat)
{
    //choose uniformly random center
    double distance,sq_distance;
    double sum1;
    list< vecter > centers;
    //choose the first vector/curve from the dataset
    //generate a random vector to be a center
    centers=init_first(1,dat);
    list<vecter>::iterator it,vl;

    int testtemp=nearest_neighbor_vec(dat,centers);
    /**/

    //compare every dimensions distance between the two vectors
    vector <double> all_distances,temp1,temp2,squared_distances;
    //all_distances holds the minimum distances from the best possible center
    vector<vector <double> > all_distances_array,temp22;

    vector <double> Di;  //minmax function in new file


    cout<<"manh test here"<<endl;
    double sum=0,def_sum,sq_sum=0,pr_sum=0,prob_ch;


    default_random_engine generator;
    uniform_real_distribution<double> d_rand(0,1);
    prob_ch=1-d_rand(generator);
    cout<< "chosen probability "<<prob_ch <<endl;
    cout<< "chosen probability "<<prob_ch <<endl;
    for(vl=centers.begin();vl!=centers.end();vl++){
        for (it = dat.begin(); it!=dat.end();++it)
        {
            if(it==dat.begin())
                it++;
            //cout<<"in loop"<<endl;
            temp1=vl->coordinate;
            temp2=it->coordinate;
            //cout<< vl->id << it->id <<endl;
            distance = manhattan_distance(temp1,temp2);
            all_distances.push_back(-1);
            sum+=distance;
            sq_distance= distance*distance;//Dr^2
            sq_sum+= distance*distance;//Sum of Di^2
        }
    }
    
    cout<<"last pr is "<< sq_distance/sq_sum <<endl;
    cout<<"NEW SUM: "<< sum <<" sq_sum "<<sq_sum<<endl;
////a new loop to choose our center based on the probabillity
    for(vl=centers.begin();vl!=centers.end();vl++){
        for (it = dat.begin(); it!=dat.end();++it)
        {
            if(it==dat.begin())
                it++;
            temp1=vl->coordinate;
            temp2=it->coordinate;
            distance = manhattan_distance(temp1,temp2);


            sq_distance= distance*distance;//Dr^2
            pr_sum+= sq_distance/sq_sum;
            if(pr_sum>=prob_ch)
            {
                cout<<pr_sum<<" "<<prob_ch<<endl;
                cout<<"our new chosen center is: "<<it->id<<" with distance "<<distance<<endl;
                break;
            }

         }
    }
    cout<<"our brand new loop starts here"<<endl;
    vl=centers.begin();
    int count=0;
    sum=0;
    sq_sum=0;

    //K=3;
    cout<<centers.size()<<endl;
    while(centers.size()<K)
    {

      for (it = dat.begin(); it!=dat.end();++it)
      {
        if(it==dat.begin())
                it++;
        temp1=vl->coordinate;

        cout<<"count is:"<<count<<endl;
        temp2=it->coordinate;
        distance = manhattan_distance(temp1,temp2);
        //cout<<distance<<" "<<all_distances[count]<<endl;
        if((distance<=all_distances[count])||(all_distances[count]<0))
        {
           // cout<<distance<<endl;
          sum=sum-all_distances[count];
          sq_sum=sq_sum-all_distances[count]*all_distances[count];
          all_distances[count]=distance; //di
          cout<<all_distances[count]<<endl;
          sum+=distance;

          //
          //sq_distance= distance*distance;//Dr^2
          sq_sum+= distance*distance;//Sum of Di^2

        }
        count++;
      }


      //apostaseis+upologismoi
      //NOTE FOR NORMALIZATION FOR BIG DATASET DIVIDE BY MAXDI
      //PICK X BETWEEN PR-1 AND PR
      prob_ch=1-d_rand(generator);
      cout<< "chosen probability "<<prob_ch <<endl;
      cout<< "chosen probability "<<prob_ch <<endl;
      pr_sum=0;
      for(unsigned int i=0;i<all_distances.size();i++)
      {
        cout<<"yes"<<endl;
        sq_distance= all_distances[i]*all_distances[i];//Dr^2
        pr_sum+= sq_distance/sq_sum;
        cout<<pr_sum<<endl;
        if(pr_sum>=prob_ch)//||i==all_distances.size()
        {
            cout<<pr_sum<<" "<<prob_ch<<endl;
            //cout<<"our new chosen center is: "<<it->id<<" with distance "<<distance<<endl;
            it=dat.begin();
            advance(it,i);
            centers.push_back(*it);
            //cout<<"our c: "<<c<<endl;
            cout<<"we have center: "<<i<<endl;
            break;
        }
      }
      count=0;
      vl++;
    }
    cout<<dat.size()<<endl;
    cout<<centers.size()<<endl;
    cout<<"end of neoinit"<<endl;
    return centers;
}


list< curve > init_second_c(int K,list< curve > dat)

{
    //choose uniformly random center
    double distance,sq_distance;
    double sum1;
    list< curve > centers;
    //int c;
    //choose the first vector/curve from the dataset
    //generate a random vector to be a center
    centers=init_firstc(1,dat);
    list<curve>::iterator it,vl;

    cout<<centers.size()<<endl;

    //compare every dimensions distance between the two curves
    vector <double> all_distances,squared_distances;
    //all_distances holds the minimum distances from the best possible center
    vector<vector <double> > all_distances_array,temp1,temp2;

    vector <double> Di;  //minmax function in new file
    double sum=0,def_sum,sq_sum=0,pr_sum=0,prob_ch;

    default_random_engine generator;
    uniform_real_distribution<double> d_rand(0,1);
    prob_ch=1-d_rand(generator);
    cout<< "chosen probability "<<prob_ch <<endl;
    cout<<dat.size()<<endl;
    cout<<centers.size()<<endl;

    for(vl=centers.begin();vl!=centers.end();vl++){
        for (it = dat.begin(); it!=dat.end();++it)
        {
            if(it==dat.begin())
                it++;
            cout<<"all distances loop"<<endl;
            all_distances.push_back(-1);
        }
        
    }
    //*/
    cout<<"between two loops"<<endl;
////a new loop to choose our center based on the probabillity
    for(vl=centers.begin();vl!=centers.end();vl++){
        for (it = dat.begin(); it!=dat.end();++it)
        {
            if(it==dat.begin())
                it++;
            temp1=vl->coordinates;
            temp2=it->coordinates;
            distance = dtw(temp1,temp2);


            sq_distance= distance*distance;//Dr^2
            pr_sum+= sq_distance/sq_sum;
            if(pr_sum>=prob_ch)
            {
                cout<<pr_sum<<" "<<prob_ch<<endl;
                cout<<"our new chosen center is: "<<it->id<<" with distance "<<distance<<endl;
                break;
            }

         }
    }
cout<<"our brand new loop starts here"<<endl;
    vl=centers.begin();
    int count=0;
    sum=0;
    sq_sum=0;

    //K=3;
    cout<<centers.size()<<endl;
    while(centers.size()<K)
    {

      for (it = dat.begin(); it!=dat.end();++it)
      {
        if(it==dat.begin())
                it++;
        temp1=vl->coordinates;
        //it++;///WARNING
        //cout<< *it <<endl;
        cout<<"count is:"<<count<<endl;
        temp2=it->coordinates;
        distance = dtw(temp1,temp2);
        //cout<<distance<<" "<<all_distances[count]<<endl;
        if((distance<=all_distances[count])||(all_distances[count]<0))
        {
            cout<<distance<<" "<<all_distances[count]<<endl;
          sum=sum-all_distances[count];
          //sq_sum=sq_sum-all_distances[count]*all_distances[count];
          all_distances[count]=distance; //di
          cout<<all_distances[count]<<endl;
          sum+=distance;

          //
          //sq_distance= distance*distance;//Dr^2
          sq_sum+= distance*distance;//Sum of Di^2
          cout<<"sqsum is: "<< sq_sum <<" distance^2: "<< distance*distance <<endl;

        }




        count++;
      }


      //apostaseis+upologismoi
      //NOTE FOR NORMALIZATION FOR BIG DATASET DIVIDE BY MAXDI
      //PICK X BETWEEN PR-1 AND PR
      prob_ch=1-d_rand(generator);
      cout<< "chosen probability "<<prob_ch <<endl;
      //prob_ch=0.55;
      pr_sum=0;
      for(int i=0;i<=all_distances.size();i++)
      {
        sq_distance= all_distances[i]*all_distances[i];//Dr^2
        pr_sum+= sq_distance/sq_sum;
        //cout<<i<<"sqsqsqs: "<<sq_distance<<" "<<pr_sum<<" "<<sq_sum<<endl;
        if(pr_sum>=prob_ch||i==all_distances.size())
        {
            cout<<"yes: "<<pr_sum<<" "<<prob_ch<<endl;
            //cout<<"our new chosen center is: "<<it->id<<" with distance "<<distance<<endl;
            it=dat.begin();
            advance(it,i);
            centers.push_back(*it);
            //cout<<"our c: "<<c<<endl;
            cout<<"we have center: "<<i<<endl;
            break;
        }
      }
      //change vl
      count=0;

      //centers++
      vl++;


    }

    cout<<dat.size()<<endl;
    cout<<centers.size()<<endl;
    cout<<"end of neoinit"<<endl;
    return centers;
}
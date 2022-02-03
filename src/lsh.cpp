#include "../include/libraries.h"
#include "../include/lsh.h"
#include "../include/metrics.h"

using namespace std;

////////delta=4*2*min(m1,m2);
//create first grid 2x16 dimension based on the smallest curve from the centerslist
//the other L grids are 2x16 dimension shifted by (0,d] 

///init grids
list<grid> create_grid(int L,list<curve> centers){
    list<grid> grid_list;
    grid gr;
    double minx,miny,maxx,maxy,dtw_min=0.000300666;
    list<curve>::iterator it;
    for(it=centers.begin();it!=centers.end();++it){
        if(it==centers.begin())
        {
            minx=it->coordinates[0][0];
            maxx=minx;
            miny=it->coordinates[0][1];
            maxy=miny;
        }
        if(it->coordinates[0][0]<minx){
            minx=it->coordinates[0][0];
        }
        else if(it->coordinates[0][0]>maxx){
            maxx=it->coordinates[0][0];
        }
        if(it->coordinates[0][1]<miny){
            miny=it->coordinates[0][1];
        }
        else if(it->coordinates[0][1]>maxy){
            maxy=it->coordinates[0][1];
        }
    }
    gr.initial_x=minx;
    gr.initial_y=miny;
    gr.end_x=maxx;
    gr.end_y=maxy;
    gr.cell_dist=dtw_min;

    double xr,yr;
    default_random_engine generator;
    //uniform_real_distribution<double> x_rand(0,8*dtw_min),y_rand(0,8*dtw_min);//chosen because d returns inappropriate results
    uniform_real_distribution<double> x_rand((-4)*dtw_min,4*dtw_min),y_rand((-4)*dtw_min,4*dtw_min);
    for(int i=0;i<L;i++){
        //shifted first_grid
        xr=x_rand(generator);
        yr=y_rand(generator);
        cout<<"METATOPISI kata x: "<<xr<<" METATOPISI kata y: "<< yr <<endl;
        gr.initial_x=minx+xr;
        gr.initial_y=miny+yr;
        cout<<"kainourgio min x: "<<gr.initial_x<<" kainourgio min y: "<<gr.initial_y<<endl;
        gr.end_x=maxx+xr;
        gr.end_y=maxy+yr;
        cout<<"kainourgio max x: "<< gr.end_x<<" kainourgio max y: "<< gr.end_y<<endl;
        gr.cell_dist=dtw_min;
        grid_list.push_back(gr);
    }
    cout<<"SIZE: "<<grid_list.size()<<endl;
    return grid_list;
}

//transfer grid to vector<double>
list <curve> grid_as_curve(grid grids){
    list<curve> gr;
    list<curve>::iterator ci;
    double cur_x,cur_y;
    cur_x=grids.initial_x;
    cur_y=grids.initial_y;
    curve cutemp;
    //we need id, number of points and coordinates
    string id="temporary";
    int numpoints=1;
    cout<<"function"<<endl;
    ci=gr.begin();
    int flag=0;
    
        do{
    
           (cutemp.coordinates).push_back({cur_x,cur_y});
            cout<<"do loop"<<endl;
            if(cur_x<grids.end_x){
             cur_x+=grids.cell_dist;
            }
            if(cur_y<grids.end_y){
                cur_y+=grids.cell_dist;
            }
            cout<<"initial_x= "<<grids.initial_x<<" initial_y ="<<grids.initial_y<<endl;
            cout<<"cell distance:"<<grids.cell_dist<<endl;
            cout<<"cur_x= "<<cur_x<<" cur_y ="<<cur_y<<endl;
            cout<<"end_x= "<<grids.end_x<<" end_y="<<grids.end_y<<endl;

            cout<<"before break"<<numpoints<<endl;
            if((cur_x>=grids.end_x)&&(cur_y>=grids.end_y)){
              cout<<"break"<<endl;
                cutemp.id=id;//to_string(8);
               cutemp.number_of_points=numpoints;
                flag=1;
            }
            cout<<"all good?"<<endl;
            numpoints++;
            ci++;
        }while(flag==0);
    
    cout<<"print ????? "<<endl;
    gr.push_back(cutemp);
    cout<<"print id: "<<cutemp.id<<endl;
    
    return gr;
}
//call prev function and put it to a list of grids
list<curve> grid_recurs(list<curve> gr,list<grid> grids){ //int L??
    list<grid>::iterator itgr;
    for(itgr=grids.begin();itgr!=grids.end();itgr++){
    //for(int i=0;i<L;i++){
       // gr.merge(grid_as_curve(*itgr));
        //append(gr,grid_as_curve(*itgr));
        gr.splice(gr.end(),grid_as_curve(*itgr));
    //}
    }
    cout<<"megethos list grid (L) "<< grids.size()<<endl;
    cout<<"megethos recursive list "<< gr.size()<<endl;
    return gr;
}

/*
// snap the curves on the grid
list<list <curve> > snapped_curves(list <curve> data_curves,list<grid> grids,int L)
{
    double x_cell,y_cell;
    int correct_x,correct_y;
    list <curve>::iterator itcur;
    list<grid>::iterator itgr;
    vector<vector <double> > coord;

    for(itgr=grids.begin();itgr!=grids.end();itgr++){
        for(itcur=data_curves.begin();itcur!=data_curves.end();itcur++){
    
            x_cell= itcur->coordinates[0][0]/itgr->cell_dist;
            y_cell=itcur->coordinates[0][1]/itgr->cell_dist;
            correct_x=fmod(itcur->coordinates[0][0],itgr->cell_dist);
            correct_y=fmod(itcur->coordinates[0][1],itgr->cell_dist);
            
            cout<<"our x_cell: "<<x_cell<<"our snapped y_cell: "<<y_cell<<endl;
            cout<<"our correct_x: "<<correct_x<<"our snapped correct_y: "<<correct_y<<endl;

      //      euclidean(itcur->coordinates[0][0])
        }
    }
    cout<<"heyyy"<<endl;
}*/

//assign curves from the dataset to grid coordinates, based on their euclidean distances
//(snap to grid)
list<list <curve> > snapped_curves(list <curve> data_curves,list<curve> curve_grids)
{
    list<list<curve>> snappedcurves;
    list<curve> distlistcurve;
    list <curve>::iterator itd,itg;
    vector <vector<double>> dc,gc;
    vector <vector<double>>:: iterator itdc,itgc;
    double mindist,edist;
    curve tmpcurve;
    cout<<data_curves.size()<<endl;
    for(itg=curve_grids.begin();itg!=curve_grids.end();itg++)
    {
         cout<<"inside grid list: "<<endl;
        int count=0;
        for(itd=data_curves.begin();itd!=data_curves.end();itd++)
        {
            cout<<"inside dtata curve list: "<<endl;
            count++;
         //   cout<<"PRINT COUNT(NUMBER OF CURVES):"<< count<<endl;
            //computations
            mindist=10000;
            gc=itg->coordinates;
            dc=itd->coordinates;
            int count3=0;
            for(itdc=dc.begin();itdc!=dc.end();itdc++){          

           // for(itgc=gc.begin();itgc!=gc.end();itgc++){
                count3++;
            //    cout<<"PRINT COUNT(NUMBER OF POINTS) GRIDS:"<< count3<<endl;
   
                int count2=0;
            for(itgc=gc.begin();itgc!=gc.end();itgc++){
                //for(itdc=dc.begin();itdc!=dc.end();itdc++){          
                    count2++;
                //    cout<<"PRINT COUNT(NUMBER OF POINTS):"<< count2<<endl;
                    edist=euclidean(*itgc,*itdc);
                    if(edist<mindist){
                        mindist=edist;
                        //tmpcurve.coordinates=itg->coordinates;
                        (tmpcurve.coordinates).push_back({itg->coordinates[0]});
                        tmpcurve.id=itd->id;
                        tmpcurve.number_of_points=itd->number_of_points;
                    }
                }
              //  distlistcurve.push_back(tmpcurve);
            }
            distlistcurve.push_back(tmpcurve);
            (tmpcurve.coordinates).clear();
        }
        snappedcurves.push_back(distlistcurve);
    }
    cout<<"size of list of snapped curves: "<<snappedcurves.size()<<endl;
    return snappedcurves;
}


//remove repeated coordinates

//gather the points above to form a vector

//._____________________________.

//hash like the vector lsh FROM 1ST EX
//hash and

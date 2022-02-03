#include "../include/libraries.h"

#include "../include/tempother.h"
//temporary untested functions

//clean a curve from repetitive coordinates
//void clean_curves(list< curve > curves_list)
list< curve > clean_curves(list< curve > curves_list)
{
	std::list<curve>::iterator vl;
	std::cout<<"clean curve list test"<<std::endl;
	int i=0;
	for (vl=curves_list.begin(); vl!=curves_list.end(); ++vl)
	{
		std::cout << vl->id<<std::endl;
		std::cout << vl->number_of_points <<endl;
		//for (int i=0; i< vl->coordinates.size();++i){
		//int i=stoi(vl->id);//
		/*
		for(int j=0; j< 2*(vl->number_of_points); j++){
			//std::cout<<" "<<vl->coordinates[i][j];
			//std::cout<<" "<<vl->coordinates[1][0];
            //if the coordinate is the same as the previous one, delete it
			
            //if((j>=2)&&((j+1)<2*(vl->number_of_points))&&(vl->coordinates[i][j]==vl->coordinates[i][j-2])&&(vl->coordinates[i][j-1]==vl->coordinates[i][j+1]))
			if((j>=3)&&(j<2*(vl->number_of_points))&&(vl->coordinates[i][j]==vl->coordinates[i][j-2])&&(vl->coordinates[i][j-1]==vl->coordinates[i][j-3]))
            {
				//cout<<" yes "<<i<<" "<<j<<endl;
				cout<<" yes "<<vl->coordinates[i][j-2]<<" "<<vl->coordinates[i][j-1]<<endl;
                //curves_list.erase(vl);
                //curves_list.erase(vl);
				//cout<<" erase "<< vl->coordinates[i].begin()+j-1 <<endl;
				cout<<" erase "<< *(vl->coordinates[i].begin()+j-3) << endl;
				(vl->coordinates[i]).erase(vl->coordinates[i].begin()+j-3);
				//cout<<" yes "<<vl->coordinates[i][j-2]<<" "<<vl->coordinates[i][j-1]<<endl;
				cout<<" erase "<< *(vl->coordinates[i].begin()+j-3) << endl;
				(vl->coordinates[i]).erase(vl->coordinates[i].begin()+j-3);
				//cout<<" yes "<<vl->coordinates[i][j-2]<<" "<<vl->coordinates[i][j-1]<<endl;
				
				vl->number_of_points=vl->number_of_points-1;
				//vl=vl-2;
				//vl--;
				j=0;
            }
			
		}
		*/
		for(unsigned int i=0;i<(vl->coordinates).size();i++)
		{
			for(unsigned int j=0;j<(vl->coordinates).size();j++)
			{
				if(i!=j)
				{
					if((vl->coordinates[i][0]==vl->coordinates[j][0])&&(vl->coordinates[i][1]==vl->coordinates[j][1]))
					{
						(vl->coordinates).erase((vl->coordinates).begin()+i);
						vl->number_of_points=vl->number_of_points-1;
						i=0;
					}
				}
			}
		}
		cout<<endl;
		//}
		std::cout<<std::endl;
		i++;
	}
	return curves_list;
}

//select the number 1 or 2
int one_or_two(void)
{
    return rand()%2 +1;
}
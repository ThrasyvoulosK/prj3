//curves.cpp
#include "../include/libraries.h"

#include "../include/curves.h"

list<curve> assign_curves(string input_file, list<curve> curves_list)
{
	curve ccc;
	vector<double> xy;
	vector<vector<double> > xys;
	int count=0;
	
	ifstream infile;
	infile.open(input_file);
	
	string dataline,dataword,datanum,temp;
	//int numcoord;//the coordinates represented as an integer 
	infile>>dataword;//the first line, which we don't need
	//keep the curves of the input file
	while (!infile.eof())
	{
		infile>>dataword;
		ccc.id=dataword;
		infile>>dataword;
		ccc.number_of_points=stoi(dataword);
		cout<<"ids: "<<ccc.id<<"number of points: "<<ccc.number_of_points<<endl;
		//we want to assign  our coordinates properly
		getline(infile,dataline);
		cout<<"test";
		istringstream datalines(dataline);
		cout<<"test";
		count=0;
		while(datalines>>datanum)
		{
			//cout<<"test"<<endl;
				
			temp=datanum;
			//datanum.copy(temp,datanum.begin(),datanum.end());
			if(temp.front()=='(')
			{
				//cout<<"parenthesis at front"<<endl;
				temp.erase(temp.begin());
			}
			if(temp.back()==',')
			{
				//cout<<"comma at the back"<<endl;
				//temp.erase(temp.end());
				temp.pop_back();
			}			
			if(temp.back()==')')
			{
				//cout<<"end parenthesis"<<endl;
				//temp.erase(temp.end());
				temp.pop_back();
			}
					
			//cout<<"datanum and tempm: "<<endl<<datanum<<" "<<temp<<endl;
			//cout<<" "<<temp.front()<<" "<<temp.back()<<endl;
			xy.push_back(stod(temp));
			//xy[count]=(stod(temp));

			//if(xy.size()>=2)
			if(count>=1)
			{
				//cout<<"size is 2 "<<(ccc.coordinates).size()<<endl;
				cout<<"size is 2 "<<xys.size()<<endl;
				//(ccc.coordinates).push_back(xy);
				xys.push_back(xy);
				//curves_list.push_back(ccc);
				//cout<< ccc.coordinates[0][0];
				xy.clear();
				//(ccc.coordinates).clear();
				count=0;
			}
			else
				count++;
		}
			//xys.push_back(xy);
			
			
			//(ccc.coordinates).push_back(xy);
			//xy.clear();
			ccc.coordinates=xys;
			curves_list.push_back(ccc);
			cout<< "coordinates test "<<ccc.coordinates[132][0]<<endl;
			//(ccc.coordinates).clear();
			xys.clear();
			cout<<endl;
	}
	//}
	infile.close();
	
	return curves_list;
}


void print_curves(list< curve > curves_list)
{
	std::list<curve>::iterator vl;
	std::cout<<"print curve list test"<<std::endl;
	//int i=0;
	cout<<"curves size "<<curves_list.size() <<endl;
	for (vl=curves_list.begin(); vl!=curves_list.end(); ++vl)
	{
		std::cout << vl->id<<std::endl;
		std::cout << vl->number_of_points <<endl;
		//for (int i=0; i< vl->coordinates.size();++i){
		//int i=stoi(vl->id);//
		//cout<<vl->coordinates[0][0]<<" "<<vl->coordinates[0][1]<<endl;
		//cout<<vl->coordinates[0][2]<<" "<<vl->coordinates[0][3]<<endl;
		//cout<<vl->coordinates[1][0]<<" "<<vl->coordinates[1][1]<<endl;
		//cout<<vl->coordinates[2][0]<<" "<<vl->coordinates[2][1]<<endl;
		//cout<< (vl->coordinates).size()<<endl;
		/*
		for(int j=0; j< 2*(vl->number_of_points); j++){
			std::cout<<" "<<vl->coordinates[i][j];
			////std::cout<<i<<" "<<j<<" "<<vl->coordinates[i][j]<<endl;
			if(j%2==1)
				cout<<endl;
			}
			*/
		/*
		for(int j=0;j<2;j++)
			cout<<vl->coordinates[i][j]<<" ";
			*/
		//cout<<vl->coordinates[0][i]<<endl;
		for(unsigned int i=0;i<(vl->coordinates).size();i++)
			cout<<i<<": "<<vl->coordinates[i][0]<<" "<<vl->coordinates[i][1]<<endl;


		cout<<endl;
		//}
		std::cout<<std::endl;
		//i++;
	}
}
	


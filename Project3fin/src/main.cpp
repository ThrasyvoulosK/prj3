//Project 2 2019-2020
#include "../include/libraries.h"


using namespace std;
#include "../include/preprocessing.h"


#include "../include/curves.h"
#include "../include/init.h"

#include "../include/metrics.h"

#include "../include/tempother.h"
#include "../include/clustering.h"
#include "../include/assign.h"
#include "../include/lsh.h"
#include "../include/silhouette.h"


#include "../include/update.h"

#include <chrono>
using namespace std::chrono; 

int main(int argc,char** argv)
{
	string input_file,conf_file,output_file,complete;// the files we are going to use from the input line
	/*input is
	$./cluster -i <input file> -c <configuration file> -o <output file> -complete <optional>
	*/

	//check if the arguments given are valid
	cout<<"Checking arguments"<<endl;
	int arg_count=0;

	while(argv[arg_count]!=NULL)
	{
		cout<<argv[arg_count];
		if (strcmp(argv[arg_count],"-i")==0)
		{
			printf("-i given ok\n");
			//if the next arg is invalid print error
			//we do the exact same thing for the next variables
			if (argv[arg_count+1]==NULL)
			{
				printf("Error: Wrong Arguments Given\n");
				return -1;
			}
			else
			{
				//the input file
				input_file=argv[arg_count+1];
			}
		}
		if (strcmp(argv[arg_count],"-c")==0)
		{
			printf("-c given ok\n");
			if (argv[arg_count+1]==NULL)
			{
				printf("Error: Wrong Arguments Given\n");
				return -1;
			}
			else
			{
				//the cluster configuration file
				conf_file=argv[arg_count+1];
			}
		}
		if (strcmp(argv[arg_count],"-o")==0)
		{
			printf("-o given ok\n");
			if (argv[arg_count+1]==NULL)
			{
				printf("Error: Wrong Arguments Given\n");
				return -1;
			}
			else
			{
				//the output file
				output_file=argv[arg_count+1];
			}
		}
		if (strcmp(argv[arg_count],"-complete")==0)
		{
			printf("-complete given ok\n");
			if (argv[arg_count+1]==NULL)
			{
				printf("Error: Wrong Arguments Given\n");
				return -1;
			}
			else
			{
				//complete
				complete=argv[arg_count+1];
			}
		}
		arg_count++;
	}

	cout<<endl<<input_file<<conf_file<<output_file<<complete<<endl;

	//open the input file
	//check whether its about vectors or polygonal curves

	if(curves_or_vectors(input_file)!="error")
		cout<<"We shall deal with: "<<curves_or_vectors(input_file)<<endl;
	else
	{
		cout<<"Error: Wrong Input File Given"<<endl;
		return -1;
	}

		list<curve> curves_list,curves_list2,centers_c;

	//testing curves.h
	if(curves_or_vectors(input_file)=="curves")
	{
		list<curve>::iterator ci,ciplus;
		ciplus=curves_list.begin();
		//int countcurv=0;
		curves_list=assign_curves(input_file, curves_list);

		curves_list2=clean_curves(curves_list);
		//centers_c=init_firstc(3,curves_list2);
		//cout<<"curves list size: "<<curves_list.size()<<endl;
		//print_curves(curves_list);

		/*
		//int n=3;
//		list<clustering_c> assign_for_curves,updc;
		//list<list<curve>> snappedcl;
		list<list<curve>>::iterator itsn;
		cout<<"print assign for curves"<<endl;
		//print_assign_c(assign_for_curves);
		list<grid> listgrid;
		list <grid>::iterator gri;
		listgrid=create_grid(3,centers_c);
		list<curve> gridy_curves;

//		gridy_curves=grid_as_curve(listgrid.front());
		gridy_curves=grid_recurs(gridy_curves,listgrid);

		cout<<"printing grid curves"<<endl;
		snappedcl= snapped_curves(curves_list,gridy_curves);
		for(itsn=snappedcl.begin();itsn!=snappedcl.end();itsn++)
{		print_curves(*itsn);}
	//	cout<<snappedcl.size()<<endl;

	//	print_curves(gridy_curves);
		//snappedcl=snapped_curves(curves_list,listgrid,3);
		*/
	}
	cout<<"end of curves tests"<<endl;
	//if we have a curve file, we must convert it to a vector


	int number_of_clusters=4;//K of Kmeans
	cout<<endl<<"Please give us the desired number of clusters"<<endl;
	cin>>number_of_clusters;
	int number_of_grids=2;//
	int number_of_vector_hash_tables=3;//L
	int number_of_vector_hash_functions;//k of LSH vectors
	number_of_vector_hash_functions=1;//
	cout<<number_of_clusters*number_of_grids*number_of_vector_hash_tables*number_of_vector_hash_functions<<endl;//
	list<vecter> vector_list;

	if(curves_or_vectors(input_file)=="vectors")
	{
		vector_list=assign_vectors(input_file, vector_list);
	
	}



	//write our results on output_file

	//ask for user input
	string answer,answer1,answer2;
	list< vecter > in;
	list<clustering> clv;
	list<clustering> upd;
	list<string> temp_centrs;
	list<string>::iterator tci;
	list<clustering>::iterator ci,updi;
	//list<curve> curves_list2,centers_c;
	list<clustering_c> assign_for_curves,updc;
	list<clustering_c>::iterator updicit;

	list<clustering> sil;
	list<clustering>::iterator sili;

	auto start = high_resolution_clock::now(); 
	

	answer="0";
	cout<<"Which Initialisation do you wish to do?"<<endl;
	cout<<"Press 1 if you want Random Selection Of K Vectors/Curves, please "<<endl;
	cout<<"OR"<<endl<<"Press 2 if you want K-Means++, please "<<endl;
	cin>>answer;
	while (answer!="1"||answer!="2") {
		if (answer=="1") {
			std::cout << "you have chosen random K" << '\n';

			if(curves_or_vectors(input_file)=="vectors")
			{
				
				in=init_first(number_of_clusters,vector_list);
				
			}
			if(curves_or_vectors(input_file)=="curves"){
				centers_c=init_firstc(number_of_clusters,curves_list2);
			}

			break;
		}
		else if (answer=="2") {
			std::cout << "you have chosen K-Means" << '\n';
			if(curves_or_vectors(input_file)=="vectors")
			{
				in=init_second_neo(number_of_clusters,vector_list);

			}
			if(curves_or_vectors(input_file)=="curves"){
				centers_c=init_second_c(number_of_clusters,curves_list2);

			}
			break;
		}
		else
		{
			std::cout << "Wrong Input! please, try again" << '\n';
			cin>>answer;
		}
	}
	answer1="0";
	cout<<endl<<"Which Assignment do you wish to do?"<<endl;
	cout<<"Press 1 if you want Lloyd's assignment, please "<<endl;
	cout<<"OR"<<endl<<"Press 2 if you want assignment by Range Search, please "<<endl;
	cin>>answer1;
	while (answer1!="1"||answer1!="2") {
		if (answer1=="1") {
			std::cout << "you have chosen Lloyd's assignment" << '\n';
			if(curves_or_vectors(input_file)=="vectors")
			{
				clv=assign_first_v(vector_list,in);
			}
			if(curves_or_vectors(input_file)=="curves"){
				assign_for_curves=assign_first_c(curves_list2,centers_c);
			}
			break;
		}
		else if (answer1=="2") {
			std::cout << "you have chosen assignment by Range Search" << '\n';
			if(curves_or_vectors(input_file)=="vectors")
			{
				cout<<"we are working on assignment for vectors"<<endl;
				cout<<"the program will choose Lloyd's assignment  for the moment "<<endl;
				answer1	="1";			
			}
			if(curves_or_vectors(input_file)=="curves"){
				cout<<"we are working on assignment for curves"<<endl;
				cout<<"the program will choose Lloyd's assignment  for the moment "<<endl;
				answer1	="1";			
			}
			//break;
		}
		else
		{
			std::cout << "Wrong Input! please, try again" << '\n';
			cin>>answer1;
		}
	}
	answer2="0";
	cout<<endl<<"Which Update do you wish to do?"<<endl;
	cout<<"Press 1 if you want PAM, please "<<endl;
	cout<<"OR"<<endl<<"Press 2 if you want Mean Vector or DTW centroid curve, please "<<endl;
	cin>>answer2;
	while (answer2!="1"||answer2!="2") {
		if (answer2=="1") {
			std::cout << "you have chosen PAM" << '\n';
			if(curves_or_vectors(input_file)=="vectors")
			{
				upd=update_first_v(in,clv,vector_list);
			}
			if(curves_or_vectors(input_file)=="curves"){
				updc= update_first_c(centers_c,assign_for_curves,curves_list2);
			}
			break;
		}
		else if (answer2=="2") {
			std::cout << "you have chosen Mean Vector or DTW centroid curve" << '\n';
			if(curves_or_vectors(input_file)=="vectors")
			{
				upd=update_second_v(in,clv,vector_list);

			}
			if(curves_or_vectors(input_file)=="curves"){
				cout<<"we are working on update for curves"<<endl;
				cout<<"the program will choose PAM's update  for the moment "<<endl;
				answer2	="1";
			}
			break;
		}
		else
		{
			std::cout << "Wrong Input! please, try again" << '\n';
			cin>>answer2;
		}
	}
	//time ends here
	auto stop = high_resolution_clock::now(); 
	auto duration= duration_cast<microseconds>(stop - start); 

	int incent=0;
	if(curves_or_vectors(input_file)=="curves"){
		cout<<"output for curves starts here"<<endl;
		updicit=updc.begin();
		temp_centrs.push_back(updicit->center_id);
		do{
			//cout<<"do starts here"<<endl;
			//updicit++;
			incent=0;
			for(tci=temp_centrs.begin();tci!=temp_centrs.end();tci++)
			{
				if(updicit->center_id==(*tci)){
					incent=1;
					//break;
				}

			}
			if(incent==0)
				temp_centrs.push_back(updicit->center_id);
			//break;
			updicit++;
		}while(updicit!=updc.end());
		//cout<<"out of loop here"<<endl;
		//OUTPUT
   		 std::ofstream file;//(output_file)
    	// open file and overwrite it if it exists, or create it if it doesn't exist
   		 file.open(output_file, std::ios::out);
   		 file<< "Algorithm:"<<"I"<< answer<<"A"<<answer1<<"U"<<answer2<<endl;
    
    	tci=temp_centrs.begin();
    	for (unsigned int i=0;i<temp_centrs.size();i++){
    		//cout<<"for starts here"<<endl;
	    	int clussum=0;
    		//size kai centroids
 
    		for(updicit=updc.begin();updicit!=updc.end();updicit++)
    		{
	    		//size of cluster is the sum of thepoints in the dataset with the selected centre id
    			if((*tci)==updicit->center_id)
	    			clussum++;
    		}
    		file<<endl;
    		file<<"CLUSTER-"<<i<<" {size: "<< clussum;
	    	

			file<<", centroid: "<<(*tci) <<endl;

    		for(updicit=updc.begin();updicit!=updc.end();updicit++)
    		{    		
    			if((*tci)==updicit->center_id)
    				file<<" "<<updicit->id;
    		}
    		file<<"}"<<endl;
    	
    		tci++;

    	}

    	//xronos
    	file<<"clustering_time: "<< duration.count() <<endl;
    	file.close();
		cout<<endl<<"Our program ends here. Please, check out the output file."<<endl;
		return 0;
	}

	//make a list with the ids of the clusters
	updi=upd.begin();
	temp_centrs.push_back(updi->center_id);
	
	do{
		updi++;
		incent=0;
		for(tci=temp_centrs.begin();tci!=temp_centrs.end();tci++)
		{
			if(updi->center_id==(*tci)){
				incent=1;
				break;
			}

		}
		if(incent==0)
			temp_centrs.push_back(updi->center_id);
				
	}while(updi!=upd.end());

	//OUTPUT
    //string filename;
    std::ofstream file;//(output_file)
    // open file and overwrite it if it exists, or create it if it doesn't exist
    file.open(output_file, std::ios::out);
    //file.open(output_file, std::ios::app);
    
    file<< "Algorithm:"<<"I"<< answer<<"A"<<answer1<<"U"<<answer2<<endl;
    //for (int i=0;i<K;i++){
    tci=temp_centrs.begin();
    for (unsigned int i=1;i<temp_centrs.size();i++){
    	int clussum=0;
    	//size kai centroids
    	

    	for(updi=upd.begin();updi!=upd.end();updi++)
    	{
    		//size of cluster is the sum of thepoints in the dataset with the selected centre id
    		if((*tci)==updi->center_id)
    			clussum++;
    	}
    	file<<endl;
    	file<<"CLUSTER-"<<i<<" {size: "<< clussum;
    	
    	//if(answer2=="1"){
    		file<<", centroid: "<<(*tci) <<endl;
    	//}
/*
    	else{
    		//print centroids coordinates
    		file<<", centroid: "<< <<endl;
    	}
    	*/
    	for(updi=upd.begin();updi!=upd.end();updi++)
    	{    		
    		if((*tci)==updi->center_id)
    			file<<" "<<updi->id;
    	}
    	file<<"}"<<endl;
    	
    	tci++;

    }
    //xronos
    file<<"clustering_time: "<< duration.count() <<endl;

    file<<"Silhouette: [";

    sil=centers_for_silhoutte_v( vector_list, in);
	//print_assign_v(sil);
	sili=sil.begin();
	//ci=clv.begin();
	updi=upd.begin();
	int max=0,count_s=0;
	double dsum,dist_sil,dmean;

	for(unsigned int i=0;i<vector_list.size();i++){
		if(updi->distance_from_cent>sili->distance_from_cent){
			max=updi->distance_from_cent;
		}
		else{
			max=sili->distance_from_cent;
		}
		//cout<< abs(sili->distance_from_cent - ci->distance_from_cent)/max << endl;
		if(max!=0)
		{	count_s++;
			dist_sil=(sili->distance_from_cent - updi->distance_from_cent)/max;

			file<<" "<<dist_sil;
		}
			
			dsum+=dist_sil;
			cout<< dist_sil << endl;
			sili++;
			updi++;
	}
	dmean=dsum/vector_list.size();

	file<<"]";
	file<<endl<<"si average is: "<<dmean<<endl;


    file.close();

    cout<<endl<<"Our program ends here. Please, check out the output file."<<endl;
	

	return 0;

}

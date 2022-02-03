#include "../include/libraries.h"

#include "../include/preprocessing.h"

using namespace std;
std::string curves_or_vectors(std::string input_file)
{
	ifstream infile;
	infile.open(input_file);
	string dataline,dataword,datanum,curves_or_vectors;
	infile>>dataword;
	if(dataword=="curves")
		curves_or_vectors="curves";
	else if (dataword=="vectors")
		curves_or_vectors="vectors";
	else
	{
		cout<<"Error, this file doesn't declare its purpose: "<<input_file<<endl;
		//return -1;
		return "error";
	}
	//cout<<input_file<<"We shall deal with: "<<curves_or_vectors<<endl;
	
	infile.close();
	return curves_or_vectors;
}


void print_vector_list(std::list<vecter> vector_list)
{
	std::list<vecter>::iterator vl;
	std::cout<<"print_vector_list test"<<std::endl;
	unsigned int i;
	for (vl=vector_list.begin(); vl!=vector_list.end(); ++vl)
	{
		std::cout << vl->id<<std::endl;
		for (i=0; i< vl->coordinate.size();++i)
			std::cout<<" "<<vl->coordinate[i];
		std::cout<<std::endl;
	}
}


list<vecter> assign_vectors(string input_file, list<vecter> vector_list)
{
	// we put our vectors in lists of structs, composed of strings(for ids) and (int)vectors for their coordinates
	//list<vecter> vector_list,qvector_list,concat_list;
	list<vecter>::iterator vl;
	vecter vcx;// temporary struct used mainly for our input to the lists
	
	ifstream infile;
	infile.open(input_file);
	
	string dataline,dataword,datanum;
	dataline="e";
	dataword="e";
	datanum="e";
	//int numcoord;//the coordinates represented as an integer
	double numcoord;
	
	//make a loop to read and store the input files
	//gather data from the input file
	//infile>>dataword;//the first line is just a description word
	//cout<<dataword<<endl;
	cout<<"Storing Input Files and Gathering their Information"<<endl;
	while (!infile.eof())
	{
		cout<<"test"<<endl;
		infile>>dataword;
		getline(infile,dataline);
				
		vcx.id=dataword;
		cout<<dataword<<endl;
		// convert dataline to vector coordinates
		istringstream datalines(dataline);
		while(datalines>>datanum)
		{
			//numcoord=stoi(datanum);
			numcoord=stod(datanum);
			cout<<datanum<<endl;
			(vcx.coordinate).push_back(numcoord);
		}
		vector_list.push_back(vcx);//vector_list includes the data from the input file;
		
		(vcx.coordinate).clear();
	}
	
	infile.close();
	
	return vector_list;
}

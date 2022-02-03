#include "../include/metrics.h"
using namespace std;

double min_three(double x1, double x2, double x3){
	int min=x1;
	if(x1<=x2 && x1<=x3){
		min=x1;
	}
	else if(x2<=x1 && x2<=x3){
		min=x2;
	}
	else{
		min=x3;
	}
	return min;
}
double euclidean(std::vector<double> x, std::vector<double> y) {
    int i,dim;
    double sum=0;
    dim= x.size();
    for(int i=0; i<dim; i++){
        sum+=pow(std::abs(x[i]-y[i]),dim);
    }
    return std::sqrt(sum);
}
//dtw=dynamic time warping
double dtw(vector<vector<double>> c,vector<vector<double>> p ){
	double sum=0;
	double d=0;

	vector<vector<double>> maxv,minv;
	vector<double> dist;
	if(c.size()>=p.size())
	{
		maxv=c;
		minv=p;
	}
	else
	{
		maxv=p;
		minv=c;
	}

	for(unsigned int i=0;i<maxv.size();i++){
		for(unsigned int j=0;j<minv.size();j++){
			if(i==0 && j==0 ){
				d=euclidean(maxv[i],minv[j]);
				dist.push_back(d);
			}
		 else if(i==(maxv.size()-1) && j==(minv.size()-1)){
			 d=euclidean(maxv[i],minv[j]);
			 dist.push_back(d);
			}
			//check the minimum distance between (i-1,j),(i-1,j-1),(i,j-1)
			else{
				if(i==0){
					continue;
				}
				else if(j==0){
						continue;
				}
				else{
					d=min_three(euclidean(maxv[i-1],minv[j]),euclidean(maxv[i-1],minv[j-1]),euclidean(maxv[i],minv[j-1]));
					dist.push_back(d);
				}
			}
		}
	}
	for(unsigned int k=0;k<dist.size();k++){
		sum+=dist[k];

	}
	std::cout << "DTW SUM: " << sum << '\n';
	return sum;
}

double manhattan_distance(vector < double > c,vector < double > p)
{
	double sum=0;
	//compare every dimensions distance between the two vectors
	for (unsigned int i=0; i<(c.size());++i)
	{
		//std::cout<<vl->coordinate[i]<<" space "<<ql->coordinate[i]<<" sum "<<sum<<std::endl;
		//Manhattan distance is : dist = sum of abs(xi -yi)
		sum=sum+abs(c[i] - p[i]);
    }
	//cout<<"sum is:"<<sum<<" and sum squared is "<< sum*sum <<endl;
	return sum;
}

int nearest_neighbor_vec(list< vecter > input_vectors_list,list< vecter > query_vectors_list)
{
	std::string vl_id,nvl_id;
	std::list<struct _vecter_>::iterator vl,ql;

	int count=0,nearest_dist_V=0,R=0;
	double nearest_dist=100000000;

	ql=query_vectors_list.begin();// our query is the first (and only) vector in its list
	for(vl=input_vectors_list.begin(); vl!=input_vectors_list.end(); ++vl)
	{
		double sum=0;
		count++;
		//compare every dimensions distance between the two vectors
		for (unsigned int i=0; i<(vl->coordinate.size());++i)
		{
			//std::cout<<vl->coordinate[i]<<" space "<<ql->coordinate[i]<<" sum "<<sum<<std::endl;
			//Manhattan distance is : dist = sum of abs(xi -yi)
			sum=sum+abs(vl->coordinate[i] - ql->coordinate[i]);
		}
		cout<<"vector "<<count<< " distance in double manhattan is: "<<sum<<endl;
		if(sum<nearest_dist&&sum>0)//nearest neighbour
		{
			nearest_dist=sum;
			nearest_dist_V=count;
			nvl_id=vl->id;
		}
		if(sum<=R)//within radius
		{
			vl_id=vl->id;
			//std::cout<<"vector "<<count<<" "<<vl_id<<" is within R with a distance of "<<sum<<std::endl;

			//outfile<<vl_id<<" ";
		}

	}

	std::cout<<"vector number "<<nearest_dist_V<<" is the nearest to the query with a Manhattan distance of "<<nearest_dist<<std::endl;

	return 0;
}

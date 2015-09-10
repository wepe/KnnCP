#include "utils.h"


//Euclidian distance
double eucDist(std::vector<double> x1,std::vector<double> x2){
	double dis;
	for(int i=0;i<x1.size();i++){
		dis += pow((x1[i]-x2[i]),2);
	}
	return sqrt(dis);
}

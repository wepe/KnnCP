#include "knn.h"
#include "utils.h"


Knn::Knn(int n_neighbours){
	k = n_neighbours;
}


int Knn::test(int inp){
	return inp+1;
}


void Knn::fit(std::vector<std::vector<double> > samples,std::vector<int> labels){
	//TO DO:check data first
	X = samples;
	y = labels;
	d = samples[0].size();
}

int Knn::predict(std::vector<double> sample){
	if(sample.size()!=d){
		throw "dimensionality size not match";
	} 
	
	/*
	In a multimap, the key values are generally used to sort 
	and uniquely identify the elements, while the mapped values
	store the content associated to this key.
	*/
	std::multimap<double, int>  disMap;//disMap<distance,index>
	for(int i=0;i<X.size();i++){
		double distance = eucDist(sample,X[i]);
		disMap.insert(std::pair<double,int>(distance,i));
	}
	
	std::multimap<double,int>::iterator iter = disMap.begin();
	std::map<int,int> votes;//votes<label,cnts>
	for(int i=0;i<k;i++,iter++){
		votes[y[iter->second]]++;
	}
	
	int major_label = 0;
	for(std::map<int,int>::iterator iter=votes.begin();iter!=votes.end();iter++){
		if(iter->second > votes[major_label]){
			major_label = iter->first;
		}
	}
	return major_label;
}


std::vector<double> Knn::predict_prob(std::vector<double> sample){
	if(sample.size()!=d){
		throw "dimensionality size not match";
	}
	
	std::multimap<double, int>  disMap;//disMap<distance,index>
	for(int i=0;i<X.size();i++){
		double distance = eucDist(sample,X[i]);
		disMap.insert(std::pair<double,int>(distance,i));
	}
	
	std::multimap<double,int>::iterator iter = disMap.begin();
	std::map<int,int> votes;//votes<label,cnts>
	for(int i=0;i<k;i++,iter++){
		votes[y[iter->second]]++;
	}
	
	std::multimap<int,double> labelMap;
	for(std::map<int,int>::iterator iter=votes.begin();iter!=votes.end();iter++){
		labelMap.insert(std::pair<int,double>(iter->first,iter->second/double(k)));
	}
	
	std::vector<double> probs;
	for(std::multimap<int,double>::iterator iter=labelMap.begin();iter!=labelMap.end();iter++){
		probs.push_back(iter->second);
	}
	return probs;
}




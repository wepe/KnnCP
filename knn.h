#ifndef KNN_H
#define KNN_H

#include<vector>
#include<cmath>
#include<map>


class Knn{
	private:
	std::vector<std::vector<double> > X;//samples
	std::vector<int> y;//samples' label
	int k;//
	int d;// the dimensionality of each sample
	
	public:
	Knn(int n_neigbours);
	int test(int inp);
	void fit(std::vector<std::vector<double> > samples,std::vector<int> labels);
	int predict(std::vector<double> sample);
	std::vector<double> predict_prob(std::vector<double> sample);//return probability of each label for sample
};

#endif
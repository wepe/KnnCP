#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "knn.h"

using namespace std;


vector<int> load_y(const char* file){
	ifstream fin(file);
	string line;
	vector<int> y;
	int tmp;
	while(getline(fin,line)){
		stringstream ss(line);
		ss>>tmp;
		y.push_back(tmp);
	}
	return y;
}

vector<vector<double> > load_X(const char* file){
	ifstream fin(file);
	string line;
	vector<vector<double> > X;
	while(getline(fin,line)){
		stringstream ss(line);
		vector<double> x;
		double tmp;
		while(!ss.eof()){
			ss>>tmp;
			x.push_back(tmp);
		}
		X.push_back(x);
	}
	return X;
}




int main(){
	const char* filex = "X.dat";
	const char* filey = "y.dat";
	vector<vector<double> > X = load_X(filex);
	vector<int> y = load_y(filey);
	
	//train a model
	Knn clf = Knn(5);
	clf.fit(X,y);
	
	//predict x1 whose size is not match
	vector<double> x1;
	for(int i=0;i<4;i++){
		x1.push_back(double(i));
	}
	
	try{
		cout<<clf.predict(x1)<<endl;
	}catch(const char* msg){
		cout <<msg<<endl;
	}
	
	//predict x2
	vector<double> x2;
	for(int i=0;i<5;i++){
		x2.push_back(double(i));
	}
	
	cout<<clf.predict(x2)<<endl;
	
	vector<double> res = clf.predict_prob(x2);
	for(vector<double>::iterator iter=res.begin();iter!=res.end();iter++){
		cout<<*iter<<" ";
	}
	
	return 0;
}
%module knn

%{
#include "knn.h"
%}

%include "stl.i"
%include "std_vector.i"
%include std_pair.i
%include std_map.i
%include std_multimap.i
namespace std {
  %template(VecDouble) vector<double>;
  %template(VecVecdouble) vector< vector<double> >;
  %template(IntMap) map<int,int>;
  %template(IntMultimap) multimap<int,double>;
  %template(DoubleMultimap) multimap<double,int>;
}


%include "knn.h"






/*
swig -c++ -python knn.i (generate knn_wrap.cxx)
g++ -O2 -fPIC -c knn.cpp utils.cpp knn_wrap.cxx -I /usr/include/python2.7/
g++ -O2 -shared knn.o knn_wrap.o utils.o -o  _knn.so
*/
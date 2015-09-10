###C++ implement of KNN and Python binding (a practice)


- `knn.h`,`knn.cpp`
- `utils.h`,`utils.cpp`
- `main.cpp`
- `makefile`, compile and generate `main`
- `knn.i`,use swig to wrap c++ for python. ( **still some bug to fix**)

	- https://github.com/swig/swig/tree/master/Examples/python

	- http://www.swig.org/Doc3.0/SWIGDocumentation.html#SWIGPlus_class_extension
	- other tools:  ctypes,cython

- `X.dat`,`y.dat`，data file.


###TO DO

- apply Eigen matrix instead of  " vector<vector<> > "

- task parallelism (mainly the `predict` method).
- KDTree

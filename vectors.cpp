// Lab9_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++0x
// Example: g++ Lab9_vectors.cpp -o Lab9_vectors -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a template

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;

// ***********************************************************************
	// Try all the ways to initializa a vector shown in Table 3.4. Use the
	// vectors above and/or declare new vectors.
	// Some of those operations have already been used, but write your
	// own examples.

		vector<int> jvec1(3), jvec2;
//		vector<double> dvec11{1.1}, dvec22(4,1.2),dvec3(dvec2),dvec4,dvec5{1,2,3,4,5,4,3,2,1},dvec6={1,2,3,4,5};
//		vector<string> svec1 = {"Table 3.4", "have 7 different ways to initialize a vector"};
//		for(auto i:svec1)
//			cout <<"shouing initilized vectors"<< svec1 << endl;
//		cout << "\n------------------------------------------------------------------" << endl;
//
		for(auto i:jvec2)
			cout<<jvec2 << endl;
		cout << "\n------------------------------------------------------------------" << endl;
		for(auto i:dvec11)
			cout<<dvec11 << endl;
		cout << "\n------------------------------------------------------------------" << endl;
		for(auto i:dvec22)
			cout<<dvec22 << endl;
		cout << "\n------------------------------------------------------------------" << endl;
		for(auto i:dvec3)
			cout<<dvec3	<< endl;
		cout << "\n------------------------------------------------------------------" << endl;
		for(auto i:dvec4)
			cout<<dvec4 << endl;
		cout << "\n------------------------------------------------------------------" << endl;
		for(auto i:dvec5)
			cout << dvec5 << endl;
		cout << "\n------------------------------------------------------------------" << endl;
		for(auto i:dvec6)
			cout << dvec6 << endl;
		cout << "\n------------------------------------------------------------------" << endl;
		for(auto i:svec1)
			cout << dvec4 << endl;
		cout << "\n------------------------------------------------------------------" << endl;

	// Do exercises 3.14 and 3.15 from Lippman (page 102)
	vector<int> vec;
	int i;
	while(cin>>i)
	{
		vec.push_back(i);
	}
	for(auto i:vec)
			cout << vec << endl;

	vector<string> vec1;
	string j;
	while(cin>>j)
	{
		vec1.push_back(j);
	}
	for(auto j:vec1)
			cout << vec1 << endl;

	// Try all the vector operations shown in table 3.5. Use the vectors above
	// or define new ones. Try different types.
	vector<string> vet;
	if(vet.empty())
		cout<<"vet is empty"<<endl;
	else
		cout<<"vet is not empty"<<endl;

	vector<double>vet1={1.1,2.1,3.1,4.1,5.1,6.1,7.1};
	cout<< "the size of vet1 contains 1 to 7 is:"<<vet1.size()<<endl;
	cout<<"vet1[3]  is :"<<vet1[3]<<endl;
	cout<<"push_back is in exercise3.14 and 3.15"<<endl;
	vector<double> vet2;
	vet2 = vet1;
	for(auto k:vec1)
			cout << vet2 << endl;
	if(vet1 == vet2)
		cout<<"vet1 == vet2 is true"<<endl;
	else
		cout<<"vet1 == vet2 is not true"<<endl;
	if(vet1 != vet2)
		cout<<"vet1 != vet2 is true"<<endl;
	else
		cout<<"vet1 != vet2 is not true"<<endl;
	if(vet1[0]>=vet2[0])
		cout<<"vet1[0]>=vet2[0] is true"<<endl;
	else
		cout<<"vet1[0]>=vet2[0] is not true"<<endl;
// ***********************************************************************

	return 0;
}


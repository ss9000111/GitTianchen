
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

class signal{
private:
	int i,length,max;
	int total,n;
	double average;
	int *data;//private members
	double average_data (){average = total/length; return average;};
//auxiliary methods
	void sig_info(){};
	//display length, max and average;
public:
	char name_in[20],name_out[20];
	signal();
	signal(int);
	signal(char*);//constructor, default,input an int,input an file name
	~signal();//destructor

	void filename(char*);
	void Offset(int);
	void Scale(double);
	void Center();
	void Nomalize();
	void Statistics();
	void save_file(char*);//to create a text file with current data
};
signal::signal(){
	length = average = max= 0;
	data = NULL;
	cout << "\nDefault constructor" << endl;
}
signal::signal(int num){
		sprintf(name_in,"Raw_data_%02d.txt",num);
		cout << "\n constructor taking file number: "<<name_in << endl;
}
signal::signal(char* file){

		cout << "\n constructor taking file name: " <<file<< endl;
}
signal::~signal(){
		delete[] data;
		cout << "\n Destructor " << endl;
}


/*void signal::Offset(int i);
void signal::Scale(double i);
void signal::Center();
void signal::Nomalize();
void signal::Statistics();*/
void signal::save_file(char* name){
	cout<<"the file will be saved as name of:"<<name<<endl;
	return;
}//to create a text file with current data






int main(int argc, char *argv[]) {
	using std::cout;
	using std::endl;
	cout << "Please enter the option 1.default constructor\n 2.constructor with input file number\n 3.constructor with input file name" << endl; // prints
	int input;
	char* filenameis;
	cin>>input;
	cout<< "the option you picked is number:"<<input<< endl;
	switch(input)
	{
	case 1:
	{
		cout <<"deafult constructor called"<<endl;
		signal signal1;
		//call default constructor
		break;//desructor called
	}
	case 2:
	{
		cout<<"please enter the file number you want to open"<<endl;
		cin>>input;
		signal signal2(input);		//call  constructor with input number
		break;//desructor called
	}
	case 3:
	{
		cout<<"please enter the file name you want to open"<<endl;
		cin>>filenameis;
		signal signal3(filenameis);
		break;//desructor called
	}
	default:
	{
		cout<<" invalid option please select from 1 to 3"<<endl;
		break;

	}
	}
	cout<<"please input the file name you want to save as:"<<endl;
	cin>>filenameis;
}

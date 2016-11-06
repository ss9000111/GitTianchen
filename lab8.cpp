#include <iostream>
#include <stdio.h>
#include <string>
// using library string
using namespace std;
string datastring = "abcdefghijklmnopqrstuvwxyz";
string moscodelib[26] = {".-","-...","-.-. "," -.. "," . "," ..-. "," --. "," .... "," .. "," .--- "," -.- "," .-.. "," -- "," -. "," --- "," .--. "," --.- "," .-. "," ... "," - "," ..- "," ...- "," .-- "," -..- "," -.-- "," --.."};
// --------- message class and methods ------------------------------
class message{
protected: // accessible by derived classes, not by other users.
string msg;
public:
message(); // default constructor.
message(string str); // parametric constructor
~message(); // destructor
void printinfo();
};

// Base class constructor
message::message(){
cout<< "default constructor"<<endl;
}
// Base class constructor
message::message(string str){
msg = str;
cout<< "parametic constructor"<<endl;
}

// Base class destructor
message::~message(){
cout << "destructor." << endl;
}

void message::printinfo() {
cout<<"the string you entered is:" <<msg<<endl;
}
 //------------------------------------------------------------------

 //--------- morsecodemessage class and methods ----------------------------
class morsecodemessage : public message{ // morsecodemessage is derived from class message is a public base class
protected:
string *mosecode;
public:
morsecodemessage();
morsecodemessage(string str);
~morsecodemessage();
// define new member function,called when initialization
void translate(string str);
// redefine member function
void printinfo();
};



// Derived class constructor.
morsecodemessage::morsecodemessage() : message() {
	mosecode = NULL;
cout<< "mosecodemessage default constructor"<<endl;
}

morsecodemessage::morsecodemessage(string str) : message(str) {
mosecode = new string[str.length()];
cout<< "you are entering  morsecode translator, the infor you entered and result will display"<<endl;

}
// Derived class destructor
morsecodemessage::~morsecodemessage() {
delete mosecode;
cout << "destructor for morsecodemessage" << endl;
}

// Redefined printInfo function for derived class
void morsecodemessage::printinfo(){
cout<<"the string you entered is:" <<msg<<endl<<"the morsecode translated is:"<<mosecode<<endl;

}
void morsecodemessage::translate(string str)
{
int i,j;
char *c;
j = str.length();
cout<<"string length is:"<<j<<endl;
//there should be a pointer to the datastring which is the library for alphabets. but char *c always give me error
cout<<"the morsecode translated is:"<<endl;
		for (i=0; i<j;i++)
		{
			size_t index = datastring.find(c);
		cout<< moscodelib[index];
		}
cout<<endl;
}


// --------- messageStack class and methods ------------------------------
class messagestack{
protected: // accessible by derived classes, not by other users.
int size,top;
int *stackPtr;
public:
messagestack(); // default constructor.
messagestack(string str); // parametric constructor
~messagestack(); // destructor
void push();
void pop();
void printstack();

};

// Base class constructor
messagestack::messagestack(){
cout<< "default constructor"<<endl;
}
// Base class constructor
messagestack::messagestack(string str){
cout<< "parametic constructor"<<endl;
}

// Base class destructor
messagestack::~messagestack(){
cout << "destructor." << endl;
}
void messagestack::push(){

}
void messagestack::pop(){

}
void messagestack::printstack(){

}



// Main function. A few examples
int main(){
	cout<<"You are entering morsecode converter, please follow instruction to continue"<<endl;
	cout<<"please enter a string (upper or lower case letters only )to conver to mosecode"<<endl;
string strr;
cin>>strr;
message message1(strr);
message1.printinfo();


cout<<"You are entering morsecode converter, please follow instruction to continue"<<endl;
cout<<"please enter a string (upper or lower case letters only )to conver to mosecode"<<endl;
cin>>strr;
morsecodemessage mosemsg(strr);
mosemsg.translate(strr);
mosemsg.printinfo();

return 0;
}

// Lab9_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	string s1, s2("Hello"), s3 = "World";
	cout << "\nEnter a word:" << endl;
	cin >> s1;

	string s4(s1);

	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;

	s1 = s2 + s3;
	cout << s1 << endl;

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
	string str1,str2(str1),str3=str2,str4("table 3.2 contain 14 ways of "),str5 = "Operation",str6(6,'s');
		cout << "\ntrying table 3.2\nEnter a string that will copy to str1,str2 and str3:" << endl;\
		cin>>str1;
		cout<<str1<<" "<<str2<<str3<<str4<<str5<<str6<<endl;



	cout<<"1. test1<<str1"<<endl;
		string test1;
		cout<<test1<<str1;

		cout<<"enter 2 different string "<<endl;
		cin>>test1>>str1;
	cout<<"2. test1>>str1 \n string1 is :"<<endl<<test1<<"\nand string2 is :"<<endl<<str1<<endl;

		string line;
	cout<<"3. get line"<<endl
		<< "Enter some text, finish it with an &" << endl;
		getline(cin, line, '&');
		cout << line << endl;
	cout<<"4. empty test testing empty string"<<endl;
		string test;
		if(test.empty()==1)
		cout<<"test1 empty"<<endl;
		else
		cout<<"test1 not empty"<<endl;
	cout<<"5. size of string str6(6,'s') is:"
		<<str6.size()<<endl;
	cout<<"6. string'operation', return str5[3] start from 0 (r):"<<endl
			<<str5[3]<<endl;
	cout<<"7. returns concatenation of s1 and s2"<<endl;
		test = str5+str6;
		cout<<test<<endl;
	cout<<"8. replace characters in test1 with copy of test"<<endl;
		test1 = test;
		cout<<test1<<endl;
	cout<<"9. test1 and test are contain same characters"<<endl;
			if(test1==test)
			cout<<"test1 equals to test which is \n"<<test1<<endl<<test<<endl;
			else
			cout<<"string test1 not same as test"<<endl;
	cout<<"10. equality is case_senstive"<<endl;
				tolower(test1[0]);
				if(test1!=test)
				cout<<"test1 not equals to test which is \n"<<test1<<endl<<test<<endl;
				else
				cout<<"string test1 same as test"<<endl;
	cout<<"11. comparisons, > < >= <= are case sensitive use dictionary ordering"<<endl;
				string test2(8,'a'),test3(7,'b'),test4 = "zaaaaa",test5 = "azzzzzzz";
				test=test2;

				if (test2<test3)
					cout<<"compairing b > a as dictionary said > or <,seems compairing only first digit"<<endl;
				else
					cout<<"compairing the length??"<<endl;
				if (test4>test5)
					cout<<"test 4 larger than test 5 as "<<test4<<">"<<test5<<endl;
				else
					cout<<"test4 is smaller than test5 as "<<test4<<"<"<<test5<<endl;
				if (test >= test2)
					cout <<"test = test2 as said"<<endl;
				else
					cout<<"error"<<endl;


// ***********************************************************************
// -----------------------------------------------------------------------

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
				/*cout<<"3. get line"<<endl
					<< "Enter some text, finish it with an &" << endl;
					getline(cin, line, '&');
					cout << line << endl;*/
cout<<"part 2 not allowed us C++98 mode but it should be correct because from book"<<endl;

	cout<<line<<endl<<"changing to upper case"<<endl;

	for (auto &c : line)
	{
		c = toupper(c);
	}
	cout<<line<<endl;
	cout<<"changing to lower case"<<endl;
	for(auto &c:line)
	{
		c= tolower(c);
	}
		cout<<line<<endl;
//


// 2) Replace any whitespace with a dot ('.').
		cout<<"changing whitespace to a dot";
		for(auto &c:line)
		{
			if(isspace(c))
				c = '.';
		}
			cout<<line<<endl;

// Print the converted text.
// ***********************************************************************

	return 0;
}

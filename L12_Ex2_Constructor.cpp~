

#include <iostream>
#include <cstring>

class Stock{
	private://private members
		char company[30];
		int shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val;}
		Stock acquire(const char*, int, double);
	public://public members

		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void display();
		// Constructors: same name as the class
		Stock();	// default, no arguments.
		Stock(const char*, int, double);
		Stock(const char*);
};

Stock::Stock(){
	company[0] = '\n';
	shares = 0;
	share_val = 0;
	set_tot();
}//set others zero
Stock Stock::acquire(const char * co, int n, double pr){
			std::strncpy(company, co, 29);
			this->company[29] = '\0';
			if(n < 0){
				std::cerr << "Number of shares can't be negative; "
						  << company << " shares set to 0.\n";
				this->shares = 0;
			}
			else{
				this->shares = n;
				std::cout << "\nUpdated shares." << std::endl;
			}
			this->share_val = pr;
			this->set_tot();
			return *this;
}// return "this" -->pointing "this" object
Stock::Stock(const char* co, int n, double pr){
	acquire(co, n, pr);
}//initialize stock
Stock::Stock(const char* co){
	acquire(co, 0, 0);
}//initialize stock


void Stock::display(){
	std::cout << std::endl << "Company: " << company << std::endl
			  << "Shares: " << shares << std::endl
			  << "Share value: " << share_val << std::endl
			  << "Total value: " << total_val << std::endl;
}

void Stock::update(double price)
{
share_val = price;
set_tot();
}
void Stock::buy(int num, double price)
{
double i=0;
i = num*price;
shares = shares + num;
total_val = total_val + i;
share_val = total_val / shares;
}//buying stock, without error control(negative numbers)
void Stock::sell(int num, double price)
{
double i=0;
i = num*price;
shares = shares - num;
total_val = total_val - i;
share_val = total_val / shares;
}//selling stock, without error control(negative shares)


int main(){
	using std::cout;
	using std::endl;

	Stock stock1("Nanosmart", 20, 12.50);
	stock1.buy(10,5);
	stock1.display();//result should be total 300 30 shares 10 each
	stock1.sell(10,5);
	stock1.display();//result should be 20 shares 12.5 each, total 250

	Stock stock2("Amazon", 30, 10);
	stock2.display();
	//aquire is private so can not be called
	//result should be total 300, 30 shares 10 each

	Stock stock3("ebay",20,10);//constructor
	stock3.display();

	Stock stock4("Yami food");
	stock4.display();
	//constructor, set others zero taken company name only
	return 0;
}


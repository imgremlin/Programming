#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> 
#define N 10

using namespace std;

class Edition{  
public:
  char* name;
  char* about;
  int price;
  int page;   
  int code; 
  
  public:   	
  Edition(){  
    name=new char[10];
	about=new char [20];  
    strcpy(name, "KaptainMorine");
	strcpy(about, "CoolBoy");
	price = 0;
	page = 0;
	code = 0;
	//printf("default Edition constructor\n");    
  	}
	  
  Edition(char *name1, char *about1, int price1, int page1, int code1){  
    name = new char[strlen(name1)+1];  
    strcpy(name, name1);
	about = new char[strlen(about1)+1];  
    strcpy(about, about1);
	price = price1;
	page = page1;
	code = code1;
	//printf("constructor Edition with parameters\n");
   
  }
  
  Edition(Edition &b){
        
        name= new char [strlen(b.name)+1];
        about= new char [strlen(b.about)+1];
        strcpy(name, b.name);
        strcpy(about, b.about);
        price=b.price;
		page=b.page;
		code = b.code;
		//printf("copy constructor Edition\n");     
    }
    
    ~Edition()
		{
			delete[] name;
			delete[] about;
			//printf("Destruction Edition\n");
		}
	
		void set_name(char *bk)
		{
			delete[] name;
			name = new char[strlen(bk) + 1];
				strcpy(name, bk);
		}
		void set_about(char *u)
		{
			delete[] about;
			about = new char[strlen(u) + 1];
				strcpy(about, u);
		}
		void set_price(int y)
		{
			price = y;
		}
		void set_page(int p)
		{
			page = p;
		}
		
		void set_code(int m)
		{
			code = m;
		}
		
		
		char *get_name()
		{
			return name;
		}
		char *get_about()
		{
			return about;
		}
		int get_price()
		{
			return price;
		}
		int get_page()
		{
			return page;
		}
		int get_code()
		{
			return code;
		}

		/*void full()
		{
			printf("Edition: %s about: %s price: %d number of pages: %d code: %d\n", name, about, price, page, code);
		}*/
			
		virtual void print(){
			printf("Edition: %s about: %s price: %d number of pages: %d code: %d\n", name, about, price, page, code);
		}
		
	bool operator == (const Edition &b){
	if((b.name==name)&&(b.about==about)&&(b.price==price)&&(b.page==page)&&(b.code==code)) return true;
	return false;
		}

	friend ostream& operator << (ostream &out , Edition &b){
				
				out<<"\nname of book: "<<b.name<< "\nabout: "<< b.about<<"\nprice: "<< b.price<<"\nnumber of pages: "<< b.page<<"\ncode of book: "<< b.code;
				return out;	
							}	
	
	friend istream& operator>>(istream &in , Edition &b){
				printf("Input info about book: \n");
				printf("name of book: ");
				in>>b.name;
				printf("smth about it: ");
				in>>b.about;
				printf("price: ");
				in>>b.price;
				printf("number of pages: ");
				in>>b.page;
				printf("book code: ");
				in>>b.code;
				return in;	
			}	
			
	friend Edition operator++(Edition &b){
	b.page+=1;
	return b;
}		
				
};

class Periodical: public Edition{
int period;
char* category;
int amount;
public:
Periodical(){  
    category=new char[25]; 
    strcpy(category, "CoolCategory");
	period=0;
	amount=0;
	//printf("default constructor Periodical\n");    
  	}
  	
Periodical(char *name2, char *about2, int price2, int page2, int code2, int period2, char* category2,  int amount2): Edition(name2, about2, price2, page2, code2){  
    category=new char[strlen(category2)+1];  
    strcpy(category, category2);
	period=period2;
	amount=amount2;
	//printf("constructor Periodical with parameters\n");
   }
   
Periodical(Periodical&b): Edition (b.get_name(), b.get_about(), b.get_price(), b.get_page(), b.get_code()){
		category= new char [strlen(b.category)+1];
        strcpy(category, b.category);
        amount=b.amount;
		period=b.period;
		//printf("copy constructor Periodical\n");
	
}
~Periodical(){
			delete[] category;
			//printf("Destruction Periodical\n");
		}
		
		char *get_category()
		{
			return category;
		}
		int get_period()
		{
			return period;
		}
		int get_amount()
		{
			return amount;
		}

		void set_period(int inv)
		{
			period = inv;
		}
		void set_category(char *ava)
		{
			delete[] category;
			category = new char[strlen(ava) + 1];
				strcpy(category, ava);
		}
		
		void set_amount(int co)
		{
			amount = co;
		}

	void print(){
		Edition::print();
		printf("period: %d category: %s amount: %d", period, category, amount);
	}
	
	friend Periodical operator+=(Periodical &a, Periodical &b){
	a.amount+=b.amount;
	return a;
		}
		
	friend bool operator<(Periodical &a, Periodical &b){
	if (a.amount<b.amount) return true;
	return false;
}	
	
};	

class Book: public Edition{
char* format;
char* type;
public:
Book(){  
    type=new char[25]; 
    strcpy(type, "Wool");
	format=new char[25]; 
    strcpy(format, "Usual");
	//printf("default constructor Book\n");    
  	}
  	
Book(char *name3, char *about3, int price3, int page3, int code3, char *format3,  char *type3): Edition(name3, about3, price3, page3, code3){  
    type=new char[strlen(type3)+1];  
    strcpy(type, type3);
	format=new char[strlen(format3)+1];  
    strcpy(format, format3);
	//printf("constructor Book with parameters\n");
   }
   
Book(Book&b): Edition (b.get_name(), b.get_about(), b.get_price(), b.get_page(), b.get_code()){
		type= new char [strlen(b.type)+1];
        strcpy(type, b.type);
        format= new char [strlen(b.format)+1];
        strcpy(format, b.format);
		//printf("copy constructor Book\n");
	
}
~Book(){
			delete[] type;
			delete[] format;
			//printf("Destruction Book\n");
		}
		
		char *get_type()
		{
			return type;
		}
		char *get_format()
		{
			return format;
		}

		void set_type(char *avaa)
		{
			delete[] type;
			type = new char[strlen(avaa) + 1];
				strcpy(type, avaa);
		}
		
		void set_format(char *aka)
		{
			delete[] format;
			format = new char[strlen(aka) + 1];
				strcpy(format, aka);
		}


	void print(){
		Edition::print();
		printf("format: %s type: %s \n", format, type);
	}
	
	friend ostream& operator << (ostream &out , Book &b){
				
				out<<"\nname of book: "<<b.name<< "\nabout: "<< b.about<<"\nprice: "<< b.price<<"\nnumber of pages: "<< b.page<<"\ncode of book: "<< b.code<<"\nbook format: "<< b.format<<"\ntype of book: "<< b.type;
				return out;	
							}	
	
	friend istream& operator>>(istream &in , Book &b){
				printf("Input info about book: \n");
				printf("name of book: ");
				in>>b.name;
				printf("smth about it: ");
				in>>b.about;
				printf("price: ");
				in>>b.price;
				printf("number of pages: ");
				in>>b.page;
				printf("book code: ");
				in>>b.code;
				printf("type of book: ");
				in>>b.type;
				printf("book format: ");
				in>>b.format;
				return in;	
			}	
			
	bool operator == (const Book &b){
	if((b.format==format)&&(b.type==type)&&(b.name==name)&&(b.about==about)&&(b.price==price)&&(b.page==page)&&(b.code==code)) return true;
	return false;
		}
};	

class Dovidnik{
    	
    	char* name_dov;
    	Edition vidannya[N];
    	int amount;
    	public:
    		Dovidnik(){
    			name_dov=new char[20];
    			strcpy(name_dov, "none");
        		amount=0;
    			
			//	printf("default constructor Bibliotek\n");
			};
			
			
			
    		Dovidnik(int i, char n): amount(i) {
    			
				name_dov[0]=n;
			//	printf("constructor Shop with parameters\n");
        
			}
			
			~Dovidnik(){
			//	printf("destruction Shop\n");
			}
			void print_dov(){

        	cout<<name_dov<<"  "<<amount<<"  ";
        	for(int i=0;i<amount;i++){
				vidannya[i].print();
				cout<<endl;
			}
        	
        	}
        	
        	Edition& operator [](int index){
        		
        		return vidannya[index];
        		
			}
        	
    	
	};


int main()  
{    
	char *names;
	char *abouts;
	int prices;
	int codes;
	int pages;
	int periods;
	char* categories;
	int amounts; 
	char name_dov[20];
	int c;
	
	names = new char[255];
	abouts = new char[255];
	categories = new char[255];
	char *formats;
	char *types;
	formats = new char[255];
	types = new char[255];
	
	/*printf ("Editions are the same?\n");
	Edition ed1, ed2("KapitanMorine", "CoolBook", 99, 240, 001), ed3;
	cin>>ed3;
	cout<< "\nYou entered obj3: " << ed3 << '\n';
	printf ("\n");
	ed1=ed2;
	if (ed3==ed2) printf ("These objects ed3 and ed2 are the same\n");
	else printf ("These objects ed3 and ed2 aren`t the same\n");
	if (ed1==ed2) printf ("These objects ed1 and ed2 are the same\n");
	else printf ("These objects ed1 and ed2 aren`t the same\n");
	printf ("\n");
	
	printf ("\nPeriodical <>\n");
	Periodical per1("aaa", "bbb", 299, 100, 001, 2, "book", 12), per2("aaa", "bbb", 299, 101, 002, 3, "book", 13);
	if (per1<per2) printf ("The amount of the per2 is more than the per1\n");
	else if (per1<per2) printf ("The amount of the bi1 is more than the bi2\n");
	else printf ("per1 and per2 amount are equal\n");
	
	printf ("\nPeriodical ++\n");
	++ed2;
	ed2.full();
	
	printf ("\nPeriodical +=\n");
	Periodical per3("aaa", "bbb", 299, 100, 001, 2, "book", 12), per4("aaa", "bbb", 299, 100, 001, 2, "book", 10), per5;
	per3+=per4;
	per3.print();*/
					
	Edition ed1, ed2("KapitanMorine", "CoolBook", 99, 240, 001), ed3;
	Periodical per1("aaa", "bbb", 299, 100, 001, 2, "book", 12), per2("aaa", "bbb", 299, 101, 002, 3, "book", 13);
	Edition ed5;
	
	Edition *e[3];
	e[0]=new Edition;
	e[1]=new Periodical;
	e[2]=new Book;
	
	for (int i=0; i<3;i++){
		e[i]->print();
		cout<<endl<<endl;
	}
					
  return 0;  
  }

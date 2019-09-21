#include<string.h>  
#include<stdio.h>  
#include<math.h>   

class Edition{  
private:
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
	printf("default Edition constructor\n");    
  	}
	  
  Edition(char *name1, char *about1, int price1, int page1, int code1){  
    name = new char[strlen(name1)+1];  
    strcpy(name, name1);
	about = new char[strlen(about1)+1];  
    strcpy(about, about1);
	price = price1;
	page = page1;
	code = code1;
	printf("constructor Edition with parameters\n");
   
  }
  
  Edition(Edition &b){
        
        name= new char [strlen(b.name)+1];
        about= new char [strlen(b.about)+1];
        strcpy(name, b.name);
        strcpy(about, b.about);
        price=b.price;
		page=b.page;
		code = b.code;
		printf("copy constructor Edition\n");     
    }
    
    ~Edition()
		{
			delete[] name;
			delete[] about;
			printf("Destruction Edition\n");
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

		void full()
		{
			printf("Edition: %s about: %s price: %d number of pages: %d code: %d\n", name, about, price, page, code);
			printf("\n");
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
	printf("default constructor Periodical\n");    
  	}
  	
Periodical(char *name2, char *about2, int price2, int page2, int code2, int period2, char* category2,  int amount2): Edition(name2, about2, price2, page2, code2){  
    category=new char[strlen(category2)+1];  
    strcpy(category, category2);
	period=period2;
	amount=amount2;
	printf("constructor Periodical with parameters\n");
   }
   
Periodical(Periodical&b): Edition (b.get_name(), b.get_about(), b.get_price(), b.get_page(), b.get_code()){
		category= new char [strlen(b.category)+1];
        strcpy(category, b.category);
        amount=b.amount;
		period=b.period;
		printf("copy constructor Periodical\n");
	
}
~Periodical(){
			delete[] category;
			printf("Destruction Periodical\n");
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
		Edition::full();
		printf("period: %d category: %s amount: %d \n", period, category, amount);
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
	printf("default constructor Book\n");    
  	}
  	
Book(char *name3, char *about3, int price3, int page3, int code3, char *format3,  char *type3): Edition(name3, about3, price3, page3, code3){  
    type=new char[strlen(type3)+1];  
    strcpy(type, type3);
	format=new char[strlen(format3)+1];  
    strcpy(format, format3);
	printf("constructor Book with parameters\n");
   }
   
Book(Book&b): Edition (b.get_name(), b.get_about(), b.get_price(), b.get_page(), b.get_code()){
		type= new char [strlen(b.type)+1];
        strcpy(type, b.type);
        format= new char [strlen(b.format)+1];
        strcpy(format, b.format);
		printf("copy constructor Book\n");
	
}
~Book(){
			delete[] type;
			delete[] format;
			printf("Destruction Book\n");
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


	void print1(){
		Edition::full();
		printf("format: %s type: %s \n", format, type);
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
	
	int c;
	
	names = new char[255];
	abouts = new char[255];
	categories = new char[255];
	char *formats;
	char *types;
	formats = new char[255];
	types = new char[255];
	
	printf ("choose tha class: 1.Periodical 2.Book");
	scanf ("%d", &c);
	
	switch (c)
		{
			case 1:
				{
					Periodical obj1;
					obj1.print();
					printf("Enter name of Periodical Edition, smth about it, price, number of pages, code, period, categories, amount:\n");  
				    scanf("%s %s %d %d %d %d %s %d", names, abouts, &prices, &pages, &codes, &periods, categories,  &amounts);
				    Periodical obj2(names, abouts, prices, pages, codes, periods, categories, amounts);
				    Periodical obj3=obj2;
				    printf("\n This is obj3 as copy obj2 \n");
					obj3.print();
					printf("\n Enter new name of Edition obj3, smth about it, price, number of pages and its code:\n");
					scanf("%s %s %d %d %d", names, abouts, &prices, &pages, &codes);
				    obj3.set_name(names);
					obj3.set_about(abouts);
					obj3.set_price(prices);
					obj3.set_page(pages);
					obj3.set_code(codes);
					printf("\n This is obj3 after change\n");
					obj3.print();
					break;}

				case 2:
				{
					Book obj4;
					obj4.print1();		
					printf("Enter name of Book Edition, smth about it, price, number of pages, code, format, type:\n");  
					scanf("%s %s %d %d %d %s %s", names, abouts, &prices, &pages, &codes, formats, types);
					Book obj5(names, abouts, prices, pages, codes, formats, types);
					Book obj6=obj5;
					printf("\n This is obj6 as copy obj5 \n");
					obj6.print1();
					printf("\n Enter new name of Edition obj3, smth about it, price, number of pages and its code:\n");
					scanf("%s %s %d %d %d", names, abouts, &prices, &pages, &codes);
					obj6.set_name(names);
					obj6.set_about(abouts);
					obj6.set_price(prices);
					obj6.set_page(pages);
					obj6.set_code(codes);
					printf("\n This is obj3 after change\n");
					obj6.print1();
					break;}
				
				default:	printf("wrong number");}
					
  return 0;  
  }

#include<string.h>  
#include<stdio.h>  


class Publisher{  

private: 
  char *name;
  char *address;
  char *phone;    
  
  
  public:  
 Publisher(){  
 name = new char[20];
 address = new char [20];
 phone = new char [20];  
 strcpy(name, "Frederik");
 strcpy(address, "Osinnya 33");
 strcpy(phone, "4747474774");    
  }   
  
  
   Publisher(char*title1, char*title2, char*title3){  
    name = new char[strlen(title1)+1];  
    strcpy(name, title1);
 address = new char[strlen(title2)+1];  
    strcpy(address, title2);
 phone = new char[strlen(title3)+1];  
    strcpy(phone, title3);        
  }
  
  
Publisher(Publisher &a){    
    name = new char[strlen(a.name)+1];  
    strcpy(name, a.name);
 address = new char[strlen(a.address)+1];  
    strcpy(address, a.address);  
    phone = new char[strlen(a.phone)+1];  
    strcpy(phone, a.phone);
    }
   
   
~Publisher(){ 
 if (name) delete[] name;
 if (address) delete[] address;
 if (phone) delete[] phone;
 printf("destructed\n");
};
  
  
void set_name(char*title1){
  delete[] name;   
  name = new char[strlen(title1)+1];  
  strcpy(name, title1);    
}; 


void set_address(char*title2){    
  delete[] address; 
  address = new char[strlen(title2)+1];
  strcpy(address, title2);  
};  


void set_phone(char*title3){
  delete[] phone;    
  phone=new char[strlen(title3)+1];  
  strcpy(phone, title3);    
}; 
  
  
char* get_name(){return name;};
char* get_address(){return address;};  
char* get_phone(){return phone;};


void print(){  
  printf("name of company: %s; address of company: %s; company phone: %s;\n", name, address, phone);  
}

};


class Ediition{  


private:
  char* edit;
  char* about;
  int price;
  int pages;
  int code;
  Publisher About;    
  
  
  public:     
  Ediition(){  
    edit=new char[20];
 about=new char [20];  
    strcpy(edit, "Edition name");
 strcpy(about, "Smthng about ediition");
 price=0;
 pages=0;
 code = 0;   
   }
   
   
  Ediition(char *edit1, char *about1, int price1, int pages1, int code1, Publisher& About1):About(About1){  
  
    edit = new char[strlen(edit1)+1];  
    strcpy(edit, edit1);
 about = new char[strlen(about1)+1];  
    strcpy(about, about1);
 price = price1;
 pages = pages1;
 code = code1;
     
  }
  
  
  Ediition(Ediition &b):About(b.About){
        
        edit = new char [strlen(b.edit)+1];
        about = new char [strlen(b.about)+1];
        strcpy(edit, b.edit);
        strcpy(about, b.about);
        price = b.price;
  pages = b.pages;
  code = b.code;    
    }
    
    
~Ediition()
  {
   if (edit) delete[] edit;
   if (about) delete[] about;
   printf("destructed\n");
  }
  
  
 void set_name(char *nm)
  {
   About.set_name(nm);
  }
 
 
 void set_address(char *sm)
 {
  About.set_address(sm);
 } 
 
 void set_phone(char *pn)
 {
  About.set_phone(pn);
 } 
 
 void set_edit(char *bk)
 {
  delete[] edit;
  edit = new char[strlen(bk) + 1];
  strcpy(edit, bk);
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
 
 
 void set_pages(int p)
 {
  pages = p;
 }
 
 
 void set_code(int c)
 {
  pages = c;
 }
 
  
  char *get_edit()
  {
   return edit;
  }
  
  
  char *get_about()
  {
   return about;
  }
  
  
  int get_price()
  {
   return price;
  }
  
  
  int get_pages()
  {
   return pages;
  }
  
  int get_code()
  {
   return code;
  }

  void short_output()
  {
   printf("edition: %s; publisher: %s; address: %s; phone: %s; \n", edit, About.get_name(), About.get_address(), About.get_phone()); 
  }
  
  
  void full_output()
  {
   printf("edition: %s; about: %s; price: %d; amount of pages: %d; code of paper: %d;", edit, about, price, pages, code);
   About.print();
   printf("\n");
  }
  
}; 


int main()  
  {    
  
  char *Nm;
  char *Sm;
  char *Ph;
  
  Nm = new char[25]; 
  Sm = new char[10];  
  Ph = new char[10]; 
  
  printf("enter publisher, address and phone:\n");  
  scanf("%s %s %s",Nm,Sm, Ph);
  Publisher A (Nm, Sm, Ph);
  int c;
  
  printf("do you want to print publisher?(no - 0, yes - 1)\n");

  scanf("%d", &c);
  if (c == 1)
  {
  A.print();
  printf("\n");
 }
 
  char *edit;
  int prices;
  int pages;
  int codes;
  char *about;
 edit = new char[255];
 about = new char[255];
 printf("enter name of edition, smth about it, code of paper, price and number of pages:\n");  
    scanf("%s %s %d %d %d", edit, about, &codes, &prices, &pages);
    
    Ediition Ediition1 (edit, about, codes, prices, pages, A);
    
    printf("print full or short list?(0/1)\n");
 int in;
 scanf("%d", &in);
 
 
 switch(in)
 {
  case 0:
  {
   Ediition1.full_output();
   break;
  }
  case 1:
  {
   Ediition1.short_output();
   break;
  }
  default:
   printf("reenter number\n");
  
 }
 
 
 printf("do u want to change smth?(no-0 / yes-1)\n");
 scanf("%d", &c);
 
 if (c == 1)
 {
  printf("1 - in publisher\n2 - in edition\n");
  scanf("%d", &in);
  if (in == 1)
  {
   printf("what do u want to change:\n 0 - name\n 1 - address\n 2 - phone\n");
   scanf("%d", &in);
   switch(in)
   {
    case 0:
    {
     printf("input: ");
     char *new_name;
     new_name = new char[255];
     scanf("%s", new_name);
     Ediition1.set_name(new_name);;
     break;

    }
    case 1:
    {
     printf("input: ");
     char *new_name;
     new_name = new char[255];
     scanf("%s", new_name);
     Ediition1.set_address(new_name);
     break;
    }
    case 2:
    {
     printf("input: ");
     char *new_name;
     new_name = new char[255];
     scanf("%s", new_name);
     Ediition1.set_phone(new_name);
     break;
    }      
   }
  }
  else if (in == 2)
  {
   printf("what do u want to change:\n 0 - edition name \n 1 - smth about edition\n 2 - code of paper \n 3 - price \n 4 - number of pages\n");
   scanf("%d", &in);
   switch(in)
   {
    case 0:
    {
     printf("input: ");
     char * new_name;
     new_name = new char[255];
     scanf("%s", new_name);
     Ediition1.set_edit(new_name);
     break; 
    }
    case 1:
    {
     printf("input: ");
     char * new_name;
     new_name = new char[255];
     scanf("%s", new_name);
     Ediition1.set_about(new_name);
     break;
    }
    
    case 2:
    {
     printf("input: ");
     int y;
     scanf("%d", &y);
     Ediition1.set_code(y);
     break;
    }
    
    case 3:
    {
     printf("input: ");
     int y;
     scanf("%d", &y);
     Ediition1.set_price(y);
     break;
    }
    
    case 4:
    {
     printf("input: ");
     int p;
     scanf("%d", &p);
     Ediition1.set_pages(p);
     break;
    }
   }
  }
 }
 
printf("print full or short list?(0/1)\n");
 scanf("%d", &in);
 
 
 switch(in)
 {
  case 0:
  {
   Ediition1.full_output();
   break;
  }
  case 1:
  {
   Ediition1.short_output();
   break;
  }
  default:
   printf("reenter number\n");
  
 }
  
  return 0;  }

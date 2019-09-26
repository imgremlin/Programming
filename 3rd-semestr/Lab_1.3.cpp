#include<string.h>  
#include<stdio.h>  
#include<math.h>
#include<iostream>
#include<stdlib.h>  

using namespace std;

enum Appointment{
	RESERVED,
	FOR_SILGOSP,
	UNDER_CONST
};

class Owner{  

private:
  	string name;
  	string surname;  
	string date; 
  
public:   	
Owner(){   
    name = "own name";
	surname = "own surn";
	date = "01.01.2001"; 
}
	  
Owner(string name1, string surname1, string date1){  
    name= name1;
	date = date1;
    surname= surname1; 
}
  
Owner(Owner &b){    
    name = b.name;
    surname = b.surname;
    date = b.date;   
}
    
~Owner(){}
	
Owner& set_name(string bk){
	name= bk;
	return *this;
}

Owner& set_surname(string u){
	surname= u;
	return *this;
}

Owner& set_date(string m){
	date= m;
	return *this;
}
	
string get_name(){
	return name;
}

string get_surname(){
	return surname;
}

string get_date(){
	return date;
}

void print(){
	cout<<"Owner`s name: "<<name<< endl<< "Owner`s surname: "<<surname<<endl<< "Owner`s date: "<<date<<endl;
}
};


class Description{
private:
	string ground_type;
	int ground_level;
	int *array;
	int Des_size;

public:

Description(){   
    ground_type= "Glina";
	ground_level = 50;
	
	array=new int[1];
    int temp;
    array[0]=temp;
    Des_size=1; 
}
  	
Description(string ground_type2, int ground_level2, int *a, int s){  
    ground_type = ground_type2;
	ground_level = ground_level2;
	Des_size=s;    
    array = new int[s];
    for (int i=0; i<s; i++){
		cout<<"input arr["<<i<<"]:";
		cin>>array[i];
		}
}
   
Description(Description&b){
    ground_type= b.ground_type;
    ground_level = b.ground_level;
    
    Des_size=b.Des_size;  
    array = new int[Des_size];
    
    //for (int i=0; i<Exp_size; i++){
//		cout<<"input arr["<<i<<"]:";
//		cin>>array[i];
//	}
}

~Description(){
	if (array) delete[] array;
}
		
int get_ground_level(){
	return ground_level;
}

string get_ground_type(){
	return ground_type;
}

int *get_des(){
	return array;
}

int get_size(){
	return Des_size;
}

Description& set_des(int *a, int s){
	Des_size = s;
	delete[] array;
	array = new int[s];
	for (int i=0; i<s; i++){
		cout<<"input arr["<<i<<"]:";
		cin>>array[i];
	}
	return *this;
}

Description& set_ground_level(string ava){
	ground_type = ava;
	return *this;
}


Description& set_ground_type(int co){
	ground_level = co;
	return *this;
}


void print(){
	cout<<"Ground type: " << ground_type << endl <<"Ground level: " << ground_level << endl;
	cout<<"Dscrptn array:";
	for (int i=0; i<Des_size; i++)
		cout<<array[i]<<' ';
		
}
};




class Zem_dil{
	
	Owner F;
	int price;
	Appointment P;

public:
	Description A;
	
Zem_dil(){
	P=RESERVED; 
	price=2222;  
}
  	
Zem_dil(Owner f, Description a, int price2, Appointment p){
	F=f;
	A=a;
	price=price2;
	P=p;
}
   
Zem_dil(Zem_dil&b){
	F=b.F;
	A=b.A;
	price=b.price;
	P=b.P;
}

~Zem_dil(){}
		
int get_price(){
	return price;
}

Appointment& get_P(){
	return P;
}

Owner& get_F(){
	return F;
}

Description& get_A(){
	return A;
}

Zem_dil& set_price(int pr){
	price = pr;
	return *this;
}

Zem_dil& set_P(Appointment p){
	P=p;
	return *this;
}

Zem_dil& set_F(Owner f){
	F=f;
	return *this;
}

Zem_dil& set_A(Description a){
	A=a;
	return *this;
}

void print(){
	cout<<"Owner`s srnm: "<<F.get_surname()<<endl;
	cout <<"Price: " << price << endl;
	if (P==0)
	cout << "Appointment: RESERVED"<< endl;
	if (P==1)
	cout << "Appointment: FOR_SILGOSP"<< endl;
	if (P==2)
	cout << "Appointment: UNDER_CONST"<< endl;
	}
	
void full_print(){
	cout<<"Owner`s srnm: "<<F.get_surname()<<endl;
	cout<<"Owner`s nm: "<<F.get_name()<<endl;
	cout<<"Owner`s dt: "<<F.get_date()<<endl;
	cout<<"Desc ground level: "<<A.get_ground_level()<<endl;
	cout<<"Desc ground type: "<<A.get_ground_type()<<endl;
	cout <<"Price: " << price << endl;
	if (P==0)
	cout << "Appointment: RESERVED"<< endl;
	if (P==1)
	cout << "Appointment: FOR_SILGOSP"<< endl;
	if (P==2)
	cout << "Appointment: UNDER_CONST"<< endl;
	}	
};



class Punkt{  
	static int amount;
	Zem_dil *arr;
	int Zem_dil_size;   
private:int number;

public:   
	
Punkt(){  
    arr=new Zem_dil[1];
    Zem_dil temp;
    arr[0]=temp;
    Zem_dil_size=1;
 
}
	  
Punkt(Zem_dil*a, int s){
	Zem_dil_size=s;    
    arr = new Zem_dil[s];
    for (int i=0; i<s; i++){
		arr[i].set_F(a[i].get_F());
		arr[i].set_A(a[i].get_A());
		arr[i].set_price(a[i].get_price());
		arr[i].set_P(a[i].get_P());
	}
	
}
  
Punkt(Punkt &b){
	Zem_dil_size=b.Zem_dil_size;  
    arr = new Zem_dil[Zem_dil_size];
    for (int i=0; i<Zem_dil_size; i++){
		arr[i].set_F(b.arr[i].get_F());
		arr[i].set_A(b.arr[i].get_A());
		arr[i].set_price(b.arr[i].get_price());
		arr[i].set_P(b.arr[i].get_P());
	}
    
}
    
~Punkt(){
	if (arr) delete[] arr;	
	}
	
Zem_dil *get_zem_dil(){
	return arr;
}

int get_size(){
	return Zem_dil_size;
}

Punkt& set_zem_dil(Zem_dil *a, int s){
	Zem_dil_size = s;
	delete[] arr;
	arr = new Zem_dil[s];
	for (int i=0; i<s; i++){
		arr[i].set_F(a[i].get_F());
		arr[i].set_A(a[i].get_A());
		arr[i].set_price(a[i].get_price());
		arr[i].set_P(a[i].get_P());
	}
	return *this;
}


void print(){
	cout<<"Zem_dil size: "<<Zem_dil_size<<endl;
	for (int i=0;i<Zem_dil_size; i++){
		cout<<i+1<<". "; 
		arr[i].print();
		if (i!=Zem_dil_size-1) cout<<endl;
	}
}

Punkt& add(Zem_dil b){
	Zem_dil *temp = new Zem_dil[Zem_dil_size+1];
	for (int i=0; i<Zem_dil_size; i++){
		temp[i].set_F(arr[i].get_F());
		temp[i].set_A(arr[i].get_A());
		temp[i].set_price(arr[i].get_price());
		temp[i].set_P(arr[i].get_P());
	}
	temp[Zem_dil_size].set_F(b.get_F());
	temp[Zem_dil_size].set_A(b.get_A());
	temp[Zem_dil_size].set_price(b.get_price());
	temp[Zem_dil_size].set_P(b.get_P());
	
	delete[] arr;
	arr = new Zem_dil[Zem_dil_size+1];
	for (int i=0; i<Zem_dil_size; i++){
		arr[i].set_F(temp[i].get_F());
		arr[i].set_A(temp[i].get_A());
		arr[i].set_price(temp[i].get_price());
		arr[i].set_P(temp[i].get_P());
	}
	
	Zem_dil_size++;
	return *this;
}

};




int main(){
	
	Owner e1;
	e1.print();
	cout<<endl;
	
  	Description d1;
	d1.print();
	cout<<endl<<endl;
	int p,pl;
	cout<<"Enter price of zemelna dilyanka: ";
	cin>>p;
	cout<<"Enter place (RESERVED - 0, FOR_SILGOSP - 1, UNDER_CONST - 2) of Description: ";
	cin>>pl;
	Zem_dil ex2(e1, d1, p, RESERVED);
	switch(pl){
		case(1):{
			ex2.set_P(FOR_SILGOSP);
			break;
		}	
		case(2):{
			ex2.set_P(UNDER_CONST);
			break;
		}	
	}
	ex2.print();
	cout<<endl<<endl;
	
	int *ar = new int[10];
	int n;
	cout<<"Input size of array: ";
	cin>>n;
	Description e2("aaa",47 , ar, n);
	cout<<endl<<endl;
	cout<<"Descrpt print:"<<endl;
	e2.print();
	cout<<endl<<endl;
	Owner e3("Ivan", "Khropach", "4.07.1922");
	
	int *arr = new int[10];
	
	Description d3("Garniy grunt", 7, arr, 3);
	Zem_dil ex4;
	Zem_dil ex3(e3, d3, 999999, UNDER_CONST);
	
	Zem_dil *array = new Zem_dil[10];
	array[0] = ex3;
	cout<<endl<<endl;
	
	cout<<"Ex3 full print:"<<endl;
	ex3.full_print();
	cout<<endl<<endl;
	int rd=0;
	cout<<"ready?";
	cin>>rd;
	
	cout<<"Punkt print:"<<endl;
	Punkt p1(array, 1);
	
	p1.print();
	cout<<endl<<endl;
	
	cout<<"Punkt print + 1:"<<endl;
	p1.add(ex4);
	p1.print();
	cout<<endl<<endl;
	
	cout<<"Ex4 full print:"<<endl;
	ex4.full_print();
	cout<<endl<<endl;
	return 0;
}

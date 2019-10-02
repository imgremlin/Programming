#include <iostream>
#include <string>
#include <vector>   
#include <algorithm>

using namespace std; 

class Owner{  

private:
  	string name;
  	string surname;  
	int day;
	int month;
	int year; 
  
public:   	
Owner(){   
    name = "own name";
	surname = "own surn";
	day = 1;
	month = 1;
	year = 1920; 
}
	  
Owner(string name1, string surname1, int day1, int month1, int year1){  
    name= name1;
    surname= surname1; 
    day = day1;
    month = month1;
    year = year1;
}
  
Owner(const Owner &b){    
    name = b.name;
    surname = b.surname;
    day = b.day;
	month = b.month;
	year = b.year;   
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

Owner& set_day(int d){
	day = d;
	return *this;
}

Owner& set_month(int m){
	month= m;
	return *this;
}

Owner& set_year(int y){
	year= y;
	return *this;
}

	
string get_name(){
	return name;
}

string get_surname(){
	return surname;
}

int get_day(){
	return day;
}

int get_month(){
	return month;
}

int get_year(){
	return year;
}

void print(){
	cout<<"Owner`s name: "<<name<< endl<< "Owner`s surname: "<<surname<<endl<< "Owner`s date: "<<day<<'.'<<month<<'.'<<year<<endl;
}
};

	
			
			
int main() 
{ 
	vector<Owner> g1; 
	Owner aa;
	Owner a1("alex", "tsepa", 3,4,2001);
	
	g1.push_back(aa);
	g1.push_back(a1);
	
	string nm, srn;
	int d,m,y, count;
	cout<<"How many objects u wanna add: ";
	cin>>count;
	cout<<endl;
	
	for(int i=0; i<count; i++)
	{
		bool check = true;
		cout<<"Input Number "<<i+1<<endl;
		cout<<"Input name: ";
		cin>>nm;
		
		
		cout<<"Input surname: ";
		cin>>srn;
		
		
		cout<<"Input year: ";
		while (1)
		{
			cin>>y;
			if (y<g1[g1.size()-1].get_year())
				cout<<"Incorrect year, after: "<<g1[g1.size()-1].get_year()<< " ";
			else if (y==g1[g1.size()-1].get_year() )
			{
				check = false;
				break;
			}
			else break;	
			}
		
		
		cout<<"Input month: ";
		while (1)
		{
			cin>>m;
			if (check == true)
				break;
			else if (m<g1[g1.size()-1].get_month())
				cout<<"Incorrect month, after: "<<g1[g1.size()-1].get_month()<< " ";
			else if (m==g1[g1.size()-1].get_month())
				{
				check = false;
				break;
			}
			else break;
			}
				
				
		cout<<"Input day: ";
		while (1)
		{
			cin>>d;
			if (check == true)
				break;
			else if (d<=g1[g1.size()-1].get_day())
				cout<<"Incorrect day, after: "<<g1[g1.size()-1].get_day()<< " ";
			else
				break;
			}
		
		
		g1.push_back(Owner(nm, srn, d, m, y));
		cout<<endl;
	}
	
	cout<<"Queue size = "<<g1.size()<<endl<<endl;
	
	for(int i = 0; i < g1.size(); i++)
		{
			cout<<i+1<<". ";
	    	g1[i].print();
	    	cout<<endl;
			}
			
			
	char des = 'y';
	

	
	while (g1.size()>0 && des!='n')
	{
		
		cout<<"Do u wanna kick smb from queue? (Y/N): ";
		cin>>des;
		if (des == 'y')
		{
			reverse(g1.begin(), g1.end());
			g1.pop_back();
			reverse(g1.begin(), g1.end());
		}
			
		cout<<endl;
		for(int i = 0; i < g1.size(); i++)
		{
			cout<<i+1<<". ";
	    	g1[i].print();
	    	cout<<endl;
			}
	}
	
		
	return 0; 
	
}

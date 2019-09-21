#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Student{
	public:
    char *name;
    int age;
public:
    Student(){
    	name=new char [15];
    	strcpy(name, "unknown");
    	int age=0;
	}
	
    Student(const char* name_, int age_){
    name=new char[strlen(name_)+1];
    strcpy(name, name_);
    age = age_;
}
 
    const char* get_name() const {return name;}
    int    get_age()  const {return age; } 
    
    friend bool operator ==(const Student &obj1, const Student &obj2)
        {
            if (obj1.age == obj2.age)
                return true;
            return false;
        }
        
    friend ostream& operator << (ostream &out , Student &a){
			
			out<<"Name: "<<a.name<< " age: "<< a.age;
			return out;
		}
		
	friend bool operator>(Student &a, double n)
	{
		if (a.age>n) return true;
		return false;		
	}
	
	};

template < typename T > 
int Count(T a[], int n1)
{
	double n;
		
	int amount=0;
	cout<<"mass = ";
	for(int i=0; i<n1; i++) cout<<a[i]<<" ";
	cout<<endl<<"Input number: ";
	cin>>n;
	
	for(int i=0; i<n1; i++)
	{
		
		
		cout<<a[i]<<" > "<<n<<"  =  ";
		if(a[i]>n){amount++; cout<<"+";} else cout<<"-"; 
		cout<<endl;
	}
	
	
	cout<<"Amount of numbers: "<<amount;
}


int main()
{
	int arr[]={1,2,3,4,5,6,6};
	int n1=sizeof(arr)/sizeof(*arr);
	
    Student arrr[] = {  
        Student("Wasia", 162),
        Student("Petia", 12),
        Student("Olesa", 13)
    };
    int n2=sizeof(arrr)/sizeof(*arrr);
    
    Count(arrr, n2);
    return 0;
}

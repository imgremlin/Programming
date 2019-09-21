#include <iostream> 
#include <vector> 

using namespace std; 

template < typename T > 
int Minimum(vector<T>& g1)
{
	/*vector<int> g1; 
	double n;
	int size;
	
	cout<<"Input size of vector: ";
	cin>>size;
	cout<<"Input elements of vector: ";
	for (int i=0; i<size; i++)
	{	
		cin>>n;
		g1.push_back(n); 
	}*/
	cout << "Size : " << g1.size()<<endl;  
	cout<<"Array = ";
	for(int i=0; i<g1.size(); i++)
			cout<<g1[i]<<" ";
	int min = g1[0];
	int min_i = 0;
	for (int i=1; i<g1.size(); i++)
			if (g1[i]<min)
			{
				min = g1[i];
				min_i = i;
			}
			
	vector<int> del1; 		

	for(int i=0; i<g1.size(); i++)
		if (g1[i]==min)
		{
			del1.push_back(i);
			//cout<<"index = "<<i<<endl;
			//cout<<"size = "<<g1.size()<<endl;
			cout<<endl<<endl;			
			}
			//cout<<"del mass = ";		
	//for(int i=0; i<del1.size(); i++)
					//cout<<del1[i]<<" ";		
					
	//cout<<endl<<"del size = "<<del1.size();
	for (int i=0; i<del1.size(); i++)
		g1.erase (g1.begin()+del1[del1.size()-i-1]);
	
	cout<<endl<<"mass = ";
	for(int i=0; i<g1.size(); i++)
			cout<<g1[i]<<" ";
}

int main() 
{ 
	vector<float> g1; 
	g1.push_back(1.3);
	g1.push_back(2);
	g1.push_back(3);
	g1.push_back(1);
	g1.push_back(5);
	Minimum(g1);
		
	return 0; 
	
}

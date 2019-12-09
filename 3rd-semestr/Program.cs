using System;
using System.Threading;

namespace KP_3
{
	
	class Excursion
	{
	    public string place; // имя
	    public int cost;     // возраст
	 	
	    
	    
	   	public Excursion() { place = "Somewhere"; cost = 199; }
     
	   	
	   	
    	public Excursion(string n, int a) { place = n; cost = a; }
    
    	
    	
	    public void GetInfo()
	    {
	        Console.WriteLine("Place: {0}  Cost: {1}", place, cost);
	    }
	    
	    
	    
	    public static bool operator >(Excursion p1, Excursion p2)
	    {
	        return p1.cost > p2.cost;
	    }
	    
	    
	    
	    public static bool operator <(Excursion p1, Excursion p2)
	    {
	        return p1.cost < p2.cost;
	    }
	    
	   
	    
	    public override string ToString()
        {
            return "Place: " + place + " Cost: " + cost;
        }
	    
	    

	    public static Excursion operator +(Excursion p1, Excursion p2)
	    {
	    	if (p1.place == p2.place)
	    			return (p1 + p2);
	    	else return p1;
	    }
	    
	}
	
	class Show : Excursion
	{
	    public string name_;
	    public DateTime date;
	 	
	    public Show() { name_ = "Name"; date = DateTime.Now; place = "Somewhere"; cost = 1000; }
     
	    public Show(string n1, DateTime dt, string n2, int v) : base(n2,v) { name_ = n1; date = dt; }
	    
	    public override string ToString()
        {
	    	return "Title: " + name_ + "; Date: " + date.ToString("d") + "; Place: " + place + "; Cost: " + cost;
        }
	    
	    
	    public override bool Equals(object obj)  
	    {
	    	var p2 = (Show)obj;
	        return (place == p2.place && cost == p2.cost && date ==p2.date && name_ == p2.name_);  
	    }  
	    
	    
	    public override int GetHashCode()  
	    {  
	    	return place.GetHashCode() ^ cost.GetHashCode() ^ name_.GetHashCode() ^ date.GetHashCode();
	    }
	    
	    public static bool operator ==(Show p1, Show p2)
        {
	    	return p1.Equals(p2);
        }
	    
	    public static bool operator !=(Show p1, Show p2)
        {
	    	return !(p1==p2);
        }
	}
	
	
	class List
	{
		Show[] data;
		
		public List()
		{
			data = new Show[2];
		}
		
		public Show this[int index]
		{
			get
			{
				return data[index];
			}
			set
			{
				data[index]=value;
			}
		}
		
		public override string ToString()
        {
			for (int i=0;i<2; i++)
				Console.WriteLine(data[i]);
			
	    	return "";
        }
		
	}
	
	
	
	class Program
	{
		public static void Main(string[] args)
		{
			
			Excursion p1 = new Excursion() {place = "Lviv", cost = 1099};
			Excursion p2 = new Excursion();
			Console.WriteLine("Excursions:");
			Console.WriteLine(p1);
			Console.WriteLine(p2);
			Thread.Sleep(1500);
			if (p1 > p2)  
            Console.WriteLine("Excursions 1 cost more");  
        	else  
            Console.WriteLine("Excursions 2 cost more");
            
			DateTime dt1 = DateTime.Now;
			Thread.Sleep(1500);
	        Console.WriteLine ("\nOld date: "+dt1.ToString("d"));
	        
	        DateTime dt2 = dt1.AddDays(7);
	        Console.WriteLine ("New date: "+dt2.ToString("d"));
	        Thread.Sleep(1500);
	        Console.WriteLine("\nTour list:");
	        Show sh1 = new Show() {name_="First Excursion", date=dt2, place="Kyiv", cost=2099};
	        Show sh2 = new Show();
	        if (sh1 != sh2)  
            Console.WriteLine("Shows are not the same");  
        	else  
            Console.WriteLine("Shows are the same");	
	        List l = new List();
	        l[0] = sh1;
	        l[1] = sh2;
	        
	        Console.WriteLine(l);
			
			
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
string visited_list[100];
int f=1,num,cmp,l=0,lvl=-1,o=0;string dist[100];int limit=0;
string skip,word,start,end,conn_file,location_file,temp;
fstream conn_pointer,location_pointer;
int find_next_place(string);
int print(string [],int);
float get_distance(string first,string second);
int main()
{   
   
   	 //Opening file
    conn_file = "connections.txt";     
    conn_pointer.open(conn_file.c_str());
    location_file = "locations.txt";     
    location_pointer.open(location_file.c_str());
	
    //Getting user data
	cout << "enter the starting place";
    cin >> start;
    cout << "enter the ending place";
    cin >> end;
    
   
    
    // Recursive Function to find next place
   find_next_place(start);
   l=0;
   cout<<"\nThe end\n";
   
}
 int find_next_place(string tbf)
    {  
    
      conn_pointer.seekg(0, ios::beg);
      int count,z;
      string item[50];
      
      //comparing current node with end node
      if(end.compare(tbf)==0)
		    {   
		        visited_list[l]=tbf;l++;
		    	//cout<<"\n";
		    	for(int i=0;i<l;i++)
		    	{
		    		
		    		 dist[i]=visited_list[i];
		    		 
				}
				print(dist,l);
			  
		    	 goto br1;
	        }
	        
	     //adding the node to the path
		 visited_list[l]=tbf;
	     l++;    
       
	       
      	//finding the correct node in the connection document 
	    while (f)
      	{
			conn_pointer >> word;
            f--;
            if(word=="END")
            {
            	    f++;
            		goto br1;
			}
            if(word==tbf)
            {   
            	f++;
            	goto br;
			}
			else
			{   f++;
				getline(conn_pointer,skip);
			}    
        }
        br:
	    conn_pointer >> num;
     	count=num;
        	z=0;
        	
        //Retriving child node
	    while(count!=0)
	       {
		    conn_pointer >> word;
	     	item[z]=word;
	     	z++;
	     	count--;
	        }
       	count=num;
       	
     	//Sorting the child node
      	for(int i=0;i<count;i++)
	    for(int j=0;j<count;j++)
        	{
	    	cmp=item[i].compare(item[j]);
		   
	     	if(cmp==-1)
	        	{
		    	temp.swap(item[i]);
                item[i].swap(item[j]);
                item[j].swap(temp);
	        	}
        	} 
        count=num;	
       
	    for(int i=0;i<count;i++)
	    {    
	       string ad=item[i];
	       
	    //Checking whether the node is already visited
	       for(int k=0;k<l;k++)
	       {
	       	if(ad.compare(visited_list[k])==0)
	       	{
	       		goto re;
			   }
		   }
	   //recursion
	       find_next_place(ad);
	       l--;
	      
	       re:cout << "";
	       
	       
	    }
	    
           br1:
		   cout<< "";
        	
    }
        //Print function
   int print( string dis[],int length)
{   
     
    float total=0;
     string one,two;
   
   
   
   //  limit++;
     //if(limit>10)
     //{
     //	goto sd;
	 //}
     
	for(int i=0;i<length-1;i++)
	{   

	  one=dis[i];two=dis[i+1];
	 	 cout<< one <<" to "<< two <<" length is "<< get_distance(one,two)<<"\n";
		  total += get_distance(one,two); 
	}
	   cout << "Total path length is "<< total << "\n" << "\n";
		for(int i=0;i<length;i++)
		dis[i]="";
       
       //sd:cout<<"";
 }

    //Getting distance between two node
float get_distance(string first,string second)
{  
    f=1;
    location_pointer.seekg(0, ios::beg);
    int x,y,a,b,e,r,t,counter=0;
    float l;
    //Reading from locations
    while(f)
    {
    
     	location_pointer >> word;
	    
    if(word==first)
    {    
    	location_pointer >> x; 
		location_pointer >> y; 
    	counter++;
	}
	if(word==second)
	{    
		location_pointer >> a; 
		location_pointer >> b;
		counter++;
	}
	
	if(counter==2){
	 break;
}
}
	//Using Euclidean to calculate the distance between two nodes
	e=x-a;
	r=y-b;
	e=e*e;
	r=r*r;
	t=e+r;
	l=sqrt(t);
    return(l);
}




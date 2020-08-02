#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int num,count1=0,z=0,l=0,sum=0,f,o=1,store,t,avoid;
int mvalue,hvalue[100];
 
fstream conn_pointer,location_pointer;
string conn_file,location_file,end,start,word,item[100],vlist[100],one,two,temp,avoid_node[100];
string skip,tbv[100];

int stepbystep_straightline(string beg);
int get_distance(string first,string second);
int optimal_straightline(string tbf);
int main()
{    
    int choice;
	conn_file = "connections.txt";     
    conn_pointer.open(conn_file.c_str());
    location_file = "locations.txt";     
    location_pointer.open(location_file.c_str());
	
    //Getting user data
	cout << "Enter the starting place";
    cin >> start;
    cout << "Enter the ending place";
    cin >> end;
    cout<<"\nEnter the number of nodes that you dont want to go";
    cin>>avoid;
    if(avoid>0)
    cout<<"\nEnter the nodes\t";
    for(int i=0;i<avoid;i++)
    cin>>avoid_node[i];
    
   // cout<<"select any one \n \t 1)Straightline distance \n \t 2)Fewest cities";
    cout<<"How do you want to display \n 1)Stepbystep\n 2)Optimalpath only";
    cin>>choice;
    if(choice==1)
    {
    stepbystep_straightline(start);  	
	}
	else if(choice==2)
	{
		optimal_straightline(start);
	}
     
}

int stepbystep_straightline(string tbf)
{     

      cout<<"\ncity selected: "<<tbf <<"\n";
      conn_pointer.seekg(0, ios::beg);
       if(end.compare(tbf)==0)
	  {
	  	o--;
	  	int total=0;
	  	cout<< tbf <<"is the destination\n";
	  	vlist[l]=tbf;
	      l++;
	  	cout<<" The Final solution path is \n";
	  	for(int i=0;i<l-1;i++)
	  	{  // cout<<"inside";
	  	    one=vlist[i];two=vlist[i+1];
	  		cout<< one <<" to "<< two << " "<<get_distance(one,two)<<"\n";
	  		total+=get_distance(one,two);
		}
		cout<<"Total optimal path "<<total;
		goto ha;
	  	
	  }
	   cout<<"possible cities to where to travel:";
      while(o)
	  {
      	
	
	  conn_pointer >> word;
	  if(word==tbf)
	  {   
	      vlist[l]=tbf;
	      l++;
	  	  conn_pointer >> num;
	      count1=num;
                 	
         //Retriving child node
         int k=0;
	    while(count1!=0)
	       {
		    conn_pointer >> word;
		    for(int i=0;i<z;i++)
		    {
		    	if(tbv[i]==word)
		    	{
				
		    	goto d;}
		    	
			}
            for(int i=0;i<l;i++)
		    {
		    	if(vlist[i]==word){
				
		    	goto z;}
		    	
			}
			for(int i=0;i<avoid;i++)
			{
				if(avoid_node[i]==word)
				goto yy;
			}

            cout<<word ;
	     	item[k]=word;
	     	k++;
	     	d:cout<<"";
			z:cout<<"";
			yy:cout<<""; 
			 count1--;
	        }
	        cout<<"\n";
       	count1=k;
       //	cout<<k;
       	//finding heuristic value
       	cout<<"cities at the end of possible paths: ";
       	for(int i=0;i<z;i++)
       	{
       	  cout<<tbv[i]<<"("<<hvalue[i]<<") ";	
		}
		if(k==0)
		goto y;
	
		sum=0;
       
		   	
		   	if(l>1)
		   	{     
		   	    //cout<<"hi" <<l;
		   	     for(int h=0;h<l-1;h++)
			     {
			     //	cout<<"inside";
			     
			  	  one=vlist[h];two=vlist[h+1];
			  	  
			  	   sum+=get_distance(one,two);
			  	  // cout<<vlist[h];
			  	   //cout<<sum;
			   	 }
			   	 // cout<<sum;
			   	 t=sum;
			  for(int i=0;i<count1;i++)
			  {
				 sum=t;
			   one=item[i];
			   sum+=get_distance(tbf,one);
			   if(end.compare(one)!=0)
			   {
			   two=end;
			   sum+=get_distance(one,two);
		       }
			   tbv[z]=item[i];
			   hvalue[z]=sum;
			   cout<<item[i]<<"("<<hvalue[z]<<") ";
			   z++; 
		       }
			}
		    	for(int i=0;i<count1;i++)
		   
		    {  
		       if(l==1)
		       {
			   
		        one=item[i];two=vlist[0];
		     	sum=get_distance(one,two);
		     	one=item[i],two=end;
		     	hvalue[z]=sum+get_distance(one,two);
		     	tbv[z]=item[i];
		     	cout<<item[i]<<"("<<hvalue[z]<<") ";
		     	z++;
		     	sum=0;
		       }
	       	}
		   	 
		   	
		   y:cout<<"";
		   
		   mvalue=hvalue[0];
		   for(int i=0;i<z;i++)
		   {
		   	  if(mvalue > hvalue[i])
		   	  {
		   	  	mvalue=hvalue[i];
			  }
		   }
		   for(int i=0;i<z;i++)
		   {
		   	if(mvalue==hvalue[i])
		   	{   
		   	    temp=tbv[i];
		   	   		store=i;
		    }
		   }
		   for(int i=0;i<count1;i++)
		   item[i]="";
		   
		   for(int i=store;i<z-1;i++)
		   {
		   	tbv[i]=tbv[i+1];
		   	hvalue[i]=hvalue[i+1];
		   }
		   z--;
		   stepbystep_straightline(temp);
		   o--;
         	  
       }
       else
       {
	   
       getline(conn_pointer,skip);
       }
       

}
ha:cout<<"";
o++;		  
		  	
}

int optimal_straightline(string tbf)
{     

    //  cout<<"\ncity selected: "<<tbf <<"\n";
      conn_pointer.seekg(0, ios::beg);
      
       if(end.compare(tbf)==0)
	  {
	  	o--;
	    int total=0;
	  	vlist[l]=tbf;
	      l++;
	  	cout<<" The Final optimal solution path is \n";
	  	for(int i=0;i<l-1;i++)
	  	{  // cout<<"inside";
	  	    one=vlist[i];two=vlist[i+1];
	  		cout<< one <<" to "<< two << " "<<get_distance(one,two)<<"\n";
	  		total+=get_distance(one,two);
		}
		cout<<"Total distance is "<<total;
		goto ha;
	  	
	  }
	 //  cout<<"possible cities to where to travel:";
      while(o)
	  {
      	
	
	  conn_pointer >> word;
	  if(word==tbf)
	  {   
	      vlist[l]=tbf;
	      l++;
	  	  conn_pointer >> num;
	      count1=num;
                 	
         //Retriving child node
         int k=0;
	    while(count1!=0)
	       {
		    conn_pointer >> word;
		    for(int i=0;i<z;i++)
		    {
		    	if(tbv[i]==word)
		    	{
				
		    	goto d;}
		    	
			}
            for(int i=0;i<l;i++)
		    {
		    	if(vlist[i]==word){
				
		    	goto z;}
		    	
			}
			for(int i=0;i<avoid;i++)
			{
				if(avoid_node[i]==word)
				goto yy;
			}

       //     cout<<word ;
	     	item[k]=word;
	     	k++;
	     	d:cout<<"";
			z:cout<<"";
			yy:cout<<""; 
			 count1--;
	        }
	    //    cout<<"\n";
       	count1=k;
       //	cout<<k;
       	//finding heuristic value
      // 	cout<<"cities at the end of possible paths: ";
       	//for(int i=0;i<z;i++)
       	//{
       	//  cout<<tbv[i]<<"("<<hvalue[i]<<") ";	
		//}
		if(k==0)
		goto y;
	
		sum=0;
       
		   	
		   	if(l>1)
		   	{     
		   	    //cout<<"hi" <<l;
		   	     for(int h=0;h<l-1;h++)
			     {
			     //	cout<<"inside";
			     
			  	  one=vlist[h];two=vlist[h+1];
			  	  
			  	   sum+=get_distance(one,two);
			  	  // cout<<vlist[h];
			  	   //cout<<sum;
			   	 }
			   	 // cout<<sum;
			   	 t=sum;
			  for(int i=0;i<count1;i++)
			  {
				 sum=t;
			   one=item[i];
			   sum+=get_distance(tbf,one);
			   if(end.compare(one)!=0)
			   {
			   two=end;
			   sum+=get_distance(one,two);
		       }
			   tbv[z]=item[i];
			   hvalue[z]=sum;
		//	   cout<<item[i]<<"("<<hvalue[z]<<") ";
			   z++; 
		       }
			}
		    	for(int i=0;i<count1;i++)
		   
		    {  
		       if(l==1)
		       {
			   
		        one=item[i];two=vlist[0];
		     	sum=get_distance(one,two);
		     	one=item[i],two=end;
		     	hvalue[z]=sum+get_distance(one,two);
		     	tbv[z]=item[i];
		  //   	cout<<item[i]<<"("<<hvalue[z]<<") ";
		     	z++;
		     	sum=0;
		       }
	       	}
		   	 
		   	
		   y:cout<<"";
		   
		   mvalue=hvalue[0];
		   for(int i=0;i<z;i++)
		   {
		   	  if(mvalue > hvalue[i])
		   	  {
		   	  	mvalue=hvalue[i];
			  }
		   }
		   for(int i=0;i<z;i++)
		   {
		   	if(mvalue==hvalue[i])
		   	{   
		   	    temp=tbv[i];
		   	   		store=i;
		    }
		   }
		   for(int i=0;i<count1;i++)
		   item[i]="";
		   
		   for(int i=store;i<z-1;i++)
		   {
		   	tbv[i]=tbv[i+1];
		   	hvalue[i]=hvalue[i+1];
		   }
		   z--;
		   optimal_straightline(temp);
		   o--;
         	  
       }
       else
       {
	   
       getline(conn_pointer,skip);
       }
       

}
ha:cout<<"";
o++;		  
		  	
}

int get_distance(string first,string second)
{  
  
   int fa=1;
    location_pointer.seekg(0, ios::beg);
    int x,y,a,b,e,r,ta,counter=0;
    int la;
    //Reading from locations
   // cout<<first<<second;
    while(fa)
    {
    
     	location_pointer >> word;
     //	cout<<word;
	    
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
	ta=e+r;
	la=sqrt(ta);
	
    return(la);
}



  #include<iostream> 
  using namespace std;    
     int countOccurrences(string txt, string pat)  
	 {   	  int count=0;      
	 int found = txt.find(pat);   
	     while (found != string::npos)
	   {           count++; 
	          
	    found = txt.find(pat, found + 1);    
	    }   
	    return count; 
		
		}    
		   int main() 
		{  
		  string txt, pat1="SUVO",pat2="SUVOJIT";  
		  cout<<"Enter text:";     
		  getline(cin,txt);    
		  cout<<"\nNo of times SUVO Occured is:"<< countOccurrences(txt, pat1)<<endl;  
		   cout<<"\nNo of times SUVOJIT Occured is:"<< countOccurrences(txt, pat2)<<endl;  
		return 0;  
	 }
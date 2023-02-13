#include <iostream>
using namespace std;
int binarySearch(int arr[], int N, int x)
{
for(int i=0;i<N;i++)
{
if(arr[i]==x)
return i;	
}
return -1;
}
int main(void) {
int arr[] = {2, 3, 4, 10, 40};
int x = 10;
int N = sizeof(arr) / sizeof(arr[0]);
int result = binarySearch(arr, N, x);

if(result == -1){
cout<<"Element is not present in array"<<endl;
}else{
cout<<"Element is present at index "<<result; 
}
return 0;
}
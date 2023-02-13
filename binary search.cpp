#include <iostream>
using namespace std;
int binarySearch(int arr[], int start, int end, int key)
{
while (start <= end)

{
int mid = (start +end)/2;
// Check if x is present at mid
if (arr[mid] == key)
return mid;
// If x greater, ignore left half
if (arr[mid] < key)
start = mid + 1;
// If x is smaller, ignore right half
else
end = mid- 1;

}
// if we reach here, then element was
// not present
return -1;
}
int main(void) {
int arr[] = {2, 3, 4, 10, 40};
int n = 5;
int key = 40;
int result = binarySearch(arr, 0, n-1, key);

if(result == -1){
cout<<"Element is not present in array"<<endl;
}else{
cout<<"Element is present at index "<<result; 
}
return 0;
}
#include<iostream>
using namespace std;
int main() {
	int x, n;
	cout << "Enter the number of ID:" << "\n";
	cin >>n;
	int *arr = new int(n);
	cout << "Enter " << n << " ID " << endl;
	for (x = 0; x < n; x++) {
		cin >> arr[x];
	}
	cout << "The Even Id are  : ";
	for (x = 0; x < n; x++) {
		if(arr[x] % 2 == 0)
		{
    	cout << arr[x] << " ";
    }
}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

 //Palindrome means a reserve of input string same as original
 //if same then YES otherwise No
// Function that returns true
// if string is a palindrome
bool isPalindrome(string s)
{
    int length = s.size();
 
    // Creating a Stack
    stack<char> st;
 
    // Finding the mid
    int i, mid = length / 2;
 
    for (i = 0; i < mid; i++) {
        st.push(s[i]);
    }
 
    // Checking if the length of the string
    // is odd, if odd then neglect the
    // middle character
    if (length % 2 != 0) {
        i++;
    }
   
    char ele;
    // While not the end of the string
    while (s[i] != '\0')
    {
         ele = st.top();
         st.pop();
 
    // If the characters differ then the
    // given string is not a palindrome
    if (ele != s[i])
        return false;
        i++;
    }
 
return true;
}
 
// Driver code
int main()
{
    string s = "Hammad";
    cout<<" Input String " <<s<< " Palindrome Of String Is "<<endl;
    if (isPalindrome(s)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
 
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int rowCount, columnCount, i, j;
    int firstMatrix[3][3], secondMatrix[3][3], resultMatrix[3][3];

    cout<<"Number of rows of matrices to be Added : ";
    cin>>rowCount;

    cout<<"Number of columns matrices to be Added : ";
    cin>>columnCount;

    cout<<"Elements of first matrix : \n";

    for (i = 0; i < rowCount; i++)
        for (j = 0; j < columnCount; j++)
            cin>>firstMatrix[i][j];

    cout<<"Elements of second matrix : \n";

    for (i = 0; i < rowCount; i++)
        for (j = 0; j < columnCount; j++)
            cin>>secondMatrix[i][j];

    cout<<"Addition of entered matrices : \n";

    for (i = 0; i < rowCount; i++)
    {
        for (j = 0; j < columnCount; j++)
        {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
            cout<<resultMatrix[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"Subtraction of entered matrices : \n";

    for (i = 0; i < rowCount; i++)
    {
        for (j = 0; j < columnCount; j++)
        {
            resultMatrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
            cout<<resultMatrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Multiplication of entered matrices : \n";

    for (i = 0; i < rowCount; i++)
    {
        for (j = 0; j < columnCount; j++)
        {
            resultMatrix[i][j] = firstMatrix[i][j] * secondMatrix[i][j];
            cout<<resultMatrix[i][j]<<"\t";
        }
        cout<<"\n";
    }

    return 0;
}
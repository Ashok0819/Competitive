#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// The code is fine but there needs to be some advancements.
// Array is created to mark the vertices that have been already visited

int isVisited[100][100] = {0};
void visit_island(int arr[][100], int row, int columns, int size)
{
    if((row >= 0 && row < size) && (columns >= 0 && columns < size))
    {
        if(arr[row][columns] == 1 && isVisited[row][columns] == 0)
        {
            isVisited[row][columns] = 1;
            visit_island(arr, row + 1, columns, size);
            visit_island(arr, row - 1, columns, size);
            visit_island(arr, row, columns + 1, size);
            visit_island(arr, row, columns - 1, size);
        }
    }
    return;
}

int calculate_islands(int arr[][100], int size)
{
    int count = 0;
    for(int row = 0; row < size; row++)
    {
        for(int column = 0; column < size; column++)
        {
            if(isVisited[row][column] == 0 && arr[row][column] == 1)
            {
                count++; 
                isVisited[row][column] = 1;
                visit_island(arr, row + 1, column, size);
                visit_island(arr, row - 1, column, size);
                visit_island(arr, row, column + 1, size);
                visit_island(arr, row, column - 1, size);
            }
        }
    }
    return count;
}

// starting of the driver function. This is the point from where the execution of the program begins
int main()
{
    // memset(dP, sizeof(dP), -1);
    int arr[100][100];
    int size;
    cin >> size;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << calculate_islands(arr, size) << endl;
    return 0;
}

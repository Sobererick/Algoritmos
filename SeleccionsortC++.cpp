// C++ program for implementation of
// selection sort
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> // Para std::swap
#include <chrono>    // Para medir el tiempo

using namespace std;
using namespace std::chrono;


// Function for Selection sort
void selectionSort(int arr[], int n)
{
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}



vector<int> readCSV(const string &filename)
{
    ifstream file(filename);
    vector<int> data;
    string line;

    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return data;
    }

    while (getline(file, line))
    {
        stringstream ss(line);
        string item;
        while (getline(ss, item, ','))
        {
            data.push_back(stoi(item)); // Convert string to integer and add to vector
        }
    }

    file.close();
    return data;
}




// Driver program
int main()
{
    string filename = "datitos.csv"; // Name of the CSV file
    vector<int> data = readCSV(filename);

    if (data.empty())
    {
        cerr << "No data to sort." << endl;
        return 1;
    }

    int n = data.size();
    int *arr = new int[n];
    copy(data.begin(), data.end(), arr); // Copy vector data to array

    // Start measuring time
    auto start = high_resolution_clock::now();

    selectionSort(arr, n);

    // Stop measuring time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start); // Duration in milliseconds

    cout << "Sorted array: \n";
    printArray(arr, n);

    cout << "Time taken by selection sort: " << duration.count() << " milliseconds" << endl;

    delete[] arr; // Free allocated memory

    return 0;
}



// This is code is contributed by rathbhupendra
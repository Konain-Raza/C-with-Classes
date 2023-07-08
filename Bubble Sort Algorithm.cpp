#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
            
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int size;
    cout<< "Enter the Size of the Array: ";
    cin>> size;
    int arr[size];
    cout<< "Enter Array Elements: "<<endl;
    for(int i=0; i<=size-1; i++){
    	cout<< "Array ["<< i << "]: ";
    	cin>> arr[i];
	}
    
    bubbleSort(arr, size);
    
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout <<endl;

    return 0;
}

// Note: This code won't work with visual studio compiler, this code written for MingW and Cmake compilers.
#include <bits/stdc++.h>
#define ll long long
#define el "\n"
using namespace std;
void printArray(int arr[],int size){
    for (int i = 0; i < size; ++i) {
        if (i == size - 1)
            cout << arr[i];
        else
            cout << arr[i] << " ";
    }
}
bool sortedAscending(int arr[] , int size){
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}
bool sortedDescending(int arr[],int size){
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] < arr[i+1])
            return false;
    }
    return true;
}
int linearSearch(int arr[] , int size , int value){
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}
int binarySearch(int arr[],int size,int value){
    int left = 0 , right = size - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == value)
            return mid;
        else if(arr[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
void bubbleSort(int arr[] , int size){
    for (int i = 0; i < size - 1; ++i) {
        bool sorted = true;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                sorted = false;
            }
        }
        if(sorted)
            break;
    }
}
void selectionSort(int arr[],int size){
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j])
                swap(arr[i],arr[j]);
        }
    }
}
void insertionSort(int arr[],int size){
    for (int i = 1; i < size; ++i) {
        int j = i - 1 , key = arr[i];
        while (j > -1 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int partition(int arr[],int left,int right){
    int i = left , j = right , piv = i;
    while (i < j){
        if (arr[j] < arr[piv] && piv != j)
            swap(arr[j],arr[piv]);
        if (arr[i] > arr[piv] && piv != i)
            swap(arr[i],arr[piv]);
        if (piv != i)
            i++;
        if (piv != j)
            j--;
    }
    return piv;
}
void quickSort(int arr[],int left,int right){
    if (left < right){
        int piv = partition(arr,left,right);
        quickSort(arr,left,piv);
        quickSort(arr,piv+1,right);
    }
}
void merge(int arr[],int left, int right){
    int mid = (left+right) / 2;
    int leftArray[mid-left+1] , rightArray[right - mid];
    for (int i = 0; i < mid-left+1; i++)
    {
        leftArray[i] = arr[left+i];
    }
    for (int i = 0; i < right - mid; i++)
    {
        rightArray[i] = arr[mid + 1 + i];
    }
    int i = 0 , j = 0;
    int k = left;
    while (i < mid-left+1 && j < right - mid)
    {
        if (leftArray[i] <= rightArray[j]){
            arr[k] = leftArray[i];
            k++;
            i++;
        }
        else{
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }
    while (i < mid-left+1)
    {
        arr[k] = leftArray[i];
        k++;
        i++;
    }
    while (j < right - mid)
    {
        arr[k] = rightArray[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[],int left,int right){
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,right);
    }
}
int main(){
    while (true){
        cout << "Welcome to my data structure project!" << el;
        cout << "In this project you can deal with arrays, linked lists, stacks, queues, trees!" << el;
        cout << "Enter 1 to deal with Arrays\nEnter 2 to deal with Linked Lists\nEnter 3 to deal with Stacks\nEnter 4 to deal with Queues\nEnter 5 to deal with Trees\n\nEnter 0 to Exit the program" << el;
        cout << "-------------------------------------------------" << el;
        cout << "Enter your choice:";
        int mainChoice; cin >> mainChoice;
        if (mainChoice == 1){
            cout << "Array is activated successfully!" << el;
            cout << "Enter the size of the array:";
            int size; cin >> size;
            cout << "Enter elements of the array in one line seperated by space:";
            int arr[size];
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            cout << "Your array is [";
            printArray(arr,size);
            cout << "]" << el;
            cout << "-------------------------------------------------" << el;
            cout << "Checking if the array is sorted or not....." << el;
            bool sorted = sortedAscending(arr,size) || sortedDescending(arr,size);
            if (sortedAscending(arr,size))
                cout << "This array is sorted ascending!" << el;
            else if (sortedDescending(arr,size))
                cout << "This array is sorted descending!" << el;
            else
                cout << "This array is not sorted!" << el;
            if (sorted){
                while (true){
                    cout << "Operations available for sorted array:" << el;
                    cout << "Enter 1 for Linear search\nEnter 2 for Binary search\n\nEnter 0 to exit from array option" << el;
                    cout << "-------------------------------------------------" << el;
                    cout << "Enter your choice:";
                    int sortedChoice; cin >> sortedChoice;
                    if (sortedChoice == 1){
                        cout << "Linear search activated successfully!" << el;
                        cout << "Enter value to search for it in the array using Linear search:";
                        int value; cin >> value;
                        int ans = linearSearch(arr,size,value);
                        if (ans == -1)
                            cout << "The value " << value << " not found in the array!" << el;
                        else
                            cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                        cout << "-------------------------------------------------" << el;
                        cout << "Do you want to make more operations on this array?" << el;
                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                        cout << "Enter your choice: ";
                        string moreChoice; cin >> moreChoice;
                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                            continue;
                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                            break;
                    }
                    else if (sortedChoice == 2){
                        cout << "Binary search activated successfully!" << el;
                        cout << "Enter value to search for it in the array using Binary search:";
                        int value; cin >> value;
                        int ans = binarySearch(arr,size,value);
                        if (ans == -1)
                            cout << "The value " << value << " not found in the array!" << el;
                        else
                            cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                        cout << "-------------------------------------------------" << el;
                        cout << "Do you want to make more operations on this array?" << el;
                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                        cout << "Enter your choice: ";
                        string moreChoice; cin >> moreChoice;
                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                            continue;
                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                            break;
                    }
                    else if (sortedChoice == 0){
                        break;
                    }
                }
            }
            else{
                while (true){
                    cout << "Operations available for unsorted array:" << el;
                    cout << "Enter 1 for Linear search\nEnter 2 for Binary search\nEnter 3 for Bubble sort\nEnter 4 for Selection sort\nEnter 5 for Insertion sort\nEnter 6 for Quick sort\nEnter 7 for Merge sort\n\nEnter 0 to exit to main menu" << el;
                    cout << "-------------------------------------------------" << el;
                    cout << "Enter your choice:";
                    int unsortedChoice; cin >> unsortedChoice;
                    if (unsortedChoice == 1){
                        cout << "Linear search activated successfully!" << el;
                        cout << "Enter value to search for it in the array using Linear search:";
                        int value; cin >> value;
                        int ans = linearSearch(arr,size,value);
                        if (ans == -1)
                            cout << "The value " << value << " not found in the array!" << el;
                        else
                            cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                        cout << "-------------------------------------------------" << el;
                        cout << "Do you want to make more operations on this array?" << el;
                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                        cout << "Enter your choice: ";
                        string moreChoice; cin >> moreChoice;
                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                            continue;
                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                            break;
                    }
                    else if (unsortedChoice == 2 && sorted == false){
                        cout << "Binary search activated successfully but the array is not sorted you must sort it first!" << el;
                        cout << "Enter 1 for Bubble sort\nEnter 2 for Selection sort\nEnter 3 for Insertion sort\nEnter 4 for Quick sort\nEnter 5 for Merge sort\n\nEnter 0 to exit to last menu" << el;
                        cout << "-------------------------------------------------" << el;
                        cout << "Enter your choice:";
                        int sortChoice; cin >> sortChoice;
                        if (sortChoice == 1){
                            cout << "Bubble sort activated successfully!" << el;
                            bubbleSort(arr,size);
                            cout << "The array after sorting it using Bubble sort: [";
                            printArray(arr,size);
                            cout << "]" << el;
                            sorted = true;
                        }
                        else if (sortChoice == 2){
                            cout << "Selection sort activated successfully!" << el;
                            selectionSort(arr,size);
                            cout << "The array after sorting it using Selection sort: [";
                            printArray(arr,size);
                            cout << "]" << el;
                            sorted = true;
                        }
                        else if (sortChoice == 3){
                            cout << "Insertion sort activated successfully!" << el;
                            insertionSort(arr,size);
                            cout << "The array after sorting it using Insertion sort: [";
                            printArray(arr,size);
                            cout << "]" << el;
                            sorted = true;
                        }
                        else if (sortChoice == 4){
                            cout << "Quick sort activated successfully!" << el;
                            quickSort(arr,0,size-1);
                            cout << "The array after sorting it using Quick sort: [";
                            printArray(arr,size);
                            cout << "]" << el;
                            sorted = true;
                        }
                        else if (sortChoice == 5){
                            cout << "Merge sort activated successfully!" << el;
                            mergeSort(arr,0,size-1);
                            cout << "The array after sorting it using Merge sort: [";
                            printArray(arr,size);
                            cout << "]" << el;
                            sorted = true;
                        }
                        else if(unsortedChoice == 0){
                            break;
                        }
                        if (sorted){
                            cout << "Enter value to search for it in the array using Binary search:";
                            int value; cin >> value;
                            int ans = binarySearch(arr,size,value);
                            if (ans == -1)
                                cout << "The value " << value << " not found in the array!" << el;
                            else
                                cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                            cout << "-------------------------------------------------" << el;
                            cout << "Do you want to make more operations on this array?" << el;
                            cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                            cout << "Enter your choice: ";
                            string moreChoice; cin >> moreChoice;
                            if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y"){
                                bool enough = false , out = false;
                                while (true){
                                    cout << "The array is now sorted!\n" << el;
                                    cout << "Operations available for sorted array:" << el;
                                    cout << "Enter 1 for Linear search\nEnter 2 for Binary search\n\nEnter 0 to exit from array option" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Enter your choice: ";
                                    int sortedChoice; cin >> sortedChoice;
                                    if (sortedChoice == 1){
                                        cout << "Linear search activated successfully!" << el;
                                        cout << "Enter value to search for it in the array using Linear search:";
                                        int value; cin >> value;
                                        int ans = linearSearch(arr,size,value);
                                        if (ans == -1)
                                            cout << "The value " << value << " not found in the array!" << el;
                                        else
                                            cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                        cout << "-------------------------------------------------" << el;
                                        cout << "Do you want to make more operations on this array?" << el;
                                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                        cout << "Enter your choice: ";
                                        string moreChoice; cin >> moreChoice;
                                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                            continue;
                                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                            enough = true;
                                            break;
                                        }
                                    }
                                    else if (sortedChoice == 2){
                                        cout << "Binary search activated successfully!" << el;
                                        cout << "Enter value to search for it in the array using Binary search:";
                                        int value; cin >> value;
                                        int ans = binarySearch(arr,size,value);
                                        if (ans == -1)
                                            cout << "The value " << value << " not found in the array!" << el;
                                        else
                                            cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                        cout << "-------------------------------------------------" << el;
                                        cout << "Do you want to make more operations on this array?" << el;
                                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                        cout << "Enter your choice:";
                                        string moreChoice; cin >> moreChoice;
                                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                            continue;
                                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                            enough = true;
                                            break;
                                        }
                                    }
                                    else if (sortedChoice == 0){
                                        out = true;
                                        break;
                                    }
                                }
                                if (out)
                                    break;
                                if (enough){
                                    cout << "This array is now sorted, You can Enter another array!" << el;
                                    break;
                                }
                            }
                            else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                                break;
                        }
                    }
                    else if (unsortedChoice == 3 && sorted == false){
                        cout << "Bubble sort activated successfully!" << el;
                        bubbleSort(arr,size);
                        cout << "The array after sorting it using Bubble sort: [";
                        printArray(arr,size);
                        cout << "]" << el;
                        sorted = true;
                        cout << "-------------------------------------------------" << el;
                        cout << "Do you want to make more operations on this array?" << el;
                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                        cout << "Enter your choice: ";
                        string moreChoice; cin >> moreChoice;
                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y"){
                            bool enough = false, out = false;
                            while (true){
                                cout << "The array is now sorted!\n" << el;
                                cout << "Operations available for sorted array:" << el;
                                cout << "Enter 1 for Linear search\nEnter 2 for Binary search\n\nEnter 0 to exit from array option" << el;
                                cout << "-------------------------------------------------" << el;
                                cout << "Enter your choice:";
                                int sortedChoice; cin >> sortedChoice;
                                if (sortedChoice == 1){
                                    cout << "Linear search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Linear search:";
                                    int value; cin >> value;
                                    int ans = linearSearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice: ";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if (sortedChoice == 2){
                                    cout << "Binary search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Binary search:";
                                    int value; cin >> value;
                                    int ans = binarySearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice:";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if (sortedChoice == 0){
                                    out = true;
                                    break;
                                }
                            }
                            if(out)
                                break;
                            if (enough){
                                cout << "This array is now sorted, You can Enter another array!" << el;
                                break;
                            }
                        }
                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                            break;
                    }
                    else if (unsortedChoice == 4 && sorted == false){
                        cout << "Selection sort activated successfully!" << el;
                        selectionSort(arr,size);
                        cout << "The array after sorting it using Selection sort: [";
                        printArray(arr,size);
                        cout << "]" << el;
                        sorted = true;
                        cout << "-------------------------------------------------" << el;
                        cout << "Do you want to make more operations on this array?" << el;
                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                        cout << "Enter your choice: ";
                        string moreChoice; cin >> moreChoice;
                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y"){
                            bool enough = false , out = false;
                            while (true){
                                cout << "The array is now sorted!\n" << el;
                                cout << "Operations available for sorted array:" << el;
                                cout << "Enter 1 for Linear search\nEnter 2 for Binary search\n\nEnter 0 to exit from array option" << el;
                                cout << "-------------------------------------------------" << el;
                                cout << "Enter your choice: ";
                                int sortedChoice; cin >> sortedChoice;
                                if (sortedChoice == 1){
                                    cout << "Linear search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Linear search:";
                                    int value; cin >> value;
                                    int ans = linearSearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice: ";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if (sortedChoice == 2){
                                    cout << "Binary search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Binary search:";
                                    int value; cin >> value;
                                    int ans = binarySearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice:";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if(sortedChoice == 0){
                                    out = true;
                                    break;
                                }
                            }
                            if(out)
                                break;
                            if (enough){
                                cout << "This array is now sorted, You can Enter another array!" << el;
                                break;
                            }
                        }
                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                            break;
                    }
                    else if (unsortedChoice == 5 && sorted == false){
                        cout << "Insertion sort activated successfully!" << el;
                        insertionSort(arr,size);
                        cout << "The array after sorting it using Insertion sort: [";
                        printArray(arr,size);
                        cout << "]" << el;
                        sorted = true;
                        cout << "-------------------------------------------------" << el;
                        cout << "Do you want to make more operations on this array?" << el;
                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                        cout << "Enter your choice: ";
                        string moreChoice; cin >> moreChoice;
                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y"){
                            bool enough = false , out = false;
                            while (true){
                                cout << "The array is now sorted!\n" << el;
                                cout << "Operations available for sorted array:" << el;
                                cout << "Enter 1 for Linear search\nEnter 2 for Binary search\n\nEnter 0 to exit from array option" << el;
                                cout << "-------------------------------------------------" << el;
                                cout << "Enter your choice: ";
                                int sortedChoice; cin >> sortedChoice;
                                if (sortedChoice == 1){
                                    cout << "Linear search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Linear search:";
                                    int value; cin >> value;
                                    int ans = linearSearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice: ";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if (sortedChoice == 2){
                                    cout << "Binary search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Binary search:";
                                    int value; cin >> value;
                                    int ans = binarySearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice: ";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if (sortedChoice == 0){
                                    out = true;
                                    break;
                                }
                            }
                            if(out)
                                break;
                            if (enough){
                                cout << "This array is now sorted, You can Enter another array!" << el;
                                break;
                            }
                        }
                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                            break;
                    }
                    else if (unsortedChoice == 6 && sorted == false){
                        cout << "Quick sort activated successfully!" << el;
                        quickSort(arr,0,size-1);
                        cout << "The array after sorting it using Quick sort: [";
                        printArray(arr,size);
                        cout << "]" << el;
                        sorted = true;
                        cout << "-------------------------------------------------" << el;
                        cout << "Do you want to make more operations on this array?" << el;
                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                        cout << "Enter your choice: ";
                        string moreChoice; cin >> moreChoice;
                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y"){
                            bool enough = false , out = false;
                            while (true){
                                cout << "The array is now sorted!\n" << el;
                                cout << "Operations available for sorted array:" << el;
                                cout << "Enter 1 for Linear search\nEnter 2 for Binary search\n\nEnter 0 to exit from array option" << el;
                                cout << "-------------------------------------------------" << el;
                                cout << "Enter your choice: ";
                                int sortedChoice; cin >> sortedChoice;
                                if (sortedChoice == 1){
                                    cout << "Linear search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Linear search:";
                                    int value; cin >> value;
                                    int ans = linearSearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice: ";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if (sortedChoice == 2){
                                    cout << "Binary search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Binary search:";
                                    int value; cin >> value;
                                    int ans = binarySearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice: ";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if(sortedChoice == 0){
                                    out = true;
                                    break;
                                }
                            }
                            if(out)
                                break;
                            if (enough){
                                cout << "This array is now sorted, You can Enter another array!" << el;
                                break;
                            }
                        }
                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                            break;
                    }
                    else if (unsortedChoice == 7 && sorted == false){
                        cout << "Merge sort activated successfully!" << el;
                        mergeSort(arr,0,size-1);
                        cout << "The array after sorting it using Merge sort: [";
                        printArray(arr,size);
                        cout << "]" << el;
                        sorted = true;
                        cout << "-------------------------------------------------" << el;
                        cout << "Do you want to make more operations on this array?" << el;
                        cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                        cout << "Enter your choice: ";
                        string moreChoice; cin >> moreChoice;
                        if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y"){
                            bool enough = false , out = false;
                            while (true){
                                cout << "The array is now sorted!\n" << el;
                                cout << "Operations available for sorted array:" << el;
                                cout << "Enter 1 for Linear search\nEnter 2 for Binary search\n\nEnter 0 to exit from array option" << el;
                                cout << "-------------------------------------------------" << el;
                                cout << "Enter your choice: ";
                                int sortedChoice; cin >> sortedChoice;
                                if (sortedChoice == 1){
                                    cout << "Linear search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Linear search:";
                                    int value; cin >> value;
                                    int ans = linearSearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice: ";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if (sortedChoice == 2){
                                    cout << "Binary search activated successfully!" << el;
                                    cout << "Enter value to search for it in the array using Binary search:";
                                    int value; cin >> value;
                                    int ans = binarySearch(arr,size,value);
                                    if (ans == -1)
                                        cout << "The value " << value << " not found in the array!" << el;
                                    else
                                        cout << "The value " << value << " found at index " << ans << " in the array!" << el;
                                    cout << "-------------------------------------------------" << el;
                                    cout << "Do you want to make more operations on this array?" << el;
                                    cout << "Enter (YES,yes,y) to make more operations\nEnter (NO,no,n) to exit from array option" << el;
                                    cout << "Enter your choice: ";
                                    string moreChoice; cin >> moreChoice;
                                    if (moreChoice == "YES" || moreChoice == "yes" || moreChoice == "y")
                                        continue;
                                    else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n"){
                                        enough = true;
                                        break;
                                    }
                                }
                                else if (sortedChoice == 0){
                                    out = true;
                                    break;
                                }
                            }
                            if (out)
                                break;
                            if (enough){
                                cout << "This array is now sorted, You can Enter another array!" << el;
                                break;
                            }
                        }
                        else if (moreChoice == "NO" || moreChoice == "no" || moreChoice == "n")
                            break;
                    }
                    else if (unsortedChoice == 0){
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
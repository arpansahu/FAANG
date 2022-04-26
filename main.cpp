#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int linearSearchIterative(int arr[], int find, int size){
    for (int index = 0; index < size; ++index) {
        if (arr[index] == find) return index;
    }
    return -1;
}

int binarySearchIterative(int arr[], int find, int start, int end){
    while(end >= start){
        int mid = start + (end-start)/2;
        if (arr[mid] == find) return mid;
        else if (arr[mid] > find) end = mid -1;
        else start = mid + 1;
    }
}

int jumpSearchIterative(int arr[], int find, int size){
    int jump = sqrt(size);
    int prev = 0;
    while(arr[min(jump, size)-1] < find){
        prev = jump;
        jump += sqrt(size);
        if(prev >= jump) return -1;
    }
    while(arr[prev] < find){
        prev++;
        if (prev == min(jump, size)) return -1;
    }
    if (arr[prev] == find) return prev;
    return -1;
}

int interpolationSearchIterative(int arr[], int find, int start, int end){
    while(end >= start){
        if (end == start){
            if (arr[start] == find) return start;
            return -1;
        }
        int pos = (((end-start) / (arr[end]-arr[start])) * (find-arr[start]));
        if (arr[pos] == find) return pos;
        if (arr[pos] > find) end = pos-1;
        else start = pos +1;
    }
}

int exponentialSearchIterative(int arr[], int find, int end){
    if (arr[0] == find) return 0;
    int i = 1;
    while(arr[i] <= find) i*=2;
    binarySearchIterative(arr, find, i/2, end);
}

int ternarySearchIterative(int arr[], int find, int start, int end){
    while(end >= start){
        if (end == start){
            if (arr[start] == find) return find;
            return -1;
        }
        int mid1 = start + (end - start) / 3;
        int mid2 = mid1 + (end - start) / 3;
        if (arr[mid1] == find) return mid1;
        if (arr[mid2] == find) return mid2;
        if (arr[mid1] > find) end = mid1-1;
        else if (arr[mid2] < find) start = mid2 + 1;
        else{
            start = mid1+1;
            end = mid2 -1;
        }
    }
}
int main()
{
    int arr[] = {-8,2,-5,6,4,1, };
    int size = (*(&arr +1) - arr);

    int sorted_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sorted_size = (*(&sorted_arr +1) - sorted_arr);

    int index;
//
//    index = linearSearchIterative(arr, 6, size);
//    index = binarySearchIterative(sorted_arr, 6, 0, sorted_size-1);
//    index = jumpSearchIterative(sorted_arr, 6, sorted_size);
//    index = interpolationSearchIterative(sorted_arr, 6, 0, sorted_size-1);
//    index = exponentialSearchIterative(sorted_arr, 6, sorted_size-1);
//    index = ternarySearchIterative(sorted_arr, 6,0, sorted_size-1);
//    cout<<index;


//    int arr[] = {-8,2,-5,6,4,1, };
//    int size = (*(&arr +1) - arr);

//    insertionSortRecursive(arr, size, 1);
//    insertionSortIterative(arr, size);
//    shellSortRecursive(arr, size, size/2);
//    shellSortIterative(arr, size);
//    selectionSortRecursive(arr, size, 0);
//    selectionSortIterative(arr, size);
//    int writes = 0;
//      cycleSortRecursive(arr, size, 0, writes);
//      cycleSortIterative(arr, size, writes);
//      cout<<writes<<endl;
//    bubbleSortRecursive(arr, size);
//    bubbleSortIterative(arr, size);
//    combSort(arr, size);
//    countSort(arr, size);
//    pigeonHoleSort(arr, size);
//    float bucket_arr []= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
//    int bucket_size = (*(&bucket_arr + 1) - bucket_arr);
//    bucketSort(bucket_arr, bucket_size);
//    int pos_arr[] = {8, 5, 1, 2, 4, 6};
//    radixSort(pos_arr, size);
//    int aux[size];
//    for (int i = 0; i < size; ++i) aux[i] = arr[i];
//    mergeSortRecursive(arr, aux, 0, size - 1);
//    mergeSortIterative(arr, aux, size-1);
//    quickSortHoares(arr, 0, size-1);
//    quickSortLomuto(arr, 0, size-1);
//    quicksortRandomisedparititonwithHoares(arr, 0, size-1);
//    quickSortTailRecursive(arr, 0, size-1);

//    int dutch_arr[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
//    int dutch_size = (*(&dutch_arr + 1) - dutch_arr);
//
//    quickSortDutchNationalFlag(dutch_arr, 0, dutch_size);
//    for (int i = 0; i < dutch_size; ++i) {
//        cout<<dutch_arr[i]<<" ";
//    }
//    quickSortIterative(arr, size-1);
//    heapSortOutOfPlace(arr, size);
//    heapSortInPlace(arr, size);
//    heapSort(arr, size);
//    for (int i = 0; i < size; ++i) {
//        cout<<arr[i]<<" ";
//    }


//  Linked List
//    Node *root = new Node();
//    root->data = 1;
//
//
//    insertionNodeAtFirst(&root, 0);
//    insertionNodeAtLast(&root, 5);
//    insertionNodeAtPos(&root, 2, 3);
//    insertionNodeAtPos(&root, 3, 4);
//    insertionNodeAtPos(&root, 4, 5);

//    display(root);
//    deletionAtPosition(&root, 6);
//    deletionWithKey(&root, 2);
//    deleteCompleteLinkedList(&root);

//    lengthOfLinkedListIterative(&root);
//    lengthOfLinkedListRecursive(&root, 0);
//    searchInLinkedListIterative(&root, 2);
//    searchInLinkedListRecursive(&root, 12);
//    cout<<getNthNodeInALinkedList(&root, 3)->data<<endl;
//    cout<<getNthNodeInALinkedListFromLastNode(&root, 1)->data<<endl;
//    cout<<middleNodeOfLinkedList(&root)->data<<endl;
//    insertionNodeAtFirst(&root, 0);
//    cout<<countNoOfTimesADigitOccursInLinkedList(&root, 0)<<endl;

//    Node * last_node = getNthNodeInALinkedListFromLastNode(&root, 1);
//    last_node->next = root;
//    cout<<"Loops found : "<<detectLoopInLinkedList(&root)<<endl;


//    Node * middle_node = middleNodeOfLinkedList(&root);
//    middle_node->next=root;
//    cout<<"Length of Loop : "<<lengthOfLoopInLinkedList(&root)<<endl;

    //checking palindrome in linkedlist
//    insertionNodeAtLast(&root, 5);
//    insertionNodeAtLast(&root, 4);
//    insertionNodeAtLast(&root, 3);
//    insertionNodeAtLast(&root, 2);
//    insertionNodeAtLast(&root, 1);
//    insertionNodeAtLast(&root, 0);
//    display(root);
//    cout<<"Palindrome: "<<checkPalindromeInLinkedListUsingStack(&root)<<endl;
//    cout<<"Palindrome: "<<checkPalindromeInLinkedListUsingRecursion(&root, root)<<endl;

//    reverseLinkedListIterative(&root);
//    reverseLinkedListRecursive(&root);
//    display(root);





    return 0;

}

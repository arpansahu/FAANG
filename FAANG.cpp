#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;



#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int linearSearchRecursive(int arr[], int find, int size, int index){
    if (index == size) return -1;
    if (arr[index] == find) return index;
    if (index + 1 <= size) linearSearchRecursive(arr, size, find, index+1);
}

int linearSearchIterative(int arr[], int find, int size){
    for (int i = 0; i < size; ++i) {
        if (arr[i] == find) return i;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int find, int start, int end){
    if (end >= start){
        int mid = start + (end - start) / 2;
        if (arr[mid] == find) return mid;
        if (arr[mid] > find) return binarySearchRecursive(arr, find, start, mid - 1);
        return binarySearchRecursive(arr, find, mid + 1, end);
    }
    return -1;
}

int binarySearchIterative(int arr[], int find, int start, int end){
    while (end >= start) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == find) return mid;
        if (arr[mid] > find) end =  mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int jumpSearchIterative(int arr[],  int find, int size){
    int jump = sqrt(size);
    int prev =0;
    while(arr[min(jump, size)-1] < find){
        prev = jump;
        jump += sqrt(size);
        if (prev >= size) return -1;
    }

    while(arr[prev] < find){
        prev++;
        if (prev== min(jump, size)) return -1;
    }
    if (arr[prev]==find) return  prev;
    return -1;
}

int interpolationSearchIterative(int arr[], int find, int end){
    int start = 0;
    while(end >= start && arr[end] >= find && arr[start] <= find){
        if (start == end){
            if (arr[start] == find) return start;
            return -1;
        }
        int pos = start + (((end - start) / (arr[end] - arr[start])) / (find-arr[start]));
        if (arr[pos] == find) return pos;
        if (arr[pos] > find) end = pos - 1;
        else start = pos+1;
    }
    return -1;
}

int exponentialSearch(int arr[], int find, int size){
    if(arr[0] == find) return 0;

    int i = 1;
    while (i < size && arr[i] <= find)
        i = i*2;

    return binarySearchRecursive(arr, find, i/2,  min(i, size-1));
}

int ternarySearchRecursive(int arr[], int find, int start, int end){
    if (end >= start){
        int mid1 = start + (end - start)/3;
        int mid2 = mid1 + (end - start)/3;
        if (arr[mid1] == find)  return mid1;
        if (arr[mid2] == find)  return mid2;
        if (arr[mid1] > find) return ternarySearchRecursive(arr, find, start, mid1-1 );
        if (arr[mid2] < find) return ternarySearchRecursive(arr, find,mid2+1, end);
        return ternarySearchRecursive(arr, find, mid1+1, mid2-1);
    }
    return -1;
}

int ternarySearchIterative(int arr[], int find, int start, int end){
    while (end >= start){
        int mid1 = start + (end - start)/3;
        int mid2 = mid1 + (end - start)/3;
        if (arr[mid1] == find)  return mid1;
        if (arr[mid2] == find)  return mid2;
        if (arr[mid1] > find) end=mid1-1;
        else if (arr[mid2] < find) start=mid2+1;
        else{
            start = mid1+1; end = mid2-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {-8,2,-5,6,4,1, };
    int size = (*(&arr +1) - arr);

    int sorted_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sorted_size = (*(&sorted_arr +1) - sorted_arr);

    int index;

    //LinearSearch: a simple searching by one by one visiting every index
    //It can be used on any kind of array
    //    index = linearSearchRecursive(arr, 6, size, 0);
//    index = linearSearchIterative(arr, 6, size);

    //All these sorting are needed to be performed on sorted data or arrays
//    index = binarySearchRecursive(sorted_arr, 6, 0, sorted_size-1);

    //BinarySearch divides arr by half
//    index = binarySearchIterative(sorted_arr, 6, 0, sorted_size-1);

    //JumpSearch: same as linear search, just keep jumping by sqrt(size)
//    index = jumpSearchIterative(arr, 6, size);

    //InterpolationSearch: starts its search from the side which is closer to key
//    index = interpolationSearchIterative(sorted_arr, 6, sorted_size);

    //Exponenetial Sort: Optimises the start point by i*2
//    index = exponentialSearch(sorted_arr, 6, sorted_size);

    //Ternary Search: Same as Binary Search just divides array into 3 halves
//    index = ternarySearchRecursive(sorted_arr, 6, 0, sorted_size-1);
//    index = ternarySearchIterative(sorted_arr, 6, 0, sorted_size-1);
    cout<<index;

    return 0;
}


void insertionSortRecusrive(int arr[], int size, int index){
    int val = arr[index];
    int j = index;
    while(j > 0 && arr[j-1] > val) {
        arr[j] = arr[j-1];
        j--;
    }
    arr[j] = val;
    if(j + 1 < size) insertionSortRecusrive(arr, size, index+1);
    return;
}

void insertionSortIterative(int arr[], int size){
    for (int i = 1; i < size; ++i) {
        int val = arr[i];
        int j = i;

        while(j > 0 && arr[j-1] > val){
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = val;
    }
    return ;
}

void shellSortRecursive(int arr[], int size, int gap){
    for (int index = gap; index < size; ++index) {
        int val = arr[index];
        int j = index;

        while(j >= gap && arr[j-gap] > val){
            arr[j] = arr[j-gap];
            j -= gap;
        }
        arr[j] = val;
    }
    if(gap > 0) shellSortRecursive(arr, size, gap/2);
}

void shellSortIterative(int arr[], int size){
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int index = gap; index < size; ++index) {
            int val = arr[index];
            int j = index;
            while(j >= gap && arr[j-gap]> val){
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = val;
        }
    }
}


void selectionSortRecursive(int arr[], int size, int index){
    int min  = index;
    for (int i = index + 1; i < size; ++i) {
        if(arr[i] < arr[min]) min = i;
    }
    swap(arr[index], arr[min]);
    if(index + 1 <  size - 1) selectionSortRecursive(arr, size, index+1);
    return;
}

void selectionSortIterative(int arr[], int size){
    for (int index = 0; index < size - 1; ++index) {
        int min = index;
        for (int j = index + 1; j < size; ++j) {
            if(arr[j] < arr[min]) min = j;
        }
        swap(arr[index], arr[min]);
    }
    return;
}

void cycleSortRecursive(int arr[], int size, int cycle_start, int & writes){
    int val = arr[cycle_start];
    int j = cycle_start;

    for (int i = cycle_start + 1; i < size; ++i) {
        if (arr[i] < val) j++;
    }

    if (j == cycle_start) {
        if(cycle_start + 1< size - 1) cycleSortRecursive(arr, size, cycle_start + 1, writes);
        return;
    }

    while(arr[j] == val) j++;

    if(j != cycle_start){
        swap(arr[j], val);
        writes++;
    }

    while(j != cycle_start){
        j = cycle_start;

        for (int i = cycle_start + 1; i < size; ++i) {
            if(arr[i] < val)j++;
        }

        while(arr[j] == val) j++;

        if(arr[j] != val){
            swap(arr[j], val);
            writes++;
        }
    }

    if(cycle_start + 1< size - 1) cycleSortRecursive(arr, size, cycle_start + 1, writes);
}

void cycleSortIterative(int arr[], int size, int &writes){
    for (int cycle_start = 0; cycle_start < size - 1; ++cycle_start) {
        int val = arr[cycle_start];
        int j = cycle_start;

        for (int i = cycle_start + 1 ; i < size; ++i) {
            if (arr[i] < val) j++;
        }
        if (j == cycle_start) continue;
        //skip duplicates
        while(arr[j] == val) j++;

        if (j != cycle_start){
            swap(val, arr[j]);
            writes++;
        }
        //rotate rest of thr cycle
        while( j != cycle_start){
            j = cycle_start;
            for (int i = cycle_start + 1;  i < size; ++i) {
                if (arr[i] < val) j++;
            }

            while(arr[j] == val) j++;

            if(arr[j] != val){
                swap(arr[j], val);
                writes++;
            }
        }
    }
}

void bubbleSortRecursive(int arr[], int size){
    int count  = 0;
    for (int i = 0; i < size-1; ++i) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i + 1]);
            count++;
        }
    }
    if (count == 0) return;
    if (size -1 > 0) bubbleSortRecursive(arr, size-1);
}

void bubbleSortIterative(int arr[], int size){
    for (int s = size; s > 1 ; s--) {
        int count = 0;
        for (int i = 0; i < s - 1; ++i) {
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                count++;
            }
        }
        if(count == 0) return;
    }
}


int getNextGap(int gap){
    gap = (gap*10)/13 ;
    if (gap < 1) return 1;
    return gap;
}

void combSort(int arr[], int size){
    int gap = size;
    bool swapped = true;

    while(gap != 1 || swapped == true){
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < size - gap; ++i) {
            if(arr[i] > arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}

void countSort(int arr[],int size){
    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; ++i) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }

    int range = max -  min + 1;
    int count[range], output[size];

    //initialize with 0
    for (int i = 0; i < range; ++i) {
        count[i] = 0;
    }

    //store count of elements at their index
    for (int i = 0; i < size; ++i) {
        count[arr[i] - min]++;
    }
    //add last element into current in count array
    for (int i = 1; i < range; ++i) {
        count[i] += count[i-1];
    }
    //fill output array using below formula
    for (int i = size-1; i >= 0 ; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
}

void pigeonHoleSort(int arr[], int size){
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; ++i) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    int range = max - min + 1;
    vector<int> holes [range];

    for (int i = 0; i < size; ++i) {
        holes[arr[i] - min].push_back(arr[i]);
    }

    int index = 0;
    for (int i = 0; i < range; ++i) {
        vector<int> :: iterator it;
        for(it = holes[i].begin(); it != holes[i].end(); ++it){
            arr[index++] = *it;
        }
    }

}
void bucketSort(float arr[], int size){
    vector<float> bucket[size];

    for (int i = 0; i < size; ++i) {
        int bucket_index = arr[i] * size;
        bucket[bucket_index].push_back(arr[i]);
    }
    
    for (int i = 0; i < size; ++i) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int index = 0;
    for (int i = 0; i < size; ++i) {
        vector<float> :: iterator it;
        for (it = bucket[i].begin(); it != bucket[i].end() ; ++it) {
            arr[index++] = *it;
        }
    }
}

void countSortRadix(int arr[], int size, int exp){
    int output[size];
    int i, count[10] = {0};

    for (i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i <10; ++i) {
        count[i] += count[i-1];
    }

    for (i = size -1; i >= 0 ; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < size; ++i)
        arr[i] = output[i];
}

void radixSort(int arr[], int size){
    int max = arr[0];

    for (int i = 0; i < size; ++i)
        if(arr[i] > max) max = arr[i];

    for (int exp = 1; max / exp > 0 ; exp *= 10) {
        countSortRadix(arr, size, exp);
    }
}

void merge(int arr[], int aux[], int start, int mid, int end){
    int k = start, i = start, j = mid + 1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]) aux[k++] = arr[i++];
        else aux[k++] = arr[j++];
    }
    while(i <= mid) aux[k++] = arr[i++];
    for (int l = start; l <= end; ++l) arr[l] = aux[l];
}




void mergeSortIterative(int arr[], int aux[], int end){
    for (int m = 1; m <= end; m = 2*m)
    {
        for (int i = 0; i < end; i += 2*m)
        {
            int from = i;
            int mid = i + m - 1;
            int to = min(i + 2*m - 1, end);
            merge(arr, aux, from, mid, to);
        }
    }
}

int partitionHoares(int arr[], int start , int end){
    int i = start - 1, j = end + 1, pivot = arr[start];
    while(1){
        do i++; while (arr[i] < pivot);
        do j--; while(arr[j] > pivot);
        if(i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

void quickSortHoares(int arr[],int start, int end){
    if (start >= end) return;
    int pivot = partitionHoares(arr, start, end);
    quickSortHoares(arr, start, pivot);
    quickSortHoares(arr, pivot+1, end);
}

int partitionLomuto(int arr[], int start, int end){
    int pivot = arr[end], pIndex = start;
    for (int i = start; i < end; ++i)
        if (arr[i] <= pivot) swap(arr[i], arr[pIndex++]);
    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quickSortLomuto(int arr[], int start, int end){
    if( start >= end) return;
    int pivot = partitionLomuto(arr, start, end);
    quickSortLomuto(arr, start, pivot - 1);
    quickSortLomuto(arr, pivot + 1, end);
}

void quicksortRandomisedparititonwithHoares(int arr[], int start, int end){
    int random = rand() % (end- start + 1) + start;
    swap(arr[start], arr[random]);
    quickSortHoares(arr, start, end);
}

void quicksortTailRecusrive(int arr[], int start, int end){
    while(start <= end){
        if (end - start < 10){
            insertionSortIterative(arr, end+1);
            return;
        }
        else{
            int pivot = partitionLomuto(arr, start, end);
            if(pivot - start < end - pivot){
                quicksortTailRecusrive(arr, start, pivot - 1);
                start = pivot + 1;
            }
            else{
                quicksortTailRecusrive(arr, pivot + 1, end);
                end = pivot - 1;
            }
        };
    }
}

pair<int, int> partitionDutch(int arr[], int start, int end)
{
    int mid = start, pivot = arr[end];
    while (mid <= end)
    {
        if (arr[mid] < pivot){
            swap(arr[start++], arr[mid++]);
        }
        else if (arr[mid] > pivot){
            swap(arr[end--], arr[mid]);
        }
        else ++mid;
    }
    return make_pair(start - 1, mid);
}
void quickSortDutchNationalFlag(int arr[], int start,  int end){
    if (start >= end) return;
    if (end - start == 1){
        if (arr[start] < arr[end]){
            swap(arr[start], arr[end]);
            return;
        }
    }
    pair<int, int> pivot = partitionDutch(arr, start, end);
    quickSortDutchNationalFlag(arr, start, pivot.first);
    quickSortDutchNationalFlag(arr, pivot.second, end);
}

void quickSortIterative(int arr[],int size){
    stack<pair<int,int>> lookup;
    lookup.push({0,size});

    while(!lookup.empty()){
        int start = lookup.top().first, end =  lookup.top().second;
        int pivot = partitionLomuto(arr,start,end);
        lookup.pop();
        if(pivot - 1 > start) lookup.push({start,pivot - 1});
        if(pivot + 1 < end) lookup.push({pivot + 1,end});

    }
}

class priorityQueueMin{
private:
    int *arr;
    int size;

    int LEFT(int index){
        return index * 2 + 1;
    }

    int RIGHT(int index){
        return index * 2 + 2;
    }

    int heapifyDown(int index){
        int left = LEFT(index);
        int right = RIGHT(index);
        int minimum = index;
        if(left < size && arr[left] <  arr[minimum]) minimum = left;
        if(right < size && arr[right] < arr[minimum]) minimum = right;
        if(minimum != index){
            swap(arr[minimum], arr[index]);
            heapifyDown(minimum);
        }
    }

public:
    priorityQueueMin(int arr[], int size){
        this->arr = new int[size];
        this->size = size;
        for (int i = 0; i < size; ++i) this->arr[i] = arr[i];
        int index = (size-2) / 2;
        while(index >= 0) heapifyDown(index--);
    }

    ~priorityQueueMin(){
        delete [] arr;
    }

    bool empty(){
        return size == 0;
    }

    int pop(){
        try{
            if(size == 0) throw out_of_range("heap under flow");
            int top = arr[0];
            arr[0] = arr[size-- - 1];
            heapifyDown(0);
            return top;
        }
        catch(out_of_range &err){
            cout<<err.what()<<endl;
        }
    }
};

void heapSortOutOfPlace(int arr[], int size){
    priorityQueueMin pq(arr, size);
    int index = 0;
    while(!pq.empty()) arr[index++] = pq.pop();
}

class priorityQueueMax{
    int LEFT(int index){
        return index * 2 + 1;
    }
    int RIGHT(int index){
        return index * 2 + 2;
    }

    void heapifyDown(int arr[],int size,int index){
        int left = LEFT(index);
        int right = RIGHT(index);
        int maximum  = index;
        if(left <  size && arr[maximum] < arr[left]) maximum = left;
        if(right < size && arr[maximum] < arr[right]) maximum = right;
        if(maximum != index){
            swap(arr[maximum],arr[index]);
            heapifyDown(arr,size,maximum);
        }
    }
public:
    priorityQueueMax(int arr[],int size){
        int index = (size - 2) / 2;
        while(index >= 0) heapifyDown(arr,size,index--);
    }
    int pop(int arr[],int end){
        if( end <= 0 ) return -1;
        int top = arr[0];
        arr[0] = arr[end];
        heapifyDown(arr,end,0);
        return top;
    }
};


void heapSortInPlace(int arr[], int size){
    priorityQueueMax pq(arr, size);
    for (int i = size-1; i > 0 ; --i) {
        arr[i] = pq.pop(arr, i);
    }
}

void heapify(int arr[], int size, int index){
    int maximum = index;
    int left = (index * 2) + 1;
    int right = (index * 2) + 2;
    if(left < size && arr[left] > arr[maximum]) maximum = left;
    if(right < size && arr[right] > arr[maximum]) maximum = right;
    if(maximum != index) {
        swap(arr[index], arr[maximum]);
        heapify(arr, size, maximum);
    }
}

void heapSort(int arr[], int size){
    int index = (size - 2) / 2;
    while(index >= 0) heapify(arr, size, index--);

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {-8,2,-5,6,4,1};
    int size = (*(&arr +1) - arr);

    //    index based sorting
    //    complexity : n to n2

    //Insertion Sort: O(N) [when array is already sorted],O(N2), O(N2) [when array is reverse sorted]
//    insertionSortRecusrive(arr,size,1);
//    insertionSortIterative(arr, size);

    //ShellSort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead.
    // When an element has to be moved far ahead, many movements are involved. The idea of shellSort is to allow
    // exchange of far items. In shellSort, we make the array h-sorted for a large value of h. We keep reducing the
    // value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element is sorted.
//    shellSortIterative(arr, size);
//    shellSortRecursive(arr, size, size/2);

    //Selection Sort: O(N2), O(N2), O(N2) independent of distribution of data
//    selectionSortRecursive(arr, size, 0);
//    selectionSortIterative(arr, size);

//    Cycle sort is an in-place sorting Algorithm, unstable sorting algorithm, a comparison sort that is theoretically
//    optimal in terms of the total number of writes to the original array.

//    int writes = 0;
//    cycleSortRecursive(arr, size, 0, writes);
//      cycleSortIterative(arr, size, writes);
//    cout<<writes<<endl;


    //Bubble Sort: O(N) [when array is already sorted],O(N2), O(N2) [when array is reverse sorted]
//    bubbleSortRecursive(arr, size);
//    bubbleSortIterative(arr,size);

//    combSort(arr, size);


//    linear complexity sorting techniques

//    Counting sort is a sorting technique based on keys between a specific range. It works by counting the number
//    of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate the position
//    of each object in the output sequence.
//    countSort(arr, size);

//    pigeonHole Sort is used when holes and no of elements are same
//    pigeonHoleSort(arr, size);

//    Bucket sort is mainly useful when input is uniformly distributed over a range. For example, consider the
//    following problem.
//    Sort a large set of floating point numbers which are in range from 0.0 to 1.0 and are uniformly distributed
//    across the range. How do we sort the numbers efficiently?
//    A simple way is to apply a comparison based sorting algorithm. The lower bound for Comparison based sorting
//    algorithm (Merge Sort, Heap Sort, Quick-Sort .. etc) is Ω(n Log n), i.e., they cannot do better than nLogn.
//    Can we sort the array in linear time? Counting sort can not be applied here as we use keys as index in counting
//    sort. Here keys are floating point numbers.
//    The idea is to use bucket sort. Following is bucket algorithm.

//    float bucket_arr []= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
//    int bucket_size = (*(&bucket_arr + 1) - bucket_arr);
//
//    bucketSort(bucket_arr, bucket_size);
//
//    for (int i = 0; i < bucket_size; ++i) {
//        cout<<bucket_arr[i]<<" ";
//    }

//    Counting sort is a linear time sorting algorithm that sort in O(n+k) time when elements are in the range from
//    1 to k.
//       What if the elements are in the range from 1 to n2?
//       We can’t use counting sort because counting sort will take O(n2) which is worse than comparison-based
//       sorting algorithms. Can we sort such an array in linear time?
//       Radix Sort is the answer. The idea of Radix Sort is to do digit by digit sort starting from least significant
//       digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.
//    Note: Radix Sort is not meant for negative numbers
//
//    int pos_arr[] = {8, 5, 1, 2, 4, 6};
//    radixSort(pos_arr, size);
//    for (int i = 0; i < size; ++i) {
//        cout<<pos_arr[i]<<" ";
//    }
//    what if we want to modify radi Sort to sort neg pos int array?
//    we can divide neg and pos arrays and then perform radixSort



//  divide and conquer based sorting
//  Merge Sort : nlogn complexity best avg worst , divides array intow two halves and keep sorting

//    int aux[size];
//    for (int i = 0; i < size; ++i) aux[i] = arr[i];
//    mergeSortRecursive(arr, aux, 0, size - 1);
//    mergeSortIterative(arr, aux, size-1);

//    quickSortHoares(arr, 0, size-1);
//    quickSortLomuto(arr, 0, size-1);
//    quicksortRandomisedparititonwithHoares(arr, 0, size -1);
//    quicksortTailRecusrive(arr, 0, size-1);

//    int dutch_arr[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
//    int dutch_size = (*(&dutch_arr + 1) - dutch_arr);
//
//    quickSortDutchNationalFlag(dutch_arr,0, dutch_size);
//    for (int i = 0; i < dutch_size; ++i) {
//        cout<<dutch_arr[i]<<" ";
//    }
    quickSortIterative(arr, size-1);
//    heapSortOutOfPlace(arr, size);
//    heapSortInPlace(arr, size);
    heapSort(arr, size);
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }

    return 0;
}


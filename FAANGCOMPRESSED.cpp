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
        int mid = start + (end - start) / 2;
        if (arr[mid] == find) return mid;
        if (arr[mid] > find) end = mid -1;
        else start = mid +1;
    }
    return -1;
}

int jumpSearchIterative(int arr[], int find, int size){
    int jump = sqrt(size);
    int prev = 0;
    while(arr[min(jump, size)-1] < find){
        prev = jump;
        jump += sqrt(size);
        if (prev >= size) return -1;
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
        if (arr[pos] > find) end = pos -1;
        else start = pos+1;
    }
    return -1;
}

int exponentialSearchIterative(int arr[], int find, int end){
    if (arr[0]==find) return 0;
    int i = 1;
    while(arr[i] <= find) i++;
    return binarySearchIterative(arr, find, i/2, end);
}

int ternarySearchIterative(int arr[], int find, int start, int end){
    while(end >= start){
        int mid1 = start + (end - start)/3;
        int mid2 = mid1 + (end - start)/3;
        if (arr[mid1] == find) return mid1;
        if (arr[mid2] == find) return mid2;
        if (arr[mid1] > find) end = mid1-1;
        else if (arr[mid2] < find) start = mid2+1;
        else{
            start = mid1+1;
            end = mid2-1;
        }
    }
    return -1;
}

void insertionSortRecursive(int arr[], int size, int index){
    int val = arr[index];
    int j = index;
    while(j > 0 && arr[j-1] > val) {
        arr[j] = arr[j-1];
        j--;
    }
    arr[j] = val;
    if (index + 1 < size) insertionSortRecursive(arr, size, index+1);
}

void insertionSortIterative(int arr[], int size){
    for (int index = 1; index < size; ++index) {
        int val = arr[index];
        int j = index;
        while(j > 0 && arr[j-1]  > val){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=val;
    }
}

void shellSortRecursive(int arr[], int size, int gap){
    for (int index = gap; index < size; ++index) {
        int val =arr[index];
        int j = index;
        while(j > 0 && arr[j-gap] > val){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=val;
    }
    if (gap > 0) shellSortRecursive(arr, size, gap/2);
}

void shellSortIterative(int arr[], int size){
    for (int gap = size/2; gap > 0 ; gap/=2) {
        for (int index = gap; index < size; ++index) {
            int val = arr[index];
            int j = index;
            while(j > 0 && arr[j-gap]>val){
                arr[j]=arr[j-1];
                j--;
            }
            arr[j]=val;
        }
    }
}

void selectionSortRecursive(int arr[], int size, int index){
    int min = index;
    for (int i = min + 1; i < size; ++i) {
        if (arr[i] < arr[min]) min = i;
    }
    swap(arr[index], arr[min]);
    if (index +  1< size ) selectionSortRecursive(arr, size, index+1);
}

void selectionSortIterative(int arr[], int size){
    for (int index = 0; index < size - 1; ++index) {
        int min= index;
        for (int i = min + 1; i < size; ++i) {
            if (arr[i] < arr[min]) min = i;
        }
        swap(arr[index], arr[min]);
    }
}

void cycleSortRecursive(int arr[], int size, int cycle_start, int &writes){
    int val = arr[cycle_start];
    int j = cycle_start;
    for (int i = cycle_start + 1; i < size; ++i) if(arr[i] < val) j++;
    if (cycle_start == j){
        if (cycle_start+1 < size - 1) cycleSortRecursive(arr, size, cycle_start+1, writes);
        return;
    }
    while(arr[j] == val) j++;
    if (j != cycle_start){
        swap(arr[j], val);
        writes++;
    }
    while(j != cycle_start){
        j = cycle_start;
        for (int i = cycle_start + 1; i < size; ++i) if (arr[i] < val) j++;
        while(arr[j] == val) j++;
        if (arr[j] != val){
            swap(arr[j], val);
            writes++;
        }
    }
    if (cycle_start+1 < size-1) cycleSortRecursive(arr, size, cycle_start+1, writes);
}

void cycleSortIterative(int arr[], int size, int &writes){
    for (int cycle_start = 0; cycle_start < size-1; ++cycle_start) {
        int val = arr[cycle_start];
        int j = cycle_start;
        for (int i = cycle_start + 1; i < size; ++i) if(arr[i] < val) j++;
        if (cycle_start == j) continue;
        while(arr[j] == val) j++;
        if (j != cycle_start){
            swap(arr[j], val);
            writes++;
        }
        while(j != cycle_start){
            j = cycle_start;
            for (int i = cycle_start + 1; i < size; ++i) if (arr[i] < val) j++;
            while(arr[j] == val) j++;
            if (arr[j] != val){
                swap(arr[j], val);
                writes++;
            }
        }
    }
}

void bubbleSortRecursive(int arr[], int size){
    int count = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i+1]) { swap(arr[i], arr[i + 1]);
            count++;
        }
    }
    if (count == 0) return;
    if (size - 1 > 0 ) bubbleSortRecursive(arr, size-1);
}

void bubbleSortIterative(int arr[], int size){
    for (int s = size; s > 0  ; s--) {
        int count = 0;
        for (int i = 0; i < s-1; ++i) {
            if (arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
                count++;
            }
        }
        if (count == 0) return;
    }
}
int getNextGap(int gap){
    gap = gap *10/13;
    if (gap < 1) return  1;
    return gap;
}
void combSort(int arr[], int size){
    int gap = size;
    bool swapped = true;
    while(gap != 1 || swapped != true)
    {
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < size - gap; ++i) {
            if (arr[i] > arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}

void countSort(int arr[], int size){
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    int range = max - min + 1;
    int count[range], output[size];
    for (int i = 0; i < range; ++i) count[i] = 0;
    for (int i = 0; i < size; ++i) count[arr[i] - min]++;
    for (int i = 1; i < range; ++i) count[i] +=count[i-1];
    for (int i = 0; i < size; ++i) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i]-min]--;
    }
    for (int i = 0; i < size; ++i) arr[i] = output[i];
}

void pigeonHoleSort(int arr[], int size){
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    int range = max - min + 1;
    vector<int> holes[range];

    for (int i = 0; i < size; ++i) holes[arr[i] - min].push_back(arr[i]);
    int index = 0;
    for (int i = 0; i < range; ++i) {
        vector<int> :: iterator it;
        for (it = holes[i].begin(); it != holes[i].end() ; ++it) {
            arr[index++] = *it;
        }
    }

}
void bucketSort(float arr[], int size){
    vector<float> bucket[size];
    for (int i = 0; i < size; ++i) {
        int bi = arr[i] * size;
        bucket[bi].push_back(arr[i]);
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
    int count[10] = {0};
    for (int i = 0; i < size; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i <10; ++i) count[i] += count[i-1];
    for (int i = size -1; i >= 0 ; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < size; ++i) arr[i] = output[i];
}
void radixSort(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > max) max = arr[i];
    for (int exp = 1; max/exp > 0 ; exp*=10) {
        countSortRadix(arr, size, exp);
    }
}

void merge(int arr[], int aux[], int start, int mid, int end){
    int k = start, i = start, j = mid + 1;
    while(i <= mid && j <= end){
        if (arr[i] <= arr[j]) aux[k++] = arr[i++];
        else aux[k++] = arr[j++];
    }
    while(i <= mid) aux[k++]=arr[i++];
    for (int l = start; l <= end ; ++l) arr[l]=aux[l];
}

void mergeSortRecursive(int arr[], int aux[], int start, int end){
    if (start == end) return;
    int mid = start + ((end - start) /2);
    mergeSortRecursive(arr, aux, start, mid);
    mergeSortRecursive(arr, aux, mid+1, end);
    merge(arr, aux, start, mid, end);
}

void mergeSortIterative(int arr[], int aux[], int end){
    for (int m = 1; m < end ; m*=2) {
        for (int i = 0; i < end ; i+=2*m) {
            int from = i;
            int mid = i +m -1;
            int to = min(i + (2*m) -1, end);
            merge(arr, aux, from, mid, to);
        }
    }
}

int partitionHoares(int arr[], int start, int end){
    int pivot = arr[start], i = start -1, j = end + 1;
    while(1){
        do i++; while(arr[i] < pivot);
        do j--; while(arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

void quickSortHoares(int arr[], int start, int end){
    if (start >= end) return;
    int pivot = partitionHoares(arr, start, end);
    quickSortHoares(arr, start, pivot);
    quickSortHoares(arr, pivot+1, end);
}
int partitionLomuto(int arr[], int start, int end){
    int pivot = arr[end], pIndex = start;
    for (int i = start; i < end; ++i) {
        if (arr[i] <= pivot) swap(arr[i], arr[pIndex++]);
    }
    swap(arr[end], arr[pIndex]);
    return pIndex;
}
void quickSortLomuto(int arr[], int start, int end){
    if (start >= end) return;
    int pivot = partitionLomuto(arr, start, end);
    quickSortLomuto(arr, start, pivot - 1);
    quickSortLomuto(arr, pivot +1, end);
}

void quicksortRandomisedparititonwithHoares(int arr[], int start, int end){
    int random = rand() %  + ((end - start) + 1) + start;
    swap(arr[start], arr[random]);
    quickSortHoares(arr, start, end);
}

void quickSortTailRecursive(int arr[], int start, int end){
    while(start <= end){
        if (end - start < 2){
            insertionSortIterative(arr, end-1);
            return ;
        }
        else{
            int pivot = partitionLomuto(arr, start, end);
            if (pivot - start < end - pivot) { quickSortTailRecursive(arr, start, pivot - 1); start = pivot + 1; }
            else{ quickSortTailRecursive(arr, pivot +1, end); end = pivot - 1;}
        }
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

void quickSortIterative(int arr[], int end){
    stack<pair<int, int>> lookup;
    lookup.push(make_pair(0, end));
    while(!lookup.empty()){
        int start = lookup.top().first, end = lookup.top().second;
        lookup.pop();
        int pivot = partitionLomuto(arr, start, end);
        if (pivot - 1 > start) lookup.push(make_pair(start, pivot -1));
        if (pivot + 1 < end) lookup.push(make_pair(pivot+1, end));
    }
}

class priorityQueueMin{
    int * arr;
    int size;

    int LEFT(int index){
        return index * 2 + 1;
    }
    int RIGHT(int index){
        return index * 2 + 2;
    }

    void heapify(int index){
        int min = index;
        int left = LEFT(index);
        int right = RIGHT(index);
        if (left < size && arr[left] < arr[min]) min = left;
        if (right < size && arr[right] < arr[min]) min = right;
        if (min != index){
            swap(arr[min], arr[index]);
            heapify(min);
        }
    }

public:
    priorityQueueMin(int arr[], int size){
        this->arr  = new int[size];
        for (int i = 0; i < size; ++i) this->arr[i]=arr[i];
        this->size = size;
        int index = (size - 2)/2;
        while(index >= 0) heapify(index--);
    }
    ~priorityQueueMin(){
        delete [] arr;
    }
    bool empty(){
        return size == 0;
    }
    int pop(){
        int top = arr[0];
        arr[0] = arr[size-- -1];
        heapify(0);
        return top;
    }
};

void heapSortOutOfPlace(int arr[], int size){
    priorityQueueMin pq(arr, size);
    int index = 0;
    while(!pq.empty()) arr[index++] =  pq.pop();
}

class priorityQueueMax{
private:
    int LEFT(int index){
        return index * 2 + 1;
    }
    int RIGHT(int index){
        return index * 2 + 2;
    }

    void heapify(int arr[], int size, int index){
        int max = index;
        int left = LEFT(index);
        int right = RIGHT(index);
        if (left < size && arr[left] > arr[max]) max = left;
        if (right < size && arr[right] > arr[max]) max = right;
        if (max != index){
            swap(arr[max], arr[index]);
            heapify(arr, size, max);
        }
    }

public:
    priorityQueueMax(int arr[], int size){
        int index = (size-2)/2;
        while(index>=0) heapify(arr, size, index--);
    }
    int pop(int arr[], int end){
        int top = arr[0];
        arr[0] =arr[end];
        heapify(arr, end, 0);
        return top;
    }
};

void heapSortInPlace(int arr[], int size){
    priorityQueueMax pq(arr, size);
    for (int i = size-1; i > 0 ; i--) {
        arr[i] = pq.pop(arr, i);
    }
}

void heapify(int arr[], int size, int index){
    int max = index;
    int left = index*2+1;
    int right = index*2+2;
    if (left < size && arr[left] > arr[max]) max = left;
    if (right < size && arr[right] > arr[max]) max = right;
    if (max != index){
        swap(arr[max], arr[index]);
        heapify(arr, size, max);
    }
}

void heapSort(int arr[], int size){
    int index = (size-2)/2;
    while(index>=0) heapify(arr, size, index--);

    for (int i = size-1; i > 0 ; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

class Node{
public:
    Node * next;
    int data;
};

void insertionNodeAtFirst(Node** root, int data){
    Node * new_node = new Node();
    new_node->data = data;
    new_node->next = *root;
    *root = new_node;
}

void insertionNodeAtLast(Node** root, int data){
    Node *new_node = new Node();
    new_node->data = data;
    Node * iter = *root;
    while (iter->next != nullptr) iter = iter->next;
    iter->next = new_node;
}

void insertionNodeAtPos(Node** root, int data, int pos){
    Node * new_node = new Node();
    new_node->data = data;
    if(pos == 1){
        new_node->next = *root;
        *root = new_node;
    }
    else{
        Node * iter = *root;
        pos--;
        while (pos-- > 1){
            iter = iter->next;
        }
        new_node->next = iter->next;
        iter->next = new_node;
    }
}

void deletionAtPosition(Node** root, int pos){
    if (pos == 1){
        Node * temp =*root;
        *root = temp->next;
    }else{
        pos--;
        Node * iter = * root;
        while (pos-- > 1) iter = iter->next;
        iter->next = iter->next->next;
    }
}

void deletionWithKey(Node** root, int key){
    if (*root != nullptr && (*root)->data == key){
        Node * temp = *root;
        *root = temp->next;
    }
    else{
        Node * iter = *root;
        while(iter->next->data != key) iter = iter->next;
        iter->next = iter->next->next;
    }
}

void deleteCompleteLinkedList(Node **root){
    Node * curr = *root, *next = *root;
    while(next != nullptr){
        next = next->next;
        free(curr);
        curr = next;
    }
    *root = nullptr;
}

void display(Node * root){
    Node * iter = root;
    while(iter != nullptr){
        cout<<iter->data<<"->";
        iter = iter->next;
    }
    cout<<endl;
}

void lengthOfLinkedListIterative(Node ** root){
    int count =0;
    for (Node *iter = *root; iter != nullptr  ; iter = iter->next) count++;
    cout<<count<<endl;
}

void lengthOfLinkedListRecursive(Node ** root, int count){
    if (*root == nullptr) { cout <<count<<endl; return; }
    lengthOfLinkedListRecursive(&(*root)->next, count + 1);
}

void searchInLinkedListIterative(Node **root, int data){
    for (Node * it = *root; it != nullptr ; it = it->next) if (it->data == data) { cout << "Found : " << data << endl;return; }
    cout<<"Not Found: "<<data<<endl;
}

void searchInLinkedListRecursive(Node **root, int data){
    if (*root == nullptr) {cout<<"Not Found: "<<data<<endl; return;}
    if ((*root)->data == data) { cout << "Found : " << data << endl;return; }
    searchInLinkedListRecursive(&(*root)->next, data);
}

Node * getNthNodeInALinkedList(Node **root, int n){
    if (n == 1) return *root;
    else{
        Node * iter = * root;
        while(n-- > 1) iter = iter->next;
        return iter;
    }
}

Node * getNthNodeInALinkedListFromLastNode(Node **root, int n){
    int length = 0;
    Node * iter = *root;
    while(iter != nullptr) { length++; iter = iter->next; }
    n = length - n + 1;
    iter = *root;
    while(n-- > 1) iter = iter->next;
    return iter;
}

Node * middleNodeOfLinkedList(Node **root){
    Node * slow = *root;
    Node * fast = *root;
    if (*root != nullptr){
        while(fast != nullptr && fast->next != nullptr ){
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return slow;
}

int countNoOfTimesADigitOccursInLinkedList(Node **root, int data){
    if (*root == nullptr) return 0;
    Node *iter = *root;
    int count = 0;
    while(iter != nullptr){
        if (iter->data == data) count++;
        iter = iter->next;
    }
    return count;
}

bool detectLoopInLinkedList(Node **root){
    Node * slow = *root;
    Node * fast = *root;
    while(fast != nullptr && fast != nullptr && slow != nullptr && slow->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return true;
    }
    return false;
}

int lengthOfLoopInLinkedList(Node **root){
    Node * slow = *root;
    Node * fast = *root;
    while(fast != nullptr && fast != nullptr && slow != nullptr && slow->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
    }
    int count = 0;
    Node *iter = slow->next;
    while(iter != slow) {
        iter = iter->next;
        count++;
    }
    return count;
}

bool checkPalindromeInLinkedListUsingStack(Node **root){
    stack<Node *> s;
    Node * iter = *root;

    while(iter != nullptr){
        s.push(iter);
        iter = iter->next;
    }
    iter = *root;
    bool palindrome = true;
    while(iter != nullptr){
        cout<<iter->data <<  s.top()->data<<endl;
        if (iter->data != s.top()->data){
            palindrome = false;
        }
        iter = iter->next;
        s.pop();
    }
    return palindrome;
}

bool checkPalindromeInLinkedListUsingRecursion(Node **left, Node *right){
    if (right == nullptr) return true;
    bool isp = checkPalindromeInLinkedListUsingRecursion(&(*left), right->next);
    if (isp ==false) return false;
    bool isp2 = (right->data == (*left)->data);
    *left = (*left)->next;
    return isp2;
}

void reverseLinkedListIterative(Node **root){
    if(*root == NULL) return;
    Node * prev= nullptr;
    Node * curr = *root;
    Node * next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev;
}

void reverseLinkedListRecursive(Node **root){
    Node *first, *rest;
    if (*root == nullptr) return;
    first = *root;
    rest = first->next;
    if (rest == nullptr) return;

    reverseLinkedListRecursive(&rest);
    first->next->next = first;
    first->next=nullptr;
    *root=rest;
}

int main()
{
//    int arr[] = {-8,2,-5,6,4,1, };
//    int size = (*(&arr +1) - arr);
//
//    int sorted_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int sorted_size = (*(&sorted_arr +1) - sorted_arr);
//
//    int index;

//    index = linearSearchIterative(arr, 6, size);
//    index = binarySearchIterative(sorted_arr, 6, 0, size-1);
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
    Node *root = new Node();
    root->data = 1;


    insertionNodeAtFirst(&root, 0);
    insertionNodeAtLast(&root, 5);
    insertionNodeAtPos(&root, 2, 3);
    insertionNodeAtPos(&root, 3, 4);
    insertionNodeAtPos(&root, 4, 5);

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
    display(root);
//    cout<<"Palindrome: "<<checkPalindromeInLinkedListUsingStack(&root)<<endl;
//    cout<<"Palindrome: "<<checkPalindromeInLinkedListUsingRecursion(&root, root)<<endl;

//    reverseLinkedListIterative(&root);
    reverseLinkedListRecursive(&root);
    display(root);





    return 0;

}

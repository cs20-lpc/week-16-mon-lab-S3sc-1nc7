template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while(i > 0){
        int p = this->parent(i);
        if (data[i] < data[p]){ // child < parent swap
            swap(data[p], data[i]);
            //T temp = data[p];
            //data[p] = data[i];
            //data[i] = temp;
            i = p;
        }
        else{ // child > parent, local heap property maintained
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int s = data.size();
    while(true){
        int l = this->left(i);
        int r = this->right(i);
        int min = i;

        // case left is min
        if (l < s && data[l] < data[min]){
            min = l;
        }
        if (r < s && data[r] < data[min]){
            min = r;
        }

        if (i != min){
            swap(data[i], data[min]);
            //T temp = data[i]; // saves parent
            //data[i] = data[min]; // writes min up to parent
            //data[min] = temp; // writes parent val down the tree
            i = min; // new min is child
        }
        else {
            // i fulfills local heap property
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);
    this->siftUp(data.size()-1);

}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue; // empty check outside function
    // TODO: Implement removing the root element.
    rootValue = data[0];
    data[0] = data.back();
    this->siftDown(0);
    
    data.pop_back();
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property

    if (index >= size()){ // last element removed
        return;
    }
    if (index > 0 && data[parent(index)] > data[index]){ // NOT ROOT sift up if less than parent
        this->siftUp(index);
    }
    else{
        this->siftDown(index);
    }
}

class MyCircularDeque {
public:

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size=0;
        capacity=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())  return false;
        data.push_back(value);
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())  return false;
        data.insert(data.begin(),value);
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        data.pop_back();
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        data.erase(data.begin());
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return data[size-1];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return data[0];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size==capacity;
    }

private:
   vector<int> data;
   int size;
   int capacity;
};
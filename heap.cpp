// heap.cpp
// Albert Yu

#include "heap.h"
#include <iostream>
#include <algorithm>
#include <climits>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  int last = INT_MIN;
  bool inserted = false;
  if(vdata.empty()) {
  	vdata.push_back(value);
	return;
  }
  for(unsigned int i = 0; i < vdata.size(); i++) {
    if(value >= last && value < vdata.at(i)) {
      vdata.insert(vdata.begin() + i, value);
      inserted = true;
      return;
    }
  }
  if(!inserted) {
    vdata.push_back(value);
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(!vdata.empty()) {
    vdata.erase(vdata.begin());
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if(!vdata.empty()) {
    return vdata.front();
  } else {
    return INT_MAX;
  }
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    

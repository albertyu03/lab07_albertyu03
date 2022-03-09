// heap.cpp
// Albert Yu

#include "heap.h"
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  //swap up
  vdata.push_back(value);
  //index = size() - 1
  int index = vdata.size() - 1;
  int parInd = (index - 1)/2;
  if(index == 0) {
    return;
  } //if only 1 value in tree don't need to check
  int parent = vdata.at(parInd);
  //checking for order
  while(vdata.at(index) < parent) { //fulfill heap req
    int p1 = parent;
    vdata.at(parent) = vdata.at(index); //swap child and parent
    vdata.at(index) = p1;

    index = parInd;
    if(index == 0) { //index hits top of list (don't need to check parent)
      return;
    }
    parInd = (index - 1) / 2;
    parent = vdata.at(parInd);
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  //replacement for top = rightmost
  if(vdata.size() <= 1) {
    if(!vdata.empty()) {
      vdata.pop_back();
    }
    return;
  }
  
  int rightmost = vdata.at(vdata.size() - 1);
  vdata.erase(vdata.end());
  vdata.at(0) = rightmost; //step 1
  int curAt = 0;
  while(curAt < vdata.size()) { //not back at rightmost
    int c1, c2;
    c1 = INT_MAX;
    c2 = INT_MAX;
    if(curAt * 2 + 1 < vdata.size()) { //sets c1 if children exist
      c1 = vdata.at(curAt*2+1);
    }
    if(curAt * 2 + 2 < vdata.size()) { //sets c2 if children exist
      c2 = vdata.at(curAt * 2 + 1);
    }
    if(c1 == c2 && c1 == INT_MAX) { //signfies no children = end
      return;
    }
    int cMin = std::min(c1, c2);
    if(cMin == c1) { //swap curAt and c1 num value, curAt changes
      int cur = cMin;
      vdata.at(curAt*2+1) = vdata.at(curAt);
      vdata.at(curAt) = cMin;
      curAt = curAt*2+1;
    } else { 
      int cur = cMin;
      vdata.at(curAt*2+2) = vdata.at(curAt);
      vdata.at(curAt) = cMin;
      curAt = curAt*2+2;
    }
    
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if(!vdata.empty()) {
    return vdata.front();
  } else {
    return -1 * INT_MAX;
  }
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    

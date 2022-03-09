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
    //std::cout << "IND: " << index << std::endl << "PAR: " << parInd << std::endl;
    int p1 = parent;
    vdata.at(parInd) = vdata.at(index); //swap child and parent
    vdata.at(index) = p1;

    index = parInd; //index to look at becomes parent's index
    //std::cout << "IND AGAIN: " << index << std::endl;
    if(index == 0) { //index hits top of list (don't need to check parent)
      //std::cout << "index hits top of list?" << std::endl;
      return;
    }
    parInd = (index - 1) / 2; //parent of new index
    parent = vdata.at(parInd);
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  //replacement for top = rightmost
  /*
  std::cout << "popping: ";
  for(unsigned int i = 0; i < vdata.size(); i++) {
	  std::cout << vdata.at(i) << " ";
  }
  std::cout << std::endl;
  */
  if(vdata.size() <= 1) {
    if(!vdata.empty()) {
      vdata.pop_back();
    }
    return;
  } 
  //bubble down
  unsigned long int cSize = vdata.size();
  int rightmost = vdata.at(cSize - 1);
  vdata.pop_back(); //remove rightmost
  vdata.at(0) = rightmost; //step 1: replace root with rightmost
  //std::cout << "ROOT: " << rightmost << std::endl;
  int curAt = 0;
  while(curAt < vdata.size() - 1) { //not back at rightmost index
    int c1, c2;
    c1 = INT_MAX;
    c2 = INT_MAX;
    if(curAt * 2 + 1 < vdata.size()) { //sets c1 if children exist
      c1 = vdata.at(curAt*2+1);
    }
    if(curAt * 2 + 2 < vdata.size()) { //sets c2 if children exist
      c2 = vdata.at(curAt * 2 + 2);
    }
    if(c1 == c2 && c1 == INT_MAX) { //no children = end
      break;
    }
    int cMin = std::min(c1, c2); //find min child
    if(vdata.at(curAt) <= cMin) {
	    break;
    }
    if(cMin == c1) { //swap curAt and c1 num value, curAt changes
      int cur = cMin;
      vdata.at(curAt*2+1) = vdata.at(curAt); //child becomes parent
      vdata.at(curAt) = cMin; //parent becomes child
      curAt = curAt*2+1; //current index = child
    } else { 
      int cur = cMin; //repeat for this side
      vdata.at(curAt*2+2) = vdata.at(curAt);
      vdata.at(curAt) = cMin;
      curAt = curAt*2+2;
    }/*
    std::cout << "POPPED: ";
    for(unsigned int i = 0; i < vdata.size(); i++) {
	    std::cout << vdata.at(i) << " ";
    }
    std::cout << std::endl;
    */
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
    

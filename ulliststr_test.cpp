/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;
#include "ulliststr.h"

void printAll(ULListStr* list);

int main(int argc, char* argv[])
{
  ULListStr* temp = new ULListStr();
  // Testing push_back
  cout << endl << "push_back a" << endl;
  temp->push_back("a");
  cout << "Get 0: " << temp->get(0) << endl;
  cout << "front(): " << temp->front() << endl;
  cout << "back(): " << temp->back() << endl;

  cout << endl <<"push_back b" << endl;
  temp->push_back("b");
  cout << "Get 0: " << temp->get(0) << endl << "Get 1: " << temp->get(1) << endl;
  cout << "front(): " << temp->front() << endl;
  cout << "back(): " << temp->back() << endl;

  // Testing pop_back
  cout << endl << "pop_back" << endl;
  temp->pop_back();
  // The following line should throw an error if uncommented because index 1 no longer is valid
  // cout << endl << temp->get(0) << endl << temp->get(1) << endl;

  cout << endl <<"push_back c" << endl;
  temp->push_back("c");
  cout << "Get 0: " << temp->get(0) << endl << "Get 1: " << temp->get(1) << endl;
  cout << "front(): " << temp->front() << endl;
  cout << "back(): " << temp->back() << endl;

  // Testing push_front
  cout << endl <<"push_front x" << endl;
  temp->push_front("x");
  cout << "Get 0: " << temp->get(0) << endl << "Get 1: " << temp->get(1) << endl;
  cout << "front(): " << temp->front() << endl;
  cout << "back(): " << temp->back() << endl;

  // Testing pop_front
  cout << endl << "pop_front" << endl;
  temp->pop_front();

  printAll(temp);

  // Push a whole string
  cout << endl << "push_front hello world" << endl;
  temp->push_front("hello world");
  printAll(temp);

  temp->clear();
  delete temp;

  // Make a new list full of lots of ASCII characters
  ULListStr* temp2 = new ULListStr();
  for (int i = 33; i<127; i++) {
    char cha = i;
    string str = "";
    str += cha;
    temp2->push_back(str);
  }
  printAll(temp2);

  // Remove the first 20
  for (int i = 0; i<20; i++) {
    temp2->pop_front();
  }
  printAll(temp2);

  // Add "Hi" 15 times to the front
  for (int i = 0; i<15; i++) {
    temp2->push_front("Hi");
  }
  printAll(temp2);

  // Add "Bye" 15 times to the back
  for (int i = 0; i<15; i++) {
    temp2->push_back("Bye");
  }
  printAll(temp2);

  // Remove the last 50
  for (int i = 0; i<50; i++) {
    temp2->pop_back();
  }
  printAll(temp2);

  // Remove the remaining 54 from back
  for (int i = 0; i<54; i++) {
    temp2->pop_back();
  }
  printAll(temp2);

  // Add 25 "a"s from back
  for (int i = 0; i<25; i++) {
    temp2->push_back("a");
  }
  printAll(temp2);

  // Try to access a loc out of range
  // (commented out because it throws an exception as expected)
  // cout << "get(200): " << temp2->get(200) << endl;

  // Remove all 25 from front
  for (int i = 0; i<25; i++) {
    temp2->pop_front();
  }
  printAll(temp2);

  // Pop_front and pop_back more even though the list is empty
  temp2->pop_front();
  temp2->pop_front();
  temp2->pop_back();
  temp2->pop_back();

  // Try to get a value even though the list is empty
  // (commented out because it throws an exception as expected)
  // cout << "get(0) on an empty list: " << temp2->get(0) << endl;

  temp2->clear();
  delete temp2;
  return 0;
}

// Inefficiently prints all members of an unrolled list in order
// O(n^2) when it could be O(n) as a member function,
// but it's only for testing purposes so I don't care
// Also this puts extra testing on get() when using a member function would
// bypass get() and the member function itself could be buggy
void printAll(ULListStr* list) {
  size_t size = list->size();
  cout << endl << "List size: " << size << endl;
  for (size_t i = 0; i<size; i++) {
    cout << list->get(i) << ", ";
  }
  cout << endl;
}
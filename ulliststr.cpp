#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
bool ULListStr::no_items() {
  if (head_ == NULL && tail_ == NULL) return true;
  else return false;
}

void ULListStr::create_first() {
  head_ = new Item();
  tail_ = head_;
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) return NULL;
  else {
    Item* currentItem = head_;
    size_t currentIndex = currentItem->first;
    std::string* currentVal = &currentItem->val[currentIndex];
    // Go through the list one element at a time until the correct index
    for (size_t i = 1; i<=loc; i++) {
      // If there are elements left in the Item, go to the next element
      if (currentIndex < currentItem->last - 1) {
        currentIndex++;
      } else {
        // If there are no elements left in the Item, go to the next Item
        currentItem = currentItem->next;
        currentIndex = currentItem->first;
      }
      currentVal = &currentItem->val[currentIndex];
    }
    return currentVal;
  }
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

void ULListStr::push_back(const std::string& val) {
  // If the list is empty create the first item
  if (no_items()) {
    create_first();
  }
  // If the string is already full/at the end, add a new item to the list
  // and put the push_back value there
  if (tail_->last == ARRSIZE) {
    // Make a new item and update the tail pointer
    tail_->next = new Item();
    tail_->next->prev = tail_;
    tail_ = tail_->next;
  }
  // Add the value to the next unused index of the current tail Item
  // and move the last counter up
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  // If the list is empty create the first item
  if (no_items()) {
    create_first();
  }
  // If the string is already at 0 for the first index, add a new Item before this one
  if (head_->first == 0) {
    // Make a new item and update the head pointer
    head_->prev = new Item();
    head_->prev->next = head_;
    head_ = head_->prev;
    head_->first = head_->last = 10;
  }
  head_->val[head_->first - 1] = val;
  head_->first--;
  size_++;
}

void ULListStr::pop_back() {
  // Do nothing if the list is empty
  if (tail_ == NULL) return;

  if (tail_->last - 1 != tail_->first) {
    // If the back element isn't the only one in the item, remove it from the active
    // indexes by moving the last index up. No need to deallocate
    tail_->last--;
  } else {
    // If the back element is the only one in the item, simply remove the last
    // item and move the tail pointer up
    if (tail_->prev == NULL) {
      // If the Item being removed is the only one in the list,
      // set head and tail to NULL
      delete tail_;
      tail_ = NULL;
      head_ = NULL;
    } else {
      tail_ = tail_->prev;
      delete tail_->next;
      tail_->next = NULL;
    }
  }
  size_--;
}

void ULListStr::pop_front() {
// Do nothing if the list is empty
if (head_ == NULL) return;

  if (head_->first != head_-> last - 1) {
    // If the front element isn't the only one in the item, remove it from the active
    // indexes by moving the first index up. No need to deallocate
    head_->first++;
  } else {
    // If the front element is the only one in the item, simply remove the first
    // item and move the head pointer up
    if (head_->next == NULL) {
      // If the Item being removed is the only one in the list,
      // set head and tail to NULL
      delete head_;
      head_ = NULL;
      tail_ = NULL;
    } else {
      head_ = head_->next;
      delete head_->prev;
      head_->prev = NULL;
    }
  }
  size_--;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

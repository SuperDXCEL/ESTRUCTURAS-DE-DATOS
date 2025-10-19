#include "../header/Cola.h"
#include <iostream>

Cola::Cola() {
  size_ = 0;
  first_element_ = nullptr;
  last_element_ = nullptr;
}
Cola::~Cola() {
  while (first_element_) {
    NodoCola* node = pop();
  }
}
int Cola::get_size() {
  return size_;
}
void Cola::insert(NodoCola* nodo) {
  if (!first_element_) {
    first_element_ = nodo;
    first_element_->next_ = nullptr;
  }
  if (last_element_) {
    last_element_->next_ = nodo;
  }
  last_element_ = nodo;
  size_++;
}

// Skipping elements in testPila.cc?
NodoCola* Cola::pop() {
  if (first_element_) {
    std::cout << "at pop\n" << std::endl;

    NodoCola* aux = first_element_;
    NodoCola* auxVal = new NodoCola(aux->aficionado_, nullptr);
    
    std::cout << "value of popped node: " << auxVal->aficionado_ << std::endl;
    
    first_element_ = first_element_->next_;
    if (!first_element_) {
      last_element_ = nullptr;
    }
    delete aux;
    size_--;
    return auxVal;
  }
  return nullptr;
}
NodoCola* Cola::front() {
  return first_element_;
}
NodoCola* Cola::back() {
  return last_element_;
}
NodoCola* Cola::merge_sort(NodoCola* head) {
  if (!head || !head->next_) {
    return head;
  }

  //Turtle and hare algorithm to get to the middle
  NodoCola* slow = head;
  NodoCola* fast = head;
  NodoCola* prev = nullptr;
  while (fast && fast->next_) {
    prev = slow;
    slow = slow->next_;
    fast = fast->next_->next_;
  }
  //Split the list in half
  prev->next_ = nullptr;
  
  NodoCola* left = merge_sort(head);
  NodoCola* right = merge_sort(right);

  //At this point left and right are two different sorted-in-ascending-order lists which we can just merge like this
  NodoCola* dummy = new NodoCola(nullptr, nullptr);
  NodoCola* aux = dummy;
  while (left && right) {
    int left_arrival_time = left->aficionado_->get_arrival_time();
    int right_arrival_time = right->aficionado_->get_arrival_time();
    if (left_arrival_time < right_arrival_time) {
      aux->next_ = left;
      left = left->next_;
    } else {
      aux->next_ = right;
      right = right->next_;
    }
    aux = aux->next_;
  }
  if (left) {
    aux->next_ = left;
  } else if (right) {
    aux->next_ = right;
  }
  return dummy->next_;
}
NodoCola* Cola::sortList(NodoCola* head) {
  // This way we guarantee length of at least 2 for ordering and merging
  std::cout << "SORTING" << std::endl;
  std::cout << "GOT THIS LIST" << std::endl;
  NodoCola* copy = head;
  while (copy) {
    std::cout << copy->get_aficionado() << std::endl;
    copy = copy->next_;
  }

  if (!head || !head->next_) {
      return head;
  }

  //Get middle node in {slow} by turtle and hare algo
  NodoCola* slow = head;
  NodoCola* fast = head->next_;
  while (fast && fast->next_) {
      slow = slow->next_;
      fast = fast->next_->next_;
  }

  NodoCola* fH = head;
  NodoCola* sH = slow;
  NodoCola* tmp = sH->next_;
  sH->next_ = nullptr;
  sH = tmp;
  
  std::cout << "CURRENT FIRST HALF: " << std::endl;
  NodoCola* fhCopy = fH;
  while (fhCopy) {
    std::cout << fhCopy->get_aficionado() << std::endl;
    fhCopy = fhCopy->next_;
  }

  std::cout << "CURRENT SECOND HALF: " << std::endl;
  NodoCola* shCopy = sH;
  while (shCopy) {
    std::cout << shCopy->get_aficionado() << std::endl;
    shCopy = shCopy->next_;
  }

  fH = sortList(fH);
  sH = sortList(sH);

  // At this point, because of recursion first half will contain one node and second half another node
  // Now we have two nodes we can compare, we return a linked list of size 2 the first time this is called.
  // The second time this is called it will have 2 linked lists of size 2 merged into one and it keeps going
  NodoCola* dummy = new NodoCola(nullptr, nullptr);
  NodoCola* tail = dummy;
  while (fH && sH) {
      int fHat = fH->get_aficionado()->get_arrival_time();
      int sHat = sH->get_aficionado()->get_arrival_time();
      std::cout << "fHAT: " << fHat << " sHAT: " << sHat << std::endl;
      if (fHat < sHat) {
          tail->next_ = fH;
          fH = fH->next_;
      } else {
          tail->next_ = sH;
          sH = sH->next_;
      }
      tail = tail->next_;
  }
  if (fH) {
      tail->next_ = fH;
  }
  if (sH) {
      tail->next_ = sH;
  }
  return dummy->next_;
}
void Cola::sort_list() {
  first_element_ = sortList(first_element_);
}
void Cola::show() {
  NodoCola* head = first_element_;
  while (head) {
    std::cout << head->aficionado_ << std::endl;
    head = head->next_;
  }
}

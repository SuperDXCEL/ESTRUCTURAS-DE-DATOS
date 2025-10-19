#include <iostream>
#include "../header/NodoCola.h"

class Solution {
public:
    NodoCola* sortList(NodoCola* head) {
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
        NodoCola* dummy2 = dummy;
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
        std::cout << dummy2 << std::endl;
//        while (dummy2) {
//          dummy2 = dummy2->next_;
//          std::cout << "AFICIONADO IN THIS ITERATION" << std::endl;
//          std::cout << dummy2->get_aficionado() << std::endl;
//        }
        return dummy->next_;
    }
};

NodoCola* iterative_sorting(NodoCola* head) {

}

int main() {
  Aficionado* aficionado = new Aficionado(6012, 3);
  Aficionado* aficionado2 = new Aficionado(5123, 1);
  Aficionado* aficionado3 = new Aficionado(4124, 0);
  Aficionado* aficionado4 = new Aficionado(4124, 4);
  Aficionado* aficionados[] = {aficionado, aficionado2, aficionado3, aficionado4};
  NodoCola* dummy = new NodoCola(nullptr, nullptr);
  NodoCola* first = dummy;
  for (int i = 0; i < (sizeof(aficionados) / sizeof(aficionados[0])); i++) {
    NodoCola* node = new NodoCola(aficionados[i], nullptr);
    first->next_ = node;
    first = first->next_;
    std::cout << "FIRST: " << node->get_aficionado() << std::endl;
  }
  Solution mySolution;
  NodoCola* sL = mySolution.sortList(dummy->next_);
  std::cout << "SORTED: " << std::endl;

  while (sL) {
    std::cout << sL->get_aficionado() << std::endl;
    sL = sL->next_;
  }
}

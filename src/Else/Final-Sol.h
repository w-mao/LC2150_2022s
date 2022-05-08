// Name:

#ifndef FINAL_H 
#define FINAL_H

#include <iostream>

class Final {
   public:
      Final();
      int length() const;
      void add(int x);

      void remove();

      void flip();

      friend std::ostream& operator << (std::ostream&, const Final&);
      
      Final(const Final&);
   
      Final& operator = (const Final& rtSide);

      ~Final(); 

   private:
      
      struct Node{
         int data;
         Node* next;
         Node(int d = 0, Node* n = nullptr){
         	data = d;
         	next = n;
         }


      };

      Node * head;
      Node * tail;
      void copyList(Node* p);

      void deleteList(Node *p);

      // can more functions if you want

};



Final::Final() {
   head = nullptr;
   tail = nullptr;
}

void Final::copyList(Node *p) {
   if(p){
      head = new Node(p->data,nullptr);
      tail = head;
      p = p->next;
      while(p){
         tail->next = new Node(p->data,nullptr);
         tail = tail->next;
         p = p->next;
      }
   }else{
      head = tail = nullptr;
   }

}

void Final::deleteList(Node *p) {
   while(p){
      Node* del = p;
      p = p->next;
      delete del;
   }
   head = tail = nullptr;

}

void Final::remove(){
   if(head){
      Node* del = head;
      head = head->next;
      delete del;
      if(!head){
         tail = nullptr;
      }
      
   }
}

int Final::length() const {
   int count;
   Node* p = head;
   while(p){
      count++;
      p = p->next;
   }
   return count;

}

void Final::add(int x) {
   if(!head){
      head = new Node{x,nullptr};
      tail = head;
   }else{
      tail->next = new Node{x,nullptr};
      tail = tail->next;
   }
   

}

std::ostream& operator << (std::ostream& out, const Final& f) { 
   out << "[ ";
   for(Final::Node* p = f.head; p; p = p->next){
      out << p->data << " ";
   }
   out << "]";
   return out;
}

void Final::flip(){
   if(!head || !head->next){
      return;
   }
   tail = head;
   Node*curr = head;
   Node*next = head->next;
   head->next = nullptr;
   
   while(next){
      head = next;
      next = next->next;
      head->next = curr;
      curr = head;
   }

}

Final::Final(const Final& other) {
  copyList(other.head);

}

Final& Final::operator = (const Final& other) {
   if(&other != this){
      deleteList(head);
      copyList(other.head);
   }
   return *this;

}

Final::~Final() {
   deleteList(head);

}

#endif 

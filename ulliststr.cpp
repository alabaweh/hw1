#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <string>
#include <iostream>

using namespace std;

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



void ULListStr::set_size(int i){

  if(size_==0 && i == -1)
      size_=0;
      else
  size_=size_+ i; 
}



void ULListStr::push_back(const std::string& val)
{
    Item *newNode;

    Item *currNode = nullptr;

    

    if (!head_) // if the head_ is empty
    {

      newNode = new Item;
        head_ = newNode;
        head_->val[head_->last]=val;
        head_->last++;
        tail_=head_;
    }

    else
    {
        currNode=tail_;

            if(currNode->last<=ARRSIZE-1){
            currNode->val[currNode->last]=val;
            currNode->last++;}

        else{

          newNode = new Item;

            currNode->next=newNode;
            newNode->prev=currNode;
            newNode->val[newNode->last]=val;
            newNode->next= nullptr;
            newNode->last++;
            tail_=newNode;
        }

    }

    set_size(1);


}



void ULListStr::push_front(const std::string& val) {


    Item *newNode;

    Item *currNode = nullptr;


    


    if (!head_)  // if the head_ is empty
    {

      newNode = new Item;
        head_ = newNode;
        head_->val[ARRSIZE-1]=val;
        head_->last=ARRSIZE;
        head_->first=ARRSIZE-1;
        tail_=head_;
    }

    
    else if(head_->first !=0){
        head_->first--;
        head_->val[head_->first]=val;
 
    }

    else if(head_->first ==0){ // this is to check if there head_ is full
        
       
        newNode = new Item;
        currNode=head_;
        head_=newNode;
        head_->next=currNode;
        currNode->prev=head_;
        head_->val[ARRSIZE-1]=val;
        head_->last=ARRSIZE;
        head_->first=ARRSIZE-1;

    }

    set_size(1);
}


void ULListStr::pop_front(){

    if(!head_)
        return;

    Item *currNode = nullptr;


    if(head_->first==9 ||  head_->first == head_->last -1){

        currNode=head_;

        if(!(head_->next)){
           head_= nullptr;
           tail_=nullptr;
           }
        else{
        head_=head_->next;
        head_->prev= nullptr;
        // currNode= nullptr;
        }

         delete  currNode;
    }

    else{
        head_->val[head_->first]="";
        head_->first++;
    }

    set_size(-1);

}



void ULListStr::pop_back(){



    Item *currNode = nullptr;

    if(!tail_)
        return;


    if(tail_->last-1 != tail_->first){
        tail_->val[tail_->last-1]="";
        tail_->last--;

    }


    else{

        tail_->val[tail_->last-1]="";
        tail_->last--;

        if(head_ == tail_) {
            delete tail_;
            head_ = nullptr;
            tail_=nullptr;

        }
        else {
            currNode = tail_->prev;
            currNode->next = nullptr;
            delete tail_;
            tail_ = currNode;
        }
        

    }

   

    set_size(-1);

}




std::string const& ULListStr::back() const {

    return this->tail_->val[this->tail_->last-1];
}


std::string const & ULListStr::front() const{

    return this->head_->val[this->head_->first];

}


std::string* ULListStr::getValAtLoc(size_t loc) const {

    if(!head_)
        return nullptr;

    if (loc >= size_) {
        throw std::out_of_range("Index out of range");
    }

    Item *currNode = head_;

    while (( currNode != nullptr && loc >=(currNode->last - currNode->first))) {
        loc -= (currNode->last - currNode->first);
        currNode = currNode->next;
    }

    return &(currNode->val[currNode->first + loc]);

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

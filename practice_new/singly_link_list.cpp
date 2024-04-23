#include<iostream>
using namespace std;
template <typename T>

class ListNode{
private:
     int data;
     ListNode* next;
     ListNode* head;
     ListNode(T data){
        this->data=data;
        this->head=nullptr;
        if(head==nullptr){
            this->head=this;
        }else{
            this->head=head;
        }
     } 
     void insertatend(T data){
        ListNode* node = new ListNode;
        if(head==nullptr){
            head= node;
        }else{
            ListNode* temp = head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            head->next = node;
        } 
     }
     void deletenode(int key){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        if(temp!=nullptr && temp->data==key){
            head=temp->next;
            delete temp;
            return;
        }
        while(temp!=nullptr && temp->data!=key){
            prev=temp;
            temp=temp->next;
        }
        if(temp==nullptr)   return;
        prev->next=temp->next;
        delete temp;
     }
     void printlist(){
        ListNode* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
     }
};

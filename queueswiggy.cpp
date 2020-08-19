#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int item_code;
    struct Node* next;
};


class SwiggyQueue{
    private:
        struct Node* head;
    public:
        SwiggyQueue(){
            head=NULL;
        }
        void newOrder(int item_code){
            struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
            temp->item_code=item_code;
            temp->next=head;
            head=temp;
        }
        void showAllOrders(){
            cout<<"\nAll Pending orders In Queue"<<endl;
            struct Node* temp=head;
            while(temp){
                cout<<"Item Code:"<<temp->item_code<<endl;
                temp=temp->next;
            }
        }
        void currentlyPreparingOrder(){
            struct Node* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            cout<<"\nCurrently Preparing: "<<temp->item_code<<endl;
        }
};


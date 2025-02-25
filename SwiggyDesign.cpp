#include<iostream>
#include<stdlib.h>
#include <unordered_map>
#include "queueswiggy.cpp"
using namespace std;

// menuCard category
struct menuCardCategory{
    int item_code;
    float price;
};

// restaurant
struct NodeRestraunt{
	//	menuCard is map of category and pointer to LinkedList containing items under the category
	string name;
    struct menuCardCategory* menuCard;
	//	queue will contain the orderes recieved by the restaurant
    SwiggyQueue swiggyqueue;
	struct NodeRestraunt* next;
};

class Swiggy{
	private:
		struct NodeRestraunt* head;
		unordered_map<string,struct NodeRestraunt*> SwiggyHash;

	public:
		Swiggy(){
			head=NULL;
		}
		void register_restraunt(string name);
		void updateMenuCard(string res_name);
		void order(string name,int item_number);
        void listRestrauntDetails(string res_name);
        void deleteOrder(string res_name,int item_code);
};

void Swiggy :: register_restraunt(string name){
	cout<<name<<" is now Registered under Chotta Swiggy!!"<<endl;
	struct NodeRestraunt* temp=(struct NodeRestraunt*)malloc(sizeof(struct NodeRestraunt));
	temp->name=name;
//	swiggyHash for searching restraunt by name
	SwiggyHash[name]=temp;
}


//	adding items to menu Card
void Swiggy :: updateMenuCard(string res_name){
	cout<<"\nUpdating MenuCard of "<<res_name<<endl;
	struct NodeRestraunt* temp=SwiggyHash[res_name];
    int number,item_code,price;
    cout<<"\nEnter number of items to be inserted: "<<endl;
    cin>>number;
    temp->menuCard=(struct menuCardCategory*)malloc(sizeof(menuCardCategory)*number);
//	categories for menuCard
    for(int i=1;i<=number;i++){
        cout<<i<<" Enter item code: "<<endl;
        cin>>temp->menuCard[i-1].item_code;
        cout<<i<<" Enter price: "<<endl;
        cin>>temp->menuCard[i-1].price;
    }
}


// to place order in particular restraunt with given item number
void Swiggy :: order(string res_name,int item_number){
	cout<<"\nItem number "<<item_number<<" has been assigned to "<<res_name<<endl;
	struct NodeRestraunt* res=SwiggyHash[res_name];
	res->swiggyqueue.newOrder(item_number);
}

// to list all the orders of restaurant
void Swiggy :: listRestrauntDetails(string res_name){
    struct NodeRestraunt* temp=SwiggyHash[res_name];
    cout<<"\nRestaurant Name: "<<temp->name<<endl;
    temp->swiggyqueue.currentlyPreparingOrder();
    temp->swiggyqueue.showAllOrders();
}



void Swiggy :: deleteOrder(string res_name,int itemCode){
    struct NodeRestraunt* temp=SwiggyHash[res_name];
    temp->swiggyqueue.removeOrder(itemCode);
}

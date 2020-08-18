#include<iostream>
#include<stdlib.h>
#include<queue>
#include <unordered_map>
using namespace std;

struct NodeRestraunt{
	//	menuCard is map of category and pointer to LinkedList containing items under the category
	string name;
	unordered_map<int,int*> menuCard; 
	//	queue will contain the orderes recieved by the restraunt...
	queue<int> orders;
	struct Node* next;
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
//		category 0 for breakfast, 1 for lunch, 2 for dinner
		void updateMenuCard(string res_name,int category);
//		pass restraunt name to oder
		void order(string name,int item_number);
//		getting detail of particular restaurant by name
		void listRestrauntDetails(string name);
//		Listing Summary of all the registered restaurants
//		void listFullSummary(string res_name);
};

void Swiggy :: register_restraunt(string name){
	cout<<name<<" is now Registered under Chotta Swiggy!!"<<endl;
	struct NodeRestraunt* temp=(struct NodeRestraunt*)malloc(sizeof(struct NodeRestraunt));
	temp->name=name;
//	swiggyHash for searching restraunt by name
	SwiggyHash[name]=temp;
//	categories for menuCard
	temp->menuCard[0]=NULL;
	temp->menuCard[1]=NULL;
	temp->menuCard[2]=NULL;
}


//	to update menuCard
void Swiggy :: updateMenuCard(string res_name,int category){
	cout<<"Updating MenuCard category number: "<<category<<" under "<<res_name<<endl;
	struct NodeRestraunt* res=SwiggyHash[res_name];
//	make linked list insertion here
	res->menuCard[category]=NULL;
}


// to place order in particular restraunt with given item number
void Swiggy :: order(string res_name,int item_number){
	cout<<"Item number "<<item_number<<" has been assigned to "<<res_name<<endl;
	struct NodeRestraunt* res=SwiggyHash[res_name];
	res->orders.push(item_number);
}


int main(){
	Swiggy s1;
	s1.register_restraunt("Buddhu Halwai");
}

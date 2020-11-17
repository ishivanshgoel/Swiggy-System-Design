#include<iostream>
#include "SwiggyDesign.cpp"
using namespace std;


int main(){
	Swiggy s1;
	s1.register_restraunt("Gopal Sweets");

    // s1.updateMenuCard("Gopal Sweets");

    s1.order("Gopal Sweets",123);
    s1.order("Gopal Sweets",150);
    s1.order("Gopal Sweets",256);
    s1.listRestrauntDetails("Gopal Sweets");
    s1.deleteOrder("Gopal Sweets",123);
    s1.deleteOrder("Gopal Sweets",150);
    s1.deleteOrder("Gopal Sweets",150);
    s1.listRestrauntDetails("Gopal Sweets");
}

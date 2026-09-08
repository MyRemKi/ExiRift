#include "Inventory.h"

Inventory::Inventory()
{

}

void Inventory::Print(char c){
    if(c == 'i'){
        cout<<"----------ITEM PART----------"<<endl;
        cout<<"Name | ID "<<endl;
        for(int i=0;i<inventory.size();i++){
            cout<<i<<" | ";
            cout<<inventory[i].name<<" | "<<inventory[i].id<<endl;
        }
    }
    else if(c == 'w'){
        cout<<"---------WEAPON PART---------"<<endl;
        for(int i=0;i<weapon.size();i++){
            cout<<i<<" | ";
            cout<<inventory[i].name<<" | "<<inventory[i].id<<endl;
        }
    }
    if(c == 'm'){
        for(int i=0;i<module.size();i++){
            cout<<i<<" | ";
            cout<<inventory[i].name<<" | "<<inventory[i].id<<endl;
        }
    }

}

//TODO 

void Inventory::Help(){
    cout<<"Coming soon..."<<endl;
}

Inventory::~Inventory()
{

}
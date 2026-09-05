#include "Player.h"

Player::Player(int h, int a)
    : health(h), attack(a)
{

}

void Player::printItems() const
{
    cout<< "Player Inventory: " <<endl;
    if(inventory.empty()) {
        cout<< "No items in inventory." <<endl;
    } 
    else {
        for (const auto& item : inventory) {
            cout << "--------------------" <<endl;
            cout << "Item Name: " << item.name <<" | Type: " << item.type <<" | Rarity: " << item.rarity <<" | ID: " << item.id << endl;
            cout<<"--------------------" <<endl;
        }
    }
}

Player::~Player()
{

}
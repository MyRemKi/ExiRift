#include <iostream>
using namespace std;
#include "Random.h"
#include "Rules.h"
#include "DropRules.h"
#include "Player.h"
#include <stdlib.h>
#include <chrono>   // Pour std::chrono::seconds
#include <thread>   // Pour std::this_thread::sleep_for
#include <iostream>
#include <string>
#include <sstream>

void test_1(){
    int randomInt = Random::getInt(1, 100);
    float randomFloat = Random::getFloat(0.0f, 1.0f);
    bool result = Random::rollChance(0.5f);

    cout << "Random Int: " << randomInt << endl;
    cout << "Random Float: " << randomFloat << endl;
    cout << "Roll Chance (50%): " << (result ? "Success" : "Failure") << endl;
}

void test_2(){
    Rules rules;
    rules.printItems();
    
    cout << "randomDropItem: " << endl;
    DropRules dropRules;
    Mob *mob = new Mob(MobType::Basic);
    Item item = dropRules.dropItem(rules, *mob);
    cout << "Dropped Item: " << item.name << endl;
    delete mob;
}

void test_3(int count=0){
    Rules rules;
    DropRules dropRules;
    Player player(100, 10); // Example player with 100 health and 10 attack
    vector<Mob*> mobs;

    for(int i = 0; i < count; ++i) {
        MobType mobType;

        if(Random::rollChance(0.01f)) { 
            mobType = MobType::Boss;
        } else if (Random::rollChance(0.2f)) {
            mobType = MobType::MiniBoss;
        }
        else {
            mobType = MobType::Basic;
        }
        Mob *mob = new Mob("mob" + to_string(i), 100, 2, 30, mobType);
        mobs.push_back(mob);
    }
    while(!mobs.empty()) {
        Mob *mob = mobs.back();
        while(mob->health > 0) {
            system("cls");
            cout<<"choisi ta position d'action (ex: attack) : "<<endl;
            string request; // Example damage value
            request = "attack"; // For testing purposes, we simulate an attack command
            if(request == "attack") {
                mob->health = 0/*-= player.SetHit()*/; // Example damage value
                cout << "Attacked mob! Remaining health: " << mob->type<< endl;
            } else if(request == "inventory") {
                player.printItems();
                bool backToGame = false;
                while(!backToGame) {
                    cout << "Type 'back' to return to the game." << endl;
                    string inventoryRequest;
                    cin >> inventoryRequest;
                    if(inventoryRequest == "back") {
                        backToGame = true;
                    } else {
                        cout << "Unknown command." << endl;
                    }
                }
            } else if(request == "exit") {
                cout << "Exiting the game." << endl;
                break;
            } else {
                cout << "Unknown command." << endl;
            }
        }
        system("cls");
        if(mob->health <= 0) {
            cout << "Mob defeated!" << endl;
            Item item = dropRules.dropItem(rules, *mob);
            cout <<"---------------------" <<endl;
            cout << "Dropped Item: " << item.name << endl;
            cout << "Dropped type: " << item.type << endl;
            cout << "Dropped rarity: " << item.rarity << endl;
            cout << "Dropped id: " << item.id << endl;
            cout <<"---------------------" <<endl;
            player.AddItem(item);
            cout << "Item added to inventory." << endl;
            delete mob;
            mobs.pop_back();
        }
        system("cls");
    }
    player.printItems();
}

int main() {
    std::string ligne;

    std::cout << "Mini-terminal. Tape 'exit' pour quitter.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, ligne);

        std::istringstream flux(ligne);
        std::string commande;
        flux >> commande;

        if (commande == "exit") {
            break;
        }
        if (commande == "clear") {
            system("cls");
        }
        else if (commande == "test") {
            std::string option;
            flux >> option;

            if (option == "-n") {
                std::string valeur;
                if (!(flux >> valeur)) {
                    std::cout << "Erreur : -n attend une valeur\n";
                    continue;
                }

                // --- On regarde QUELLE valeur pour savoir la suite ---
                if (valeur == "1") {
                    test_1();
                }
                else if (valeur == "2") {
                    test_2();
                }
                else if (valeur == "3") {
                    // -n 3 attend un -c ensuite
                    std::string suite;
                    if (!(flux >> suite) || suite != "-c") {
                        std::cout << "Erreur : -n 3 attend un -c ensuite\n";
                        continue;
                    }
                    std::string count;
                    if (!(flux >> count)) {
                        std::cout << "Erreur : -c attend une valeur\n";
                        continue;
                    }
                    test_3(std::stoi(count));
                }
                else {
                    std::cout << "Valeur de -n non geree : " << valeur << "\n";
                }
            }
            else {
                std::cout << "Option inconnue : " << option << "\n";
            }
        }
        else if (commande.empty()) {
            // rien
        }
        else {
            std::cout << "Commande inconnue : " << commande << "\n";
        }
    }

    return 0;
}
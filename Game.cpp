#include "Game.h"

Game::Game()
{
    this->PrintCommand();
    this->Init();
}

void Game::Init(){
    player = new Player(100,10);

    for(int i=0;i<SIZE_SPAWN_MOBS;i++){
        Mob * mob = new Mob("minimob",20,1,MobType::Basic);
        mobs.push_back(mob);
    }
}

void Game::Run(){
    string request="";
    while(this->loop){
        request = this->ReturnRequest();
        this->CommandSelectionToMethodCalling(request);
    }
}

void Game::Exit(){

}

string Game::ReturnRequest(){
    string request="";
    cout<<"/";
    cin >> request;
    return request;
}

void Game::CommandSelectionToMethodCalling(string &request){
    if(request == "play"){
        this->Play();
    }
    else if (request == "inventory"){
        this->CheckInventory();
    }
    else if(request == "equipment"){
        this->CheckEquipments();
    }
    else if(request == "help"){
        cout<<"-----------HELP PAGE-----------"<<endl;
        cout<<"play = to play the game "<<endl;
        cout<<"inventory = to open and check your inventory "<<endl;
        cout<<"equiment = to check your equipment (weapons and modules) "<<endl;
        cout<<endl;
        cout<<"-----FOR MORE INFORMATION-----"<<endl;
        cout<<"play -h"<<endl;
        cout<<"inventory -h"<<endl;
        cout<<"equipment -h"<<endl;
    }
    
    else{
        cout<<"retype your command please ..."<<endl;
    }
}

//PARTIE LOOP DU GAME
void Game::Play(){
    bool playloop=true;
    while(playloop){

    }
}

void Game::CheckInventory(){
    bool inventoryloop=true;
    string request="";
    cout<<"-----ITEMS-----"<<endl;
    while(inventoryloop){
        cin>>request;
        if(request == "show"){
            inventory->Print('i');
        }
        else if(request == "help"){
            inventory->Help();
        }
        else if(request == "exit"){
            inventoryloop=false;
        }
        else{
            cout<<"error command"<<endl;
        }
    }
}

void Game::CheckEquipments(){
    string request="";
    bool equipmentloop=true;
    while(equipmentloop){
        cin>>request;
        if(request == "show"){
            inventory->Print('w');
            inventory->Print('m');
        }
        else if(request == "help"){
            inventory->Help();
        }
        else if(request == "exit"){
            equipmentloop=false;
        }
        else{
            cout<<"error command"<<endl;
        }
    }
}

Game::~Game()
{

}
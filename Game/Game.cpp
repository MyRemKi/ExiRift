#include "Game.h"

Game::Game()
{
    this->PrintCommand();
    this->Init();
}

void Game::PrintCommand(){
    cout<<"-------- Command Avaible --------"<<endl;
    cout<<" - exit      : to leave the game"<<endl;
    cout<<" - play      : to begin the game"<<endl;
    cout<<" - inventory : check items "<<endl;
    cout<<" - equipment : check modules / equipments"<<endl;
    cout<<"-------- --------------- --------"<<endl;

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
    this->loop=false;
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
        this->PrintCommand();
        cout<<"----- FOR MORE INFORMATION -----"<<endl;
        cout<<"play -h"<<endl;
        cout<<"inventory -h"<<endl;
        cout<<"equipment -h"<<endl;
        cout<<"----- -------------------- -----"<<endl;
    }
    else if(request == "exit"){
        this->Exit();
    }
    
    else{
        cout<<"retype your command please ..."<<endl;
    }
}

//PARTIE LOOP DU GAME
void Game::Play(){
    bool playloop=true;
    cout<<"-------- Command Avaible --------"<<endl;
    cout<<" - generate mobs  : to leave the game"<<endl;
    cout<<" - attack         : to hit the mob   "<<endl;
    cout<<" - exit           : to exit the play"<<endl;
    cout<<"-------- --------------- --------"<<endl;
    while(playloop){
        string request="";

        if(request == "generate"){
            for(int i=1;i<10;i++){
                Mob * mob=new Mob("Basic Mob",rand.getInt(3,20),rand.getInt(1,3),MobType::Basic);
                mobs.push_back(mob);
            }
        }
        else if(request == "attack"){
            cout<<"attack"<<endl;
        }
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
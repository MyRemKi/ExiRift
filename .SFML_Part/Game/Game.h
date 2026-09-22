#ifndef GAME_H
#define GAME_H

#pragma once

class Game
{
public:
    Game();
    void Init();
    void Run();
    void Update();
    void Render();
    void HandleEvents();
    void CleanUp();
    ~Game();

private:

};

#endif
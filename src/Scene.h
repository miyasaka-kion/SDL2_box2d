#pragma once
#include <SDL2/SDL.h>
#include <algorithm>
#include <box2d/box2d.h>
#include <memory>
#include <vector>

#include "Box.h"
#include "Edge.h"
#include "Entity.h"

// should be a singleton
class Scene {
public:
    // Initialize the sdl window and sdl renderer, 
    // Initialize the world of box2d 
    // Load(TODO) and add all entities to the game.
    Scene();
    ~Scene();
    
    void run();

private:
    void init_sdl_window();
    void init_sdl_renderer();

    void loadEntities();
    void pollEvents();
    void refresh();
    void removeInactive();

public: 
    std::unique_ptr<b2World> world;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    std::vector<std::unique_ptr<Entity>> entityList;

    bool closeGame;
};
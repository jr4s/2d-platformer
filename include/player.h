#include "raylib.h"
#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    Texture2D texture;
    Vector2 position;
    Vector2 origin;
    Rectangle source;
    float rotation;
    float scale;
    
} Sprite;

typedef struct {
    float x, y;
    float vx, vy;
    float width, height;
    float jumpPower;
    float gravityPull;
    float collision;
    float fall;
    float speed;
    int onGround;
	
    Sprite sprite;  
} Player;


void InitPlayer(Player* player, float startX, float startY);
void UpdatePlayer(Player* player, float dt);
void DrawPlayer(Player* player);
void GroundCollision(Player* player, float groundY);

#endif

#include "raylib.h"
#include "player.h"
#include <math.h>

void InitPlayer(Player* player, float startX, float startY) {
    // Player Logic
    player->x = startX;
    player->y = startY;
    player->vx = 0;
    player->vy = 0;
    player->width = 120;
    player->height = 120;
    player->speed = 300;
    player->jumpPower = 300;
    player->gravityPull = 600;
    player->onGround = 0;
    

    // Player Sprite
    player->sprite.texture = LoadTexture("assets/player.png");
    player->sprite.position = (Vector2){player->x, player->y};
    player->sprite.origin = (Vector2){0, 0};  
    player->sprite.source = (Rectangle){0, 0, player->sprite.texture.width, player->sprite.texture.height};  
    player->sprite.rotation = 0.0f;
    player->sprite.scale = 1.0f;

    TraceLog(LOG_INFO, "Texture size: %d x %d", player->sprite.texture.width, player->sprite.texture.height);

    if (player->sprite.texture.id == 0) {
        TraceLog(LOG_ERROR, "Failed to load player texture");
    }
}

void GroundCollision(Player* player, float groundY) {
    if (player->y + player->height >= groundY) {
        player->collision = fabs(player->vy);
        player->y = groundY - player->height;
        player->vy = 0;
        player->onGround = 1;
    } else {
        player->onGround = 0;
        player->collision = 0;
    }
}

void UpdatePlayer(Player* player, float dt) {
    player->vy += player->gravityPull * dt;
    player->vx = 0;

    GroundCollision(player, 400);

    if (IsKeyDown(KEY_A)) {
        player->vx = -player->speed;
    } else if (IsKeyDown(KEY_D)) {
        player->vx = player->speed;
    }

    if (IsKeyPressed(KEY_SPACE) && player->onGround) {
        player->vy = -player->jumpPower;
        player->onGround = 0;
    }

    player->x += player->vx * dt;
    player->y += player->vy * dt;

    player->sprite.position = (Vector2){player->x, player->y};
}

void DrawPlayer(Player* player) {
    DrawTexturePro(
        player->sprite.texture,
        player->sprite.source,
        (Rectangle){player->x, player->y, player->width, player->height},
        player->sprite.origin,
        player->sprite.rotation,
        WHITE
    );
}

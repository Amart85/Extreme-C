// File name: ExtremeC_examples_chapter4_5_player.c
// Description: Implementation of the class Player

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "ExtremeC_examples_chapter4_5_gun.h"

// Attribute structure
typedef struct {
  char* name;
  struct gun_t* gun;
} player_t;

player_t* player_new() { return (player_t*)malloc(sizeof(player_t)); }

void player_ctor(player_t* player, const char* name) {
  player->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
  strcpy(player->name, name);
  // This is important. We need to nullify aggregation pointers if they
  // are not meant to be set in constructor.
  player->gun = NULL;
}

void player_dtor(player_t* player) { free(player->name); }

void player_pickup_gun(player_t* player, struct gun_t* gun) {
  // Here, we establish the aggregation relation.
  player->gun = gun;
}

void player_shoot(player_t* player) {
  // We need to check if the player has picked up th gun
  // otherwise, shooting is meaningless
  if (player->gun) {
    gun_trigger(player->gun);
  } else {
    printf("Player wants to shoot but he has not gun! A logical error has happened!");
    exit(1);
  }
}

void player_drop_gun(player_t* player) {
  // After the following line the aggregation relation ends between
  // two objects. Note that the object gun should not be freed since
  // this object is not its owner like composition.
  player->gun = NULL;
}

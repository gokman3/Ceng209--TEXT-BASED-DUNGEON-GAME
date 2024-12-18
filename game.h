#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Creature {
    char name[50];
    int health;
    int strength;
} Creature;

typedef struct Item {
    char name[50];
    char description[250];
    int effect;
    char type;
} Item;

typedef struct Room{
   char room_Name[50];
   char description[300];
   Item *item;
   Item *item2;
   Creature *creature;
   

}Room;

typedef struct Player {
    int health;
    int strength;
    Item inventory[MAX_ITEMS];
    Room *current_room;
    Item *equipped_weapon;
    Item *equipped_armor;
} Player;


void create_player();
void initialize_rooms_creatures_and_items();
void look();
void move(char *direction);
void inventory();
void pickup();
void equip(char *item_name);
void drop(char *item_name);
void attack();
void map(Room rooms[4][4]);
void player_info();
void dungeon_info();
void save_game(char *filepath);
void load_game(char *filepath);

#endif

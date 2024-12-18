#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"


Player player;
Room room1, room2, room3, room4,room5,room6,room7,room8,room9,room10;
Room rooms[4][4];
Creature goblin,goblin2,elf,wizard,ogre,bear,boss,boss2,boss3;
Item sword,sword2, axe, bow, armor,sword3, armor2, sword4, armor3;
int count=0;

//Function that creates the character
void create_player() {
    player.health = 100;
    player.strength = 10;
    player.current_room = &rooms[0][0];
    memset(player.inventory, 0, sizeof(player.inventory));
    player.equipped_weapon = NULL;
    player.equipped_armor = NULL;
}

//Function that creates rooms, monsters and items
void initialize_rooms_creatures_and_items() {
    strcpy(goblin.name, "Goblin");
    goblin.health = 50;
    goblin.strength = 5;
    strcpy(goblin2.name, "Superior Goblin");
    goblin2.health = 75;
    goblin2.strength = 10;
    strcpy(elf.name, "Elf");
    elf.health = 75;
    elf.strength = 15;
    strcpy(wizard.name, "Wizard");
    wizard.health = 50;
    wizard.strength = 20;
    strcpy(ogre.name, "Ogre");
    ogre.health = 150;
    ogre.strength = 5;
    strcpy(bear.name, "Bear");
    bear.health = 120;
    bear.strength = 8;
    strcpy(boss.name, "Super Goblin");
    boss.health = 100;
    boss.strength = 12;
    strcpy(boss2.name, "Wizard King");
    boss2.health = 150;
    boss2.strength = 20;
    strcpy(boss3.name, "Warrior");
    boss3.health = 200;
    boss3.strength = 20;

    strcpy(sword.name,"Wooden Sword");sword.effect=5;sword.type='W';
    strcpy(sword.description,"Simple weapon to attack enemies.Increase strength +5");
    strcpy(sword2.name,"Stone Sword");sword2.effect=7;sword2.type='W';
    strcpy(sword2.description,"Better than wood.Increase strength +7");
    strcpy(axe.name,"Axe");axe.effect=10;axe.type='W';
    strcpy(axe.description,"Deals devastating blows to enemies.Increase strength +10");
    strcpy(bow.name,"Bow");bow.effect=12;bow.type='W';
    strcpy(bow.description,"Can attack enemies from a distance.Increase strength +12");
    strcpy(armor.name,"Chain Armor");armor.effect=10;armor.type='A';
    strcpy(armor.description,"Simple protection.Increase health +10");
    strcpy(sword3.name,"Iron Sword");sword3.effect=15;sword3.type='W';
    strcpy(sword3.description,"Very suitable for war.Increase strength +15");
    strcpy(armor2.name,"Iron Armor");armor2.effect=20;armor2.type='A';
    strcpy(armor2.description,"High protection against attacks.Increase health +20");
    strcpy(sword4.name,"Diamond Sword");sword4.effect=30;sword4.type='W';
    strcpy(sword4.description,"Most Powerful weapon.Increase strength +30");
    strcpy(armor3.name,"Diamond Armor");armor3.effect=50;armor3.type='A';
    strcpy(armor3.description,"Full protection against enemies.Increase health +50");


    strcpy(room1.room_Name,"Room1");
    strcpy(room1.description,"Starting room there is no creature in this room but this room have a item.");
    room1.creature=NULL;
    room1.item=&sword;
    rooms[0][0] = room1;
    strcpy(room2.room_Name,"Room2");
    strcpy(room2.description,"The first enemy you encounter is here and there is an item in the room.");
    room2.creature=&goblin;
    room2.item=&sword2;
    rooms[0][1]=room2;
    strcpy(room3.room_Name,"Room3");
    strcpy(room3.description,"A room full of goblin soldiers A powerful goblin is eager to face you.");
    room3.creature=&goblin2;
    room3.item=&axe;
    rooms[0][2]=room3;
    strcpy(room4.room_Name,"Room4");
    strcpy(room4.description,"The area where the goblin king is located.");
    room4.creature=&boss;
    room4.item=&armor;
    rooms[0][3]=room4;
    strcpy(room5.room_Name,"Room5");
    strcpy(room5.description,"An elf welcomes you at the beginning of the path to a dark and dangerous forest.");
    room5.creature=&elf;
    room5.item=&bow;
    rooms[1][1]=room5;
    strcpy(room6.room_Name,"Room6");
    strcpy(room6.description,"A dangerous area where wizards live.");
    room6.creature=&wizard;
    room6.item=&sword3;
    rooms[2][1]=room6;
    strcpy(room7.room_Name,"Room7");
    strcpy(room7.description,"Home of the wizard king you will face a powerful enemy.");
    room7.creature=&boss2;
    room7.item=&armor2;
    rooms[3][1]=room7;
    strcpy(room8.room_Name,"Room8");
    strcpy(room8.description,"A scary dark and dangerous place.");
    room8.creature=&bear;
    room8.item=&sword4;
    rooms[2][2]=room8;
    strcpy(room9.room_Name,"Room9");
    strcpy(room9.description,"The region where powerful and mighty ogres live.");
    room9.creature=&ogre;
    room9.item=&armor3;
    rooms[2][3]=room9;
    strcpy(room10.room_Name,"Room10");
    strcpy(room10.description,"An arena where the strongest warriors appear.");
    room10.creature=&boss3;
    rooms[3][3]=room10;
   
}

//function that gives us information about the room
void look() {
    Room *current = player.current_room;
    printf("Room: %s\n", current->room_Name);
    printf("Description: %s\n", current->description);

    if (current->creature) {
        printf("Creature: %s (Health: %d, Strength: %d)\n", 
               current->creature->name, current->creature->health, current->creature->strength);
    }
    if (current->item) {
        printf("Item: %s - %s\n", current->item->name, current->item->description);
    }
}

//Function that allows us to switch between rooms
void move(char *direction) {
    int currentRow, currentCol;

    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (&rooms[i][j] == player.current_room) {
                currentRow = i;
                currentCol = j;
                break;
            }
        }
    }

    
    int newRow = currentRow;
    int newCol = currentCol;

    if (strcmp(direction, "up") == 0) {
        newRow--;
    } else if (strcmp(direction, "down") == 0) {
        newRow++;
    } else if (strcmp(direction, "left") == 0) {
        newCol--;
    } else if (strcmp(direction, "right") == 0) {
        newCol++;
    } else {
        printf("Invalid direction. Use 'move up', 'move down', 'move left', or 'move right'.\n");
        return;
    }

   
    if (newRow < 0 || newRow >= 4 || newCol < 0 || newCol >= 4) {
        printf("You cant move in that direction. There is a wall.\n");
        return;
    }

    if (strlen(rooms[newRow][newCol].room_Name) == 0) {
        printf("You cant move there. There is a wall.\n");
        return;
    }

    player.current_room = &rooms[newRow][newCol];
    printf("You moved to %s.\n", rooms[newRow][newCol].room_Name);
}
//function that gives us information about inventory
void inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strlen(player.inventory[i].name) > 0) {
            printf("- %s\n", player.inventory[i].name);
        }
    }
    if (player.equipped_weapon) {
        printf("Equipped Weapon: %s\n", player.equipped_weapon->name);
    }
    if (player.equipped_armor) {
        printf("Equipped Armor: %s\n", player.equipped_armor->name);
    }
}
//Function that allows us to use the item in the inventory
void equip(char *item_name) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(player.inventory[i].name, item_name) == 0) {
          
            if (player.inventory[i].type == 'W') {
                if (player.equipped_weapon) {
                    printf("Unequipping %s.\n", player.equipped_weapon->name);
                    player.strength -= player.equipped_weapon->effect;
                }
                player.equipped_weapon = &player.inventory[i];
                player.strength += player.equipped_weapon->effect;
                printf("Equipped weapon: %s. Strength is now %d.\n", 
                       player.equipped_weapon->name, player.strength);
                return;
            }
          
            else if (player.inventory[i].type == 'A') {
                if (player.equipped_armor) {
                    printf("Unequipping %s.\n", player.equipped_armor->name);
                    player.health -= player.equipped_armor->effect;
                }
                player.equipped_armor = &player.inventory[i];
                player.health += player.equipped_armor->effect;
                printf("Equipped armor: %s. Health is now %d.\n", 
                       player.equipped_armor->name, player.health);
                return;
            } else {
                printf("Cannot equip this item.\n");
                return;
            }
        }
    }
    printf("Item not found in inventory.\n");
}

//Function that allows us to retrieve the item in the room
void pickup() {
    if (!player.current_room->item) {
        printf("No items to pick up in this room.\n");
        return;
    }
    if(!player.current_room->creature){

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strlen(player.inventory[i].name) == 0) {
            player.inventory[i] = *player.current_room->item;
            printf("Picked up: %s\n", player.current_room->item->name);
            player.current_room->item = NULL;
            return;
        }
    }
    }else{
        printf("You can't pick this item because you haven t killed the creature in the room yet.");
        return;
    }
    printf("You cannot pick this item because your inventory is full.\n");

}

//Function that allows us to leave items in our inventory
void drop(char *item_name) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(player.inventory[i].name, item_name) == 0) {
            player.current_room->item = &player.inventory[i];
            printf("Dropped: %s\n", player.inventory[i].name);
            memset(&player.inventory[i], 0, sizeof(Item)); 
            return;
        }
    }
    printf("There is no such item in your inventory.\n");
}
//The function that allows us to fight creatures
void attack() {
    Room *current = player.current_room;
    if (!current->creature) {
        printf("No creature to attack in this room.\n");
        return;
    }

    printf("Attacking %s \n", current->creature->name);

    while (player.health > 0 && current->creature->health > 0) {
        
        current->creature->health -= player.strength;
        if (current->creature->health <= 0) {
            printf("You defeated %s!\n", current->creature->name);
            current->creature = NULL; 
            player.health+=50;
            count++;
            return;
        }

       
        player.health -= current->creature->strength;
        if (player.health <= 0) {
            printf("You were defeated by %s\n", current->creature->name);
            printf("You can continue from your last save.");
            exit(0); 
        }
    }
}
//Function that allows us to save the game
void save_game(char *filepath) {
    FILE *file = fopen(filepath, "w");
    if (!file) {
        printf("Error saving game.\n");
        return;
    }

    fwrite(&player, sizeof(Player), 1, file);
    fwrite(rooms, sizeof(rooms), 1, file);
    fwrite(&count,sizeof(count), 1,file);
    fclose(file);
    printf("Game saved to %s\n", filepath);
}
//Function that allows us to load the saved game
void load_game(char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Error loading game.\n");
        return;
    }

    fread(&player, sizeof(Player), 1, file);
    fread(rooms, sizeof(rooms), 1, file);
    fread(&count,sizeof(count), 1,file);
    fclose(file);
    printf("Game loaded from %s\n", filepath);
}
//function that displays the map
void map(Room rooms[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
            if (strlen(rooms[i][j].room_Name) > 0) {
                printf("%-15s", rooms[i][j].room_Name); 
            } else {
                printf("%-15s", "WALL");
            }
        }
        printf("\n"); 
    }
}
//Function that allows the player to get information about his strength and power
void player_info(){
    printf("Your health is %d\n",player.health);
    printf("Your strength is %d\n",player.strength);
}
//Function showing how many monsters are left
void dungeon_info(){
    printf("Number of remaining monsters: %d\n",9-count);
}

int main() {
    initialize_rooms_creatures_and_items();
    create_player();

    char command[50];
    //Menu showing what the commands in the game do
    printf("Welcome to Dungeon!\n");
    printf("How to play:\n");
    printf("To get information about the room you are in, use (look) command\n");
    printf("You can use the (move right/left/up/down) command for other rooms you can go to.\n");
    printf("To get information about your inventory, you can use (inventory) command\n");
    printf("You can use the (pickup) command to pick up the items in the room.\n");
    printf("You can use the (drop (item name)) command to drop an item in your inventory.\n");
    printf("You can use the (attack) command to attack the monsters in the room.\n");
    printf("You can use the (save) command to save the game or the (load (savename)) command to load a saved game;\n");
    printf("You can use the (exit) command to leave the game.\n");
    printf("You can look map with (map) command\n");
    printf("You can equip items with (equip itemname)command\n");
    printf("You can look you health and strength with (playerinfo) command.\n");
    printf("You can use (dungeoninfo) command to find out the number of remaining monsters.\n");
    printf("Now you are in the first room. The game has started.\n");
    

   //The loop that decides the action according to the command entered, which allows the player to play the game
   //Count is used to decide whether the game is over or not.
    while (count<9) {
        printf("\n> ");
        fgets(command, 50, stdin);
        command[strcspn(command, "\n")] = 0;
        

        if (strncmp(command, "look", 4) == 0) {
            look();
        } else if (strncmp(command, "move ", 5) == 0) {
            move(command + 5);
        } else if (strncmp(command, "inventory", 9) == 0) {
            inventory();
        } else if (strncmp(command, "pickup", 6) == 0) {
            pickup();
        } else if (strncmp(command, "drop ", 5) == 0) {
            drop(command + 5);
        } else if (strncmp(command, "attack", 6) == 0) {
            attack();
        } else if (strncmp(command, "save ", 5) == 0) {
            save_game(command + 5);
        } else if (strncmp(command, "load ", 5) == 0) {
            load_game(command + 5);
        } else if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting game. Goodbye.\n");
            break;
        }else if(strncmp(command, "map",3)==0){
            map(rooms);
        } else if(strncmp(command,"equip ",6)==0){
            equip(command + 6);
        } else if(strncmp(command,"playerinfo",10)==0){
            player_info();}
            else if(strncmp(command,"dungeoninfo",11)==0){
                dungeon_info();
            }
            else{
            printf("Unknown command. Try again.\n");
        }
    }
    if(count==9){
    printf("Congratulations, you killed all the creatures and completed the game successfully.\n");
        exit(0);
     }
    return 0;
}

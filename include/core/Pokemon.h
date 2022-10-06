#ifndef POKEMON_H
#define POKEMON_H

typedef struct{
    char name[25];
    float height;
    float weight;
    char category[25];
    char abilities[25];
}Data;

typedef struct{
    int HP;
    int attack;
    int defense;
    int s_attack;
    int s_defense;
    int speed;
}Stats;

typedef struct{
    Data PokemonData;
    Stats PokemonStats;
    char type[1024];
    char weakness[5][1024];
}Pokemon;

#endif
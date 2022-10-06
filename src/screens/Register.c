#include "../../include/screens/Register.h"

#include "../../include/core/Window_Utils.h"

#include "../../include/components/Input.h"
#include "../../include/components/Button.h"
#include "../../include/core/Pokemon.h"

#include "../../include/core/EventHandler.h"

#include <string.h>
#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>

char BUG_POKEMONS[19][255] = { "Caterpie", "Metapod", "Pinsir", "Pineco", "Wurmple", "Silcoon", "Cascoon", "Volbeat", "Illumise", "Kricketot", "Kricketune", "Burmy", "Karrablast", "Shelmet", "Accelgor", "Scatterbug", "Spewpa", "Grubbin", "Blipbug"};
float BUG_POKEMONS_HEIGHT[19] = { 0.3, 0.7, 1.5, 0.6, 0.3, 0.6, 0.7, 0.7, 0.3, 1, 0.2, 0.5, 0.4, 0.8, 0.3, 0.3, 0.4, 0.4 };
float BUG_POKEMONS_WEIGHT[19] = { 2.9, 9.9, 55.0, 7.2, 3.6, 10, 11.5, 17.7, 17.7, 2.2, 25.5, 3.4, 5.9, 7.7, 25.3, 2.5, 8.4, 4.4, 8};
char BUG_POKEMONS_CATEGORY[19][255] = { "Worm", "Coccon", "Stag Bettle", "Bagworm", "Worm", "Cocoon", "Cocoon", "Firefly", "Firefly", "Cricket", "Cricket", "Bagworm", "Clamping", "Snail", "Shell Out", "Scatterdust", "Scatterdust", "Larva", "Larva" };
char BUG_POKEMONS_ABILITIES[19][255] = { "Shield Dust", "Shed Skin", "Hyper Cutter\nMold Breaker", "Sturdy", "Shield Dust", "Shed Skin", "Shed Skin", "Swarm\nIlluminate", "Tinted Lens\nOblivious", "Shed Skin", "Swarm", "Shed Skin", "Shed Skin\nSwarm", "Hydration\nShell Armor", "Hydration\nSticky Hold", "Shield Dust\nCompound Eyes", "Shed Skin", "Swarm", "Compound Eyes\nSwarm" };
int BUG_POKEMONS_HP[19] = {3, 3, 4, 3, 3, 3, 3, 4, 4, 3, 5, 3, 3, 3, 5, 3, 3, 3, 2};
int BUG_POKEMONS_ATTACK[19] = {2, 2, 8, 4, 3, 3, 3, 5, 3, 2, 5, 2, 5, 3, 5, 3, 2, 4, 2};
int BUG_POKEMONS_DEFENSE[19] = {3, 4, 6, 6, 3, 4, 4, 5, 5, 3, 3, 3, 3, 5, 3, 3, 4, 3, 2};
int BUG_POKEMONS_S_ATTACK[19] = {2, 2, 4, 3, 2, 2, 2, 2, 3, 5, 2, 4, 2, 3, 3, 6, 2, 4, 3};
int BUG_POKEMONS_S_DEFENSE[19] = {2, 2, 5, 3, 2, 2, 2, 5, 5, 3, 3, 3, 3, 4, 4, 2, 2, 3, 3};
int BUG_POKEMONS_SPEED[19] = {3, 2, 5, 1, 2, 1, 1, 5, 5, 2, 4, 3, 4, 3, 9, 3, 2, 3, 2};
char BUG_POISON_POKEMONS[11][255] = { "Weedle", "Kakuna", "Beedrill", "Venonat", "Venomoth", "Spinarak", "Ariados", "Dustox", "Venipede", "Whirlipede", "Scolipede"};


void DrawDataBox(Texture2D DataBox, char* input, FILE* SaveFile, Pokemon* Poke){
    //static char BUG_POKEMONS[19][255] = { "Cartepie", "Metapod", "Pinsir", "Pineco", "Wurmple", "Silcoon", "Cascoon", "Volbeat", "Illumise", "Kricketot", "Kricketune", "Burmy", "Karrablast", "Shelmet", "Accelgor", "Scatterbug", "Spewpa", "Grubbin", "Blipbug"};
    //static float BUG_POKEMONS_HEIGHT[19] = { 0.3, 0.7, 1.5, 0.6, 0.3, 0.6, 0.7, 0.7, 0.3, 1, 0.2, 0.5, 0.4, 0.8, 0.3, 0.3, 0.4, 0.4 };
    //static float BUG_POKEMONS_WEIGHT[19] = { 2.9, 9.9, 55.0, 7.2, 3.6, 10, 11.5, 17.7, 17.7, 2.2, 25.5, 3.4, 5.9, 7.7, 25.3, 2.5, 8.4, 4.4, 8};
    //static char BUG_POKEMONS_CATEGORY[19][255] = { "Worm", "Coccon", "Stag Bettle", "Bagworm", "Worm", "Cocoon", "Cocoon", "Firefly", "Firefly", "Cricket", "Cricket", "Bagworm", "Clamping", "Snail", "Shell Out", "Scatterdust", "Scatterdust", "Larva", "Larva" }; 
    //static char BUG_POISON_POKEMONS[11][255] = { "Weedle", "Kakuna", "Beedrill", "Venonat", "Venomoth", "Spinarak", "Ariados", "Dustox", "Venipede", "Whirlipede", "Scolipede"};
    char name[255];
    Pokemon pokemon;
    pokemon = *Poke;
    for(int i = 0; i < 19; i++){
        if(!strcmp(input, BUG_POKEMONS[i])){
            strcpy(pokemon.PokemonData.name, BUG_POKEMONS[i]);
            pokemon.PokemonData.height = BUG_POKEMONS_HEIGHT[i];
            pokemon.PokemonData.weight = BUG_POKEMONS_WEIGHT[i];
            strcpy(pokemon.PokemonData.category, BUG_POKEMONS_CATEGORY[i]);
            strcpy(pokemon.PokemonData.abilities, BUG_POKEMONS_ABILITIES[i]);
            strcpy(pokemon.type, "bug");
            pokemon.PokemonStats.HP = BUG_POKEMONS_HP[i];
            pokemon.PokemonStats.attack = BUG_POKEMONS_ATTACK[i];
            pokemon.PokemonStats.defense = BUG_POKEMONS_DEFENSE[i];
            pokemon.PokemonStats.s_attack = BUG_POKEMONS_S_ATTACK[i];
            pokemon.PokemonStats.s_defense = BUG_POKEMONS_S_DEFENSE[i];
            pokemon.PokemonStats.speed = BUG_POKEMONS_SPEED[i];
        }
    }
    for(int i = 0; i < 11; i++){
        if(!strcmp(input, BUG_POISON_POKEMONS[i])){
            strcpy(pokemon.PokemonData.name, BUG_POISON_POKEMONS[i]);
        }
    }
    if(strcmp(pokemon.PokemonData.name, "\0")){
        DrawText("Dados:", ScreenXRelatedSize(5), ScreenYRelatedSize(3.7), 24, BLACK);
        DrawTextureEx(DataBox, (Vector2){ScreenXRelatedSize(5), ScreenYRelatedSize(3.2)}, 0.f, 1.f, WHITE);
        DrawText("Altura", ScreenXRelatedSize(4.8), ScreenYRelatedSize(3), 20, BLACK);
        DrawText(TextFormat("%.1f m", pokemon.PokemonData.height), ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.75), 20, BLACK);
        DrawText("Peso", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.55), 20, BLACK);
        DrawText(TextFormat("%.1f kg", pokemon.PokemonData.weight), ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.40), 20, BLACK);
        DrawText("Categoria", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.20), 20, BLACK);
        DrawText(pokemon.PokemonData.category, ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.05), 20, BLACK);
        DrawText("Gênero", ScreenXRelatedSize(4.8), ScreenYRelatedSize(1.90), 20, BLACK);
        DrawText("F/M", ScreenXRelatedSize(4.8), ScreenYRelatedSize(1.80), 20, BLACK);
        DrawText("Habilidades", ScreenXRelatedSize(2.9), ScreenYRelatedSize(3), 20, BLACK);
        DrawText(pokemon.PokemonData.abilities, ScreenXRelatedSize(2.9), ScreenYRelatedSize(2.75), 20, BLACK);
    }
    else{
       DrawText("Dados:", ScreenXRelatedSize(5), ScreenYRelatedSize(3.7), 24, BLACK);
        DrawTextureEx(DataBox, (Vector2){ScreenXRelatedSize(5), ScreenYRelatedSize(3.2)}, 0.f, 1.f, WHITE);
        DrawText("Altura", ScreenXRelatedSize(4.8), ScreenYRelatedSize(3), 20, BLACK);
        DrawText("0.0 m", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.75), 20, BLACK);
        DrawText("Peso", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.55), 20, BLACK);
        DrawText("0.0 kg", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.40), 20, BLACK);
        DrawText("Categoria", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.20), 20, BLACK);
        DrawText("Nenhum.", ScreenXRelatedSize(4.8), ScreenYRelatedSize(2.05), 20, BLACK);
        DrawText("Gênero", ScreenXRelatedSize(4.8), ScreenYRelatedSize(1.90), 20, BLACK);
        DrawText("F/M", ScreenXRelatedSize(4.8), ScreenYRelatedSize(1.80), 20, BLACK);
        DrawText("Habilidades", ScreenXRelatedSize(2.9), ScreenYRelatedSize(3), 20, BLACK);
        DrawText("Nenhum.", ScreenXRelatedSize(2.9), ScreenYRelatedSize(2.75), 20, BLACK); 
    }
    *Poke = pokemon;
}

void DrawTypes(Markers AllMarkers, Pokemon Poke){
    DrawText("Tipo:", ScreenXRelatedSize(5), ScreenYRelatedSize(1.55), 24, BLACK);
    if(strcmp(Poke.type, "bug") || !strcmp(Poke.PokemonData.name, "\0"))
        DrawTextureEx(AllMarkers.Undefined, (Vector2){ScreenXRelatedSize(5), ScreenYRelatedSize(1.45)}, 0.f, 1.f, WHITE);
    else if(!strcmp(Poke.type, "bug")){
        DrawTextureEx(AllMarkers.Bug, (Vector2){ScreenXRelatedSize(5), ScreenYRelatedSize(1.45)}, 0.f, 1.f, WHITE);
    }
}

void DrawWeaknesses(Markers AllMarkers, Pokemon Poke){
    DrawText("Fraquezas: ", ScreenXRelatedSize(1.8), ScreenYRelatedSize(8), 24, BLACK);
    if(strcmp(Poke.type, "bug") || !strcmp(Poke.PokemonData.name, "\0"))
        DrawTextureEx(AllMarkers.Undefined, (Vector2){ScreenXRelatedSize(1.8), ScreenYRelatedSize(6)}, 0.f, 1.f, WHITE);
    else if(!strcmp(Poke.type, "bug")){
        DrawTextureEx(AllMarkers.Fire, (Vector2){ScreenXRelatedSize(1.8), ScreenYRelatedSize(6)}, 0.f, 1.f, WHITE);
        DrawTextureEx(AllMarkers.Flying, (Vector2){ScreenXRelatedSize(1.60), ScreenYRelatedSize(6)}, 0.f, 1.f, WHITE);
        DrawTextureEx(AllMarkers.Rock, (Vector2){ScreenXRelatedSize(1.44), ScreenYRelatedSize(6)}, 0.f, 1.f, WHITE);
    }
}

void DrawStats(Texture2D DataBox, Pokemon Poke){
    if(strcmp(Poke.PokemonData.name, "\0")){
        DrawText("Stats:", ScreenXRelatedSize(1.8), ScreenYRelatedSize(3.7), 24, BLACK);
        DrawTextureEx(DataBox, (Vector2){ScreenXRelatedSize(1.8), ScreenYRelatedSize(3.2)}, 0.f, 1.f, WHITE);
        DrawText("HP", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.92), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.92), floor(ScreenXRelatedSize(6)/15) * Poke.PokemonStats.HP, ScreenYRelatedSize(30), BLUE);
        DrawText("Attack", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.62), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.62), floor(ScreenXRelatedSize(6)/15) * Poke.PokemonStats.attack, ScreenYRelatedSize(30), BLUE);
        DrawText("Defense", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.40), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.40), floor(ScreenXRelatedSize(6)/15) * Poke.PokemonStats.defense, ScreenYRelatedSize(30), BLUE);
        DrawText("S. Attack", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.20), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.20), floor(ScreenXRelatedSize(6)/15) * Poke.PokemonStats.s_attack, ScreenYRelatedSize(30), BLUE);
        DrawText("S. Defense", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.03), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.03), floor(ScreenXRelatedSize(6)/15) * Poke.PokemonStats.s_defense, ScreenYRelatedSize(30), BLUE);
        DrawText("Speed", ScreenXRelatedSize(1.78), ScreenYRelatedSize(1.88), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(1.88), floor(ScreenXRelatedSize(6)/15) * Poke.PokemonStats.speed, ScreenYRelatedSize(30), BLUE);
    }
    else{
        DrawText("Stats:", ScreenXRelatedSize(1.8), ScreenYRelatedSize(3.7), 24, BLACK);
        DrawTextureEx(DataBox, (Vector2){ScreenXRelatedSize(1.8), ScreenYRelatedSize(3.2)}, 0.f, 1.f, WHITE);
        DrawText("HP", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.92), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.92), ScreenXRelatedSize(6), ScreenYRelatedSize(30), BLUE);
        DrawText("Attack", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.62), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.62), ScreenXRelatedSize(6), ScreenYRelatedSize(30), BLUE);
        DrawText("Defense", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.40), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.40), ScreenXRelatedSize(6), ScreenYRelatedSize(30), BLUE);
        DrawText("S. Attack", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.20), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.20), ScreenXRelatedSize(6), ScreenYRelatedSize(30), BLUE);
        DrawText("S. Defense", ScreenXRelatedSize(1.78), ScreenYRelatedSize(2.03), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(2.03), ScreenXRelatedSize(6), ScreenYRelatedSize(30), BLUE);
        DrawText("Speed", ScreenXRelatedSize(1.78), ScreenYRelatedSize(1.88), 20, BLACK);
        DrawRectangle(ScreenXRelatedSize(1.55), ScreenYRelatedSize(1.88), ScreenXRelatedSize(6), ScreenYRelatedSize(30), BLUE);
    }
}

CurrentScreen Register(Texture2D Background, Texture2D RegisterScreenBackground, Texture2D Small_Button, Texture2D Small_Hovered_Button, Texture2D Button, Texture2D HoveredButton, Texture2D Input, Texture2D DataBox, Markers AllMarkers, char* input, FILE* SaveFile, FILE* WriteIDsFile, FILE* ReadIDsFile){
    Pokemon pokemon;
    strcpy(pokemon.PokemonData.name, "\0");
    char SavedID[4];
    int IDs;
    fread(&SavedID, sizeof(char), 4, ReadIDsFile);
    if(!strcmp(SavedID, "\0")){
        IDs = 0;
    }
    else{
        IDs = atoi(SavedID);
    }
    

    BeginDrawing();
    ClearBackground(RAYWHITE);
    //Draw Background
    DrawTextureEx(Background, (Vector2){0, 0}, 0.f, 1.f, WHITE);
    DrawTextureEx(RegisterScreenBackground, CentralizeObject(RegisterScreenBackground.width, RegisterScreenBackground.height), 0.f, 1.f, WHITE);
    //Draw Exit Button.
    if(IsMouseHover(ScreenXRelatedSize(26), ScreenYRelatedSize(16), ScreenXRelatedSize(1.11), ScreenYRelatedSize(20))){
        DrawTextureEx(Small_Hovered_Button, (Vector2){ScreenXRelatedSize(1.11), ScreenYRelatedSize(20)}, 0.f, 1.f, WHITE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return MENU;
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else{
        //SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        DrawTextureEx(Small_Button, (Vector2){ScreenXRelatedSize(1.11), ScreenYRelatedSize(20)}, 0.f, 1.f, WHITE);
    }
    //Draw Input Part.
    DrawText("Nome do Pokémon:", ScreenXRelatedSize(5), ScreenYRelatedSize(8), 24, BLACK);
    InputComponent(Input, input, ScreenXRelatedSize(5), ScreenYRelatedSize(6));
    //Draw DataBox.
    DrawDataBox(DataBox, input, SaveFile, &pokemon);
    //Draw Pokémon Type Section
    DrawTypes(AllMarkers, pokemon);
    //Draw Pokémon Weaknesses.
    DrawWeaknesses(AllMarkers, pokemon);
    //Draw Pokémon Stats Box.
    DrawStats(DataBox, pokemon);
    //Save Button
    if(IsMouseHover(ScreenXRelatedSize(4), ScreenYRelatedSize(9), ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.25))){
        if(strlen(input) > 0){
            DrawTextureEx(HoveredButton, (Vector2){ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.28)}, 0.f, 1.f, WHITE);
            DrawText("Salvar Pokémon", ScreenXRelatedSize(2.5) + floor((Button.width/2) - MeasureText("Salvar Pokémon", 24)/2), ScreenYRelatedSize(1.28) + floor(Button.height/2 - 24/2), 24, BLACK);
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                fwrite(&pokemon, sizeof(pokemon), 1, SaveFile);
                IDs++;
                sprintf(SavedID, "%d", IDs); 
                fwrite(&SavedID, sizeof(char), 4, WriteIDsFile);
            }
        }
        else{
            DrawTextureEx(HoveredButton, (Vector2){ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.28)}, 0.f, 1.f, WHITE);
            DrawText("Salvar Pokémon", ScreenXRelatedSize(2.5) + floor((Button.width/2) - MeasureText("Salvar Pokémon", 24)/2), ScreenYRelatedSize(1.28) + floor(Button.height/2 - 24/2), 24, (Color){174, 150, 180, 255});
            SetMouseCursor(MOUSE_CURSOR_NOT_ALLOWED);
        }
    }
    else{
        DrawTextureEx(Button, (Vector2){ScreenXRelatedSize(2.5), ScreenYRelatedSize(1.28)}, 0.f, 1.f, WHITE);
        DrawText("Salvar Pokémon", ScreenXRelatedSize(2.5) + floor((Button.width/2) - MeasureText("Salvar Pokémon", 24)/2), ScreenYRelatedSize(1.28) + floor(Button.height/2 - 24/2), 24, (Color){174, 150, 180, 255});
        //SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    EndDrawing();
    return REGISTER;
}
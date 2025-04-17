#pragma once
#include "Informer.h"
#include "Ant.h"
#include <vector>

class AntHill; // обязательно, чтобы использовать ссылку или указатель на AntHill

class Vrag
{
private:
    int sila;
    
public:
    Vrag ( int sila_vraga );
    void Atakovat ( InformerSoldatov & informer, AntHill & muraveynik ); // 
};

#include "Vrag.h"
#include "AntHill.h"
#include <iostream>
#include <algorithm>
#include <random>

Vrag::Vrag ( int sila_vraga )
{
    sila = sila_vraga;
}

void Vrag::Atakovat ( InformerSoldatov & informer, AntHill & muraveynik )
{
    std::cout << "💥 ВРАГ НАПАЛ НА МУРАВЕЙНИК!\n";
    
    std::vector< Ant * > & vse = muraveynik.GetMuravi ();
    std::vector< Ant * > soldati;
    
    for ( Ant * a : vse )
          {
        if ( a->JavlyaetsyaSoldatom () )
              {
            soldati.push_back ( a );
              }
          }
    
    if ( soldati.empty () )
          {
        std::cout << "❌ Нет солдат! Враг убивает случайных муравьёв...\n";
        
        int skoko = std::min ( 2, ( int ) vse.size () );
        for ( int i = 0; i < skoko; ++i )
              {
            Ant * zhertva = vse[ rand () % vse.size () ];
            zhertva->PoluchitUron ( 40 ); // 
              }
        
            // Враг крадёт еду
        int ukrali = 10 + rand () % 6;
        muraveynik.ZabratEdyu ( ukrali );
        std::cout << "🍖 Враг украл " << ukrali << " еды!\n";
        
        return;
          }
    
        // Сражение
    int sila_vraga = 50 + rand () % 30;
    int sila_soldat = 0;
    
    for ( Ant * s : soldati )
          {
        int sila = 10 + rand () % 11;
        sila_soldat += sila;
        std::cout << s->GetOpisanie () << " бьёт врага с силой " << sila << "\n";
          }
    
    std::cout << "🔁 Сила врага: " << sila_vraga << ", сила солдат: " << sila_soldat << "\n";
    
    int ukradeno = 5 + rand () % 6;
    
    if ( sila_soldat >= sila_vraga )
          {
        std::cout << "✅ Враг был отброшен! Муравейник в безопасности.\n";
        muraveynik.DobavitEdy ( ukradeno * 2 );
        std::cout << "🎁 В награду муравейник получил " << ukradeno * 2 << " еды!\n";
          }
    else
          {
        std::cout << "❌ Солдаты проиграли. Враг пробрался в муравейник...\n";
        
        for ( Ant * s : soldati )
              {
            s->PoluchitUron ( 20 + rand () % 20 );
              }
        
        muraveynik.ZabratEdyu ( ukradeno );
        std::cout << "🍖 Враг украл " << ukradeno << " еды!\n";
          }
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#include "AntHill.h"
#include "Informer.h"
#include "Vrag.h"

int main ()
{
    srand ( time ( nullptr ) );
    
    AntHill muraveynik;
    
    InformerSoldatov informerSoldatov;
    InformerStroitelei informerStroitelei;
    InformerSobrately informerSobrately;
    
    for ( int i = 0; i < 5; i++ )
          {
        muraveynik.DobavitMuravya ();
          }
    
    int den = 1;
    
    while ( true )
          {
        std::cout << "\n=== День " << den << " ===\n";
        muraveynik.ZhiznCikla ();
        
            // Чередование событий
        if ( den % 7 == 0 )
              {
            Vrag vrag( 60 );
            vrag.Atakovat ( informerSoldatov, muraveynik );
              }
        
        if ( den % 5 == 0 )
              {
            informerStroitelei.Opozit ();
              }
        
        if ( den % 2 == 0 )
              {
            informerSobrately.Opozit ();
              }
        
            // Проверка на вымирание
        if ( muraveynik.VseMuraviUmerli () )
              {
            std::cout << "\n☠️  Все муравьи умерли... Муравейник опустел. Симуляция завершена.\n";
            break;
              }
        
        std::this_thread::sleep_for ( std::chrono::seconds ( 1 ) );
        den++;
          }
    
    return 0;
}

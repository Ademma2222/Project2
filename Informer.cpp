#include "Informer.h"
#include "Ant.h"

void InformerSoldatov::Opozit ()
{
    std::cout << "[Оповещение] Нападение! Солдаты реагируют!\n";
    for ( Ant * a : podpischiki )
          {
        a->ReagirovatNaVragov ();
          }
}

void InformerStroitelei::Opozit ()
{
    std::cout << "[Оповещение] Найдена тяжёлая ветка! Строители на помощь!\n";
    for ( Ant * a : podpischiki )
          {
        a->PomochStroitelstvu ();
          }
}

void InformerSobrately::Opozit ()
{
    std::cout << "[Оповещение] Большая еда! Собиратели бегут на помощь!\n";
    for ( Ant * a : podpischiki )
          {
        a->PomochSboru ();
          }
}

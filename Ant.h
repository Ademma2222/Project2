#pragma once
#include "Role.h"
#include "Informer.h"

#include <cstdlib>

class AntHill;

class Ant
{
private:
    int vozrast;
    int zdorovie;
    Role * rolya;
    AntHill * muraveynik;
    int id;
    static int sled_id;
  
   
    
    void UpdateRole ();
    
public:
    Ant ();
    ~Ant ();
    
    void Rosti ();
    void Zhivi ();
        // Обработка событий от информеров
    void ReagirovatNaVragov ();
    void PomochStroitelstvu ();
    void PomochSboru ();
    
        // Подписка и отписка на информеры
    void PodpisatsyaNaInformer ( Informer * );
    void OtpuditOtInformera ( Informer * );
    
    void PoluchitUron ( int uro );
    bool EstLiZhizn () const;
    
    void UstanovitSvyaz ( AntHill * ukazatel );
   ;
    
    int GetId () const;
    std::string GetOpisanie () const;
    
    bool JavlyaetsyaSoldatom () const;
    
    Role * GetRole () const;
    
    void Vosstanovit ( int k );
    
    AntHill * GetMuraveynik () const;
    
   
};




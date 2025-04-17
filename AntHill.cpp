#include "AntHill.h"
#include <iostream>

static const int MAX_ROJDENIY_V_DEN = 3;

AntHill::AntHill ()
{
    razmer = 1000;
    max_muravei = 100;
    eda = 100;
    vetki = 0;
    den = 1;
}

AntHill::~AntHill ()
{
    for ( Ant * a : muravi )
          {
        delete a;
          }
}

void AntHill::ZhiznCikla()
{
    
    
    std::vector< Ant * > zhivye;
    
    for ( Ant * ant : muravi )
          {
        if ( !ant ) continue;
        
        ant->Rosti();
        ant->Zhivi();
        
        if ( rand() % 100 < 50 )
              {
            int uro = 5 + rand() % 5;
            ant->PoluchitUron( uro );
              }
        
        if ( ant->EstLiZhizn() )
              {
            zhivye.push_back( ant );
              }
        else
              {
            delete ant;
              }
          }
    
    muravi = zhivye;
    
    UpdatitRazmer();
    
    if ( eda <= 0 )
          {
        std::cout << "⚠️  Еды нет! Все муравьи голодают!\n";
        for ( Ant * ant : muravi )
              {
            ant->PoluchitUron( 10 );
              }
          }
    else
          {
        int rashod = static_cast<int>( muravi.size() ) * 2;
        eda -= rashod;
        if ( eda < 0 ) eda = 0;
        
        std::cout << "🍽️  Муравьи поели. Осталось еды: " << eda << "\n";
        
        for ( Ant * ant : muravi )
              {
            ant->Vosstanovit( 10 );
              }
          }
    
        // Централизованное рождение муравьёв
    int skolko_rodit = 0;
    while ( skolko_rodit < MAX_ROJDENIY_V_DEN && eda >= 5 && muravi.size() < max_muravei )
          {
        Ant * noviy = PoyavlenieNovogoMuravya();
        if ( noviy )
              {
            muravi.push_back( noviy );
            skolko_rodit++;
              }
          }
    
    std::cout << "\nВыживших муравьёв: " << muravi.size() << "\n";
    for ( Ant * ant : muravi )
          {
        std::string rol = "без роли";
        if ( ant->JavlyaetsyaSoldatom() )
            rol = "солдат";
        else if ( dynamic_cast< Nurse * >( ant->GetRole() ) )
            rol = "нянька";
        else if ( dynamic_cast< Shepherd * >( ant->GetRole() ) )
            rol = "пастух";
        else if ( dynamic_cast< Forager * >( ant->GetRole() ) )
            rol = "собиратель";
        else if ( dynamic_cast< Builder * >( ant->GetRole() ) )
            rol = "строитель";
        else if ( dynamic_cast< Cleaner * >( ant->GetRole() ) )
            rol = "уборщик";
        
        std::cout << rol << " #" << ant->GetId() << "\n";
          }
    
    den++;
}

void AntHill::DobavitMuravya ()
{
    if ( ( int ) muravi.size () < max_muravei )
          {
        Ant * noviy = new Ant ();
        noviy->UstanovitSvyaz ( this );
        muravi.push_back ( noviy );
          }
}

int AntHill::GetEda () const
{
    return eda;
}

int AntHill::GetVetki () const
{
    return vetki;
}

void AntHill::DobavitEdy ( int kolvo )
{
    eda += kolvo;
    std::cout << "🍎 Муравейник получил " << kolvo << " еды. Всего: " << eda << "\n";
}

void AntHill::DobavitVetok ( int kolvo )
{
    vetki += kolvo;
    std::cout << "🪵 Муравейник получил " << kolvo << " веток. Всего: " << vetki << "\n";
}

void AntHill::UpdatitRazmer ()
{
    if ( vetki >= 10 )
          {
        vetki -= 10;
        razmer += 10;
        max_muravei += 1;
        std::cout << "🏠 Муравейник расширился! Размер: " << razmer << ", Макс. муравьёв: " << max_muravei << "\n";
          }
}

bool AntHill::VseMuraviUmerli () const
{
    return muravi.empty ();
}

std::vector< Ant * > & AntHill::GetMuravi ()
{
    return muravi;
}

void AntHill::ZabratEdyu ( int kolvo )
{
    eda -= kolvo;
    if ( eda < 0 ) eda = 0;
}

Ant * AntHill::PoyavlenieNovogoMuravya ()
{
    if ( muravi.size() >= max_muravei ) return nullptr;
    if ( eda < 5 ) return nullptr;
    
    Ant * noviy = new Ant ();
    noviy->UstanovitSvyaz ( this );
    eda -= 5;
    
    std::cout << "🐣 Новый муравей появился на свет!\n";
    return noviy;
}

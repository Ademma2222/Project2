#include "Ant.h"
#include "AntHill.h"
#include <sstream>

int Ant::sled_id = 1;

Ant::Ant ()
{
    vozrast = 0;
    zdorovie = 100;
    rolya = nullptr;
    muraveynik = nullptr;
    id = sled_id++;
    
  
}

Ant::~Ant ()
{
    delete rolya;
}

void Ant::Rosti ()
{
    vozrast++;
    UpdateRole ();
}

void Ant::UpdateRole()
{
    std::string staraia_rolya = "";
    if (rolya != nullptr)
          {
        if (dynamic_cast<Nurse*>(rolya))
            staraia_rolya = "нянька";
        else if (dynamic_cast<Soldier*>(rolya))
            staraia_rolya = "солдат";
        else if (dynamic_cast<Shepherd*>(rolya))
            staraia_rolya = "пастух";
        else if (dynamic_cast<Forager*>(rolya))
            staraia_rolya = "собиратель";
        else if (dynamic_cast<Builder*>(rolya))
            staraia_rolya = "строитель";
        else if (dynamic_cast<Cleaner*>(rolya))
            staraia_rolya = "уборщик";
          }
    
    delete rolya;
    
    if (vozrast < 2)
          {
        rolya = nullptr;
          }
    else if (vozrast < 6)
          {
        rolya = new Nurse();
          }
    else if (vozrast < 11)
          {
        rolya = (zdorovie > 50)
        ? static_cast<Role*>(new Soldier())
        : static_cast<Role*>(new Shepherd());
          }
    else if (vozrast < 30)  //
          {
        rolya = (rand() % 2 == 0)
        ? static_cast<Role*>(new Forager())
        : static_cast<Role*>(new Builder());
          }
    else // Если возраст >= 30, то становимся уборщиком
          {
        rolya = new Cleaner();
          }
    
    std::string novaya_rolya = "";
    if (rolya != nullptr)
          {
        if (dynamic_cast<Nurse*>(rolya))
            novaya_rolya = "нянькой";
        else if (dynamic_cast<Soldier*>(rolya))
            novaya_rolya = "солдатом";
        else if (dynamic_cast<Shepherd*>(rolya))
            novaya_rolya = "пастухом";
        else if (dynamic_cast<Forager*>(rolya))
            novaya_rolya = "собирателем";
        else if (dynamic_cast<Builder*>(rolya))
            novaya_rolya = "строителем";
        else if (dynamic_cast<Cleaner*>(rolya))
            novaya_rolya = "уборщиком";
          }
    
    if (!staraia_rolya.empty() && !novaya_rolya.empty() && staraia_rolya != novaya_rolya)
          {
        std::cout << GetOpisanie() << " стал " << novaya_rolya << ".\n";
          }
}


void Ant::Zhivi ()
{
    if ( rolya != nullptr )
          {
        rolya->Work ( this ); // передаём себя
        
        if ( muraveynik != nullptr )
              {
            if ( dynamic_cast< Forager * >( rolya ) )
                  {
                muraveynik->DobavitEdy ( 4 + rand () % 4 );
                  }
            
            if ( dynamic_cast< Builder * >( rolya ) )
                  {
                muraveynik->DobavitVetok ( 3 + rand () % 3 );
                  }
            
            
            
              }
          }
    else
          {
        std::cout << GetOpisanie () << " растет, пока без роли.\n";
          }
}

void Ant::ReagirovatNaVragov ()
{
    std::cout << "Муравей (возраст: " << vozrast << ") реагирует на врага.\n";
}

void Ant::PomochStroitelstvu ()
{
    std::cout << "Муравей помогает с тяжёлой веткой.\n";
}

void Ant::PomochSboru ()
{
    std::cout << "Муравей помогает донести еду.\n";
}

void Ant::PodpisatsyaNaInformer ( Informer * informer )
{
    informer->Podpisatsya ( this );
}

void Ant::OtpuditOtInformera ( Informer * informer )
{
    informer->Otpudit ( this );
}

void Ant::PoluchitUron ( int uro )
{
    zdorovie -= uro;
    
    std::cout << GetOpisanie () << " получил " << uro << " урона. Здоровье: " << zdorovie << "\n";
    
    if ( zdorovie <= 0 )
          {
        std::cout << "☠️  " << GetOpisanie () << " умер.\n";
          }
}
bool Ant::EstLiZhizn () const
{
    return zdorovie > 0;
}


void Ant::UstanovitSvyaz ( AntHill * ukazatel )
{
    muraveynik = ukazatel;
}

int Ant::GetId () const
{
    return id;
}

bool Ant::JavlyaetsyaSoldatom () const
{
    return dynamic_cast< Soldier * >( rolya ) != nullptr;
}

std::string Ant::GetOpisanie () const
{
    std::ostringstream potok;
    potok << "Муравей #" << id << " (";
    
    if ( rolya != nullptr )
          {
        if ( dynamic_cast< Nurse * >( rolya ) )
              {
            potok << "нянька";
              }
        else if ( dynamic_cast< Soldier * >( rolya ) )
              {
            potok << "солдат";
              }
        else if ( dynamic_cast< Shepherd * >( rolya ) )
              {
            potok << "пастух";
              }
        else if ( dynamic_cast< Forager * >( rolya ) )
              {
            potok << "собиратель";
              }
        else if ( dynamic_cast< Builder * >( rolya ) )
              {
            potok << "строитель";
              }
        else if ( dynamic_cast< Cleaner * >( rolya ) )
              {
            potok << "уборщик";
              }
        else
              {
            potok << "неизвестная роль";
              }
          }
    else
          {
        potok << "без роли";
          }
    
    potok << ")";
    return potok.str();
}

Role * Ant::GetRole () const
{
    return rolya;
}

void Ant::Vosstanovit ( int k )
{
    zdorovie += k;
    if ( zdorovie > 100 )
          {
        zdorovie = 100;
          }
}

AntHill * Ant::GetMuraveynik () const
{
    return muraveynik;
}



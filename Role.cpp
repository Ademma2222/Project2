#include "Role.h"
#include "Ant.h"
#include "AntHill.h"
#include <iostream>

void Nurse::Work ( Ant * kto )
{
    std::cout << kto->GetOpisanie () << " заботится о детях.\n";
 
}

void Soldier::Work ( Ant * kto )
{
    std::cout << kto->GetOpisanie () << " охраняет муравейник.\n";
}

void Shepherd::Work ( Ant * kto )
{
    std::cout << kto->GetOpisanie () << " присматривает за тлёй.\n";
}

void Forager::Work ( Ant * kto )
{
    std::cout << kto->GetOpisanie () << " ищет еду.\n";
}

void Builder::Work ( Ant * kto )
{
    std::cout << kto->GetOpisanie () << " укрепляет муравейник.\n";
}

void Cleaner::Work ( Ant * kto )
{
    std::cout << kto->GetOpisanie () << " чистит туннели.\n";
}

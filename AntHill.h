#pragma once
#include "Ant.h"
#include <vector>
//Ant * PoyavlenieNovogoMuravya ();
class AntHill
{
private:
    int razmer;
    int max_muravei;
    int eda;
    int vetki;
    std::vector< Ant * > muravi;
    int rozhdenoSegodnya = 0; 
    const int limitNaDen = 3; // максимум рождений в день
   
  
    int den;
    
public:
    AntHill ();
    ~AntHill ();
    
    void ZhiznCikla ();
    void DobavitMuravya ();
    int GetEda () const;
    int GetVetki () const;
    void DobavitEdy ( int );
    void DobavitVetok ( int );
    void UpdatitRazmer ();
    Ant * PoyavlenieNovogoMuravya ();
    bool VseMuraviUmerli () const;
    std::vector< Ant * > & GetMuravi ();
    void ZabratEdyu ( int kolvo );
    void DobavitNovorozhdennogo ( Ant * noviy );

};

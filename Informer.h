#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Ant; // forward declaration

class Informer
{
protected:
    std::vector< Ant * > podpischiki;
    
public:
    virtual ~Informer () {}
    
    void Podpisatsya ( Ant * a )
    {
  podpischiki.push_back ( a );
    }
    
    void Otpudit ( Ant * a )
    {
  podpischiki.erase (
                     std::remove ( podpischiki.begin (), podpischiki.end (), a ),
                     podpischiki.end ()
                     );
    }
    
    virtual void Opozit () = 0;
};

class InformerSoldatov : public Informer
{
public:
    void Opozit () override;
};

class InformerStroitelei : public Informer
{
public:
    void Opozit () override;
};

class InformerSobrately : public Informer
{
public:
    void Opozit () override;
};

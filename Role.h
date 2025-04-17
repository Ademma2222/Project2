#pragma once
#include <iostream>

class Ant; // f

class Role
{
public:
    virtual ~Role() {}
    virtual void Work ( Ant * kto ) = 0;
};

class Nurse : public Role
{
public:
    void Work ( Ant * kto ) override;
};

class Soldier : public Role
{
public:
    void Work ( Ant * kto ) override;
};

class Shepherd : public Role
{
public:
    void Work ( Ant * kto ) override;
};

class Forager : public Role
{
public:
    void Work ( Ant * kto ) override;
};

class Builder : public Role
{
public:
    void Work ( Ant * kto ) override;
};

class Cleaner : public Role
{
public:
    void Work ( Ant * kto ) override;
};

#pragma once
#include "game.h"


class Unit : public Cell {
protected:
    const double base_health;
    double health;
    double strength;
    bool _alive = true;
public:
    Unit(double b_hp);
    virtual void hit(Unit* a);
    virtual void takeHit(double damage);
    virtual void roar() = 0;
    virtual void status() = 0;
    bool alive() { return _alive; };
    void heal();

};


class Alien : public Unit {
public:
    void roar();
    void status();
    Alien(const double health, const double strenght);

};

class Predator : public Unit {
protected:
    double critical_coef;
public:
    void roar();
    void status();
    void hit(Unit* a);
    Predator(const double health, const double strenght, const double critical_coef);
    Predator(const double health, const double strenght);
};
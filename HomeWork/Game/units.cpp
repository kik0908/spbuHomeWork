#define ALIEN_CRY "I AM ALIEN"
#define PREDATOR_CRY "I AM PREDATOR"


#include "units.h"
#include <iostream>

void Unit::hit(Unit* a)
{
    a->takeHit(strength);
}

void Unit::takeHit(double damage)
{
    health -= damage;
    if (health <= 0) {
        this -> _alive = false;
    }
}

void Unit::heal()
{
    this->health = this->base_health;
}

Unit::Unit(const double b_hp) :base_health(b_hp) {

}

void Alien::roar()
{
    std::cout << ALIEN_CRY << '\n';
}

void Alien::status()
{
    std::cout << "Alien have " << this->health << "HP!\n";
}

Alien::Alien(const double health, const double strenght) : Unit(health){
    this->health = health;
    this->strength = strenght;
}

void Predator::roar()
{
    std::cout << PREDATOR_CRY << '\n';
}

void Predator::status()
{
    std::cout << "Predator have " << this->health << "HP!\n";
}

void Predator::hit(Unit* a)
{
    double dmg = this->strength;
    if (rand() % 100 <=35) {
        dmg *= this->critical_coef;
    }
    a->takeHit(dmg);
}

Predator::Predator(const double health, const double strenght, const double critical_coef) : Unit(health){
    this->critical_coef = critical_coef;
    this->health = health;
    this->strength = strenght;
}

Predator::Predator(const double health, const double strenght): Predator(health, strenght, 1) {}
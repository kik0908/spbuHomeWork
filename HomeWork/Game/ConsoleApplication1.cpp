#include <iostream>
#include "units.h"


void fight(Unit* a, Unit* b) {
    bool flag = rand() % 2;
    if (flag) {
        Unit* _ = a;
        a = b;
        b = _;
    }

    a->roar();
    b->roar();

    while (a->alive()) {
        a->hit(b);
        b->status();
        if (!b->alive()) {
            break;
        }
        b->hit(a);
        a->status();
    }

    std::cout << "Roar of winner: ";

    if (a->alive()) {
        a->roar();
        a->heal();
    }
    else{
        b->roar();
        b->heal();
    }
}


int main()
{
    srand(time(0));
    const double ALIEN_DMG = 30;
    const double ALIEN_HP = 100;

    const double PREDATOR_DMP = 20;
    const double PREDATOR_HP = 100;

    size_t N = 10;
    Unit** fighters = new Unit*[N];
   
    for (size_t i = 0; i < N; ++i) {
        switch (i % 2) {
        case 0:
            fighters[i] = new Alien(ALIEN_HP, ALIEN_DMG);
            break;
        case 1:
            fighters[i] = new Predator(PREDATOR_HP, PREDATOR_DMP, 2.4);
            break;
        }
    }

    for (size_t i = 0; i < N - 1; ++i) {
        /// <summary>
        /// ZAGLUSHKA
        /// </summary>
        /// <returns></returns>
        for (size_t j = 0; j < N-1; ++j) {
            for (size_t k = j+1; k < N; ++k) {
                if (fighters[j]->alive() and fighters[k]->alive()) {
                    fight(fighters[j], fighters[k]);
                    j = k;
                }
           }
        }

    }

    return 0;
}

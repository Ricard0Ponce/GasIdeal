using namespace std;
#include <iostream>
#include "Atomo.h"
#include "Sim.h"


int main() {
    std::cout << "GI1" << std::endl;
    Sim *sim; // Usamos un apuntador
    sim = new Sim;
    sim -> prin();
    //sim -> Datos();

    return 0;

}

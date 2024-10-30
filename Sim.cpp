//
// Created by rich on 25/10/24.
//

#include "Sim.h"

#include "Atomo.h"

Sim::Sim()
{

}

// Esto es un destructor que libera memoria
Sim::~Sim()
{

}


int Sim::prin()
{
    cout << endl;
    cout << "Sim::prin " << endl;
    Datos();
    EscribirDatos();
    IniciarAtomos();
    //EscribirDatos();
    EscribirPosVel();
    Simulacion();

    return 0;
}

void Sim::Datos()
{
    cout << endl;
  cout << "Sim::Datos" << endl;
    na = 10; // Numero de atomos
    nd = 3; // Numero de dimensiones
    nc = 15; // Numero de configuraciones

    dt = 0.1; // Delta de tiempo
    L = 1.0; // Espacio
    d= 0.1;
    r = d / 2.0;
    v0 = 1;

    ncp =10;// Numero de configuraciones parciales
    nci = nc / ncp;

    //p[100][100], v[100][100]; // Matrices
}


void Sim :: EscribirDatos() {

    cout << endl;
    cout << "Sim::EscribirDatos " << endl;

    // Escribir datos iniciales
    cout << endl;
    cout << "Datos iniciales" << endl;
    cout << "na,nd,nc " << na << " "
                        << nd << " "
                        << nc << endl;

    cout << "dt,L,d,r " << dt << " "
                    << L << " "
                    << d << " "
                        << r << endl;

    cout << "v0 " << v0 << endl;
    cout << "ncp,nci " << ncp << " " << nci << endl;

}

void Sim::IniciarAtomos() {
    cout << endl;
    cout << "Sim::IniciarAtomos " << endl;

    double pv[3]; // Vector de 3 dimensiones que funciona como auxiliar

    // Definir los objetos atomos
    for(int ia=0; ia < na; ia ++ ) {
        Atomo *att = new Atomo;
        atomos.push_back(att);
    }
    int an = atomos.size();
    cout << "an " << an << endl;

    // Iniciar posiciones y velocidades al azar.
    for(int ia = 0; ia < na; ia ++ ) {
        for(int id = 0; id < nd; id++ ) {
            pv[id] = rand() % 10000 / 10000.;
            // atomos[ia] -> p[id] = pv[id];
            atomos[ia] -> p.push_back(pv[id]);
        }
    }

    for(int ia = 0; ia < na; ia ++ ) {
        for(int id = 0; id < nd; id++ ) {
            double r = rand() % 10000 / 10000.;
            r = (r * 2.0) - 1;
            pv[id] = v0 * r;
            // atomos[ia] -> v[id] = pv[id];
            atomos[ia] -> v.push_back(pv[id]);
        }
    }
}

void Sim::EscribirPosVel() {
    cout << endl;
    cout << "Sim::EscribirPosVel " << endl;

    //Escribir posiciones y velocidades iniciales

    cout << endl;
    cout << "Posiciones y velocidades iniciales" << endl;
    for(int ia=0; ia < na; ia ++ ) {
        cout << "ia " << ia << endl;
        for(int id = 0; id < nd; id ++ ) {
            double pi = atomos[ia] -> p[id];
            cout << pi << " " << endl;
        }
        for (int id = 0; id < nd; id++ ) {
            double vi = atomos[ia] -> v[id];
            cout << vi << " ";
        }
        cout << endl;
    }
}

void Sim ::Simulacion() {
    cout << endl;
    cout << "Sim::Simulacion " << endl;

    // SImulacion
    // Ciclo de configuraciones
    for (int ic = 0; ic < nc; ic++) {
        // Ciclo de los atomos
        for(int ia = 0; ia < na; ia ++) {
            // Ciclo de las dimensiones
            for(int id = 0; id < nd; id ++ ) {
                double pp = atomos[ia] -> p[id] + dt * atomos[ia] -> v[id];
                if(pp > L) pp = pp - L;
                if(pp < 0) pp = pp + L;
                atomos[ia] -> p[id] = pp; // Se desplazan los atomos
            }
            //Ciclo de las dimensiones
        }
        //Ciclo de los atomos
        if(ic % nci == 0) {
            cout << "ic,ia" << ic << " " << "1" << " "
            << atomos[0] ->p[0] << " "
            << atomos[0] ->p[1] << " "
            << atomos[0] ->p[2] << " " << endl;
        }
    }
    //Ciclo de las configuraciones
}



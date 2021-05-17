#include "szemely.h"

int Szemely::id_count = 0;

Szemely::Szemely(Nev nev, Cim cim, Telefonszam telefonszam): ID(id_count++), nev(nev), cim(cim), telefonszam(telefonszam){}

void Szemely::setID(int num){
    ID = num;
}

bool Szemely::operator==(const Szemely& sz) const{
    return ID == sz.getID() && nev == sz.getNev() &&  cim == sz.getCim() && telefonszam == sz.getTelefonszam() ? true : false;
}

Szemely::~Szemely(){}

std::ostream& operator<<(std::ostream &os, const Szemely &sz){
    return os << "ID: " << sz.getID() <<"\n" << sz.getNev() << sz.getCim() << sz.getTelefonszam();
}

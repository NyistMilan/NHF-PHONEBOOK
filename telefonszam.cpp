#include "telefonszam.h"

Telefonszam::Telefonszam(std::string munka, std::string priv): munkahelyi(munka), privat(priv){}

bool Telefonszam::operator==(const Telefonszam& t) const{
    return munkahelyi.compare(t.getMunkahelyi()) == 0 && privat.compare(t.getPrivat()) == 0 ? true : false;
}

Telefonszam::~Telefonszam(){
}

std::ostream& operator<<(std::ostream &os, const Telefonszam &t1){
    return os << "Munkahelyi: " << t1.getMunkahelyi() << ", Privat: " << t1.getPrivat() << std::endl;
}

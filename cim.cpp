#include "cim.h"

Cim::Cim(int irszam, std::string varos, std::string utca, int hazszam):iranyitoszam(irszam), varos(varos), utca(utca), hazszam(hazszam){}

bool Cim::operator==(const Cim& c) const{
    return iranyitoszam == c.getIranyitoszam() && varos.compare(c.getVaros()) == 0 && utca.compare(c.getUtca()) == 0 && hazszam == c.getHazszam() ? true : false;
}

Cim::~Cim(){
}

std::ostream& operator<<(std::ostream &os, const Cim &c){
    return os << c.getIranyitoszam() << ", " << c.getVaros() << ", " << c.getUtca() << " utca " << c.getHazszam() << "." << std::endl;
}

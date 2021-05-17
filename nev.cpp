#include "nev.h"

Nev::Nev(std::string vezeteknev, std::string becenev, std::string keresztnev): vezeteknev(vezeteknev), becenev(becenev), keresztnev(keresztnev){}

bool Nev::operator==(const Nev& n) const{
    return vezeteknev.compare(n.getVezeteknev()) == 0 && becenev.compare(n.getBecenev()) == 0 && keresztnev.compare(n.getKeresztnev()) == 0 ? true : false;
}

Nev::~Nev(){
}

std::ostream& operator<<(std::ostream &os, const Nev &n){
    return os << n.getVezeteknev() << " \"" << n.getBecenev() << "\" " << n.getKeresztnev() << std::endl;
}

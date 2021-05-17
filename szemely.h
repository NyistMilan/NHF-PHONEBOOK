#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED

#include "nev.h"
#include "cim.h"
#include "telefonszam.h"

class Szemely{
    static int id_count;
    int ID;
    Nev nev;
    Cim cim;
    Telefonszam telefonszam;
public:
    Szemely(Nev nev = Nev(), Cim cim = Cim(), Telefonszam telefonszam = Telefonszam());

    inline Nev getNev() const{
        return nev;
    }

    inline Cim getCim() const{
        return cim;
    }

    inline Telefonszam getTelefonszam() const{
        return telefonszam;
    }

    inline int getID() const{
        return ID;
    }

    void setID(int num);

    inline void setID_count(int num){
        id_count = num;
    }
    inline int getID_count() const{
        return id_count;
    }

    bool operator==(const Szemely& sz) const;

    ~Szemely();
};
std::ostream& operator<<(std::ostream &os, const Szemely &sz);

#endif // SZEMELY_H_INCLUDED

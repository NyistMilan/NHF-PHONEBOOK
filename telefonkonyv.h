#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include <string>
#include <iostream>
#include "filekezeles.h"
#include "szemely.h"
#include "memtrace.h"

enum Adatok {ID_alapjan, Nev_alapjan, Cim_alapjan, Telefon_alapjan};

class Telefonkonyv{
    size_t db;
    Szemely* tkonyv;
public:
    Telefonkonyv();

    Telefonkonyv(const Telefonkonyv& tk);

    inline size_t getSize() const{
        return db;
    }

    int seged_keres(const Szemely &sz);

    bool keres(const Szemely &sz, Adatok adat);

    void hozzaad(Szemely &sz);

    void szemely_torol(const Szemely &sz);

    void lista_torol();

    void valtoztat(const Szemely &kit, const Szemely &kire);

    void kiir(std::string filenev);

    void beolvas(std::string filenev);

    Szemely& operator[](int i);

    const Szemely& operator[](int i) const;

    Telefonkonyv& operator=(const Telefonkonyv& sz);

    void fixID(Szemely& test);

    ~Telefonkonyv();
};
std::ostream& operator<<(std::ostream &os, const Telefonkonyv &t1);

#endif // TELEFONKONYV_H_INCLUDED

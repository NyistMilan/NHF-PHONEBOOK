#include "telefonkonyv.h"


Telefonkonyv::Telefonkonyv(): db(0), tkonyv(new Szemely[0]){}

int Telefonkonyv::seged_keres(const Szemely &sz){
    for(size_t i = 0; i < db; i++)
        if(tkonyv[i].getID() == sz.getID())
            return i;
    return -1;
}

bool Telefonkonyv::keres(const Szemely &sz, Adatok adat){
    switch(adat){
        case ID_alapjan:
            for(size_t i = 0; i < db; i++)
                if(tkonyv[i].getID() == sz.getID())
                    return true;
            return false;
        case Nev_alapjan:
            for(size_t i = 0; i < db; i++)
                if(tkonyv[i].getNev() == sz.getNev())
                    return true;
            return false;
        case Cim_alapjan:
            for(size_t i = 0; i < db; i++)
                if(tkonyv[i].getCim() == sz.getCim())
                    return true;
            return false;
        case Telefon_alapjan:
            for(size_t i = 0; i < db; i++)
                if(tkonyv[i].getTelefonszam() == sz.getTelefonszam())
                    return true;
            return false;
        default:
            return false;
    }
}

void Telefonkonyv::hozzaad(Szemely &sz){
    fixID(sz);

    Szemely* uj = tkonyv;
    tkonyv = new Szemely[db+1];
    tkonyv->setID_count(tkonyv->getID_count() - (db + 1));
    for(size_t i = 0; i < db; i++){
        tkonyv[i] = uj[i];
    }
    tkonyv[db++] = sz;
    delete[] uj;
}

void Telefonkonyv::szemely_torol(const Szemely &sz){
    size_t index = seged_keres(sz);

    if((int) index == -1)
        throw std::out_of_range("Nincs ilyen szemely a telefonkonyvben.");

    Szemely* uj = tkonyv;
    tkonyv = new Szemely[--db];
    tkonyv->setID_count(tkonyv->getID_count() - (db + 1));
    for(size_t j = 0; j < db; j++){
        if(j < index)
            tkonyv[j] = uj[j];
        else if(j >= index){
            tkonyv[j] = uj[j+1];
        }
    }
    delete[] uj;
}

void Telefonkonyv::lista_torol(){
    delete[] tkonyv;
    db = 0;
}

void Telefonkonyv::valtoztat(const Szemely &kit, const Szemely &kire){
    if(seged_keres(kit) == -1)
        throw std::out_of_range("Nincs ilyen szemely a telefonkonyvben.");

    size_t index = seged_keres(kit);

    if(seged_keres(kire) == -1)
        tkonyv[index] = kire;
    else
        throw std::out_of_range("A szemely mar resze a telefonkonyvnek.");
}

void Telefonkonyv::kiir(std::string filenev){
    std::ofstream myfile;

    myfile.open(filenev);
    myfile << *this;
    myfile.close();
}

void Telefonkonyv::beolvas(std::string filenev){
    lista_torol();
    tkonyv = new Szemely[0];
    tkonyv->setID_count(tkonyv->getID_count() - (db + 2));
    size_t size = number_of_lines(filenev)/4;
    std::ifstream myfile(filenev);

    if(!myfile.is_open()){
        myfile.close();
        throw std::bad_alloc();
    }

    Nev nev;
    Cim cim;
    Telefonszam telszam;
    std::string temp;

    for(size_t i = 0; i < size; i++){
        cp::getline(myfile, temp);
        int ID = getId(filenev, temp);

        cp::getline(myfile, temp);
        nev = getNev(filenev, temp);

        cp::getline(myfile, temp);
        cim = getCim(filenev, temp);

        cp::getline(myfile, temp);
        telszam = getTelefonszam(filenev, temp);

        Szemely sz(nev, cim, telszam);
        sz.setID(ID);

        hozzaad(sz);

        if(myfile.eof())
            myfile.close();
    }
}

Telefonkonyv::~Telefonkonyv(){
    delete[] tkonyv;
}

Szemely& Telefonkonyv::operator[](int i){
    return tkonyv[i];
}

const Szemely& Telefonkonyv::operator[](int i) const{
    return tkonyv[i];
}

std::ostream& operator<<(std::ostream &os, const Telefonkonyv &t1){
    for(size_t i = 0; i < t1.getSize(); i++){
        os << t1[i];
    }
    return os;
}

Telefonkonyv& Telefonkonyv::operator=(const Telefonkonyv& sz){
    if(this != &sz){
        delete[] tkonyv;
        db = sz.getSize();
        tkonyv = new Szemely[db];
        tkonyv->setID_count(tkonyv->getID_count() - (db));

        for(size_t i = 0; i < db; i++){
            tkonyv[i] = sz[i];
        }
    }
    return *this;
}

Telefonkonyv::Telefonkonyv(const Telefonkonyv& tk){
    db = tk.getSize();
    tkonyv = new Szemely[db];
    tkonyv->setID_count(tkonyv->getID_count() - (db + 1));

    for(size_t i = 0; i < db; i++){
        tkonyv[i] = tk[i];
    }

}

void Telefonkonyv::fixID(Szemely& test){
    size_t range = 20;

    if(db >= range)
        range += 20;

    while(seged_keres(test) != -1){
        test.setID(rand() % range);
    }
}

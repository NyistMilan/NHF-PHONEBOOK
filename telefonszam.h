#ifndef TELEFONSZAM_H_INCLUDED
#define TELEFONSZAM_H_INCLUDED

#include <iostream>
#include <string>

class Telefonszam{
    std::string munkahelyi;
    std::string privat;
public:
    Telefonszam(std::string munka = "+UNKNOWN", std::string priv = "+UNKNOWN");

    inline std::string getMunkahelyi() const{
        return munkahelyi;
    }

    inline std::string getPrivat() const{
        return privat;
    }

    bool operator==(const Telefonszam& t) const;

    ~Telefonszam();
};

std::ostream& operator<<(std::ostream &os, const Telefonszam &t1);
#endif // TELEFONSZAM_H_INCLUDED

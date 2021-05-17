#ifndef NEV_H_INCLUDED
#define NEV_H_INCLUDED

#include <string>
#include <iostream>

class Nev{
    std::string vezeteknev;
    std::string becenev;
    std::string keresztnev;
public:
    Nev(std::string vezeteknev = "UNKNOWN", std::string becenev = "UNKNOWN", std::string keresztnev = "UNKNOWN");

    inline std::string getVezeteknev() const{
        return vezeteknev;
    }

    inline std::string getBecenev() const{
        return becenev;
    }

    inline std::string getKeresztnev() const{
        return keresztnev;
    }

    bool operator==(const Nev& n) const;

    ~Nev();
};

std::ostream& operator<<(std::ostream &os, const Nev &n);

#endif // NEV_H_INCLUDED

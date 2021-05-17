#ifndef CIM_H_INCLUDED
#define CIM_H_INCLUDED

#include <string>
#include <iostream>

class Cim{
    int iranyitoszam;
    std::string varos;
    std::string utca;
    int hazszam;
public:
    Cim(int irszam = 0, std::string varos = "UNKNOWN", std::string utca = "UNKNOWN", int hazszam = 0);

    inline std::string getVaros() const{
        return varos;
    }

    inline std::string getUtca() const{
        return utca;
    }

    inline int getIranyitoszam() const{
        return iranyitoszam;
    }

    inline int getHazszam() const{
        return hazszam;
    }

    bool operator==(const Cim& c) const;

    ~Cim();
};

std::ostream& operator<<(std::ostream &os, const Cim &c);

#endif // CIM_H_INCLUDED

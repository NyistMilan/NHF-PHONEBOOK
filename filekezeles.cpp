#include "filekezeles.h"

std::istream& cp::getline(std::istream& is, std::string& str) {
    std::getline(is, str);
    if (str.size() && *str.rbegin() == '\r')
        str.erase(str.size()-1);
    return is;
}

int number_of_lines(std::string filenev){
    std::ifstream myfile(filenev);
    std::string ide;
    int res = 0;

    if(myfile.is_open()){
        while(cp::getline(myfile, ide)){
            res++;
        }
        myfile.close();
    }
    return res;
}

int getId(std::string filenev, std::string innen){
    std::ifstream myfile(filenev);

    innen.erase(0, 4);
    int res = std::stoi(innen);

    myfile.close();
    return res;
}

Nev getNev(std::string filenev, std::string innen){
    std::ifstream myfile(filenev);

    std::size_t pos = innen.find(" ");
    std::string vezeteknev = innen.substr(0, pos);

    std::size_t new_pos = innen.find(" ", pos+1);
    std::string becenev = innen.substr(pos+2, new_pos-pos-3);

    std::string keresztnev = innen.substr(new_pos+1);

    myfile.close();

    return Nev(vezeteknev, becenev, keresztnev);
}

Telefonszam getTelefonszam(std::string filenev, std::string innen){
    std::ifstream myfile(filenev);

    std::string munka = innen.substr(innen.find("+"), innen.find(",") - innen.find("+"));

    std::string priv = innen.substr(innen.find("+", innen.find("+") + 1));

    myfile.close();
    return Telefonszam(munka, priv);
}

Cim getCim(std::string filenev, std::string innen){
    std::ifstream myfile(filenev);

    int irszam = std::stoi(innen);

    std::size_t pos = innen.find(' ') + 1;
    std::size_t comma_pos = innen.find(',', pos);
    std::string varos = innen.substr(pos, comma_pos-pos);

    std::size_t utca_pos = innen.find("utca");
    std::string utca = innen.substr(comma_pos+2, utca_pos-comma_pos-3);

    int hazszam = std::stoi(innen.substr(utca_pos+4));

    myfile.close();
    return Cim(irszam, varos, utca, hazszam);
}

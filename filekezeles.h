#ifndef FILEKEZELES_H_INCLUDED
#define FILEKEZELES_H_INCLUDED

#include "szemely.h"
#include <string>
#include <iostream>
#include <fstream>

namespace cp {
  std::istream& getline(std::istream& is, std::string& str);
}

int number_of_lines(std::string filenev);
int getId(std::string filenev, std::string innen);
Nev getNev(std::string filenev, std::string innen);
Cim getCim(std::string filenev, std::string innen);
Telefonszam getTelefonszam(std::string filenev, std::string innen);

#endif // FILEKEZELES_H_INCLUDED

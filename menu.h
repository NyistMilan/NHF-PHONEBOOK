#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "telefonkonyv.h"

bool CinCheck();

void displayStart();

void displayMainMenu();

void menuController(Telefonkonyv& tk);

void addMemberMenu(Telefonkonyv& tk);

void delMemberMenu(Telefonkonyv& tk);

void swapMemberMenu(Telefonkonyv& tk);

void findMemberMenu(Telefonkonyv& tk);

void writeToFileMenu(Telefonkonyv& tk);

void readFromFileMenu(Telefonkonyv& tk);

void delPhonebook(Telefonkonyv& tk);

#endif // MENU_H_INCLUDED

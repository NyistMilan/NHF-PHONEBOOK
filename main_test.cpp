#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "telefonkonyv.h"
#include "gtest_lite.h"
#include "memtrace.h"
#include "menu.h"

//#define CPORTA

#ifndef CPORTA
int main()
{
    srand(time(NULL));
    Telefonkonyv telefonkonyv;
    menuController(telefonkonyv);

    return 0;
}
#endif // CPORTA

#ifdef CPORTA
int main(){

    srand(time(NULL));

    TEST(SzemelyTest, INIT){
        Szemely Jani(Nev("Kiss", "Jani", "Janos"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36305554444", "+36305554444"));
        EXPECT_EQ(0, Jani.getID()) << "ID hiba" << std::endl;
        EXPECT_EQ(Nev("Kiss", "Jani", "Janos"), Jani.getNev()) << "Nev-ben hiba" << std::endl;
        EXPECT_EQ(Cim(5600, "Bekescsaba", "Kecske", 69), Jani.getCim()) << "Cim-ben hiba" << std::endl;
        EXPECT_EQ(Telefonszam("+36305554444", "+36305554444"), Jani.getTelefonszam()) << "Telefonszam-ban hiba" << std::endl;
    } ENDM

    TEST(TelkonyvTest, KIIR){
        Telefonkonyv telefonkonyv;
        Szemely Jani(Nev("Kiss", "Jani", "Janos"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36305554444", "+36305554444"));
        Szemely Juli(Nev("Kiss", "Juli", "Julianna"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36303244527", "+36308643452"));
        telefonkonyv.hozzaad(Jani);
        telefonkonyv.hozzaad(Juli);
        telefonkonyv.kiir("test_kiir.txt");
        EXPECT_EQ(Jani, telefonkonyv[0]) << "Jani hiba" << std::endl;
        EXPECT_EQ(Juli, telefonkonyv[1]) << "Juli hiba" << std::endl;
        EXPECT_EQ((size_t) 2, telefonkonyv.getSize()) << "Meretezesi hiba" << std::endl;
    } ENDM

    TEST(TelkonyvTest, KERES){
        Telefonkonyv telefonkonyv;
        Szemely Jani(Nev("Kiss", "Jani", "Janos"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36305554444", "+36305554444"));
        Szemely Juli(Nev("Kiss", "Juli", "Julianna"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36303244527", "+36308643452"));
        Szemely Test(Nev("Kiss", "Jani", "Janos"), Cim(1007, "Budapest", "Alma", 420), Telefonszam("+36303244527", "+36308643452"));
        telefonkonyv.hozzaad(Jani);
        telefonkonyv.hozzaad(Juli);
        EXPECT_FALSE(telefonkonyv.keres(Test, ID_alapjan));
        EXPECT_TRUE(telefonkonyv.keres(Test, Nev_alapjan));
        EXPECT_FALSE(telefonkonyv.keres(Test, Cim_alapjan));
        EXPECT_TRUE(telefonkonyv.keres(Test, Telefon_alapjan));
    } ENDM

    TEST(TelkonyvTest, TOROL){
        Telefonkonyv telefonkonyv;
        Szemely Jani(Nev("Kiss", "Jani", "Janos"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36305554444", "+36305554444"));
        Szemely Juli(Nev("Kiss", "Juli", "Julianna"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36303244527", "+36308643452"));
        Szemely Mari(Nev("Nagy", "Mari", "Mariann"), Cim(1007, "Budapest", "Alma", 420), Telefonszam("+36303244527", "+36308643452"));
        telefonkonyv.hozzaad(Jani);
        telefonkonyv.hozzaad(Juli);
        EXPECT_EQ(Jani, telefonkonyv[0]) << "Jani hiba" << std::endl;
        EXPECT_EQ(Juli, telefonkonyv[1]) << "Juli hiba" << std::endl;
        telefonkonyv.szemely_torol(Jani);
        EXPECT_EQ(Juli, telefonkonyv[0]) << "Torles hiba" << std::endl;
        EXPECT_EQ((size_t) 1, telefonkonyv.getSize()) << "Tomb meret hiba" << std::endl;
        telefonkonyv.szemely_torol(Juli);
        EXPECT_EQ((size_t) 0, telefonkonyv.getSize()) << "Tomb meret hiba" << std::endl;
        EXPECT_THROW(telefonkonyv.szemely_torol(Mari), std::out_of_range&);
    } ENDM

    TEST(TelkonyvTest, CSERE){
        Telefonkonyv telefonkonyv;
        Szemely Jani(Nev("Kiss", "Jani", "Janos"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36305554444", "+36305554444"));
        Szemely Juli(Nev("Kiss", "Juli", "Julianna"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36303244527", "+36308643452"));
        Szemely Mari(Nev("Nagy", "Mari", "Mariann"), Cim(1007, "Budapest", "Alma", 420), Telefonszam("+36303244527", "+36308643452"));
        telefonkonyv.hozzaad(Juli);
        EXPECT_EQ(Juli, telefonkonyv[0]) << "Juli hiba" << std::endl;
        telefonkonyv.valtoztat(Juli, Mari);
        EXPECT_EQ(Mari, telefonkonyv[0]) << "Mari hiba" << std::endl;
        EXPECT_THROW(telefonkonyv.valtoztat(Jani, Juli), std::out_of_range&);
        EXPECT_THROW(telefonkonyv.valtoztat(Mari, Mari), std::out_of_range&);
    } ENDM

    TEST(TelkonyvTest, BEOLVAS){
        Telefonkonyv telefonkonyv;
        telefonkonyv.beolvas("test_beolv.txt");
        Szemely Jani(Nev("Kiss", "Jani", "Janos"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36305554444", "+36305554444"));
        Jani.setID(40);
        EXPECT_EQ(telefonkonyv[0], Jani);

        Szemely Juli(Nev("Kiss", "Juli", "Julianna"), Cim(5600, "Bekescsaba", "Kecske", 69), Telefonszam("+36303244527", "+36308643452"));
        Juli.setID(50);
        EXPECT_EQ(telefonkonyv[1], Juli);
    } ENDM

    return 0;
}
#endif // CPORTA

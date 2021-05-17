#include "menu.h"
#include "memtrace.h"

bool CinCheck(std::string message){
    if(std::cin.fail()){
        std::cout << message << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void displayStart(){
    std::cout << "Menu demo 1.0\nCreated by: Milan Konor Nyist"<< std::endl << std::endl;
    displayMainMenu();
}

void displayMainMenu(){
    std::cout << "\n\tChoose an option:"<< std::endl;
    std::cout << "\t1, ADD MEMBER"<< std::endl;
    std::cout << "\t2, DELETE MEMBER"<< std::endl;
    std::cout << "\t3, SWAP MEMBER"<< std::endl;
    std::cout << "\t4, FIND MEMBER"<< std::endl;
    std::cout << "\t5, LIST PHONEBOOK"<< std::endl;
    std::cout << "\t6, WRITE TO FILE"<< std::endl;
    std::cout << "\t7, READ FROM FILE"<< std::endl;
    std::cout << "\t8, DELETE PHONEBOOK" << std::endl;
    std::cout << "\t9, EXIT" << std::endl << std::endl << std::endl;
    std::cout << "Enter a number: ";
}

void menuController(Telefonkonyv& tk){
    int next_menu = 0;
    do{
        next_menu == 0 ? displayStart() : displayMainMenu();
        do{
            std::cin >> next_menu;
        }while(!CinCheck("Wrong Input, try again..."));

        switch(next_menu){
            case 1:
                addMemberMenu(tk);
                break;
            case 2:
                delMemberMenu(tk);
                break;
            case 3:
                swapMemberMenu(tk);
                break;
            case 4:
                findMemberMenu(tk);
                break;
            case 5:
                std::cout << "\n" << tk;
                break;
            case 6:
                writeToFileMenu(tk);
                break;
            case 7:
                readFromFileMenu(tk);
                break;
            case 8:
                delPhonebook(tk);
                break;
            case 9:
                break;
            default:
                std::cout << "Wrong character, try again..." << std::endl;
                break;
        }
    } while(next_menu != 9);
}

void addMemberMenu(Telefonkonyv& tk){
    std::cout << "Enter the member's informations:" << std::endl;
    std::cout << "Enter First Name, Nickname, Second Name:" << std::endl;
    std::string f_name, n_name, s_name, throw_away;

    cp::getline(std::cin, throw_away);
    cp::getline(std::cin, f_name);
    cp::getline(std::cin, n_name);
    cp::getline(std::cin, s_name);

    std::string city, street;
    int zipcode, street_num;
    std::cout << "Enter Zipcode, City, Street, Street Number:" << std::endl;

    do{
        std::cin >> zipcode;
    }while(!CinCheck("Wrong Zipcode, try again..."));

    cp::getline(std::cin, throw_away);
    cp::getline(std::cin, city);
    cp::getline(std::cin, street);

    do{
        std::cin >> street_num;
    }while(!CinCheck("Wrong Street Number, try again..."));

    std::string pub_phone, priv_phone;
    std::cout << "Public Phone Number, Private Phone Number:" << std::endl;
    cp::getline(std::cin, throw_away);
    cp::getline(std::cin, pub_phone);
    cp::getline(std::cin, priv_phone);
    Szemely temp(Nev(f_name, n_name, s_name), Cim(zipcode, city, street, street_num), Telefonszam(pub_phone, priv_phone));
    tk.hozzaad(temp);
}

void delMemberMenu(Telefonkonyv& tk){
    int ID;
    std::cout << "Enter the member's ID:" << std::endl;

    do{
        std::cin >> ID;
    }while(!CinCheck("Wrong ID, try again..."));

    Szemely temp;
    temp.setID(ID);
    try{
        tk.szemely_torol(temp);
        std::cout << "Member deleted." << std::endl;
    }catch(std::out_of_range&)
    {
        std::cout << "No member was found.";
    }
}

void writeToFileMenu(Telefonkonyv& tk){
    std::string file;
    std::cout << "Enter the file name:" << std::endl;
    std::cin >> file;

    tk.kiir(file);
    std::cout << "Writing to file finished." << std::endl;
}

void readFromFileMenu(Telefonkonyv& tk){
    std::string file;
    std::cout << "Enter the file name:" << std::endl;
    std::cin >> file;

    try{
        tk.beolvas(file);
        std::cout<< "Reading from file finished." << std::endl;
    }catch(std::bad_alloc&){
        std::cout << "File not found." <<std::endl;
    }

}

void findMemberMenu(Telefonkonyv& tk){
    char adat;
    std::cout << "Based on (I)D || (N)ame || (A)ddress || (P)hone Number:" << std::endl;

    do{
        std::cin >> adat;
    }while(!CinCheck("Wrong Input, try again..."));

    switch(adat){
        case 'I':
        case 'i':
            {
            int ID;
            std::cout << "ID:" << std::endl;
            do{
                std::cin >> ID;
            }while(!CinCheck("Wrong ID, try again..."));
            Szemely temp;
            temp.setID(ID);
            tk.keres(temp, ID_alapjan) ? std::cout << "Member found." : std::cout << "Member not found.";
            }
            break;
        case 'N':
        case 'n':
            {
            std::string f_name, n_name, s_name, throw_away;
            std::cout << "Name (First Name, Nickname, Second Name):" << std::endl;
            cp::getline(std::cin, throw_away);
            cp::getline(std::cin, f_name);
            cp::getline(std::cin, n_name);
            cp::getline(std::cin, s_name);
            Szemely temp(Nev(f_name, n_name, s_name), Cim(), Telefonszam());
            tk.keres(temp, Nev_alapjan) ? std::cout << "Member found." : std::cout << "Member not found.";
            }
            break;
        case 'A':
        case 'a':
            {
            std::string city, street, throw_away;
            int zipcode, street_num;
            std::cout << "Address (Zipcode, City, Street, Street Number):" << std::endl;
            do{
                std::cin >> zipcode;
            }while(!CinCheck("Wrong Zipcode, try again..."));
            cp::getline(std::cin, throw_away);
            cp::getline(std::cin, city);
            cp::getline(std::cin, street);
            do{
                std::cin >> street_num;
            }while(!CinCheck("Wrong Street Number, try again..."));

            Szemely temp(Nev(), Cim(zipcode, city, street, street_num), Telefonszam());
            tk.keres(temp, Cim_alapjan) ? std::cout << "Member found." : std::cout << "Member not found.";
            }
            break;
        case 'P':
        case 'p':
            {
            std::string pub_phone, priv_phone, throw_away;
            std::cout << "Phone Number (Public Phone Number, Private Phone Number):" << std::endl;
            cp::getline(std::cin, throw_away);
            cp::getline(std::cin, pub_phone);
            cp::getline(std::cin, priv_phone);
            Szemely temp(Nev(), Cim(), Telefonszam(pub_phone, priv_phone));
            tk.keres(temp, Telefon_alapjan) ? std::cout << "Member found." : std::cout << "Member not found.";
            }
            break;
        default:
            std::cout << "No option found. Returning to Menu..." << std::endl;
            break;
    }
}

void swapMemberMenu(Telefonkonyv& tk){
    int ID;
    std::cout << "Enter the old member's ID:" << std::endl;
    do{
        std::cin >> ID;
    }while(!CinCheck("Wrong ID, try again..."));

    Szemely old;
    old.setID(ID);

    std::cout << "Enter the new member's informations:" << std::endl;
    std::cout << "Enter First Name, Nickname, Second Name:" << std::endl;
    std::string f_name, n_name, s_name, throw_away;

    cp::getline(std::cin, throw_away);
    cp::getline(std::cin, f_name);
    cp::getline(std::cin, n_name);
    cp::getline(std::cin, s_name);

    std::string city, street;
    int zipcode, street_num;
    std::cout << "Enter Zipcode, City, Street, Street Number:" << std::endl;
    do{
        std::cin >> zipcode;
    }while(!CinCheck("Wrong Zipcode, try again..."));
    cp::getline(std::cin, throw_away);
    cp::getline(std::cin, city);
    cp::getline(std::cin, street);
    do{
        std::cin >> street_num;
    }while(!CinCheck("Wrong Street Number, try again..."));

    std::string pub_phone, priv_phone;
    std::cout << "Public Phone Number, Private Phone Number:" << std::endl;
    cp::getline(std::cin, throw_away);
    cp::getline(std::cin, pub_phone);
    cp::getline(std::cin, priv_phone);

    Szemely new_member(Nev(f_name, n_name, s_name), Cim(zipcode, city, street, street_num), Telefonszam(pub_phone, priv_phone));

    try{
        tk.valtoztat(old, new_member);
    }catch(std::out_of_range&){
        std::cout << "No such member in phone book.";
    }
}

void delPhonebook(Telefonkonyv& tk){
    if(tk.getSize() == 0){
        std::cout << "Phonebook already empty!" << std::endl;
    }else{
        Telefonkonyv uj;
        tk = uj;
        std::cout << "Phonebook updated!" << std::endl;
    }
}

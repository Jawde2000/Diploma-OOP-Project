/**********|**********|**********|
Program: Shopper progrom for shop owner.cpp 
Course          : Object Oriented Programming
Year            : Trimester 1 (2020/2021)
Name            : Chew Zhi Peng
ID              : 1191202464
Lecture Section : TC01
Tutorial Section: TT01
Email           : 1191202464@student.mmu.edu.my
Phone           : 016-6401837
**********|**********|**********/
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <errno.h>
using namespace std;

int main();
void main2();
class register_password //class for login and register//
{
private:
    string register_name; // new Owner User name//
    string   password; //password for shop owner//
    string adpassword; // admin password//
    string admin_name; //admin name//
    int       success; //a number to know if user successful to login//
public:
    register_password()
    {
        admin_name = register_name; //admin_name is equal to register_name//
        adpassword =      password; //adpassword is equal to password//
        //so the if loop in class scanning_password_and_id of function void testing_scanningAll can match the//
        //name and password//
    }

    void declare(string rn, string pw)
    {
        register_name = rn; //replace rn as register_name//
        password      = pw; //replace pw as password//
    }

    void newuser_register() // function of new user registration//
    {
        ofstream op;
        op.open("registration.csv"); // open the registration file//
        cout << "Welcome ! " << endl;
        cin.ignore();
        cout << "New Username        : ";
        getline(cin, register_name);
        cout << "Set your password   : ";
        cin  >>  password;
        op << register_name; //put the register_name inside registration.csv//
        op << '\n';
        op << password;      // put the password inside registration.csv//
        op.close();
        declare(register_name, password); // send the register_name and password back to declare function//
    }

    void admin_namepassword() //for login function//
    {
        cout << "Welcome ! " << endl;
        cin.ignore();
        cout << "Enter Name          : ";
        getline(cin, admin_name);
        cout << "Enter your password : ";
        cin >> adpassword;
    }
    friend class scanning_password_and_id; //to make the register password connected to this class//
};

class scanning_password_and_id // class of get password and id//
{
public:
    scanning_password_and_id()
    {

    }
    void testing_scanningAll() // function for user to test if user want to login or register//
    {
        int ans;

        do {
            cout << "Are you a new administrator?[Yes: 1; No: 2]: "; //ask if the user is beginner or already used//
            cin >> ans;
        } while (ans != 1 && ans != 2); // if the answer from user is not 1 or 2 the loop will repeat//
        

        if (ans == 1)
        {
            ofstream op;
            op.open("registration.csv"); // open the registration file//
            if (!op.is_open())  // if registration file is not open the below words will show up//
            {
                cout << "Could not find the file";
                cout << endl;
            }

            cout << endl;
            cout << endl;

            register_password rp; // object of register_password//

            rp.newuser_register(); //call function from class register password to here//                      
            
            cout << endl;
            cout << "Register Successful!"; //when user finish the registration the compiler will shown up the words//
            cout << endl;

            int ans2;
            cout << endl;
            cout << "Do you wish to log in now?[Yes: 1; No: 2]: "; //ask if user want to login//
            cin >> ans2;

            if (ans2 == 1)
            {
                string name;
                string pass;
                register_password rp;
                ifstream f;
                f.open("registration.csv");
                if (!f.is_open())
                {
                    cout << "Could not find the file";
                    cout << endl;
                }

                getline(f, name, '\n'); // scan the registration file and paste it to name//
                getline(f, pass, '\n'); // scan the registration file and paste it to pass//
                f.close();

                while (1) //login//
                {
                    cout << endl;
                    rp.admin_namepassword();

                    if (rp.admin_name == name && rp.adpassword == pass)
                    {                     
                        cout << "Login Successful!";
                        cout << endl;
                        cout << "Welcome " << rp.admin_name;
                        break; //exit the while loop if user entered the true account//
                    }
                    cout << "Incorrect name or password" << endl;//if the account is false then the loop will continue//
                }                                  
            }           
        }

        else if (ans == 2)
        {
            string name, pass;
            register_password rp;
            ifstream f;
            f.open("registration.csv");
            if (!f.is_open())
            {
                cout << "Could not find the file";
                cout << endl;
            }

            getline(f, name, '\n');
            getline(f, pass, '\n');
            f.close();

            while (1) //login//
            {
                cout << endl;
                rp.admin_namepassword();

                if (rp.admin_name == name && rp.adpassword == pass)
                {  
                    cout << endl;
                    cout << "Login Successful!";
                    cout << endl;
                    cout << "Welcome " << rp.admin_name << "!";
                    break; //exit the while loop if user entered the true account//
                }
                cout << "Incorrect name or password!" << endl;//if the account is false then the loop will continue//
            }           
        }
    }
};

class ShopItem
{
protected:
    int item_id;
    string name;
    float price;
    int unit;
    char ans;// to let user answer yes or no
    string company_name;
    string item_type;
    string p_id;      //all this are variable type of copy ShopItem protected//
    string anw;     //
    string p_price; // 
    string p_unit;  // 
    string p_com;   //
    string p_actor; //
    string p_type;  // 
    string p_name;  //
    string p_month; //
    string p_year;  // 
    string p_author_name;// 
public:
    ShopItem()
    {
        item_id = 0;
        name    = "No Item Name";
        price   = 0;
        unit    = 0;
        company_name = "No Company Name";
        item_type    =    "No Item Type";
    }

    friend class Magazine;
    friend class Book;
    friend class movie;
    friend class selection;
};

class Magazine: public ShopItem
{
protected:
    int month;
    int year;
    int id_num;
public:
    Magazine()
    {
       
    }
    void type_is_magazine() //add item function
    {
        ShopItem SI;

        ofstream si;
        si.open("magazine3_shop_item.csv", ios::app); // open the shop_item csv without overwrite//
        if (!si.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }

        cin.ignore();
        cout << "Enter the item name          : ";
        getline(cin, SI.name);
        cout << "Name of the company          : ";
        getline(cin, SI.company_name);
        cout << "Enter the price              : RM ";
        cin  >> SI.price;
        cout << "Number of units available    : ";
        cin  >> SI.unit;     
        cout << "Month published              : ";
        cin  >> month;
        cout << "Year of published            : ";
        cin  >> year;
        srand((unsigned)time(0));
        SI.item_id = (rand() % 999) + 3000;  //get a random id number//  
        SI.item_type = "Magazine";
        
        si << SI.item_id      << ","; //save into magazine3_shop_item.csv//
        si << SI.name         << ","; //save into magazine3_shop_item.csv//
        si << SI.price        << ","; //save into magazine3_shop_item.csv//
        si << SI.unit         << ","; //save into magazine3_shop_item.csv//
        si << SI.company_name << ","; //save into magazine3_shop_item.csv//
        si << SI.item_type    << ","; //save into magazine3_shop_item.csv//
        si << month           << ","; //save into magazine3_shop_item.csv//
        si << year            << "\n"; //save into magazine3_shop_item.csv//
        si.close(); //file close//
    }

    void view_magazine_information()
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tMagazine Item" << endl;
        cout << "========================================" << endl;
        cout << endl;
        ifstream view;   // read view
        view.open("magazine3_shop_item.csv", ios::in | ios::app | ios::binary);  // open view
        if (!view.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }
        cout << "ID" << setw(25) << "    Item Name " << setw(20) << "Price(RM)" << setw(10) << "      Unit" << setw(20)
            << "  Company Name" << setw(4) << " " << setw(10)//display the movie items tag//
            << " " << "Month" << setw(8) << "Year" << endl;
        cout << "===================================================================================================" <<
            "================" << endl;
        int line;
        while (view >> line)
        {
            getline(view, p_id, ',');
            getline(view, p_name, ',');
            getline(view, p_price, ',');// get all information in movie3_shop_item.csv//
            getline(view, p_unit, ',');
            getline(view, p_com, ',');
            getline(view, p_type, ',');
            getline(view, p_month, ',');
            getline(view, p_year, '\n');

            cout << setw(5) << line++ << '|' << setw(25) << p_name << setw(10) <<
                "RM " << p_price << setw(10) << p_unit << setw(25) << p_com << setw(15) << // output the information//
                p_month << setw(10) << p_year << endl;
            cout << "--------------------------------------------------------------------------------" <<
                "---------------------------------" << endl;
        }
        view.close();
    }

    void update_magazine_information()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tUpdate Magazine Item" << endl;
        cout << "========================================" << endl;
        fstream tin, tin2("magazine3_shop_item.csv", ios::app), replace("magazine3_shop_item.csv", ios::app), in("magazine3_shop_item.csv", ios::app);
        fstream tout;
        fstream sale("magazinesales.csv", ios::app);
        int jawapan;
        string new_change;
        string dump;
        string line;
        string magazine_id;
        string copy_id;

        tin.open("magazine3_shop_item.csv", ios::app);
        tout.open("magazine3_temp.csv", ios::app);

        cout << "Enter Item ID to be updated : ";
        cin >> magazine_id;
        cout << endl;
        cout << "Searching for " << magazine_id << "......." << endl;
        cout << endl;
        ifstream tmpin("magazine3_shop_item.csv");

        while (getline(tmpin, dump))
        {
            tin >> copy_id, ',';
            getline(tin, dump, ',');
            getline(tin, name, ',');
            getline(tin, p_price, ',');
            getline(tin, p_unit, ',');
            getline(tin, p_com, ',');
            getline(tin, p_type, ',');
            getline(tin, p_month, ',');
            getline(tin, p_year, '\n');

            if (magazine_id == copy_id)
            {
                magazine_id = true;
                do
                {
                    system("cls");
                    cout << "==============================" << endl;
                    cout << "Update Magazine Item" << endl;
                    cout << "==============================" << endl;
                    cout << "Which would you like to edit?" << endl;
                    cout << "1) Name            : " << name << endl;
                    cout << "2) Book price      : RM " << p_price << endl;
                    cout << "3) Unit            : " << p_unit  << endl;
                    cout << "4) Product Company : " << p_com   << endl;
                    cout << "5) Month           : " << p_month << endl;
                    cout << "6) Year            : " << p_year  << endl;
                    cout << endl << "Please enter the number of the field you would like to edit";
                    cout << endl;
                    cout << "Alternatively, enter 0 to return to Menu" << endl;
                    cin.ignore();
                    cout << "Your Answer : ";
                    cin >> jawapan;
                    cout << endl;
                    cout << "Searching for " << jawapan << "......." << endl;

                    if (jawapan == 0)
                    {
                        tin.close();
                        tout.close();
                        main();
                    }

                } while (jawapan != 1 && jawapan != 2 && jawapan != 3
                    && jawapan != 4 && jawapan != 5);

                cin.ignore();
                cout << "Please enter the new change : ";
                getline(cin, new_change);
                cout << endl << "Making changing.........." << endl;

                while (getline(in, line))
                {
                    replace >> copy_id;
                    getline(replace, dump, ',');
                    getline(replace, name, ',');
                    getline(replace, p_price, ',');
                    getline(replace, p_unit, ',');
                    getline(replace, p_com, ',');
                    getline(replace, p_type, ',');
                    getline(replace, p_month, ',');
                    getline(replace, p_year, '\n');

                    if (copy_id == magazine_id)
                    {
                        if (jawapan == 1)
                        {
                            tout << copy_id << "," << new_change << "," << p_price << "," << p_unit << "," <<
                                 p_com << "," << p_type << "," << p_month << p_year << "\n";
                        }
                        else if (jawapan == 2)
                        {
                            tout << copy_id << "," << name << "," << new_change << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << p_month << p_year << "\n";                    
                        }
                        else if (jawapan == 3)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << new_change << "," <<
                                p_com << "," << p_type << "," << p_month << p_year << "\n";
                            sale << copy_id << ",";
                            sale << name << ",";
                            sale << p_price << ",";
                            if (stoi(new_change) > stoi(p_unit))
                            {
                                sale << new_change << ",";
                            }
                            else if (stoi(p_unit) > stoi(new_change))
                            {
                                sale << stoi(p_unit) - stoi(new_change) << ",";
                            }
                            sale << p_com << ",";
                            sale << p_type << ",";
                            sale << p_month << ",";
                            sale << p_year << "\n";
                            sale.close();
                        }
                        else if (jawapan == 4)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                new_change << "," << p_type << "," << p_month << p_year << "\n";
                        }
                        else if (jawapan == 5)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << new_change << p_year << "\n";
                        }
                        else if (jawapan == 6)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << p_month << new_change << "\n";
                        }
                        else
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << p_month << p_year << "\n";
                        }
                    }

                    tin.close();
                    tout.close();
                    replace.close();
                    in.close();
                    tmpin.close();
                    rename("magazine3_temp.csv", "magazine3_shop_item.csv");
                    cout << endl;
                }
                copy_id = true;
            }
        }

        while (magazine_id != copy_id)
        {
            cout << "Can't find the ID!" << endl;
            cout << "[Yes : 1; No : 2]" << endl;
            cout << endl;

            while (1)
            {

                cout << "Do you wish to add new item? : ";
                cin >> anw;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
                }
                if (anw == "1")
                {
                    type_is_magazine();
                    break;
                }
                else if (anw == "2")
                {
                    update_magazine_information();
                    break;
                }
                cout << endl;
                cout << "Wrong number!" << endl;//keep looping if the number is not 1 or 2//  
                cout << endl;
            }
        }
    }

    void delete_magazine_information()
    {
        string li;
        string num;
        fstream din;
        fstream dout;
        string yesno;
        din.open("magazine3_shop_item.csv", ios::in);
        dout.open("delete3_magazine.csv", ios::out | ios::app);
        if (!din.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }
        if (!dout.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }

        cout << endl;
        cout << "========================================" << endl;
        cout << "\tDelete Magazine Record " << endl;
        cout << "========================================" << endl;
        cout << endl << "Enter the Item ID Record that you want to delete : ";
        cin  >> num;
        cout << endl << "[ Yes : 1; No : Any Keyboard]";
        cout << endl << "Are you sure you want to delete " << num << "?" << endl;
        cout << endl << "Are you sure you type the right ID?" << endl;
        cout << "Ans : ";//if answer is 1 the it go to if statement and delete the item record if any keyboard back to delete magazine
        cin >> yesno;

        if (yesno == "1")
        {
            vector<string> lis;
            while (getline(din, li))
            {
                if (li.find(num) == string::npos)//seaching for the id number
                {
                    dout << li << endl;
                }
            }
        }
        else
        {
            delete_magazine_information(); //if the id is not sure it backs to this function and reenter the value
        }
        dout.close();
        din.close();

        remove("book2_shop_item.csv");
        rename("delete2_book.csv", "book2_shop_item.csv");
        cout << endl << "Delete Successful.....Data Saved" << endl;
    }
    friend class ShopItem;
};

class Book: public ShopItem
{
protected:
    string author_name; // aunthor name//
public:
    Book()
    {
        author_name = "No Author Name";
    }

    void type_is_book()
    {
        ShopItem SI;

        ofstream si;
        si.open("book2_shop_item.csv", ios::app); // open the shop_item csv without overwrite//
        if (!si.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }

        cin.ignore();
        cout << "Enter the item name          : ";
        getline(cin, SI.name);
        cout << "Name of the company          : ";
        getline(cin, SI.company_name);
        cout << "Author name                  : ";
        getline(cin, author_name);
        cout << "Enter the price              : RM ";
        cin  >> SI.price;
        cout << "Number of units available    : ";
        cin  >> SI.unit;
              
        srand((unsigned)time(0));
        SI.item_id = (rand() % 999) + 1000;  //get a random id number//  
        SI.item_type = "Book";

        si << SI.item_id      << ","; //save into magazine3_shop_item.csv//
        si << SI.name         << ","; //save into magazine3_shop_item.csv//
        si << SI.price        << ","; //save into magazine3_shop_item.csv//
        si << SI.unit         << ","; //save into magazine3_shop_item.csv//
        si << SI.company_name << ","; //save into magazine3_shop_item.csv//
        si << SI.item_type    << ","; //save into magazine3_shop_item.csv//
        si << author_name     << "\n"; //save into magazine3_shop_item.csv//       
        si.close(); //file close//
    }

    void view_book_information()
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tBook Item" << endl;
        cout << "========================================" << endl;
        cout << endl;
        ifstream view;   // read view
        view.open("book2_shop_item.csv", ios::in | ios::app | ios::binary);  // open view
        if (!view.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }
        cout << "ID" << setw(19) << "    Item Name " << setw(30) << "Price(RM)" << setw(18) << "Unit" << setw(23)
            << "  Company Name" << setw(4) << " " << setw(8)//display the movie items tag//
            << setw(8) << " " << "Author Name" << endl;
        cout << "==================================================================================================="<<
                 "====================" << endl;
        int line;
        while (view >> line)
        {
            getline(view, p_id, ',');
            getline(view, p_name, ',');
            getline(view, p_price, ',');// get all information in movie3_shop_item.csv//
            getline(view, p_unit, ',');
            getline(view, p_com, ',');
            getline(view, p_type, ',');
            getline(view, p_author_name, '\n');
        
            cout << setw(5) << line++ << '|' << setw(25) << p_name << setw(15) << 
                 "RM "<< p_price << setw(17) << p_unit << setw(30) << p_com << setw(20) <<
                 p_author_name << setw(20) << endl;
            cout << "--------------------------------------------------------------------------------" <<
                "---------------------------------------" << endl;         
        }
        view.close();
    }

    void update_book_information()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tUpdate Book Item" << endl;
        cout << "========================================" << endl;
        fstream tin, tin2("book2_shop_item.csv"), replace("book2_shop_item.csv"), in("book2_shop_item.csv");
        fstream tout;
        fstream sale("booksales.csv", ios::app);
        int jawapan;
        string new_change;
        string dump;
        string line;
        string book_id;
        string copy_id;

        tin.open("book2_shop_item.csv", ios::in | ios::app | ios::binary);
        tout.open("book_temp.csv", ios::out | ios::app | ios::binary);
        cin.ignore();
        cout << "Enter Item ID to be updated : ";
        getline(cin, book_id);
        cout << endl;
        cout << "Searching for " << book_id << "......." << endl;
        cout << endl;
        ifstream tmpin("book2_shop_item.csv");

        while (getline(tmpin, dump))
        {
            getline(tin, copy_id, ',');
            getline(tin, name, ',');
            getline(tin, p_price, ',');
            getline(tin, p_unit, ',');
            getline(tin, p_com, ',');
            getline(tin, p_type, ',');
            getline(tin, p_author_name, '\n');

            if (book_id == copy_id)
            {
                book_id = true;
                do
                {
                    system("cls");
                    cout << "=============================="         << endl;
                    cout << "Update Movie Item"                      << endl;
                    cout << "=============================="         << endl;
                    cout << "Which would you like to edit?"          << endl;
                    cout << "1) Name            : " << name          << endl;
                    cout << "2) Book price      : RM " << p_price    << endl;
                    cout << "3) Unit            : " << p_unit        << endl;
                    cout << "4) Product Company : " << p_com         << endl;
                    cout << "5) Author name     : " << p_author_name << endl;
                    cout << endl << "Please enter the number of the field you would like to edit";
                    cout << endl;
                    cout << "Alternatively, enter 0 to return to Menu" << endl;                  
                    cout << "Your Answer : ";       
                    cin >> jawapan;
                    cout << endl;
                    cout << "Searching for " << jawapan << "......." << endl;

                    if (jawapan == 0)
                    {
                        tin.close();
                        tout.close();
                        main();
                    }

                } while (jawapan != 1 && jawapan != 2 && jawapan != 3
                    && jawapan != 4 && jawapan != 5);

                cin.ignore();
                cout << "Please enter the new change : ";
                getline(cin, new_change);
                cout << endl << "Making change.........." << endl;

                while (getline(in, line))
                {
                    getline(replace, copy_id, ',');
                    getline(replace, name, ',');
                    getline(replace, p_price, ',');
                    getline(replace, p_unit, ',');
                    getline(replace, p_com, ',');
                    getline(replace, p_type, ',');
                    getline(replace, p_author_name, '\n');

                    if (copy_id == book_id)
                    {
                        if (jawapan == 1)
                        {
                            tout << copy_id << "," << new_change << "," << p_price << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << p_author_name << "\n";
                        }
                        else if (jawapan == 2)
                        {
                            tout << copy_id << "," << name << "," << new_change << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << p_author_name << "\n";
                        }
                        else if (jawapan == 3)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << new_change << "," <<
                                p_com << "," << p_type << "," << p_author_name << "\n";
                            sale << copy_id << ",";
                            sale << name << ",";
                            sale << p_price << ",";
                            if (stoi(new_change) > stoi(p_unit))
                            {
                                sale << new_change << ",";
                            }
                            else if (stoi(p_unit) > stoi(new_change))
                            {
                                sale << stoi(p_unit) - stoi(new_change) << ",";
                            }
                            sale << p_com << ",";
                            sale << p_type << ",";
                            sale << p_author_name << "\n";
                            sale.close();
                        }
                        else if (jawapan == 4)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                new_change << "," << p_type << "," << p_author_name << "\n";
                        }
                        else if (jawapan == 5)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << new_change << "\n";
                        }
                        else
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << p_author_name << "\n";
                        }
                    }

                    tin.close();
                    tout.close();
                    replace.close();
                    in.close();
                    tmpin.close();
                    rename("book_temp.csv", "book2_shop_item.csv");
                    cout << endl;
                }
                copy_id = true;
            }
        }

        while (book_id != copy_id)
        {
            cout << "Can't find the ID!" << endl;
            cout << "[Yes : 1; No : 2]" << endl;
            cout << endl;

            while (1)
            {

                cout << "Do you wish to add new item? : ";
                cin >> anw;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
                }
                if (anw == "1")
                {
                    type_is_book();
                    break;
                }
                else if (anw == "2")
                {
                    update_book_information();
                    break;
                }
                cout << endl;
                cout << "Wrong number!" << endl;//keep looping if the number is not 1 or 2//  
                cout << endl;
            }
        }
    }

    void delete_book_information()
    {
        string li;
        string num;
        fstream din;
        fstream dout;
        string yesno;
        din.open("book2_shop_item.csv", ios::in);
        dout.open("delete2_book.csv", ios::out | ios::app);
        if (!din.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }
        if (!dout.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }

        cout << endl;
        cout << "========================================" << endl;
        cout << "\tDelete Book Record " << endl;
        cout << "========================================" << endl;
        cout << endl << "Enter the Item ID Record that you want to delete : ";
        cin >> num;
        cout << endl << "[ Yes : 1; No : Any Keyboard]";
        cout << endl << "Are you sure you want to delete " << num << "?" << endl;
        cout << endl << "Are you sure you type the right ID?" << endl;
        cout << "Ans : ";
        cin >> yesno;

        if (yesno == "1")
        {
            vector<string> lis;
            while (getline(din, li))
            {
                if (li.find(num) == string::npos)
                {
                    dout << li << endl;
                }
            }         
        }
        else
        {
            delete_book_information();
        }
        dout.close();
        din.close();

        remove("book2_shop_item.csv");
        rename("delete2_book.csv", "book2_shop_item.csv");
        cout << endl << "Delete Successful.....Data Saved" << endl;
    }
};

class movie : public ShopItem
{
protected:
    string actor1_name; // main actor name //
    string anw;
    string movie_id;//
    string copy_id;
public:
    movie()
    {
        actor1_name = "No Actor Name";
    }
    void type_is_movie()
    {
        system("cls");
        ShopItem SI;
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tMovie Item" << endl;
        cout << "========================================" << endl;
        ofstream si;
        si.open("movie3_shop_item.csv", ios::app); // open the shop_item csv without overwrite//
        if (!si.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }

        cin.ignore();
        cout << "Enter the item name          : ";
        getline(cin, SI.name);
        cout << "Main Actor name              : ";
        getline(cin, actor1_name);
        cout << "Name of the company          : ";
        getline(cin, SI.company_name);
        cout << "Enter the price              : RM ";
        cin >> SI.price;
        cout << "Number of units available    : ";
        cin >> SI.unit;
        srand((unsigned)time(0));
        SI.item_id = (rand() % 999) + 2000;  //get a random id number//
        SI.item_type = "Movie";

        si << SI.item_id << ","; //save into magazine3_shop_item.csv//
        si << SI.name << ","; //save into magazine3_shop_item.csv//
        si << SI.price << ","; //save into magazine3_shop_item.csv//
        si << SI.unit << ","; //save into magazine3_shop_item.csv//
        si << SI.company_name << ","; //save into magazine3_shop_item.csv//
        si << SI.item_type << ","; //save into magazine3_shop_item.csv//
        si << actor1_name << "\n"; //save into magazine3_shop_item.csv//       
        si.close(); //file close//
    }

    void update_movie_information()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tUpdate Movie Item" << endl;
        cout << "========================================" << endl;
        ifstream tin("movie3_shop_item.csv", ios::app),
            tin2("movie3_shop_item.csv", ios::app),
            replace("movie3_shop_item.csv", ios::app),
            in("movie3_shop_item.csv", ios::app);
        ofstream tout("movie_temp.csv", ios::app);
        fstream sale("moviesales.csv", ios::app);
        int jawapan;
        string new_change;
        string dump;
        string line;

        cin.ignore();
        cout << "Enter Item ID to be updated : ";
        getline(cin, movie_id);
        cout << endl;
        cout << "Searching for " << movie_id << "......." << endl;
        cout << endl;
        ifstream tmpin("movie3_shop_item.csv");

        while (getline(tmpin, dump))
        {
            getline(tin, copy_id, ',');      
            getline(tin, name, ',');
            getline(tin, p_price, ',');
            getline(tin, p_unit, ',');
            getline(tin, p_com, ',');
            getline(tin, p_type, ',');
            getline(tin, p_actor, '\n');

            if (movie_id == copy_id)
            { 
                do
                {
                    system("cls");
                    cout << "==============================" << endl;
                    cout << "Update Movie Item" << endl;
                    cout << "==============================" << endl;
                    cout << "Which would you like to edit?"  << endl;
                    cout << "1) Name            : " <<    name    << endl;
                    cout << "2) Movie price     : RM " << p_price << endl;
                    cout << "3) Unit            : " <<    p_unit  << endl;
                    cout << "4) Product Company : " <<    p_com   << endl;
                    cout << "5) Main Actor      : " <<    p_actor << endl;
                    cout << endl << "Please enter the number of the field you would like to edit";                 
                    cout << endl;
                    cout <<"Alternatively, enter 0 to return to Menu" << endl;                  
                    cout << "Your Answer : ";
                    cin >> jawapan;
                    cout << endl;
                    cout << "Searching for " << jawapan << "......." << endl;

                    if (jawapan == 0)
                    {
                        tin.close();
                        tout.close();
                        replace.close();
                        remove("movie_temp.csv");
                        main();
                    }

                }while (jawapan != 1 && jawapan != 2 && jawapan != 3 
                    && jawapan != 4 && jawapan != 5);

                cin.ignore();
                cout << "Please enter the new change : ";
                getline(cin, new_change);
                cout << endl << "Making change.........." << endl;
                
                while (getline(tmpin, dump))
                {
                    getline(replace, copy_id, ',');               
                    getline(replace, name, ',');
                    getline(replace, p_price, ',');
                    getline(replace, p_unit, ',');
                    getline(replace, p_com, ',');
                    getline(replace, p_type, ',');
                    getline(replace, p_actor, '\n');
                    if (copy_id == movie_id)
                    {
                        if (jawapan == 1)
                        {
                            getline(replace, copy_id, ',');
                            getline(replace, name, ',');
                            getline(replace, p_price, ',');
                            getline(replace, p_unit, ',');
                            getline(replace, p_com, ',');
                            getline(replace, p_type, ',');
                            getline(replace, p_actor, '\n');
                            tout << copy_id << "," << new_change << "," << p_price << "," << p_unit << "," <<
                                 p_com << "," << p_type << "," << p_actor << "\n";
                        }
                        else if (jawapan == 2)
                        {
                            getline(replace, copy_id, ',');
                            getline(replace, name, ',');
                            getline(replace, p_price, ',');
                            getline(replace, p_unit, ',');
                            getline(replace, p_com, ',');
                            getline(replace, p_type, ',');
                            getline(replace, p_actor, '\n');
                            tout << copy_id << "," << name << "," << new_change << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << p_actor << "\n";                           
                        }
                        else if (jawapan == 3)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << new_change << "," <<
                                p_com << "," << p_type << "," << p_actor << "\n";
                            sale << copy_id << ",";
                            sale << name << ",";
                            sale << p_price << ",";
                            if (stoi(new_change) > stoi(p_unit))
                            {
                                sale << new_change << ",";
                            }
                            else if (stoi(p_unit) > stoi(new_change))
                            {
                                sale << stoi(p_unit)- stoi(new_change) << ",";
                            }                         
                            sale << p_com << ",";
                            sale << p_type << ",";                         
                            sale << p_actor << "\n";
                            sale.close();
                        }
                        else if (jawapan == 4)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                new_change << "," << p_type << "," << p_actor << "\n";
                        }
                        else if (jawapan == 5)
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                p_com << "," << p_type << "," << new_change << "\n";
                        }
                        else
                        {
                            tout << copy_id << "," << name << "," << p_price << "," << p_unit << "," <<
                                 p_com << "," << p_type << "," << p_actor << "\n";
                        }     
                        movie_id = "0";
                    }  
                    tin.close();
                    tout.close();
                    replace.close();
                    in.close();
                    tmpin.close();
                    remove("movie3_shop_item.csv");
                    rename("movie_temp.csv", "movie3_shop_item.csv");
                    cout << endl;
                }
                copy_id = true; 
                movie_id = true;
            }
        }   
                    while (movie_id != copy_id)
                    {
                       cout << "Can't find the ID!" << endl;
                       cout << "[Yes : 1; No : 2]" << endl;
                       cout << endl;

                       while (1)
                       {

                           cout << "Do you wish to add new item? : ";
                           cin >> anw;
                           if (cin.fail())
                           {
                               cin.clear();
                               cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
                           }
                           if (anw == "1")
                           {
                               type_is_movie();
                               break;
                           }
                           else if (anw == "2")
                           {
                              update_movie_information();
                              break;
                           }
                           cout << endl;
                           cout << "Wrong number!" << endl;//keep looping if the number is not 1 or 2//  
                           cout << endl;
                       }
                    }  
    }                
    
    void view_movie_information()
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tMovie Item" << endl;
        cout << "========================================" << endl;
        cout << endl;
        ifstream view;   // read view
        view.open("movie3_shop_item.csv", ios::in|ios::app|ios::binary);  // open view
        if (!view.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        } 
        cout << "ID" << setw(17) << "    Item Name " << setw(30) << "    Price(RM)" << setw(8) << "         Unit" << setw(23)
             << "  Company Name" << setw(4) << " " << setw(8)//display the movie items tag//
             << setw(4) << " " << "Actor Name" << endl;
        cout << "=============================================================================================================" << endl;
        int line;
        while(view >> line)
        {
            getline(view, p_id,    ',');
            getline(view, p_name,  ',');
            getline(view, p_price, ',');// get all information in movie3_shop_item.csv//
            getline(view, p_unit,  ',');
            getline(view, p_com,   ',');
            getline(view, p_type,  ',');
            getline(view, p_actor,'\n');
            cout << setw(5) << line++ << " | "  << setw(20) << p_name  <<setw(15) << " | RM "<< p_price << " | " 
                << setw(15) << p_unit << " | "  << setw(10) << p_com  << setw(20)
                << setw(10) << "| " << p_actor << endl;//display the movie items//
            cout << endl;
            cout << "------------------------------------------------------------------------------------------" <<
                "-------------------" << endl;
        }
        view.close();
    }

    void delete_movie_information()//to delete the information record//
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tDelete Movie Item" << endl;
        cout << "========================================" << endl;
        string li;
        string num;
        fstream din;
        fstream dout;
        string yesno;
        din.open("movie3_shop_item.csv", ios::in);
        dout.open("delete3_movie.csv", ios::out | ios::app);
        if (!din.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }
        if (!dout.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }

        cout << endl;
        cout << "========================================" << endl;
        cout << "\tDelete Movie Record " << endl;
        cout << "========================================" << endl;
        cout << endl << "Enter the Item ID Record that you want to delete : ";
        cin  >> num;
        cout << endl << "[ Yes : 1; No : Any Keyboard]";
        cout << endl << "Are you sure you want to delete " << num << "?" << endl;
        cout << endl << "Are you sure you type the right ID?" << endl;
        cout << "Ans : ";
        cin >> yesno;

        if (yesno == "1")
        {
            vector<string> lis;
            while (getline(din, li))
            {
                  if (li.find(num) == string::npos)
                  {
                     dout << li << endl;
                  }
            }
        }
        else
        {
            delete_movie_information();
        }
        
        dout.close();
        din.close();

        remove("movie3_shop_item.csv");
        rename("delete3_movie.csv", "movie3_shop_item.csv");
        cout << endl << "Delete Successful.....Data Saved" << endl;
    }

    friend class Magazine;
    friend class Book;
    friend class movie;
    friend class selection;
};

void display_selection()
{
    system("cls"); 
    cout << endl;
    cout << "==========================================="<< endl;
    cout << "\tSelection           "                     << endl;
    cout << "==========================================="<< endl;
    cout << "1) Insert new items "                       << endl;
    cout << "2) Update information of items in the shop" << endl;
    cout << "3) Delete items from the shop"              << endl;
    cout << "4) View items in the shop"                  << endl;
    cout << "5) Sales data analysis"                     << endl;
    cout << "6) Log out"                         << endl << endl;
    cout << "Please select an option"                    << endl;
}

class sales_data_analysis: public ShopItem
{
public:
    void product_name_()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "Sales Data Analysis By Product Name  "    << endl;
        cout << "========================================" << endl;
        string price;
        string name;
        string unit;
        ifstream op;
        ifstream pp;
        ifstream ap;
        double total_sales = 0;
        int total_unit = 0;
        op.open("booksales.csv");
        if (!op.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        int line;
        cout << setw(5) << "Item ID" << setw(25) << "Item Name" << setw(23) << "Item Price" <<
             setw(6.5) << "Unit" << setw(15) << "Revenue" << endl;
        cout << "==========================================================================================" << endl;
        while (op >> line)
        {
            getline(op, p_id, ',');
            getline(op, p_name, ',');
            getline(op, price, ',');// get all information in movie3_shop_item.csv//
            getline(op, unit, ',');
            getline(op, p_com, ',');
            getline(op, p_type, ',');
            getline(op, p_author_name, '\n');
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << setw(5) << line++ << "|" << setw(25) << p_name << setw(15) << "|" 
                 << "RM " << price << "|"
                 << setw(5) << unit << setw(10)<< "| RM " << stod(unit) * stod(price)
                 << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            total_sales = stod(price) * stod(unit) + total_sales;
            total_unit = stoi(unit) + total_unit;
        }

        pp.open("moviesales.csv");
        if (!pp.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        while (pp >> line)
        {
            getline(pp, p_id, ',');
            getline(pp, p_name, ',');
            getline(pp, price, ',');// get all information in movie3_shop_item.csv//
            getline(pp, unit, ',');
            getline(pp, p_com, ',');
            getline(pp, p_type, ',');
            getline(pp, p_actor, '\n');
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << setw(5) << line++ << "|" << setw(25) << p_name << setw(15) << "|"
                << "RM " << price << "|"
                << setw(5) << unit << setw(10) << "| RM " << stod(unit) * stod(price)
                << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            total_sales = stod(price) * stod(unit) + total_sales;
            total_unit = stoi(unit) + total_unit;
        }
        
        ap.open("magazinesales.csv");
        if (!ap.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        while (ap >> line)
        {
            getline(ap, p_id, ',');
            getline(ap, p_name, ',');
            getline(ap, price, ',');// get all information in movie3_shop_item.csv//
            getline(ap, unit, ',');
            getline(ap, p_com, ',');
            getline(ap, p_type, ',');
            getline(ap, p_month, ',');
            getline(ap, p_year, '\n');
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << setw(5) << line++ << "|" << setw(25) << p_name << setw(15) << "|"
                << "RM " << price << "|"
                << setw(5) << unit << setw(10) << "| RM " << stod(unit) * stod(price)
                << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            total_sales = stod(price) * stod(unit) + total_sales;
            total_unit = stoi(unit) + total_unit;
        }
        cout << setw(57) << "Total Unit = " << total_unit << setw(10) << "RM " << total_sales << " = Sales amount" << endl;

        op.close();
        pp.close();
        ap.close();
    }

    void company_name_()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "Sales Data Analysis By Company Name  " << endl;
        cout << "========================================" << endl;
        string price;
        string name;
        string unit;
        ifstream op;
        ifstream pp;
        ifstream ap;
        int line;
        double total_sales = 0;
        int total_unit = 0;
        op.open("booksales.csv");
        if (!op.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        cout << setw(5) << "Item ID" << setw(25) << "Company Name" << setw(23) << "Unit" <<
             setw(15) << "Revenue" << endl;
        cout << "==========================================================================================" << endl;
        while (op >> line)
        {
            getline(op, p_id, ',');
            getline(op, p_name, ',');
            getline(op, price, ',');// get all information in movie3_shop_item.csv//
            getline(op, unit, ',');
            getline(op, p_com, ',');
            getline(op, p_type, ',');
            getline(op, p_author_name, '\n');
        
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << setw(5) << line++ << "|" << setw(25) << p_com << setw(15) << "|"
                << setw(5) << unit << setw(10) << "| RM " << stod(unit) * stod(price)
                << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            total_sales = stod(price) * stod(unit) + total_sales;
            total_unit = stoi(unit) + total_unit;
        }

        pp.open("moviesales.csv");
        if (!pp.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        while (pp >> line)
        {
            getline(pp, p_id, ',');
            getline(pp, p_name, ',');
            getline(pp, price, ',');// get all information in movie3_shop_item.csv//
            getline(pp, unit, ',');
            getline(pp, p_com, ',');
            getline(pp, p_type, ',');
            getline(pp, p_actor, '\n');
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << setw(5) << line++ << "|" << setw(25) << p_com << setw(15) << "|"
                 << setw(5) << unit << setw(10) << "| RM " << stod(unit) * stod(price)
                 << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            total_sales = stod(price) * stod(unit) + total_sales;
            total_unit = stoi(unit) + total_unit;
        }

        ap.open("magazinesales.csv");
        if (!ap.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        while (ap >> line)
        {
            getline(ap, p_id, ',');
            getline(ap, p_name, ',');
            getline(ap, price, ',');// get all information in movie3_shop_item.csv//
            getline(ap, unit, ',');
            getline(ap, p_com, ',');
            getline(ap, p_type, ',');
            getline(ap, p_month, ',');
            getline(ap, p_year, '\n');
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << setw(5) << line++ << "|" << setw(25) << p_com << setw(15) << "|"             
                 << setw(5) << unit << setw(10) << "| RM " << stod(unit) * stod(price)
                 << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            total_sales = stod(price) * stod(unit) + total_sales;
            total_unit = stoi(unit) + total_unit;
        }
        cout << setw(49) << "Total Unit = " << total_unit << setw(10) << "RM " << total_sales << " = Sales amount" << endl;

        op.close();
        pp.close();
        ap.close();
    }

    void item_type()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "Sales Data Analysis By Item Type  " << endl;
        cout << "========================================" << endl;
        string price;
        string name;
        string unit;
        ifstream op;
        ifstream pp;
        ifstream ap;
        double total_sales = 0;
        int total_unit = 0;
        double total_sales2 = 0;
        int total_unit2 = 0;
        double total_sales3 = 0;
        int total_unit3 = 0;
        int unit_up = 0;
        double total_up = 0;
        int i = 0;
        int j = 0;
        op.open("booksales.csv");
        if (!op.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        int line;
        cout << setw(5) << "Item Type" << setw(20) << "Unit" <<
            setw(20) << "Revenue(RM)" << setw(10) << "Index" << endl;
        cout << "==========================================================================================" << endl;
        while (op >> line)
        {
            getline(op, p_id, ',');
            getline(op, p_name, ',');
            getline(op, price, ',');// get all information in movie3_shop_item.csv//
            getline(op, unit, ',');
            getline(op, p_com, ',');
            getline(op, p_type, ',');
            getline(op, p_author_name, '\n');
            if (p_type == "Book")
            {
               i++;
               total_sales = total_sales + stod(price) * stod(unit);
               total_unit  = total_unit  + stoi(unit);  
               j++;
            }
            
        }
        cout << endl;
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << setw(10) << "Book" << setw(18) << total_unit << setw(20) << total_sales << setw(10) << i << endl;
        cout << "------------------------------------------------------------------------------------------" << endl; 
        i = 0;
        pp.open("magazinesales.csv");
        if (!pp.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        while (pp >> line)
        {
            getline(pp, p_id, ',');
            getline(pp, p_name, ',');
            getline(pp, price, ',');// get all information in movie3_shop_item.csv//
            getline(pp, unit, ',');
            getline(pp, p_com, ',');
            getline(pp, p_type, ',');
            getline(pp, p_month, ',');
            getline(pp, p_year, '\n');
            if (p_type == "Magazine")
            {
                i++;
                total_sales2 = total_sales2 + stod(price) * stod(unit);
                total_unit2 = total_unit2 + stoi(unit);
                j++;
            }          
        }
        cout << endl;
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << setw(10) << "Magazine" << setw(18) << total_unit2 << setw(20) << total_sales2 << setw(10) << i << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        i = 0;
        ap.open("moviesales.csv");
        if (!ap.is_open())
        {
            cout << "Could not find the file";
            cout << endl;
        }
        while (ap >> line)
        {
            getline(ap, p_id, ',');
            getline(ap, p_name, ',');
            getline(ap, price, ',');// get all information in movie3_shop_item.csv//
            getline(ap, unit, ',');
            getline(ap, p_com, ',');
            getline(ap, p_type, ',');
            getline(ap, p_actor, '\n');
            if (p_type == "Movie")
            {
                i++;
                total_sales3 = total_sales3 + stod(price) * stod(unit);
                total_unit3  = total_unit3  + stoi(unit);
                j++;
            }
        }
        cout << endl;
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << setw(10) << "Movie" << setw(18) << total_unit3 << setw(20) << total_sales3 << setw(10) << i << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        unit_up = total_unit + total_unit2 + total_unit3;
        total_up = total_sales + total_sales2 + total_sales3;
        cout << setw(28) << unit_up << " units" << setw(15) <<  total_up << setw(10) << j << endl;
        op.close();
        pp.close();
        ap.close();
    }
};

class selection: public Magazine, public Book, public movie, public sales_data_analysis
{
private:
    int itemtype_num; 
    char ans;
      string a_id;
      string a_name;
      string a_price;
      string a_unit;
      string a_com;
      string a_type;
      string a_author;
      string a_actor;
      Magazine m;
      Book b;
      movie M;   
public:
    selection()
    {

    }
    void view_all()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "\tShop Items" << endl;
        cout << "========================================" << endl;
        cout << endl;
        ifstream view;   // read view
        view.open("book2_shop_item.csv", ios::in | ios::app | ios::binary);  // open view
        if (!view.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }
        cout << "ID" << setw(20) << "    Item Name " << setw(25) << "Price(RM)" << setw(10) << "      Unit" << setw(20)
            << "  Company Name" << setw(4) << " " << setw(10)//display the movie items tag//
            << " " << "Type" << endl;
        cout << "===================================================================================================" <<
            "================" << endl;
        int line;
        while (view >> line)
        {
            getline(view, a_id, ',');
            getline(view, a_name, ',');
            getline(view, a_price, ',');// get all information in movie3_shop_item.csv//
            getline(view, a_unit, ',');
            getline(view, a_com, ',');
            getline(view, a_type, ',');
            getline(view, a_author, '\n');

            cout << setw(5) << line++ << '|' << setw(25) << a_name << setw(10) <<
                "RM " << a_price << setw(10) << a_unit << setw(25) << a_com << setw(15) 
                 << a_type << endl;
            cout << "--------------------------------------------------------------------------------" <<
                "-------------------" << endl;
        }
        view.close();

        ifstream siew;   // read view
        siew.open("movie3_shop_item.csv", ios::in | ios::app | ios::binary);  // open view
        if (!siew.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }
        while (siew >> line)
        {
            getline(siew, a_id, ',');
            getline(siew, a_name, ',');
            getline(siew, a_price, ',');// get all information in movie3_shop_item.csv//
            getline(siew, a_unit, ',');
            getline(siew, a_com, ',');
            getline(siew, a_type, ',');
            getline(siew, a_actor, '\n');

            cout << setw(5) << line++ << '|' << setw(25) << a_name << setw(10) <<
                "RM " << a_price << setw(10) << a_unit << setw(25) << a_com << setw(15)
                << a_type << endl;
            cout << "--------------------------------------------------------------------------------" <<
                "-------------------" << endl;
        }
        siew.close();

        ifstream fiew;   // read view
        fiew.open("magazine3_shop_item.csv", ios::in | ios::app | ios::binary);  // open view
        if (!fiew.is_open())  // if shop_item csv is not open the below words will show up//
        {
            cout << "Could not find the file";
            cout << endl;
        }
        while (fiew >> line)
        {
            getline(fiew, a_id, ',');
            getline(fiew, a_name, ',');
            getline(fiew, a_price, ',');// get all information in movie3_shop_item.csv//
            getline(fiew, a_unit, ',');
            getline(fiew, a_com, ',');
            getline(fiew, a_type, ',');
            getline(fiew, a_actor, '\n');

            cout << setw(5) << line++ << '|' << setw(25) << a_name << setw(10) <<
                "RM " << a_price << setw(10) << a_unit << setw(25) << a_com << setw(15)
                << a_type << endl;
            cout << "--------------------------------------------------------------------------------" <<
                "-------------------" << endl;
        }
        siew.close();
    }

    void insert_new_item() //A function to insert new item//
    {    
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "Welcome to Insert New Item  " << endl;
        cout << "========================================" << endl;

        do
        {
            cout << endl;
            cout << "Please choose a type to insert new item." << endl;
            cout << "Type of item";
            cout << endl;
            cout << endl;
            cout << "[ 1 : Book; 2 : Movie; 3 : magazine]";
            cout << endl;
            
            while (1)
            {
                cout << "Item type                    : ";
                cin >> itemtype_num;
                if (itemtype_num == 1 || itemtype_num == 2 || itemtype_num == 3)
                {
                    break; // if the number is 1, 2, or 3 the loop break//
                }
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
                }
                cout << endl;
                cout << "Wrong number! Please type again!" << endl;//keep looping if the number is not 1 ,2 and 3//
            }
            
            switch (itemtype_num)
            {
            case 1://when the itemtype_num is 1// 
                b.type_is_book();             
                break;
            case 2://when the itemtype_num is 2//  
                M.type_is_movie();               
                break;
            case 3://when the itemtype_num is 3// 
                m.type_is_magazine();                            
                break;
            default:
                cout << endl << "Don't have this Selection" << endl;
                insert_new_item();
            }

            cout << endl;
            cout << "Insert Item Successful!";
            cout << endl;
            cout << "[ Y : Yes; N : No]";
            cout << endl;
            cout << "Do you wish to add new item? : ";
            cin  >> ans;
        } while (ans == 'Y' || ans == 'y' && ans != 'N' || ans != 'n');
        if (ans == 'N' || ans == 'n')
        {
            main2();
        }
    }

    void update_item_information()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "Welcome to Update Item Information  "     << endl;
        cout << "========================================" << endl;

        do
        {
            cout << endl;
            cout << "Please choose a type to update item information." << endl;
            cout << "Type of item";
            cout << endl;
            cout << "[ 1 : Book; 2 : Movie; 3 : magazine]";
            cout << endl; 
            
            while (1)
            {
                
                cout << "Item type                    : ";
                cin >> itemtype_num;
                if (itemtype_num == 1 || itemtype_num == 2 || itemtype_num == 3)
                {
                    break; // if the number is 1, 2, or 3 the loop break//
                }
                if (cin.fail()) 
                {
                    cin.clear();
                    cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
                }
                cout << endl;
                cout << "Wrong number! Please type again!" << endl;//keep looping if the number is not 1 ,2 and 3//
                
            }

            switch (itemtype_num)
            {
            case 1://when the itemtype_num is 1//              
                b.update_book_information();
                break;
            case 2://when the itemtype_num is 2//  
                M.update_movie_information();
                break;
            case 3://when the itemtype_num is 3//  
                m.update_magazine_information();
                break;
            default:
                cout << endl << "Don't have this Selection" << endl;
                update_item_information();
            }
            
            cout << "[ Y : Yes; N : No]";
            cout << endl;
            cout << "Do you wish to update another item information? : ";
            cin  >> ans;
        } while (ans == 'Y' || ans == 'y' && ans != 'N' || ans != 'n');
        
        if (ans == 'N' || ans == 'n')
        {
            main2();
        }
    }

    void view_item_information()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "Welcome to View Item  " << endl;
        cout << "========================================" << endl;

        do
        {
            cout << endl;
            cout << "Please choose a type to View." << endl;
            cout << "Type of item";
            cout << endl;
            cout << endl;
            cout << "[ 1 : Book; 2 : Movie; 3 : magazine ; 4 : All]";
            cout << endl;

            while (1)
            {
                cout << "Item type                    : ";
                cin >> itemtype_num;
                if (itemtype_num == 1 || itemtype_num == 2 || itemtype_num == 3 ||itemtype_num == 4)
                {
                    break; // if the number is 1, 2, or 3 the loop break//
                }
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
                }
                cout << endl;
                cout << "Wrong number! Please type again!" << endl;//keep looping if the number is not 1 ,2 and 3//
            }

            switch (itemtype_num)
            {
            case 1://when the itemtype_num is 1//           
                b.view_book_information();            
                break;              
            case 2://when the itemtype_num is 2// 
                M.view_movie_information(); 
                break;
            case 3://when the itemtype_num is 3// 
                m.view_magazine_information();
                break;
            case 4:
                system("cls");
                view_all();
                break;
            default:
                cout << endl << "Don't have this Selection" << endl;
                view_item_information();
                
            }

            cout << endl;
            cout << "[ Y : Yes; N : No]";
            cout << endl;
            cout << "Do you wish to view others? : ";
            cin >> ans;
        } while (ans == 'Y' || ans == 'y' && ans != 'N' || ans != 'n');

        if (ans == 'N' || ans == 'n')
        {
            main2();
        }
    }

    void delete_item()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "Welcome to Delete Item  " << endl;
        cout << "========================================" << endl;

        do
        {
            cout << endl;
            cout << "Please choose a type to Delete." << endl;
            cout << "Type of item";
            cout << endl;
            cout << endl;
            cout << "[ Book : 1;  Movie : 2; magazine : 3]";
            cout << endl;

            while (1)
            {
                cout << "Item type                    : ";
                cin >> itemtype_num;
                if (itemtype_num == 1 || itemtype_num == 2 || itemtype_num == 3)
                {
                    break; // if the number is 1, 2, or 3 the loop break//
                }
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
                }
                cout << endl;
                cout << "Wrong number! Please type again!" << endl;//keep looping if the number is not 1 ,2 and 3//
            }

            switch (itemtype_num)
            {
            case 1://when the itemtype_num is 1//  
                b.delete_book_information();
                break;
            case 2://when the itemtype_num is 2//  
                M.delete_movie_information();
                break;
            case 3://when the itemtype_num is 3// 
                m.delete_magazine_information();
                break;
            default:
                cout << endl << "Don't have this Selection" << endl;
                delete_item(); // if the user answer is not 1 , 2 , or 3 the default will bring back to delete_item();
            }

            cout << endl;
            cout << "[ Y : Yes; N : No]";
            cout << endl;
            cout << "Do you wish to view others? : ";
            cin >> ans;
        } while (ans == 'Y' || ans == 'y' && ans != 'N' || ans != 'n');// while the user answer is y or y it loops back
        //if  the user answer is n or N the loop break

        if (ans == 'N' || ans == 'n')// if the do while loop answer is n or N it backs to main2 function//
        {
            main2();
        }
    }

    void sales_unit()
    {
        system("cls");
        cout << endl;
        cout << "========================================" << endl;
        cout << "Sales Data Analysis  " << endl;
        cout << "========================================" << endl;
        sales_data_analysis se;

        do
        {
            cout << endl;
            cout << "Please choose a type of analysis." << endl;
            cout << "Type of item";
            cout << endl;
            cout << endl;
            cout << "[By Product Name : 1; By Company Name : 2; By Item Type : 3]";
            cout << endl;

            while (1)
            {
                cout << "Which one you would like to know? : ";
                cin >> itemtype_num;
                if (itemtype_num == 1 || itemtype_num == 2 || itemtype_num == 3)
                {
                    break; // if the number is 1, 2, or 3 the loop break//
                }
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
                }
                cout << endl;
                cout << "Wrong number! Please type again!" << endl;//keep looping if the number is not 1 ,2 and 3//
            }

            switch (itemtype_num)
            {
            case 1://when the itemtype_num is 1//  
                se.product_name_();
                break;
            case 2://when the itemtype_num is 2//  
                se.company_name_();
                break;
            case 3://when the itemtype_num is 3// 
                se.item_type();
                break;
            default:
                cout << endl << "Don't have this Selection" << endl;
                sales_unit();//back to sales_unit() if the user answer is not 1 , 2 or 3
            }

            cout << endl;
            cout << "[ Y : Yes; N : No]";
            cout << endl;
            cout << "Do you wish to view others? : "; //if user want to view again this if not the while loop will bring back to menu
            cin >> ans;
        } while (ans == 'Y' || ans == 'y' && ans != 'N' || ans != 'n'); // while the user answer is y or y it loops back
        //if  the user answer is n or N the loop break

        if (ans == 'N' || ans == 'n')// if the do while loop answer is n or N it backs to main2 function//
        {
            main2(); 
        }
    }

    void logout()
    {
        cout << endl << "Log Out Successfully!" << endl;
        while (1)
        {
            break; // quit the menu and cout log out successfully//
        }
    }

    friend ShopItem;
};

int main()
{  
    scanning_password_and_id pass_id;
  
    cout << "-------------------------------" << endl;
    cout << "Welcome to Administrator Kiosk!" << endl;
    cout << "-------------------------------" << endl;
    // object of password and Id//

    pass_id.testing_scanningAll(); // login or sign in//   
    main2();// to access all the function
    
}

void main2()
{  
    ShopItem shopI;
    int choice;
    string strchoice;
    selection s;
    movie m;
    Book b;
    Magazine ma;

    while (1)
    {
        cout << endl;
        display_selection();   //display the number you want from display function//
        cout << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
        }
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
        {
            break;
        }
    }

    switch (choice)
    {
    case 1:
        s.insert_new_item();
        break;
    case 2:
        s.update_item_information();
        break;
    case 3:
        s.delete_item();
        break;
    case 4:
        s.view_item_information();
        break;
    case 5:
        s.sales_unit();
        break;
    case 6:
        s.logout();
        break;
    default:
        cout << "Wrong input !" << endl;
        cout << "Please Enter Again" << endl;
        main2();
    }
}
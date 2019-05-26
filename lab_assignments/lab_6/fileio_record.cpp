// Che Blankenhip
// Written based on Michael Miller source code.
// read/write binary record

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;


//Item description, Quantity on hand, Wholesale cost, Retail cost, and Date added to inventory.
// Use a char array for item description and date.
struct Info
{
    char itemDescription[20];
    int quantity;
    double wholeSaleCost;
    double retailCost;
    char dateAddedToInventory[8]; // dd/mm/yy
};

//
void print_item_info(Info p)
{
    cout << "Item description : " << p.itemDescription << endl;
    cout << "Quantity : " << p.quantity << endl;
    cout << "Wholesale cost : " << p.wholeSaleCost << endl;
    cout << "Retail cost : " << p.retailCost << endl;
    cout << "Date added to inventory : " << p.dateAddedToInventory << endl;
}

int get_record_count(istream &in)
{
    long pos = in.tellg();
    int num = 0;
    in.seekg(0, ios::end);
    in.clear();
    cout << "# records = " << in.tellg()/sizeof(Info) << endl;
    num = in.tellg()/sizeof(Info);
    in.seekg(pos, ios::beg);

    return num;
}

void write_records();
void read_all_records();
void read_any_records();
void write_any_records();
void menu_function();
// void read_write_record();

const char filename[] = "data.dat";

int main()
{

    menu_function();

    return 0;
}


// Add a new record at the end of the file.
void write_records()
{

    int NUM = 0;
    // User input
    cout << "--------- Enter inventory information ---------" << '\n';
    // check how many items user wants to enter.
    cout << "How many inventories?: ";
    cin >> NUM;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Array of Info struct.
    Info p[NUM];

    for (size_t i = 0; i < NUM; i++)
    {
        //Item description,
        char input_description[20];
        int input_quantity;
        double input_wholeSaleCost;
        double input_retailCost;
        char input_dateAddedToInventory[8]; // dd/mm/yy

        // inventory description
        while (!(std::cout << "Enter inventory description: " && cin >> input_description))
        {
            std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
            std::cin.clear(); //clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
        }
        strcpy(p[i].itemDescription, input_description);

        //Quantity on hand,
        while (!(std::cout << "Enter quantity on hand: " && (cin >> input_quantity) && input_quantity > 0))
        {
            std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
            std::cin.clear(); //clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        p[i].quantity = input_quantity;

        //Wholesale cost,
        while (!(std::cout << "Enter whole sale cost: " && (cin >> input_wholeSaleCost) && input_wholeSaleCost > 0))
        {
            std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
            std::cin.clear(); //clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        p[i].wholeSaleCost = input_wholeSaleCost;

        //Retail cost,
        while (!(std::cout << "Enter retail cost: " && (cin >> input_retailCost) && input_retailCost > 0))
        {
            std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
            std::cin.clear(); //clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        p[i].retailCost = input_retailCost;

        //Date added to inventory.
        while (!(std::cout << "Enter date added to inventory (dd/mm/yy): " && cin >> input_dateAddedToInventory))
        {
            std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
            std::cin.clear(); //clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
        }
        std::cout << "check " << input_dateAddedToInventory << '\n';
        strcpy(p[i].dateAddedToInventory, input_dateAddedToInventory);
        std::cout << "check " << p[i].dateAddedToInventory << '\n';
        std::cout << '\n';

    }

    // add to the end with app mode binary mode.
    ofstream outfile(filename, ios::app|ios::binary);
    // go to the end
    outfile.seekp(0, ios::end);

    for (size_t j = 0; j < NUM; j++)
    {
        outfile.write(reinterpret_cast<char *>(&p[j]), sizeof(Info));
    }

    outfile.close();
}


void read_all_records()
{

    // read a file
    Info p;
    cout << "Reading from file " << filename << endl;
    ifstream infile(filename, ios::binary);
    //cout << "pos = " << infile.tellg() << endl;

    infile.read(reinterpret_cast<char *>(&p), sizeof(Info));
    while (!infile.fail())
    {
        print_item_info(p);
        cout << '\n';
        // cout << "pos = " << infile.tellg() << endl;
        infile.read(reinterpret_cast<char *>(&p), sizeof(Info));
    }
    cout << endl;
    //cout << "pos = " << infile.tellg() << endl;

    // did go to EOF
    infile.clear();
    //cout << "size (bytes)/last location = " << infile.tellg() << endl;
    infile.close();

}

// Access to a specific record by using random access and display.
void read_any_records()
{

    Info p;
    long record_number;
    fstream readFile(filename, ios::in | ios::out | ios::binary);

    // Get the record number of the desired record.
    int record_range = get_record_count(readFile);
    cout << "Which record do you want to display? " << '\n';
    cout << "There are " << record_range << " records." << '\n';
    if (record_range == 0)
    {
        cout << "Choose from record "  << "0 ~ " << record_range << '\n';
        cin >> record_number;

        // Move to the record and read it.
        readFile.seekg((record_number) * sizeof(p), ios::beg);
        readFile.read(reinterpret_cast<char *>(&p), sizeof(p));
    }
    else
    {
        cout << "Choose from record "  << "1 ~ " << record_range << '\n';
        cin >> record_number;

        // Move to the record and read it.
        readFile.seekg((record_number-1) * sizeof(p), ios::beg);
        readFile.read(reinterpret_cast<char *>(&p), sizeof(p));
    }

    // Display the inventory contents
    cout << "Item description : " << p.itemDescription << endl;
    cout << "Quantity : " << p.quantity << endl;
    cout << "Wholesale cost : " << p.wholeSaleCost << endl;
    cout << "Retail cost : " << p.retailCost << endl;
    cout << "Date added to inventory : " << p.dateAddedToInventory << endl;
    // print_item_info(p);

    readFile.close();
}

// Edit specific record.
void write_any_records()
{
    Info p;
    long record_number;
    fstream editFile(filename, ios::in | ios::out | ios::binary);
    int record_range = get_record_count(editFile);

    cout << "CHECK HOW MANY RECORDS I HAVE  readfile" << record_range << '\n';
    cout << "Which record do you want to edit? ";
    if (record_range == 0)
    {
        cout << "Choose from record "  << "0 ~ " << record_range << '\n';
        cin >> record_number;
    }
    else
    {
        cout << "Choose from record "  << "1 ~ " << record_range << '\n';
        cin >> record_number;
    }

    // Get new data
    //Item description,
    char input_description[20];
    int input_quantity;
    double input_wholeSaleCost;
    double input_retailCost;
    char input_dateAddedToInventory[8]; // dd/mm/yy

    // inventory description
    while (!(std::cout << "Enter inventory description: " && cin >> input_description))
    {
        std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
        std::cin.clear(); //clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
    }
    strcpy(p.itemDescription, input_description);

    //Quantity on hand,
    while (!(std::cout << "Enter quantity on hand: " && (cin >> input_quantity) && input_quantity > 0))
    {
        std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
        std::cin.clear(); //clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    p.quantity = input_quantity;

    //Wholesale cost,
    while (!(std::cout << "Enter whole sale cost: " && (cin >> input_wholeSaleCost) && input_wholeSaleCost > 0))
    {
        std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
        std::cin.clear(); //clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    p.wholeSaleCost = input_wholeSaleCost;

    //Retail cost,
    while (!(std::cout << "Enter retail cost: " && (cin >> input_retailCost) && input_retailCost > 0))
    {
        std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
        std::cin.clear(); //clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    p.retailCost = input_retailCost;

    //Date added to inventory.
    while (!(std::cout << "Enter date added to inventory (dd/mm/yy): " && cin >> input_dateAddedToInventory))
    {
        std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
        std::cin.clear(); //clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
    }
    strcpy(p.dateAddedToInventory, input_dateAddedToInventory);

    // Move back to the beginning of this record's position.
    if (record_range == 0)
    {
        editFile.seekp(record_number * sizeof(p), ios::beg);
    }
    else
    {
        editFile.seekp((record_number-1) * sizeof(p), ios::beg);
    }

    // Write the new record over the current record.
    editFile.write(reinterpret_cast<char *>(&p), sizeof(p));

    editFile.close();

}


void menu_function()
{

    int chooseMenu;

    cout << "------------- Menu -------------" << '\n';
    string menu = "Enter [1] to add a new record at the end of the file.\nEnter [2] to display any record in the file.\nEnter [3] to change any record in the file.\nEnter [4] to display all records in the file.\nEnter [5] to exit the program. \n>> ";

    while (!(cout << menu && cin >> chooseMenu) || !((chooseMenu > 0) && (chooseMenu < 5)))
    {
        cin.clear(); //clear bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input. Please re-enter(only [1] ~ [5]).\n\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    if (chooseMenu == 1)
    {
        cout << "menu 1" << '\n';
        write_records();
    }
    else if(chooseMenu == 2)
    {
        cout << "menu 2" << '\n';
        read_any_records();
    }
    else if(chooseMenu == 3)
    {
        cout << "menu 3" << '\n';
        write_any_records();
    }
    else if(chooseMenu == 4)
    {
        cout << "menu 4" << '\n';
        read_all_records();
    }
    else if(chooseMenu == 5)
    {
        cout << "menu 5" << '\n';
        exit(0);
    }
    else
    {
        cout << "ERROR" << '\n';
    }

}

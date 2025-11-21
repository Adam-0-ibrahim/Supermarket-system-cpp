#include <iostream>
#include <string>
using namespace std;
class shopping
{
private:
    struct product
    {

        int code;
        float price;
        float discount;
        string name;
    };
    product products[100]; // array we will store the products inside
    int count = 0;         // count of products
public:
    void menu();
    void adminstrator();
    void customer();
    void add();
    void edit();
    void remove();
    void list();
    void receipt();
};
void shopping::menu()
{
m:
    int choice;
    string email;
    string password;
    string domain = "@admin.com";
    cout << "\t\t\tsupermarket please enter a choice" << endl; // the interactive main menu of the app
    cout << "\t\t\t=================================" << endl;
    cout << "\t\t\t1) Adminstrator" << endl;
    cout << "\t\t\t2) Customer" << endl;
    cout << "\t\t\t3) Exit" << endl;
    cout << "\t\t\t";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "\t\t\tPlease enter your E-mail and Password" << endl
             << "\t\t\tE-mail:" << endl;
        getline(cin, email);
        cout << "\t\t\t";
        cin >> email;
        cout << "\t\t\tPassword:" << endl;
        cout << "\t\t\t";
        cin >> password;
        if (email.length() >= domain.length()) // checking if the user is an adminstrator
        {
            string ending = email.substr(email.length() - domain.length()); // to extract the domain of the mail
            if (ending == domain)
            {
                adminstrator();
            }
            else
            {
                cout << "\t\t\tInvalid user please check the email or password" << endl;
            }
        }
        else
            cout << "\t\t\tInvalid user please check the email or password" << endl;
        break;
    }
    case 2:
    {
        customer();
        break;
    }
    case 3:
    {
        exit(0);
    }

    default:
        cout << "\t\t\tplease select one of the given choices";
    }
    goto m;
}
void shopping::adminstrator() // adminstrator menu
{
m:
    int choice;
    cout << "\t\t\tplease select a choice" << endl;
    cout << "\t\t\t======================" << endl;
    cout << "\t\t\t1)Add product" << endl;
    cout << "\t\t\t2)Edit product" << endl;
    cout << "\t\t\t3)Remove product" << endl;
    cout << "\t\t\t4)Main Menu" << endl;
    cout << "\t\t\t";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        remove();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\t\t\tinvalid choice" << endl;
    }
    goto m;
}
void shopping ::customer() // the customer menu
{
m:
    cout << "\t\t\tPlease select an option" << endl;
    cout << "\t\t\t=======================" << endl;

    cout << "\t\t\t1)Buy product" << endl;
    cout << "\t\t\t2)list of products" << endl;
    cout << "\t\t\t3)Return to the Main menu" << endl;
    int choice;
    cout << "\t\t\t";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        list();
    case 3:
        menu();
    default:
        cout << "\t\t\tPlease enter a valid choice.";
    }
    goto m;
}
void shopping::add()
{
    if (count >= 100)
    {
        cout << "\t\t\tProduct storage is full" << endl;
    }
a:
    int code;
    string name;
    double price, discount;
    cout << "\t\t\tAdd new product:" << endl;
    cout << "\t\t\t========================" << endl;

    cout << "\t\t\tEnter product code:" << endl;
    cout << "\t\t\t";
    cin >> code;

    cout << "\t\t\tEnter product name" << endl;
    cout << "\t\t\t";
    cin >> name;

    cout << "\t\t\tEnter product price" << endl;
    cout << "\t\t\t";
    cin >> price;

    cout << "\t\t\tEnter product discount";
    cout << "\t\t\t";
    cin >> discount;

    for (int i = 0; i < count; i++) // to check for duplicates
    {
        if (products[i].code == code)
        {
            cout << "\t\t\tProduct code already exists!\n";
            goto a;
        }
    }
    products[count].code = code;
    products[count].name = name;
    products[count].price = price;
    products[count].discount = discount;
    count++;
    cout << "\t\t\t product added successufully" << endl;
o:
    cout << "\t\t\tDo you want to add another product? (Y=yes, N=No,L=Logout,E=Exit)" << endl;
    char option;
    cout << "\t\t\t";
    cin >> option;
    if (option == 'Y' || option == 'y')
    {
        goto a; // add another product
    }
    else if (option == 'N' || option == 'n')
        return; // return to administrator menu
    else if (option == 'L' || option == 'l')
    {
        menu(); // log out and go to the main menu
        return;
    }
    else if (option == 'E' || option == 'e')
    {
        exit(0); // exit the app
    }
    else
    {
        cout << "\t\t\tPlease enter a valid letter." << endl;
        goto o;
    }
}

void shopping::edit()
{
a:
    if (count == 0)
    {
        cout << "\t\t\tNo products available" << endl;
    }
    int code;
    cout << "\t\t\tEnter the product code to edit" << endl;
    cout << "\t\t\t";
    cin >> code;

    bool found = false; // to check if the inserted code exists or not
    for (int i = 0; i < count; i++)
    {
        if (products[i].code == code)
        {
            found = true;
            cout << "\t\t\tEditing product: " << products[i].name << endl;

            cout << "\t\t\tEnter the new name" << endl;
            cout << "\t\t\t";
            cin >> products[i].name;

            cout << "\t\t\tEnter the new price" << endl;
            cout << "\t\t\t";
            cin >> products[i].price;

            cout << "\t\t\tEnter the new discount" << endl;
            cout << "\t\t\t";
            cin >> products[i].discount;
        }
    }
    cout << "\t\t\tproduct has been updated successfully" << endl;
    if (!found)
    {
        cout << "\t\t\tProduct not found" << endl;
    }

o:
    cout << "\t\t\tDo you want to edit another product? (Y=yes, N=No,L=Logout,E=Exit)" << endl;

    char option;
    cout << "\t\t\t";
    cin >> option;

    if (option == 'Y' || option == 'y')
    {
        goto a; // edit another product
    }
    else if (option == 'N' || option == 'n')
        return; // return to administrator menu
    else if (option == 'L' || option == 'l')
    {
        menu(); // log out and go to the main menu
        return;
    }
    else if (option == 'E' || option == 'e')
    {
        exit(0); // exit the app
    }
    else
    {
        cout << "\t\t\tPlease enter a valid letter." << endl;
        goto o;
    }
}

void shopping::remove()
{
a:
    if (count == 0)
    {
        cout << "\t\t\tNo products to remove." << endl;
    }
    int code;
    cout << "\t\t\t Enter the product code to remove." << endl;
    cout << "\t\t\t";
    cin >> code;

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (products[i].code == code)
        {
            found = true;

            for (int j = i; j < count - 1; j++) // to remove elements by shifting
            {
                products[j] = products[j + 1];
            }
            count--;
            cout << "\t\t\tProduct removed successfully" << endl;
        }
    }
    if (!found)
    {
        cout << "\t\t\tProduct not found" << endl;
    }
o:
    cout << "\t\t\tDo you want to remove another product? (Y=yes, N=No,L=Logout,E=Exit)" << endl;

    char option;
    cout << "\t\t\t";
    cin >> option;

    if (option == 'Y' || option == 'y')
    {
        goto a; // remove another product
    }
    else if (option == 'N' || option == 'n')
        return; // return to administrator menu
    else if (option == 'L' || option == 'l')
    {
        menu(); // log out and go to the main menu
        return;
    }
    else if (option == 'E' || option == 'e')
    {
        exit(0); // exit the app
    }
    else
    {
        cout << "\t\t\tPlease enter a valid letter." << endl;
        goto o;
    }
}
void shopping::list()
{
    if (count == 0)
    {
        cout << "\t\t\tProduct not found" << endl;
    }

    cout << "\t\t\tProducts list" << endl;
    cout << "\t\t\t====================" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "\t\t\tCode: " << products[i].code << endl;
        cout << "\t\t\tName: " << products[i].name << endl;
        cout << "\t\t\tprice: " << products[i].price << endl;
        cout << "\t\t\tdiscount: " << products[i].discount << " %" << endl;
        cout << "\t\t\t=====================" << endl;
    }
}
void shopping::receipt()
{
    if (count == 0)
    {
        cout << "\t\t\tNo products Available" << endl;
    }
    int codes[100], quantity[100];
    int n, totalitems = 0;
    cout << "\t\t\tEnter the number of products you want to buy" << endl;
    cout << "\t\t\t";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\t\t\tEnter product code: " << endl;
        cin >> codes[i];
        cout << "\t\t\tEnter product quantity: " << endl;
        cin >> quantity[i];
    }

    float total = 0;
    cout << "\t\t\t====================" << endl;
    cout << "\t\t\tReceipt" << endl;
    cout << "\t\t\t====================" << endl;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < count; j++)
        {
            if (products[j].code == codes[i])
            {
                found = true;
                float priceAfterDis = products[j].price * (1 - products[j].discount / 100.0);
                float itemTotal = priceAfterDis * quantity[i];
                total += itemTotal;

                cout << "\t\t\t" << products[j].name << " * " << quantity[i] << " = " << itemTotal << endl;
            }
        }
        if (!found)
        {
            cout << "\t\t\t Product not found" << endl;
        }
    }
    cout << "\t\t\tTotal amount: " << total << endl;
    exit(0);
}
int main()
{
    shopping shop;
    shop.menu();
}
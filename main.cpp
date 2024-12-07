#include<iostream>
#include<fstream>
#include <windows.h>
#include <unistd.h>
using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float dis;
        string pname ;

    public:

        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};


void shopping :: menu()
{
    m :
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t_________________________________________________________________________________\n";
    cout<<"\t\t\t\t|                                                                                |\n";
    cout<<"\t\t\t\t|                              Supermarket Main Menu                             |\n";
    cout<<"\t\t\t\t|                                                                                |\n";
    cout<<"\t\t\t\t|________________________________________________________________________________|\n";
    cout<<endl;

    cout<<"\t\t\t\t|                        (1) Administrator                     |\n";
    cout<<"\t\t\t\t|                                                              |\n";
    cout<<"\t\t\t\t|                        (2) Buyer                             |\n";
    cout<<"\t\t\t\t|                                                              |\n";
    cout<<"\t\t\t\t|                        (3) Exit                              |\n";
    cout<<"\t\t\t\t|                                                              |\n";

    cout<<endl;

    cout<<"\t\t\t\t  Please Select  : "; cin>>choice ;
    system("cls");




    switch(choice)
    {
        case 1 :
            {
                cout<<"\t\t\t\t\t\t  Please Login  \n";
                cout<<"\t\t\t\t\t\t  Enter Your Email : ";
                cin>>email;
                cout<<"\t\t\t\t\t\t  Enter Password  : ";
                cin>>password;
                system("cls");


                if(email == "abc@gmail.com" && password == "donno")
                {

                   cout<<"\n\n\n\n\t\tloging in.....";
                   sleep(5);
                   system("cls");
                    administrator();
                }
                else
                {
                    cout<<"\t\t\t\t\t\t  Invalid Email Or Password \n";

                                    }

                break;
            }


        case 2 :
            {
                buyer();
                break;
            }

        case 3 :
            {
                exit(0);
                break;
            }
        default :
            {
                cout<<"\t\t\t\t\t\t  Please select from the given Options \n";
            }
    }
    goto m;

}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<endl;
    cout<<"\t\t\t\t\t\t Administrator Menu \n";
    cout<<"\n\t\t\t\t\t\t|__________1) Add new product_________________|";
    cout<<"\n\t\t\t\t\t\t|                                             |";
    cout<<"\n\t\t\t\t\t\t|__________2) Modify the product______________|";
    cout<<"\n\t\t\t\t\t\t|                                             |";
    cout<<"\n\t\t\t\t\t\t|__________3) Remove product__________________|";
    cout<<"\n\t\t\t\t\t\t|                                             |";
    cout<<"\n\t\t\t\t\t\t|__________4) Back to Main menu_______________|";
    cout<<endl;

    cout<<"\n\t\t\t\t\t\t  Please Enter your choice  ";
    cin>>choice;
    system("cls");

    switch(choice)
    {
        case 1:
            {
                add();
                break;
            }
        case 2:
            {
                edit();
                break;
            }
        case 3:
            {
                rem();
                break;
            }
        case 4:
            {
                menu();
                break;
            }
        default:
            cout<<"\t\t\t\t\t\t  Invalid Choice !!" ;
    }

    goto m;
}


void shopping ::buyer()
{
    m:
    int choice;
    cout<<"\n\n\n\n\t\t\t\t\t\t  Buyer Menu \n";
    cout<<"\n\t\t\t\t\t\t|______1) Buy Product_______|";
    cout<<"\n\t\t\t\t\t\t|                           |";
    cout<<"\n\t\t\t\t\t\t|______2) Go back___________|";
    cout<<endl;

    cout<<"\t\t\t\t\t\t  Enter your Choice  : ";

    cin>>choice;
    system("cls");

    switch(choice)
    {
        case 1:
            {
                receipt();
                break;
            }
        case 2:
            {
                menu();
                break;
            }
        default:
            cout<<"\t\t\t\t\t\t  Invalid Choice !!"<<endl;

    }

    goto m;
}


void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token = 0 ;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t\t\t  Add new product  ";
    cout<<"\n\n\t\t\t\t\t\t  Enter Product code ";
    cin>>pcode;
    cout<<"\n\n\t\t\t\t\t\t  Name of the Product ";
    cin>>pname;
    cout<<"\n\n\t\t\t\t\t\t  Price of the Product ";
    cin>>price ;
    cout<<"\n\n\t\t\t\t\t\t  Discount on Product  ";
    cin>>dis;

    data.open("database.txt" , ios::in) ;

    if(!data)
    {
        data.open("database.txt" , ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
            }

            data>>c>>n>>p>>d;
        }
        data.close();

        if(token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt" , ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }

    cout<<"\n\t\t\t\t\t\t  Record Inserted Successfully !!"<<endl;
}

void shopping :: edit()
{
    fstream data , data1;
    int pkey ;
    int token = 0 ;
    int c;
    float p;
    float d;
    string n ;

    cout<<"\n\t\t\t\t\t\t  Modify the Product ";
    cout<<"\n\t\t\t\t\t\t  Enter Product Code  :";
    cin>>pkey;

    data.open("database.txt" , ios::in);

    if(!data)
    {
        cout<<"\n\n\t\t\t\t\t\t  File doesn't Exist ! ";
    }
    else
    {

        data1.open("database1.txt" , ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pkey == pcode)
            {
                cout<<"\n\t\t\t\t\t\t  Product new Code  :";
                cin>>c;
                cout<<"\n\t\t\t\t\t\t  Name of the Product  :";
                cin>>n;
                cout<<"\n\t\t\t\t\t\t  Price  :";
                cin>>p;
                cout<<"\n\t\t\t\t\t\t  Discount :";
                cin>>d;


                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t\t\t\t\t  Record Edited  ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }

            data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();


        rename("database1.txt" , "database.txt");

        if(token == 0)
        {
            cout<<"\n\n\t\t\t\t\t\t  Sorry! Record not found ";
        }
    }
}

void shopping :: rem()
{
    fstream data , data1;
    int pkey ;
    int token = 0 ;
    cout<<"\n\n\t\t\t\t\t\t  Delete Product ";
    cout<<"\n\n\t\t\t\t\t\t  Product code  :";
    cin>>pkey;

    data.open("database.txt" , ios::in);

    if(!data)
    {
        cout<<"\t\t\t\t\t\t  File doesn't Exist"<<endl;
    }
    else
    {
        data1.open("database1.txt" , ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pcode == pkey)
            {
                cout<<"\n\n\t\t\t\t\t\t  Product deleted Successfully ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }

            data>>pcode>>pname>>price>>dis;
        }



        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt" , "database.txt");

        if(token == 0)
        {
            cout<<"\n\t\t\t\t\t\t  Record Not found"<<endl;
        }

    }
}


void shopping :: list()
{
    fstream data;
    data.open("database.txt" , ios::in);

    cout<<"\n\n\t\t\t\t\t\t|____________________________________________________________________|\n";
    cout<<"\t\t\t\t\t\t  Product No. \t  Name \t\t Price \n";
    cout<<"\n\n\t\t\t\t\t\t|____________________________________________________________________|\n";
    data>>pcode>>pname>>price>>dis;

    while(!data.eof())
    {
        cout<<"\t\t\t\t\t\t   "<<pcode<<"\t\t"<<pname<<"\t\t "<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }

    data.close();

}

void shopping :: receipt()
{
    m:
    fstream data;

    int arrc[100];
    int arrq[100];
    string choice;
    int c = 0 ;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\n\t\t\t\t\t\t                          RECEIPT                      ";
    data.open("database.txt" , ios::in);
    if(!data)
    {
        cout<<"\n\n\t\t\t\t\t\t  Empty database"<<endl;
        return ;
    }
    else
    {
        data.close();

        list();

        cout<<"\n\t\t\t\t\t\t__________________________________________________\n";
        cout<<"\n\t\t\t\t\t\t|                                                 |\n";
        cout<<"\n\t\t\t\t\t\t|            Please place your order              |\n";
        cout<<"\n\t\t\t\t\t\t|                                                 |\n";
        cout<<"\n\t\t\t\t\t\t__________________________________________________\n";




        do
        {
            cout<<"\n\n\t\t\t\t\t\t  Enter Product Code  :";
            cin>>arrc[c];
            cout<<"\n\n\t\t\t\t\t\t  Enter the product Quantity  :";
            cin>>arrq[c];


            for(int i = 0 ; i < c ; i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout<<"\n\n\t\t\t\t\t\t  Duplicate Product Code . Please try again :";
                    goto m;
                }
            }

            c++;

            cout<<"\n\n\t\t\t\t\t\t  Do you want to Buy another Product ? If yes then Press 'y' else 'n' ";
            cin>>choice;
        }
        while (choice == "y" || choice == "yes" || choice == "Yes" || choice == "Y");


        cout<<"\n\n\t\t\t\t\t\t_________________________________RECEIPT________________________\n";
        cout<<"\n\t\t\t\t\t\t Product No.\t Product Name\t Product quantity\t Price\t Amount\t Amount with Discount\n";


        for(int i = 0 ; i < c ; i++)
        {
            data.open("database.txt" , ios::in);
            data>>pcode>>pname>>price>>dis;

            while(!data.eof())
            {
                if(pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis/100);
                    total = total + dis;
                    cout<<"\n\t\t\t\t\t\t  "<<pcode<<"\t\t  "<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
                i++;
            }
        }

        data.close();
    }

    cout<<"\n\n\t\t\t\t\t\t___________________________________________________________";
    cout<<"\n\t\t\t\t\t\t  Total Amount :  "<<total<<endl;

}

int main()
{
    system("color 5e");
    shopping s;
    s.menu();

    return 0;
}






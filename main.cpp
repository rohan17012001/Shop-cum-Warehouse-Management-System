#include<bits/stdc++.h>
#include<conio.h>
#include "owner.h"
#include "customer.h"
using saamaan::product;
using graahak::customer;
using karmchaari::emp;
using maalik::owner;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    char ch='Y';
    while(ch=='Y')
    {
        system("cls");
        cout<<"\n\n\n\n\n\n                                               *****************************************************\n";
        cout<<"                                               *Welcome to Sundarban Warehouse-cum-Shopping Center!*\n";
        cout<<"                                               *****************************************************\n\n\n";
        cout<<"\n                                                             Who are you? ";
        cout<<"\n                                                             1.Customer";
        cout<<"\n                                                             2.Employee";
        cout<<"\n                                                             3.Owner";
        cout<<"\n                                                        Enter Your Choice (1/2/3) ";
        cout<<"\n                                                        Press 0 to exit the Sundarban Portal ";
        cout<<"\n                                                        Enter your Choice: ";
        int k;
        cin>>k;
        if(k==1)
        {
            system("cls");
            cout<<"\n\n\n                                                             Hello Customer!!!";
            cout<<"\n\n                                                        Enter name: ";
            string s;
            cin>>s;
            cout<<"                                                        Enter your contact number: ";
            string n;
            cin>>n;
            customer c1(s,n);
            cout<<"\n                                                             Hello "<<s<<" !!!";
            cout<<"\n                                                        What you wanna do??";
            cout<<"\n                                                        1.Show Products List";
            cout<<"\n                                                        2.Buy Products";
            cout<<"\n                                                        Enter choice (1/2): ";
            int choice;
            cin>>choice;
            if(choice==2)
            {
                c1.buy();
                cout<<"\n                                                             Purchase Successful!!!";
                cout<<"\n                                                             Here is your bill: ";
                fstream f("tempbill.txt", ios::in);
                string s;
                getline(f,s);
                while(!f.eof())
                {
                    cout<<"                                                     "<<s<<"\n";
                    getline(f,s);
                }
                f.close();
                cout<<"\n                                                             Thanks for shoping!!!";
                getch();
            }
            else if(choice==1)
            {
                c1.productshow();
                getch();
            }
        }
        else if(k==2)
        {
            system("cls");
            string pass;
            cout<<"\n\n\n                                                      EMPLOYEE LOGIN PORTAL";
            cout<<"\n\n                                                        Enter Password: ";
            cin>>pass;
            if(pass=="emp")
            {
                system("cls");
                cout<<"\n\n\n                                                             Hi Employee!!!";
                cout<<"\n                                                     Enter your name: ";
                string s;
                cin>>s;
                emp e1;
                cout<<"                                                             Hello "<<s;
                cout<<"\n                                                        What you wanna do??";
                cout<<"\n                                                     1.Show list of products available";
                cout<<"\n                                                     2.Update the stock";
                cout<<"\n                                                     3.Show the earning of store";
                cout<<"\n                                                     4.Add a new product in stock";
                int choice = 1;
                cout<<"\n\n                                                     Enter Choice: ";
                cin>>choice;
                if(choice==1)
                {
                    cout<<"Products available with us: \n";
                    e1.stock_check();
                    getch();
                }
                else if(choice==2)
                {
                    e1.stock_check();
                    cout<<"\n                                                        Enter the name of product you want to update stock of: ";
                    string p;
                    cin>>p;
                    cout<<"\n                                                        Enter the product units added in the stock: ";
                    int unit;
                    cin>>unit;
                    e1.stock_update(p, unit);
                    cout<<"\n                                                             Stock Updated!!!";
                    getch ();
                }
                else if(choice==3)
                {
                    e1.money();
                    getch();
                }
                else if(choice==4)
                {
                    string s;
                    int cp, sp, q;
                    cout<<"\nProduct name: ";
                    cin>>s;
                    cout<<"\nCost Price of Product: ";
                    cin>>cp;
                    cout<<"\nSelling Price of the Product: ";
                    cin>>sp;
                    cout<<"\nNet units of the product in stock: : ";
                    cin>>q;
                    e1.addprod(s, cp, sp, q);
                    getch();
                }
            }
            else
            {
                system("cls");
                cout<<"\n\n\n                                                          WRONG PASSWORD!!!";
                cout<<"\n\n                                                          SESSION ABORTED";
                getch();
                exit(0);
            }
        }
        else if(k==3)
        {
            system("cls");
            string password;
            system("cls");
            cout<<"\n\n\n                                                         OWNER LOGIN PORTAL";
            cout<<"\n\n\n                                                        Enter Password: ";
            cin>>password;
            if(password=="own")
            {
                system("cls");
                owner o1;
                cout<<"\n                                                       What do you want to do? ";
                cout<<"\n                                                    1. Add a new employee";
                cout<<"\n                                                    2. View total earning";
                cout<<"\n                                                    3. View total profit";
                cout<<"\n                                                    4. Show products available";
                cout<<"\n                                                    5. Show ledger";
                cout<<"\n                                                 Enter your choice: ";
                int choice;
                cin>>choice;
                if(choice==1)
                {
                    cout<<"\n\n                                                            Adding a new employee\n";
                    o1.addemp();
                    getch();
                }
                else if(choice==2)
                {
                    cout<<"\n\n                                                            View Total Earning\n\n";
                    o1.earning();
                    getch();
                }
                else if(choice==3)
                {
                    cout<<"\n\n                                                            View total profit\n\n";
                    o1.profit();
                    getch();
                }
                else if(choice==4)
                {
                    cout<<"\n\n                                                            Products available with us\n\n";
                    o1.productsshow();
                    getch();
                }
                else if(choice==5)
                {
                    cout<<"\n\n                                                            Show Ledger\n\n";
                    o1.showledger();
                    getch();
                }
        
            }
            else
            {
                cout<<"\n\n\n                                                         WRONG PASSWORD!!";
                cout<<"\n\n\n                                                        Session Aborted";
                getch();
                exit(0);
            }
        }
        else if(k==0)
        exit(0);
        cout<<"\n                                                        Want to continue?? (Y/N): ";
        cin>>ch;
        if(ch=='N')
        {
            system("cls");
            cout<<"                                                       Thanks for visiting the Sundarban Portal!!!";
            getch();
        }
    }
    return 0;
}
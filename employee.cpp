#include "employee.h"
using namespace std;
using saamaan::product;
namespace karmchaari
{
    emp::emp()
    {
        cout<<"                                                            Hello !!!\n";
    }
    emp::emp(string s, int a, char g, string c)
    {
        name=s;
        age=a;
        gender=g;
        contact=c;
    }
    void emp::addprod(string s, int cp, int sp, int q)
    {
        newproduct(s,cp,sp,q);
        fstream f("ledger.txt", ios::app);
        f<<"------------NEW PRODUCT IN STOCK------------\n\n";
        f<<"Product name: "<<s;
        f<<"\nCost Price of Product: "<<cp;
        f<<"\nSelling Price of the Product: "<<sp;
        f<<"\nNet units of the product in stock: : "<<q;
        f<<"\n-------------------------------------------\n\n";
        f.close();
    }
    void emp::stock_check()
    {
        fstream fin("productlist.txt", ios::in);
        string s;
        while(getline(fin, s))
        {
            cout<<s<<"\n";
        }
        fin.close();
    }
    void emp::stock_update(string s, int k)
    {
        product p;
        string n=s;
        s.push_back('.');
        s.push_back('t');
        s.push_back('x');
        s.push_back('t');
        fstream f(s, ios::in | ios::out);
        f.read((char*)&p, sizeof(p));
        int orig=p.quantity;
        p.quantity+=k;
        f.close();
        fstream f1(s, ios::in | ios::out);
        f.write((char*)&p, sizeof(p));
        f.close();
        fstream g("ledger.txt", ios::app);
        g<<"----------------STOCK ADDED----------------";
        g<<"Name of product: "<<n;
        g<<"\nOriginal stock: "<<orig;
        g<<"\nAdded stock: "<<k;
        g<<"Total stock: "<<p.quantity;
        g<<"\n-------------------------------------------\n\n";
        g.close();
    }
    void emp::money()
    {
        fstream f("earning.txt", ios::in);
        int j;
        f>>j;
        cout<<"Total earning till date: "<<j;
        f.close();
    }
}
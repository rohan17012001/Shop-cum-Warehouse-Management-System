#include "owner.h"
using namespace std;
using saamaan::product ;
using karmchaari::emp;
namespace maalik
{
    owner::owner()
    {
        cout<<"                                                            Hi Owner!!\n";
    }
    void owner::addemp()
    {
        string s,c,ma;
        int a, b;
        char g;
        bool m;
        cout<<"Enter employee name: ";
        cin>>s;
        cout<<"\nEnter employee's age: ";
        cin>>a;
        cout<<"\nEnter the gender of employee (M/F): ";
        cin>>g;
        cout<<"Enter employee contact nuber: ";
        cin>>c;
        emp e1(s, a, g, c);
        fstream f("empdetail.txt", ios::app);
        f.write((char*)&e1, sizeof(e1));
        f.close();
    }
    void owner::earning()
    {
        cout<<"Total earning till date: ";
        fstream f("earning.txt", ios::in);
        long long int money;
        f>>money;
        cout<<money;
        f.close();
    }
    void owner::profit()
    {
        cout<<"Total profit made till date: ";
        fstream f("profit.txt", ios::in);
        long long int prof;
        f>>prof;
        cout<<prof;
        f.close();
    }
    void owner::productsshow()
    {
        cout<<"Products available: \n";
        fstream f("productlist.txt", ios::in);
        string s;
        f>>s;
        while(!f.eof())
        {
            cout<<s<<"\n";
            f>>s;
        }
        f.close();
    }
    void owner::showledger()
    {
        fstream f("ledger.txt", ios::in);
        string s;
        getline(f,s);
        while(!f.eof())
        {
            cout<<s<<"\n";
            getline(f,s);
        }
        f.close();
    }
}

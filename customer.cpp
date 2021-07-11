#include "customer.h"
using namespace std;
namespace graahak
{
    customer::customer(string s, string n)
    {
        name=s;
        contact=n;
    }
    void customer::productshow()
    {
        string s;
        fstream c("productlist.txt", ios::in);
        cout<<"Products availavble with us: \n";
        int k=1;
        c>>s;
        while(!c.eof())
        {
            cout<<k<<" : "<<s<<endl;
            k+=1;
            c>>s;
        }
    }
    void customer::buy()
    {
        int k;
        productshow();
        cout<<"Enter the number of different products you want to buy: ";
        cin>>k;
        int m=1;
        string s;
        long long int earn=0, loss=0;
        int q;
        for(int i=1;i<=k;i++)
        {
            cout<<"Enter the name of product "<<i<<" : ";
            cin>>s;
            int q;
            cout<<"\nEnter the no of quantities required of "<<s<<" : ";
            cin>>q;
            product p;
            int n=p.quantity_change(s,q);
            if(n==0)
            {
                cout<<"Not enough stocks left for the given product. Sorry! ";
            }
            else
            {
                ofstream ab("tempbill.txt",ios::app);
                ab<<m<<")"<<s<<" : "<<q<<" "<< q*(n%1000)<<"\n";
                m+=1;
                earn+= n%1000;
                loss+= n/1000;
                ab.close();
            }
        }
        fstream pesa("earning.txt", ios::in | ios:: out | ios::trunc);
        long long int j;
        pesa>>j;
        long long int paisa=j+earn;
        pesa<<paisa;
        pesa.close();
        long long int profit=earn-loss;
        fstream prof("profit.txt", ios::in | ios::out | ios::trunc);
        long long int d;
        prof>>d;
        long long int munafa=d+profit;
        prof<<munafa;
        prof.close();
        fstream bahi("ledger.txt", ios::app);
        bahi<<"----------NEW ENTRY IN THE LEDGER----------\n";
        bahi<<"Original amount in the treasury: "<<j;
        bahi<<"\nAmount of purchase done: "<<earn;
        bahi<<"\nTotal amount in treasury: "<<paisa;
        bahi<<"\n\nNet profit in recent pruchase: "<<profit;
        bahi<<"\nTotal profit earned till date: "<<munafa;
        bahi<<"\n-------------------------------------------\n\n";
        bahi.close();
    }
}
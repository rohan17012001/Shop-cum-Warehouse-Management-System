#include "product.h"
#include<bits/stdc++.h>
using namespace std;
namespace saamaan
{
    void product::newproduct(string s, int p, int sp, int q)
    {
        ofstream outfile("productlist.txt", ios::app);
        product k;
        k.prod_name=s;
        k.costprice=p;
        k.sellprice=sp;
        k.quantity=q;
        outfile<<k.prod_name<<"\n";
        outfile.close();
        cout<<"\nProduct added in the list!\n";
        s.push_back('.');
        s.push_back('t');
        s.push_back('x');
        s.push_back('t');
        fstream f(s, ios::app);
        f.write((char*)&k,sizeof(k));
        f.close();
    }
    int product::quantity_change(string s, int k)
    {
        product a;
        string s1=s;
        s1.push_back('.');
        s1.push_back('t');
        s1.push_back('x');
        s1.push_back('t');
        fstream f(s1, ios::in | ios::out);
        f.read((char*)&a,sizeof(a));
        if(a.quantity-k<0)
        {
            cout<<"Sorry, not enought stocks available for this product!\n";
            return 0;
        }
        else
        {
            a.quantity-=k;
            f.write((char*)&a,sizeof(a));
            long long int mon=a.costprice*1000+a.sellprice;
            return mon;
        }
        /*ifstream fin("productlist.txt", ios::in);
        fin.read((char*)&a, sizeof(a));
        while(!fin.eof())
        {
            if(a.prod_name==s)
            {
                if(a.quantity-k<0)
                {
                    cout<<"Not required stocks of the product "<<a.prod_name<<" left";
                    return 0;
                }
                else
                {
                    a.quantity-=k;
                    return 1;
                }
            }
        }*/
    }
}
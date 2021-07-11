#ifndef _prod
#define _prod
#include<bits/stdc++.h>
using std::string;
namespace saamaan
{
    class product
    {
        public:
            string prod_name;
            int costprice;
            int sellprice;
            int quantity;
            void newproduct(string s, int p, int sp, int q);
            int quantity_change(string s, int);
    };
}
#endif
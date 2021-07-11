#ifndef _cust
#define _cust
#include<bits/stdc++.h>
#include "product.h"
using std::cin;
using std::cout;
using std::string;
using saamaan::product;
namespace graahak
{
    class customer:virtual public product
    {
        public:
            string name;
            string contact;
            customer(string,string);
            static void productshow();
            void buy();            
    };
}
#endif
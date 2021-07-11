#ifndef _empl
#define _empl
#include<bits/stdc++.h>
#include "product.h"
using namespace std;
using saamaan::product ;
namespace karmchaari
{
    class emp:virtual public product
    {
        public:
            string name;
            int age;
            char gender;
            string contact;
            emp();
            emp(string s, int a, char g, string c);
            void addprod(string, int, int, int);
            void stock_check();
            void stock_update(string s, int k);
            void money();
    };
}
#endif
#ifndef _own
#define _own
#include<bits/stdc++.h>
#include "employee.h"
#include "customer.h"
using namespace std;
using karmchaari::emp;
using graahak::customer;
namespace maalik
{
    class owner: public emp
    {
        public:
            owner();
            void addemp();
            void earning();
            void profit();
            void productsshow();
            void showledger();
    };
}
#endif
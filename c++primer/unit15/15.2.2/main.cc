#include "Quote.h"
#include <iostream>
using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Bulk_quote bq("123", 50.0, 2, 0.3);
    print_total(cout, bq, 3);
}
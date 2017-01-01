#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const double &d, const std::string &s) : price(d), bookNo(s) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
protected:
    double price = 0.0;
private:
    std::string bookNo;
};


class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string s, double p, std::size_t st, double d) : Quote(p, s), min_qty(st), discount(d) { }
    double net_price(std::size_t n) const override
    {
        if (n >= min_qty)
            return n * price * (1 - discount);
        else
            return n * price;
    }
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};
#include <unordered_map>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

class Product
{
public:
    virtual float getPrice() = 0;
};

class Water : public Product
{
public:
    float getPrice()
    {
        return 1.0;
    }
};

class Coke : public Product
{
public:
    float getPrice()
    {
        return 2.0;
    }
};

class Payment
{
public:
    virtual float checkout(Product *p) = 0;
};

class CardPayment : public Payment
{
public:
    float checkout(Product *p)
    {
        return p->getPrice() * 0.8;
    }
};

class CashPayment : public Payment
{
public:
    float checkout(Product *p)
    {
        return p->getPrice() * 1;
    }
};

class VendingMachine
{
private:
    unordered_map<string, Product *> slots;

    int capacity;
    int pay;

public:
    VendingMachine(int cap) : capacity(cap){};

    bool addProduct(string idx, Product *p)
    {
        if (slots.size() >= capacity)
        {
            return false;
        }
        slots.insert({idx, p});

        return true;
    }

    Product *order(string idx)
    {
        auto result = slots[idx];
        if (result)
        {
            slots.erase(idx);
        }

        return result;
    }

    float checkout(vector<Product *> prod, Payment *pay)
    {
        float total = 0;
        for (auto p : prod)
        {
            total += pay->checkout(p);
        }

        return total;
    }
};

class Customer
{
private:
    VendingMachine *vm;

    vector<Product *> cart;

public:
    Customer(VendingMachine *v) : vm(v) {}

    bool select(string idx)
    {
        Product *p = vm->order(idx);

        if (p)
        {
            cart.push_back(p);
            return true;
        }

        return false;
    }

    float checkout(Payment *payment)
    {
        return vm->checkout(cart, payment);
    }
};

int main()
{
    auto w1 = new Water();
    auto w2 = new Water();
    auto c1 = new Coke();
    auto c2 = new Coke();

    auto vm = new VendingMachine(5);
    vm->addProduct("A1", w1);
    vm->addProduct("A2", w2);
    vm->addProduct("A3", c1);
    vm->addProduct("A4", c2);

    Customer *customer = new Customer(vm);
    customer->select("A1");
    customer->select("A2");

    auto card = new CardPayment();
    assert(abs(customer->checkout(card) - 1.6) < 1e-6);

    return 0;
}

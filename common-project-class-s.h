#ifndef common_proj_s
#define common_proj_s
#include "domain.h"

class Product
{
protected:
    string name;
    double price;
    int quantity;

public:
    Product(const string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

    virtual ~Product() = default;

    virtual string getName() const
    {
        return name;
    }
    virtual double getPrice() const
    {
        return price;
    }
    virtual int getQuantity() const
    {
        return quantity;
    }
    virtual void updatePrice(double newPrice)
    {
        price = newPrice;
    }
    virtual void updateQuantity(int newQuantity)
    {
        quantity = newQuantity;
    }
    virtual void GetInfo() const
    {
        cout << "Product: " << name << "\nPrice: " << price << " $" << "\nQuantity: " << quantity << endl;
    }
};


class DiscountedProduct : public Product
{
private:
    double discount;
public:
    DiscountedProduct(const string name, double price, int quantity, double discount) : Product(name, price, quantity), discount(discount) {}

    double getPrice() const override
    {
        return price * (1 - discount / 100.0);
    }

    void setDiscount(double newDiscount)
    {
        discount = newDiscount;
    }
    void GetInfo() const 
    {
        cout << "Product: " << name << "\nPrice: " << price << "\nQuantity: " << quantity << "\nDiscount: " << discount << "\nDiscounted price: " << getPrice() << "%" << endl;;
    }
};

class Category : public DiscountedProduct, public Product
{
private:
    string name;
    vector<shared_ptr<Product>> products;
public:
    Category() = default;
    void addProduct(const shared_ptr<Product>& product)
    {
        products.push_back(product);
    }

    void removeProduct(const string& productName)
    {
        products.erase(remove_if(products.begin(), products.end(), [&productName](const shared_ptr<Product>& product) {
            return product->getName() == productName;
            }), products.end());

    }
    void getProducts(string name) const
    {
        cout << "Category: " << name << endl;
        for (int i = 0; i < products.size(); ++i)
        {
           products[i]->GetInfo();
        }cout << endl;

    }
    int getProductCount() const
    {
        return products.size();
    }
};
#endif // common_proj_s
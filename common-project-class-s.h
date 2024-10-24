#ifndef common_proj_s
#define common_proj_s
#include "libs.h"

class Product
{
protected:
	string name;
	double price;
	int quantity;

public:
	Product(const string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

	virtual ~Product() = default;

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

	
	virtual void display() const
	{
		cout << "Name: " << name << endl;
		cout << "Price: $" << price << endl;
		cout << "Quantity: " << quantity << "\n" << endl;
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
		 return price * (1 - discount / 100);
	}

	void setDiscount(double newDiscount)
	{
		discount = newDiscount;
	}
	void display() const override
	{
		cout << "Name(discounted): " << name << endl;
		cout << "Start Price: $" << price << endl;
		cout << "Discount: " << discount << "%" << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Discounted Price: $" << discount << "\n" << endl;
	}
};
#endif // common_proj_s
#ifndef common_proj_s
#define common_proj_s
#include "domain.h"

class Product
{
protected:
	string name;
	float price;
	int quantity;

public:
	Product(const string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

	virtual ~Product() = default;

	virtual float getPrice() const
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
		cout << "Price: " << price << "$" << endl;
		cout << "Quantity: " << quantity << "\n" << endl;
	}
	
};

class Category
{
string categoryName, *categories;
Product* products;
int size_1, size_2;
public:
	void addProduct(int index, const string& name, float price, int quantity)
	{
		if (index >= 0 && index < size_1)
			products[index] = Product(name, price, quantity);
	}
	void removeProduct(int index) {
		if (index < 0 || index >= size_1) {
			cout << "Invalid index!" << endl;
		}
		for (int i = index; i < size_1 - 1; ++i) {
			products[i] = products[i + 1];
		}
		size_1--;
		cout << "Item removed from index " << index << ".\n";
	}
	void getProducts(int products)
	{
		for (int i = 0; i < size_1; ++i)
		{
			cout << products[i] << " ";
		}
	}
	~Category() {
		delete[] products;
	}
};

class DiscountedProduct : public Product
{
private:
	float discount;
public:
	DiscountedProduct(const string name, float price, int quantity, float discount) : Product(name, price, quantity), discount(discount) {}

	float getPrice() const override
	{
		 return price * (1 - discount / 100);
	}

	void setDiscount(float newDiscount)
	{
		discount = newDiscount;
	}
	void display() const override
	{
		cout << "Name(discounted): " << name << endl;
		cout << "Start Price:" << price <<  "$" << endl;
		cout << "Discount: " << discount << "%" << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Discounted Price: " << discount << "$" << "\n" << endl;
	}
};
#endif // common_proj_s
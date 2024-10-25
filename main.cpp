#include "common-project-class-s.h"

int main()
{
	Product newProduct("Guitar", 1400, 10);
	Category newCategory("Musical Instruments");
	newProduct.GetInfo();

	shared_ptr<Product> newProductPtr = make_shared<Product>("Drums", 2000, 5);
	newCategory.addProduct(newProductPtr);
	shared_ptr<Product> newProductPtr2 = make_shared<Product>("Piano", 3000, 3);
	newCategory.addProduct(newProductPtr2);
	shared_ptr<Product> newProductPtr3 = make_shared<Product>("Electric Bass Guitar", 2300, 10);
	newCategory.addProduct(newProductPtr3);
	shared_ptr<Product> newDIscountedProductPtr1 = make_shared<Product>("Electric Bass Guitar", 2300, 10);
	newCategory.addProduct(newDIscountedProductPtr1);

	DiscountedProduct newDiscountedProduct("Electric Bass Guitar", 2300, 10, 15);
	newDiscountedProduct.GetInfo();
	newCategory.listProducts();
	newCategory.removeProduct("Piano");

	cout << "Product count:" << newCategory.getProductCount() << endl;


	Product* productPtr = &newDiscountedProduct;
	productPtr->GetInfo();

	return 0;
}
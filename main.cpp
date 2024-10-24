#include "domain.h"

int main()
{
	Product newProduct("Guitar", 1400, 10);
	newProduct.display();

	DiscountedProduct newDiscountedProduct("Electric Bass Guitar", 2300, 10, 15);
	newDiscountedProduct.display();

	Product* productPtr = &newDiscountedProduct;
	productPtr->display();

	return 0;
}
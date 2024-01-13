#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct order {
	int orderID;
	char *customerName;
	struct items *orderItems[];
};

struct items {
	char *itemName;
	float price;
};

void main(){

	struct items menu[6];

	struct items burger;
	burger.itemName = "Burger";
	burger.price = 4.99;

	menu[0] = burger;

	struct items sandwich;
	sandwich.itemName = "Sandwich";
	sandwich.price = 3.99;

	menu[1] = sandwich;

	struct items tenders;
	tenders.itemName = "Tenders";
	tenders.price = 3.99;

	menu[2] = tenders;

	struct items fries;
	fries.itemName = "Fries";
	fries.price = 1.99;

	menu[3] = fries;

	struct items biscuit;
	biscuit.itemName = "Biscuit";
	biscuit.price = 1.00;

	menu[4] = biscuit;

	struct items softdrink;
	softdrink.itemName = "Soft Drink";
	softdrink.price = 0.89;

	menu[5] = softdrink;

	printf("\nMenu List:");

	for(int i = 0; i < 6; i++){
		printf("\nThe name of item is %s the price of item is $%.2f,", menu[i].itemName, menu[i].price);

	}
	printf("\n");
	int response;
	int quantity;
	float tax = 0;
	float sum_total = 0;
	float grossrev;

	int totalCustomerOrder;
	int count =0;
	struct order takeOrder[30];
	struct items *pointerMenu = menu;

	char input = 'y';

	while(input == 'y'){

		printf("\nPlease make a selection. Type 0 for burger, 1 for sandwich, etc, ");
		scanf("%d", &response);
		printf("How many do you want? ");
		scanf("%d", &quantity);

		totalCustomerOrder = count + quantity;

		for(int j = count; j < totalCustomerOrder; j++){
			takeOrder[0].orderItems[j] = &pointerMenu[response];
			count++;
		}
		printf("\nDo you want to make another order? (y for yes/ no for no) ");
		scanf("%s",&input);
		}

	for(int i = 0; i < totalCustomerOrder; i++){
		sum_total = sum_total + takeOrder->orderItems[i]->price;
	}
	tax = 0.07 * sum_total;

	printf("\n ORDER: \n");
	for(int i = 0; i < totalCustomerOrder; i++){
		printf("item: %s\t price: $%.2f\n", takeOrder->orderItems[i]->itemName, takeOrder->orderItems[i]->price);
	}
	printf("\n");
	printf("Total Bill including Tax: \t$%.2f\n", tax);

	FILE *fp;
	fp = fopen("menu.txt","w");
	fprintf(fp,"ORDER:\n");

	for(int i = 0; i < totalCustomerOrder; i++){
		fprintf(fp, "%s\n $%.2f\n", takeOrder->orderItems[i]->itemName, takeOrder->orderItems[i]->price);
	}

	fprintf(fp, "\nTotal cost with tax:\n $%.2f", tax);
	fclose(fp);
}

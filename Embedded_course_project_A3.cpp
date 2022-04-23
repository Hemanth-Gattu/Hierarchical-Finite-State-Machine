#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

enum VendingMachineState {
	SELECT, AVAILABILITY, CALCULATE, UPDATE
};

enum Brand {
	COKE = 1, LAYS = 2, OREO = 3, DIARYMILK = 4, REAL = 5, 
};

struct Product {
	Brand brandName;
	int quantity;
	int price;
};

string name = "You";
int points = 500; //100,000 Points in Wallet


int main() {

	//Initial Vending Machine State is SELECT. Update upon state change.
	VendingMachineState currentState = SELECT;
	
	vector<Brand> product_name = {COKE,LAYS,OREO,DIARYMILK,REAL};
	vector<int> product_quantity = {10,8,10,15,20};
	vector<int> product_cost = {40,20,40,100,20};
	vector<string> p_names = {"COKE","LAYS","OREO","DIARYMILK","REAL"};
	//Fill up our vending machine with Products.
	Product vendingMachine[product_name.size()];
	
	for(int i=0;i<product_name.size();i++){
	    vendingMachine[i].brandName = product_name[i];
	    vendingMachine[i].quantity = product_quantity[i];
	    vendingMachine[i].price = product_cost[i];
	}
	
	Product selectedProduct;

	while (true) {
		switch (currentState) {
		case SELECT:
		
			//1. Display the current status for the vending machine and the student's wallet.
			cout << "Current Status of Vending Machine" << endl;
			cout << "\n";
			sleep(2);//sleeps for 4 second
			
                cout << left
                << setw(10)
                << "Product"
                << left
                << setw(12)
                << "AVAILABILITY "
                << left
                << setw(12)
                << "PRICE"
                << endl<<endl;
                
			for (int i = 0; i < product_name.size(); i++) {
    			cout<< left
                << setw(10)
                << vendingMachine[i].brandName
                << left
                << setw(12)
                << vendingMachine[i].quantity
                << left
                << setw(12)
                <<  vendingMachine[i].price 
                << endl;
				sleep(0.75);
			}
			
			cout << "\n";

			cout << "Total Points "<< name << " have : " <<  points << endl;
			cout << "\n";
			sleep(1);

			
			//3. Display the soda names and corresponding ID values.
			cout << left
                << setw(20)
                << "PRODUCT NAME"
                << left
                << setw(20)
                << "PRODUCT ID"
                << endl<<endl;
            for (int i = 0; i < product_name.size(); i++) {
    			cout<< left
                << setw(20)
                << p_names[i]
                << left
                << setw(20)
                << i+1
                << endl;
			}
			
			//2. Ask the user what drink they want.
			cout<<endl;
			cout << "Select a Product from the Above ID's : ";
			sleep(0.5);
			
			//4. User inputs the drink.
			int selectedDrink;
			cin >> selectedDrink;
			
			cout<<endl;
			
			//5. If valid drink selected, move to QUANTITY state; else, go back to SELECT state.
			switch (selectedDrink) {
			    
			case COKE:
				cout << "Product selected : COKE" << endl;
				selectedProduct.brandName = COKE;
				currentState = AVAILABILITY;
				break;
			case LAYS:
				cout << "Product selected : LAYS" << endl;
				selectedProduct.brandName = LAYS;
				currentState = AVAILABILITY;
				break;
			case OREO:
				cout << "Product selected : OREO" << endl;
				selectedProduct.brandName = OREO;
				currentState = AVAILABILITY;
				break;
			case DIARYMILK:
				cout << "Product selected : DIARYMILK" << endl;
				selectedProduct.brandName = DIARYMILK;
				currentState = AVAILABILITY;
				break;
			case REAL:
				cout << "Product selected : REAL" << endl;
				selectedProduct.brandName = REAL;
				currentState = AVAILABILITY;
				break;

			default:
				cout << " Invalid Product Selected ! " << endl;
				cout << " No Product Available ! " << endl;
				currentState = SELECT;
				break;
			}
			break;
			
		case AVAILABILITY:

			cout << "Required Quantity: ";
			int orderQuantity;
			cin >> orderQuantity;
            cout << "\n";
			cout << "Your order has been received. You placed an order " << orderQuantity << " Product(s)" << endl;

			switch (selectedProduct.brandName) {
			    
			case COKE:
				if (orderQuantity < 0 || orderQuantity > vendingMachine[0].quantity) {
					cout << "Not Enough " << selectedProduct.brandName << " In Stock" << endl;
					currentState = SELECT;
					cout << endl ;
				}
				else {
					currentState = CALCULATE;
				}
				break;
			case LAYS:
				if (orderQuantity < 0 || orderQuantity > vendingMachine[1].quantity) {
					cout << "Not Enough In Stock" << endl;
					currentState = SELECT;
					cout << endl ;
				}
				else {
					currentState = CALCULATE;
				}
				break;
			case OREO:
				if (orderQuantity < 0 || orderQuantity > vendingMachine[2].quantity) {
					cout << "Not Enough In Stock" << endl;
					currentState = SELECT;
					cout << endl ;
				}
				else {
					currentState = CALCULATE;
				}
				break;
			case DIARYMILK:
				if (orderQuantity < 0 || orderQuantity > vendingMachine[3].quantity) {
					cout << "Not Enough In Stock" << endl;
					currentState = SELECT;
					cout << endl ;
				}
				else {
					currentState = CALCULATE;
				}
				break;
			case REAL:
				if (orderQuantity < 0 || orderQuantity > vendingMachine[4].quantity) {
					cout << "Not Enough In Stock !" << endl;
					currentState = SELECT;
					cout << endl ;
				}
				else {
					currentState = CALCULATE;
				}
				break;
			default:
				cout << "Invalid Amount Received." << endl;
				break;
			}

			break;
		case CALCULATE:
			cout << "Total Amount : ";
			int cost;
			switch (selectedProduct.brandName) {
				case COKE:
					cost = vendingMachine[0].price * orderQuantity;
					cout << cost << endl;
					break;
				case LAYS:
					cost = vendingMachine[1].price * orderQuantity;
					cout << cost << endl;
					break;
				case OREO:
					cost = vendingMachine[2].price * orderQuantity;
					cout << cost << endl;
					break;
				case DIARYMILK:
					cost = vendingMachine[3].price * orderQuantity;
					cout << cost << endl;
					break;
				case REAL:
					cost = vendingMachine[4].price * orderQuantity;
					cout << cost << endl;
					break;
				default:
					cout << "Error!" << endl;
					break;
			}
			int payment;
			cout << "Please type in your payment : ";
			cin >> payment;

			if (payment > points || payment < cost || payment <= 0) {
				cout << "You don't have enough money !" << endl;
				currentState = SELECT;
				cout << endl ;
			}
			else {
				points =  points - payment;
				int change = payment - cost;
				cout << "\n";
				sleep(0.75);
				cout << "Thank you! Your change is " << change << " points." << endl;
				points =  points + change;
				currentState = UPDATE;
			}

			break;
	
		case UPDATE:

			switch (selectedProduct.brandName) {
				case COKE:
					vendingMachine[0].quantity = vendingMachine[0].quantity - orderQuantity;
					currentState = SELECT;
					cout << endl ;
					break;
				case LAYS:
					vendingMachine[1].quantity = vendingMachine[1].quantity - orderQuantity;
					currentState = SELECT;
					cout << endl;
					break;
				case OREO:
					vendingMachine[2].quantity = vendingMachine[2].quantity - orderQuantity;
					currentState = SELECT;
					cout << endl ;
					break;
				case DIARYMILK:
					vendingMachine[3].quantity = vendingMachine[3].quantity - orderQuantity;
					currentState = SELECT;
					cout << endl ;
					break;
				case REAL:
					vendingMachine[4].quantity = vendingMachine[4].quantity - orderQuantity;
					currentState = SELECT;
					cout << endl ;
					break;
				default: 
					cout << "Error" << endl;
					currentState = SELECT;
					cout << endl ;
					break;
			}

			cout << "quantity Updated" << endl;
			currentState = SELECT;
			cout << endl ;

			break;
		default:
			cout << "Error! Invalid State Detected." << endl;
			break;
		}
	}
	return 0;
}

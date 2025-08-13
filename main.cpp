#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility> // for pair

using namespace std;

struct Order {
    int orderID;
    string customerName;
    vector<pair <string,int> > items;  // pair<foodItem, quantity>
};

class Restaurant {
private:
    queue<Order> orderQueue; //vector stores the struct elements in the queue
    vector<Order> completedOrders; // vector stores the completed orders with the struct elements
    int nextOrderID = 1;

public:

    void takeOrder(const string& customerName, const string& foodItem, int quantity) {
        Order newOrder;
        newOrder.orderID = nextOrderID++; // object uses dot to approah variable
        newOrder.customerName = customerName;
        newOrder.items.push_back({ foodItem, quantity });

        orderQueue.push(newOrder);
        cout << "Order placed successfully! -- Order ID: " << newOrder.orderID <<endl;
    }

    void addItemToOrder(int orderID, const string& item, int quantity) {//update existing order
        queue<Order> tempQueue; // temporary queue to store orders
        bool found = false;
        while (!orderQueue.empty()) {// loop through the queue when the queue ends
            Order current = orderQueue.front();
            orderQueue.pop();
            if (current.orderID == orderID) {
                current.items.push_back({ item, quantity });
                found = true;
                cout << "Item added to Order ID " << orderID << " successfully."<<endl;
            }
            tempQueue.push(current);
        }
        orderQueue = tempQueue;
        if (!found) {
            cout << "Order ID not found in pending orders or already processed."<<endl;
        }
    }
    void CompleteOrder() {
        if (orderQueue.empty()) {
            cout << "No pending orders to process."<<endl;
            return;
        }
        Order order = orderQueue.front();
        orderQueue.pop();
        completedOrders.push_back(order);// add to completed orders
        cout << "Processing Order ID: " << order.orderID << endl;
        cout << "Customer: " << order.customerName << "\n Items:"<<endl;
        for (const auto& item : order.items) { // display all the items of an order
            cout << "- " << item.first << " x" << item.second << endl; //first is food item and second is quantity
        }
        cout << "Order Completed!"<<endl;
    }
    void showPendingOrders() const {
        if (orderQueue.empty()) {
            cout << "No pending orders."<<endl;
            return;
        }
        queue<Order> tempQueue = orderQueue;
        cout << "Pending Orders:"<<endl;
        while (!tempQueue.empty()) {
            Order pending = tempQueue.front(); //retrieve first because FIFO apply
            tempQueue.pop();

            cout << "Order ID: " <<pending.orderID << ", Customer: " <<pending.customerName << "\n";
            for (const auto& item : pending.items) {
                cout << "   - " << item.first << " x" << item.second << endl;
            }
        }
    }
    void showCompletedOrders() const {
        if (completedOrders.empty()) {
            cout << "No completed orders."<<endl;
            return;
        }
        cout<<"Completed Orders:"<<endl;
        for(const Order& ord : completedOrders) {
            cout<< "Order ID: " << ord.orderID << ", Customer: " << ord.customerName <<endl;
            for(const auto& item : ord.items) {
                cout<< "   -- " << item.first << " x" << item.second <<endl;
            }
        }
    }
};

int main() {
    Restaurant restaurant; // Object of the class
    int choice;
    cout<<"\n=====--- WELCOME TO MS CUISINE ---=====\n";
    do {
        cout<<"\n===== Restaurant Order Management System ====="<<endl;
        cout<<"1. Place New Order"<<endl;
        cout<<"2. Add Item to Existing Order"<<endl;
        cout<<"3. Process Next Order"<<endl;
        cout<<"4. Show Pending Orders"<<endl;
        cout << "5. Show Completed Orders"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"  -  Choose an option:  ";
        cin >> choice;
        cin.ignore();
        cout << endl;
        if (choice == 1) {
            string customerName, foodItem;
            int quantity;
            cout << "Enter customer name: ";
            getline(cin, customerName);
            cout << "Enter food item: ";
            getline(cin, foodItem);
            cout << "Enter quantity: ";
            cin >> quantity;
            cin.ignore();
            restaurant.takeOrder(customerName, foodItem, quantity);
        }
        else if (choice == 2) {
            int orderID, quantity;
            string item;
            cout << "Enter Order ID to update: ";
            cin >> orderID;
            cin.ignore();
            cout << "Enter new food item: ";
            getline(cin, item);
            cout << "Enter quantity: ";
            cin >> quantity;
            cin.ignore();
            restaurant.addItemToOrder(orderID, item, quantity);
        }
        else if (choice == 3) {
            restaurant.CompleteOrder();
        }
        else if (choice == 4) {
            restaurant.showPendingOrders();
        }
        else if (choice == 5) {
            restaurant.showCompletedOrders();
        }
        else if (choice == 6) {
            cout << " --Thanks You-- \n Exiting system."<<endl;
        }
        else {
            cout << "Invalid choice."<<endl;
        }
    } while (choice != 6); //do while loop to repeat the menu until exit and also run 1 time
    return 0;
}

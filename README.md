Restaurant Order Management System (C++)
This project is a console-based Restaurant Order Management System developed in C++ as part of my Data Structures and Algorithms course. It demonstrates the application of queues, vectors, structs, and object-oriented programming concepts to manage restaurant operations efficiently.

Features
Place Orders – Record customer name, ordered items, and quantities.

Modify Orders – Add items to existing pending orders before they are processed.

Process Orders – Serve orders based on the First-In-First-Out (FIFO) principle.

View Pending Orders – Display details of all unprocessed orders.

View Completed Orders – Maintain a record of processed orders for reference.

Technical Implementation
Queue: Stores pending orders to ensure FIFO order processing.

Vector: Holds multiple items within a single order.

Structs: Encapsulate order details such as ID, customer name, and item list.

OOP Principles: Encapsulation and modular design for maintainability and clarity.

How It Works
A new order is placed and added to the pending orders queue.

Additional items can be appended to a pending order before processing.

The system processes orders sequentially, moving them from the pending queue to the completed orders list.

The user can view pending or completed orders at any time.

Educational Value
This project showcases how data structures can be applied to real-world problems, emphasizing efficient order handling, record management, and modular programming practices. It also reinforces the integration of multiple C++ features—such as classes, member functions, and STL containers—into a cohesive, functional application.

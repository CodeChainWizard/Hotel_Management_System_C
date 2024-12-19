// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Structure to represent a hotel room
// typedef struct {
//     int roomNumber;
//     int capacity;
//     int price;
//     char status[10]; // "available" or "booked"
// } Room;

// // Structure to represent a customer
// typedef struct {
//     char name[50];
//     char email[50];
//     char phoneNumber[20];
//     int bookingCount;
// } Customer;

// // Structure to represent a booking
// typedef struct {
//     int bookingId;
//     int roomId;
//     int customerId;
//     char bookingDate[20];
//     char checkinDate[20];
//     char checkoutDate[20];
// } Booking;

// // Structure to represent a manager
// typedef struct {
//     char username[20];
//     char password[20];
// } Manager;

// // Structure to represent a receptionist
// typedef struct {
//     char username[20];
//     char password[20];
// } Receptionist;

// // Function to display the header
// void displayHeader() {
//     printf("\n");
//     printf("****************************************************\n");
//     printf("*                                                 *\n");
//     printf("*               Hotel Management System          *\n");
//     printf("*                                                 *\n");
//     printf("****************************************************\n");
//     printf("\n");
// }

// // Function to add a new room
// void addRoom(Room *rooms, int *roomCount) {
//     Room newRoom;
//     printf("Enter room number: ");
//     scanf("%d", &newRoom.roomNumber);
//     printf("Enter room capacity: ");
//     scanf("%d", &newRoom.capacity);
//     printf("Enter room price: ");
//     scanf("%d", &newRoom.price);
//     strcpy(newRoom.status, "available");
//     rooms[*roomCount] = newRoom;
//     (*roomCount)++;
// }

// // Function to book a room
// void bookRoom(Room *rooms, int roomCount, Customer *customers, int customerCount, Booking *bookings, int *bookingCount) {
//     int roomId;
//     printf("Enter room number to book: ");
//     scanf("%d", &roomId);
//     for (int i = 0; i < roomCount; i++) {
//         if (rooms[i].roomNumber == roomId && strcmp(rooms[i].status, "available") == 0) {
//             printf("Enter customer name: ");
//             scanf("%s", customers[customerCount].name);
//             printf("Enter customer email: ");
//             scanf("%s", customers[customerCount].email);
//             printf("Enter customer phone number: ");
//             scanf("%s", customers[customerCount].phoneNumber);
//             customers[customerCount].bookingCount++;
//             Booking newBooking;
//             newBooking.bookingId = *bookingCount;
//             newBooking.roomId = roomId;
//             newBooking.customerId = customerCount;
//             printf("Enter booking date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.bookingDate);
//             printf("Enter checkin date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkinDate);
//             printf("Enter checkout date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkoutDate);
//             bookings[*bookingCount] = newBooking;
//             (*bookingCount)++;
//             strcpy(rooms[i].status, "booked");
//             return;
//         }
//     }
//     printf("Room not available\n");
// }

// // Function to cancel a booking
// void cancelBooking(Room *rooms, int roomCount, Booking *bookings, int bookingCount) {
//     int bookingId;
//     printf("Enter booking ID to cancel: ");
//     scanf("%d", &bookingId);
//     for (int i = 0; i < bookingCount; i++) {
//         if (bookings[i].bookingId == bookingId) {
//             for (int j = 0; j < roomCount; j++) {
//                 if (rooms[j].roomNumber == bookings[i].roomId) {
//                     strcpy(rooms[j].status, "available");
//                     break;
//                 }
//             }
//             printf("Booking cancelled\n");
//             return;
//         }
//     }
//     printf("Booking not found\n");
// }

// // Function to login as manager
// int loginManager(Manager manager) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, manager.username) == 0 && strcmp(password, manager.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to display rooms
// void displayRooms(Room *rooms, int roomCount) {
//     printf("+---------+----------+----------+ --------+\n");
//     printf("| Room No | Capacity | Price   | Status |\n");
//     printf("+---------+----------+----------+--------+\n");
//     for (int i = 0; i < roomCount; i++) {
//         printf("| %6d | %8d | %8d | %6s |\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].price, rooms[i].status);
//     }
//     printf("+---------+----------+----------+--------+\n");
// }

// // Function to display customer status
// void displayCustomerStatus(Customer *customers, int customerCount) {
//     printf("+---------+----------+----------+----------+\n");
//     printf("| Customer| Email    | Phone    | Bookings |\n");
//     printf("+---------+----------+----------+----------+\n");
//     for (int i = 0; i < customerCount; i++) {
//         printf("| %6s | %8s | %8s | %8d |\n", customers[i].name, customers[i].email, customers[i].phoneNumber, customers[i].bookingCount);
//     }
//     printf("+---------+----------+----------+----------+\n");
// }

// // Function to display booking status
// void displayBookingStatus(Booking *bookings, int bookingCount) {
//     printf("+---------+----------+----------+----------+----------+\n");
//     printf("| Booking | Room No | Customer | Booking  | Checkin  | Checkout|\n");
//     printf("+---------+----------+----------+----------+----------+\n");
//     for (int i = 0; i < bookingCount; i++) {
//         printf("| %6d | %6d | %8d | %8s | %8s | %8s |\n", bookings[i].bookingId, bookings[i].roomId, bookings[i].customerId, bookings[i].bookingDate, bookings[i].checkinDate, bookings[i].checkoutDate);
//     }
//     printf("+---------+----------+----------+----------+----------+\n");
// }

// // Function to login as receptionist
// int loginReceptionist(Receptionist receptionist) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, receptionist.username) == 0 && strcmp(password, receptionist.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// Function to load menu items from a file
// void loadMenu(MenuItem *menu, int *menuCount) {
//     FILE *file = fopen("menu.txt", "r");
//     if (file == NULL) {
//         printf("Could not open menu file.\n");
//         return;
//     }
//     while (fscanf(file, "%49[^,],%f\n", menu[*menuCount].name, &menu[*menuCount].price) != EOF) {
//         (*menuCount)++;
//     }
//     fclose(file);
// }

// // Function to display the menu
// void displayMenu(MenuItem *menu, int menuCount) {
//     printf("+----------------------+----------+\n");
//     printf("| Item                 | Price    |\n");
//     printf("+----------------------+----------+\n");
//     for (int i = 0; i < menuCount; i++) {
//         printf("| %-20s | %.2f    |\n", menu[i].name, menu[i].price);
//     }
//     printf("+----------------------+----------+\n");
// }

// // Function to purchase an item
// void purchaseItem(MenuItem *menu, int menuCount) {
//     char itemName[50];
//     printf("Enter the name of the item to purchase: ");
//     scanf("%s", itemName);
//     for (int i = 0; i < menuCount; i++) {
//         if (strcmp(menu[i].name, itemName) == 0) {
//             printf("You have purchased %s for %.2f\n", menu[i].name, menu[i].price);
//             return;
//         }
//     }
//     printf("Item not found in the menu.\n");
// }


// int main() {
//     displayHeader();
//     Room rooms[100];
//     int roomCount = 0;
//     Customer customers[100];
//     int customerCount = 0;
//     Booking bookings[100];
//     int bookingCount = 0;
//     Manager manager;
//     Receptionist receptionist;

//     // Open the file in write mode
//     FILE *fp = fopen("login_info.txt", "w");
//     if (fp == NULL) {
//         printf("Error opening file\n");
//         return 1;
//     }

//     printf("Enter manager username: ");
//     scanf("%s", manager.username);
//     printf("Enter manager password: ");
//     scanf("%s", manager.password);

//     // Write the manager's username and password to the file
//     fprintf(fp, "Manager Username: %s\n", manager.username);
//     fprintf(fp, "Manager Password: %s\n", manager.password);

//     printf("Enter receptionist username: ");
//     scanf("%s", receptionist.username);
//     printf("Enter receptionist password: ");
//     scanf("%s", receptionist.password);

//     // Write the receptionist's username and password to the file
//     fprintf(fp, "Receptionist Username: %s\n", receptionist.username);
//     fprintf(fp, "Receptionist Password: %s\n", receptionist.password);

//     fclose(fp);

//     while (1) {
//         printf("+-----------------------+\n");
//         printf("|       Login Menu     |\n");
//         printf("+-----------------------+\n");
//         printf("| 1. Login as manager  |\n");
//         printf("| 2. Login as receptionist|\n");
//         printf("| 3. Exit              |\n");
//         printf("+-----------------------+\n");
//         int choice;
//         scanf("%d", &choice);

//         if (choice == 1) {
//             if(loginManager(manager)){
//                 while (1) {
//                 printf("+-----------------------+\n");
//                 printf("|      Manager Menu    |\n");
//                 printf("+-----------------------+\n");
//                 printf("| 1. Add room          |\n");
//                 printf("| 2. Display rooms     |\n");
//                 printf("| 3. Display customer status|\n");
//                 printf("| 4. Display booking status|\n");
//                 printf("| 5. Logout            |\n");
//                 printf("+-----------------------+\n");
//                 int choice2;
//                 scanf("%d", &choice2);

//                 if (choice2 == 1) {
//                     addRoom(rooms, &roomCount);
//                 } else if (choice2 == 2) {
//                     displayRooms(rooms, roomCount);
//                 } else if (choice2 == 3) {
//                     displayCustomerStatus(customers, customerCount);
//                 } else if (choice2 == 4) {
//                     displayBookingStatus(bookings, bookingCount);
//                 } else if (choice2 == 5) {
//                     break;
//                 } else {
//                     printf("Invalid choice\n");
//                 }
//             }
//             }
            
//         } else if (choice == 2) {
//             if(loginReceptionist(receptionist)){
//                 while (1) {
//                 printf("+-----------------------+\n");
//                 printf("|    Receptionist Menu |\n");
//                 printf("+-----------------------+\n");
//                 printf("| 1. Book room          |\n");
//                 printf("| 2. Cancel booking     |\n");
//                 printf("| 3. Display rooms      |\n");
//                 printf("| 4. Display customer status|\n");
//                 printf("| 5. Display booking status|\n");
//                 printf("| 6. Logout            |\n");
//                 printf("+-----------------------+\n");
//                 int choice2;
//                 scanf("%d", &choice2);

//                 if (choice2 == 1) {
//                     bookRoom(rooms, roomCount, customers, customerCount, bookings, &bookingCount);
//                     customerCount++;
//                 } else if (choice2 == 2) {
//                     cancelBooking(rooms, roomCount, bookings, bookingCount);
//                 } else if (choice2 == 3) {
//                     displayRooms(rooms, roomCount);
//                 } else if (choice2 == 4) {
//                     displayCustomerStatus(customers, customerCount);
//                 } else if (choice2 == 5) {
//                     displayBookingStatus(bookings, bookingCount);
//                 } else if (choice2 == 6) {
//                     break;
//                 } else {
//                     printf("Invalid choice\n");
//                 }
//             }
//             }
            
//         } else if (choice == 3) {
//             return 0;
//         } else {
//             printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }


// ------------------------- Update the code Add the Menu feture -------------------

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Structure to represent a hotel room
// typedef struct {
//     int roomNumber;
//     int capacity;
//     int price;
//     char status[10]; // "available" or "booked"
// } Room;

// // Structure to represent a customer
// typedef struct {
//     char name[50];
//     char email[50];
//     char phoneNumber[20];
//     int bookingCount;
// } Customer;

// // Structure to represent a booking
// typedef struct {
//     int bookingId;
//     int roomId;
//     int customerId;
//     char bookingDate[20];
//     char checkinDate[20];
//     char checkoutDate[20];
// } Booking;

// // Structure to represent a manager
// typedef struct {
//     char username[20];
//     char password[20];
// } Manager;

// // Structure to represent a receptionist
// typedef struct {
//     char username[20];
//     char password[20];
// } Receptionist;

// // Structure to represent a menu item
// typedef struct {
//     char name[50];
//     float price;
// } MenuItem;

// // Function to display the header
// void displayHeader() {
//     printf("\n");
//     printf("****************************************************\n");
//     printf("*                                                 *\n");
//     printf("*               Hotel Management System          *\n");
//     printf("*                                                 *\n");
//     printf("****************************************************\n");
//     printf("\n");
// }

// // Function to add a new room
// void addRoom(Room *rooms, int *roomCount) {
//     Room newRoom;
//     printf("Enter room number: ");
//     scanf("%d", &newRoom.roomNumber);
//     printf("Enter room capacity: ");
//     scanf("%d", &newRoom.capacity);
//     printf("Enter room price: ");
//     scanf("%d", &newRoom.price);
//     strcpy(newRoom.status, "available");
//     rooms[*roomCount] = newRoom;
//     (*roomCount)++;
// }

// // Function to book a room
// void bookRoom(Room *rooms, int roomCount, Customer *customers, int *customerCount, Booking *bookings, int *bookingCount) {
//     int roomId;
//     printf("Enter room number to book: ");
//     scanf("%d", &roomId);
//     for (int i = 0; i < roomCount; i++) {
//         if (rooms[i].roomNumber == roomId && strcmp(rooms[i].status, "available") == 0) {
//             printf("Enter customer name: ");
//             scanf("%s", customers[*customerCount].name);
//             printf("Enter customer email: ");
//             scanf("%s", customers[*customerCount].email);
//             printf("Enter customer phone number: ");
//             scanf("%s", customers[*customerCount].phoneNumber);
//             customers[*customerCount].bookingCount++;
//             Booking newBooking;
//             newBooking.bookingId = *bookingCount;
//             newBooking.roomId = roomId;
//             newBooking.customerId = *customerCount;
//             printf("Enter booking date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.bookingDate);
//             printf("Enter checkin date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkinDate);
//             printf("Enter checkout date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkoutDate);
//             bookings[*bookingCount] = newBooking;
//             (*bookingCount)++;
//             strcpy(rooms[i].status, "booked");
//             (*customerCount)++; // Increment customer count
//             return;
//         }
//     }
//     printf("Room not available\n");
// }

// // Function to cancel a booking
// void cancelBooking(Room *rooms, int roomCount, Booking *bookings, int bookingCount) {
//     int bookingId;
//     printf("Enter booking ID to cancel: ");
//     scanf("%d", &bookingId);
//     for (int i = 0; i < bookingCount; i++) {
//         if (bookings[i].bookingId == bookingId) {
//             for (int j = 0; j < roomCount; j++) {
//                 if (rooms[j].roomNumber == bookings[i].roomId) {
//                     strcpy(rooms[j].status, "available");
//                     break;
//                 }
//             }
//             printf("Booking cancelled\n");
//             return;
//         }
//     }
//     printf("Booking not found\n");
// }

// // Function to login as manager
// int loginManager(Manager manager) {
//     char username[20];
//     char password[20];
//     printf("Enter username : ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, manager.username) == 0 && strcmp(password, manager.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to display rooms
// void displayRooms(Room *rooms, int roomCount) {
//     printf("+---------+----------+----------+ --------+\n");
//     printf("| Room No | Capacity | Price    | Status  |\n");
//     printf("+---------+----------+----------+--------+\n");
//     for (int i = 0; i < roomCount; i++) {
//         printf("| %6d | %8d | %8d | %6s |\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].price, rooms[i].status);
//     }
//     printf("+---------+----------+----------+--------+\n");
// }

// // Function to display customer status
// void displayCustomerStatus(Customer *customers, int customerCount) {
//     printf("+---------+----------+----------+----------+\n");
//     printf("| Customer| Email    | Phone    | Bookings |\n");
//     printf("+---------+----------+----------+----------+\n");
//     for (int i = 0; i < customerCount; i++) {
//         printf("| %6s | %8s | %8s | %8d |\n", customers[i].name, customers[i].email, customers[i].phoneNumber, customers[i].bookingCount);
//     }
//     printf("+---------+----------+----------+----------+\n");
// }

// // Function to display booking status
// void displayBookingStatus(Booking *bookings, int bookingCount) {
//     printf("+---------+----------+----------+----------+----------+\n");
//     printf("| Booking | Room No | Customer | Booking  | Checkin  | Checkout|\n");
//     printf("+---------+----------+----------+----------+----------+\n");
//     for (int i = 0; i < bookingCount; i++) {
//         printf("| %6d | %6d | %8d | %8s | %8s | %8s |\n", bookings[i].bookingId, bookings[i].roomId, bookings[i].customerId, bookings[i].bookingDate, bookings[i].checkinDate, bookings[i].checkoutDate);
//     }
//     printf("+---------+----------+----------+----------+----------+\n");
// }

// // Function to login as receptionist
// int loginReceptionist(Receptionist receptionist) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, receptionist.username) == 0 && strcmp(password, receptionist.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to load menu items from a file
// void loadMenu(MenuItem *menu, int *menuCount) {
//     FILE *file = fopen("menu.txt", "r");
//     if (file == NULL) {
//         printf("Could not open menu file.\n");
//         return;
//     }
//     while (fscanf(file, "%49[^,],%f\n", menu[*menuCount].name, &menu[*menuCount].price) != EOF) {
//         (*menuCount)++;
//     }
//     fclose(file);
// }

// // Function to display the menu
// void displayMenu(MenuItem *menu, int menuCount) {
//     printf("+----------------------+----------+\n");
//     printf("| Item                 | Price    |\n");
//     printf("+----------------------+----------+\n");
//     for (int i = 0; i < menuCount; i++) {
//         printf("| %-20s | %.2f    |\n", menu[i].name, menu[i].price);
//     }
//     printf("+----------------------+----------+\n");
// }

// // Function to purchase an item
// void purchaseItem(MenuItem *menu, int menuCount) {
//     char itemName[50];
//     printf("Enter the name of the item to purchase: ");
//     scanf("%s", itemName);
//     for (int i = 0; i < menuCount; i++) {
//         if (strcmp(menu[i].name, itemName) == 0) {
//             printf("You have purchased %s for %.2f\n", menu[i].name, menu[i].price);
//             return;
//         }
//     }
//     printf("Item not found in the menu.\n");
// }

// int main() {
//     displayHeader();
//     Room rooms[100];
//     int roomCount = 0;
//     Customer customers[100];
//     int customerCount = 0;
//     Booking bookings[100];
//     int bookingCount = 0;
//     Manager manager;
//     Receptionist receptionist;
//     MenuItem menu[100];
//     int menuCount = 0;

//     // Load menu items from file
//     loadMenu(menu, &menuCount);

//     // Open the file in write mode for login info
//     FILE *fp = fopen("login_info.txt", "w");
//     if (fp == NULL) {
//         printf("Error opening file\n");
//         return 1;
//     }

//     printf("Enter manager username: ");
//     scanf("%s", manager.username);
//     printf("Enter manager password: ");
//     scanf("%s", manager.password);

//     // Write the manager's username and password to the file
//     fprintf(fp, "Manager Username: %s\n", manager.username);
//     fprintf(fp, "Manager Password: %s\n", manager.password);

//     printf("Enter receptionist username: ");
//     scanf("%s", receptionist.username);
//     printf("Enter receptionist password: ");
//     scanf("%s", receptionist.password);

//     // Write the receptionist's username and password to the file
//     fprintf(fp, "Receptionist Username: %s\n", receptionist.username);
//     fprintf(fp, "Receptionist Password: %s\n", receptionist.password);

//     fclose(fp);

//     while (1) {
//         printf("+-----------------------+\n");
//         printf("|       Login Menu     |\n");
//         printf("+-----------------------+\n");
//         printf("| 1. Login as manager  |\n");
//         printf("| 2. Login as receptionist|\n");
//         printf("| 3. Exit              |\n");
//         printf("+-----------------------+\n");
//         int choice;
//         scanf("%d", &choice);

//         if (choice == 1) {
//             if (loginManager(manager)) {
//                 while (1) {
//                     printf("+-----------------------+\n");
//                     printf("|      Manager Menu    |\n");
//                     printf("+-----------------------+\n");
//                     printf("| 1. Add room          |\n");
//                     printf("| 2. Display rooms     |\n");
//                     printf("| 3. Display customer status|\n");
//                     printf("| 4. Display booking status|\n");
//                     printf("| 5. Logout            |\n");
//                     printf("+-----------------------+\n");
//                     int choice2;
//                     scanf("%d", &choice2);

//                     if (choice2 == 1) {
//                         addRoom(rooms, &roomCount);
//                     } else if (choice2 == 2) {
//                         displayRooms(rooms, roomCount);
//                     } else if (choice2 == 3) {
//                         displayCustomerStatus(customers, customerCount);
//                     } else if (choice2 == 4) {
//                         displayBookingStatus(bookings, bookingCount);
//                     } else if (choice2 == 5) {
//                         break;
//                     } else {
//                         printf("Invalid choice\n");
//                     }
//                 }
//             }
//         } else if (choice == 2) {
//             if (loginReceptionist(receptionist)) {
//                 while (1) {
//                     printf("+-----------------------+\n");
//                     printf("|    Receptionist Menu  |\n");
//                     printf("+-----------------------+\n");
//                     printf("| 1. Book room          |\n");
//                     printf("| 2. Cancel booking     |\n");
//                     printf("| 3. Display rooms      |\n");
//                     printf("| 4. Display customer status|\n");
//                     printf("| 5. Display booking status|\n");
//                     printf("| 6. Display menu       |\n");
//                     printf("| 7. Purchase item      |\n");
//                     printf("| 8. Logout             |\n");
//                     printf("+-----------------------+\n");
//                     int choice2;
//                     scanf("%d", &choice2);

//                     if (choice2 == 1) {
//                         bookRoom(rooms, roomCount, customers, &customerCount, bookings, &bookingCount);
//                     } else if (choice2 == 2) {
//                         cancelBooking(rooms, roomCount, bookings, bookingCount);
//                     } else if (choice2 == 3) {
//                         displayRooms(rooms, roomCount);
//                     } else if (choice2 == 4) {
//                         displayCustomerStatus(customers, customerCount);
//                     } else if (choice2 == 5) {
//                         displayBookingStatus(bookings, bookingCount);
//                     } else if (choice2 == 6) {
//                         displayMenu(menu, menuCount);
//                     } else if (choice2 == 7) {
//                         purchaseItem(menu, menuCount);
//                     } else if (choice2 == 8) {
//                         break;
//                     } else {
//                         printf("Invalid choice\n");
//                     }
//                 }
//             }
//         } else if (choice == 3) {
//             return 0;
//         } else {
//             printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }



// ---------------------------- Update the code add the Bill feture ---------------------------
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Structure to represent a hotel room
// typedef struct {
//     int roomNumber;
//     int capacity;
//     int price;
//     char status[10]; // "available" or "booked"
// } Room;

// // Structure to represent a customer
// typedef struct {
//     char name[50];
//     char email[50];
//     char phoneNumber[20];
//     int bookingCount;
// } Customer;

// // Structure to represent a booking
// typedef struct {
//     int bookingId;
//     int roomId;
//     int customerId;
//     char bookingDate[20];
//     char checkinDate[20];
//     char checkoutDate[20];
// } Booking;

// // Structure to represent a manager
// typedef struct {
//     char username[20];
//     char password[20];
// } Manager;

// // Structure to represent a receptionist
// typedef struct {
//     char username[20];
//     char password[20];
// } Receptionist;

// // Structure to represent a menu item
// typedef struct {
//     char name[50];
//     float price;
// } MenuItem;

// // Structure to represent a bill
// typedef struct {
//     int bookingId;
//     float roomPrice;
//     float menuTotal;
//     float totalAmount;
// } Bill;

// // Function to display the header
// void displayHeader() {
//     printf("\n");
//     printf("****************************************************\n");
//     printf("*                                                 *\n");
//     printf("*               Hotel Management System          *\n");
//     printf("*                                                 *\n");
//     printf("****************************************************\n");
//     printf("\n");
// }

// // Function to add a new room
// void addRoom(Room *rooms, int *roomCount) {
//     Room newRoom;
//     printf("Enter room number: ");
//     scanf("%d", &newRoom.roomNumber);
//     printf("Enter room capacity: ");
//     scanf("%d", &newRoom.capacity);
//     printf("Enter room price: ");
//     scanf("%d", &newRoom.price);
//     strcpy(newRoom.status, "available");
//     rooms[*roomCount] = newRoom;
//     (*roomCount)++;
// }

// // Function to book a room
// void bookRoom(Room *rooms, int roomCount, Customer *customers, int *customerCount, Booking *bookings, int *bookingCount, Bill *bills, int *billCount, MenuItem *menu, int menuCount) {
//     int roomId;
//     printf("Enter room number to book: ");
//     scanf("%d", &roomId);
//     for (int i = 0; i < roomCount; i++) {
//         if (rooms[i].roomNumber == roomId && strcmp(rooms[i].status, "available") == 0) {
//             // Collect customer details
//             printf("Enter customer name: ");
//             scanf("%s", customers[*customerCount].name);
//             printf("Enter customer email: ");
//             scanf("%s", customers[*customerCount].email);
//             printf("Enter customer phone number: ");
//             scanf("%s", customers[*customerCount].phoneNumber);
//             customers[*customerCount].bookingCount++;

//             // Create a new booking
//             Booking newBooking;
//             newBooking.bookingId = *bookingCount;
//             newBooking.roomId = roomId;
//             newBooking.customerId = *customerCount;
//             printf("Enter booking date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.bookingDate);
//             printf("Enter checkin date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkinDate);
//             printf("Enter checkout date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkoutDate);
//             bookings[*bookingCount] = newBooking;
//             (*bookingCount)++;
//             strcpy(rooms[i].status, "booked");
//             (*customerCount)++; // Increment customer count

//             // Bill generation
//             Bill newBill;
//             newBill.bookingId = newBooking.bookingId;
//             newBill.roomPrice = rooms[i].price;
//             newBill.menuTotal = 0.0;

//             // Menu item selection
//             char addMore;
//             do {
//                 char itemName[50];
//                 printf("Enter the name of the menu item to add to the bill: ");
//                 scanf("%s", itemName);
//                 int found = 0;
//                 for (int j = 0; j < menuCount; j++) {
//  if (strcmp(menu[j].name, itemName) == 0) {
//                         newBill.menuTotal += menu[j].price;
//                         printf("Added %s to the bill for %.2f\n", menu[j].name, menu[j].price);
//                         found = 1;
//                         break;
//                     }
//                 }
//                 if (!found) {
//                     printf("Menu item not found.\n");
//                 }
//                 printf("Do you want to add another item? (y/n): ");
//                 scanf(" %c", &addMore);
//             } while (addMore == 'y');

//             newBill.totalAmount = newBill.roomPrice + newBill.menuTotal;
//             bills[*billCount] = newBill;
//             (*billCount)++;

//             printf("Room booked successfully!\n");
//             printf("Total bill amount: %.2f\n", newBill.totalAmount);
//             return;
//         }
//     }
//     printf("Room not available\n");
// }

// // Function to cancel a booking
// void cancelBooking(Room *rooms, int roomCount, Booking *bookings, int bookingCount) {
//     int bookingId;
//     printf("Enter booking ID to cancel: ");
//     scanf("%d", &bookingId);
//     for (int i = 0; i < bookingCount; i++) {
//         if (bookings[i].bookingId == bookingId) {
//             for (int j = 0; j < roomCount; j++) {
//                 if (rooms[j].roomNumber == bookings[i].roomId) {
//                     strcpy(rooms[j].status, "available");
//                     break;
//                 }
//             }
//             printf("Booking cancelled\n");
//             return;
//         }
//     }
//     printf("Booking not found\n");
// }

// // Function to login as manager
// int loginManager(Manager manager) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, manager.username) == 0 && strcmp(password, manager.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to display rooms
// void displayRooms(Room *rooms, int roomCount) {
//     printf("+---------+----------+----------+ --------+\n");
//     printf("| Room No | Capacity | Price    | Status  |\n");
//     printf("+---------+----------+----------+--------+\n");
//     for (int i = 0; i < roomCount; i++) {
//         printf("| %6d | %8d | %8d | %6s |\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].price, rooms[i].status);
//     }
//     printf("+---------+----------+----------+--------+\n");
// }

// // Function to display customer status
// void displayCustomerStatus(Customer *customers, int customerCount) {
//     printf("+---------+----------+----------+----------+\n");
//     printf("| Customer| Email    | Phone    | Bookings |\n");
//     printf("+---------+----------+----------+----------+\n");
//     for (int i = 0; i < customerCount; i++) {
//         printf("| %6s | %8s | %8s | %8d |\n", customers[i].name, customers[i].email, customers[i].phoneNumber, customers[i].bookingCount);
//     }
//     printf("+---------+----------+----------+----------+\n");
// }

// // Function to display booking status
// void displayBookingStatus(Booking *bookings, int bookingCount) {
//     printf("+---------+----------+----------+----------+----------+\n");
//     printf("| Booking | Room No | Customer | Booking  | Checkin  | Checkout|\n");
//     printf("+---------+----------+----------+----------+----------+\n");
//     for (int i = 0; i < bookingCount; i++) {
//         printf("| %6d | %6d | %8d | %8s | %8s | %8s |\n", bookings[i].bookingId, bookings[i].roomId, bookings[i].customerId, bookings[i].bookingDate, bookings[i].checkinDate, bookings[i].checkoutDate);
//     }
//     printf("+---------+----------+----------+----------+----------+\n");
// }

// // Function to login as receptionist
// int loginReceptionist(Receptionist receptionist) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, receptionist.username) == 0 && strcmp(password, receptionist.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to load menu items from a file
// void loadMenu(MenuItem *menu, int *menuCount) {
//     FILE *file = fopen("menu.txt", "r");
//     if (file == NULL) {
//         printf("Could not open menu file.\n");
//         return;
//     }
//     while (fscanf(file, "%49[^,],%f\n", menu[*menuCount].name, &menu[*menuCount].price) != EOF) {
//         (*menuCount)++;
//     }
//     fclose(file);
// }

// // Function to display the menu
// void displayMenu(MenuItem *menu, int menuCount) {
//     printf("+----------------------+----------+\n");
//     printf("| Item                 | Price    |\n");
//     printf("+----------------------+----------+\n");
//     for (int i = 0; i < menuCount; i++) {
//         printf("| %-20s | %.2f    |\n", menu[i].name, menu[i].price);
//     }
//     printf("+----------------------+----------+\n");
// }

// // Function to display the bill
// void displayBill(Bill *bills, int billCount) {
//     printf("+---------+----------+----------+----------+\n");
//     printf("| Booking | Room Price | Menu Total | Total   |\n");
//     printf("+---------+----------+----------+----------+\n");
//     for (int i = 0; i < billCount; i++) {
//         printf("| %6d | %.2f    | %.2f      | %.2f    |\n", bills[i].bookingId, bills[i].roomPrice, bills[i].menuTotal, bills[i].totalAmount);
//     }
//     printf("+---------+----------+----------+----------+\n");
// }

// // Function to purchase an item
// void purchaseItem(MenuItem *menu, int menuCount) {
//     char itemName[50];
//     printf("Enter the name of the item to purchase: ");
//     scanf("%s", itemName);
//     for (int i = 0; i < menuCount; i++) {
//         if (strcmp(menu[i].name, itemName) == 0) {
//             printf("You have purchased %s for %.2f\n", menu[i].name, menu[i].price);
//             return;
//         }
//     }
//     printf("Item not found in the menu.\n");
// }

// int main() {
//     displayHeader();
//     Room rooms[100];
//     int roomCount = 0;
//     Customer customers[100];
//     int customerCount = 0;
//     Booking bookings[100];
//     int bookingCount = 0;
//     Bill bills[100];
//     int billCount = 0;
//     Manager manager;
//     Receptionist receptionist;
//     MenuItem menu[100];
//     int menuCount = 0;

//     // Load menu items from file
//     loadMenu(menu, &menuCount);

//     // Open the file in write mode for login info
//     FILE *fp = fopen("login_info.txt", "w");
//     if (fp == NULL) {
//         printf("Error opening file\n");
//         return 1;
//     }

//     printf("Enter manager username: ");
//     scanf("%s", manager.username);
//     printf("Enter manager password: ");
//     scanf("%s", manager.password);

//     // Write the manager's username and password to the file
//     fprintf(fp, "Manager Username: %s\n", manager.username);
//     fprintf(fp, "Manager Password: %s\n", manager.password);

//     printf("Enter receptionist username: ");
//     scanf("%s", receptionist.username);
//     printf("Enter receptionist password: ");
//     scanf("%s", receptionist.password);

//     // Write the receptionist's username and password to the file
//     fprintf(fp, "Receptionist Username: %s\n", receptionist.username);
//     fprintf(fp, "Receptionist Password: %s\n", receptionist.password);

//     fclose(fp);

//     while (1) {
//         printf("+-----------------------+\n");
//         printf("|       Login Menu     |\n");
//         printf("+-----------------------+\n");
//         printf("| 1. Login as manager  |\n");
//         printf("| 2. Login as receptionist|\n");
//         printf("| 3. Exit              |\n");
//         printf("+-----------------------+\n");
//         int choice;
//         scanf("%d", &choice);

//         if (choice == 1) {
//             if (loginManager(manager)) {
//                 while (1) {
//                     printf("+-----------------------+\n");
//                     printf("|      Manager Menu    |\n");
//                     printf("+-----------------------+\n");
//                     printf("| 1. Add room          |\n");
//                     printf("| 2. Display rooms     |\n");
//                     printf("| 3. Display customer status|\n");
//                     printf("| 4. Display booking status|\n");
//                     printf("| 5. Display bills     |\n");
//                     printf("| 6. Logout            |\n");
//                     printf("+-----------------------+\n");
//                     int choice2;
//                     scanf("%d", &choice2);

//                     if (choice2 == 1) {
//                         addRoom(rooms, &roomCount);
//                     } else if (choice2 == 2) {
//                         displayRooms(rooms, roomCount);
//                     } else if (choice2 == 3) {
//                         displayCustomerStatus(customers, customerCount);
//                     } else if (choice2 == 4) {
//                         displayBookingStatus(bookings, bookingCount);
//                     } else if (choice2 == 5) {
//                         displayBill(bills, billCount);
//                     } else if (choice2 == 6) {
//                         break;
//                     } else {
//                         printf("Invalid choice\n");
//                     }
//                 }
//             }
//         } else if (choice == 2) {
//             if (loginReceptionist(receptionist)) {
//                 while (1) {
//                     printf("+-----------------------+\n");
//                     printf("|    Receptionist Menu  |\n");
//                     printf("+-----------------------+\n");
//                     printf("| 1. Book room          |\n");
//                     printf("| 2. Cancel booking     |\n");
//                     printf("| 3. Display rooms      |\n");
//                     printf("| 4. Display customer status|\n");
//                     printf("| 5. Display booking status|\n");
//                     printf("| 6. Display menu       |\n");
//                     printf("| 7. Purchase item      |\n");
//                     printf("| 8. Logout             |\n");
//                     printf("+-----------------------+\n");
//                     int choice2;
//                     scanf("%d", &choice2);

//                     if (choice2 == 1) {
//                         bookRoom(rooms, roomCount, customers, &customerCount, bookings, &bookingCount, bills, &billCount, menu, menuCount);
//                     } else if (choice2 == 2) {
//                         cancelBooking(rooms, roomCount, bookings, bookingCount);
//                     } else if (choice2 == 3) {
//                         displayRooms(rooms, roomCount);
//                     } else if (choice2 == 4) {
//                         displayCustomerStatus(customers, customerCount);
//                     } else if (choice2 == 5) {
//                         displayBookingStatus(bookings, bookingCount);
//                     } else if (choice2 == 6) {
//                         displayMenu(menu, menuCount);
//                     } else if (choice2 == 7) {
//                         purchaseItem(menu, menuCount);
//                     } else if (choice2 == 8) {
//                         break;
//                     } else {
//                         printf("Invalid choice\n");
//                     }
//                 }
//             }
//         } else if (choice == 3) {
//             return 0;
//         } else {
//             printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }





// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Structure to represent a hotel room
// typedef struct {
//     int roomNumber;
//     int capacity;
//     int price;
//     char status[10]; // "available" or "booked"
// } Room;

// // Structure to represent a customer
// typedef struct {
//     char name[50];
//     char email[50];
//     char phoneNumber[20];
//     int bookingCount;
// } Customer;

// // Structure to represent a booking
// typedef struct {
//     int bookingId;
//     int roomId;
//     int customerId;
//     char bookingDate[20];
//     char checkinDate[20];
//     char checkoutDate[20];
// } Booking;

// // Structure to represent a manager
// typedef struct {
//     char username[20];
//     char password[20];
// } Manager;

// // Structure to represent a receptionist
// typedef struct {
//     char username[20];
//     char password[20];
// } Receptionist;

// // Structure to represent a menu item
// typedef struct {
//     char name[50];
//     float price;
// } MenuItem;

// // Structure to represent a bill
// typedef struct {
//     int bookingId;
//     float roomPrice;
//     float menuTotal;
//     float totalAmount;
// } Bill;

// // Function to display the header
// void displayHeader() {
//     printf("\n");
//     printf("****************************************************\n");
//     printf("*                                                 *\n");
//     printf("*               Hotel Management System          *\n");
//     printf("*                                                 *\n");
//     printf("****************************************************\n");
//     printf("\n");
// }

// // Function to add a new room
// void addRoom(Room *rooms, int *roomCount) {
//     Room newRoom;
//     printf("Enter room number: ");
//     scanf("%d", &newRoom.roomNumber);
//     printf("Enter room capacity: ");
//     scanf("%d", &newRoom.capacity);
//     printf("Enter room price: ");
//     scanf("%d", &newRoom.price);
//     strcpy(newRoom.status, "available");
//     rooms[*roomCount] = newRoom;
//     (*roomCount)++;
// }

// // Function to book a room
// void bookRoom(Room *rooms, int roomCount, Customer *customers, int *customerCount, Booking *bookings, int *bookingCount, Bill *bills, int *billCount, MenuItem *menu, int menuCount) {
//     int roomId;
//     printf("Enter room number to book: ");
//     scanf("%d", &roomId);
//     for (int i = 0; i < roomCount; i++) {
//         if (rooms[i].roomNumber == roomId && strcmp(rooms[i].status, "available") == 0) {
//             // Collect customer details
//             printf("Enter customer name: ");
//             scanf("%s", customers[*customerCount].name);
//             printf("Enter customer email: ");
//             scanf("%s", customers[*customerCount].email);
//             printf("Enter customer phone number: ");
//             scanf("%s", customers[*customerCount].phoneNumber);
//             customers[*customerCount].bookingCount++;

//             // Create a new booking
//             Booking newBooking;
//             newBooking.bookingId = *bookingCount;
//             newBooking.roomId = roomId;
//             newBooking.customerId = *customerCount;
//             printf("Enter booking date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.bookingDate);
//             printf("Enter checkin date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkinDate);
//             printf("Enter checkout date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkoutDate);
//             bookings[*bookingCount] = newBooking;
//             (*bookingCount)++;
//             strcpy(rooms[i].status, "booked");
//             (*customerCount)++; // Increment customer count

//             // Bill generation
//             Bill newBill;
//             newBill.bookingId = newBooking.bookingId;
//             newBill.roomPrice = rooms[i].price;
//             newBill.menuTotal = 0.0;

//             // Menu item selection
//             char addMore;
//             do {
//                 char itemName[50];
//                 printf("Enter the name of the menu item to add to the bill: ");
//                 scanf("%s", itemName);
//                 int found = 0;
//                 for (int j = 0; j < menuCount; j++) {
//                     if (strcmp(menu[j].name, itemName) == 0) {
//                         newBill.menuTotal += menu[j].price;
//                         printf("Added %s to the bill for %.2f\n", menu[j].name, menu[j].price);
//                         found = 1;
//                         break;
//                     }
//                 }
//                 if (!found) {
//                     printf("Menu item not found.\n");
//                 }
//                 printf("Do you want to add another item? (y/n): ");
//                 scanf(" %c", &addMore);
//             } while (addMore == 'y');

//             newBill.totalAmount = newBill.roomPrice + newBill.menuTotal;
//             bills[*billCount] = newBill;
//             (*billCount)++;

//             printf("Room booked successfully!\n");
//             printf("Total bill amount: %.2f\n", newBill.totalAmount);
//             return;
//         }
//     }
//     printf("Room not available\n");
// }

// // Function to cancel a booking
// void cancelBooking(Room *rooms, int roomCount, Booking *bookings, int bookingCount) {
//     int bookingId;
//     printf("Enter booking ID to cancel: ");
//     scanf("%d", &bookingId);
//     for (int i = 0; i < bookingCount; i++) {
//         if (bookings[i].bookingId == bookingId) {
//             for (int j = 0; j < roomCount; j++) {
//                 if (rooms[j].roomNumber == bookings[i].roomId) {
//                     strcpy(rooms[j].status, "available");
//                     break;
//                 }
//             }
//             printf("Booking cancelled\n");
//             return;
//         }
//     }
//     printf("Booking not found\n");
// }

// // Function to login as manager
// int loginManager(Manager manager) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, manager.username) == 0 && strcmp(password, manager.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to display rooms
// void displayRooms(Room *rooms, int roomCount) {
//     printf("+---------+----------+----------+ --------+\n");
//     printf("| Room No | Capacity | Price    | Status  |\n");
//     printf("+---------+----------+----------+--------+\n");
//     for (int i = 0; i < roomCount; i++) {
//         printf("| %6d | %8d | %8d | %6s |\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].price, rooms[i].status);
//     }
//     printf("+---------+----------+----------+--------+\n");
// }

// // Function to display customer status
// void displayCustomerStatus(Customer *customers, int customerCount) {
//     printf("+---------+----------+----------+----------+\n");
//     printf("| Customer| Email    | Phone    | Bookings |\n");
//     printf("+---------+----------+----------+----------+\n");
//     for (int i = 0; i < customerCount; i++) {
//         printf("| %6s | %8s | %8s | %8d |\n", customers[i].name, customers[i].email, customers[i].phoneNumber, customers[i].bookingCount);
//     }
//     printf("+---------+----------+----------+----------+\n");
// }

// // Function to display booking status
// void displayBookingStatus(Booking *bookings, int bookingCount) {
//     printf("+---------+----------+----------+----------+----------+\n");
//     printf("| Booking | Room No | Customer | Booking  | Checkin  | Checkout|\n");
//     printf("+---------+----------+----------+----------+----------+\n");
//     for (int i = 0; i < bookingCount; i++) {
//         printf("| %6d | %6d | %8d | %8s | %8s | %8s |\n", bookings[i].bookingId, bookings[i].roomId, bookings[i].customerId, bookings[i].bookingDate, bookings[i].checkinDate, bookings[i].checkoutDate);
//     }
//     printf("+---------+----------+----------+----------+----------+\n");
// }

// // Function to login as receptionist
// int loginReceptionist(Receptionist receptionist) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, receptionist.username) == 0 && strcmp(password, receptionist.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to load menu items from a file
// void loadMenu(MenuItem *menu, int *menuCount) {
//     FILE *file = fopen("menu.txt", "r");
//     if (file == NULL) {
//         printf("Could not open menu file.\n");
//         return;
//     }
//     while (fscanf(file, "%49[^,],%f\n", menu[*menuCount].name, &menu[*menuCount].price) != EOF) {
//         (*menuCount)++;
//     }
//     fclose(file);
// }

// // ```c
// // Function to load login information from a file
// void loadLoginInfo(Manager *manager, Receptionist *receptionist) {
//     FILE *file = fopen("login_info.txt", "r");
//     if (file == NULL) {
//         return; // File does not exist, return without loading
//     }
//     fscanf(file, "Manager Username: %s\n", manager->username);
//     fscanf(file, "Manager Password: %s\n", manager->password);
//     fscanf(file, "Receptionist Username: %s\n", receptionist->username);
//     fscanf(file, "Receptionist Password: %s\n", receptionist->password);
//     fclose(file);
// }

// // Function to save login information to a file
// void saveLoginInfo(Manager manager, Receptionist receptionist) {
//     FILE *file = fopen("login_info.txt", "w");
//     if (file == NULL) {
//         printf("Error opening file\n");
//         return;
//     }
//     fprintf(file, "Manager Username: %s\n", manager.username);
//     fprintf(file, "Manager Password: %s\n", manager.password);
//     fprintf(file, "Receptionist Username: %s\n", receptionist.username);
//     fprintf(file, "Receptionist Password: %s\n", receptionist.password);
//     fclose(file);
// }

// // Function to display the menu
// void displayMenu(MenuItem *menu, int menuCount) {
//     printf("+----------------------+----------+\n");
//     printf("| Item                 | Price    |\n");
//     printf("+----------------------+----------+\n");
//     for (int i = 0; i < menuCount; i++) {
//         printf("| %-20s | %.2f    |\n", menu[i].name, menu[i].price);
//     }
//     printf("+----------------------+----------+\n");
// }

// // Function to display the bill
// void displayBill(Bill *bills, int billCount) {
//     printf("+---------+----------+----------+----------+\n");
//     printf("| Booking | Room Price | Menu Total | Total   |\n");
//     printf("+---------+----------+----------+----------+\n");
//     for (int i = 0; i < billCount; i++) {
//         printf("| %6d | %.2f    | %.2f      | %.2f    |\n", bills[i].bookingId, bills[i].roomPrice, bills[i].menuTotal, bills[i].totalAmount);
//     }
//     printf("+---------+----------+----------+----------+\n");
// }

// // Function to purchase an item
// void purchaseItem(MenuItem *menu, int menuCount) {
//     char itemName[50];
//     printf("Enter the name of the item to purchase: ");
//     scanf("%s", itemName);
//     for (int i = 0; i < menuCount; i++) {
//         if (strcmp(menu[i].name, itemName) == 0) {
//             printf("You have purchased %s for %.2f\n", menu[i].name, menu[i].price);
//             return;
//         }
//     }
//     printf("Item not found in the menu.\n");
// }

// int main() {
//     displayHeader();
//     Room rooms[100];
//     int roomCount = 0;
//     Customer customers[100];
//     int customerCount = 0;
//     Booking bookings[100];
//     int bookingCount = 0;
//     Bill bills[100];
//     int billCount = 0;
//     Manager manager = {"", ""};
//     Receptionist receptionist = {"", ""};
//     MenuItem menu[100];
//     int menuCount = 0;

//     // Load menu items from file
//     loadMenu(menu, &menuCount);

//     // Load login information from file
//     loadLoginInfo(&manager, &receptionist);

//     // Check if login info exists
//     if (strlen(manager.username) == 0 || strlen(receptionist.username) == 0) {
//         // Register manager and receptionist if not already registered
//         printf("Enter manager username: ");
//         scanf("%s", manager.username);
//         printf("Enter manager password: ");
//         scanf("%s", manager.password);

//         printf("Enter receptionist username: ");
//         scanf("%s", receptionist.username);
//         printf("Enter receptionist password: ");
//         scanf("%s", receptionist.password);

//         // Save the login information to the file
//         saveLoginInfo(manager, receptionist);
//     }

//     while (1) {
//         printf("+-----------------------+\n");
//         printf("|       Login Menu     |\n");
//         printf("+-----------------------+\n");
//         printf("| 1. Login as manager  |\n");
//         printf("| 2. Login as receptionist|\n");
//         printf("| 3. Exit              |\n");
//         printf("+-----------------------+\n");
//         int choice;
//         scanf("%d", &choice);

//         if (choice == 1) {
//             if (loginManager(manager)) {
//                 while (1) {
//                     printf("+-----------------------+\n");
//                     printf("|      Manager Menu    |\n");
//                     printf("+-----------------------+\n");
//                     printf("| 1. Add room          |\n");
//                     printf("| 2. Display rooms     |\n");
//                     printf("| 3. Display customer status|\n");
//                     printf("| 4. Display booking status|\n");
//                     printf("| 5. Display bills     |\n");
//                     printf("| 6. Logout            |\n");
//                     printf("+-----------------------+\n");
//                     int choice2;
//                     scanf("%d", &choice2);

//                     if (choice2 == 1) {
//                         addRoom(rooms, &roomCount);
//                     } else if (choice2 == 2) {
//                         displayRooms(rooms, roomCount);
//                     } else if (choice2 == 3) {
//                         displayCustomerStatus(customers, customerCount);
//                     } else if (choice2 == 4) {
//                         displayBookingStatus(bookings, bookingCount);
//                     } else if (choice2 == 5) {
//                         displayBill(bills, billCount);
//                     } else if (choice2 == 6) {
//                         break;
//                     } else {
//                         printf("Invalid choice\n");
//                     }
//                 }
//             }
//         } else if (choice == 2) {
//             if (loginReceptionist(receptionist)) {
//                 while (1) {
//                     printf("+-----------------------+\n");
//                     printf("|    Receptionist Menu  |\n");
//                     printf("+-----------------------+\n");
//                     printf("| 1. Book room          |\n");
//                     printf("| 2. Cancel booking     |\n");
//                     printf("| 3. Display rooms      |\n");
//                     printf("| 4. Display customer status|\n");
//                     printf("| 5. Display booking status|\n");
//                     printf("| 6. Display menu       |\n");
//                     printf("| 7. Purchase item      |\n");
//                     printf("| 8. Logout             |\n");
//                     printf("+-----------------------+\n");
//                     int choice2;
//                     scanf("%d", &choice2);

//                     if (choice2 == 1) {
//                         bookRoom(rooms, roomCount, customers, &customerCount, bookings, &bookingCount, bills, &billCount, menu, menuCount);
//                     } else if (choice2 == 2) {
//                         cancelBooking(rooms, roomCount, bookings, bookingCount);
//                     } else if (choice2 == 3) {
//                         displayRooms(rooms, roomCount);
//                     } else if (choice2 == 4) {
//                         displayCustomerStatus(customers, customerCount);
//                     } else if (choice2 == 5) {
//                         displayBookingStatus(bookings, bookingCount);
//                     } else if (choice2 == 6) {
//                         displayMenu(menu, menuCount);
//                     } else if (choice2 == 7) {
//                         purchaseItem(menu, menuCount);
//                     } else if (choice2 == 8) {
//                         break;
//                     } else {
//                         printf("Invalid choice\n");
//                     }
//                 }
//             }
//         } else if (choice == 3) {
//             return 0;
//         } else {
//             printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }




// ----- Final Code before User Add -----

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Structure to represent a hotel room
// typedef struct {
//     int roomNumber;
//     int capacity;
//     int price;
//     char status[10]; // "available" or "booked"
// } Room;

// // Structure to represent a customer
// typedef struct {
//     char name[50];
//     char email[50];
//     char phoneNumber[20];
//     int bookingCount;
// } Customer;

// // Structure to represent a booking
// typedef struct {
//     int bookingId;
//     int roomId;
//     int customerId;
//     char bookingDate[20];
//     char checkinDate[20];
//     char checkoutDate[20];
// } Booking;

// // Structure to represent a manager
// typedef struct {
//     char username[20];
//     char password[20];
// } Manager;

// // Structure to represent a receptionist
// typedef struct {
//     char username[20];
//     char password[20];
// } Receptionist;

// // Structure to represent a menu item
// typedef struct {
//     char name[50];
//     float price;
// } MenuItem;

// // Structure to represent a bill
// typedef struct {
//     int bookingId;
//     float roomPrice;
//     float menuTotal;
//     float totalAmount;
// } Bill;

// // Function to display the header
// void displayHeader() {
//     printf("\n");
//     printf("****************************************************\n");
//     printf("*                                                 *\n");
//     printf("*               Hotel Management System          *\n");
//     printf("*                                                 *\n");
//     printf("****************************************************\n");
//     printf("\n");
// }

// // Function to add a new room
// void addRoom(Room *rooms, int *roomCount) {
//     Room newRoom;
//     printf("Enter room number: ");
//     scanf("%d", &newRoom.roomNumber);
//     printf("Enter room capacity: ");
//     scanf("%d", &newRoom.capacity);
//     printf("Enter room price: ");
//     scanf("%d", &newRoom.price);
//     strcpy(newRoom.status, "available");
//     rooms[*roomCount] = newRoom;
//     (*roomCount)++;
// }

// // Function to book a room
// void bookRoom(Room *rooms, int roomCount, Customer *customers, int *customerCount, Booking *bookings, int *bookingCount, Bill *bills, int *billCount) {
//     int roomId;
//     printf("Enter room number to book: ");
//     scanf("%d", &roomId);
//     for (int i = 0; i < roomCount; i++) {
//         if (rooms[i].roomNumber == roomId && strcmp(rooms[i].status, "available") == 0) {
//             // Collect customer details
//             printf("Enter customer name: ");
//             scanf("%s", customers[*customerCount].name);
//             printf("Enter customer email: ");
//             scanf("%s", customers[*customerCount].email);
//             printf("Enter customer phone number: ");
//             scanf("%s", customers[*customerCount].phoneNumber);
//             customers[*customerCount].bookingCount++;

//             // Create a new booking
//             Booking newBooking;
//             newBooking.bookingId = *bookingCount;
//             newBooking.roomId = roomId;
//             newBooking.customerId = *customerCount;
//             printf("Enter booking date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.bookingDate);
//             printf("Enter checkin date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkinDate);
//             printf("Enter checkout date (YYYY-MM-DD): ");
//             scanf("%s", newBooking.checkoutDate);
//             bookings[*bookingCount] = newBooking;
//             (*bookingCount)++;
//             strcpy(rooms[i].status, "booked");
//             (*customerCount)++; // Increment customer count

//             // Bill generation
//             Bill newBill;
//             newBill.bookingId = newBooking.bookingId;
//             newBill.roomPrice = rooms[i].price;
//             newBill.menuTotal = 0.0;
//             bills[*billCount] = newBill; // Store the bill for this booking
//             (*billCount)++;

//             printf("Room booked successfully!\n");
//             printf("Total room price: %.2f\n", newBill.roomPrice);
//             return;
//         }
//     }
//     printf("Room not available\n");
// }

// // Function to cancel a booking
// void cancelBooking(Room *rooms, int roomCount, Booking *bookings, int bookingCount) {
//     int bookingId;
//     printf("Enter booking ID to cancel: ");
//     scanf("%d", &bookingId);
//     for (int i = 0; i < bookingCount; i++) {
//         if (bookings[i].bookingId == bookingId) {
//             for (int j = 0; j < roomCount; j++) {
//                 if (rooms[j].roomNumber == bookings[i].roomId) {
//                     strcpy(rooms[j].status, "available");
//                     break;
//                 }
//             }
//             printf("Booking cancelled\n");
//             return;
//         }
//     }
//     printf("Booking not found\n");
// }

// // Function to login as manager
// int loginManager(Manager manager) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, manager.username) == 0 && strcmp(password, manager.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to display rooms
// void displayRooms(Room *rooms, int roomCount) {
//     printf("+---------+----------+----------+ --------+\n");
//     printf("| Room No | Capacity | Price    | Status  |\n");
//     printf("+---------+----------+----------+--------+\n");
//     for (int i = 0; i < roomCount; i++) {
//         printf("| %6d | %8d | %8d | %6s |\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].price, rooms[i].status);
//     }
//     printf("+---------+----------+----------+--------+\n");
// }

// // Function to display customer status
// void displayCustomerStatus(Customer *customers, int customerCount) {
//     printf("+---------+----------+----------+----------+\n");
//     printf("| Customer| Email    | Phone    | Bookings |\n");
//     printf("+---------+----------+----------+----------+\n");
//     for (int i = 0; i < customerCount; i++) {
//         printf("| %6s | %8s | %8s | %8d |\n", customers[i].name, customers[i].email, customers[i].phoneNumber, customers[i].bookingCount);
//     }
//     printf("+---------+----------+----------+----------+\n");
// }

// // Function to display booking status
// void displayBookingStatus(Booking *bookings, int bookingCount) {
//     printf("+---------+----------+----------+----------+----------+\n");
//     printf("| Booking | Room No | Customer | Booking  | Checkin  | Checkout|\n");
//     printf("+---------+----------+----------+----------+----------+\n");
//     for (int i = 0; i < bookingCount; i++) {
//         printf("| %6d | %6d | %8d | %8s | %8s | %8s |\n", bookings[i].bookingId, bookings[i].roomId, bookings[i].customerId, bookings[i].bookingDate, bookings[i].checkinDate, bookings[i].checkoutDate);
//     }
//     printf("+---------+----------+----------+----------+----------+\n");
// }

// // Function to login as receptionist
// int loginReceptionist(Receptionist receptionist) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, receptionist.username) == 0 && strcmp(password, receptionist.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

// // Function to load menu items from a file
// void loadMenu(MenuItem *menu, int *menuCount) {
//     FILE *file = fopen("menu.txt", "r");
//     if (file == NULL) {
//         printf("Could not open menu file.\n");
//         return;
//     }
//     while (fscanf(file, "%49[^,],%f\n", menu[*menuCount].name, &menu[*menuCount].price) != EOF) {
//         (*menuCount)++;
//     }
//     fclose(file);
// }

// // Function to load login information from a file
// void loadLoginInfo(Manager *manager, Receptionist *receptionist) {
//     FILE *file = fopen("login_info.txt", "r");
//     if (file == NULL) {
//         return; // File does not exist, return without loading
//     }
//     fscanf(file, "Manager Username: %s\n", manager->username);
//     fscanf(file, "Manager Password: %s\n", manager->password);
//     fscanf(file, "Receptionist Username: %s\n", receptionist->username);
//     fscanf(file, "Receptionist Password: %s\n", receptionist->password);
//     fclose(file);
// }

// // Function to save login information to a file
// void saveLoginInfo(Manager manager, Receptionist receptionist) {
//     FILE *file = fopen("login_info.txt", "w");
//     if (file == NULL) {
//         printf("Error opening file\n");
//         return;
//     }
//     fprintf(file, "Manager Username: %s\n", manager.username);
//     fprintf(file, "Manager Password: %s\n", manager.password);
//     fprintf(file, "Receptionist Username: %s\n", receptionist.username);
//     fprintf(file, "Receptionist Password: %s\n", receptionist.password);
//     fclose(file);
// }

// // Function to display the menu
// void displayMenu(MenuItem *menu, int menuCount) {
//     printf("+----------------------+----------+\n");
//     printf("| Item                 | Price    |\n");
//     printf("+----------------------+----------+\n");
//     for (int i = 0; i < menuCount; i++) {
//         printf("| %-20s | %.2f    |\n", menu[i].name, menu[i].price);
//     }
//     printf("+----------------------+----------+\n");
// }

// // Function to display the bill
// void displayBill(Bill *bills, int billCount) {
//     printf("+---------+----------+----------+----------+\n");
//     printf("| Booking | Room Price | Menu Total | Total   |\n");
//     printf("+---------+----------+----------+----------+\n");
//     for (int i = 0; i < billCount; i++) {
//         printf("| %6d | %.2f    | %.2f      | %.2f    |\n", bills[i].bookingId, bills[i].roomPrice, bills[i].menuTotal, bills[i].totalAmount);
//     }
//     printf("+---------+----------+----------+----------+\n");
// }

// // Function to purchase an item and add to the bill
// void purchaseItem(MenuItem *menu, int menuCount, Bill *bill) {
//     char itemName[50];
//     printf("Enter the name of the item to purchase: ");
//     scanf("%s", itemName);
//     for (int i = 0; i < menuCount; i++) {
//         if (strcmp(menu[i].name, itemName) == 0) {
//             bill->menuTotal += menu[i].price;
//             bill->totalAmount = bill->roomPrice + bill->menuTotal; // Update total amount
//             printf("You have purchased %s for %.2f\n", menu[i].name, menu[i].price);
//             return;
//         }
//     }
//     printf("Item not found in the menu.\n");
// }

// int main() {
//     displayHeader();
//     Room rooms[100];
//     int roomCount = 0;
//     Customer customers[100];
//     int customerCount = 0;
//     Booking bookings[100];
//     int bookingCount = 0;
//     Bill bills[100];
//     int billCount = 0;
//     Manager manager = {"", ""};
//     Receptionist receptionist = {"", ""};
//     MenuItem menu[100];
//     int menuCount = 0;

//     // Load menu items from file
//     loadMenu(menu, &menuCount);

//     // Load login information from file
//     loadLoginInfo(&manager, &receptionist);

//     // Check if login info exists
//     if (strlen(manager.username) == 0 || strlen(receptionist.username) == 0) {
//         // Register manager and receptionist if not already registered
//         printf("Enter manager username: ");
//         scanf("%s", manager.username);
//         printf("Enter manager password: ");
//         scanf("%s", manager.password);

//         printf("Enter receptionist username: ");
//         scanf("%s", receptionist.username);
//         printf("Enter receptionist password: ");
//         scanf("%s", receptionist.password);

//         // Save the login information to the file
//         saveLoginInfo(manager, receptionist);
//     }

//     while (1) {
//         printf("+-----------------------+\n");
//         printf("|       Login Menu     |\n");
//         printf("+-----------------------+\n");
//         printf("| 1. Login as manager  |\n");
//         printf("| 2. Login as receptionist|\n");
//         printf("| 3. Exit              |\n");
//         printf("+-----------------------+\n");
//         int choice;
//         scanf("%d", &choice);

//         if (choice == 1) {
//             if (loginManager(manager)) {
//                 while (1) {
//                     printf("+-----------------------+\n");
//                     printf("|      Manager Menu    |\n");
//                     printf("+-----------------------+\n");
//                     printf("| 1. Add room          |\n");
//                     printf("| 2. Display rooms     |\n");
//                     printf("| 3. Display customer status|\n");
//                     printf("| 4. Display booking status|\n");
//                     printf("| 5. Display bills     |\n");
//                     printf("| 6. Logout            |\n");
//                     printf("+----------------------- +\n");
//                     int choice2;
//                     scanf("%d", &choice2);

//                     if (choice2 == 1) {
//                         addRoom(rooms, &roomCount);
//                     } else if (choice2 == 2) {
//                         displayRooms(rooms, roomCount);
//                     } else if (choice2 == 3) {
//                         displayCustomerStatus(customers, customerCount);
//                     } else if (choice2 == 4) {
//                         displayBookingStatus(bookings, bookingCount);
//                     } else if (choice2 == 5) {
//                         displayBill(bills, billCount);
//                     } else if (choice2 == 6) {
//                         break;
//                     } else {
//                         printf("Invalid choice\n");
//                     }
//                 }
//             }
//         } else if (choice == 2) {
//             if (loginReceptionist(receptionist)) {
//                 while (1) {
//                     printf("+-----------------------+\n");
//                     printf("|    Receptionist Menu  |\n");
//                     printf("+-----------------------+\n");
//                     printf("| 1. Book room          |\n");
//                     printf("| 2. Cancel booking     |\n");
//                     printf("| 3. Display rooms      |\n");
//                     printf("| 4. Display customer status|\n");
//                     printf("| 5. Display booking status|\n");
//                     printf("| 6. Display menu       |\n");
//                     printf("| 7. Purchase item      |\n");
//                     printf("| 8. Logout             |\n");
//                     printf("+-----------------------+\n");
//                     int choice2;
//                     scanf("%d", &choice2);

//                     if (choice2 == 1) {
//                         bookRoom(rooms, roomCount, customers, &customerCount, bookings, &bookingCount, bills, &billCount);
//                     } else if (choice2 == 2) {
//                         cancelBooking(rooms, roomCount, bookings, bookingCount);
//                     } else if (choice2 == 3) {
//                         displayRooms(rooms, roomCount);
//                     } else if (choice2 == 4) {
//                         displayCustomerStatus(customers, customerCount);
//                     } else if (choice2 == 5) {
//                         displayBookingStatus(bookings, bookingCount);
//                     } else if (choice2 == 6) {
//                         displayMenu(menu, menuCount);
//                     } else if (choice2 == 7) {
//                         if (bookingCount > 0) {
//                             purchaseItem(menu, menuCount, &bills[bookingCount - 1]); // Pass the latest bill
//                         } else {
//                             printf("No bookings available to purchase items for.\n");
//                         }
//                     } else if (choice2 == 8) {
//                         break;
//                     } else {
//                         printf("Invalid choice\n");
//                     }
//                 }
//             }
//         } else if (choice == 3) {
//             return 0;
//         } else {
//             printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }

// -----XXXXXXXXXX--------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a hotel room
typedef struct {
    char roomName[10]; // Room name can be alphanumeric (e.g., "101A")
    int capacity;
    float price;
    char status[10]; // "available" or "booked"
    char roomType[50]; // Added room type field
} Room;

// Structure to represent a customer
typedef struct {
    char name[50];
    char email[50];
    char phoneNumber[20];
    int bookingCount;
} Customer;

// Structure to represent a booking
typedef struct {
    int bookingId;
    char roomName[10]; // Use room name instead of room ID
    int customerId;
    char bookingDate[20];
    char checkinDate[20];
    char checkoutDate[20];
    char roomType[50]; // Store the room type
} Booking;

// Structure to represent a manager
typedef struct {
    char username[20];
    char password[20];
} Manager;

// Structure to represent a receptionist
typedef struct {
    char username[20];
    char password[20];
} Receptionist;

// Structure to represent a user
typedef struct {
    char username[20];
    char password[20];
    char name[50];
    char email[50];
    char phoneNumber[20];
} User;

// Structure to represent a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Structure to represent a bill
typedef struct {
    int bookingId;
    float roomPrice;
    float menuTotal;
    float totalAmount;
} Bill;

typedef struct {
    char type[50];
    float price;
} RoomType;

// Function declarations
void displayHeader();
void addRoom(Room *rooms, int *roomCount, RoomType *roomTypes, int roomTypeCount);
void bookRoom(Room *rooms, int roomCount, Customer *customers, int *customerCount, Booking *bookings, int *bookingCount, Bill *bills, int *billCount);
void cancelBooking(Room *rooms, int roomCount, Booking *bookings, int bookingCount);
int loginManager(Manager manager);
void displayRooms(Room *rooms, int roomCount);
void displayCustomerStatus(Customer *customers, int customerCount);
void displayBookingStatus(Booking *bookings, int bookingCount);
int loginReceptionist(Receptionist receptionist);
int loginUser (User *user, int userCount);
void loadMenu(MenuItem *menu, int *menuCount);
void loadLoginInfo(Manager *manager, Receptionist *receptionist, User *user);
void saveLoginInfo(Manager manager, Receptionist receptionist, User user);
void loadUserProfile(User *user);
void saveUserProfile(User user);
void displayMenu(MenuItem *menu, int menuCount);
void displayBill(Bill *bills, int billCount, Booking *bookings);
void purchaseItem(MenuItem *menu, int menuCount, Bill *bill);
void loadRoomsFromFile(Room *rooms, int *roomCount);
void saveRoomsToFile(Room *rooms, int roomCount);
void loadRoomTypes(RoomType *roomTypes, int *roomTypeCount);
void registerUser(User *users, int *userCount);

// Function to display the header
void displayHeader() {
    printf("\n");
    printf("****************************************************\n");
    printf("*                                                 *\n");
    printf("*               Hotel Management System           *\n");
    printf("*                                                 *\n");
    printf("****************************************************\n");
    printf("\n");
}

// Function to check if a room already exists
int roomExists(Room *rooms, int roomCount, const char *roomName) {
    for (int i = 0; i < roomCount; i++) {
        if (strcmp(rooms[i].roomName, roomName) == 0) {
            return 1; // Room exists
        }
    }
    return 0; // Room does not exist
}

// Function to load room types from a file
void loadRoomTypes(RoomType *roomTypes, int *roomTypeCount) {
    FILE *file = fopen("roomType.txt", "r");
    if (file == NULL) {
        printf("Could not open room type file.\n");
        return;
    }
    while (fscanf(file, "%49[^,],%f\n", roomTypes[*roomTypeCount].type, &roomTypes[*roomTypeCount].price) != EOF) {
        (*roomTypeCount)++;
    }
    fclose(file);
}

// Function to load existing rooms from a file
void loadRoomsFromFile(Room *rooms, int *roomCount) {
    FILE *file = fopen("roomdetails.txt", "r");
    if (file == NULL) {
        printf("Could not open room details file.\n");
        return;
    }
    while (fscanf(file, "%9s %d %f %s %49[^\n]\n", rooms[*roomCount].roomName, &rooms[*roomCount].capacity, &rooms[*roomCount].price, rooms[*roomCount].status, rooms[*roomCount].roomType) != EOF) {
        (*roomCount)++;
    }
    fclose(file);
}

// Function to save rooms to a file
void saveRoomsToFile(Room *rooms, int roomCount) {
    FILE *file = fopen("roomdetails.txt", "w");
    if (file == NULL) {
        printf("Error opening room details file for writing.\n");
        return;
    }
    for (int i = 0; i < roomCount; i++) {
        fprintf(file, "%s %d %.2f %s %s\n", rooms[i].roomName, rooms[i].capacity, rooms[i].price, rooms[i].status, rooms[i].roomType);
    }
    fclose(file);
}

// Function to add a new room
void addRoom(Room *rooms, int *roomCount, RoomType *roomTypes, int roomTypeCount) {
    Room newRoom;
    char roomType[50];
    int isValidType = 0;
    float roomPrice = 0.0;

    printf("Enter room type (e.g., Double room, Presidential Suites): ");
    scanf(" %[^\n]", roomType); // Read string with spaces

    // Validate room type and get the price
    for (int i = 0; i < roomTypeCount; i++) {
        if (strcmp(roomType, roomTypes[i].type) == 0) {
            isValidType = 1;
            roomPrice = roomTypes[i].price; // Get the price for the valid type
            break;
        }
    }

    if (!isValidType) {
        printf("Invalid room type: %s\n", roomType);
        return; // Exit if invalid
    }

    printf("Enter room name (e.g., 101A): ");
    scanf("%s", newRoom.roomName);

    if (roomExists(rooms, *roomCount, newRoom.roomName)) {
        printf("Room %s already exists!\n", newRoom.roomName);
        return;
    }

    printf("Enter room capacity: ");
    scanf("%d", &newRoom.capacity);
    newRoom.price = roomPrice; // Set the price based on room type
    strcpy(newRoom.status, "available");
    strcpy(newRoom.roomType, roomType); // Store the room type
    rooms[*roomCount] = newRoom;
    (*roomCount)++;
    printf("Room %s of type %s added successfully with price %.2f!\n", newRoom.roomName, roomType, roomPrice);
    saveRoomsToFile(rooms, *roomCount); // Save updated room list to file
}

// Function to book a room
void bookRoom(Room *rooms, int roomCount, Customer *customers, int *customerCount, Booking *bookings, int *bookingCount, Bill *bills, int *billCount) {
    char roomName[10];
    printf("Enter room name to book: ");
    scanf("%s", roomName);
    for (int i = 0; i < roomCount; i++) {
        if (strcmp(rooms[i].roomName, roomName) == 0 && strcmp(rooms[i].status, "available") == 0) {
            // Collect customer details
            printf("Enter customer name: ");
            scanf("%s", customers[*customerCount].name);
            printf("Enter customer email: ");
            scanf("%s", customers[*customerCount].email);
            printf("Enter customer phone number: ");
            scanf("%s", customers[*customerCount].phoneNumber);
            customers[*customerCount].bookingCount++;

            // Create a new booking
            Booking newBooking;
            newBooking.bookingId = *bookingCount;
            newBooking.customerId = *customerCount;
            strcpy(newBooking.roomName, roomName);
            strcpy(newBooking.roomType, rooms[i].roomType); // Store the room type
            printf("Enter booking date (YYYY-MM-DD): ");
            scanf("%s", newBooking.bookingDate);
            printf("Enter checkin date (YYYY-MM-DD): ");
            scanf("%s", newBooking.checkinDate);
            scanf("%s", newBooking.checkinDate);
            printf("Enter checkout date (YYYY-MM-DD): ");
            scanf("%s", newBooking.checkoutDate);
            bookings[*bookingCount] = newBooking;
            (*bookingCount)++;
            strcpy(rooms[i].status, "booked");
            (*customerCount)++; // Increment customer count

            // Bill generation
            Bill newBill;
            newBill.bookingId = newBooking.bookingId;
            newBill.roomPrice = rooms[i].price;
            newBill.menuTotal = 0.0;
            newBill.totalAmount = newBill.roomPrice; // Initialize total amount
            bills[*billCount] = newBill; // Store the bill for this booking
            (*billCount)++;

            printf("Room %s booked successfully!\n", newBooking.roomName);
            printf("Total room price: %.2f\n", newBill.roomPrice);
            return;
        }
    }
    printf("Room %s not available\n", roomName);
}

// Function to cancel a booking
void cancelBooking(Room *rooms, int roomCount, Booking *bookings, int bookingCount) {
    int bookingId;
    printf("Enter booking ID to cancel: ");
    scanf("%d", &bookingId);
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingId == bookingId) {
            for (int j = 0; j < roomCount; j++) {
                if (strcmp(rooms[j].roomName, bookings[i].roomName) == 0) {
                    strcpy(rooms[j].status, "available");
                    break;
                }
            }
            printf("Booking cancelled\n");
            return;
        }
    }
    printf("Booking not found\n");
}

// Function to login as manager
int loginManager(Manager manager) {
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(username, manager.username) == 0 && strcmp(password, manager.password) == 0) {
        printf("Login successful\n");
        return 1;
    }
    printf("Invalid username or password\n");
    return 0;
}

// Function to display rooms
void displayRooms(Room *rooms, int roomCount) {
    printf("+------------+----------+----------+-----------+---------------------+\n");
    printf("| Room Name  | Capacity |   Price   |   Status   |      Room Type      |\n");
    printf("+------------+----------+----------+-----------+---------------------+\n");
    for (int i = 0; i < roomCount; i++) {
        printf("| %-10s | %8d | %8.2f | %-9s | %-18s |\n", 
               rooms[i].roomName, 
               rooms[i].capacity, 
               rooms[i].price, 
               rooms[i].status, 
               rooms[i].roomType);
    }
    printf("+------------+----------+----------+-----------+---------------------+\n");
}

// Function to display customer status
void displayCustomerStatus(Customer *customers, int customerCount) {
    printf("+---------+----------+----------+----------+\n");
    printf("| Customer| Email    | Phone    | Bookings |\n");
    printf("+---------+----------+----------+----------+\n");
    for (int i = 0; i < customerCount; i++) {
        printf("| %6s | %8s | %8s | %8d |\n", customers[i].name, customers[i].email, customers[i].phoneNumber, customers[i].bookingCount);
    }
    printf("+---------+----------+----------+----------+\n");
}

// Function to display booking status
void displayBookingStatus(Booking *bookings, int bookingCount) {
    printf("+---------+----------+----------+----------+----------+----------+\n");
    printf("| Booking | Room Name | Customer | Booking  | Checkin  | Checkout  |\n");
    printf("+---------+----------+----------+----------+----------+----------+\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("| %6d | %9s | %8d | %8s | %8s | %8s |\n", 
               bookings[i].bookingId, bookings[i].roomName, bookings[i].customerId, bookings[i].bookingDate, bookings[i].checkinDate, bookings[i].checkoutDate);
    }
    printf("+---------+----------+----------+----------+----------+----------+\n");
}

// Function to login as receptionist
int loginReceptionist(Receptionist receptionist) {
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(username, receptionist.username) == 0 && strcmp(password, receptionist.password) == 0) {
        printf("Login successful\n");
        return 1;
    }
    printf("Invalid username or password\n");
    return 0;
}

// Function to login as user
// int loginUser (User user) {
//     char username[20];
//     char password[20];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
//     if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
//         printf("Login successful\n");
//         return 1;
//     }
//     printf("Invalid username or password\n");
//     return 0;
// }

int loginUser(User *users, int userCount) {
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Check against all registered users
    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful\n");
            return 1; // User found and logged in
        }
    }
    printf("Invalid username or password\n");
    return 0; // User not found
}

// Function to load menu items from a file
void loadMenu(MenuItem *menu, int *menuCount) {
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) {
        printf("Could not open menu file.\n");
        return;
    }
    while (fscanf(file, "%49[^,],%f\n", menu[*menuCount].name, &menu[*menuCount].price) != EOF) {
        (*menuCount)++;
    }
    fclose(file);
}

// Function to load login information from a file
void loadLoginInfo(Manager *manager, Receptionist *receptionist, User *user) {
    FILE *file = fopen("login_info.txt", "r");
    if (file == NULL) {
        return; // File does not exist, return without loading
    }
    fscanf(file, "Manager Username: %s\n", manager->username);
    fscanf(file, "Manager Password: %s\n", manager->password);
    fscanf(file, "Receptionist Username: %s\n", receptionist->username);
    fscanf(file, "Receptionist Password: %s\n", receptionist->password);
    fscanf(file, "User  Username: %s\n", user->username);
    fscanf(file, "User  Password: %s\n", user->password);
    fclose(file);
}

// Function to save login information to a file
void saveLoginInfo(Manager manager, Receptionist receptionist, User user) {
    FILE *file = fopen("login_info.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "Manager Username: %s\n", manager.username);
    fprintf(file, "Manager Password: %s\n", manager.password);
    fprintf(file, "Receptionist Username: %s\n", receptionist.username);
    fprintf(file, "Receptionist Password: %s\n", receptionist.password);
    fprintf(file, "User  Username: %s\n", user.username);
    fprintf(file, "User  Password: %s\n", user.password);
    fclose(file);
}

// Function to load user profile information from a file
void loadUserProfile(User *user) {
    FILE *file = fopen("userProfile.txt", "r");
    if (file == NULL) {
        return; // File does not exist, return without loading
    }
    fscanf(file, "Name: %49[^\n]\n", user->name);
    fscanf(file, "Email: %49[^\n]\n", user->email);
    fscanf(file, "Phone: %19[^\n]\n", user->phoneNumber);
    fclose(file);
}

// Function to save user profile information to a file
void saveUserProfile(User user) {
    FILE *file = fopen("userProfile.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "Name: %s\n", user.name);
    fprintf(file, "Email: %s\n", user.email);
    fprintf(file, "Phone: %s\n", user.phoneNumber);
    fclose(file);
}

// Function to display the menu
void displayMenu(MenuItem *menu, int menuCount) {
    printf("+----------------------+----------+\n");
    printf("| Item                 | Price    |\n");
    printf("+----------------------+----------+\n");
    for (int i = 0; i < menuCount; i++) {
        printf("| %-20s | %.2f    |\n", menu[i].name, menu[i].price);
    }
    printf("+----------------------+----------+\n");
}

// Function to display the bill
void displayBill(Bill *bills, int billCount, Booking *bookings) {
    printf("+---------+----------+----------+----------+-----------+\n");
    printf("| Booking | Room Price | Menu Total | Total   | Room Type |\n");
    printf("+---------+----------+----------+----------+-----------+\n");
    for (int i = 0; i < billCount; i++) {
        // Find the corresponding booking to get the room type
        char roomType[50] = "";
        for (int j = 0; j < billCount; j++) {
            if (bills[i].bookingId == bookings[j].bookingId) {
                strcpy(roomType, bookings[j].roomType);
                break;
            }
        }
        printf("| %6d | %.2f    | %.2f      | %.2f    | %s       |\n", 
               bills[i].bookingId, 
               bills[i].roomPrice, 
               bills[i].menuTotal, 
               bills[i].totalAmount, 
               roomType);
    }
    printf("+---------+----------+----------+----------+-----------+\n");
}

// Function to purchase an item and add to the bill
void purchaseItem(MenuItem *menu, int menuCount, Bill *bill) {
    char itemName[50];
    printf("Enter the name of the item to purchase: ");
    scanf("%s", itemName);
    for (int i = 0; i < menuCount; i++) {
        if (strcmp(menu[i].name, itemName) == 0) {
            bill->menuTotal += menu[i].price;
            bill->totalAmount = bill->roomPrice + bill->menuTotal; // Update total amount
            printf("You have purchased %s for %.2f\n", menu[i].name, menu[i].price);
            return;
        }
    }
    printf("Item not found in the menu.\n");
}

void userBookRoom(Room *rooms, int roomCount, Customer *customers, int *customerCount, Booking *bookings, int *bookingCount, Bill *bills, int *billCount, User user) {
    char roomName[10];
    printf("Enter room name to book: ");
    scanf("%s", roomName);
    
    for (int i = 0; i < roomCount; i++) {
        if (strcmp(rooms[i].roomName, roomName) == 0 && strcmp(rooms[i].status, "available") == 0) {
            // Check if the user is already in the customers list
            int existingCustomerIndex = -1;
            for (int j = 0; j < *customerCount; j++) {
                if (strcmp(customers[j].email, user.email) == 0) { // Assuming email is unique
                    existingCustomerIndex = j;
                    break;
                }
            }

            // If the user is not found, add them as a new customer
            if (existingCustomerIndex == -1) {
                Customer newCustomer;
                strcpy(newCustomer.name, user.name);
                strcpy(newCustomer.email, user.email);
                strcpy(newCustomer.phoneNumber, user.phoneNumber);
                newCustomer.bookingCount = 1; // First booking
                customers[*customerCount] = newCustomer;
                existingCustomerIndex = (*customerCount)++;
            } else {
                // If the customer exists, just increment the booking count
                customers[existingCustomerIndex].bookingCount++;
            }

            // Create a new booking for the user
            Booking newBooking;
            newBooking.bookingId = *bookingCount;
            newBooking.customerId = existingCustomerIndex; // Use the existing customer index
            strcpy(newBooking.roomName, roomName);
            strcpy(newBooking.roomType, rooms[i].roomType); // Store the room type
            printf("Enter booking date (YYYY-MM-DD): ");
            scanf("%s", newBooking.bookingDate);
            printf("Enter checkin date (YYYY-MM-DD): ");
            scanf("%s", newBooking.checkinDate);
            printf("Enter checkout date (YYYY-MM-DD): ");
            scanf("%s", newBooking.checkoutDate);
            bookings[*bookingCount] = newBooking;
            (*bookingCount)++;
            strcpy(rooms[i].status, "booked");

            // Bill generation
            Bill newBill;
            newBill.bookingId = newBooking.bookingId;
            newBill.roomPrice = rooms[i].price;
            newBill.menuTotal = 0.0;
            newBill.totalAmount = newBill.roomPrice; // Initialize total amount
            bills[*billCount] = newBill; // Store the bill for this booking
            (*billCount)++;

            // Display customer details
            printf("\nCustomer Details:\n");
            printf("Name: %s\n", customers[existingCustomerIndex].name);
            printf("Email: %s\n", customers[existingCustomerIndex].email);
            printf("Phone: %s\n", customers[existingCustomerIndex].phoneNumber);
            printf("Total Bookings: %d\n", customers[existingCustomerIndex].bookingCount);

            printf("Room %s booked successfully!\n", newBooking.roomName);
            printf("Total room price: %.2f\n", newBill.roomPrice);
            return;
        }
    }
    printf("Room %s not available\n", roomName);
}

// --- New user regiter Logic ---
void registerUser (User *user, int *userCount) {
    printf("Enter your name: ");
    scanf(" %[^\n]", user->name); // Read string with spaces
    printf("Enter your email: ");
    scanf("%s", user->email);
    printf("Enter your phone number: ");
    scanf("%s", user->phoneNumber);
    printf("Enter a username: ");
    scanf("%s", user->username);
    printf("Enter a password: ");
    scanf("%s", user->password);

    // Save the user details to userDetails.txt
    FILE *file = fopen("userDetails.txt", "a");
    if (file == NULL) {
        printf("Error opening user details file for writing.\n");
        return;
    }
    fprintf(file, "%s,%s,%s,%s,%s\n", user->name, user->email, user->phoneNumber, user->username, user->password);
    fclose(file);
    printf("Registration successful! You can now log in.\n");
}


void loadUserDetails(User *user, int *userCount) {
    FILE *file = fopen("userDetails.txt", "r");
    if (file == NULL) {
        printf("Could not open user details file.\n");
        return;
    }
    while (fscanf(file, "%49[^,],%49[^,],%19[^,],%19[^,],%19[^\n]\n", user[*userCount].name, user[*userCount].email, user[*userCount].phoneNumber, user[*userCount].username, user[*userCount].password) != EOF) {
        (*userCount)++;
    }
    fclose(file);
    printf("Loaded %d existing users.\n", *userCount);
}

// Function to check if the user exists
int userExists(User *users, int userCount, const char *username, const char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; 
        }
    }
    return 0;
}



int main() {
    displayHeader();
    Room rooms[100];
    int roomCount = 0;
    Customer customers[100];
    int customerCount = 0;
    Booking bookings[100];
    int bookingCount = 0;
    Bill bills[100];
    int billCount = 0;
    Manager manager = {"", ""};
    Receptionist receptionist = {"", ""};
    User user = {"", "", "", "", ""};
    MenuItem menu[100];
    int menuCount = 0;
    RoomType roomTypes[100];
    int roomTypeCount = 0;

    User users[100];
    int userCount = 0;

    // Load existing rooms from file
    loadRoomsFromFile(rooms, &roomCount);

    // Load room types from file
    loadRoomTypes(roomTypes, &roomTypeCount);

    // Load menu items from file
    loadMenu(menu, &menuCount);

    // Load login information from file
    loadLoginInfo(&manager, &receptionist, &users[0]);

    // Load user profile information from file
    loadUserProfile(&user);

    loadUserDetails(users, &userCount);

    // Check if login info exists
    if (strlen(manager.username) == 0 || strlen(receptionist.username) == 0 || strlen(user.username) == 0) {
        // Register manager, receptionist, and user if not already registered
        printf("Enter manager username: ");
        scanf("%s", manager.username);
        printf("Enter manager password: ");
        scanf("%s", manager.password);

        printf("Enter receptionist username: ");
        scanf("%s", receptionist.username);
        printf("Enter receptionist password: ");
        scanf("%s", receptionist.password);

        printf("Enter user username: ");
        scanf("%s", user.username);
        printf("Enter user password: ");
        scanf("%s", user.password);

        // Save the login information to the file
        saveLoginInfo(manager, receptionist, user);
    }

    while (1) {
        printf("+-----------------------+\n");
        printf("|       Login Menu     |\n");
        printf("+-----------------------+\n");
        printf("| 1. Login as manager   |\n");
        printf("| 2. Login as receptionist|\n");
        printf("| 3. Login as user      |\n");
        printf("| 4. Register New user      |\n");
        printf("| 5. Exit               |\n");
        printf("+-----------------------+\n");
        int choice;
        scanf("Enter Choice: %d", &choice);

        if (choice == 1) {
            if (loginManager(manager)) {
                while (1) {
                    printf("+-----------------------+\n");
                    printf("|      Manager Menu     |\n");
                    printf("+-----------------------+\n");
                    printf("| 1. Add room           |\n");
                    printf("| 2. Display rooms      |\n");
                    printf("| 3. Display customer status|\n");
                    printf("| 4. Display booking status|\n");
                    printf("| 5. Display bills      |\n");
                    printf("| 6. Logout             |\n");
                    printf("+-----------------------+\n");
                    int choice2;
                    scanf("%d", &choice2);

                    if (choice2 == 1) {
                        addRoom(rooms, &roomCount, roomTypes, roomTypeCount);
                    } else if (choice2 == 2) {
                        displayRooms(rooms, roomCount);
                    } else if (choice2 == 3) {
                        displayCustomerStatus(customers, customerCount);
                    } else if (choice2 == 4) {
                        displayBookingStatus(bookings, bookingCount);
                    } else if (choice2 == 5) {
                        displayBill(bills, billCount, bookings);
                    } else if (choice2 == 6) {
                        break;
                    } else {
                        printf("Invalid choice\n");
                    }
                }
            }
        } else if (choice == 2) {
            if (loginReceptionist(receptionist)) {
                while (1) {
                    printf("+-----------------------+\n");
                    printf("|    Receptionist Menu  |\n");
                    printf("+-----------------------+\n");
                    printf("| 1. Book room          |\n");
                    printf("| 2. Cancel booking     |\n");
                    printf("| 3. Display rooms      |\n");
                    printf("| 4. Display customer status|\n");
                    printf("| 5. Display booking status|\n");
                    printf("| 6. Display menu       |\n");
                    printf("| 7. Purchase item      |\n");
                    printf("| 8. Logout             |\n");
                    printf("+-----------------------+\n");
                    int choice2;
                    scanf("Enter Choice: %d", &choice2);

                    if (choice2 == 1) {
                        bookRoom(rooms, roomCount, customers, &customerCount, bookings, &bookingCount, bills, &billCount);
                    } else if (choice2 == 2) {
                        cancelBooking(rooms, roomCount, bookings, bookingCount);
                    } else if (choice2 == 3) {
                        displayRooms(rooms, roomCount);
                    } else if (choice2 == 4) {
                        displayCustomerStatus(customers, customerCount);
                    } else if (choice2 == 5) {
                        displayBookingStatus(bookings, bookingCount);
                    } else if (choice2 == 6) {
                        displayMenu(menu, menuCount);
                    } else if (choice2 == 7) {
                        if (bookingCount > 0) {
                            purchaseItem(menu, menuCount, &bills[bookingCount - 1]); // Pass the latest bill
                        } else {
                            printf("No bookings available to purchase items for.\n");
                        }
                    } else if (choice2 == 8) {
                        break;
                    } else {
                        printf("Invalid choice\n");
                    }
                }
            }
        } else if (choice == 3) {
            if (loginUser (users, userCount)) {
                while (1) {
                    printf("+-----------------------+\n");
                    printf("|        User Menu     |\n");
                    printf("+-----------------------+\n");
                    printf("| 1. View Profile       |\n");
                    printf("| 2. Update Profile     |\n");
                    printf("| 3. Display rooms      |\n");
                    printf("| 4. Display menu       |\n");
                    printf("| 5. Book the Room      |\n");
                    printf("| 6. Order Item         |\n");
                    printf("| 7. Logout             |\n");
                    printf("+-----------------------+\n");
                    int choice2;
                    scanf("%d", &choice2);

                    if (choice2 == 1) {
                        printf("User  Profile:\n");
                        printf("Name: %s\n", user.name);
                        printf("Email: %s\n", user.email);
                        printf("Phone: %s\n", user.phoneNumber);
                    } else if (choice2 == 2) {
                        printf("Enter new name: ");
                        scanf("%s", user.name);
                        printf("Enter new email: ");
                        scanf("%s", user.email);
                        printf("Enter new phone number: ");
                        scanf("%s", user.phoneNumber);
                        saveUserProfile(user);
                        printf("Profile updated successfully!\n");
                    } else if (choice2 == 3) {
                        displayRooms(rooms, roomCount);
                    } else if (choice2 == 4) {
                        displayMenu(menu, menuCount);
                    } else if (choice2 == 5) {
                        userBookRoom(rooms, roomCount, customers, &customerCount, bookings, &bookingCount, bills, &billCount, user);
                    } else if (choice2 == 6) {
                        if (bookingCount > 0) {
                            purchaseItem(menu, menuCount, &bills[bookingCount - 1]); // Pass the latest bill
                        } else {
                            printf("No bookings available to purchase items for.\n");
                        }
                    } else if (choice2 == 7) {
                        break;
                    } else {
                        printf("Invalid choice\n");
                    }
                }
            }
        } else if (choice == 4) {
            registerUser(&users[userCount], &userCount);
            // userCount++;
            break;
        } else if(choice == 5){
            return 0;
        }else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

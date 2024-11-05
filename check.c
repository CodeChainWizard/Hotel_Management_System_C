// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Structure to represent a hotel room
// typedef struct {
//     int roomNumber;
//     char roomType[20];
//     int isOccupied;
// } Room;

// // Structure to represent a hotel guest
// typedef struct {
//     char name[50];
//     int roomNumber;
// } Guest;

// // Function to initialize the hotel management system
// void initHotel(Room rooms[], int numRooms) {
//     for (int i = 0; i < numRooms; i++) {
//         rooms[i].roomNumber = i + 1;
//         strcpy(rooms[i].roomType, "Single");
//         rooms[i].isOccupied = 0;
//     }
// }

// // Function to display the hotel rooms
// void displayRooms(Room rooms[], int numRooms) {
//     printf("Room Number\tRoom Type\tOccupied\n");
//     for (int i = 0; i < numRooms; i++) {
//         printf("%d\t\t%s\t\t%d\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].isOccupied);
//     }
// }

// // Function to book a room
// void bookRoom(Room rooms[], int numRooms, Guest guests[], int numGuests) {
//     int roomNumber;
//     printf("Enter the room number to book: ");
//     scanf("%d", &roomNumber);

//     if (roomNumber < 1 || roomNumber > numRooms) {
//         printf("Invalid room number\n");
//         return;
//     }

//     if (rooms[roomNumber - 1].isOccupied) {
//         printf("Room is already occupied\n");
//         return;
//     }

//     char name[50];
//     printf("Enter the guest's name: ");
//     scanf("%s", name);

//     Guest guest;
//     strcpy(guest.name, name);
//     guest.roomNumber = roomNumber;

//     guests[numGuests] = guest;
//     rooms[roomNumber - 1].isOccupied = 1;

//     printf("Room booked successfully\n");
// }

// // Function to cancel a booking
// void cancelBooking(Room rooms[], int numRooms, Guest guests[], int numGuests) {
//     int roomNumber;
//     printf("Enter the room number to cancel: ");
//     scanf("%d", &roomNumber);

//     if (roomNumber < 1 || roomNumber > numRooms) {
//         printf("Invalid room number\n");
//         return;
//     }

//     if (!rooms[roomNumber - 1].isOccupied) {
//         printf("Room is not occupied\n");
//         return;
//     }

//     rooms[roomNumber - 1].isOccupied = 0;

//     for (int i = 0; i < numGuests; i++) {
//         if (guests[i].roomNumber == roomNumber) {
//             guests[i].roomNumber = 0;
//             break;
//         }
//     }

//     printf("Booking cancelled successfully\n");
// }

// // Function to search for a guest
// void searchGuest(Guest guests[], int numGuests) {
//     char name[50];
//     printf("Enter the guest's name to search: ");
//     scanf("%s", name);

//     int found = 0;
//     for (int i = 0; i < numGuests; i++) {
//         if (strcmp(guests[i].name, name) == 0) {
//             printf("Guest found: Room %d\n", guests[i].roomNumber);
//             found = 1;
//             break;
//         }
//     }

//     if (!found) {
//         printf("Guest not found\n");
//     }
// }

// // Function to display guest information
// void displayGuests(Guest guests[], int numGuests) {
//     printf("Guest Name\tRoom Number\n");
//     for (int i = 0; i < numGuests; i++) {
//         if (guests[i].roomNumber != 0) {
//             printf("%s\t\t%d\n", guests[i].name, guests[i].roomNumber);
//         }
//     }
// }

// int main() {
//     int numRooms = 10;
//     Room rooms[numRooms];
//     initHotel(rooms, numRooms);

//     int numGuests = 0;
//     Guest guests[10];

//     while (1) {
//         printf("1. Display rooms\n");
//         printf("2. Book a room\n");
//         printf("3. Cancel a booking\n");
//  printf("4. Search for a guest\n");
//         printf("5. Display guest information\n");
//         printf("6. Exit\n");
//         int choice;
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 displayRooms(rooms, numRooms);
//                 break;
//             case 2:
//                 bookRoom(rooms, numRooms, guests, numGuests);
//                 numGuests++;
//                 break;
//             case 3:
//                 cancelBooking(rooms, numRooms, guests, numGuests);
//                 break;
//             case 4:
//                 searchGuest(guests, numGuests);
//                 break;
//             case 5:
//                 displayGuests(guests, numGuests);
//                 break;
//             case 6:
//                 return 0;
//             default:
//                 printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }
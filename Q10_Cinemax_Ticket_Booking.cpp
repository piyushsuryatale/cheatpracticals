// Q10. Cinemax ticket booking: 10 rows x 7 seats. Doubly linked list of free seats per row,
// array of head pointers. a) Display available seats  b) Cancel a booking.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Seat
{
 int seatNo;
 Seat* prev;
 Seat* next;
};
Seat* head[10]; // head pointer of free seat list of each row
Seat* findSeat(int row, int seatNo)
{
 Seat* temp = head[row];
 while(temp != NULL && temp->seatNo != seatNo)
 temp = temp->next;
 return temp;
}
void insertSeat(int row, int seatNo) // keeps seats in sorted order
{
 Seat* newSeat = new Seat;
 newSeat->seatNo = seatNo;
 newSeat->prev = newSeat->next = NULL;
 Seat* temp = head[row];
 Seat* last = NULL;
 while(temp != NULL && temp->seatNo < seatNo)
 {
 last = temp;
 temp = temp->next;
 }
 newSeat->next = temp;
 newSeat->prev = last;
 if(temp != NULL) temp->prev = newSeat;
 if(last != NULL) last->next = newSeat;
 else head[row] = newSeat;
}
bool bookSeat(int row, int seatNo) // removes seat from free list
{
 Seat* s = findSeat(row, seatNo);
 if(s == NULL)
 return false;
 if(s->prev != NULL) s->prev->next = s->next;
 else head[row] = s->next;
 if(s->next != NULL) s->next->prev = s->prev;
 delete s;
 return true;
}
void displayAvailable()
{
 for(int i = 0; i < 10; i++)
 {
 cout << "Row " << i + 1 << ": ";
 for(Seat* temp = head[i]; temp != NULL; temp = temp->next)
 cout << temp->seatNo << " ";
 cout << endl;
 }
}
int main()
{
 int choice, row, seat;
 srand(time(0));
 for(int i = 0; i < 10; i++)
 {
 head[i] = NULL;
 for(int j = 1; j <= 7; j++)
 insertSeat(i, j);
 }
 for(int i = 0; i < 15; i++) // random initial bookings
 bookSeat(rand() % 10, rand() % 7 + 1);
 do
 {
 cout << "\n1. Display available seats\n2. Book seat\n3. Cancel booking\n0. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 if(choice == 2 || choice == 3)
 {
 cout << "Enter row (1-10) and seat (1-7): ";
 cin >> row >> seat;
 }
 if(choice == 1)
 displayAvailable();
 else if(choice == 2)
 {
 if(bookSeat(row - 1, seat))
 cout << "Seat booked\n";
 else
 cout << "Seat is already booked\n";
 }
 else if(choice == 3)
 {
 if(findSeat(row - 1, seat) != NULL)
 cout << "This seat is not booked\n";
 else
 {
 insertSeat(row - 1, seat);
 cout << "Booking cancelled\n";
 }
 }
 } while(choice != 0);
 return 0;
}

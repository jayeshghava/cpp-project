#include <iostream>
#include <string>
using namespace std;

class Hotel {
private:
    int hotel_id;
    string hotel_name;
    string hotel_type;
    string hotel_rating;
    string hotel_location;
    int hotel_establish_year;
    int hotel_staff_quantity;
    int hotel_room_quantity;

public:
   
    void inputHotelDetails() {
        cout << "Enter Hotel ID: ";
        cin >> hotel_id;
        cin.ignore(); 

        cout << "Enter Hotel Name: ";
        getline(cin, hotel_name);

        cout << "Enter Hotel Type (e.g., Hotel or Motel): ";
        getline(cin, hotel_type);

        cout << "Enter Hotel Rating (e.g., 1 Star to 7 Star): ";
        getline(cin, hotel_rating);

        cout << "Enter Hotel Location (City): ";
        getline(cin, hotel_location);

        cout << "Enter Hotel Establishment Year: ";
        cin >> hotel_establish_year;

        cout << "Enter Number of Staff: ";
        cin >> hotel_staff_quantity;

        cout << "Enter Number of Rooms: ";
        cin >> hotel_room_quantity;

        cout << endl;
    }

  
    void displayHotelDetails() const {
        cout << "Hotel ID: " << hotel_id << endl;
        cout << "Hotel Name: " << hotel_name << endl;
        cout << "Hotel Type: " << hotel_type << endl;
        cout << "Hotel Rating: " << hotel_rating << endl;
        cout << "Hotel Location: " << hotel_location << endl;
        cout << "Establishment Year: " << hotel_establish_year << endl;
        cout << "Staff Quantity: " << hotel_staff_quantity << endl;
        cout << "Room Quantity: " << hotel_room_quantity << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of hotels: ";
    cin >> n;

    Hotel* hotels = new Hotel[n]; 

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for hotel " << (i + 1) << ":" << endl;
        hotels[i].inputHotelDetails();
    }

    cout << "\nDisplaying Hotel Information:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nHotel " << (i + 1) << ":\n";
        hotels[i].displayHotelDetails();
    }

    delete[] hotels; 

    return 0;
}

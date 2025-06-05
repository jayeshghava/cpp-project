
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class TimeConverter {
public:
    static string secondsToHHMMSS(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        stringstream ss;
        ss << hours << ":"
           << setw(2) << setfill('0') << minutes << ":"
           << setw(2) << setfill('0') << seconds;

        return ss.str();
    }


    static int HHMMSSToSeconds(const string& timeStr) {
        int hours, minutes, seconds;
        char sep1, sep2;

        stringstream ss(timeStr);
        ss >> hours >> sep1 >> minutes >> sep2 >> seconds;

        if (sep1 != ':' || sep2 != ':' || ss.fail()) {
            throw invalid_argument("Invalid time format. Use HH:MM:SS.");
        }

        return hours * 3600 + minutes * 60 + seconds;
    }
};


int main() {
    int choice;
    cout << "Choose conversion:\n1. Seconds to HH:MM:SS\n2. HH:MM:SS to Seconds\nEnter choice (1 or 2): ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        int seconds;
        cout << "Enter total seconds: ";
        cin >> seconds;
        string time = TimeConverter::secondsToHHMMSS(seconds);
        cout << "HH:MM:SS => " << time << endl;
    } else if (choice == 2) {
        string timeStr;
        cout << "Enter time in HH:MM:SS format: ";
        getline(cin, timeStr);
        try {
            int totalSeconds = TimeConverter::HHMMSSToSeconds(timeStr);
            cout << "Total seconds => " << totalSeconds << endl;
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
/*output
Choose conversion:
1. Seconds to HH:MM:SS
2. HH:MM:SS to Seconds
Enter choice (1 or 2): 1
Enter total seconds: 4500
HH:MM:SS => 1:15:00

Choose conversion:
1. Seconds to HH:MM:SS
2. HH:MM:SS to Seconds
Enter choice (1 or 2): 2
Enter time in HH:MM:SS format: 34:89:546
Total seconds => 128286
*/

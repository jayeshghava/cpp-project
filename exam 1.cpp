#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string genre;
    int releasedYear;

public:
 
    Movie() {
        title = "Unknown";
        genre = "Unknown";
        releasedYear = 0;
    }

    Movie(string t, string g, int y) {
        title = t;
        genre = g;
        releasedYear = y;
    }

    void display() const {
        cout << "Title: " << title << ", Genre: " << genre << ", Released Year: " << releasedYear << endl;
    }
};

int main() {
 
    Movie movies[3] = {
        Movie("Inception", "Sci-Fi", 2010),
        Movie("The Dark Knight", "Action", 2008),
        Movie("Interstellar", "Sci-Fi", 2014)
    };

    cout << "Movie List:" << endl;
    for (int i = 0; i < 3; i++) {
        movies[i].display();
    }

}
/*output
Movie List:
Title: Inception, Genre: Sci-Fi, Released Year: 2010
Title: The Dark Knight, Genre: Action, Released Year: 2008
Title: Interstellar, Genre: Sci-Fi, Released Year: 2014
*/

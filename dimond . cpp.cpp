#include <iostream>
#include <vector>
using namespace std;

class DiamondCompany {
private:
    int comp_id;
    string comp_name;
    int comp_staff_quantity;
    double comp_revenue;
    int comp_import_raw_diamonds;
    int comp_export_diamonds;
    string comp_ceo;

public:
    DiamondCompany(int id, string name, int staff, double revenue,
                   int import_raw, int export_dia, string ceo)
    {
        comp_id = id;
        comp_name = name;
        comp_staff_quantity = staff;
        comp_revenue = revenue;
        comp_import_raw_diamonds = import_raw;
        comp_export_diamonds = export_dia;
        comp_ceo = ceo;
    }

    void displayInfo() {
        cout << "\nCompany ID: " << comp_id << endl;
        cout << "Company Name: " << comp_name << endl;
        cout << "Staff Quantity: " << comp_staff_quantity << endl;
        cout << "Revenue (per year): $" << comp_revenue << " million" << endl;
        cout << "Raw Diamonds Imported (per year): " << comp_import_raw_diamonds << endl;
        cout << "Diamonds Exported (per year): " << comp_export_diamonds << endl;
        cout << "CEO: " << comp_ceo << endl;
    }
};

int main() {
    int N;
    cout << "Enter number of diamond companies: ";
    cin >> N;

    vector<DiamondCompany> companies;

    for (int i = 0; i < N; i++) {
        int id, staff, import_raw, export_dia;
        string name, ceo;
        double revenue;

        cout << "\nEnter details for company " << i + 1 << ":" << endl;
        cout << "Company ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Company Name: ";
        getline(cin, name);
        cout << "Number of Staff: ";
        cin >> staff;
        cout << "Revenue (in million USD per year): ";
        cin >> revenue;
        cout << "Raw Diamonds Imported per year: ";
        cin >> import_raw;
        cout << "Diamonds Exported per year: ";
        cin >> export_dia;
        cin.ignore();
        cout << "CEO Name: ";
        getline(cin, ceo);

        DiamondCompany company(id, name, staff, revenue, import_raw, export_dia, ceo);
        companies.push_back(company);
    }

    cout << "\n=== Diamond Companies Information ===" << endl;
    for (int i = 0; i < N; i++) {
        companies[i].displayInfo();
    }

}
/*output
Enter number of diamond companies: 1

Enter details for company 1:
Company ID: 101
Company Name: harikrishna diamond companu.ltd surat.
Number of Staff: 8000
Revenue (in million USD per year): 160000
Raw Diamonds Imported per year: 2300
Diamonds Exported per year: 50000
CEO Name: savjibhai dholkiya

=== Diamond Companies Information ===

Company ID: 101
Company Name: harikrishna diamond companu.ltd surat.
Staff Quantity: 8000
Revenue (per year): $160000 million
Raw Diamonds Imported (per year): 2300
Diamonds Exported (per year): 50000
CEO: savjibhai dholkiya
*/

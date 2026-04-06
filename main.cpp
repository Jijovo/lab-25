#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    //create a vector, a list, and a set using the codes.txt file, and measure the time taken for each in nanoseconds
    cout << "Starting Test..." << endl;
    //vector
    int vecRead;
    ifstream fin("codes.txt");
    vector<string> vec;
    list<string> lst;
    set<string> st;
    string code;
    auto start = chrono::high_resolution_clock::now();
    while (fin >> code) {
        vec.push_back(code);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    vecRead = duration.count();
    //list
    fin.close();
    fin.open("codes.txt");
    int lstRead;
    start = chrono::high_resolution_clock::now();
    while (fin >> code) {
        lst.push_back(code);
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    lstRead = duration.count();
    //set
    fin.close();
    fin.open("codes.txt");
    int stRead;
    start = chrono::high_resolution_clock::now();
    while (fin >> code) {
        st.insert(code);
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    stRead = duration.count();
    //test print
    cout << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << setw(10) << vecRead << setw(10) << lstRead << setw(10) << stRead << endl;
    return 0;
    
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
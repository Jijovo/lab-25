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
    fin.close();
    /*test print
    cout << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << setw(10) << vecRead << setw(10) << lstRead << setw(10) << stRead << endl;
    */
   //test sorting
   //vector
    int vecSort;
    start = chrono::high_resolution_clock::now();
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size() - 1; j++) {
            if(vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    vecSort = duration.count();
    //list
    int lstSort;
    start = chrono::high_resolution_clock::now();
    lst.sort();
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    lstSort = duration.count();
    //set
    int stSort;
    start = chrono::high_resolution_clock::now();
    end = chrono::high_resolution_clock::now(); //already sorted
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    stSort = duration.count();
    //print results
    cout << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << setw(10) << vecRead << setw(10) << lstRead << setw(10) << stRead << endl;
    cout << setw(10) << vecSort << setw(10) << lstSort << setw(10) << stSort << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
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
    /*print results
    cout << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << setw(10) << vecRead << setw(10) << lstRead << setw(10) << stRead << endl;
    cout << setw(10) << vecSort << setw(10) << lstSort << setw(10) << stSort << endl;
    */
   //test inserting "TESTCODE" in the middle of the vector and list, and in the set
   //vector
    int vecInsert;
    start = chrono::high_resolution_clock::now();
    vec.insert(vec.begin() + vec.size() / 2, "TESTCODE");
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    vecInsert = duration.count();
    //list
    int lstInsert;
    start = chrono::high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, lst.size() / 2);
    lst.insert(it, "TESTCODE");
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    lstInsert = duration.count();
    //set
    int stInsert;
    start = chrono::high_resolution_clock::now();
    st.insert("TESTCODE");
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    stInsert = duration.count();
    //test deleting the middle element of the vector and list, and "TESTCODE" from the set
    //vector
    int vecDelete;
    start = chrono::high_resolution_clock::now();
    vec.erase(vec.begin() + vec.size() / 2);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    vecDelete = duration.count();
    //list
    int lstDelete;
    start = chrono::high_resolution_clock::now();
    it = lst.begin();
    advance(it, lst.size() / 2);
    lst.erase(it);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    lstDelete = duration.count();
    //set
    int stDelete;
    start = chrono::high_resolution_clock::now();
    st.erase("TESTCODE");
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    stDelete = duration.count();
    //print results
    cout << setw(10) << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set" << endl;
    cout << setw(10) << "Read" << setw(15) << vecRead << setw(15) << lstRead << setw(15) << stRead << endl;
    cout << setw(10) << "Sort" << setw(15) << vecSort << setw(15) << lstSort << setw(15) << stSort << endl;
    cout << setw(10) << "Insert" << setw(15) << vecInsert << setw(15) << lstInsert << setw(15) << stInsert << endl;
    cout << setw(10) << "Delete" << setw(15) << vecDelete << setw(15) << lstDelete << setw(15) << stDelete << endl;
    
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
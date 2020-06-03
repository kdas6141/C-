/**
 * Test program to call the library functions defined in mgmt_lib
 */
#include <iostream>
#include <thread>
#include <chrono>
#include "mgmt_lib.hpp"
using namespace std;

int main() {
	mgmt_lib mlib;
    uint32_t id = 0;
	/* sample strings to test */
	string sample_string[] ={"abcassa",
                             "kljkl",
							 "defgh"};

    cout << "create_id("<<sample_string[0]<<") ->id " << mlib.create_id(sample_string[0]) << endl;
    cout << "create_id("<<sample_string[1]<<") ->id " << mlib.create_id(sample_string[1]) << endl;
    cout << "create_id("<<sample_string[0]<<") ->id " << mlib.create_id(sample_string[0]) << endl;
    cout << "delete_id(1)" << endl;
	mlib.delete_id(1);
	cout << "query_id(1)->" << mlib.query_id(1) << endl;
    cout << "delete_id(1)" << endl;
    mlib.delete_id(1);
    cout << "query_id(1)->" << mlib.query_id(1) << endl;
    cout << "create_id("<<sample_string[0]<<") ->id " << mlib.create_id(sample_string[0]) << endl;
    cout << "reuse id #1 after 1 sec:" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "create_id("<<sample_string[2]<<") ->id " << mlib.create_id(sample_string[2]) << endl;
    cout << "query_id(1)->" << mlib.query_id(1) << endl;

}

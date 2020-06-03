/**
 * This file will contain the class implemenation to get and 
 * return an unique id
 */
#include "mgmt_id.hpp"
#include <iostream>
using namespace std;
/**
 * Constructor will intilaze id to 1
 */
mgmt_id::mgmt_id () {
	id = 1;
}

/**
 * Destructor place holder
 */
mgmt_id::~mgmt_id () {
}

/**
 * return the id after deletion of the entry
 * in succes return 0 otherwise return -1
 */
int32_t mgmt_id::return_id(uint32_t &id) {
	struct ret_id_info rinfo = {id, std::chrono::system_clock::now()};

	ret_id.push(rinfo);

    return 0; 
}

/**
 * get id from the pool if sucess return 0 
 * otherwise return -1
 */
int32_t mgmt_id::get_id(uint32_t &new_id) {
	/* check if there is alreay returned id avilable to reuse*/
	if (!ret_id.empty()) {
		auto cur = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = cur - ret_id.front().cur_time;
        if (diff.count() >= MGMT_ID_MIN_FREEZE_TIME) {
			new_id = ret_id.front().id;
			ret_id.pop();
			return 0; 
		}
	}

	if (id < 0xFFFFFFFF) {
		new_id = id++;
        return 0;
	} else
		new_id = 0;
    return -1;
}

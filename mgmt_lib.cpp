/**
 * This file will contain all implemantation of all funnctions
 * related to mgmt library 
 */
#include <iostream>
#include "mgmt_lib.hpp" 
using namespace std;

/**
 * Place holder for constructor
 */
mgmt_lib::mgmt_lib() {
}

/**
 * Place holder for destructor
 */
mgmt_lib::~mgmt_lib() {
} 

/*
 * Private function to query a string using id
 */
string mgmt_lib::query_uint(uint32_t id) {
    string str=MGMT_LIB_QUERY_NOT_FOUND;
	unordered_map<uint32_t, string>::const_iterator got = umgmt_db.find (id);

  	if ((!umgmt_db.empty()) && (got != umgmt_db.end()))
    	str = got->second;

	return str;
}

/*
 * Private function to query an id from string
 */
uint32_t mgmt_lib::query_str(string str) {
    uint32_t id = 0;
    unordered_map<string , uint32_t>::const_iterator got = smgmt_db.find (str);

    if ((!smgmt_db.empty()) && (got != smgmt_db.end()))
    	id = got->second;

    return id;
}

/*
 * Private function to query number of occurance of an id
 */
uint32_t mgmt_lib::query_count(uint32_t id) {
    uint32_t count = 0;
    unordered_map<uint32_t, uint32_t>::const_iterator got = count_db.find (id);

    if ((!count_db.empty()) && (got != count_db.end()))
        count = got->second;

    return count;
}

/*
 * Public function to create an id for a string
 */
uint32_t mgmt_lib::create_id(string &str) {
	uint32_t id = 0;

	/* find if entry already exists */
    if ((id=query_str(str)) != 0) {
		/*increment counter */
		count_db[id]++;
		return id;	
    }

	/* get the next avilable id */
	if (mid.get_id(id) == -1) {
		cout << "Error in get id for: " << str << endl;
        return 0;
	}

	/* create a new entry */
	umgmt_db[id] = str;
    smgmt_db[str] = id;
    count_db[id] = 1;

	return id;	
}

/*
 * Public function to delete an id from the database
 */
void mgmt_lib::delete_id(uint32_t id) {
    string str = MGMT_LIB_QUERY_NOT_FOUND;

    /* find if entry already exists */
    if ((str=query_uint(id)) != MGMT_LIB_QUERY_NOT_FOUND) {
        /*decrement counter */
        count_db[id]--;

		if (count_db[id] == 0) {
			/* return the id to mgmt_id module and remove
 			 *  entries from database
			 */
			mid.return_id(id);
			count_db.erase(id);
			umgmt_db.erase(id);
			smgmt_db.erase(str);
		}
    } else
		cout << MGMT_LIB_QUERY_NOT_FOUND << endl; 
}

/*
 * Public function to query an id for the string in database
 */
string mgmt_lib::query_id(uint32_t id) {
    string str = MGMT_LIB_QUERY_NOT_FOUND;

    if ((str=query_uint(id)) != MGMT_LIB_QUERY_NOT_FOUND) {
		/* found the item */
		str = umgmt_db[id];
    }

	return str;		
}


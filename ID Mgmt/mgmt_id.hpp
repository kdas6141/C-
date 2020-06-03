#ifndef MGMT_ID_HPP
#define MGMT_ID_HPP
#include <cstdint>
#include <queue>
#include <chrono>
#define MGMT_ID_MIN_FREEZE_TIME 1.0 /* 1 sec */

/* return id structure will contain time of return and id */
struct ret_id_info {
	uint32_t id;
	std::chrono::time_point<std::chrono::system_clock> cur_time;
};

class mgmt_id {
	private:
	uint32_t id;
	std::queue<struct ret_id_info> ret_id;
	int find_return_id(uint32_t &id);

	public:
	mgmt_id();
    ~mgmt_id();
	int32_t get_id(uint32_t &id);
	int32_t return_id(uint32_t &id);
};
#endif

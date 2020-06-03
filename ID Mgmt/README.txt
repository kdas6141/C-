ID management library has been written in c++ because of its extensive STL class support.
For hashed database we used 3 unorded_map STL. For ID reutilization I used queue and chron timer.
Id can be reused if ID has been returned atleast 1 sec ago.

Some of the constraint in the design:
1. single threaded single user system. no locking between get id and delete id.
2. we considered arbitiary stream as string type data
3. id ranges from 1 to 4,294,967,295.

Here are the list of files:
mgmt_id.hpp (class deals unique id)
mgmt_id.cpp
mgmt_lib.hpp (class deals string and id management library)
mgmt_lib.cpp
test.cpp (test module to verify the features in mgmt_lib.cpp)
README.txt (description of the files and design details)

compilation command:
g++ -std=c++11 mgmt_id.cpp test.cpp mgmt_lib.cpp

execution command:
./a.out
It has been tested in linux:
Here is the output:
create_id(abcassa) ->id 1
create_id(kljkl) ->id 2
create_id(abcassa) ->id 1
delete_id(1)
query_id(1)->abcassa
delete_id(1)
query_id(1)->Not Exists
create_id(abcassa) ->id 3
reuse id #1 after 1 sec:
create_id(defgh) ->id 1
query_id(1)->defgh


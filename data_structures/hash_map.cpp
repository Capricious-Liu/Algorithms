// hash map
// same usage as map.
#include "hash_map"
#include "string"

using namespace std;

void test_hash_map(){
	hash_map<int, string> mymap;
	mymap[9527] = "ÌÆ²®»¢";

}

void hash_map_main(){
	test_hash_map();
}
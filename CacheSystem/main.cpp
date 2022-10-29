#include"Cache.cpp"
#include "HashMapStorage.cpp"
#include "LRUPolicy.cpp"

int main(){
    Cache * cache = new Cache(4, new HashMapStorage(), new LRUPolicy());
    cache->put("test1", 1);
    cache->put("test2", 2);
    cache->put("test3", 3);
    cache->get("test3");
    cache->put("test4", 4);
    // Adding 5th items, which is more than max size 4.
    // Evition policy will remove least recent used, which is "test1".
    cache->put("test5", 5);
    //As test1 is removed so "test1" will not available in cache.
    cache->get("test1");
    cache->get("test2");
    return 1;

}
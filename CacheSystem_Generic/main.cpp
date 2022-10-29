#include"Cache_Generic.cpp"
#include "HashMapStorage.cpp"
#include "LRUPolicy.cpp"

int main(){
    cout<<"Store key as string and value as int."<<endl;
    Cache<string, int> * cache = new Cache<string, int>(4, new HashMapStorage<string, int>(), new LRUPolicy<string>());
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

    cout<<"Store key as string and value as string."<<endl;
    Cache<string, string> * cache1 = new Cache<string, string>(4, new HashMapStorage<string, string>(), new LRUPolicy<string>());
    cache1->put("test1", "1");
    cache1->put("test2", "2");
    cache1->put("test3", "3");
    cache1->get("test3");
    cache1->put("test4", "4");
    // Adding 5th items, which is more than max size 4.
    // Evition policy will remove least recent used, which is "test1".
    cache1->put("test5", "5");
    //As test1 is removed so "test1" will not available in cache.
    cache1->get("test1");
    cache1->get("test2");

    return 1;

}
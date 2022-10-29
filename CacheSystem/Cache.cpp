# include"IStorage.h"
# include "IEvictionPolicy.h"
#include<unordered_map>
#include<exception>

using namespace std;

class Cache{
    private:
      IStorage * storage;
      IEvictionPolicy *policy;
      int maxSize;
      int currentSize;
    public:
        Cache(int maxsize, IStorage* st, IEvictionPolicy* p){
            maxSize = maxsize;
            currentSize = 0;
            this->storage = st;
            this->policy = p;
        } 
        ~Cache()
        {
            if(storage != NULL)
                delete storage;
            if(policy != NULL)
                delete policy;
        }
        void put(string key, int value){
            if(currentSize == maxSize){
                string removeKey = policy->evict();
                storage->remove(removeKey);
                currentSize -= 1;
            }
            storage->add(key, value);
            policy->keyAccessed(key);
            currentSize += 1;

        }
        void get(string key){
            try{
                int value = storage->get(key);
                policy->keyAccessed(key);
                cout<<"Value of key "<<key<<" = "<<value<<endl;
            }
            catch(exception ex){
                cout<<key<<" Key is not available in cache"<<endl;
            }
            
        }
};
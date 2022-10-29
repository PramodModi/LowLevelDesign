# include"IStorage.h"
# include "IEvictionPolicy.h"
#include<unordered_map>
#include<exception>

using namespace std;
template<class T1, class T2>
class Cache{
    private:
      IStorage<T1, T2> * storage;
      IEvictionPolicy<T1> *policy;
      int maxSize;
      int currentSize;
    public:
        Cache(int maxsize, IStorage<T1, T2>* st, IEvictionPolicy<T1>* p){
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
        void put(T1 key, T2 value){
            if(currentSize == maxSize){
                T1 removeKey = policy->evict();
                storage->remove(removeKey);
                currentSize -= 1;
            }
            storage->add(key, value);
            policy->keyAccessed(key);
            currentSize += 1;

        }
        void get(T1 key){
            try{
                T2 value = storage->get(key);
                policy->keyAccessed(key);
                cout<<"Value of key "<<key<<" = "<<value<<endl;

                }
            catch(exception ex){
                cout<<key<<" key is not available in cache"<<endl;
            }
        }
            
        
};
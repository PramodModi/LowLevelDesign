Low level Design for Cache system.
Requirements:
1. It should support below two operations for client.
  a. Put: User should able to put value against a key. User will pass key and value to be stored in Cache.
  b. Get: User should able to get the prevously stored value in cache against a key. User will pass key as a parameter and get stored value for that key.
2. It should able to support Eveiction policy.
3. Code should be extensible and scalable.
4. Client can choose to have different eviction policy and storage mechanism during instatiating cache class.

Aproach:
  From requirements, it is clear that, following classes are needed:
  
  class:
  1. Cache
  2. Storage
  3. EvictionPolicy

Also as eviction policy and storage can be changed. Hence will keep interface for both.

4. IStorage (interface)
5. IEvictionPolicy(Interface)

This code is written for LRU eviction policy and HashMap based storage.

So, will have following classes:
1. IStorage
2. IEveictionPolicy
3. HashMapStorage
4. LRUPolicy
5. Cache

As you are aware, for LRU cache, we need doubly linked list. So, will have two more classes.
6. DoublyLinkedList
7. Node

This is a Generic code for Key and Value.

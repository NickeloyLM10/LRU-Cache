#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

//Node to store the data (Linked List)
class Node{
public:
    string key;
    int value;
    Node(string key, int value){
        this->key = key;
        this->value = value;
    }
};

//LRU Cache Data Structure
class LRUCache{
public:
    int maxSize;
    list<Node> l;
    unordered_map<string , list<Node>::iterator> mp;

    LRUCache(int maxSize){
        this->maxSize = maxSize > 1 ? maxSize : 1;
    }

    void insertKeyValue(string key , int value){
        //2 cases
        if(mp.count(key) != 0){
            //replace the old value and update
            auto it = mp[key];
            it->value = value;
        }
        else{
            //check if cache is full or not
            //delete least recently used item from cache
            if(l.size() == maxSize){
                Node last = l.back();
                mp.erase(last.key); // remove from hashmap
                l.pop_back(); // remove from linked list 
            }

            Node n(key , value);
            l.push_front(n);
            mp[key] = l.begin();
        }
    }

    int* getValue(string key){
        if(mp.count(key) != 0){
            auto it = mp[key];
            int value = it->value;  
            l.push_front(*it);
            l.erase(it);
            mp[key] = l.begin();
            return &l.begin()->value;  // int the cache every key may not be present
        }

        return NULL;
    }

    string mostRecentKey(){
        return l.front().key;
    }

};

int main(){
    LRUCache lru(3);
    lru.insertKeyValue("mango" , 10);
    lru.insertKeyValue("orange" , 20);
    lru.insertKeyValue("apple" , 30);
    cout<<lru.mostRecentKey()<<endl;

    lru.insertKeyValue("mango" , 40);
    cout<<lru.mostRecentKey()<<endl;

    int *order = lru.getValue("mango");
    if(order != NULL){
        cout<<"order of mango is "<<*order<<endl;
    }

    lru.insertKeyValue("banana" , 20);

    if(lru.getValue("orange") == NULL){
        cout<<"orange doesn't exist";
    }

    if(lru.getValue("apple") == NULL){
        cout<<"apple doesn't exist";
    }

    if(lru.getValue("banana") == NULL){
        cout<<"banana doesn't exist";
    }

    if(lru.getValue("mango") == NULL){
        cout<<"mango doesn't exist";
    }


}
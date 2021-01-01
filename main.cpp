#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#include <queue>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#define ll long long

using namespace std;

typedef struct Node {
    string key;
    int value{};
    struct Node * left{};
    struct Node * right{};
}doubly;


class myHashStrKey{

private:
    int currentCount;
    int hashsize; // Default n = 2000. So 701 slots will be initialized.
    vector<doubly *> table;

//hash function taken from net and modified.
    size_t hash(const std::string& data) const {
        size_t h(0);
        for (int i=0; i<data.length(); i++){
            h = (h << (31-i) ^ (h >> i) ^ data[i]);
        }
        h = h%hashsize;
        return h;
    }

//Inserts the key and value. If the key is already present, the value is updated.
//Checks if the currentCount < (hashsize+1)*3
    void insertNode(doubly ** root, int Value, const string& Key){

        if(*root ==NULL){
            if(myHashStrKey::currentCount >= ((hashsize+1)*3))
                return;
            auto * newNode = new doubly();
            newNode->value = Value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->key = (Key);
            *root = newNode;
            myHashStrKey::currentCount++;
            return;
        }

        doubly * prev = nullptr;
        doubly * current = *root;
        while(current != nullptr && ((current)->key).compare(Key)){
            prev = current;
            current = current->right;
        }

        if(current ==NULL){
            if(myHashStrKey::currentCount >= ((hashsize+1)*3))
                return;
            doubly *newNode = new doubly();
            newNode->value = Value;
            newNode->key = Key;
            newNode->left = prev;
            newNode->right = NULL;
            prev->right = newNode;
            myHashStrKey::currentCount++;
        }
        else{
            (current)->value = Value;
        }
    }

//Return the corresponding value for the given key from the table
    int getNodeValue(doubly * root, string key){
        while(root != NULL){
            if(!key.compare(root->key)){
                return root->value;
            }
            root = root->right;
        }
        return -1;
    }

//Removes the node from bucket if present and reduces the currentcount
//else nothing.
    void removeNode(doubly ** root, string Key){
        doubly * toRemove;
        doubly * head = *root;

        //Check to see if the first element is the target.
        if((head != NULL) &&!(head->key).compare(Key)){
            toRemove = head;
            *root = head->right;
            if(head->right != NULL)
                head->right->left = NULL;
            delete toRemove;
            myHashStrKey::currentCount--;
            return;
        }
            //First element is not the target.
        else{
            if(head == NULL)
                return;

            while((head != NULL) &&(head->key).compare(Key)){
                head = head->right;
            }
            //Element not present. return
            if(head == NULL)
                return;

            //Element found. Remove the element and decrement currentCount.
            toRemove = head;

            head->left->right = head->right;
            if(head->right !=NULL)
                head->right->left = head->left;

            myHashStrKey::currentCount--;
            delete toRemove;
            return;
        }
    }

public:
//Constructor for default size.
//I am considering that hash table size to have default value of 701.
//The average elements per bucket is 3.
//THe total allowed elements will be 701*3 i.e. tablesize*3.
    myHashStrKey(){
        myHashStrKey::currentCount=0;
        myHashStrKey::hashsize = 701;
        myHashStrKey::table.insert(myHashStrKey::table.begin(),hashsize,((doubly *)NULL));
    }

//Constructor for the user given size
//Hashsize is calculated to be size/3 +1 (average elements per bucket is 3)
    myHashStrKey(int size){
        myHashStrKey::currentCount=0;
        myHashStrKey::hashsize = size/3 +1;
        myHashStrKey::table.insert(myHashStrKey::table.begin(),hashsize,((doubly *)NULL));
    }


//Adds entry to the HashMap
    void addKeyValue(const string &key,int value ){
        size_t keyHash = hash(key);
        insertNode(&(table[keyHash]), value, key);
    }

//Gets the corresponding value for the key if present else nothing
    int getValue(const string &key ){
        size_t keyHash = hash(key);
        int result = getNodeValue(table[keyHash],key);
        return result;
    }

//Deletes the key if present else nothing.
    void deleteKey(const string &key){
        size_t keyHash = hash(key);
        removeNode(&(table[keyHash]),key);
    }
};




class Store {
public:
    void createFile();
    void readFile();
    void deleteFile();
    void writeFile();
    Store(){

    }
};

void Store::createFile(){
    fstream file;

    file.open(R"(C:\User\Vikrant\Desktop\Key-Value-Pair.txt)",ios::out);

    if(!file){
        cout<<"Error while creating the file";
        return;
    }else{
        cout<<"File Created Successfully"<<endl;
        file.close();
    }

}
void Store::writeFile(){

    string name;
    int value;
    while (true){
        cout<<"Enter the String :-";
        getline(cin,name);
        //stringstream myname(name);
        if(name.size() < 32){
            break;
        }
        cout<<"Enter the valid string of length less than 32 characters";
    }
    cin>>value;

}

void Store::readFile(){
    cout<<"Enter the key to ready the value";

}

void Store::deleteFile(){
    cout<<"Enter the key to delete the value";
}


int main()
{
    Store first;

    cout<<"Key-Value Storage"<<endl;
    int choice;
    //bool term = true;
    cout<<"1. Create \n 2.Write \n 3. Read \n 4. Delete 5. End"<<endl;
    cin>>choice;

    switch (choice) {

        case 1: cout<<"Create a New File"<<endl;
                first.createFile();
                break;
        case 2: cout<<"Write on a File"<<endl;
                first.writeFile();
                break;
        case 3: cout<<"Read from New File"<<endl;
                first.readFile();
                break;
        case 4: cout<<"Delete a Value"<<endl;
                first.deleteFile();
                break;
        case 5: cout<<"End of the program"<<endl;
                break;

    }



    return 0;
}



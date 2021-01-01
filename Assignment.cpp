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




#include<iostream>
#include<fstream>
#include<chrono>
#include<ctime>
#include<string>

using namespace std;

string secure(string line, int key){
    string secured="";
    for(int i=0; line[i]!='\0';i++){
        secured+=char(int(line[i])^key);
    }
    return secured;
}

int main(){
    int choice;
    string username,line;
    int key;
    do{
        cout<<"\n1.Write into file.";
        cout<<"\n2.Read from file.";
        cout<<"\n0.Exit.";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice){
            case 1:
            {
                cout<<"\nEnter Username: ";
                cin>>username;
                //file opening and checking and writing
                ofstream outFile(username+".txt",ios::app);
                if(!outFile.is_open()){
                    cerr << "\nFile "<< username << ".txt" <<" doesn't exist and Creating new file."<< endl;
                    return 1;
                }else{
                    cout << "\nFile "<< username << ".txt" <<" successfully opened."<< endl;
                }
                cout<<"\nEnter Key: ";
                cin>>key;
                cin.ignore();
                while(true){
                     // Get the current time point
                    auto now = chrono::system_clock::now();

                     // Convert to time_t for use with ctime
                    time_t now_time = chrono::system_clock::to_time_t(now);

                    cout<<"\nEnter line: ";
                    getline(cin,line);
                    outFile<<secure(ctime(&now_time),key)<<endl;

                    if(line=="QUIT"){
                        cout<<"\nDiary Entry Saved Successfully."<<endl;
                        break;
                    }else{
                        outFile<<secure(line,key)<<endl;
                    }
                }
                outFile.close();
                break;
            }
            case 2:
            {
                //reading file
                cout<<"\nEnter Username: ";
                cin>>username;
                //file opening and checking and reading
                ifstream inFile(username+".txt");
                if(!inFile.is_open()){
                    cerr << "\nFile "<< username << ".txt" <<" doesn't exist."<< endl;
                    return 1;
                }else{
                    cout << "\nFile "<< username << ".txt" <<" successfully opened."<< endl;
                    cout<<"\nEnter Key: ";
                    cin>>key;
                    string data;
                    while(getline(inFile,data)){
                        cout<<secure(data,key)<<endl;
                    }
                }
                inFile.close();
                break;
            }
            case 0:
                cout<<"\nThank You....";
                break;
        
            default:
                cout<<"\nInvalid Choice....";
                break;
        }
    }while(choice!=0);
}



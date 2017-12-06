#include <iostream>
#include <sstream>
#include "forest.hpp"
int main(int argc, const char * argv[]) {
    Forest prog;
    bool loop = true;
    while(loop){
        string input = "";
        getline(cin,input);
        vector<string> result;
        istringstream iss(input);
        for(string s; iss >> s;)
            result.push_back(s);
        if(!result.empty()){
            input = result.front();
            if(input == "BID"){
                if(result.size()==4){
                    prog.bid(stoi(result[1]),stoi(result[2]),stoi(result[3]));
                }else{
                    cout<<"invalid input"<<endl;
                }
            }else if(input == "MANDATORY"){
                if(result.size()==4){
                    prog.mandatory(stoi(result[1]),stoi(result[2]),stoi(result[3]));
                }else{
                    cout<<"invalid input"<<endl;
                }
            }else if(input == "SHORTEST_PATH?"){
                if(result.size()==3){
                    prog.shortestPath(stoi(result[1]),stoi(result[2]));
                }else{
                    cout<<"invalid input"<<endl;
                }
            }else if(input == "COST?"){
                cout<<prog.getCost()<<endl;
            }else if(input == "COMPONENTS?"){
                cout<<prog.getComponent()<<endl;
            }else if(input == "CYCLE?"){
                if(prog.getCycle())
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }else if(input == "LIST?"){
                prog.getList();
            }else if(input == "END"){
                loop = false;
            }else{
                cout<<"invalid input"<<endl;
            }
        }
    }
    return 0;
}

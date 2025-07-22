#include"social.h"


    enum currentState{Action,showPost,PostInteraction};
    void displayAction(Network &object) {
        cout<<"---------Main_Actions---------\n";
        cout<<"1. Sign in\n";
        cout<<"2. Add Friend\n";
        cout<<"3. Remove Friend\n";
        cout<<"4. Show Friend List\n";
        cout<<"5. Add Post\n";
        cout<<"6. Remove Post\n";
        cout<<"7. Show Post List\n";
        cout<<"8. Access Post";
        cout<<"9. Show Newsfeed\n";
        cout<<"10.Quit";
        cout<<"-------------------------------\n";
        int act = 0;
        do{
            cout<<"Action: "; 
            cin>>act;
        }while(act < 1 || act > 10); 
        
        switch(act){
            case 1:
                signIn(object);
                break;
            case 2:

        }
            
    }

    void signIn(Network &object){
        string name;
        string pwd;
        cout<<"Enter your user name: "; cin>>name;
        cout<<"Enter your password: "; cin>>pwd;
        object.signIn(name,pwd);
    }
    void addFriend(Network &object){
        string name;
        cout<<"Enter your friend's name: "; cin>>name;
        object.addFriend(name);
    }


int main(){
    Network fb;
    bool running = true;
    while(running){
        displayAction(fb);
    }
}
#include"social.h"

bool running = true;

void signUp(Network &object){
    string name;
    string pwd;
    getline(cin,name);
    cout<<"Enter your user name: "; getline(cin,name);
    cout<<"Enter your password: "; getline(cin,pwd);
    object.signUp(name,pwd);
}
void signIn(Network &object){
    string name;
    string pwd;
    getline(cin,name);
    cout<<"Enter your user name: "; getline(cin,name);
    cout<<"Enter your password: "; getline(cin,pwd); 
    object.signIn(name,pwd);
}
void addFriend(Network &object){
    string name;
    getline(cin,name);
    cout<<"Enter your friend's name: "; getline(cin,name);
    object.addFriend(name);
}
void removeFriend(Network &object){
    string name;
    getline(cin,name);
    cout<<"Enter your friend's name: "; getline(cin,name);
    object.removeFriend(name);
}
void showFriendList (Network &object) {
    object.showFriendList();
}
void addPost(Network &object){
    string content;
    getline(cin,content);
    cout<<"What do you want to share: "; getline(cin,content);
    object.addPost(content);
}
void removePost(Network &object) {
    int id;
    cout<<"Post ID: "; cin>>id;
    object.removePost(id);
}
void showPostList(Network &object) {
    object.showPostList();
}
void accessPost(Network &object) {
    int id;
    cout<<"Post ID:"; cin>>id;
    object.accessPost(id);
}
void showNewsfeed(Network &object) {
    object.showNewsfeed();
}
void likePost(Network &object) {
    object.likePost();
}
void displayAction(Network &object) {
    cout<<"\n\n\n";
    cout<<"User: "<<object.getCurrentUserName()<<"     "<<"Post: "<<object.getCurrentPostId()<<"\n";
    cout<<"---------Main_Actions---------\n";
    cout<<"1.  Sign up\n";
    cout<<"2.  Sign in\n";
    cout<<"3.  Add Friend\n";
    cout<<"4.  Remove Friend\n";
    cout<<"5.  Show Friend List\n";
    cout<<"6.  Add Post\n";
    cout<<"7.  Remove Post\n";
    cout<<"8.  Show Post List\n";
    cout<<"9.  Access Post\n";
    cout<<"10. Show Newsfeed\n";
    cout<<"11. Like Post\n";
    cout<<"12. Quit\n";
    cout<<"-------------------------------\n";
    int act = 0;
    do{
        cout<<"Action: "; 
        cin>>act;
    }while(act < 1 || act > 12); 
    
    switch(act){
        case 1:
            signUp(object);
            break;
        case 2:
            signIn(object);
            break;
        case 3:
            addFriend(object);
            break;
        case 4: 
            removeFriend(object);
            break;
        case 5: 
            showFriendList(object);
            break;
        case 6:
            addPost(object);
            break;
        case 7: 
            removePost(object);
            break;
        case 8: 
            showPostList(object);
            break;
        case 9:
            accessPost(object);
            break;
        case 10:
            showNewsfeed(object);
            break;
        case 11:
            
        case 12:
            running = false;
            break;
    }
        
}
    


int main(){
    Network fb;
    while(running){
        displayAction(fb);
    }
}
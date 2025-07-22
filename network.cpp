#include "social.h"

Network::Network(){
    currentAccount = nullptr;
    currentPost = nullptr;
}

User* Network::searchUserByUserName(string username) {
    for(int i = 0; i < users.size(); i++) {
        if(username == users.at(i)->getUserName())
            return users.at(i);
    }
    return nullptr;
}
void Network::signUp(string name, string pwd) {
    User* check = searchUserByUserName(name);
    if(check)  {
        cout << "Username chosen. Please choose another username.\n";
        return;
    }
    User* newUser = new User(name,pwd);
    users.push_back(newUser);
    cout<<"Sign up successfully!\n";
}
void Network::signIn(string name, string pwd){
    User* check = searchUserByUserName(name);
    if(!check)  {
        cout << "Sign in unsuccessfully. User not exist!\n";
        return;
    }
    if(check->authorize(name,pwd)){
        currentAccount = check;
        currentPost = nullptr;
        cout<<"Sign in successfully!\n";
    } else {
        cout<<"Sign in successfully. Incorrect!\n";
    }
}

bool Network::isSignedIn() {
    if(currentAccount)
        return true;
    else {
        cout<<"Not sign in yet!";
        return false;
    }
}

void Network::addFriend(string username) {
    User* friendAccount = searchUserByUserName(username);
    if(!friendAccount) {
        cout<<"Friend not found!\n"; 
        return;
    }
    if(isSignedIn())
        currentAccount->addFriend(friendAccount);
}

void Network::removeFriend(string username) {
    User* friendAccount = searchUserByUserName(username);
    if(!friendAccount) {
        cout<<"Friend not found!\n"; 
        return;
    }
    currentAccount->removeFriend(friendAccount);
}

void Network::showFriendList(){
    if(isSignedIn()) {
        cout<<"You have "<<currentAccount->getFriendList().size()<<" friends:\n";
        for(User* user : currentAccount->getFriendList()){
            cout<<"+) "<<user->getUserName()<<endl;
        }
    }
}

void Network::addPost(string content){
    if(isSignedIn()){
        Post* newPost = currentAccount->addPost(currentAccount->getUserName(),content);
        posts.push_back(newPost);
    }
}

void Network::removePost(int postId){
    if(isSignedIn()){
        currentAccount->removePost(postId);
    }
}

void Network::showPostList(){
    if(isSignedIn()) {
        cout<<"You have "<<currentAccount->getPostList().size()<<" posts:\n";
        for(Post* post : currentAccount->getPostList()){
            post->showPost();
        }
    }
}

void Network::accessPost(int postId){
    if(isSignedIn()) {
        for(Post* post : posts){
            if(post->getPostId() == postId){
                currentPost = post;
            }
        }
    }
}

void Network::likePost(){
    if(currentPost)
        currentPost->like();
    else
        cout<<"Not access post yet\n";
}

void Network::showNewsfeed(){
    if(isSignedIn()) {
        cout<<"==================This is your newsfeed==================\n";
        for(User* user : currentAccount->getFriendList()){
            for(Post* post : user->getPostList()){
                post->showPost();
            }
        }
    }
}
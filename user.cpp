#include "social.h"

//*************************
// static int userId;     *
// string userName;       *
// string password;       *
// vector<User*> friends; *
// vector<Post*> posts;   *
//*************************

int User::userIdCounter = 0;
User::User() : userName(""), password(""), userId(++userIdCounter){}

User::User(string username, string password) {
    this->userId   = ++userIdCounter;
    this->userName = username;
    this->password = password;
}

User::User(const User& other) {
    userId = ++userIdCounter;
    userName = other.userName;
    password = other.password;
    for(User* mate : other.friends) {
        friends.push_back(mate);
    }
}

User::~User(){}

bool User::authorize(string name, string key) {
    return (name == userName)&&(key == password);
}

bool User::isFriend(User* Friend) {
    for (User* mate : getFriendList()) {
        if(Friend == mate)
            return true;
    }
    return false;
}
void User::addFriend(User* newFriend) {
    if(isFriend(newFriend)) {
        cout << "You and " << newFriend->getUserName() << "are already friends.\n";
        return;
    }
    this->friends.push_back(newFriend);
    cout << "You made a new friend.\n";
}
void User::removeFriend(User* aFriend) {
    for(int i = 0; i < getFriendList().size(); i++) {
        User* mate = this->friends.at(i);
        if(mate == aFriend) {
            this->friends.erase(this->friends.begin()+i);
            cout << "You and " << aFriend->getUserName() << " are not friends.\n";
            return;
        }
    }
    cout<<"Friend not found!\n";
}
vector<User*> User::getFriendList() const {
    return this->friends;
}
string User::getUserName() const {
    return this->userName;
}
int User::getUserId() const {
    return this->userId;
}

Post* User::addPost(string author, string content){
    Post* thePost = new Post(author,content);
    posts.push_back(thePost);
    cout<<"Add post successfully\n";
    return thePost;
}
void User::removePost(int postId){
    int n = posts.size();
    for(int i = 0; i < n; i++){
        if(posts[i]->getPostId() == postId){
            delete posts[i];
            posts.erase(posts.begin()+i);
            cout<<"Remove post successfully\n";
            return;
        }
    }
    cout<<"Post ID not found\n";
}
vector<Post*> User::getPostList() const {
    return this->posts;
}



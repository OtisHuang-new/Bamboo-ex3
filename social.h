#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Date {
private:
    int* day;
    int* month;
    int* year;
    int* hour;
    int* minute;
public:
    Date();
    Date(int day, int month, int year, int hour, int minute);
    Date(const string& dateStr); // "dd-MM-yyyy hh:mm"
    Date(const Date& other);
    Date& operator=(const Date& other);
    ~Date();
    friend istream& operator >> (istream& in, Date& date);
    friend ostream& operator << (ostream& out, const Date& date);
    void readFromFile(ifstream& fin);
    void writeToFile(ofstream& fout) const;
    bool isLeapYear();
    void Validate();
    void addMinutes(int minutes);
};

class Post {
private:
    static int postIdCounter;
    int postId;
    string authorName;
    bool ispublic;
    int reactions;
    int shares;
    Date timestamp;
    string content;
public:
    Post();
    Post(string authorName, string content);
    Post(const Post& other);
    ~Post();

    void showPost();
    int getPostId();
    void addComment();
    void like();
};

class User {
private:
    static int userIdCounter;
    int userId;
    string userName;
    string password;
    vector<User*> friends;
    vector<Post*> posts;
public:
    User();
    User(string userName, string password);
    User(const User &other);
    ~User();

    bool authorize(string name, string key);
    string getUserName() const;
    int getUserId() const;
    void addFriend(User* newFriend);
    void removeFriend(User* aFriend);
    vector<User*> getFriendList() const;
    bool isFriend(User* Friend);
    Post* addPost(string author, string content);
    void removePost(int postId);
    vector<Post*> getPostList() const;
};

class Network {
    private:
        vector<User*> users;
        vector<Post*> posts;
        User* currentAccount;
        Post* currentPost;
    public:
        Network();
        string getCurrentUserName() const;
        string getCurrentPostId() const;
        User* searchUserByUserName(string name);
        void signUp(string name, string pwd);
        void signIn(string name, string pwd);
        bool isSignedIn();
        void addFriend(string name);
        void removeFriend(string name);
        void showFriendList();
        void addPost(string content);
        void removePost(int postId);
        void showPostList();
        void accessPost(int postId);
        void likePost();
        void showNewsfeed();
};
#include <iostream>
#include<vector>
using namespace std;


class User {
private:
    static int userId;
    string userName;
    string password;
    vector<User*> friends;
    //vector<Post*> posts;
    //vector<Post*> newsFeed;
public:
    User();
    User(string userName, string password);
    User(const User &other);
    ~User();


    void addFriend(User* newFriend);
    void removeFriend(User* aFriend);
    vector<User*> getFriendList() const;
    void addPost(Post* newPost);
    void removePost(Post* aPost);
    vector<Post*> postList() const;
    //void getNewsfeed();

};

class Post {
private:
    int postID;
    int authorID;
    //vector<Comment*> commentList;
public:
    int reaction;
    int shares;
    Date timestamp;
    string content;

    Post(int authorID, string content);
    ~Post();

    void showPost();
    //void addComment();
    //void removeCommnent()
    //void getCommentList
};

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

class Comment {
private:
    int commentID;
    int postID;
    int commenterID;
public:
    Date timestamp;
    string content;

    Comment(int postID, int commentorID, string content);
    ~Comment();

    void showPost();
};

class UserManager {
    private:
        vector<User*> users;

};
#include "social.h"

// -postId:int
// -authorId:int
// -ispublic: bool
// -reactions:int
// -timestamp:Date
// -content:string

int Post::postIdCounter = 0;

Post::Post() {
    postId = ++postIdCounter;
    authorName = "Unknown";
    ispublic = true;
    reactions = 0;
    timestamp = Date();
    content = "";
};
Post::Post(string authorName, string content) {
    postId = ++postIdCounter;
    this->authorName = authorName;
    ispublic = 1;
    reactions = 0;
    timestamp = Date();
    this->content = content;
};
Post::Post(const Post& other) {
    postId = ++postIdCounter;
    authorName = other.authorName;
    ispublic = other.ispublic;
    reactions = other.reactions;
    timestamp = other.timestamp;
    content = other.content;
};
void Post::showPost() {
    cout<<"---------------------------Post_ID_"<<postId<<"-------------------------------------\n";
    cout<<"Author: "<<authorName<<setw(20)
        <<"Accessibility: "<< (ispublic ? "public" : "private")<<setw(20)
        <<"Created at: "<<this->timestamp;
    cout<<"    "<<content<<"\n";
    cout<<reactions<<" Likes"<<"\n";
    cout<<"-------------------------------------------------------------------------\n";
}

int Post::getPostId() {return this->postId;}

void Post::like() {reactions++;}

Post::~Post() {

};

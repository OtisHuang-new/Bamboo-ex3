#include "social.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// -postId:int
// -authorId:int
// -ispublic: bool
// -reactions:int
// -timestamp:Date
// -content:string

Post::Post() {
    postId++;
    authorId = 0;
    ispublic = 1;
    reactions = 0;
    timestamp = Date();
    content = "";
};
Post::Post(int authorId, string content) {
    postId++;
    this->authorId = authorId;
    ispublic = 1;
    reactions = 0;
    timestamp = Date();
    this->content = content;
};
Post::Post(const Post& other) {
    postId++;
    authorId = other.authorId;
    ispublic = other.ispublic;
    reactions = other.reactions;
    timestamp = other.timestamp;
    content = other.content;
};
void Post::showPost() {
    cout<<"Author: "<<authorId<<"; ";
    cout<<"Accessibility: "<<ispublic ? "public; " : "private; ";
    cout<<"Created at: "<<timestamp<<"\n";
    cout<<content<<"\n";
    cout<<reactions<<"\n";
}

Post::~Post() {

};


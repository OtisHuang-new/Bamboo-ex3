//#include "social.h"

// -postId:int
// -authorId:int
// -ispublic: bool
// -reactions:int
// -timestamp:Date
// -content:string

int Post::postIdCounter = 0;

Post::Post() {
    postId = ++postIdCounter;
    authorId = 0;
    ispublic = true;
    reactions = 0;
    timestamp = Date();
    content = "";
};
Post::Post(int authorId, string content) {
    postId = ++postIdCounter;
    this->authorId = authorId;
    ispublic = 1;
    reactions = 0;
    timestamp = Date();
    this->content = content;
};
Post::Post(const Post& other) {
    postId = ++postIdCounter;
    authorId = other.authorId;
    ispublic = other.ispublic;
    reactions = other.reactions;
    timestamp = other.timestamp;
    content = other.content;
};
void Post::showPost() {
    cout<<"------------------------------------------------------------------------\n";
    cout<<"Author: "<<authorId<<setw(20)
        <<"Accessibility: "<< (ispublic ? "public" : "private")<<setw(20)
        <<"Created at: "<<this->timestamp;
    cout<<"    "<<content<<"\n";
    cout<<reactions<<" Likes"<<"\n";
    cout<<"------------------------------------------------------------------------\n";
}
void Post::like() {
    reactions++;
}
void Post::addComment() {

}
Post::~Post() {

};

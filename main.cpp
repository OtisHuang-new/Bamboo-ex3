#include"social.h"

int main(){
    Network fb;
    fb.signUp("minh","abc");
    fb.signIn("minh","ab");
    fb.signUp("bao","1234");
    fb.addFriend("bao");
}
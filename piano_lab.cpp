#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <map>
#include <cassert>
#include "disk.h"
#include "thread.h"

using std::cout;
using std::endl;


/* given helper functions and variables */
enum Note { na = 0, d0 = 1, re = 2, mi = 3, fa = 4, sol = 5, la = 6, ti = 7};
std::string notes_str[] = {"empty", "do", "re", "mi", "fa", "sol", "la", "ti"};

// this is the wait condition
Note current_note = na;
mutex conductorMutex;
mutex noteMutex;
cv conductorCV;
cv pianoCV;

void play(Note i){
    assert(i != na);
    cout << notes_str[i] << endl;
}

/* Add global variables and helper functions here */


void conductor(){
    std::ifstream infile("input.txt");
    //reads from filestream
    int note;
    while (infile >> note) {


    } 
    // play the notes coming in
    // ensure you are not playing the same note at the same time
    /* implement here */
}

void pianoKey(Note i){
    /* implement here */
}

/* more given helper functions for thread setup*/
void pianoKeyWrapper(void* note){
    Note i = (Note)(intptr_t) note;
    while(true){
        pianoKey(i);
    }
}

void manageThreads(){
    for(intptr_t i = 1; i<=7; ++i){
        thread((thread_startfunc_t)pianoKeyWrapper, (void*) i);
    }
    thread((thread_startfunc_t)conductor, (void*) 0);
}

int main(int argc, char **argv)
{
    cpu::boot((thread_startfunc_t) manageThreads, (void *) 0, 0);
}
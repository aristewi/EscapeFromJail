#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include "user.h"

#define BUFFERSIZE 1024

//gets the file name, the user that is initialized once in the main, the number of room
//the player is in right now
void see(char fileName[], User* user, int roomNumber) {

    char buffer[BUFFERSIZE];

    char* errorMessage = "Opening file is unsuccessful!\n";
    int errorSize = strlen(errorMessage);

    int fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        write(2, errorMessage, errorSize);
    } else {
        int fileSize = read(fd, buffer, BUFFERSIZE);
        if (strstr(buffer, "found") == NULL) { //this could be done better, but it's a working solution
            switch(roomNumber) { //based on the room, sets the correct value to true, if necessary
                case 1:
                    user->isKeyCollected = true;
                    break;
                //... adding the other rooms
            }
        }
        write(1, buffer, fileSize); //writes the message to the standard output
    }

    close(fd);

}

int main() {

    User* myUser = initUser();
    see("text.txt", myUser, 1);

    free(myUser);
    return 0;
}
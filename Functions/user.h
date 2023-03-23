#ifndef _USER_H_

#define _USER_H_

#include <stdbool.h>

// the user with the needed variables
typedef struct User {

    bool isKeyCollected;
    bool isTradeMade;
    bool isFoodCollected;
    bool isCostumeCollected;
    bool hasPin;

} User;

User* initUser() {

	User* user = malloc(sizeof(User));
    user->isKeyCollected = false;
    user->isTradeMade = false;
    user->isFoodCollected = false;
    user->isCostumeCollected = false;
    user->hasPin = false;

	return user;
}

#endif
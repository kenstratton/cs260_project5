#include <iostream>
#include <string>
using namespace std;


// Length of List
int len = 0;

// Structure of a list element
struct ELMT {
    // int id;            // Element Data 1: Location (positive integer)
    int value;         // Element Data 2: Integer value
    struct ELMT *next; // Element Data 3: Pointer indicates an address of a linked element OR NULL
};

static struct ELMT *head = NULL; // A head element in a list
struct ELMT * elmt;              // A element used for searching or deleting a target
struct ELMT * new_elmt;          // A new element
struct ELMT * prev_elmt;         // A element located before a new element


// Check if a list is empty
bool isEmpty() {
    if (head == NULL) return true;
    return false;
}


/*******************************************
 Search fuction :
 * 1. Search a element with a given value (check one -> go to a next element)
 * 2. Return a element position OR 0(not found)
********************************************/
int search(int targetVal) {
    // * 1
    elmt = head; 
    int pos = 1;
    while (elmt != NULL) {
        if (elmt->value > targetVal) return 0;
        if (elmt->value == targetVal) return pos;
        elmt = elmt->next;
        pos++;
    }
    return 0; // * 2
}


/*******************************************
 Search fuction 2 :
 * 1. Search a element with a given position
 * 2. Return a element value
********************************************/
int search2(int targetPos) {
    // * 1 
    elmt = head;
    for (size_t i = 0; i < targetPos; i++) elmt = elmt->next;
    return elmt->value; // * 2
}


/*******************************************
 Add fuction :
 * 1. Allocate a memory of a list element with id and value
 * 2. Search a position where a new element is inserted (check one -> go to a next element)
 * 3. Insert a new element (head OR spot between other two elements)
 * 4. Return a result (ex->exist, s->success, f->failure)
********************************************/
string add(int value) {
    // * 1
    new_elmt = (struct ELMT*)malloc(sizeof(struct ELMT));
    new_elmt->value = value;

    // * 2
    elmt = head;
    int pos = 1;
    while (elmt !=  NULL) {
        if (elmt->value == new_elmt->value) return "ex"; // * 4
        if (elmt->value > new_elmt->value ) break;
        prev_elmt = elmt;
        elmt = elmt->next;
        pos++;
    }

    // * 3
    if (elmt == head) {
        new_elmt->next = head;
        head = new_elmt;
        len++;
        return "s"; // * 4
    } else {
        prev_elmt->next = new_elmt;
        new_elmt->next = elmt;
        len++;
        return "s"; // * 4
    }

    return "f"; // * 4
}


/*******************************************
 Remove fuction :
 * 1. Remove data case1 (only a head element in a list)
 * 2. Remove data case2 (one from some elements) (start : head, none -> go to a next element)
 * 3. Return a result (true->success, false->success)
********************************************/
bool remove(int targetVal) {
    // * 1
    elmt = head;
    if (elmt->value == targetVal) {
        int value = elmt->value;
        head = elmt->next;
        free(elmt);
        len--;
        return true; // * 3
    }

    // * 2
    while (elmt != NULL) {
        if (elmt->value > targetVal) return false;
        if (elmt->value == targetVal) break;
        prev_elmt = elmt;
        elmt = elmt->next;
    }
    if (elmt != NULL) {
        int value = elmt->value;
        prev_elmt->next = elmt->next;
        len--;
        free(elmt);
        return true; // * 3
    }

    return false; // * 3
}

// Execute search and print a result
void exSearch(int targetVal) {
    if (isEmpty()) {
        printf("(S) List is Empty\n");
    }
    else {
        int pos = search(targetVal);

        if (pos == 0) {
            printf("(S) Value %d : Not Found\n", targetVal);
        }
        else if (pos > 0) {
            string end;
            if (pos == 1) end = "st";
            if (pos == 2) end = "nd";
            if (pos == 3) end = "rd";
            if (pos > 3) end = "th";
            // printf("(S) Value %d : Found! at %d%s", targetVal, pos, end);
            cout << "(S) Value " << targetVal << " : Found! at " << pos << end << endl;
        }
    }
}

void exSearch2(int targetPos) {
    if (isEmpty()) {
        printf("(S) List is Empty\n");
    }
    else if (targetPos > len or targetPos < 0) {
        printf("(S) Position %d : Not Found\n", targetPos);
    }
    else {
        int value = search2(targetPos);
        printf("(S) Position %d : %d\n", targetPos, value);
    }
}


// Execute addtion and print a result
void exAdd(int value) {
    string result = add(value);
    if (result == "ex") printf("(A) Value %d : Already Exists\n", value);
    if (result == "f") printf("(A) Value %d : Addition Failure\n", value);
    if (result == "s") printf("(A) Value %d : Successfully Added!\n", value);
}


// Execute removal and print a result
void exRemove(int targetVal) {
    if (isEmpty()) {
         printf("(R) List is Empty\n");
    }
    else {
        bool result = remove(targetVal);
        if (result == true) printf("(R) Value %d : Removed!\n", targetVal);
        if (result == false) printf("(R) Value %d : Not Found\n", targetVal);
    }
}


// Check a length of a list
void checkLength() {
    printf(" -  List Length : %d\n", len);
}


// User Operation
int main() {
    int val1 = 10;
    int val2 = 20;
    int val3 = 30;
    int val4 = 40;
    int val5 = 50;

    // Add
    exAdd(val5);
    exAdd(val1);
    exAdd(val3);
    exAdd(val4);
    exAdd(val2);
    exSearch(val1);
    exSearch2(val2);
    exSearch(val3);
    exSearch2(val4);
    exSearch(val5);
    exSearch(51);
    checkLength();

    // Remove
    exRemove(11);
    exRemove(val1);
    exRemove(val3);
    exRemove(val2);
    exRemove(val5);
    exRemove(val4);
    exRemove(44);
    exSearch(val1);
    exSearch(val2);
    exSearch(val3);
    exSearch(val4);
    exSearch(val5);
    checkLength();
}
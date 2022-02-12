#include <iostream>
#include <string>
using namespace std;



// Length of List
int len = 0;

// Structure of a list element
struct ELMT {
    int value;         // Element Data 1: Integer value
    struct ELMT *next; // Element Data 2: Pointer indicates an address of a linked element OR NULL
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
 * 1. Search a element based on a given value (check one -> go to a next element)
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
 * 1. Search a element based on a given position
 * 2. Return a element value
********************************************/
int search2(int targetPos) {
    // * 1 
    elmt = head;
    for (size_t i = 1; i < targetPos; i++) elmt = elmt->next;
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


// Execute value-based search and print a result
bool exSearch(int targetVal) {
    if (isEmpty()) {
        printf("(S) List is Empty\n");
    }
    else {
        int pos = search(targetVal);
        if (pos == 0) {
            printf("(S) Value %d : Not Found\n", targetVal);
        }
        else {
            string end;
            if (pos == 1) end = "st";
            if (pos == 2) end = "nd";
            if (pos == 3) end = "rd";
            if (pos > 3) end = "th";
            printf("(S) Value %d : Found! at %d%s\n", targetVal, pos, end.c_str());
            return true;
        }
    }

    return false;
}


// Execute position-based search and print a result
bool exSearch2(int targetPos) {
    if (isEmpty()) {
        printf("(S) List is Empty\n");
    }
    else if (targetPos > len or targetPos < 0) {
        printf("(S) Position %d : Not Found\n", targetPos);
    }
    else {
        int value = search2(targetPos);
        printf("(S) Position %d : %d\n", targetPos, value);
        return true;
    }

    return false;
}


// Execute addtion and print a result
bool exAdd(int value) {
    string result = add(value);
    if (result == "ex") {
        printf("(A) Value %d : Already Exists\n", value);
    }
    else if (result == "f") {
        printf("(A) Value %d : Addition Failure\n", value);
    }
    else if (result == "s") {
        printf("(A) Value %d : Successfully Added!\n", value);
        return true;
    }

    return false;
}


// Execute removal and print a result
bool exRemove(int targetVal) {
    if (isEmpty()) {
         printf("(R) List is Empty\n");
    }
    else {
        bool result = remove(targetVal);
        if (result == false) {
            printf("(R) Value %d : Not Found\n", targetVal);
        }
        else {
            printf("(R) Value %d : Removed!\n", targetVal);
            return true;
        }
    }

    return false;
}


// Check a length of a list
int checkLength() {
    printf(" -  List Length : %d\n", len);
    return len;
}


/*******************************************
Test fuction :
 * 1. Prepare variables for tests
 * 2. Test add, remove, search, search2, and isEmpty functions
 * 3. Test functions executing * 2 items
********************************************/
void testList() {
    // * 1
    int val1 = 10;
    int val2 = 20;
    int val3 = 30;
    int val4 = 40;
    int val5 = 50;
    int pos1 = 1;
    int pos2 = 2;
    int pos3 = 3;
    int pos4 = 4;

    printf("Tests start!\n\n");


    // * 2
    assert(len == 0);
    assert(isEmpty() == true);
    assert(add(val1) == "s");
    assert(add(val1) == "ex");
    assert(len = 1);
    assert(isEmpty() == false);
    assert(search(val1) == 1);
    assert(search(val2) == 0);
    assert(search2(pos1) == val1);
    assert(remove(val5) == false);
    assert(remove(val1) == true);
    assert(len == 0);


    // * 3
    // Execute add
    assert(checkLength() == 0);
    assert(exAdd(val3) == true);
    assert(exAdd(val1) == true);
    assert(exAdd(val4) == true);
    assert(exAdd(val2) == true);
    assert(exAdd(val2) == false);
    cout << "" << endl;

    // Execute search (elements in a list)
    assert(checkLength() == 4);
    assert(exSearch(val1) == true);
    assert(exSearch(val2) == true);
    assert(exSearch(val3) == true);
    assert(exSearch(val4) == true);
    assert(exSearch2(pos1) == true);
    assert(exSearch2(pos2) == true);
    assert(exSearch2(pos3) == true);
    assert(exSearch2(pos4) == true);

    // Execute searching a value/position of a non-existent element
    assert(exSearch(11) == false);
    assert(exSearch2(5) == false);
    cout << "" << endl;

    // Execute removing a value of a non-existent element
    assert(exRemove(val5) == false);
    cout << "" << endl;

    // Execute removeing and searching the removed element
    assert(exRemove(val2) == true);
    assert(exSearch(val2) == false);
    assert(exSearch2(pos4) == false);
    assert(checkLength() == 3);
    cout << "" << endl;

    // Execute removeing and searching the removed element
    assert(exRemove(val3) == true);
    assert(exSearch(val3) == false);
    assert(exSearch2(pos3) == false);
    assert(checkLength() == 2);
    cout << "" << endl;

    // Execute removeing and searching the removed element
    assert(exRemove(val1) == true);
    assert(exSearch(val1) == false);
    assert(exSearch2(pos2) == false);
    assert(checkLength() == 1);
    cout << "" << endl;

    // Execute removeing and searching the removed element
    assert(exRemove(val4) == true);
    assert(exSearch(val4) == false);
    assert(exSearch2(pos1) == false);
    assert(checkLength() == 0);
    cout << "" << endl;

    // Execute removeing a value of a non-existent element
    assert(exRemove(val5) == false);
    cout << "" << endl;

    printf("Tests Done!\n");
}


// User Operation
int main() {
    testList();
}
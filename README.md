# cs260_project5

## Singly Linked List

### ▼ List Element
Each element has a pointer to contact another.<br>
We have to access elements sequentially starting from the first element.<br>
(In my program) Each element has a unique integer value.

### ▼ Tests
Whether it's possible to...
1. **Addition of elements**
    - insert  a new element between elements
    - maintain uniqueness of element values
2. **Deletion of elements**
    - appropriately delete an element
    - halt the deletion process when a list is empty or when the target is not found
3. **Search for elements**
    - search for a specific element based on its value
    - search for a specific element based on its position
    - halt the search process when a list is empty or when the target is not found

### ▼ Complexity (Big-O notation)
|Insert|Remove|Search|
|:--:|:--:|:--:|
| O(1) | O(1) | O(n) |

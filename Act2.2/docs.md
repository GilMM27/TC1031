# Functionalities of a linear data structure verification

## Introduction

A linear data structure consists of continuidely stored elementes one after the other. Meaning that a tree wouldn't be a linear data structure since each node can point to multiple other nodes. Instead, a linked list stores one value in each node that points to the next node, making it linear. This data structure commonly only store this two values, but there are variants like linked listed that store the next and previous node, in this example this feature is implemented.

## Test cases

Terminal logs:
new 1
1
update 0 2
2
update 1 2

Explanation: in this test case trying to update a position that has not been initialized causes the program to crash, so in a future iteration it is recommended to handle this error apropriately.

Terminal logs:
new 1
1
new 2
1 2
new 3
1 2 3
delete 1
1 3
exit
1 3

Explanation: in this case everything works correctly and the second element of the list is erased.

Terminal logs:
new 1
1
delete 1

Explanation: similar to the first test case, trying to work with a position in the linked list that hasn't yet been initialized causes the program to crash.

Terminal logs:
new 1
1
new 2
1 2
new 3
1 2 3
delete 0
2 3
update 0 1
1 3
update 1 2
1 2
exit
1 2

Explanation: code works as expected when the given position are part of the linked list already.

Terminal logs:
new 1
1
delete -1

Explanation: giving negative positions also makes the program crash.

## Conclusion

Code should always be tested for edge cases that we may have not considered before to avoid crashing or unexpected behaviors. Now that we have identified the error correctly a condition should be implemented to only accept position values that are part of the linked list.
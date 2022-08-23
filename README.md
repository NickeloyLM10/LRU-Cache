# LRU-Cache

- Items are arranged in the least Recently Used (LRU) Cache in order of use, making it easy to quickly determine which item hasn't
been used in the longest period of time.
- Data structures such as doubly linked lists and hash maps have been implemented.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

implemented LRU Cache using three functions-

insertKeyValue - There are two cases in this part:
a) replace the old value and update
b) again there are two cases in this case
  1 - check if cache is full or not : delete least recently used item from cache and remove that element from linked list as well as hashmap.
  2 - add element in front of linked list.
  

getValue - get value of partiular element and put that element in front of linked list.


mostRecentKey - simply return the front most element of the linked list.

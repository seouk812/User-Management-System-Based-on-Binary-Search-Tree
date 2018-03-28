# User-Management-System-Based-on-Binary-Search-Tree

Below is node form of binary search tree.

typedef struct NODE_
{
  char id[100];
  char name[100];
  struct NODE_ left;
  struct NODE_ right;
}NODE;


- In program -

You can insert uesr. (ID cannot overlap.)
![default](https://user-images.githubusercontent.com/30895117/38044341-6d8ff29a-32f4-11e8-8c57-c10601c28df4.PNG)

You can search user ID. (Found)
![2](https://user-images.githubusercontent.com/30895117/38044347-70dde0a6-32f4-11e8-83ff-b14d96dcead9.PNG)

(Not Found)
![3](https://user-images.githubusercontent.com/30895117/38044350-72841dda-32f4-11e8-9802-9acdfbb2ecbe.PNG)

You can delete user. (Coming up with an algorithm of deleting user is most difficult.)
![4](https://user-images.githubusercontent.com/30895117/38044353-743a115c-32f4-11e8-8c34-81a74998bc7e.PNG)

Even if a user is deleted, the rest are automatically sorted by my algorithm.
![5](https://user-images.githubusercontent.com/30895117/38044356-77e07170-32f4-11e8-9904-c885a2bba3c3.PNG)

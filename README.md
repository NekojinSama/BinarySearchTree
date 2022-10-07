# BinarySearchTreeAssignment
Tree structures are a widely used data construct in programming 
(including games program- ming). One such tree structure is a Binary Search Tree 
which stores data in a manner that allows fast searching. Familiarise yourself with 
this technique and write your own Binary Search Tree using the code below to help you:



struct node {int value;struct node * left;struct node * right;};

struct node * root = NULL ;

// implement the functions described by these headers

void insert_integer ( struct node ** tree , int value );

void print_tree ( struct node * tree );

void terminate_tree ( struct node * tree );

int most_common_integer ( struct node * tree);

int largest_integer ( struct node * tree );

int summ_of_all_integers (struct node * tree);

// Main function

int main () {

// call your implemented functions here to test the binary search tree

return 0;  }

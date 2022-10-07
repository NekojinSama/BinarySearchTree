#include <iostream>


struct node* root = NULL;
struct node** tree = &root;


struct node
{
	int data;
	struct node* left;
	struct node* right;
};


void insert_integer(struct node** tree, int value)
{
	if (!*tree)
	{
		*tree = new node;
		(*tree)->data = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}

	else if(value < (*tree)->data)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = new node;
			((*tree)->left)->data = value;
			((*tree)->left)->left = NULL;
			((*tree)->left)->right = NULL;
		}

		else
		{
			insert_integer(&(*tree)->left, value);
		}

	}

	else
	{
		if (!(*tree)->right)
		{
			(*tree)->right = new node;
			((*tree)->right)->data = value;
			((*tree)->right)->left = NULL;
			((*tree)->right)->right = NULL;
		}

		else
		{
			insert_integer(&(*tree)->right, value);
		}
	}
}


void print_tree(struct node* tree)
{
	if (!tree)
	{
		return;
	}
	print_tree(tree->left);
	std::cout << tree->data << " ";
	print_tree(tree->right);
}


void terminate_tree(struct node** tree)
{
	if (!*tree)
	{
		return;
	}
	terminate_tree(&(*tree)->left);
	terminate_tree(&(*tree)->right);
	
	delete *tree;
	*tree = NULL;
}


int most_common_integer(struct node* tree)
{
	int count = 1, currmax = 1;
	if (!tree)
	{
		return;
	}

	//return count = 1 + most_common_integer(tree->right) + most_common_integer(tree->left);
	int value = tree->data;

	while (tree->right != NULL)
	{
		if(value == (tree->right->data))
		{
			count += 1;
		}
		tree = tree->right;
	} 

	while (tree->left != NULL)
	{
		if (value == (tree->left->data))
		{
			count += 1;
		}
		tree = tree->left;
	}

	if (currmax < count)
		currmax = tree->data;
	


	most_common_integer(tree->left);
	most_common_integer(tree->right);
	return currmax;
}


int largest_integer(struct node* tree)
{
	if (!tree->right)
	{
		return tree->data;
	}
	largest_integer(tree->right);
}


int summ_of_all_integers(struct node* tree)
{
	int sum = 0;
	if (!tree)
	{
		return 0;
	}
	return sum = tree->data + summ_of_all_integers(tree->right) + summ_of_all_integers(tree->left);
}




int main()
{
	int ans = 10;
	int inser = 0;
	

	do
	{
		std::cout << "Perform BST \n1. Insert \n2. Print \n3. Terminate\n4. Most common integer\n5. Largest integer\n6. Sum of all integer\n";
		std::cin >> ans;
		switch (ans)
		{
		case 1:
			std::cout << "Insert a number to enter ";
			std::cin >> inser;
			insert_integer(tree, inser);
			break;

		case 2:
			if (!root)
			{
				std::cout << "No data found" << "\n";
			}

			else
			{
				print_tree(root);
				std::cout << "\n";
			}
			break;

		case 3:
			if (!root)
			{
				std::cout << "No data found" << "\n";
			}

			else
			{
				terminate_tree(tree);
			}
			break;

		case 4:
			if (!root)
			{
				std::cout << "No data found" << "\n";
			}

			else
			{
				std::cout << most_common_integer(root) << "\n";
			}
			break;

		case 5:
			if (!root)
			{
				std::cout << "No data found" << "\n";
			}

			else
			{
				std::cout << largest_integer(root) << "\n";
			}
			break;

		case 6:
			if (!root)
			{
				std::cout << "No data found" << "\n";
			}

			else
			{
				std::cout << summ_of_all_integers(root) << "\n";
			}
			break;
		}
	} while (ans != 0);
	
}

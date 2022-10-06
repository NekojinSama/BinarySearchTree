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
	if (!tree->left)
	{
		std::cout << tree->data << " ";
		if (tree->right)
		{
			print_tree(tree->right);
		}
	}

	else
	{
		print_tree(tree->left);
		std::cout << tree->data << " ";
		if (tree->right)
		{
			print_tree(tree->right);
		}
	}
}


void terminate_tree(struct node** tree)
{
	if (!tree)
	{
		return;
	}
	terminate_tree(&(*tree)->left);
	terminate_tree(&(*tree)->right);
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->data = NULL;
	delete tree;
}


int most_common_integer(struct node* tree)
{
	return 0;
}


int largest_integer(struct node* tree)
{
	return 0;

}


int summ_of_all_integers(struct node* tree)
{
	return 0;

}




int main()
{
	int ans = 10;
	int inser = 0;
	

	do
	{
		std::cout << "Perform BST \n1. Insert \n2. Print \n3. Terminate\n";
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
				std::cout << "No data found";
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
				std::cout << "No data found";
			}

			else
			{
				terminate_tree(root);
			}
			break;
		}
	} while (ans != 0);
	
}

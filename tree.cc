#include<iostream>
#include "tree.hh"

tree_ptr_t create_tree(const key_t& key,
                       const value_t& value,
                       tree_ptr_t left,
                       tree_ptr_t right)
{
	tree_ptr_t treep = new Tree{key, value, left, right};
	return treep;
}

void destroy_tree(tree_ptr_t tree)
{
	if(tree->left_ != nullptr)
	{
		destroy_tree(tree->left_);
	}
	if(tree->right_ != nullptr)
	{
		destroy_tree(tree->right_);
	}
	delete tree;
	tree = nullptr;
}


bool isKeyInTree(tree_ptr_t tree, key_t key)
{
	if (tree == nullptr){
		return false;
	}
	bool leftResult = false;
	bool rightResult = false;
	if (tree->key_ == key)
	{return true;}
	if(tree->left_ != nullptr)
	{
		leftResult = isKeyInTree(tree->left_, key);
	}
	if(tree->right_ != nullptr)
	{
		rightResult = isKeyInTree(tree->right_, key);
	}
	if (rightResult or leftResult)
	{return true;}
	else
	{return false;}
}

std::string path_to(tree_ptr_t tree, key_t key)
{
	if (tree->left_ != nullptr and isKeyInTree(tree->left_, key))
	{
		return "L" + path_to(tree->left_, key);
	}
	if (tree->key_ == key)
	{
		return "";
	}
	if (tree->right_ != nullptr and isKeyInTree(tree->right_, key))
	{
		return "R" + path_to(tree->right_, key);
	}
	exit(1);
}


tree_ptr_t node_at(tree_ptr_t tree, std::string path)
{
	if (path.length() == 0)
	{
		return tree;
	}
	if (path.length() == 1)
	{
		if (path == "L")
		{
			return tree->left_;
		}
		else if (path == "R")
		{
			return tree->right_;
		}
		else
		{
			return nullptr;
		}
	}
	else if (path.substr (0,1) == "L")
	{
		return node_at(tree->left_, path.substr (1));
	}
	else if (path.substr (0,1) == "R")
	{
		return node_at(tree->right_, path.substr(1));
	}
	else
	{
		return nullptr;
	}
}


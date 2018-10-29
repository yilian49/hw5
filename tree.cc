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
}


bool isKeyInTree(tree_ptr_t tree, key_t key)
{
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
	if(tree->left_ == nullptr and tree->right_ == nullptr)
	{
		if (tree->key_ == key)
		{return true;}
		else
		{return false;}
	}	
	if (rightResult or leftResult)
	{return true;}
	else
	{return false;}
}

std::string path_to_rec(tree_ptr_t tree, key_t key)
{	
	if (isKeyInTree(tree->left_, key))
	{
	return 'L' + path_to_rec(tree->left_, key);
	}
	else if (tree->key_ == key)
	{
	return "";
	}
	else if (isKeyInTree(tree->right_, key))
	{
	return "R" + path_to_rec(tree->right_, key);
	}
	else
	{
	exit(1);
	}	
}

std::string path_to(tree_ptr_t tree, key_t key)
{
	if (isKeyInTree(tree, key))
	{
		return path_to_rec(tree, key);
	}
	else
	{
		exit(1);
	}

}

//////////////////////////////////////////////////////////////////////////////
// node_at: Follow a path from a given root node and return the node that is
// at the end of the path. For example, for the root of the tree above,
// node_at("LR") will return a pointer to the node whose key is 6.
// If the path leads to an invalid or empty child, or contains any character
// other than 'L' or 'R', return nullptr (don't crash)
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


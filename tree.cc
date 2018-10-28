#include<iostream>
#include "tree.hh"

tree_ptr_t create_tree(const key_t& key,
                       const value_t& value,
                       tree_ptr_t left = nullptr,
                       tree_ptr_t right = nullptr)
{
	tree_ptr_t treep = new Tree{(key, value, left, right)};
	return treep;
}

void destroy_tree(tree_ptr_t tree)
{
	if(tree->left != nullptr)
	{
		destroy_tree(tree->left_);
	}
	if(tree->right != nullptr)
	{
		destroy_tree(tree->right_);
	}
	delete tree;
}

std::string path_to(tree_ptr_t tree, key_t key)
{

}

bool isKeyInTree(tree_ptr_t tree, key_t key)
{


//////////////////////////////////////////////////////////////////////////////
// node_at: Follow a path from a given root node and return the node that is
// at the end of the path. For example, for the root of the tree above,
// node_at("LR") will return a pointer to the node whose key is 6.
// If the path leads to an invalid or empty child, or contains any character
// other than 'L' or 'R', return nullptr (don't crash)
tree_ptr_t node_at(tree_ptr_t tree, std::string path);



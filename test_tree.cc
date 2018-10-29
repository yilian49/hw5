#include<iostream>
#include "tree.cc"

int main()
{
	tree_ptr_t root = create_tree(1, 10, nullptr, nullptr);
	root->left_ = create_tree(2, 15, create_tree(4, 15, nullptr, nullptr), create_tree(5,10,nullptr,nullptr));
	root->right_ = create_tree(3, 7, create_tree(6, 9, nullptr, nullptr), create_tree(7,1,nullptr,nullptr));
	bool isIn =  isKeyInTree(root, 6);
	std::cout << isIn;
	std::string str = path_to(root, 6);
	std::cout<<str;
	std::cout<<(node_at(root, str)->value_);
	destroy_tree(root);
//	std::cout<<root->left_;
}

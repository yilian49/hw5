#include<iostream>
#include "tree.cc"

int main()
{
	tree_ptr_t root = create_tree(1, 1, nullptr, nullptr);
	root->left_ = create_tree(6, 0, create_tree(7, 0, nullptr, nullptr), create_tree(8,0,nullptr,nullptr));
	root->right_ = create_tree(2, 0, create_tree(4, 0, create_tree(8, 0, nullptr, nullptr), create_tree(1, 0, nullptr, nullptr)), create_tree(7, 0, create_tree(5, 0, nullptr, nullptr), nullptr));
	root->left_->left_->left_ = create_tree(2,0,nullptr,nullptr);
	root->left_->right_->left_ = create_tree(4,0,nullptr,nullptr);

	std::cout<<"\n";	
	if(isKeyInTree(root, 2) == true
		and isKeyInTree(root->left_, 5) == false
		and isKeyInTree(root->right_,2) == true
		and isKeyInTree(root, 10) == false)
	{	std::cout<<"isKeyInTree tested";}
	else{ std::cout<<"isKeyInTree failed";}
	std::cout<<"\n";
	if(path_to(root, 4) == "LRL" and
		path_to(root, 1) == "" and
		path_to(root, 2) == "LLL" and
		path_to(root, 5) == "RRL")
	{	std::cout<<"path_to tested";}
	else{ 	std::cout<<"path_to failed";}
	std::cout<<"\n";
	if(node_at(root, "LL")->key_ == 7 and
		node_at(root, "")->key_ == 1 and
		node_at(root, "RRL")->key_ == 5 and
		node_at(root, "R")->key_ == 2 and
		node_at(root, "RLR")->key_ == 1)
	{ 	std::cout<<"node_at tested";}
	else{	std::cout<< "node_at failed";}
	
	
		tree_ptr_t tree1 = root;
		tree_ptr_t tree2 = root->left_;
		tree_ptr_t tree3 = root->left_->left_;
		tree_ptr_t tree4 = root->left_->left_->left_;
		tree_ptr_t tree5 = root->right_->left_->left_;
		destroy_tree(root);
	std::cout<<"\n";	
	if (tree1==nullptr and
		tree2==nullptr and
		tree3==nullptr and
		tree4==nullptr and
		tree5==nullptr)
	{	std::cout<<"destroy_tree tested";}
	else
	{	std::cout<<"destroy_tree failed";}
	
	}

		


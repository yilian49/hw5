# hw5
a cs homework project in making a bst in c++

The tree.cc has functions that create tree pointers. Destroy function deletes the children of nodes first recursively and lastly delete the root node. Path_to function checks if the node with key exists in the subtree before going down to its children; it is also recursive with a helper function isKetInTree. And node_at reads the string, takes it apart by using the substring operator. It is also a recursive function with 2 base cases.

The test_tree.cc tests the general functionality of these function.

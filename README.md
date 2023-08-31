## C - Binary trees

#### Task 0: New node
[0-binary_tree_node.c](0-binary_tree_node.c) contains a function that creates a binary tree node.
- Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
- Where `parent` is a pointer to the parent node of the node to create
- And `value` is the value to put in the new node
- When created, a node does not have any child
- Returns a pointer to the new node, or `NULL` on failure

#### Task 1: Insert left
[1-binary_tree_insert_left.c](1-binary_tree_insert_left.c) contains a function that inserts a node as the left-child of another node.
- Prototype: `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`
- Where `parent` is a pointer to the node to insert the left-child in
- And `value` is the value to store in the new node
- Returns a pointer to the created node, or `NULL` on failure or if parent is `NULL`
- If `parent` already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.

#### Task 2: Insert Right
[2-binary_tree_insert_right.c](2-binary_tree_insert_right.c) contains a function that inserts a node as the right-child of another node.
- Prototype: `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`
- Where `parent` is a pointer to the node to insert the rightt-child in
- And `value` is the value to store in the new node
- Returns a pointer to the created node, or `NULL` on failure or if parent is `NULL`
- If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.

#### Task 3: Delete
[3-binary_tree_delete.c](3-binary_tree_delete.c) contains that deletes an entire binary tree
- Prototype: `void binary_tree_delete(binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to delete
- Does nothing if tree is NULL

#### Task 4: Is leaf
[4-binary_tree_is_leaf.c](4-binary_tree_is_leaf.c) contains a function that checks if a node is a leaf
- Prototype: `int binary_tree_is_leaf(const binary_tree_t *node);`
- Where `node` is a pointer to the node to check
- Returns `1` if `node` is a leaf, otherwise `0`
- Returns `0` if `node` is `NULL`

#### Task 5: Is root
[5-binary_tree_is_root.c](5-binary_tree_is_root.c) contains a function that checks if a given node is a root
- Prototype: `int binary_tree_is_root(const binary_tree_t *node);`
- Where `node` is a pointer to the node to check
- Returns `1` if `node` is a root, otherwise `0`
- If node is `NULL`, return `0`

#### Task 6: Pre-order traversal
[6-binary_tree_preorder.c](6-binary_tree_preorder.c) contains a function that goes through a binary tree using pre-order traversal
- Prototype: `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`
- Where `tree` is a pointer to the root node of the tree to traverse
- And `func` is a pointer to a function to call for each node. The value in the node is passed as a parameter to this function.
- Does nothing if `tree` or `func` is `NULL`

#### Task 7: In-order traversal
[7-binary_tree_inorder.c](7-binary_tree_inorder.c) contains a function that goes through a binary tree using in-order traversal
- Prototype: `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`
- Where `tree` is a pointer to the root node of the tree to traverse
- And `func` is a pointer to a function to call for each node. The value in the node is passed as a parameter to this function.
- Does nothing if `tree` or `func` is `NULL`

#### Task 8: Post-order traversal
[8-binary_tree_postorder.c](8-binary_tree_postorder.c) contains a function that goes through a binary tree using post-order traversal
- Prototype: `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`
- Where `tree` is a pointer to the root node of the tree to traverse
- And `func` is a pointer to a function to call for each node. The value in the node is passed as a parameter to this function.
- Does nothing if `tree` or `func` is `NULL`

#### Task 9: Height
[9-binary_tree_height.c](9-binary_tree_height.c) contains a function that measures the height of a binary tree
- Prototype: `size_t binary_tree_height(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to measure the height.
- Returns `0` if tree is `NULL`

#### Task 10: Depth
[10-binary_tree_depth.c](10-binary_tree_depth.c) contains a function that measures the depth of a node in a binary tree
- Prototype: `size_t binary_tree_depth(const binary_tree_t *tree);`
- Where `tree` is a pointer to the node to measure the depth
- Returns `0` if tree is `NULL`

#### Task 11: Size
[11-binary_tree_size.c](11-binary_tree_size.c) contains a function that measures the depth of a node in a binary tree
- Prototype: `size_t binary_tree_size(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to measure the size
- Returns `0` if tree is `NULL`

#### Task 12: Leaves
[12-binary_tree_leaves.c](12-binary_tree_leaves.c) contains a function that counts the leaves in a binary tree
- Prototype: `size_t binary_tree_leaves(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to count the number of leaves
- Returns `0` if tree is `NULL`

#### Task 13: Nodes
[13-binary_tree_nodes.c](13-binary_tree_nodes.c) contains a function that counts the nodes with at least 1 child in a binary tree
- Prototype: `size_t binary_tree_nodes(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to count the number of nodes
- Returns `0` if tree is `NULL`

#### Task 14: Balance factor
[14-binary_tree_balance.c](14-binary_tree_balance.c) contains a function that measures the balance factor a binary tree
- Prototype: `int binary_tree_balance(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to measure the balance factor
- Returns `0` if tree is `NULL`

#### Task 15: Is full
[15-binary_tree_is_full.c](15-binary_tree_is_full.c) contains a function that checks if a binary tree is full
- Prototype: `int binary_tree_is_full(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to check
- Returns `0` if tree is `NULL`

#### Task 16: Is perfect
[16-binary_tree_is_perfect.c](16-binary_tree_is_perfect.c) contains a function that checks if a binary tree is perfect
- Prototype: `int binary_tree_is_perfect(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to check
- Returns `0` if tree is `NULL`

#### Task 17: Sibling
[17-binary_tree_sibling.c](17-binary_tree_sibling.c) contains a function that finds the sibling of a node
- Prototype: `binary_tree_t *binary_tree_sibling(binary_tree_t *node);`
- Where `node` is a pointer to the node to find the sibling
- Returns a pointer to the sibling node
- If node is `NULL` or the parent is `NULL`, returns `NULL`
- If `node` has no sibling, returns `NULL`

#### Task 18: Uncle
[18-binary_tree_uncle.c](18-binary_tree_uncle.c) contains a function that finds the uncle of a node
- Prototype: `binary_tree_t *binary_tree_uncle(binary_tree_t *node);`
- Where `node` is a pointer to the node to find the uncle
- Returns a pointer to the uncle node
- If node is `NULL`, returns `NULL`
- If `node` has no uncle, returns `NULL`


#### Task 19: Lowest common ancestor
[100-binary_trees_ancestor.c](100-binary_trees_ancestor.c) contains  function that finds the lowest common ancestor of two nodes
- Prototype: `binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);`
- Where `first` is a pointer to the first node
- And `second` is a pointer to the second node
- Returns a pointer to the lowest common ancestor node of the two given nodes
- If no common ancestor was found, returns `NULL`

#### Task 20: Level-order traversal
[101-binary_tree_levelorder.c](101-binary_tree_levelorder.c) contains a function that goes through a binary tree using level-order traversal
- Prototype: `void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));`
- Where `tree` is a pointer to the root node of the tree to traverse
- And `func` is a pointer to a function to call for each node. The value in the node is passed as a parameter to this function.
- Does nothing if `tree` or `func` is `NULL`

#### Task 21: Is complete
[102-binary_tree_is_complete.c](102-binary_tree_is_complete.c) contains a function that checks if a binary tree is complete
- Prototype: `int binary_tree_is_complete(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to check
- Returns `0` if tree is `NULL`

#### Task 22: Rotate left
[103-binary_tree_rotate_left.c](103-binary_tree_rotate_left.c) contains a function that performs a left-rotation on a binary tree
- Prototype: `binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to rotate
- Returns a pointer to the new root node of the tree once rotated

#### Task 23: Rotate right
[104-binary_tree_rotate_right.c](104-binary_tree_rotate_right.c) contains a function that performs a right-rotation on a binary tree
- Prototype: `binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to rotate
- Returns a pointer to the new root node of the tree once rotated

#### Task Is BST
[110-binary_tree_is_bst.c](110-binary_tree_is_bst.c) contains a function that checks if a binary tree is a valid Binary Search Tree
- Prototype: `int binary_tree_is_bst(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to check
- Returns `1` if `tree` is a valid BST, and `0` otherwise
- Returns `0` if tree is `NULL`

#### Task 25: BST - Insert
[111-bst_insert.c](111-bst_insert.c) contains a function that inserts a value in a Binary Search Tree
- Prototype: `bst_t *bst_insert(bst_t **tree, int value);`
- Where `tree` is a double pointer to the root node of the BST to insert the value
- And `value` is the value to store in the node to be inserted
- Returns a pointer to the created node, or `NULL` on failure
- If the address stored in `tree` is `NULL`, the created node becomes the root node.
- If the value is already present in the tree, it is ignored

#### Task 26: BST - Array to BST
[112-array_to_bst.c](112-array_to_bst.c) contains a function that builds a Binary Search Tree from an array
- Prototype: `bst_t *array_to_bst(int *array, size_t size);`
- Where `array` is a pointer to the first element of the array to be converted
- And `size` is the number of elements in the array
- Returns a pointer to the root node of the created BST, or `NULL` on failure
- If a value of the array is already present in the tree, this value is ignored

#### Task 27: BST - Search
[113-bst_search.c](113-bst_search.c) contains a function that searches for a value in a Binary Search Tree
- Prototype: `bst_t *bst_search(const bst_t *tree, int value);`
- Where `tree` is a pointer to the root node of the BST to search
- And `value` is the value to search in the tree
- Returns a pointer to the node containing a value equals to `value`
- Returns `NULL` if `tree` is `NULL` or if nothing is found

#### Task 28: BST - Remove
[114-bst_remove.c](114-bst_remove.c) contains a function that removes a node from a Binary Search Tree
- Prototype: `bst_t *bst_remove(bst_t *root, int value);`
- Where `root` is a pointer to the root node of the tree to be updated
- And `value` is the value to remove in the tree
- Once located, the node containing a value equals to value is removed and freed
- If the node to be deleted has two children, it is replaced with its first `in-order successor`
- Returns a pointer to the new root node of the tree after removing the desired value

#### Task Big O #BST
[115-O](115-O) contains the average time complexities of those operations on a Binary Search Tree (one answer per line):
- Inserting the value `n`
- Removing the node with the value `n`
- Searching for a node in a BST of size `n`

#### Task 30: Is AVL
[120-binary_tree_is_avl.c](120-binary_tree_is_avl.c) contains a function that checks if a binary tree is a valid AVL Tree
- Prototype: `int binary_tree_is_avl(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to check
- Returns `1` if `tree` is a valid AVL Tree, and `0` otherwise
- Returns `0` if tree is `NULL`

#### Task 31: AVL - Insert
[121-avl_insert.c](121-avl_insert.c) contains a function that inserts a value in an AVL Tree
- Prototype: `avl_t *avl_insert(avl_t **tree, int value);`
- Where `tree` is a double pointer to the root node of the AVL tree to insert the value
- And `value` is the value to store in the node to be inserted
- Returns a pointer to the created node, or `NULL` on failure
- If the address stored in `tree` is `NULL`, the created node becomes the root node.
- After the insertion, the tree remains an AVL tree.

#### Task 32: AVL - Array to AVL
[122-array_to_avl.c](122-array_to_avl.c) contains a function that builds an AVL tree from an array
- Prototype: `avl_t *array_to_avl(int *array, size_t size);`
- Where `array` is a pointer to the first element of the array to be converted
- And `size` is the number of elements in the array
- Returns a pointer to the root node of the created AVL tree, or `NULL` on failure
- If a value of the array is already present in the tree, this value is ignored

#### Task 33: AVL - Remove
[123-avl_remove.c](123-avl_remove.c) contains a function that removes a node from an AVL tree
- Prototype: `avl_t *avl_remove(avl_t *root, int value);`
- Where `root` is a pointer to the root node of the tree to remove a node from
- And `value` is the value to remove in the tree
- Once located, the node containing a value equals to value is removed and freed
- If the node to be deleted has two children, it is replaced with its first `in-order successor`
- The tree is rebalanced after deletion of the desired node if necessary
- Returns a pointer to the new root node of the tree after removing the desired value

#### Task: 34: AVL - From sorted array
[124-sorted_array_to_avl.c](124-sorted_array_to_avl.c) contains a  function that builds an AVL tree from an array
- Prototype: `avl_t *sorted_array_to_avl(int *array, size_t size);`
- Where `array` is a pointer to the first element of the array to be converted
- And `size` is the number of elements in the array
- Returns a pointer to the root node of the created AVL tree, or `NULL` on failure
- Assumes there will be no duplicate value in the array
- Does not rotate
- File only has 2 functions

#### Task 35: Big 0 #AVL Tree
[125-O](125-O) contains the average time complexities of these operations on an AVL Tree (one answer per line):
- Inserting the value `n`
- Removing the node with the value `n`
- Searching for a node in an AVL tree of size n

#### Task 36: Is Binary heap
[130-binary_tree_is_heap.c](130-binary_tree_is_heap.c) contains a function that checks if a binary tree is a valid Max Binary Heap
- Prototype: `int binary_tree_is_heap(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to check
- Returns `1` if `tree` is a valid Max Binary Heap, and `0` otherwise
- Returns `0` if tree is `NULL`

#### Task 37: Heap - Insert
[131-heap_insert.c](131-heap_insert.c) contains a function that inserts a value in a max binary heap
- Prototype: `heap_t *heap_insert(heap_t **root, int value);`
- Where `root` is a double pointer to the root node of the heap to insert the value
- And `value` is the value to store in the node to be inserted
- Returns a pointer to the created node, or `NULL` on failure
- If the address stored in `tree` is `NULL`, the created node becomes the root node.
- After the insertion, the tree remains a max heap.

#### Task 38: Heap - Array to Binary Heap
[132-array_to_heap.c](132-array_to_heap.c) contains a  function that builds an max binary heap tree from an array
- Prototype: `heap_t *sorted_array_to_heap(int *array, size_t size);`
- Where `array` is a pointer to the first element of the array to be converted
- And `size` is the number of elements in the array
- Returns a pointer to the root node of the created binary heap, or `NULL` on failure

#### Task 39: Heap - Extract
[133-heap_extract.c](133-heap_extract.c) contains a function that extracts the root node of a Max Binary Heap
- Prototype: `int heap_extract(heap_t **root);`
- Where `root` is a double pointer to the root node of heap
- Returns the value stored in the root node
- The root node is freed and replaced with the last `level-order` node of the heap
- Once replaced, the heap is rebuilt if necessary
- Returns `0` if it fails

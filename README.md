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

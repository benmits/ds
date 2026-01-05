#include <stdio.h> #include <stdlib.h>
#define MAX_KEYS 3 // Maximum keys in a node (t-1 where t is the minimum degree)
#define MIN_KEYS 1 // Minimum keys in a node (ceil(t/2) - 1)
#define MAX_CHILDREN (MAX_KEYS + 1) // Maximum children in a node (t)
typedef struct BTreeNode { int keys[MAX_KEYS];
struct BTreeNode* children[MAX_CHILDREN]; int numKeys;
int isLeaf;
} BTreeNode;
BTreeNode* createNode(int isLeaf) {




BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode)); node->isLeaf = isLeaf;
 
node->numKeys = 0;
for (int i = 0; i < MAX_CHILDREN; i++) { node->children[i] = NULL;
}
return node;
}
void splitChild(BTreeNode* parent, int index, BTreeNode* child) { BTreeNode* newChild = createNode(child->isLeaf);
newChild->numKeys = MIN_KEYS; for (int i = 0; i < MIN_KEYS; i++) {
newChild->keys[i] = child->keys[i + MIN_KEYS + 1];
}

if (!child->isLeaf) {
for (int i = 0; i < MIN_KEYS + 1; i++) {
newChild->children[i] = child->children[i + MIN_KEYS + 1];
}
}
child->numKeys = MIN_KEYS;
for (int i = parent->numKeys; i >= index + 1; i--) { parent->children[i + 1] = parent->children[i];
}
parent->children[index + 1] = newChild;
for (int i = parent->numKeys - 1; i >= index; i--) { parent->keys[i + 1] = parent->keys[i];
}

parent->keys[index] = child->keys[MIN_KEYS]; parent->numKeys++;
}
void insertNonFull(BTreeNode* node, int key) { int i = node->numKeys - 1;
if (node->isLeaf) {
while (i >= 0 && node->keys[i] > key) { node->keys[i + 1] = node->keys[i];
i--;
}
node->keys[i + 1] = key; node->numKeys++;
} else {
while (i >= 0 && node->keys[i] > key) { i--;
}



if (node->children[i + 1]->numKeys == MAX_KEYS) { splitChild(node, i + 1, node->children[i + 1]);
 
if (key > node->keys[i + 1]) { i++;
}
}
insertNonFull(node->children[i + 1], key);
}
}
void insert(BTreeNode** root, int key) { BTreeNode* r = *root;
if (r->numKeys == MAX_KEYS) { BTreeNode* newRoot = createNode(0); newRoot->children[0] = r; splitChild(newRoot, 0, r);
int i = 0;
if (newRoot->keys[0] < key) { i++;
}
insertNonFull(newRoot->children[i], key);
*root = newRoot;
} else {
insertNonFull(r, key);
}
}
void traverse(BTreeNode* root) { if (root == NULL) return;
int i;
for (i = 0; i < root->numKeys; i++) { if (!root->isLeaf) {
traverse(root->children[i]);
}
printf("%d ", root->keys[i]);
}
if (!root->isLeaf) { traverse(root->children[i]);
}
}

BTreeNode* search(BTreeNode* root, int key) { int i = 0;

// Find first key greater than or equal to key
while (i < root->numKeys && key > root->keys[i]) { i++;
}

// If key found
if (i < root->numKeys && key == root->keys[i]) {
 
return root;
}

// If leaf node, key not found 
if (root->isLeaf) {
return NULL;
}
// Go to appropriate child
return search(root->children[i], key);
}

int main() {
BTreeNode* root = createNode(1); insert(&root, 10);
insert(&root, 20);
insert(&root, 5);
insert(&root, 6);
insert(&root, 12);
insert(&root, 30);
insert(&root, 7);
insert(&root, 17);
printf("Traversal of the constructed B-tree is:\n"); traverse(root);
int v;
printf(“Enter a value to search:\n”); scanf(“%d”,&v);
BTreeNode* result = search(root, v); if (result != NULL)
printf("\nKey %d found in the B-tree",v);
else
printf("\nKey %d not found in the B-tree",v); return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* parent;
    struct node* left;
    struct node* right;
    char value;
} node;

/* Adds a child node to a parent node, in the position passed.
If position is 0 the child is placed on the left, otherwise it is placed on the
right.*/
node* add_child(node* parent, char value, unsigned int position)
{
    node* child = malloc(sizeof(node));
    if (child == NULL) {
        printf("Failed to allocate memory, aborting...\n");
        exit(1);
    }

    child->value = value;
    child->parent = parent;
    if (position) {
        parent->right = child;
    } else {
        parent->left = child;
    }
    return child;
}

void preorden(node* root)
{
    if (root) {
        printf("%c", root->value);
        preorden(root->left);
        preorden(root->right);
    }
}

void inorden(node* root)
{
    if (root) {
        inorden(root->left);
        printf("%c", root->value);
        inorden(root->right);
    }
}

void posorden(node* root)
{
    if (root) {
        posorden(root->left);
        posorden(root->right);
        printf("%c", root->value);
    }
}

int main(void)
{
    node a = { .value = 'A', .parent = NULL };
    node* b = add_child(&a, 'B', 0);
    node* c = add_child(&a, 'C', 1);
    node* d = add_child(b, 'D', 0);
    node* e = add_child(b, 'E', 1);
    node* f = add_child(c, 'F', 1);
    node* g = add_child(e, 'G', 0);
    node* h = add_child(e, 'H', 1);
    node* i = add_child(f, 'I', 0);

    preorden(&a);
    printf("\n");

    inorden(&a);
    printf("\n");

    posorden(&a);
    printf("\n");

    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
    free(g);
    free(h);
    free(i);
}

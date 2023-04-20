#ifndef _RB_TREES_H_
#define _RB_TREES_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX(X, Y) ((X >= Y) ? X : Y)

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 2 - Double black node
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;


rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
bool valid_colors(rb_tree_t *tree);
bool is_valid_bst(rb_tree_t *node, int min, int max);
size_t black_height(rb_tree_t *node);
size_t check_rb_height(rb_tree_t *node, size_t black_height, size_t rb_height);
int rb_tree_is_valid(rb_tree_t *tree);


#endif /* _RB_TREES_H_ */

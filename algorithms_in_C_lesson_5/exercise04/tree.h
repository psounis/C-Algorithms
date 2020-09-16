/* tree.h : Dilwseis dendrou */

#define TRUE 1
#define FALSE 0

typedef int telem;          /* typos dedomenwn dendrou*/

struct tnode{		 /* Typos komvou listas */
   telem data; 		 /* dedomena */
   struct tnode *left;      /* aristero paidi */
   struct tnode *right;     /* deksi paidi */
};

typedef struct tnode TREE_NODE; /* Sinwnimo tou komvou dendrou */
typedef struct tnode *TREE_PTR; /* Sinwnimo tou deikti komvou */

void TR_init(TREE_PTR *root);
int TR_empty(TREE_PTR root);
telem TR_data(TREE_PTR p);
int TR_insert_root(TREE_PTR *root,telem x);
int TR_insert_left(TREE_PTR node,telem x);
int TR_insert_right(TREE_PTR node,telem x);
int TR_delete_root(TREE_PTR *root, telem *x);
int TR_delete_left(TREE_PTR parent, telem *x);
int TR_delete_right(TREE_PTR parent, telem *x);
void TR_preorder(TREE_PTR v);
void TR_inorder(TREE_PTR v);
void TR_postorder(TREE_PTR v);


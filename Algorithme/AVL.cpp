#include <iostream>
#include <cstdlib>
#include <queue>
#include <list>

using namespace std;

/**
 * The class definition of a node in Binary Search Tree
 **/
class AVLNode
{
private:
  AVLNode* right;
  AVLNode* left;
  int value;
  int balanced;
  
public:
  AVLNode(int e, AVLNode* l = NULL, AVLNode* r = NULL)
  {
    value = e;
    left = l;
    right = r;
  }

  ~AVLNode()
  {
    delete right;
    delete left;
  }

  int getValue()
  {
    return value;
  }

  int getBalanced()
  {
    return balanced;
  }

  void setBalanced(int b)
  {
    balanced = b;
  }

  void setRight(AVLNode* r)
  {
    right = r;
  }

  void setLeft(AVLNode* l)
  {
    left = l;
  }

  void setValue(int e)
  {
    value = e;
  }

  AVLNode* getLeft()
  {
    return left;
  }

  AVLNode* getRight()
  {
    return right;
  }

  bool operator==(const AVLNode* node)
  {
    return (this->value == node->value && this->left == node->left && this->right == node->right);
  }
};


/**
 * Insert a new node whose value = val
 **/
AVLNode* insert(AVLNode* root, int val)
{
  if(root != NULL)
    {
      if(val < root->getValue())
	{
	  if(root->getLeft() != NULL)
	    {
	      insert(root->getLeft(), val);
	    }
	  else
	    {
	      root->setLeft(new AVLNode(val));
	    }
	}
      else if(val >= root->getValue())
	{
	  if(root->getRight() != NULL)
	    {
	      insert(root->getRight(), val);
	    }
	  else
	    {
	      root->setRight(new AVLNode(val));
	    }
	}
      
      return root;
    }
  else // when root is initialized as NULL
    {
      return new AVLNode(val);
    }
}

/**
 * Find the left most Node (the smallest node in all the nodes whose value is superior than root)
 * (used in function remove)
 **/
AVLNode* leftMost(AVLNode* root)
{
  AVLNode* temp;

  while(root->getLeft() != NULL)
    {
      temp = root;
      root = root->getLeft();
    }

  return temp;
}


/**
 * Remove the specified node indicated by root
 * (used for function remove)
 **/
AVLNode* removeNode(AVLNode* root)
{
  // Case 1 : no child
  if(root->getLeft() == NULL && root->getRight() == NULL)
    {
      delete root;
      return NULL;
    }
  // Case 3 : a lot of children --> find leftmost
  else if(root->getLeft() != NULL && root->getRight() != NULL)
    {
      AVLNode* tempRemove = root; // the node to remove

      AVLNode* dad = NULL, // parent node of the left most node 
	*lm = NULL, // the left most node
	*lmRight = NULL, // the rigth node of the left most node
	*tempL = NULL, // pointer to the left value of node to remove
	*tempR = NULL; // pointer to the right value of node to remove

      root = root->getRight();

      if(root->getLeft() == NULL)
	{
	  lm = root;
	  tempL = tempRemove->getLeft();
	  tempR = NULL;
	}
      else
	{
	  dad = leftMost(root);
	  lm = dad->getLeft();
	  lmRight = dad->getLeft()->getRight();
	  tempL = tempRemove->getLeft();
	  tempR = tempRemove->getRight();
	}

      lm->setLeft(tempL);
      lm->setRight(tempR);

      if(lmRight != NULL) 
	{
	  dad->setLeft(lmRight);
	}
      else 
	{
	  if(dad != NULL) dad->setLeft(NULL);
	}	      

      tempRemove->setLeft(NULL);
      tempRemove->setRight(NULL);
      delete tempRemove;

      root = lm;

      return root;
    }
  // Case 2 : got one child
  else
    {
      if(root->getLeft() != NULL && root->getRight() == NULL)
	{
	  AVLNode* temp = root->getLeft();
	  delete root;
	  return temp;
	}
      else if(root->getRight() != NULL && root->getLeft() == NULL)
	{
	  AVLNode* temp = root->getRight();
	  delete root;
	  return temp;
	}
    }
}

/**
 * Remove the node whose value is val
 **/
AVLNode* remove(AVLNode* root, int val)
{
  if(root == NULL) return NULL;
  else
    {
      if(root->getValue() == val) 
	{
	  return removeNode(root);
	}
      else if(root->getValue() > val) 
	{
	  root->setLeft(remove(root->getLeft(), val));
	}
      else if(root->getValue() < val) 
	{
	  root->setRight(remove(root->getRight(), val));
	}

      return root;
    }
}


/**
 * Calculat the height of the AVL
 **/
int height(AVLNode* root)
{
  if(root == NULL) return 0;

  int hleft  = height(root->getLeft());
  int hright = height(root->getRight());

  if(hleft > hright) 
    {
      return 1 + hleft;
    }
  else
    {
      return 1 + hright;
    }
}

AVLNode* father = NULL;

AVLNode* getFather(AVLNode* root, AVLNode* child)
{
  if(root == NULL) return NULL;

  if(root == child) 
    {
      return father;
    }
 
  if(root->getValue() < child->getValue())
    {
      father = root;
      return getFather(root->getRight(), child);
    }
      
  if(root->getValue() >= child->getValue())
    {
      father = root;
      return getFather(root->getLeft(), child);
    }
}

AVLNode* singleRot(AVLNode* a, AVLNode* b, AVLNode* c, AVLNode* dad)
{
  // Rotation left
  if(a->getRight() == NULL)
    {
      a->setLeft( b->getRight() );
      b->setRight( a );
      dad->setLeft( b );
    }

  // Rotation right
  if(a->getLeft() == NULL)
    {
      a->setRight( b->getLeft() );
      b->setLeft( a );
      dad->setRight( b );
    }

  return dad;
}

AVLNode* doubleRot(AVLNode* a, AVLNode* b, AVLNode* c, AVLNode* dad)
{
  if(a->getLeft()==b)
    {
      b->setRight(c->getLeft());
      c->setLeft(b);
      a->setLeft(c);
      singleRotate(a, c, b, dad);
    }
  else 
    {
      b->setLeft(c->getRight());
      c->setRight(b);
      a->setRight(c);
      singleRotate(a, c, b, dad);
    }

 return dad;
}


int hleft, hright;
int fois = 0;
AVLNode* keepRoot;

int makeBalanced(AVLNode* root)
{
  if(fois == 0) 
    {
      keepRoot = root;
      fois++;
    }

  if(root == NULL) return 0;
  
  if(root != NULL)
    {
      hleft  = makeBalanced(root->getLeft());
    }

  if(root != NULL)
    {
      hright = makeBalanced(root->getRight());
    }

  if(hleft - hright == 0)
    {
      root->setBalanced(0);
      return hleft+1;
    }
  
  if(hleft - hright == 1)
    {
      root->setBalanced(1);
      return hleft+1;
    } 

  if(hright - hleft == 1)
    {
      root->setBalanced(2);
      return hright+1;
    }

  AVLNode *a, *b, *c, *dad;

  if(hleft - hright > 1)
    {
      a = root;
      b = root->getLeft();

      if( b->getBalanced() == 1 )
	{
	  c = b->getLeft();
	  dad = getFather(keepRoot, a);
	  dad = singleRot(a, b, c, dad);
	  root = b;
	  hleft = 1;
	  hright = 1;
	}
      else // balanced == 2 
	{
	  c = b->getRight();
	  doubleRot(a, b, c, dad);
	}
    }
   
  if(hleft - hright < 1)
    {
      a = root;
      b = root->getRight();

      if( b->getBalanced() == 1)
	{
	  c = b->getLeft();
	  doubleleRot(a, b, c, dad);
	}
      else
	{
	  c = b->getRight();
	  singleRot(a, b, c, dad);
	}
    }
}

/**
 * Calculate the level of the given node (AVLNode* node)
 **/
int level(AVLNode* root, AVLNode* node)
{
  if(root == NULL || node == NULL) return -1;
  
  if(root == node) return 0;

  if(root->getValue() <= node->getValue()) 
    {
      return 1 + level(root->getRight(), node);
    }
  else    { 
    return 1 + level(root->getLeft(), node);
  }
}


/**
 * The action which a function-pointer points to
 **/
void print(AVLNode* node)
{
  cout << node->getValue() << endl;
}


/**
 * Pre-order traversal, with function-pointer as parameter
 **/
void preOrder(AVLNode* root, void (*fnt)(AVLNode*))
{
  if(root == NULL) return;
  fnt(root);
  preOrder(root->getLeft(), fnt);
  preOrder(root->getRight(), fnt);
}

void pre(AVLNode* root)
{
  if(root == NULL) return;
  cout << root->getValue() << endl;
  pre(root->getLeft());
  pre(root->getRight());
}

/**
 * In-order traversal, with function-pointer as parameter
 **/
void inOrder(AVLNode* root, void (*fnt)(AVLNode*))
{
  if(root != NULL)
    {
      inOrder(root->getLeft(), fnt);
      fnt(root);
      inOrder(root->getRight(), fnt);
    }
}


/**
 * Post-order traversal, with function-pointer as parameter
 **/
void postOrder(AVLNode* root, void (*fnt)(AVLNode*))
{
  if(root != NULL)
    {
      postOrder(root->getLeft(), fnt);
      postOrder(root->getRight(), fnt);
      fnt(root);
    }
}


/**
 * Breadth traversal, with function-pointer as parameter
 **/
void breadth(AVLNode* root, void (*fnt)(AVLNode*))
{
  queue<AVLNode*> q;
  q.push(root);

  while(!q.empty())
    {
      root = q.front();
      q.pop();
      fnt(root);
      if(root->getLeft() != NULL) q.push(root->getLeft());
      if(root->getRight() != NULL) q.push(root->getRight());
    }
}

int main()
{
  /*
  AVLNode* root = new AVLNode(37);
  root = insert(root, 24);
  root = insert(root, 7);
  root = insert(root, 32);
  root = insert(root, 2);
  root = insert(root, 42);
  root = insert(root, 40);
  root = insert(root, 42);
  root = insert(root, 120);
  root = insert(root, 1);
  
  void (*action)(AVLNode*);
  action = &print;
  //preOrder(root, action);
  */

  AVLNode* root = new AVLNode(24);
  root = insert(root, 7);
  root = insert(root, 32);
  root = insert(root, 2);
  root = insert(root, 1);
  makeBalanced(root);
  //pre(root);

  delete root;
  
  return EXIT_SUCCESS;
}

#include <iostream>
#include <cstdlib>
#include <queue>
#include <list>

using namespace std;

/**
 * The class definition of a node in Binary Search Tree
 **/
class BSTNode
{
private:
  BSTNode* right;
  BSTNode* left;
  int value;
  
public:
  BSTNode(int e, BSTNode* l = NULL, BSTNode* r = NULL)
  {
    value = e;
    left = l;
    right = r;
  }

  ~BSTNode()
  {
    delete right;
    delete left;
  }

  int getValue()
  {
    return value;
  }

  void setRight(BSTNode* r)
  {
    right = r;
  }

  void setLeft(BSTNode* l)
  {
    left = l;
  }

  void setValue(int e)
  {
    value = e;
  }

  BSTNode* getLeft()
  {
    return left;
  }

  BSTNode* getRight()
  {
    return right;
  }

  bool operator==(const BSTNode* node)
  {
    return (this->value == node->value && this->left == node->left && this->right == node->right);
  }
};


/**
 * Insert a new node whose value = val
 **/
BSTNode* insert(BSTNode* root, int val)
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
	      root->setLeft(new BSTNode(val));
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
	      root->setRight(new BSTNode(val));
	    }
	}

      return root;
    }
  else // when root is initialized as NULL
    {
      return new BSTNode(val);
    }
}


/**
 * Find the left most Node (the smallest node in all the nodes whose value is superior than root)
 * (used in function remove)
 **/
BSTNode* leftMost(BSTNode* root)
{
  BSTNode* temp;

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
BSTNode* removeNode(BSTNode* root)
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
      BSTNode* tempRemove = root; // the node to remove

      BSTNode* dad = NULL, // parent node of the left most node 
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
	  BSTNode* temp = root->getLeft();
	  delete root;
	  return temp;
	}
      else if(root->getRight() != NULL && root->getLeft() == NULL)
	{
	  BSTNode* temp = root->getRight();
	  delete root;
	  return temp;
	}
    }
}

/**
 * Remove the node whose value is val
 **/
BSTNode* remove(BSTNode* root, int val)
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
 * Calculat the height of the BST
 **/
int height(BSTNode* root)
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


/**
 * Calculate the level of the given node (BSTNode* node)
 **/
int level(BSTNode* root, BSTNode* node)
{
  if(root == NULL || node == NULL) return -1;
  
  if(root == node) return 0;

  if(root->getValue() <= node->getValue()) 
    {
      return 1 + level(root->getRight(), node);
    }
  else
    { 
      return 1 + level(root->getLeft(), node);
    }
}


/**
 * Verify whether the BST is balanced or not
 * If BST is unbalanced, store all the unbalanced nodes into a list (unbNode)
 **/
bool balanced(BSTNode* root, list<BSTNode*>& unbNode)
{
  if(root == NULL) return true;
  
  if(root->getLeft() == NULL && root->getRight() == NULL) return true;
  
  int delta = height(root->getLeft()) - height(root->getRight());

  if(delta >= -1 && delta <= 1) 
    {
      return true;
    }
  else
    {
      BSTNode* oldRoot = root;
      int levelOther = delta > 0 ? height(root->getRight()) : height(root->getLeft());
      queue<BSTNode*> q;
      q.push(root);

      // use the principe of Breadth Traversal
      while(!q.empty())
	{
	  root = q.front();
	  q.pop();
	  if(level(oldRoot, root) > levelOther + 1) 
	    // compare to the deepest node of the shorter subtree
	    // if the distance between them >= 2, than put that node into the list
	    {
	      unbNode.push_back(root);
	    }
	  if(root->getLeft() != NULL) q.push(root->getLeft());
	  if(root->getRight() != NULL) q.push(root->getRight());
	}
    }

  return false;
}


/**
 * The action which a function-pointer points to
 **/
void print(BSTNode* node)
{
  cout << node->getValue() << endl;
}


/**
 * Pre-order traversal, with function-pointer as parameter
 **/
void preOrder(BSTNode* root, void (*fnt)(BSTNode*))
{
  if(root == NULL) return;
  fnt(root);
  preOrder(root->getLeft(), fnt);
  preOrder(root->getRight(), fnt);
}


/**
 * In-order traversal, with function-pointer as parameter
 **/
void inOrder(BSTNode* root, void (*fnt)(BSTNode*))
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
void postOrder(BSTNode* root, void (*fnt)(BSTNode*))
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
void breadth(BSTNode* root, void (*fnt)(BSTNode*))
{
  queue<BSTNode*> q;
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
  BSTNode* root = new BSTNode(10);
  root = insert(root, 5);
  root = insert(root, 12);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 4);
  root = insert(root, 8);
  root = insert(root, 6);
  root = insert(root, 9);

  root = remove(root, 10);
  
  void (*action)(BSTNode*);
  action = &print;
  preOrder(root, action);

  delete root;
 
  return EXIT_SUCCESS;
}

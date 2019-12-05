//BST.cpp
//BST class interface

#include "BST.h"

//default constructor
BST::BST(): root{nullptr}
{}

//destructor
BST::~BST()
{
    //remove all apps recursively
    removeAll();
}

//insert app into tree
void BST::insert(App *& a)
{
    //if tree is empty
    if(!root)
    {
        root = a;
        return;
    }

    //if tree has content
    insert(a, root);
}

//insert app into tree recursive
void BST::insert(App * a, App * root)
{
    //if app to add is less than current root
    if(*a < *root)
    {
        if(root->goLeft())
        {
            insert(a, root->goLeft());
            return;
        }
        root->setLeft(a);
        return;
    }
    
    //if app to add is greater than or equal to current node
    if(root->goRight())
    {
        insert(a, root->goRight());
        return;
    }
    root->setRight(a);
}

//remove all apps from tree wrapper
void BST::removeAll()
{
    //if tree is empty
    if(!root)
        return;

    //if tree has content
    removeAll(root);
}

//retrieve item from tree wrapper
bool BST::retrieve(char * name)
{
    //if tree is empty
    if(!root)
        return false;

    //if tree has content
    return retrieve(name, root);
}

//retrieve recursive
bool BST::retrieve(char * name, App * root)
{
   //if passed in name is equal to current name
   if(*root == name)
   {
       root->display();
       return true;
   }

   //if passed in name is less than current name, traverse left
   if(name < *root)
   {
       if(root->goLeft())
           return retrieve(name, root->goLeft());
       return false;
   }

   //if passed in name is greater than current name, traverse right
   if(name > *root)
   {
       if(root->goLeft())
           return retrieve(name, root->goRight());
       return false;
   }

   //if no match found
   return false;
}

//display all apps
void BST::display()
{
    //if tree is empty
    if(!root)
        return;

    cout << "Displaying all apps: \n";

    //if tree has content
    display(root);
    cout << endl;
}

//display all apps recursive
void BST::display(App * root)
{
    //traverse left
    if(root->goLeft())
        display(root->goLeft());

    //display root
    root->display();

    //traverse right
    if(root->goRight())
        display(root->goRight());
}

//remove app from tree
void BST::remove(char * name)
{
    //if tree is empty
    if(!root)
        return;

    //if tree has content
    remove(name, root);    
}

//remove app recursive
void BST::remove(char * name, App *& root)
{
    //if root is to be removed
    if(*root == name)
    {
        //if root has no children
        if(root->isLeaf())
            delete root;

        //if root has one child
        else if(root->oneChild())
        {
            //if only child is left
            if(root->goLeft())
            {
                App * temp = root;
                root = temp->goLeft();
                delete temp;
            }
            //if only child is right
            if(root->goRight())
            {
                App * temp = root;
                root = temp->goRight();
                delete temp;
            }
        }

        //if root has two children
        else
        {
            //locate inorder successor
            App * ios = root->inOrder();
            App * iosp = root->inOrderParent();

            //if successor has children
            if(ios->goLeft() && iosp != root)
                iosp->setRight(ios->goLeft());

            if(ios->goLeft() && iosp == root)
            {
                ios->setRight(root->goRight());
                delete root;
                root = ios;
                return;
            }     

            //set ios pointers to move ios to root
            ios->setLeft(root->goLeft());
            ios->setRight(root->goRight());
            delete root;
            root = ios;
        }
    }
    else
    {
        if(name < *root)
        {
            if(root->goLeft())
                remove(name, root->goLeft());
        }
        else
        {
            if(root->goRight())
                remove(name, root->goRight());
        }
    }
}

//compound assignment overload
BST & BST::operator += (App * a)
{
    insert(a);
    return *this;
}

//remove all recursive
void BST::removeAll(App * root)
{
    //traverse left
    if(root->goLeft())
        removeAll(root->goLeft());

    //traverse right
    if(root->goRight())
        removeAll(root->goRight());

    //delete root
    delete root;
}



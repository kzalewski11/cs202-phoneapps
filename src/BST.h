//BST.h
//BST class interface

#include "App.h"

class BST
{
    public:
        BST();  //default constructor
        ~BST(); //destructor

        void insert(App *&);   //insert app into tree
        void removeAll();   //remove all apps
        bool retrieve(char *); //retrieve using search term
        void display();     //display entire tree
        void remove(char *); //remove app from tree

        BST& operator += (App*);   //compound assignment overload

    private:
        App * root;

        void insert(App *, App *);  //recursive insert
        void removeAll(App *); //recursive remove all
        bool retrieve(char *, App*);    //recursive retrieve
        void display(App *);   //recursive tree display
        void remove(char *, App*&); //remove app from tree
};

//App.h
//App class interface

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class App
{
    public:
        App();  //default constructor
        App(const App&);    //copy constructor
        virtual ~App(); //destructor

        App *& goLeft(); //go left
        App *& goRight();    //go right
        App * inOrder();   //find inorder successor
        App * inOrderParent();  //find inorder successor parent
        void setLeft(App *); //set left
        void setRight(App *);   //set right
        bool isLeaf();  //app is leaf
        bool oneChild();    //app has one child

        App& operator = (const App &);  //assignment operator overload

        virtual void display() = 0; //pure virtual display

        //operator overloads

        // equality
        friend bool operator == (const App &, const char *);
        friend bool operator == (const char *, const App &);
        friend bool operator == (const App&, const App &);

        //inequality
        friend bool operator != (const App &, const char *);
        friend bool operator != (const char *, const App &);
        friend bool operator != (const App &, const App&);

        //less than
        friend bool operator < (const App &, const char *);
        friend bool operator < (const char *, const App &);
        friend bool operator < (const App &, const App&);

        //greater than
        friend bool operator > (const App &, const char *);
        friend bool operator > (const char *, const App &);
        friend bool operator > (const App &, const App&);

        //less than or equal to
        friend bool operator <= (const App &, const char *);
        friend bool operator <= (const char *, const App &);
        friend bool operator <= (const App&, const App &);

        //greater than or equal to
        friend bool operator >= (const App &, const char *);
        friend bool operator >= (const char *, const App &);
        friend bool operator >= (const App&, const App &);

        //insertion
        friend ifstream& operator >> (ifstream &, App *);


    protected:
        App * left;
        App * right;

        char * title;   //app title
        App * inOrder(App *);   //find inorder successor
        App * inOrderParent(App *); //find inorder successor parent
};

class Game: public App
{
    public:
        Game(); //default constructor
        Game(int);  //constructor with name and score
        ~Game();    //destructor
        void display();     //display

        //compound assignment overload
        Game& operator += (const int);
    
        //extraction operator overload
        friend ofstream& operator << (ofstream &, const App *);

    private:
        int hiScore;    //high score stored in app
};

class News: public App
{
    public:
        News(); //default constructor
        News(char *);   //constructor with name and headline
        News(const News&); //copy constructor
        ~News();    //destructor

        void display(); //display

        //extraction operator overload
        friend ofstream& operator << (ofstream &, const News *);

    private:
        char * headline;    //current local news headline
};

class Weather: public App
{
    public:
        Weather();  //default constructor
        Weather(int);   //constructor with name and temp
        ~Weather(); //destructor

        void display(); //display

        //extraction operator overload
        friend ofstream& operator << (ofstream &, const Weather *);
        
    private:
        int temperature;    //current temperature

};

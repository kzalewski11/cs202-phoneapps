//App.cpp
//App class implementation

#include "App.h"

//app default constructor
App::App(): left{nullptr}, right{nullptr}, title{nullptr}
{}

//app copy constructor
App::App(const App& a)
{
    title = new char[strlen(a.title) + 1];
    strcpy(title, a.title);
    left = a.left;
    right = a.right;
}

//app destructor
App::~App()
{
    left = NULL;
    right = NULL;
    delete title;
    title = NULL;
}

//go left
App *& App::goLeft()
{
    return left;
}

//go right
App *& App::goRight()
{
    return right;
}

//find inorder successor
App * App::inOrder()
{
    if(left)
        return inOrder(left);
    return this;
}

//find inorder successor
App * App::inOrder(App *a)
{
    //if right exists
    if(a->right)
        inOrder(a->right);
    return a;
}

//find inorder successor parent
App * App::inOrderParent()
{
    if(!left->right)
        return this;
    if(left)
        return inOrderParent(left);
    return this;
}

//find inorder successor parent
App * App::inOrderParent(App * a)
{
    if(a->right)
    {
        if(a->right->right)
            inOrderParent(a->right);
    }
    return a;
}

//set left
void App::setLeft(App * toSet)
{
    left = toSet;
}

//set right
void App::setRight(App * toSet)
{
    right = toSet;
}

bool App::isLeaf()
{
    if(!left && !right)
        return true;
    return false;
}

bool App::oneChild()
{
    if((left && !right) || (right && !left))
        return true;
    return false;
}

//assignment operator overload
App& App::operator = (const App& a)
{
    title = new char[strlen(a.title) + 1];
    strcpy(title, this->title);
    left = a.left;
    right = a.right;
    return *this;
}

//== overload
bool operator == (const App & a, const char * name)
{
    return strcmp(a.title, name) == 0;
}

bool operator == (const char * name, const App & a)
{
    return strcmp(a.title, name) == 0;
}

bool operator == (const App & a, const App & b)
{
    return strcmp(a.title, b.title) == 0;
}

//!= overload
bool operator != (const App & a, const char * name)
{
    return strcmp(a.title, name) != 0;
}
bool operator != (const char * name, const App & a)
{
    return strcmp(a.title, name) != 0;
}

bool operator != (const App & a, const App & b)
{
    return strcmp(a.title, b.title) != 0;
}

//< overload
bool operator < (const App & a, const char * name)
{
    return strcmp(a.title, name) < 0;
}

bool operator < (const char * name, const App & a)
{
    return strcmp(name, a.title) < 0;
}

bool operator < (const App & a, const App & b)
{
    return strcmp(a.title,  b.title) < 0;
}

//> overload
bool operator > (const App & a, const char * name)
{
    return strcmp(a.title, name) > 0;
}

bool operator > (const char * name, const App & a)
{
    return strcmp(name, a.title) > 0;
}

bool operator > (const App & a, const App & b)
{
    return strcmp(a.title, b.title) > 0;
}

//<= overload
bool operator <= (const App & a, const char * name)
{
    return strcmp(a.title, name) <= 0;
}

bool operator <= (const char * name, const App & a)
{
    return strcmp(name, a.title) <= 0;
}

bool operator <= (const App & a, const App & b)
{
    return strcmp(a.title, b.title) <= 0;
}

//>= overload
bool operator >= (const App & a, const char * name)
{
    return strcmp(a.title, name) >= 0;
}

bool operator >= (const char * name, const App & a)
{
    return strcmp(name, a.title) >= 0;
}

bool operator >= (const App & a, const App & b)
{
    return strcmp(a.title, b.title) >= 0;
}

//insertion overload
ifstream& operator >> (ifstream &in, App *a)
{
    a->title = new char[100];
    in.get(a->title, 100, '\n');
    in.ignore(100, '\n');
    
    return in;
}

//Game default constructor
Game::Game(): hiScore{0}
{}

//Game constructor with args
Game::Game(int s): hiScore{s}
{}

//Game destructor
Game::~Game()
{
    hiScore = 0;
}

//Game display function
void Game::display()
{
    cout << "App name: " << title << endl
        << "High Score: " << hiScore << endl << endl;
}

//compound assignment overload
Game& Game::operator += (const int n)
{
    hiScore += n;
    return *this;
}
    
//extraction operator overload
ofstream& operator << (ofstream & out, const Game * g)
{
    //out << g->hiScore << endl;
    return out;
}

//News constructor
News::News(): headline{nullptr}
{}

//News constructor with headline
News::News(char * h)
{
    headline = new char[strlen(h)+1];
    strcpy(headline, h);
}

//News copy constructor
News::News(const News& n): App(n)
{
    headline = new char[strlen(n.headline) + 1];
    strcpy(headline, n.headline);
}

//News destructor
News::~News()
{
    delete headline;
}

//News display
void News::display()
{
    cout << "App name: " << title << endl
        << "Current Headline: " << headline << endl << endl;
}

//extraction operator overload
ofstream& operator << (ofstream & out, const News * n)
{
    out << n->headline << endl;
    return out;
}

//Weather constructor
Weather::Weather(): temperature{0}
{}

//Weather constructor with temp
Weather::Weather(int t): temperature{t}
{}

//Weather destructor
Weather::~Weather()
{
    temperature = 0;
}

//Weather display
void Weather::display()
{
    cout << "App name: " << title << endl
        << "Current Temperature: " << temperature << endl << endl;
}

//extraction operator overload
ofstream& operator << (ofstream & out, const Weather * w)
{
    out << w->temperature << endl;
    return out;
}

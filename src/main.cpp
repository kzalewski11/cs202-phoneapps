    //main.cpp

#include "BST.h"

int main()
{
    //user welcome message
    cout << "Welcome to app info!\n"
        << "Here you will find info on your apps.\n\n";

    //create tree
    BST * tree = new BST();

    //declare fstream variables
    ifstream in("apps.txt");
    ofstream out("appsOut.txt");

    //create app names
    /*
    char n1[] = "Asteroids";
    char n2[] = "NewsSource";
    char n3[] = "LocalWeather";
    char n4[] = "CubeGame";
    char n5[] = "Reddit";
    char n6[] = "WorldWeather";
    */

    //create news headlines
    char h1[] = "Florida man kicks local business in half";
    char h2[] = "Floor Legos becoming serious issue in local Walmart";

    /*
    //create apps manually
    App * a1 = new Game(n1, 1200);
    App * a2 = new News(n2, h1);
    App * a3 = new Weather(n3, 62);
    App * a4 = new Game(n4, 1500);
    App * a5 = new News(n5, h2);
    App * a6 = new Weather(n6, 75);
    */

    //create apps
    App * a1 = new Game(1200);
    App * a2 = new News(h1);
    App * a3 = new Weather(76);
    App * a4 = new Game(1500);
    App * a5 = new News(h2);
    App * a6 = new Weather(84);

    //set app names from file
    in >> a1;
    in >> a2;
    in >> a3;
    in >> a4;
    in >> a5;
    in >> a6;

    //output info to output file
    out << a1;
    out << a2;
    out << a3;
    out << a4;
    out << a5;
    out << a6;

    //close file stream
    in.close();
    out.close();

    //insert apps into tree
    tree->insert(a1);
    //tree += a2;
    tree->insert(a2);
    tree->insert(a3);
    tree->insert(a4);
    tree->insert(a5);
    tree->insert(a6);

    //display tree
    tree->display();

    //test retrieve
    char n1[] = "Asteroids";
    char n2[] = "Asteroibs";
    char n3[] = "NewsSource";

    //test exists
    bool retrieved = tree->retrieve(n1);
    if(retrieved)
        cout << "App found!\n";
    else
        cout << "App not found\n";

    //test does not exist
    retrieved = tree->retrieve(n2);
    if(retrieved)
        cout << "App found!\n";
    else
        cout << "App not found\n";
    

    //remove test
    tree->remove(n3);
    tree->display();

    //delete tree
    delete tree;
    
    //return from main
    return 0;
}

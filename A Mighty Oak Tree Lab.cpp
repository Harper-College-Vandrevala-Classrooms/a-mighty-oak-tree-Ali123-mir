#include <iostream>
#include <string>
using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) {
        this->name = name;
    }

    string get_name() {
        return this->name;
    }
};

class Node {
private:
    Squirrel* squirrel; 
    Node* left_child;   
    Node* right_child;  

public:
   
    Node(Squirrel* squirrel) : squirrel(squirrel), left_child(nullptr), right_child(nullptr) {}

    
    void set_left(Node* left) {
        this->left_child = left;
    }

   
    void set_right(Node* right) {
        this->right_child = right;
    }

 
    Node* left() const {
        return this->left_child;
    }

    
    Node* right() const {
        return this->right_child;
    }

    
    Squirrel* get_squirrel() const {
        return this->squirrel;
    }
};


void traverse_tree(Node* root) {
    if (root == nullptr) {
        return;
    }

    
    cout << root->get_squirrel()->get_name() << " ";

    
    traverse_tree(root->left());

    
    traverse_tree(root->right());
}


int main() {
    
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    
    Node node_one(&cheeks);
    Node node_two(&squeaks);
    Node node_three(&fluffybutt);

    
    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    
    Node* left_node = node_one.left();
    Node* right_node = node_one.right();

    
    cout << "Left child: " << left_node->get_squirrel()->get_name() << endl;
    cout << "Right child: " << right_node->get_squirrel()->get_name() << endl;

    
    cout << "Tree traversal (preorder): ";
    traverse_tree(&node_one);
    cout << endl;

    return 0;
}

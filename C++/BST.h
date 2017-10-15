class BST {

    private:

    struct node{
        int data;
        node* left;
        node* right;
    };

    node* root;

    public:

    BST();
    node* createNode(int data);


}
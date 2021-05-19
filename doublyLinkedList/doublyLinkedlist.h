struct Node{
    int value;
    Node* prev;
    Node* next;
};

class DLL{
public:
    DLL();
    ~DLL();
    bool search();
    void insert();
    void erase();  /*後に、返り値を出すように変更？*/
    int minimum();
    int maximum();

private:
    Node node;
    Node* head;
};
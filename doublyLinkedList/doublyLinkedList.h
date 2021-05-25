struct Node{
    int value;
    Node* prev;
    Node* next;
};

class DLL{
public:
    DLL();
    ~DLL();
    Node* search(int);
    void insert(Node*, int);
    void erase(Node*);  /*後に、返り値を出すように変更？*/
    int* pminimum;
    int* pmaximum;
    Node* head;

    //for debug
    void showList();

private:
    void update(int);
};

//headをprivateにした時、その後ろにつなげた
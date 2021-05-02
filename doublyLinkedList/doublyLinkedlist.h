struct Cell{
    int value;
    int* prev;
    int* next;
};

class DLL{
public:
    DLL(int);
    ~DLL();
    bool search();
    void insert();
    void erase(); /*後に、返り値を出すように変更？*/
    int minimum();
    int maximum();

private:
    Cell cell;
    int* head;
};

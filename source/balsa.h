
class Balsa {
private:
    int nerds = 0;
    int serfs = 0;

public:

    bool isFull();
    bool addNerd();
    bool addSerf();
};

bool Balsa::addNerd(){

    if(isFull()) return false;

    if (serfs>1 & nerds>=2) return false;

    nerds++;
    return true;
}

bool Balsa::addSerf(){
    
    if(isFull()) return false;

    if (nerds>1 & serfs>=2) return false;

    serfs++;
    return true;
    
}

bool Balsa::isFull(){

    return (nerds + serfs) >= 4
}

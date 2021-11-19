#include <iostream>
using namespace std;

class CoffeeMachineInterface {
    public:
        void FirstSelection(){
            cout<<"First Flavour selected in the interface "<<endl;
        }
        void SecondSelection(){
            cout<<"Second Flavour selected in the interface"<<endl;
        }
};

class OldCoffeeMachine {
    public:
        void FirstSelection(){
            cout<<"First Flavour selected in old machine"<<endl;
        }
        void SecondSelection(){
            cout<<"Second Flavour selected in old machine"<<endl;
        }
};

class CoffeeTouchscreenAdapter : public CoffeeMachineInterface {
    private:
        OldCoffeeMachine* OldVendingMachine;
    public:
        CoffeeTouchscreenAdapter(OldCoffeeMachine* OldVendingMachine){
            OldVendingMachine = OldVendingMachine;
        }
        void FirstSelection(){
            OldVendingMachine -> FirstSelection();
        }
        void SecondSelection(){
            OldVendingMachine -> SecondSelection();
        }
};

int main() {
    CoffeeMachineInterface* newMachine = new CoffeeMachineInterface;
    OldCoffeeMachine* oldMachine = new OldCoffeeMachine;
    CoffeeTouchscreenAdapter* adapter = new CoffeeTouchscreenAdapter(oldMachine);
    newMachine -> FirstSelection();
    adapter -> FirstSelection();
    newMachine -> SecondSelection();
    adapter -> SecondSelection();

    return 0;
}

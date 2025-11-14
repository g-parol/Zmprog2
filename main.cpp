#include <iostream>


using namespace std;

class Kalkulator {
    public:
    virtual ~Kalkulator() = default;
    virtual float Dzialanie(float a, int b) = 0;
};

class DodawanieKalkulator: public Kalkulator{
public:
    float Dzialanie(float a, int b)override{
        return a+b;
    }
};
class OdejmowanieKalkulator: public Kalkulator{
public:
    float Dzialanie(float a, int b)override{
        return a-b;
    }
};
class MnozenieKalkulator: public Kalkulator{
public:
    float Dzialanie(float a, int b)override{
        return a*b;
    }
};
class DzielenieKalkulator: public Kalkulator{
public:
    float Dzialanie(float a, int b)override{
        if(b==0){
            return 0.0f;
        }else{
        return a/b;
        }
    }
};


class KalkulatorKreator{
    private:
        Kalkulator* kalkulator;
    public:
    KalkulatorKreator(char typ):kalkulator(nullptr){
        switch(typ){
            case '+':
            kalkulator= new DodawanieKalkulator;
            break;
            case '-':
            kalkulator = new OdejmowanieKalkulator;
            break;
            case '*':
            kalkulator = new MnozenieKalkulator;
            break;
            case '/':
            kalkulator = new DzielenieKalkulator;
            break;
        }
    }

    Kalkulator* ZwrocKalkulator(){ 
        return kalkulator;
    };
    void ZniszczKalkulator(){
        delete kalkulator;
        kalkulator = nullptr;
    }
    ~KalkulatorKreator(){
        delete kalkulator;
    }

};


int main(){

cout<<"WEL24MX1S4"<<endl;
cout<<"Grzegorz Parol"<<endl;
cout<<"14.11.2025"<<endl;
cout<<"linux"<<endl;
cout<<"10.202.131.88 zestaw nr 4"<<endl;


char typ;
float a;
int b;


cout<<"Wprowadź pierwsza cyfre :";
cin>>a;
cout<<"Wprowadź drugą cyfre: ";
cin>>b;
cout<<"Wprowadź operator do użycia(znak matematyczny): ";
cin>>typ;

KalkulatorKreator kreator(typ);
Kalkulator* liczenie = kreator.ZwrocKalkulator();

float wynik= liczenie->Dzialanie(a,b);

cout<<"Wynik operacji wynosi:"<<wynik;



kreator.ZniszczKalkulator();



};
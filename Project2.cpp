#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class rules {
public:
    string failas, juosta, esama_busena[100], nauja_busena[100];
    char esamas_sim[100], naujas_sim[100], kryptis[100];
    int galva;
    int stulpelis = 0;


    void ivedimas() {
        cout << "Iveskite faila: ";
        cin >> failas;
        ifstream duom(failas);
        duom >> galva;
        duom >> juosta;
        while (!duom.eof()) {
            duom >> esama_busena[stulpelis] >> esamas_sim[stulpelis] >> naujas_sim[stulpelis] >> kryptis[stulpelis] >> nauja_busena[stulpelis];
            stulpelis++;
        }
        duom.close();

    }
    void masina()
    {
        string busena = "0";
        while (galva >= 0) {
            for (int i = 0; i < stulpelis; i++) {
                if (esama_busena[i] == busena) {
                    if (esamas_sim[i] == juosta[galva]) {
                        juosta[galva] = naujas_sim[i];
                        if (kryptis[i] == 'R') {
                            galva++;
                        }
                        if (kryptis[i] == 'L') {
                            galva--;
                        }
                        busena = nauja_busena[i];
                        cout << juosta << endl;
                    }
                }
            }
        }
    }
};

int main()
{
    rules turing;
    turing.ivedimas();
    turing.masina();

}


#include <fstream>
#include <iostream>

using namespace std;

const char DFPav[] = "duomenys.txt";
const char RFPav[] = "rezultatai.txt";
const int MAX_DIENU = 100;

void skaitymas(int &n, int menesiai[], int dienos[], float mases[], int baravykai[], int raudonvirsiai[]);
void derlingiausios_dienos(int n, int menesiai[], int dienos[], float mases[], int baravykai[], int raudonvirsiai[], int &derlingiausia_mase, int &derlingiausia_baravykais, int &derlingiausia_raudonvirsiais);

int main() {
    int n;
    int menesiai[MAX_DIENU];
    int dienos[MAX_DIENU];
    float mases[MAX_DIENU];
    int baravykai[MAX_DIENU];
    int raudonvirsiai[MAX_DIENU];
    int derlingiausia_mase, derlingiausia_baravykais, derlingiausia_raudonvirsiais;

    skaitymas(n, menesiai, dienos, mases, baravykai, raudonvirsiai);
    derlingiausios_dienos(n, menesiai, dienos, mases, baravykai, raudonvirsiai, derlingiausia_mase, derlingiausia_baravykais, derlingiausia_raudonvirsiais);

    ofstream rf (RFPav);
    rf << "Derlingiausia diena: ";
    if (derlingiausia_mase>=0) {
        rf << menesiai[derlingiausia_mase] << ' ' << dienos[derlingiausia_mase] << endl;
    } else {
        rf << "nėra" << endl;
    }
    rf << "Derlingiausia baravykų diena: ";
    if (derlingiausia_baravykais>=0) {
        rf << menesiai[derlingiausia_baravykais] << ' ' << dienos[derlingiausia_baravykais] << endl;
    } else {
        rf << "nėra" << endl;
    }
    rf << "Derlingiausia raudonviršių diena: ";
    if (derlingiausia_raudonvirsiais>=0) {
        rf << menesiai[derlingiausia_raudonvirsiais] << ' ' << dienos[derlingiausia_raudonvirsiais] << endl;
    } else {
        rf << "nėra" << endl;
    }

    rf.close();

    return 0;
}

void skaitymas(int &n, int menesiai[], int dienos[], float mases[], int baravykai[], int raudonvirsiai[]) {
    ifstream df (DFPav);

    df >> n;
    for(int i=0; i<n; i++) {
        df >> menesiai[i] >> dienos[i] >> mases[i] >> baravykai[i] >> raudonvirsiai[i];
    }

    df.close();
}

void derlingiausios_dienos(int n, int menesiai[], int dienos[], float mases[], int baravykai[], int raudonvirsiai[], int &derlingiausia_mase, int &derlingiausia_baravykais, int &derlingiausia_raudonvirsiais) {
    int max_mase_indeksas;
    float max_mase=0;
    int max_baravykais_indeksas, max_baravyku=0;
    int max_raudonvirsiais_indeksas, max_raudonvirsiu=0;

    for(int i=0; i<n; i++) {
        if (mases[i] > max_mase) {
            max_mase_indeksas = i;
            max_mase = mases[i];
        }
        if (baravykai[i] > max_baravyku) {
            max_baravykais_indeksas = i;
            max_baravyku = baravykai[i];
        }
        if (raudonvirsiai[i] > max_raudonvirsiu) {
            max_raudonvirsiais_indeksas = i;
            max_raudonvirsiu = raudonvirsiai[i];
        }
    }
    if (max_mase) {
        derlingiausia_mase = max_mase_indeksas;
    } else {
        derlingiausia_mase = -1;
    }
    if (max_baravyku) {
        derlingiausia_baravykais = max_baravykais_indeksas;
    } else {
        derlingiausia_baravykais = -1;
    }
    if (max_raudonvirsiu) {
        derlingiausia_raudonvirsiais = max_raudonvirsiais_indeksas;
    } else {
        derlingiausia_raudonvirsiais = -1;
    }
}

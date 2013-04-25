#include <fstream>

using namespace std;

const char DFPav[] = "duomenys.txt";
const char RFPav[] = "rezultatai.txt";
const int MAX_DIENU = 100;

struct dienos_rezultatas {
	int menuo;
	int diena;
	float mase;
	int baravyku;
	int raudonvirsiu;
};

void skaitymas(int &n, dienos_rezultatas masyvas[]);
void derlingiausios_dienos(int n, dienos_rezultatas masyvas[], int &derlingiausia_mase, int &derlingiausia_baravykais, int &derlingiausia_raudonvirsiais);

int main() {
	int n;
	dienos_rezultatas masyvas[MAX_DIENU];
	int derlingiausia_mase, derlingiausia_baravykais, derlingiausia_raudonvirsiais;

	skaitymas(n, masyvas);
	derlingiausios_dienos(n, masyvas, derlingiausia_mase, derlingiausia_baravykais, derlingiausia_raudonvirsiais);

	ofstream rf (RFPav);

	rf << "Derlingiausia diena: " << masyvas[derlingiausia_mase].menuo << ' ' << masyvas[derlingiausia_mase].diena << endl;
	rf << "Derlingiausia baravykų diena: " << masyvas[derlingiausia_baravykais].menuo << ' ' << masyvas[derlingiausia_baravykais].diena << endl;
	rf << "Derlingiausia raudonviršių diena: " << masyvas[derlingiausia_raudonvirsiais].menuo << ' ' << masyvas[derlingiausia_raudonvirsiais].diena << endl;

	rf.close();

	return 0;
}

void skaitymas(int &n, dienos_rezultatas masyvas[]) {
	ifstream df (DFPav);

	df >> n;
	for(int i=0; i<n; i++) {
		df >> masyvas[i].menuo >> masyvas[i].diena >> masyvas[i].mase >> masyvas[i].baravyku >> masyvas[i].raudonvirsiu;
	}

	df.close();
}

void derlingiausios_dienos(int n, dienos_rezultatas masyvas[], int &derlingiausia_mase, int &derlingiausia_baravykais, int &derlingiausia_raudonvirsiais) {
	int max_mase_indeksas; float max_mase=0;
	int max_baravykais_indeksas, max_baravyku=0;
	int max_raudonvirsiais_indeksas, max_raudonvirsiu=0;

	for(int i=0; i<n; i++) {
		if (masyvas[i].mase > max_mase) {
			max_mase_indeksas = i;
			max_mase = masyvas[i].mase;
		}
		if (masyvas[i].baravyku > max_baravyku) {
			max_baravykais_indeksas = i;
			max_baravyku = masyvas[i].baravyku;
		}
		if (masyvas[i].raudonvirsiu > max_raudonvirsiu) {
			max_raudonvirsiais_indeksas = i;
			max_raudonvirsiu = masyvas[i].raudonvirsiu;
		}
	}
	derlingiausia_mase = max_mase_indeksas;
	derlingiausia_baravykais = max_baravykais_indeksas;
	derlingiausia_raudonvirsiais = max_raudonvirsiais_indeksas;
}

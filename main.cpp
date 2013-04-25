#include <fstream>

using namespace std;

const char DFPav[] = "duomenys.txt";
const char RFPav[] = "rezultatai.txt";
const MAX_DIENU = 100;

struct dienos_rezultatas {
	int menuo;
	int diena;
	float mase;
	int baravyku;
	int raudonvirsiu;
};

void skaitymas();

int main() {
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

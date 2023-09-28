//Hunde vs Katzen
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

#define KATZEN_ANZAHL 5
#define HUNDE_ANZAHL 5
#define LEBEN_KATZEN 100
#define LEBEN_HUNDE 150
#define KRAFT_KATZEN 25
#define KRAFT_HUNDE 15




class Tiere {
private:
	int kraft_tier;
	int leben_tier;

public:
	void setKraft(int kraft) {
		kraft_tier = kraft;
	}
	int getKraft() {
		return kraft_tier;
	}
	void setLeben(int leben) {
		leben_tier = leben;
	}
	int getLeben() {
		return leben_tier;
	}
	void meinStatus() {
		printf("Ich habe noch %i Lebenspunkte!\n\n\n", getLeben());
	}
};

class Hund : Tiere {

};

class Katze : Tiere {

};


bool lebtNochMindestensEiner(Tiere* Tiername[], int anzahl) {
	for (int i = 0; i < anzahl; i++)
	{
		if (Tiername[i] == NULL) {
			continue;
		}
		if (Tiername[i]->getLeben() > 0) {
			return true;
		}
	}
	return false;
}





int main() {
	srand(time(NULL));

	Tiere* Hundehorde[HUNDE_ANZAHL];
	Tiere* Katzenhorde[KATZEN_ANZAHL];


	for (int i = 0; i < HUNDE_ANZAHL; i++)
	{
		Hundehorde[i] = new Tiere();
		Hundehorde[i]->setKraft(rand() % KRAFT_HUNDE + 1);		//max. 30
		Hundehorde[i]->setLeben(rand() % LEBEN_HUNDE + 1);	//max. 300
	}
	//Hunde erzeugen

	for (int i = 0; i < KATZEN_ANZAHL; i++)
	{
		Katzenhorde[i] = new Tiere();
		Katzenhorde[i]->setKraft(rand() % KRAFT_KATZEN + 1);	//max. 40
		Katzenhorde[i]->setLeben(rand() % LEBEN_KATZEN + 1);	//max. 250
	}
	//Katzen erzeugen



	for (int i = 0; i < HUNDE_ANZAHL; i++)		//Hunde HP ausprinten
	{
		printf("vorher Leben Hund %i: %i\n ", i + 1, Hundehorde[i]->getLeben());
	}
	//Hunde Leben ausgeben

	printf("\n\n");

	for (int i = 0; i < KATZEN_ANZAHL; i++)		//Katzen HP ausgeben
	{
		printf("vorher Leben Katze %i : %i\n ", i + 1, Katzenhorde[i]->getLeben());
	}
	//Katzen leben ausgeben

	printf("\n\n");

	for (int i = 0; i < HUNDE_ANZAHL; i++)		//Hunde DMG ausprinten
	{
		printf("Damage Hund %i: %i\n ", i + 1, Hundehorde[i]->getKraft());
	}
	//Hunde schaden ausgeben

	printf("\n\n");

	for (int i = 0; i < KATZEN_ANZAHL; i++)		//Katzen DMG ausgeben
	{
		printf("Damage Katze %i : %i\n ", i + 1, Katzenhorde[i]->getKraft());
	}
	//Kazen schaden ausgeben

	printf("\n\n");



	do {
		for (int i = 0; i < HUNDE_ANZAHL; i++)						//geht alle Hunde durch
		{
			for (int j = 0; j < KATZEN_ANZAHL; j++)					//geht alle Katzen durch
			{
				if (Hundehorde[i] == NULL || Katzenhorde[j] == NULL) {		//wenn eine Katze/ein hund tod ist wird er übersprungen
					continue;												//überspringen
				}
				else if (Hundehorde[i] != NULL && Katzenhorde[j] != NULL)	//wenn noch ein Hund UND eine Katze lebt
				{
					printf("Der %i. Hund greift die %i. Katze an!\nEr hat %i Schaden gemacht!\n", i + 1, j + 1, Hundehorde[i]->getKraft());
					Katzenhorde[j]->setLeben(Katzenhorde[j]->getLeben() - Hundehorde[i]->getKraft()); //neue Leben = alte leben - schaden von Hund
					Katzenhorde[j]->meinStatus();

					///Sleep(200);
					printf("Die %i. Katze greift den %i. Hund an!\nSie hat %i Schaden gemacht!\n", j + 1, i + 1, Katzenhorde[j]->getKraft());
					Hundehorde[i]->setLeben(Hundehorde[i]->getLeben() - Katzenhorde[j]->getKraft()); //neue Leben = alte leben - schaden von Katze
					Hundehorde[i]->meinStatus();

					if (Hundehorde[i]->getLeben() < 0) {							//wenn leben unter 0 ist
						printf("Der %ite Hund ist gestorben!\n", i + 1);
						Hundehorde[i] = NULL;											//Hund stirbt
					}
					if (Katzenhorde[j]->getLeben() < 0) {							//wenn leben unter 0 ist
						printf("Die %ite Katze ist gestorben!\n", j + 1);
						Katzenhorde[j] = NULL;											//katze stirbt
					}
				}


			}
			//Sleep(500);
		}
	} while (lebtNochMindestensEiner(Hundehorde, HUNDE_ANZAHL) && lebtNochMindestensEiner(Katzenhorde, KATZEN_ANZAHL));


	system("CLS");

	if (!lebtNochMindestensEiner(Hundehorde, HUNDE_ANZAHL)) {				//wenn alle tod sind
		printf("DIE KATZEN HABEN GEWONNEN!\n\n\n");


		/*printf("                               |        |\n");
		printf("                               |\\      /|\n");
		printf("                               | \\____/ |\n");
		printf("                               |  /\\/\\  |\n");
		printf("                              .'___  ___`.\n");
		printf("                             /  \\|/  \\|/  \\\n");
		printf("            _.--------------( ____ __ _____)\n");
		printf("         .-' \\  -. | | | | | \\ ----\\/---- /\n");
		printf("       .'\\  | | / \\` | | | |  `.  -'`-  .'\n");
		printf("      /`  ` ` '/ / \\ | | | | \  `------'\\\n");
		printf("     /-  `-------.' `-----.       -----. `---.\n");
		printf("    (  / | | | |  )/ | | | )/ | | | | | ) | | )\n");
		printf("     `._________.'_____,,,/\\_______,,,,/_,,,,/ \n");*/


		printf("                               ,----.\n");
		printf("                              ( WOW! )                         .-.\n");
		printf("                               `----' _                         \\ \\\n");
		printf("                                     (_)                         \\ \\\n");
		printf("                                         O                       | |\n");
		printf("                    |\\ /\\                  o                     | |\n");
		printf("    __              |,\\(_\\_                  . /\\---/\\   _,---._ | |\n");
		printf("   ( (              |\\,`   `-^.               /^   ^  \\,'       `. ;\n");
		printf("    \\ \\             :    `-'   )             ( O   O   )           ;\n");
		printf("     \\ \\             \\        ;               `.=o=__,'            \\\n");
		printf("      \\ \\             `-.   ,'                  /         _,--.__   \\\n");
		printf("       \\ \\ ____________,'  (                   /  _ )   ,'   `-. `-. \\\n");
		printf("        ; '                ;                  / ,' /  ,'        \\ \\ \\ \\\n");
		printf("        \\                 /___,-.            / /  / ,'          (,_)(,_)\n");
		printf("         `,    ,_____|  ;'_____,'           (,;  (,,)      \n");
		printf("       ,-\" \\  :      | :\n");
		printf("      ( .-\" \\ `.__   | |\n");
		printf("       \\__)  `.__,'  |__)\n");

	}

	if (!lebtNochMindestensEiner(Katzenhorde, KATZEN_ANZAHL)) {				//wenn alle tod sind
		printf("DIE HUNDE HABEN GEWONNEN!\n\n\n");

		printf("               ____\n");
		printf("            ,-'-,  `---._\n");
		printf("     _______(0} `, , ` , )\n");
		printf("     V           ; ` , ` (                            ,'~~~~~~`,\n");
		printf("     `.____,- '  (,  `  , )                          :`,-'\"\"`. \";\n");
		printf("       `-------._);  ,  ` `,                         \\;:      )``:\n");
		printf("              )  ) ; ` ,,  :                          ``      : ';\n");
		printf("             (  (`;:  ; ` ;:\                                 ;;;,\n");
		printf("             (:  )``;:;;)`'`'`--.    _____     ____       _,-';;`\n");
		printf("             :`  )`;)`)`'   :    \"~~~     ~~~~~    ~~~`--',.;;;'\n");
		printf("             `--;~~~~~      `  ,  \", \"\"\",  \"  \"   \"` \",, \ ;``\n");
		printf("               ( ;         ,   `                ;      `; ;\n");
		printf("               (; ; ;      `                   ,`       ` :\n");
		printf("                (; /            ;   ;          ` ;     ; :\n");
		printf("                ;(_; ;  :   ; ; `; ;` ; ; ,,,\"\"\";}     `;\n");
		printf("                : `; `; `  :  `  `,,;,''''   );;`);     ;\n");
		printf("                ;' :;   ; : ``'`'           (;` :( ; ,  ;\n");
		printf("                |, `;; ,``                  `)`; `(; `  `;\n");
		printf("                ;  ;;  ``:                   `).:` \;,   `.\n");
		printf("             ,-'   ;`;;:;`                   ;;'`;;  `)   )\n");
		printf("              ~~~,-`;`;,\"                    ~~~~~  ,-'   ;\n");
		printf("                 \"\"\"\"\"\"                             `\"\"\"\"\"\n");

	}

	printf("\n\n");


	for (int i = 0; i < KATZEN_ANZAHL; i++)
	{
		if (Katzenhorde[i] == NULL) {				//wenn die katze tod ist wird sie übersprungen
			continue;
		}
		printf("Die %i. Katze hat noch mit %i Leben \201eberlebt.\n", i + 1, Katzenhorde[i]->getLeben());
	}

	printf("\n\n\n");

	for (int i = 0; i < HUNDE_ANZAHL; i++)
	{
		if (Hundehorde[i] == NULL) {					//wenn der hund tod ist wird er übersprungen
			continue;
		}
		printf("Der %i. Hund hat noch mit %i Leben \201eberlebt.\n", i + 1, Hundehorde[i]->getLeben());
	}

	system("PAUSE");
	return 0;
}
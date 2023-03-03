#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

string maiusc(string s){
    int l;
    l=s.size();
    for(int i=0; i<l; i++){
        s[i]=toupper(s[i]);
    }
    return s;
}


class Squadra{
    public:
    string name;
    string articolo;
    float forzaSquadra;
    string giocatori[11];

    Squadra(string n, float f, string a){
        name=n;
        forzaSquadra=f;
        articolo=a;
    }

    void visualizzaSquadra(){
        cout<<name<<", forza: "<<forzaSquadra<<endl;
    }

};



class Marcatore{
    public:
    int minuto;
    string giocatore;
    string squadra;


    void visualizzaMarcatore(){
            cout<<minuto<<"' "<<giocatore<<" ("<<squadra<<")"<<endl;
    }
};



int generaGol(){
    int n_casuale;
    n_casuale=(rand()%100)+1;
    if(n_casuale<=4){
        return 1;
    } else {
        return 0;
    }
}



int assegnaGol(int g, float s){
    int p;
    p=(rand()%100)+1;
    if (g==1){

        switch(int(s*10)){

        case 0:
        if (p<=50){
            return 1;
        } else{
            return 2;
        }
        break;

        case 5:
        if (p<=55){
            return 1;
        } else{
            return 2;
        }
        break;

        case -5:
        if (p<=55){
            return 2;
        } else{
            return 1;
        }
        break;

        case 10:
        if (p<=60){
            return 1;
        } else{
            return 2;
        }
        break;

        case -10:
        if (p<=60){
            return 2;
        } else{
            return 1;
        }
        break;

        case 15:
        if (p<=65){
            return 1;
        } else{
            return 2;
        }
        break;

        case -15:
        if (p<=65){
            return 2;
        } else{
            return 1;
        }
        break;
        
        default:
        if(s>0){
            if (p<=70){
            return 1;
            } else{
            return 2;
            }
        } else {
            if (p<=70){
            return 2;
            } else{
            return 1;
            }
        }
        break;
        
        }
    } else {
        return 0;
    }
}

int generaRigore(){
    int n_casuale;
    n_casuale=(rand()%100)+1;
    if(n_casuale<=74){
        return 1;
    } else {
        return 0;
    }
}


int assegnaGiocatore(){
    int p;
    p=(rand()%300)+1;

    if(p==1){
        return 0;
    } else if (p>1 && p<=50){
        return ((rand()%4)+1);
    } else if (p>50 && p<=150){
        return ((rand()%4)+5);
    } else if (p>150 && p<=210){
        return 9;
    } else if (p>210 && p<=300){
        return 10;
    } else {
        return -1;
    }

}







void visualizzaRisFT(string s1, string s2, int r1, int r2, int temp){
    cout<<maiusc(s1)<<" "<<r1<<" - "<<r2<<" "<<maiusc(s2)<<endl;
}

void visualizzaRis(string s1, string s2, int r1, int r2, int temp){
    cout<<temp<<"'   "<<maiusc(s1)<<" "<<r1<<" - "<<r2<<" "<<maiusc(s2)<<endl;
}

void visualizzaRisDCR(string s1, string s2, int r1, int r2, int rig1, int rig2){
    cout<<endl;
    cout<<"RISULTATO FINALE"<<endl;
    cout<<maiusc(s1)<<" "<<r1<<" - "<<r2<<" "<<maiusc(s2)<<" ("<<r1+rig1<<"  -  "<<r2+rig2<<" dcr)"<<endl;
}



int selezionaSquadra(int m){
    int n;
    int exit=0;
    
    while(exit<1){
        cout<<"Squadra "<<m<<". Digita un numero da 1 a 20: ";
        cin>>n;
        if(n>=0 && n<=20){
            exit++;
        } else {
            cout<<"Numero invalido!"<<endl;
        }
    }

    cout<<endl;
    return n;
}

int selezionaModalita(){
    int n;
    int exit=0;

    cout<<endl<<"Seleziona la modalita'"<<endl<<"1. Serie A"<<endl<<"2. Coppa Italia (con supplementari e rigori)"<<endl<<endl;

    while(exit<1){
        cout<<"Digita 1 o 2: ";
        cin>>n;
        if(n>=1 && n<=2){
            exit++;
        } else {
            cout<<endl<<"Numero invalido!"<<endl<<endl;
        }
    }

    return n;
}



int vittoriaRigori(int G1, int G2, int T2){
    if(G1>(G2+(5-T2))){
        return 1;
    } else {
        return 0;
    }
}




int main(){

srand(time(0));

int mod;
int CalciDiRigore=0;
int sq1, sq2, sqG;
int G=0;
int ris1=0;
int ris2=0;
int nomeGiocatore;
float difSq;
int j=0;
int turno1=0;
int turno2=0;
int exit=0;
int gr;
int rigorista1=10;
int rigorista2=10;
int ng1=0;
int ng2=0;
int matchpoint1=0;
int matchpoint2=0;

string giocatori[20][11]{

{"Onana", "Skriniar", "Acerbi", "Bastoni", "Dumfries", "Di Marco", "Barella", "Brozovic", "Calhanoglu", "Lautaro", "Dzeko"},
{"Maignan", "Calabria", "Kalulu", "Tomori", "Theo Hernandez", "Tonali", "Bennacer", "Brahim Diaz", "Messias", "Leao", "Giroud"},
{"Szczesny", "Bremer", "Danilo", "Bonucci", "Alex Sandro", "Cuadrado", "Rabiot", "Locatelli", "Kostic", "Milik", "Vlahovic"},
{"Meret", "Di Lorenzo", "Kim", "Rrhamani", "Mario Rui", "Anguissa", "Lobotka", "Zielinski", "Lozano", "Kvaratskhelia", "Osimhen"},
{"Rui Patricio", "Mancini", "Smalling", "Ibanez", "Spinazzola", "Karsdorp", "Cristante", "Pellegrini", "Zaniolo", "Dybala", "Abraham"},
{"Musso", "Toloi", "Demiral", "Scalvini", "Hateboer", "Ederson", "Koopmeiners", "Maehle", "Pasalic", "Lookman", "Zapata"},
{"Provedel", "Hysaj", "Casale", "Romagnoli", "Marusic", "Marcos Antonio", "Milinkovic Savic", "Luis Alberto", "Zaccagni", "Felipe Anderson", "Immobile"},
{"Terraciano", "Dodo", "Milenkovic", "Igor", "Biraghi", "Barak", "Amrabat", "Mandragora", "Saponara", "Ikone", "Jovic"},
{"Vanja Milinkovic-Savic", "Djiji", "Schuurs", "Buongiorno", "Singo", "Lazaro", "Lukic", "Ricci", "Radonjic", "Vlasic", "Sanabria"},
{"Silvestri", "Becao", "Bijol", "Perez", "Udogie", "Pereyra", "Lovric", "Walace", "Makengo", "Deulofeu", "Beto"},
{"Consigli", "Rogerio", "Ferrari", "Erlic", "Toljan", "Frattesi", "Obiang", "Thorstvedt", "Lauriente'", "Berardi", "Pinamonti"},
{"Skorupski", "Soumaoro", "Lucumi", "Posch", "Lykogiannis", "Dominguez", "Ferguson", "Soriano", "Medel", "Orsolini", "Arnautovic"},
{"Di Gregorio", "Izzo", "Caldirola", "Marlon", "Carlos Augusto", "Ciurria", "Rovella", "Sensi", "Pessina", "Caprari", "Petagna"},
{"Sepe", "Fazio", "Daniliuc", "Bronn", "Mazzocchi", "Candreva", "Vilhena", "Maggiore", "Coulibaly", "Dia", "Piatek"},
{"Audero", "Murillo", "Ferrari", "Amione", "Bereszynski", "Rincon", "Villar", "Leris", "Duricic", "Gabbiadini", "Caputo"},
{"Montipo", "Dawidowicz", "Gunter", "Ceccherini", "Depaoli", "Tameze", "Veloso", "Lazovic", "Verdi", "Lasagna", "Henry"},
{"Vicario", "Parisi", "Luperto", "Ismajli", "Stojanovic", "Bandinelli", "Marin", "Haas", "Bajrami", "Satriano", "Destro"},
{"Carnesecchi", "Aiwu", "Bianchetti", "Lochoshvili", "Valeri", "Sernicola", "Ascacibar", "Meite", "Pickel", "Dessers", "Okereke"},
{"Falcone", "Gallo", "Pongracic", "Umtiti", "Baschirotto", "Gonzalez", "Hjulmand", "Banda", "Di Francesco", "Strefezza", "Colombo"},
{"Dragowski", "Nikolau", "Caldara", "Kiwior", "Holm", "Bastoni", "Bourabia", "Ampadu", "Agudelo", "Gyasi", "Nzola"},

};







cout<<"SIMULAZIONE PARTITA DI SERIE A / COPPA ITALIA"<<endl<<endl;

Squadra serieA[20]={Squadra("Inter", 4.5, "L'"), 
                    Squadra("Milan", 4.5, "Il "), 
                    Squadra("Juventus", 4.5, "La "), 
                    Squadra("Napoli", 4.5, "Il "), 
                    Squadra("Roma", 4, "La "), 
                    Squadra("Atalanta", 4, "L'"), 
                    Squadra("Lazio", 4, "La "), 
                    Squadra("Fiorentina", 4, "La "), 
                    Squadra("Torino", 3.5, "Il "), 
                    Squadra("Udinese", 3.5, "L'"), 
                    Squadra("Sassuolo", 3.5, "Il "), 
                    Squadra("Bologna", 3.5, "Il "), 
                    Squadra("Monza", 3.0, "Il "), 
                    Squadra("Salernitana", 3.0, "La "), 
                    Squadra("Sampdoria", 3.0, "La "), 
                    Squadra("Hellas Verona", 3.0, "L'"), 
                    Squadra("Empoli", 3.0, "L'"), 
                    Squadra("Cremonese", 3.0, "La "), 
                    Squadra("Lecce", 3.0, "Il "), 
                    Squadra("Spezia", 3.0, "Lo "),};




Marcatore marcatori[20];


for (int i=0; i<20; i++){
    cout<<i+1<<". ";
    serieA[i].visualizzaSquadra();
}


mod=selezionaModalita()-1;

cout<<endl<<"Seleziona 2 squadre"<<endl<<endl;

sq1=selezionaSquadra(1)-1;

cout<<maiusc(serieA[sq1].name)<<"  vs  "<<endl<<endl;

sq2=selezionaSquadra(2)-1;

cout<<maiusc(serieA[sq1].name)<<"  vs  "<<maiusc(serieA[sq2].name)<<endl<<endl;

difSq=(serieA[sq1].forzaSquadra+0.5)-serieA[sq2].forzaSquadra;

cout<<"Inizio Simulazione"<<endl<<endl;
Sleep(1000);

for (int min=1; min<=120; min++){
    sqG=0;
    G=generaGol();
    sqG=assegnaGol(G, difSq);
    if(sqG==1){
        ris1++;
    } else if (sqG==2){
        ris2++;
    }

    if(min<=9){
        cout<<" ";
    }

    if(min>90 && min<100){
        cout<<" ";
    }
    



    visualizzaRis(serieA[sq1].name, serieA[sq2].name, ris1, ris2, min);

    if(G==1){
        if(sqG==1){
            nomeGiocatore=assegnaGiocatore();
            cout<<"      GOL! Ha segnato "<<giocatori[sq1][nomeGiocatore]<<" ("<<serieA[sq1].name<<")"<<endl;
            marcatori[j].minuto=min;
            marcatori[j].giocatore=giocatori[sq1][nomeGiocatore];
            marcatori[j].squadra=serieA[sq1].name;
            j++;
            } else if(sqG==2){
            nomeGiocatore=assegnaGiocatore();
            cout<<"      GOL! Ha segnato "<<giocatori[sq2][nomeGiocatore]<<" ("<<serieA[sq2].name<<")"<<endl;
            marcatori[j].minuto=min;
            marcatori[j].giocatore=giocatori[sq2][nomeGiocatore];
            marcatori[j].squadra=serieA[sq2].name;
            j++;
            }
        Sleep(3000);
    } else {
        Sleep(200);
    }

    if(min==45){
        cout<<endl<<"FINE PRIMO TEMPO"<<endl;


        visualizzaRisFT(serieA[sq1].name, serieA[sq2].name, ris1, ris2, min);

        for(int k=0; k<(ris1+ris2); k++){
            marcatori[k].visualizzaMarcatore();
        }

        Sleep(4000);
        cout<<endl<<"INIZIO SECONDO TEMPO"<<endl;
        Sleep(1000);
        
    }
    
    if(min==90){
        if(mod==0){
            cout<<endl<<"FINE PARTITA"<<endl;
            visualizzaRisFT(serieA[sq1].name, serieA[sq2].name, ris1, ris2, min);

            for(int k=0; k<(ris1+ris2); k++){
                    marcatori[k].visualizzaMarcatore();
            }
            break;
        } else {
            if(ris1!=ris2){
                cout<<endl<<"FINE PARTITA"<<endl;
                visualizzaRisFT(serieA[sq1].name, serieA[sq2].name, ris1, ris2, min);

                for(int k=0; k<(ris1+ris2); k++){
                    marcatori[k].visualizzaMarcatore();
                }
                break;
            } else {

                cout<<endl<<"FINE TEMPO REGOLAMENTARE"<<endl;

                visualizzaRisFT(serieA[sq1].name, serieA[sq2].name, ris1, ris2, min);

                for(int k=0; k<(ris1+ris2); k++){
                    marcatori[k].visualizzaMarcatore();
                }

                Sleep(4000);
                cout<<endl<<"INIZIO PRIMO TEMPO SUPPLEMENTARE"<<endl;
                Sleep(1000);
                }
        }
    }

    if(min==105){
        cout<<endl<<"FINE PRIMO TEMPO SUPPLEMENTARE"<<endl;


        visualizzaRisFT(serieA[sq1].name, serieA[sq2].name, ris1, ris2, min);

        for(int k=0; k<(ris1+ris2); k++){
            marcatori[k].visualizzaMarcatore();
        }

        Sleep(4000);
        cout<<endl<<"INIZIO SECONDO TEMPO SUPPLEMENTARE"<<endl;
        Sleep(1000);
    }

    if(min==120){
        if(ris1!=ris2){
            cout<<endl<<"FINE PARTITA"<<endl;


            visualizzaRisFT(serieA[sq1].name, serieA[sq2].name, ris1, ris2, min);

            for(int k=0; k<(ris1+ris2); k++){
               marcatori[k].visualizzaMarcatore();
            } 
        } else {

            cout<<endl<<"FINE TEMPI SUPPLEMENTARI"<<endl;

            visualizzaRisFT(serieA[sq1].name, serieA[sq2].name, ris1, ris2, min);

            for(int k=0; k<(ris1+ris2); k++){
                marcatori[k].visualizzaMarcatore();
            } 

            cout<<endl;


            CalciDiRigore=1;

        }
    }
    
}

if (CalciDiRigore==1){

    cout<<"CALCI DI RIGORE"<<endl;
    Sleep(3000);

    for(int rigoriStd=0 ; rigoriStd<5; rigoriStd++){

        gr=generaRigore();
        if(gr==1){
            cout<<"O "<<giocatori[sq1][rigorista1]<<" ("<<serieA[sq1].name<<")"<<endl;
            ng1++;
            turno1++;
            Sleep(2000);
        } else {
            cout<<"X "<<giocatori[sq1][rigorista1]<<" ("<<serieA[sq1].name<<")"<<endl;
            Sleep(2000);
            turno1++;
        }
        rigorista1--;

        exit=vittoriaRigori(ng1, ng2, turno2);
        if (exit==1){
            visualizzaRisDCR(serieA[sq1].name, serieA[sq2].name, ris1, ris2, ng1, ng2);

            for(int k=0; k<(ris1+ris2); k++){
                marcatori[k].visualizzaMarcatore();
            }
            break;
        }

        gr=generaRigore();
        if(gr==1){
            cout<<"O "<<giocatori[sq2][rigorista2]<<" ("<<serieA[sq2].name<<")"<<endl<<endl;
            ng2++;
            turno2++;
            Sleep(2000);
        } else {
            cout<<"X "<<giocatori[sq2][rigorista2]<<" ("<<serieA[sq2].name<<")"<<endl<<endl;
            Sleep(2000);
            turno2++;
        }
        rigorista2--;

        exit=vittoriaRigori(ng2, ng1, turno1)+vittoriaRigori(ng1, ng2, turno2);
        if (exit>0){
            visualizzaRisDCR(serieA[sq1].name, serieA[sq2].name, ris1, ris2, ng1, ng2);

            for(int k=0; k<(ris1+ris2); k++){
                marcatori[k].visualizzaMarcatore();
            }
            break;
        }
    }

    if (ng1==ng2){
        for(; ;){
            gr=generaRigore();

            if(rigorista1==0){
                rigorista1=rigorista1+10;
            }

            if(rigorista2==0){
                rigorista2=rigorista2+10;
            }

            if(gr==1){
                cout<<"O "<<giocatori[sq1][rigorista1]<<" ("<<serieA[sq1].name<<")"<<endl;
                ng1++;
                matchpoint1++;
                Sleep(2000);
            } else {
                cout<<"X "<<giocatori[sq1][rigorista1]<<" ("<<serieA[sq1].name<<")"<<endl;
                Sleep(2000);
            }
            rigorista1--;
            

            gr=generaRigore();
            if(gr==1){
                cout<<"O "<<giocatori[sq2][rigorista2]<<" ("<<serieA[sq2].name<<")"<<endl<<endl;
                ng2++;
                matchpoint2++;
                Sleep(2000);
            } else {
                cout<<"X "<<giocatori[sq2][rigorista2]<<" ("<<serieA[sq2].name<<")"<<endl<<endl;
                Sleep(2000);
            }
            rigorista2--;

            if((matchpoint1-matchpoint2)!=0){
                visualizzaRisDCR(serieA[sq1].name, serieA[sq2].name, ris1, ris2, ng1, ng2);

                for(int k=0; k<(ris1+ris2); k++){
                    marcatori[k].visualizzaMarcatore();
                }
                break;
            }

            
        }
    }
}

return 0;
}
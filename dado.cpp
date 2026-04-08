#include <iostream>
#include <ctime>

int conto = 10000;

int main(){

    srand(time(0));

    std::string facce_dado[6][5] = {
        {"|-----|", "|     |", "|  o  |", "|     |", "|-----|"}, // 1
        {"|-----|", "|     |", "| o o |", "|     |", "|-----|"}, // 2
        {"|-----|", "| o   |", "|  o  |", "|    o|", "|-----|"}, // 3
        {"|-----|", "| o o |", "|     |", "| o o |", "|-----|"}, // 4
        {"|-----|", "| o o |", "|  o  |", "| o o |", "|-----|"}, // 5
        {"|-----|", "| o o |", "| o o |", "| o o |", "|-----|"}  // 6
    };

    while(true){
        int risposta;
        char risposta2;
        int num1 = (rand() % 6) + 1;
        int num2 = (rand() % 6) + 1;
        int num3 = (rand() % 6) + 1;
        int puntata = 0;
        int numero_fortunato;

        int numeri[] = {num1, num2, num3};

        std::cout << "Prego, inserisca il numero di dadi con cui vuole giocare(massimo 3, inserire 4 per uscire, inserire 5 per vedere il conto): ";
        std::cin >> risposta;
        if(risposta < 4 && risposta > 0){
            do
            {
            std::cout << "Vuoi puntare? (Y/N), ricorda che hai " << conto << " soldi sul conto" << std::endl;
            std::cin >> risposta2;
            if(risposta2 != 'Y' && risposta2 != 'N' && risposta2 != 'y' && risposta2 != 'n'){
                std::cout << "\nPer favore inserire una risposta valida\n";
            }
            }while(risposta2 != 'Y' && risposta2 != 'N' && risposta2 != 'y' && risposta2 != 'n');
            
            if(risposta2 == 'Y' || risposta2 == 'y'){
                do{
                    std::cout << "Scelga il suo numero fortunato: ";
                    std::cin >> numero_fortunato;
                    if(numero_fortunato > (risposta*6) || numero_fortunato < risposta){
                        std::cout << "Mi spiace, ma non è consentito inserire numeri maggiori di " << (risposta*6) << " o minori di " << risposta << '\n';
                    }
                }while(numero_fortunato < risposta || numero_fortunato > (risposta*6));
                std::cout << "\nBene, quanto desidera puntare? ";
                std::cin >> puntata;
                if(puntata > conto){
                    std::cout << "Non avete abbastanza soldi, puntata annullata\n\n";
                    puntata = 0;
                } else if(puntata <= 0){
                    std::cout << "Non potete puntare meno di 1, puntata annullata\n\n";
                    puntata = 0;
                }
            }
        }

        switch (risposta)
        {
        case 1:
            std::cout << "È uscito il numero: "<< num1 << '\n';
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < risposta; j++){
                    std::cout << facce_dado[numeri[j]-1][i] << '\n';
                };
            };
                std::cout << "\n";
            break;
        case 2:
            std::cout << "Sono usciti i numeri: "<< num1 << " e " << num2 << '\n';
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < risposta; j++){
                    std::cout << facce_dado[numeri[j]-1][i] << "  "; 
                    if(j == 1){
                        std::cout << '\n';
                    }
                };
            };
                std::cout << "\n";
            break;
        case 3:
            std::cout <<"Sono usciti i numeri: "<< num1 << ", " << num2 << " e " << num3 << '\n';
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < risposta; j++){
                    std::cout << facce_dado[numeri[j]-1][i] << "  "; 
                    if(j == 2){
                        std::cout << '\n';
                    }
                };
            };
                std::cout << "\n";
            break;
        case 4:
            break;
        case 5:
            std::cout << "A vostro carico ammontano " << conto << " soldi" << '\n';
            break;
        default:
            std::cout << "Inserisci una risposta valida!\n";
            break;
        }
        if(risposta == 4){
            std::cout << "\nGrazie per aver giocato!\n";
            break;
        }
        if(puntata!=0){
            int somma = 0;
            for(int i = 0; i < risposta; i++){
                somma += numeri[i];
            }
            if(somma==numero_fortunato){
                std::cout << "Congratulazioni, avete vinto, la vostra puntata sarà subito aggiunga al vostro conto\n";
                if(risposta > 1){
                    std::cout << "Dato che avete giocato con più dadi, riceverete un moltiplicatore\n";
                }
                conto += puntata*risposta;
            } else {
                std::cout << "Mi spiace, non avete vinto, la vostra puntata verrà sottratta dal vostro conto\n";
                conto -= puntata;
            }
        }
    }
    return 0;
}

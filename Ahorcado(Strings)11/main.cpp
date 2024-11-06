#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <limits>  
using namespace std;

// Funci�n para dibujar el ahorcado seg�n los intentos fallidos
void dibujarAhorcado(int intentosFallidos) {
    cout << "  +---+" << endl;
    cout << "  |   " << (intentosFallidos >= 1 ? "|" : " ") << endl;
    cout << "  |   " << (intentosFallidos >= 2 ? "O" : " ") << endl;
    cout << "  |  " << (intentosFallidos >= 3 ? "/" : " ") 
         << (intentosFallidos >= 4 ? "|" : " ") 
         << (intentosFallidos >= 5 ? "\\" : " ") << endl;
    cout << "  |  " << (intentosFallidos >= 6 ? "/" : " ") 
         << " " << (intentosFallidos >= 7 ? "\\" : " ") << endl;
    cout << "  |" << endl;
    cout << "=========" << endl;
}

int main() {
    // Inicializar generador de n�meros aleatorios una vez
    srand(time(0));
    
    vector<string> palabras;
palabras.push_back("programacion");
palabras.push_back("computadora");
palabras.push_back("desarrollo");
palabras.push_back("tecnologia");
palabras.push_back("software");
palabras.push_back("videojuego");

    while (true) {
        // Seleccionar palabra aleatoria
        string palabraSecreta = palabras[rand() % palabras.size()];
        string palabraAdivinada(palabraSecreta.length(), '_');
        int intentosFallidos = 0;
        vector<char> letrasUsadas;
        const int MAX_INTENTOS = 7;
        
        cout << "\n�Bienvenido al Juego del Ahorcado!" << endl;
        
        while (intentosFallidos < MAX_INTENTOS && palabraAdivinada != palabraSecreta) {
            cout << "\nPalabra: " << palabraAdivinada << endl;
            cout << "Intentos fallidos: " << intentosFallidos << "/" << MAX_INTENTOS << endl;
            cout << "Letras usadas: ";
            for (size_t i = 0; i < letrasUsadas.size(); i++) {
    char letra = letrasUsadas[i];
    cout << letra << " ";
}

            cout << endl;
            
            dibujarAhorcado(intentosFallidos);
            
            char letra;
            cout << "\nIngresa una letra: ";
            cin >> letra;
            letra = tolower(letra);
            
            // Verificar si el usuario ha ingresado una sola letra
            if (!isalpha(letra) || cin.fail()) {
                cin.clear();  // limpiar el estado de error de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignorar cualquier entrada adicional
                cout << "Entrada no v�lida. Por favor, ingresa una sola letra." << endl;
                continue;
            }

            // Verificar si la letra ya fue usada
            if (find(letrasUsadas.begin(), letrasUsadas.end(), letra) != letrasUsadas.end()) {
                cout << "�Ya usaste esa letra! Intenta con otra." << endl;
                continue;
            }
            
            letrasUsadas.push_back(letra);
            
            // Verificar si la letra est� en la palabra
            bool letraEncontrada = false;
            for (size_t i = 0; i < palabraSecreta.length(); i++) {
                if (palabraSecreta[i] == letra) {
                    palabraAdivinada[i] = letra;
                    letraEncontrada = true;
                }
            }
            
            if (!letraEncontrada) {
                intentosFallidos++;
                cout << "�Letra incorrecta!" << endl;
            }
        }
        
        // Mostrar resultado final
        dibujarAhorcado(intentosFallidos);
        cout << "\nLa palabra era: " << palabraSecreta << endl;
        
        if (palabraAdivinada == palabraSecreta) {
            cout << "�Felicitaciones! �Has ganado!" << endl;
        } else {
            cout << "�Game Over! Mejor suerte la pr�xima vez." << endl;
        }
        
        // Preguntar si quiere jugar de nuevo
        char respuesta;
        cout << "\n�Quieres jugar de nuevo? (s/n): ";
        cin >> respuesta;
        if (tolower(respuesta) != 's') {
            break;
        }
    }
    
    return 0;
}


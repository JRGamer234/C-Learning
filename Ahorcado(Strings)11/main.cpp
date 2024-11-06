#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// Función para dibujar el ahorcado según los intentos fallidos
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
    // Lista de palabras para el juego - CORREGIDO
    vector<string> palabras = {
        "programacion", "computadora", "desarrollo",
        "tecnologia", "software", "videojuego"
    };
    
    // Inicializar generador de números aleatorios
    srand(time(0));
    
    while (true) {
        // Seleccionar palabra aleatoria
        string palabraSecreta = palabras[rand() % palabras.size()];
        string palabraAdivinada(palabraSecreta.length(), '_');
        int intentosFallidos = 0;
        vector<char> letrasUsadas;
        const int MAX_INTENTOS = 7;
        
        cout << "\n¡Bienvenido al Juego del Ahorcado!" << endl;
        
        while (intentosFallidos < MAX_INTENTOS && palabraAdivinada != palabraSecreta) {
            cout << "\nPalabra: " << palabraAdivinada << endl;
            cout << "Intentos fallidos: " << intentosFallidos << "/" << MAX_INTENTOS << endl;
            cout << "Letras usadas: ";
            for (char letra : letrasUsadas) {
                cout << letra << " ";
            }
            cout << endl;
            
            dibujarAhorcado(intentosFallidos);
            
            char letra;
            cout << "\nIngresa una letra: ";
            cin >> letra;
            letra = tolower(letra);
            
            // Verificar si la letra ya fue usada
            if (find(letrasUsadas.begin(), letrasUsadas.end(), letra) != letrasUsadas.end()) {
                cout << "¡Ya usaste esa letra! Intenta con otra." << endl;
                continue;
            }
            
            letrasUsadas.push_back(letra);
            
            // Verificar si la letra está en la palabra
            bool letraEncontrada = false;
            for (size_t i = 0; i < palabraSecreta.length(); i++) {
                if (palabraSecreta[i] == letra) {
                    palabraAdivinada[i] = letra;
                    letraEncontrada = true;
                }
            }
            
            if (!letraEncontrada) {
                intentosFallidos++;
                cout << "¡Letra incorrecta!" << endl;
            }
        }
        
        // Mostrar resultado final
        dibujarAhorcado(intentosFallidos);
        cout << "\nLa palabra era: " << palabraSecreta << endl;
        
        if (palabraAdivinada == palabraSecreta) {
            cout << "¡Felicitaciones! ¡Has ganado!" << endl;
        } else {
            cout << "¡Game Over! Mejor suerte la próxima vez." << endl;
        }
        
        // Preguntar si quiere jugar de nuevo
        char respuesta;
        cout << "\n¿Quieres jugar de nuevo? (s/n): ";
        cin >> respuesta;
        if (tolower(respuesta) != 's') {
            break;
        }
    }
    
    return 0;
}

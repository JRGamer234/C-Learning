// Framework: Standard C++ libraries

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class Ahorcado {
public:
    static void main() {
        std::string secretWord = getSecretWord();
        std::vector<char> wordWithDashes = getDashesFromWord(secretWord);
        bool isGameOver = false;
        int attempts = 5;

        do {
            bool isAnyLetterGuessed = false;
            std::cout << "Te quedan " << attempts << " intentos" << std::endl;
            std::cout << wordWithDashes.data() << std::endl;
            std::cout << "Introduce una letra:" << std::endl;
            char letter;
            std::cin >> letter;

            // Recorrer palabra
            for (size_t i = 0; i < secretWord.length(); i++) {
                if (secretWord[i] == letter) {
                    wordWithDashes[i] = letter;
                    isAnyLetterGuessed = true;
                }
            }

            // Fallar letras
            if (!isAnyLetterGuessed) {
                std::cout << "No has acertado ninguna letra" << std::endl;
                --attempts;
                if (attempts == 0) {
                    std::cout << "¡Has perdido! Se acabaron los intentos." << std::endl;
                    isGameOver = true;
                }
            } else {
                // Ver si he ganado
                bool isGameWon = !hasDashes(wordWithDashes);
                if (isGameWon) {
                    std::cout << "¡Has ganado el juego!" << std::endl;
                    isGameOver = true;
                }
            }
        } while (!isGameOver);

        std::cout << wordWithDashes.data() << std::endl;
    }

    // Palabras
    static std::string getSecretWord() {
        std::string words[] = { "casa", "perro", "coche" };
        std::srand(static_cast<unsigned int>(std::time(0)));
        int n = std::rand() % (sizeof(words) / sizeof(words[0]));
        return words[n];
    }

    // Guiones en las letras
    static std::vector<char> getDashesFromWord(const std::string& word) {
        size_t numberOfLettersInSecretWord = word.length();
        std::vector<char> wordWithDashes(numberOfLettersInSecretWord, '_');
        return wordWithDashes;
    }

    // Verificar guiones
    static bool hasDashes(const std::vector<char>& array) {
        for (char ch : array) {
            if (ch == '_')
                return true;
        }
        return false;
    }
};

int main() {
    Ahorcado::main();
    return 0;
}

#include <iostream>
#include <chrono>
#include <numeric>
using namespace std;

//#include "Sphere.hpp"
//#include "Plan.hpp"
#include "Scene.hpp"
#include "Vecteur.hpp"
#include "Image.hpp"
#include "Camera.hpp"

// profondeur de la récursion pour le lancer de rayons
#define PROF 2
// nombre de threads à utiliser
#define NBT 16


int main(int argc, char *argv[]) {

    // vérification de la syntaxe de la commande

    if (argc != 2) {
        cerr << "ERREUR - Syntaxe = ";
        cerr << argv[0] << " <fichier descriptif d'une scène>";
        cerr << endl;
        return -1;
    }


    // création et chargement de la scène
    Scene sc;
    if (!sc.charger(argv[1])) {
        cerr << "ERREUR au chargement du fichier " << argv[1] << endl;
        return -1;
    };

    // création de l'image et de la caméra
    Image im(512, 512);
    Camera cam;

    std::vector<double> time;
    for(int i=0;i<10;i++) {
        // génération de l'image à partir de la caméra
        auto start = std::chrono::steady_clock::now();
        cam.genererImage(sc, im, PROF);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        time.push_back(elapsed_seconds.count());
    }
    std::cout << "" << (double)std::accumulate(time.begin(), time.end(), 0.0f) / (double)time.size() << "s\n";

    // sauvegarde de l'image
    //im.sauver("image.ppm");


    return 1;
}

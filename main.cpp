//Exercice 14 :MAIN réalisé par ANTON NELCON Steve

#include <iostream>

// Prototypes des exercices precedents
void exercice1();  void exercice2();  void exercice3();  void exercice4();
void exercice5();  void exercice6();  void exercice7();  void exercice8();
void exercice9();  void exercice10(); void exercice11(); void exercice12();
void exercice13();
void afficherMenu() { 
    std::cout << "\n===== MENU - Vision par Ordinateur TP1 =====" << std::endl;
    std::cout << " 1. Chargement et affichage d'une image" << std::endl;
    std::cout << " 2. Filtrage lineaire" << std::endl;
    std::cout << " 3. Lissage de l'image" << std::endl;
    std::cout << " 4. Morphologie mathematique" << std::endl;
    std::cout << " 5. Seuillage de l'image" << std::endl;
    std::cout << " 6. Detection de contours (Laplacien/Canny)" << std::endl;
    std::cout << " 7. Egalisation d'histogrammes" << std::endl;
    std::cout << " 8. Appariement d'images" << std::endl;
    std::cout << " 9. Detection de contours (findContours)" << std::endl;
    std::cout << "10. Enveloppe convexe" << std::endl;
    std::cout << "11. Appariement des descripteurs (ORB)" << std::endl;
    std::cout << "12. Classification de points avec SVM" << std::endl;
    std::cout << "13. Lecture video et interface graphique" << std::endl;
    std::cout << " 0. Quitter" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "Votre choix : ";
}

int main() {
    int choix = -1;

    do {
        afficherMenu();
        std::cin >> choix;

        switch (choix) {
        case 1:  exercice1();  break;
        case 2:  exercice2();  break;
        case 3:  exercice3();  break;
        case 4:  exercice4();  break;
        case 5:  exercice5();  break;
        case 6:  exercice6();  break;
        case 7:  exercice7();  break;
        case 8:  exercice8();  break;
        case 9:  exercice9();  break;
        case 10: exercice10(); break;
        case 11: exercice11(); break;
        case 12: exercice12(); break;
        case 13: exercice13(); break;

        case 0:  std::cout << "Fin du programme." << std::endl; break;
        default: std::cout << "[ERREUR] Choix invalide, reessayez." << std::endl; break;
        }

    } while (choix != 0);

    return 0;
}
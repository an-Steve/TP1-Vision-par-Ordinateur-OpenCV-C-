/*** Exercice 1 : Chargement et affichage d'une image */

#include <iostream>
#include <opencv2/opencv.hpp>

void exercice1() {
    std::cout << "--- [Exercice 1] Chargement et affichage d'une image ---" << std::endl;

    // 1. Charger l'image landscape.jpg
    std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/landscape.jpg";

    cv::Mat image = cv::imread(cheminImage, cv::IMREAD_COLOR);

    // 2. Vérifier si l'image chargée est vide
    if (image.empty()) {
        cheminImage = "C:/Users/adril/source/repos/images/landscape.jpg";
        image = cv::imread(cheminImage, cv::IMREAD_COLOR);

        if (image.empty()) {
            std::cerr << "[ERREUR] Impossible de trouver l'image landscape.jpg !" << std::endl;
            std::cerr << "Verifiez le chemin d'acces aux images." << std::endl;
            return;
        }
    }

    std::cout << "[INFO] Image chargee avec succes : "
        << image.cols << "x" << image.rows
        << " pixels (" << image.channels() << " canaux)" << std::endl;

    // 3. Créer une fenêtre graphique
    const std::string nomFenetre = "Exercice 1 - Paysage";
    cv::namedWindow(nomFenetre, cv::WINDOW_AUTOSIZE);

    // 4. Afficher l'image dans la fenêtre graphique
    cv::imshow(nomFenetre, image);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour afficher le resulat de l'exo 2 " << std::endl;

    // 5. Fermer la fenêtre lorsqu'une touche clavier est appuyée
    cv::waitKey(0);
    cv::destroyWindow(nomFenetre);

    std::cout << "[INFO] Fenetre fermee. Fin de l'exercice 1.\n" << std::endl;
}

//FIN DU CODE
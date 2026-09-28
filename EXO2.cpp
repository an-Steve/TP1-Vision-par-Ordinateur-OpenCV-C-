//Exercice 2 : Filtrage linéaire

#include <iostream>
#include <opencv2/opencv.hpp>

void exercice2() {
    std::cout << "--- [Exercice 2] Filtrage lineaire ---" << std::endl;

    // 1. Déclarer une image source, une image destination et une matrice noyau
    cv::Mat src, dst, noyau;

    // 2. Initialiser le noyau, de taille 3x3, avec la valeur 1/9
    noyau = cv::Mat::ones(3, 3, CV_32F) / 9.0f;

    // 3. Charger l'image plane.jpg
    std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/plane.jpg";
    src = cv::imread(cheminImage, cv::IMREAD_COLOR);

    // 4. Vérifier si l'image n'est pas vide
    if (src.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver l'image plane.jpg !" << std::endl;
        std::cerr << "Verifiez le chemin d'acces aux images." << std::endl;
        return;
    }

    std::cout << "[INFO] Image chargee avec succes : "
        << src.cols << "x" << src.rows
        << " pixels (" << src.channels() << " canaux)" << std::endl;

    // 5. Appliquer un filtre linéaire 2D en utilisant le noyau prédéfini
    cv::filter2D(src, dst, -1, noyau);

    // 6. Afficher les images source et destination
    cv::namedWindow("Exercice 2 - Image source", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 2 - Image filtree", cv::WINDOW_AUTOSIZE);

    cv::imshow("Exercice 2 - Image source", src);
    cv::imshow("Exercice 2 - Image filtree", dst);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour afficher le resultat de l'exo 3" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "[INFO] Fenetres fermees. Fin de l'exercice 2.\n" << std::endl;
}
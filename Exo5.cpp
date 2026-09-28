//Exercice 5 :Seuillage de l'image

#include <iostream>
#include <opencv2/opencv.hpp>

void exercice5() {
    std::cout << "--- [Exercice 5] Seuillage de l'image ---" << std::endl;

    // 1. Charger et vérifier l'image tiger.jpg
    std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/tiger.jpg";
    cv::Mat src = cv::imread(cheminImage, cv::IMREAD_COLOR);

    if (src.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver l'image tiger.jpg !" << std::endl;
        std::cerr << "Verifiez le chemin d'acces aux images." << std::endl;
        return;
    }

    std::cout << "[INFO] Image chargee avec succes : "
        << src.cols << "x" << src.rows
        << " pixels (" << src.channels() << " canaux)" << std::endl;

    // 2. Convertir l'image source en niveaux de gris
    cv::Mat gris;
    cv::cvtColor(src, gris, cv::COLOR_BGR2GRAY);

    // 3. Appliquer le seuillage (seuil 100, seuil max 255, type binaire)
    cv::Mat dst;
    cv::threshold(gris, dst, 100, 255, cv::THRESH_BINARY);

    // 4. Afficher l'image source et l'image résultat
    cv::namedWindow("Exercice 5 - Image source", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 5 - Image seuillee", cv::WINDOW_AUTOSIZE);

    cv::imshow("Exercice 5 - Image source", src);
    cv::imshow("Exercice 5 - Image seuillee", dst);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour voir le resulat du numéro 6" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "[INFO] Fenetres fermees. Fin de l'exercice 5.\n" << std::endl;
}

//FIN DU CODE 
//Exercice 6 :  Detection de contours

#include <iostream>
#include <opencv2/opencv.hpp>

void exercice6() {
    std::cout << "--- [Exercice 6] Detection de contours ---" << std::endl;

    // 1. Charger et vérifier l'image building.jpg
    std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/building.jpg";
    cv::Mat src = cv::imread(cheminImage, cv::IMREAD_COLOR);

    if (src.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver l'image building.jpg !" << std::endl;
        std::cerr << "Verifiez le chemin d'acces aux images." << std::endl;
        return;
    }

    std::cout << "[INFO] Image chargee avec succes : "
        << src.cols << "x" << src.rows
        << " pixels (" << src.channels() << " canaux)" << std::endl;

    // 2. Convertir l'image source en niveaux de gris
    cv::Mat gris;
    cv::cvtColor(src, gris, cv::COLOR_BGR2GRAY);

    // 3. Appliquer un filtre laplacien (noyau taille 3, profondeur destination 16S)
    cv::Mat laplacien;
    cv::Laplacian(gris, laplacien, CV_16S, 3);

    // 4. Mise à l'échelle, valeurs absolues, conversion en 8-bit
    cv::Mat laplacienAbs;
    cv::convertScaleAbs(laplacien, laplacienAbs);

    // 5. Appliquer le filtre de Canny (seuils 20 et 110)
    cv::Mat canny;
    cv::Canny(gris, canny, 20, 110);

    // 6. Afficher les images source et résultats
    cv::namedWindow("Exercice 6 - Image source", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 6 - Laplacien", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 6 - Canny", cv::WINDOW_AUTOSIZE);

    cv::imshow("Exercice 6 - Image source", src);
    cv::imshow("Exercice 6 - Laplacien", laplacienAbs);
    cv::imshow("Exercice 6 - Canny", canny);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour regarder le resultat de l'exercice 7 " << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "[INFO] Fenetres fermees. Fin de l'exercice 6.\n" << std::endl;
}
//FIN DU CODE
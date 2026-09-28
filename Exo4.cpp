//Exercice 4 :  Morphologie mathematique

#include <iostream>
#include <opencv2/opencv.hpp>

void exercice4() {
    std::cout << "--- [Exercice 4] Morphologie mathematique ---" << std::endl;

    // 1. Charger et vérifier l'image apple.png
    std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/apple.png";
    std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/apple.png";
    cv::Mat src = cv::imread(cheminImage, cv::IMREAD_COLOR);

    if (src.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver l'image apple.png !" << std::endl;
        std::cerr << "Verifiez le chemin d'acces aux images." << std::endl;
        return;
    }

    std::cout << "[INFO] Image chargee avec succes : "
        << src.cols << "x" << src.rows
        << " pixels (" << src.channels() << " canaux)" << std::endl;

    // 2. Définir un élément structurant carré de taille 7
    cv::Mat elementStructurant = cv::getStructuringElement(
        cv::MORPH_RECT, cv::Size(7, 7));

    cv::Mat dstDilatee, dstErodee;

    // 3. Dilater l'image source en utilisant l'élément structurant
    cv::dilate(src, dstDilatee, elementStructurant);

    // 4. Éroder l'image source avec le même élément structurant
    cv::erode(src, dstErodee, elementStructurant);

    // 5. Afficher les images : source, dilatée et érodée
    cv::namedWindow("Exercice 4 - Image source", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 4 - Image dilatee", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 4 - Image erodee", cv::WINDOW_AUTOSIZE);

    cv::imshow("Exercice 4 - Image source", src);
    cv::imshow("Exercice 4 - Image dilatee", dstDilatee);
    cv::imshow("Exercice 4 - Image erodee", dstErodee);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour fermer voir le resultat de l'exercice 5" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "[INFO] Fenetres fermees. Fin de l'exercice 4.\n" << std::endl;
}
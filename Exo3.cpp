//Exercice 3 : Lissage de l'image

#include <iostream>
#include <opencv2/opencv.hpp>


void exercice3() {
    std::cout << "--- [Exercice 3] Lissage de l'image ---" << std::endl;

    // 1. Charger et vérifier l'image monalisa.jpg
    std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/monalisa.jpg";
    cv::Mat src = cv::imread(cheminImage, cv::IMREAD_COLOR);

    if (src.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver l'image monalisa.jpg !" << std::endl;
        std::cerr << "Verifiez le chemin d'acces aux images." << std::endl;
        return;
    }

    std::cout << "[INFO] Image chargee avec succes : "
        << src.cols << "x" << src.rows
        << " pixels (" << src.channels() << " canaux)" << std::endl;

    cv::Mat dstGaussien, dstMedian, dstBilateral;

    // 2. Filtre gaussien, taille du noyau = 5
    cv::GaussianBlur(src, dstGaussien, cv::Size(5, 5), 0);

    // 3. Filtre médian, taille du noyau = 5
    cv::medianBlur(src, dstMedian, 5);

    // 4. Filtre bilatéral
    cv::bilateralFilter(src, dstBilateral, 15, 15 * 2, 15 / 2.0);

    // 5. Afficher les trois images résultats
    cv::namedWindow("Exercice 3 - Filtre Gaussien", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 3 - Filtre Median", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 3 - Filtre Bilateral", cv::WINDOW_AUTOSIZE);

    cv::imshow("Exercice 3 - Filtre Gaussien", dstGaussien);
    cv::imshow("Exercice 3 - Filtre Median", dstMedian);
    cv::imshow("Exercice 3 - Filtre Bilateral", dstBilateral);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour fermer pour regarder le resultat de l'exercice 4" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "[INFO] Fenetres fermees. Fin de l'exercice 3.\n" << std::endl;
}
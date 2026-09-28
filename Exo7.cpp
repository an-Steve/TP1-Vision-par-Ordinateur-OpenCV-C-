//Exercice 7 : Egalisation d'histogrammes

#include <iostream>
#include <opencv2/opencv.hpp>


void exercice7() {
    std::cout << "--- [Exercice 7] Egalisation d'histogrammes ---" << std::endl;

    // 1. Charger et vérifier l'image bird.jpg
    std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/bird.jpg";
    cv::Mat src = cv::imread(cheminImage, cv::IMREAD_COLOR);

    if (src.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver l'image bird.jpg !" << std::endl;
        std::cerr << "Verifiez le chemin d'acces aux images." << std::endl;
        return;
    }

    std::cout << "[INFO] Image chargee avec succes : "
        << src.cols << "x" << src.rows
        << " pixels (" << src.channels() << " canaux)" << std::endl;

    // 2. Convertir l'image en niveaux de gris
    cv::Mat gris;
    cv::cvtColor(src, gris, cv::COLOR_BGR2GRAY);

    // 3. Appeler la fonction d'égalisation d'histogramme prédéfinie
    cv::Mat dst;
    cv::equalizeHist(gris, dst);

    // 4. Afficher les images source et résultat
    cv::namedWindow("Exercice 7 - Image source", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exercice 7 - Image egalisee", cv::WINDOW_AUTOSIZE);

    cv::imshow("Exercice 7 - Image source", src);
    cv::imshow("Exercice 7 - Image egalisee", dst);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour afficher l'exercice 8" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "[INFO] Fenetres fermees. Fin de l'exercice 7.\n" << std::endl;
}
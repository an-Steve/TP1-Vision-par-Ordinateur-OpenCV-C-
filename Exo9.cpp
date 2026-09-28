//Exercice 9 :  Detection de contours (Canny + findContours)

#include <iostream>
#include <opencv2/opencv.hpp>


void exercice9() {
    std::cout << "--- [Exercice 9] Detection de contours ---" << std::endl;

    cv::Mat src = cv::imread("C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/porsche.jpg", cv::IMREAD_COLOR);
    if (src.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver l'image porsche.jpg !" << std::endl;
        return;
    }

    // 2. Niveaux de gris
    cv::Mat gris;
    cv::cvtColor(src, gris, cv::COLOR_BGR2GRAY);

    // 3. Canny (seuils 100 et 200)
    cv::Mat contoursCanny;
    cv::Canny(gris, contoursCanny, 100, 200);

    // 4. Trouver les contours segmentes
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchie;
    cv::findContours(contoursCanny, contours, hierarchie, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    // 5. Tracer les contours trouves
    cv::Mat dst = cv::Mat::zeros(src.size(), CV_8UC3);
    cv::RNG rng(12345);
    for (size_t i = 0; i < contours.size(); i++) {
        cv::Scalar couleur(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
        cv::drawContours(dst, contours, (int)i, couleur, 2, cv::LINE_8, hierarchie, 0);
    }

    // 6. Afficher source et destination
    cv::imshow("Exercice 9 - Image source", src);
    cv::imshow("Exercice 9 - Contours", dst);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour afficher l'exercice 10" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "[INFO] Fenetres fermees. Fin de l'exercice 9.\n" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();
    std::cout << "[INFO] Fin de l'exercice 9.\n" << std::endl;
}
//Exercice 8  :  Appariement d'images (template matching)

#include <iostream>
#include <opencv2/opencv.hpp>

void exercice8() {
    std::cout << "--- [Exercice 8] Appariement d'images ---" << std::endl;

    cv::Mat src = cv::imread("C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/bus.jpg", cv::IMREAD_COLOR);
    cv::Mat modele = cv::imread("C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/bus_template.png", cv::IMREAD_COLOR);

    if (src.empty() || modele.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver bus.jpg ou bus_template.png !" << std::endl;
        return;
    }

    std::cout << "[INFO] Source : " << src.cols << "x" << src.rows
        << " | Modele : " << modele.cols << "x" << modele.rows << std::endl;

    // 2. Appariement par methode des moindres carrees normalisee
    cv::Mat dst;
    int resultCols = src.cols - modele.cols + 1;
    int resultRows = src.rows - modele.rows + 1;
    dst.create(resultRows, resultCols, CV_32FC1);
    cv::matchTemplate(src, modele, dst, cv::TM_SQDIFF_NORMED);
    cv::normalize(dst, dst, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    // 3. Trouver les coordonnees du modele dans l'image destination
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(dst, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());
    cv::Point matchLoc = minLoc; // pour TM_SQDIFF_NORMED, le minimum = meilleure correspondance

    // 4. Rectangle autour de l'emplacement du modele
    cv::Mat srcAffichage = src.clone();
    cv::rectangle(srcAffichage, matchLoc,
        cv::Point(matchLoc.x + modele.cols, matchLoc.y + modele.rows),
        cv::Scalar(0, 255, 0), 2);

    // 5. Afficher source, destination et modele
    cv::imshow("Exercice 8 - Image source", srcAffichage);
    cv::imshow("Exercice 8 - Carte de correspondance", dst);
    cv::imshow("Exercice 8 - Modele", modele);

    std::cout << "[INFO] Appuyez sur n'importe quelle touche pour afficher l'exercice 9" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "[INFO] Fenetres fermees. Fin de l'exercice 8.\n" << std::endl;

    cv::waitKey(0);
    cv::destroyAllWindows();
    std::cout << "[INFO] Fin de l'exercice 8.\n" << std::endl;
}

// FIN DU CODE